//
//  ZIMKitGroupInfo.h
//  ZIMKit
//
//  Created by zego on 2022/5/23.
//

#import <Foundation/Foundation.h>
#import <ZIM/ZIM.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZIMKitGroupInfo : NSObject

@property (nonatomic, copy) NSString *groupID;

@property (nonatomic, copy) NSString *groupName;

@property (nonatomic, copy) NSString *groupAvatarUrl;

/// 从SDKZIMGroupFullInfo ->ZIMKitGroupInfo
- (void)fromZIMGroupFullInfo:(ZIMGroupFullInfo*)info;
@end

NS_ASSUME_NONNULL_END
