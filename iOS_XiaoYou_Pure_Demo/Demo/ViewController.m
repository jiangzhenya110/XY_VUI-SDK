//
//  ViewController.m
//  Demo
//
//  Created by Chenly on 2018/1/6.
//  Copyright © 2018年 yonyou. All rights reserved.
//

#import "ViewController.h"
#import <XiaoYou/XiaoYou.h>
#import <YYBaiduVoiceSDK/YYBaiduVoiceSDK.h>

// 百度语音
#define APP_ID     @"用户申请的百度appid"
#define API_KEY    @"用户申请的百度appkey"
#define SECRET_KEY @"用户申请的百度secretkey"

@interface ViewController () <XiaoYouViewControllerDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // 百度语音设置
    [[YYBaiduVoiceConfig sharedInstance] setApiKey:API_KEY withSecretKey:SECRET_KEY appid:APP_ID];
    
    // 小友全局设置
    XiaoYouConfiguration *configuration = [XiaoYouConfiguration configuration];
    configuration.storingSettings = YES;
    [configuration restoreSettings];
    
    configuration.nickname = @"陈庆明";
    configuration.avatar = nil;
    
    
    configuration.token = @"b28e71f4-6654-4a02-9de6-0c6523ac1c1c";
    configuration.userid = @"chenqmg";
    configuration.appcode = @"test";
    configuration.tenantid = @"test";

    
    
    static NSString * deviceid;
    if (!deviceid) {
        deviceid = [NSUUID UUID].UUIDString;
    }
    configuration.deviceid = deviceid;
    [configuration setAiServer:@"http://robottest.ublinker.com"];
    
    [configuration makeKeyConfiguration];    
    self.view.backgroundColor = [UIColor grayColor];
}

- (IBAction)action {
    [self gotoXiaoYou];
}

- (void)gotoXiaoYou
{
    // 打开小友界面
    XiaoYouViewController *vc = [[XiaoYouViewController alloc] init];
    vc.delegate = self;
    vc.isHideHelp = YES;
    [self.navigationController pushViewController:vc animated:YES];
}

#pragma mark - <XiaoYouViewControllerDelegate>

- (void)xy_viewController:(XiaoYouViewController *)viewController
     handleActionWithInfo:(NSDictionary<NSString *,id> *)info
                 callback:(void (^)(XiaoYouActionStatus status, NSDictionary *info))callback {
    
    NSString *action = info[XiaoYouActionName];
    id object = info[XiaoYouDataName];
    NSLog(@"action:%@, object:%@", action, object);
}


@end

