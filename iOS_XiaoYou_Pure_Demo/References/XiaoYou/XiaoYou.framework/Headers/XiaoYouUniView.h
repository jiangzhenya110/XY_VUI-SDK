//
//  XiaoYouUniView.h
//  XiaoYou
//
//  Created by Chenly on 2018/3/7.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XiaoYouDefines.h"

@class XiaoYouUniView;

@protocol XiaoYouUniViewDelegate <NSObject>

- (void)xy_uniView:(XiaoYouUniView *)view handleActionWithInfo:(NSDictionary<NSString *, id> *)info;

@end

@interface XiaoYouUniView : UIView

@property (nonatomic, assign) XiaoYouDisplayStatus displayStatus;
@property (nonatomic, weak) id<XiaoYouUniViewDelegate> delegate;

+ (CGSize)sizeThatFits:(CGSize)size data:(id)data;

- (instancetype)initWithData:(id)data;
- (void)loadData:(id)data;
- (id)exportData;   // 导出原始数据

@end
