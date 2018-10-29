//
//  XiaoYouConfiguration.h
//  MBP
//
//  Created by Chenly on 2018/5/18.
//  Copyright © 2018年 Chenly. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XiaoYouConfiguration : NSObject

@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *userid;
@property (nonatomic, copy) NSString *appcode;
@property (nonatomic, copy) NSString *tenantid;
@property (nonatomic, copy) NSString *deviceid;

@property (nonatomic, readonly) NSString *server;
@property (nonatomic, copy) NSDictionary *globalCustomParameters;

@property (nonatomic, copy) NSString *nickname;  // 用户昵称，如果未设置 avatar 则使用昵称作为头像
@property (nonatomic, strong) id avatar;         // 用户头像，支持 UIImage 和 NSString(图片 URL 地址) 类型

@property (nonatomic, assign) BOOL enableSpeech; // 语音播报
@property (nonatomic, assign) BOOL enableWakeup; // 语音唤醒

@property (nonatomic, assign) BOOL storingSettings; // 存储设置
- (void)restoreSettings;    // 从本地存储恢复设置

+ (instancetype)configuration;
+ (instancetype)keyConfiguration;
- (void)makeKeyConfiguration;

- (void)setAiServer:(NSString *)server;
- (void)setAiServerDevelop;
- (void)setAiServerRelease;

@end
