//
//  ConversationController.m
//  ZIMKitDemo
//
//  Created by zego on 2022/5/19.
//

#import "ConversationController.h"

@interface ConversationController ()<ZIMKitManagerDelegate>
@property (nonatomic, strong) ZIMKitAlertView *alertView;
@end

@implementation ConversationController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"ZEGO IM";

    //设置ZIMKit 代理
    ZIMKitManager.shared.delegate = self;
    //导航栏
    [self setupNav];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    self.tabBarController.tabBar.hidden = YES;
    [self.alertView dismiss];
}

#pragma mark ZIMKitConversationListVCDelegate
- (void)onTotalUnreadMessageCountChange:(NSInteger)totalCount {
    self.tabBarItem.badgeValue = totalCount ? [NSString stringWithFormat:@"%@", totalCount > 99 ? @"99+" : @(totalCount)] : nil;
}

- (void)onUserAccountKickedOut {
    UIAlertController *alter = [UIAlertController alertControllerWithTitle:nil message:KitDemoLocalizedString(@"demo_user_kick_out", LocalizedDemoKey, nil) preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *sure = [UIAlertAction actionWithTitle:KitDemoLocalizedString(@"confirm", LocalizedDemoKey, nil) style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self leftBarButtonClick:nil];
    }];
    [alter addAction:sure];
    //延迟0.25s, 聊天界面正在播放视频消息时,先播放界面消失,在弹alter
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.25 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self presentViewController:alter animated:true completion:nil];
    });
}

- (void)onConnectionStateChange:(ZIMConnectionState)state event:(ZIMConnectionEvent)event {
    NSString *title = @"ZEGO IM";
    if (event == ZIMConnectionEventKickedOut) {
        [self onUserAccountKickedOut];
        return;
    }
    
    if (state == ZIMConnectionStateConnecting || state == ZIMConnectionStateReconnecting) {
        title = [NSString stringWithFormat:@"%@(%@)",title,[NSBundle ZIMKitlocalizedStringForKey:@"conversation_connecting"]];
    } else if (state == ZIMConnectionStateDisconnected) {
        title = [NSString stringWithFormat:@"%@(%@)",title,[NSBundle ZIMKitlocalizedStringForKey:@"conversation_disconnected"]];
    } else {
        title = @"Zego IM";
    }
    self.navigationItem.title = title;
}

- (void)setupNav {
    UIButton *leftButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [leftButton setImage:[UIImage kitDemo_imageName:@"conversation_bar_left"] forState:UIControlStateNormal];
    [leftButton addTarget:self action:@selector(leftBarButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    leftButton.imageView.contentMode = UIViewContentModeScaleAspectFit;
    [leftButton.widthAnchor constraintEqualToConstant:40].active = YES;
    [leftButton.heightAnchor constraintEqualToConstant:40].active = YES;
    UIBarButtonItem *leftItem = [[UIBarButtonItem alloc] initWithCustomView:leftButton];
    self.navigationItem.leftBarButtonItem = leftItem;
    
    UIButton *moreButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moreButton setImage:[UIImage kitDemo_imageName:@"conversation_bar_right"] forState:UIControlStateNormal];
    [moreButton addTarget:self action:@selector(rightBarButtonClick:) forControlEvents:UIControlEventTouchUpInside];
    moreButton.imageView.contentMode = UIViewContentModeScaleAspectFit;
    [moreButton.widthAnchor constraintEqualToConstant:40].active = YES;
    [moreButton.heightAnchor constraintEqualToConstant:40].active = YES;
    UIBarButtonItem *moreItem = [[UIBarButtonItem alloc] initWithCustomView:moreButton];
    self.navigationItem.rightBarButtonItem = moreItem;
}


- (void)leftBarButtonClick:(UIButton *)left {
    [[ZIMKitManager shared] disconnectUser];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"logout" object:nil];
}

- (void)rightBarButtonClick:(UIButton *)right {
    [self createChatAlert];
}

- (void)createChatAlert {
    NSArray *titles = @[KitDemoLocalizedString(@"conversation_start_single_chat", LocalizedDemoKey, nil),
                        KitDemoLocalizedString(@"conversation_start_group_chat", LocalizedDemoKey, nil),
                        KitDemoLocalizedString(@"conversation_join_group_chat", LocalizedDemoKey, nil)];
    ZIMKitAlertView *alertView = [[ZIMKitAlertView alloc] initWithFrame:self.navigationController.view.bounds superView:self.navigationController.view contentSize:CGSizeZero titles:titles];
    @weakify(self);
    alertView.actionBlock = ^(NSInteger index) {
        @strongify(self);
        [self createChatWithIndex:index];
    };
    [alertView show];
    _alertView = alertView;
}

- (void)createChatWithIndex:(NSInteger)index {
    ZIMKitCreateChatController *vc = [[ZIMKitCreateChatController alloc] init];
    if (index == 1) {
        
        vc.createType = ZIMKitCreateChatTypeSingle;
        [self.navigationController pushViewController:vc animated:true];
        
    } else if (index == 2){
        
        vc.createType = ZIMKitCreateChatTypeGroup;
        [self.navigationController pushViewController:vc animated:true];
        
    } else if(index == 3) {
        vc.createType = ZIMKitCreateChatTypeJoin;
        [self.navigationController pushViewController:vc animated:true];
    }
}
@end
