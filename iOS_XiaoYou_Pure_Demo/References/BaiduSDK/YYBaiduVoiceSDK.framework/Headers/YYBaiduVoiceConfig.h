//
//  YYBaiduVoiceConfig.h
//  YYBaiduVoiceSDK
//
//  Created by Chenly on 2018/4/25.
//  Copyright © 2018年 Chenly. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YYBaiduVoiceConfig : NSObject

@property (nonatomic, readonly) NSString *apiKey;
@property (nonatomic, readonly) NSString *secretKey;
@property (nonatomic, readonly) NSString *appid;

+ (instancetype)sharedInstance;

/**
 * @brief 设置认证信息
 *
 * @param apiKey    在百度开发者中心注册应用获得
 * @param secretKey 在百度开发者中心注册应用获得
 * @param appid     在百度开发者中心注册应用获得
 */
- (void)setApiKey:(NSString *)apiKey withSecretKey:(NSString *)secretKey appid:(NSString *)appid;

@end
