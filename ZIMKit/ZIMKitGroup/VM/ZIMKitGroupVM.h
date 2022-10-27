//
//  ZIMKitGroupVM.h
//  ZIMKit
//
//  Created by zego on 2022/5/23.
//

#import <Foundation/Foundation.h>
#import <ZIM/ZIM.h>

@class ZIMKitGroupInfo, ZIMKitGroupMember;

typedef void (^ZIMKitGroupCallback)(ZIMKitGroupInfo  *_Nullable groupInfo, ZIMError * _Nullable errorInfo);
typedef void (^ZIMKitCreateGroupCallback)(ZIMKitGroupInfo  *_Nullable groupInfo,NSArray<ZIMErrorUserInfo *> * _Nullable errorUserList, ZIMError * _Nullable errorInfo);
typedef void (^ZIMKitGroupMemberListQueriedCallback)(NSString *_Nullable groupID,
                                                     NSArray<ZIMKitGroupMember *> * _Nullable userList,
                                                     unsigned int nextFlag, ZIMError * _Nullable errorInfo);

NS_ASSUME_NONNULL_BEGIN

@protocol ZIMKitGroupVMDelegate <NSObject>

@optional
/// Group state changed
- (void)onGroupStatusChange:(NSString *)groupID
                      state:(ZIMGroupState)state
                      event:(ZIMGroupEvent)event
           operatedUserInfo:(ZIMKitGroupMember *)operatedUserInfo;

/// Group member state changed
- (void)onGroupMemberStateChanged:(NSString *)groupID
                            state:(ZIMGroupMemberState)state
                            event:(ZIMGroupMemberEvent)event
                         userList:(NSArray *)userList
                 operatedUserInfo:(ZIMKitGroupMember *)operatedUserInfo;
@end

@interface ZIMKitGroupVM : NSObject

@property (nonatomic, weak) id<ZIMKitGroupVMDelegate>delegate;

/// Create group chat
///
/// @param groupID groupID
/// @param groupName group name
/// @param userIDList Group member ID list
/// @param callBack callback
- (void)createGroup:(NSString *_Nullable)groupID
          groupName:(NSString *)groupName
         userIDList:(NSArray <NSString *>*)userIDList
           callBack:(ZIMKitCreateGroupCallback)callBack;

/// Join group chat
///
/// @param groupID groupID
/// @param callBack callback
- (void)joinGroup:(NSString *)groupID callBack:(ZIMKitGroupCallback)callBack;

/// Query group members
/// 
/// @param groupID groupID
/// @param config Query config
/// @param callback callback
- (void)queryGroupMemberListByGroupID:(NSString *)groupID
                                    config:(ZIMGroupMemberQueryConfig *)config
                                  callback:(ZIMKitGroupMemberListQueriedCallback)callback;
@end

NS_ASSUME_NONNULL_END
