#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ZIMKit.h"
#import "ZIMKitBaseViewController.h"
#import "ZIMKitDefine.h"
#import "ZIMKitEventHandler.h"
#import "ZIMKitLocalAPNS.h"
#import "ZIMKitManager.h"
#import "ZIMKitNavigationController.h"
#import "ZIMKitUserInfo.h"
#import "ZIMKitBaseModule.h"
#import "ZIMKitRouter.h"
#import "NSBundle+ZIMKitUtil.h"
#import "NSObject+ZIMKitUtil.h"
#import "NSString+ZIMKitUtil.h"
#import "UIColor+ZIMKitUtil.h"
#import "UIImage+ZIMKitUtil.h"
#import "UIView+ZIMKitLayout.h"
#import "UIView+ZIMKitToast.h"
#import "ZIMKitTool.h"
#import "ZIMMessage+Extension.h"
#import "ZIMKitConversationModel.h"
#import "ZIMKitConversationCell.h"
#import "ZIMKitUnReadView.h"
#import "ZIMKitConversationListVC.h"
#import "ZegoRefreshAutoFooter.h"
#import "ZIMKitConversationListNoDataView.h"
#import "ZIMKitConversationVM.h"
#import "ZIMKitGroupInfo.h"
#import "ZIMKitGroupMember.h"
#import "ZIMKitGroupModule.h"
#import "ZIMKitGroupDetailController.h"
#import "ZIMKitGroupdetailView.h"
#import "ZIMKitGroupVM.h"
#import "ZIMKitAudioMessage.h"
#import "ZIMKitFileMessage.h"
#import "ZIMKitImageMessage.h"
#import "ZIMKitMediaMessage.h"
#import "ZIMKitMessage.h"
#import "ZIMKitMessageCellConfig.h"
#import "ZIMKitMessageModule.h"
#import "ZIMKitSystemMessage.h"
#import "ZIMKitTextMessage.h"
#import "ZIMKitUnknowMessage.h"
#import "ZIMKitVideoMessage.h"
#import "ZIMKitAudioMessageCell.h"
#import "ZIMKitBubbleMessageCell.h"
#import "ZIMKitFileMessageCell.h"
#import "ZIMKitImageMessageCell.h"
#import "ZIMKitMessageCell.h"
#import "ZIMKitSystemMessageCell.h"
#import "ZIMKitTextMessageCell.h"
#import "ZIMKitUnKnowMessageCell.h"
#import "ZIMKitVideoMessageCell.h"
#import "ZIMKitMessagesListVC+InputBar.h"
#import "ZIMKitMessagesListVC+Meida.h"
#import "ZIMKitMessagesListVC+MessageAction.h"
#import "ZIMKitMessagesListVC.h"
#import "ZIMKitMenuItem.h"
#import "ZIMKitMenuView.h"
#import "ZIMKitMultiChooseView.h"
#import "ZIMKitDefaultEmojiCollectionView.h"
#import "ZIMKitEmojiItemCell.h"
#import "ZIMKitFaceManagerView.h"
#import "ZIMKitInputTextView.h"
#import "ZIMKitInputTextViewInternal.h"
#import "ZIMKitChatBarMoreView.h"
#import "ZIMKitChatTostView.h"
#import "ZIMKitRecordView.h"
#import "ZIMKitInputBar.h"
#import "ZIMKitMessageSendToolbar.h"
#import "GKLoadingView.h"
#import "GKPanGestureRecognizer.h"
#import "GKPhotoBrowser.h"
#import "GKPhotoBrowserConfigure.h"
#import "GKPhotoManager.h"
#import "GKPhotoView.h"
#import "GKWebImageProtocol.h"
#import "UIScrollView+GKPhotoBrowser.h"
#import "ZIMKitLoadingView.h"
#import "GKSDWebImageManager.h"
#import "ZIMKitMessagesVM.h"
#import "ZIMKitMessageTool.h"
#import "ZIMKitRefreshAutoHeader.h"
#import "ZIMKitVoicePlayer.h"
#import "ZIMKitVoiceRecorder.h"

FOUNDATION_EXPORT double ZIMKit_OCVersionNumber;
FOUNDATION_EXPORT const unsigned char ZIMKit_OCVersionString[];

