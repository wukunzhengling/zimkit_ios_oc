//
//  ZIMKitManager.h
//  ZIMKit
//
//  Created by zego on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import "ZIMKitUserInfo.h"
#import <ZIM/ZIM.h>

@protocol ZIMKitManagerDelegate <NSObject>

/// ZIM状态回调
///
/// @param state 连接状态
- (void)onConnectionStateChange:(ZIMConnectionState)state event:(ZIMConnectionEvent)event;

/// 未读消息总数
///
/// @param totalCount 未读数量
- (void)onTotalUnreadMessageCountChange:(NSInteger)totalCount;

@end

NS_ASSUME_NONNULL_BEGIN

@interface ZIMKitManager : NSObject

@property (nonatomic, strong, readonly) ZIM *zim;

@property (nonatomic, strong, readonly) ZIMKitUserInfo *userInfo;

@property (nonatomic, weak) id<ZIMKitManagerDelegate>delegate;

/// 创建ZIMKitManager实例
+ (instancetype)shared;

/// 创建ZIM实例
///
/// @param appID  应用ID,请联系ZEGO技术支持
/// @param appSign appSign,请联系ZEGO技术支持
- (void)initWith:(int)appID appSign:(NSString *)appSign;

/// 登录ZIM
///
/// @param userInfo 用户信息
/// @param callback 返回结果回调
- (void)connectUser:(ZIMKitUserInfo *)userInfo
     callback:(ZIMLoggedInCallback)callback;

/// 退出ZIM
- (void)disconnectUser;

/// 查询个人信息
///
/// @param userIDs 用户ID集合
/// @param callback 返回结果回调
- (void)queryUsersInfo:(NSArray<NSString *>*)userIDs callback:(ZIMUsersInfoQueriedCallback)callback;


/// 更新用户头像
///
/// @param avatarUrl 头像URL
/// @param callback 返回结果回调
- (void)updateUserAvatarUrl:(NSString *)avatarUrl callback:(ZIMUserAvatarUrlUpdatedCallback)callback;

- (NSString *)getImagepath;

- (NSString *)getVoicePath;

- (NSString *)getVideoPath;

- (NSString *)getFilePath;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
