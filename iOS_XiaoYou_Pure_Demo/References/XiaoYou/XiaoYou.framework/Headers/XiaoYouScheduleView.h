//
//  XiaoYouScheduleView.h
//  XiaoYou
//
//  Created by Chenly on 2018/2/6.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import "XiaoYouUniView.h"
#import "XiaoYouDefines.h"

@class XYPersonMessage;
@class XYScheduleMessage;

@interface XiaoYouScheduleView : XiaoYouUniView

- (void)setSelectPerson:(XYPersonMessage *)person forRow:(NSInteger)row;
- (void)confirmSchedule:(XYScheduleMessage *)schedule;

+ (id)exportData:(id)data withPersons:(NSArray<XYPersonMessage *> *)persons;
+ (id)exportData:(id)data setSelectPerson:(XYPersonMessage *)person forRow:(NSInteger)row;
+ (id)exportData:(id)data confirmSchedule:(XYScheduleMessage *)schedule;

@end
