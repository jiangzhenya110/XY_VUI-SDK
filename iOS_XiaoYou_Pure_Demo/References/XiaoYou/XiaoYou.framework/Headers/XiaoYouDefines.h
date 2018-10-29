//
//  XiaoYouDefines.h
//  XiaoYou
//
//  Created by Chenly on 2018/2/3.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#ifndef XiaoYouDefines_h
#define XiaoYouDefines_h

// public action
extern NSString * const XiaoYouActionContactsTapCard;       // 点击联系人卡片
extern NSString * const XiaoYouActionContactsButtonChat;    // 联系人“聊天”按钮
extern NSString * const XiaoYouActionScheduleTapCard;       // 点击日程卡片
extern NSString * const XiaoYouActionScheduleDetail;        // 查看日程详情
extern NSString * const XiaoYouActionScheduleButtonConfirm; // 日程“确认”
extern NSString * const XiaoYouActionPersonPickerSelect;    // 选人“选择”
extern NSString * const XiaoYouActionPersonPickerConfirm;   // 选人“确认”
extern NSString * const XiaoYouActionCommonPhoneCall;       // 打电话
extern NSString * const XiaoYouActionCommonSendMessage;     // 发消息
extern NSString * const XiaoYouActionCommonOpenApp;         // 打开应用
extern NSString * const XiaoYouActionCommonReloadView;      // 重新布局视图
// private action
extern NSString * const XiaoYouActionLoadMore;              // 展开更多
extern NSString * const XiaoYouActionRecommendTap;          // 点击智能推荐
extern NSString * const XiaoYouActionCommonOpenURL;         // 打开链接
extern NSString * const XiaoYouActionReloadData;            // 新闻加载
extern NSString * const XiaoYouActionResendMessage;         // 重发消息
extern NSString * const XiaoYouActionScheduleButtonCancel;  // 日程“取消”
extern NSString * const XiaoYouActionCommonSendText;        // 发送文本
extern NSString * const XiaoYouActionCommonHelp;            // 打开帮助界面
// 友人才
extern NSString * const XiaoYouActionHRCloudMore;           // 更多
extern NSString * const XiaoYouActionHRCloudOpenUrl;        // 友人才打开URL
//友报账
extern NSString * const XiaoYouActionYBZFillNote;        // 友报账多条回答点击
extern NSString * const XiaoYouActionYBZFillReimbursement;
extern NSString * const XiaoYouActionYBZPrintReceipt;
extern NSString * const XiaoYouActionYBZMore;           // 友报账更多

extern NSString * const XiaoYouActionName;
extern NSString * const XiaoYouOriginDataName;
extern NSString * const XiaoYouDataName;
extern NSString * const XiaoYouDataSelectedPerson;
extern NSString * const XiaoYouDataRow;
extern NSString * const XiaoYouDataSchedule;
extern NSString * const XiaoYouDataSize;
// private
extern NSString * const XiaoYouResultName;

// Settings
extern NSString * const XiaoYouSettingsEnterpriseId;
extern NSString * const XiaoYouSettingsUid;

// 卡片显示状态
typedef NS_ENUM(NSUInteger, XiaoYouDisplayStatus) {
    XiaoYouDisplayStatusNotDetermined = 0,
    XiaoYouDisplayStatusConfirmed,
    XiaoYouDisplayStatusCanceled,
    XiaoYouDisplayStatusDone,
};

// Status
typedef NS_ENUM(NSUInteger, XiaoYouActionStatus) {
    XiaoYouActionStatus_NO_RESULT = 0,
    XiaoYouActionStatus_OK,
    XiaoYouActionStatus_Cancel,
    XiaoYouActionStatus_ERROR
};

#endif /* XiaoYouDefines_h */
