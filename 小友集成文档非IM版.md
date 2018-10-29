# 一、集成准备
## 1.1 注册开发者账号
	这部分是通用的注册流程，引用之前的注册流程
## 1.2 创建应用
	创建应用的流程与创建IM iOS应用相同。
## 1.3下载小友SDK
	小友移动端iOS SDK下载地址:http://im.yyuap.com/download.html
	SDK结构目录如下图所示:
![图片](../小友文档iOS-非IM版/demo目录结构-非IM版.png)
## 1.4申请百度语音服务账号
	由于小友SDK的语音识别等能力使用百度语音服务，因此，需要用户自行创建账号以获取授权使用相关服务。地址:http://ai.baidu.com
	用户创建百度账号及应用后，获取appid、apikey、secretkey，后续集成过程中会使用。
# 二、SDK集成
## 2.1集成小友SDK到APP
	demo工程默认使用测试机器人进行体验，若要申请用户自己的机器人（可根据用户自己的业务配置知识库等），需联系合作
	demo工程包含小友SDK、百度语音SDK,References文件夹可直接拖入用户的原生工程内。
	对于AFNetworking和SDWebImage两个第三方库，若用户工程内已使用，则不用拖入。
## 2.2依赖的类库
	XiaoYou.framework
	libBaiduSpeechSDK.a
	libYonyouIMSdk.a
	SDWebImage.framework
	YYBaiduVoiceSDK.framework
	AFNetworking.framework
	libiconv.tbd
	libc++.tbd
	libresolv.tbd
## 2.3初始化SDK
	#import <XiaoYou/XiaoYou.h>
	#import <YYBaiduVoiceSDK/YYBaiduVoiceSDK.h>
	#import <AFNetworking/AFNetworking.h>
	
	#define APP_ID     @"用户申请的百度appid"
	#define API_KEY    @"用户申请的百度appkey"
	#define SECRET_KEY @"用户申请的百度secretkey"
	
	//开启检测网络状态
    [[AFNetworkReachabilityManager sharedManager] startMonitoring];
    //初始化百度语音SDK
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
    [configuration makeKeyConfiguration]; 
## 2.4调起小友界面及实现代理协议
初始化小友界面并实现XiaoYouViewControllerDelegate协议
	
	XiaoYouViewController *vc = [[XiaoYouViewController alloc] init];
	vc.delegate = self;
	[self.navigationController pushViewController:vc animated:YES];

实现XiaoYouViewControllerDelegate代理方法

	//该代理方法用于监听小友抛出的各种事件，具体事件类型可查看相关头文件
	- (void)xy_viewController:(XiaoYouViewController *)viewController
     handleActionWithInfo:(NSDictionary<NSString *,id> *)info
                 callback:(void (^)(XiaoYouActionStatus status, NSDictionary *info))callback {
    
    	NSString *action = info[XiaoYouActionName];
    	id object = info[XiaoYouDataName];
    	NSLog(@"action:%@, object:%@", action, object);
	}

## 2.5自定义配置文件
增加小友配置文件（XiaoYouConfig.json，在SDK的文件夹目录下），以满足不同产品在首页提示语、帮助、设置等方面展示内容不同的需要。
注意：使用默认的首页提示语、帮助、设置时，不需要在工程中引入该配置文件
## 2.6其他设置
系统权限

	（1）麦克风权限
	（2）定位权限

