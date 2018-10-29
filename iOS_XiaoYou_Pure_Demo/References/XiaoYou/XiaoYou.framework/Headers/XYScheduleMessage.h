//
//  XYScheduleMessage.h
//  XiaoYou
//
//  Created by Chenly on 2018/3/7.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XYPersonMessage;
@class XYResult;

@interface XYScheduleMessage : NSObject

@property (nonatomic, copy) NSString *scheduleId;
@property (nonatomic, copy) NSString *topic;
@property (nonatomic, copy) NSString *time;
@property (nonatomic, copy) NSArray<XYPersonMessage *> *participates;

- (NSDictionary *)jsonObject;

@end
