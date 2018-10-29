//
//  YYBaiduWakeup.h
//  YYBaiduVoiceSDK
//
//  Created by Chenly on 2018/4/25.
//  Copyright © 2018年 Chenly. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YYBaiduEventManager.h"

typedef NS_ENUM(NSUInteger, YYBaiduWakeupWorkStatus) {
    YYBaiduWakeupWorkStatusStart,
    YYBaiduWakeupWorkStatusStop,
    YYBaiduWakeupWorkStatusTriggered,
    YYBaiduWakeupWorkStatusError,
};

@protocol YYBaiduWakeupDelegate <NSObject>

- (void)YYBaiduWakeupWorkStatus:(YYBaiduWakeupWorkStatus)workStatus obj:(id)obj;

@end

@interface YYBaiduWakeup : NSObject <YYBaiduEventManager>

@property (nonatomic, weak) id<YYBaiduWakeupDelegate> delegate;

+ (instancetype)sharedInstance;
- (void)start;
- (void)stop;

@end
