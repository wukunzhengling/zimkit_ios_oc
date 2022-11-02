//
//  ZIMKitMessagesListVC.h
//  ZIMKit
//
//  Created by zego on 2022/5/30.
//

#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
#import <ZIM/ZIM.h>
#import "ZIMKitBaseViewController.h"
#import "ZIMKitMessageSendToolbar.h"
#import "ZIMKitVoicePlayer.h"
#import "ZIMKitAudioMessage.h"
#import "ZIMKitFileMessage.h"
#import "ZIMKitVideoMessage.h"
#import "ZIMKitMessagesVM.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZIMKitMessagesListVC : ZIMKitBaseViewController

@property (nonatomic, strong, nullable) ZIMKitMessageSendToolbar *messageToolbar;
@property (nonatomic, strong, nullable) ZIMKitVoicePlayer        *voicePlay;
@property (nonatomic, strong, nullable) ZIMKitAudioMessage       *curPlayVoiceMessage;
@property (nonatomic, strong, nullable) ZIMKitVideoMessage       *curPlayVideoMessage;
@property (nonatomic, strong, nullable) ZIMKitFileMessage        *curPreviewFileMessage;
@property (nonatomic, strong, nullable) AVPlayerViewController   *avPlayerVC;
@property (nonatomic, strong, nullable) UIDocumentInteractionController *document;
@property (nonatomic, assign)           BOOL                     isSelectMore;
@property (nonatomic, strong, nullable) NSMutableArray           *selectedMessages;

@property (nonatomic, copy, readonly)   NSString                 *conversationID;
@property (nonatomic, assign, readonly) ZIMConversationType      conversationType;
@property (nonatomic, strong, readonly) ZIMKitMessagesVM         *messageVM;

/// Create the session page
///
/// Description: Create a session page VC first, then you can create a session page by pushing or presenting the VC.
///
/// @param conversationID : session ID.
/// @param conversationType : session type.
/// @param conversationName : session name.
- (instancetype)initWithConversationID:(NSString *)conversationID
                      conversationType:(ZIMConversationType)conversationType
                      conversationName:(nullable NSString *)conversationName;

- (UITableView *)messageTableView;

/// Send text messae
- (void)sendAction:(NSString *)text;

- (void)sendMediaMessage:(ZIMKitMediaMessage *)mediaMessage;

- (void)scrollToBottom:(BOOL)animate;

- (void)reloaddataAndScrolltoBottom:(BOOL)isReceve;

- (void)tableviewGestureRecognizerRemove:(BOOL)remove;
@end

NS_ASSUME_NONNULL_END
