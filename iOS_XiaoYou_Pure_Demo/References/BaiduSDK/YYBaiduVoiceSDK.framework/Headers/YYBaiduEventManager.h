//
//  YYBaiduEventManager.h
//  YYBaiduVoiceSDK
//
//  Created by Chenly on 2018/6/5.
//  Copyright © 2018年 Chenly. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol YYBaiduEventManager <NSObject>

- (void)setApiKey:(NSString *)apiKey withSecretKey:(NSString *)secretKey appid:(NSString *)appid;

@end
