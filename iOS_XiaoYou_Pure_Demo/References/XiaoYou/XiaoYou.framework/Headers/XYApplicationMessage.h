//
//  XYApplicationMessage.h
//  XiaoYou
//
//  Created by Chenly on 2018/3/8.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XYApplicationMessage : NSObject

@property (nonatomic, copy) NSString *app_company;
@property (nonatomic, copy) NSString *app_type;
@property (nonatomic, copy) NSString *classify_id;
@property (nonatomic, copy) NSString *des;
@property (nonatomic, copy) NSString *display;
@property (nonatomic, copy) NSString *hightest_ver;
@property (nonatomic, copy) NSString *icon;

@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *is_home;
@property (nonatomic, copy) NSString *is_new_first;
@property (nonatomic, copy) NSString *lowest_ver;
@property (nonatomic, copy) NSString *mtime;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *navColor;
@property (nonatomic, copy) NSString *open_appid;
@property (nonatomic, copy) NSString *packagetype;
@property (nonatomic, copy) NSString *power;
@property (nonatomic, copy) NSString *qz_id;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *web_url;

- (instancetype)initWithJSONObject:(NSDictionary *)jsonObject;

@end
