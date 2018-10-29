//
//  XYPersonMessage.h
//  XiaoYou
//
//  Created by Chenly on 2018/3/7.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XYPersonMessage;

@interface XYPersonMessage : NSObject

@property (nonatomic, copy) NSString *avatarUrl;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSString *department;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *landline;
@property (nonatomic, copy) NSString *memberid;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *position;

@property (nonatomic, copy) NSString *originquestion;

- (instancetype)initWithJSONObject:(NSDictionary *)jsonObject;
- (NSDictionary *)jsonObject;

+ (NSArray<XYPersonMessage *> *)objectsWithJSONArray:(NSArray<NSDictionary *> *)array;
+ (NSArray<NSDictionary *> *)jsonArrayWithObjects:(NSArray<XYPersonMessage *> *)objects;

@end
