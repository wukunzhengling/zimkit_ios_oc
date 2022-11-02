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

/// Callback for updates on the connection status changes.
/// The event callback when the connection state changes.
///
/// @param state : the current connection status.
/// @param event : the event happened. The event that causes the connection status to change.
- (void)onConnectionStateChange:(ZIMConnectionState)state event:(ZIMConnectionEvent)event;

/// Total number of unread messages.
///
/// @param totalCount : Total number of unread messages.
- (void)onTotalUnreadMessageCountChange:(NSInteger)totalCount;

@end

NS_ASSUME_NONNULL_BEGIN

@interface ZIMKitManager : NSObject

@property (nonatomic, strong, readonly) ZIM *zim;

@property (nonatomic, strong, readonly) ZIMKitUserInfo *userInfo;

/// Delegate the ZIMKitManager
@property (nonatomic, weak) id<ZIMKitManagerDelegate>delegate;

/// Create a ZIMKitManager instance.
+ (instancetype)shared;

/// Initialize the ZIMKit.
///
/// Description: You will need to initialize the ZIMKit SDK before calling methods.
///
/// @param appID : appID. To get this, go to ZEGOCLOUD Admin Console (https://console.zegocloud.com/).
/// @param appSign : appSign. To get this, go to ZEGOCLOUD Admin Console (https://console.zegocloud.com/).
- (void)initWith:(int)appID appSign:(NSString *)appSign;

/// Connects user to ZIMKit server
///
/// Description: Connects user to ZIMKit server. This method can only be used after calling the [initWith:] method and before you calling any other methods.
///
/// @param userInfo : user info
/// @param callback : callback for the results that whether the connection is successful.
- (void)connectUser:(ZIMKitUserInfo *)userInfo
     callback:(ZIMLoggedInCallback)callback;

/// Disconnects current user from ZIMKit server.
- (void)disconnectUser;

/// Update the user avatar
///
/// Description: After a successful connection, you can change the user avatar as needed.
///
/// @param avatarUrl : avatar URL.
/// @param callback : callback for the results that whether the user avatar is updated successfully.
- (void)updateUserAvatarUrl:(NSString *)avatarUrl callback:(ZIMUserAvatarUrlUpdatedCallback)callback;

/// Query users info
///
/// @param userIDs userIDs
/// @param callback  callback
- (void)queryUsersInfo:(NSArray<NSString *>*)userIDs callback:(ZIMUsersInfoQueriedCallback)callback;

- (NSString *)getImagepath;

- (NSString *)getVoicePath;

- (NSString *)getVideoPath;

- (NSString *)getFilePath;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
