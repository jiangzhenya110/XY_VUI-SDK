# XY_VUI-SDK
用友云平台 小友VUI SDK是基于用友云服务的智能语音助手，提供了完整VUI能力，包括：

+ 提供ASR语音识别及TTS语音合成等基础能力，用户不必自己集成底层的语音库，只需使用就好
+ 提供自定义热词能力，在以往的VUI中，识别特殊词汇比如人名等，准确率往往不够。小友SDK提供用户可以自定义的热词库。例如“张珊”和“张山”分别存在于企业A和企业B导入的热词库。那么小友SDK给企业A的用户返回的是“张珊”，给企业B的用户返回的则是“张山”。不仅仅是人名，企业名称、部门名称、特殊词汇等都支持自定义
+ 提供界面定制化能力，如果对SDK提供标准UI，如字体、配色、帮助条目、设置项等不满意，尤其是颜色风格等跟被继承的APP不相符时，用户可以通过配置文件自行修改
+ 提供接入第三方系统能力，例如用户想从自己现存的系统中返回数据，可以在小友的AI平台配置相应的实体，小友VUI则会把收到的数据统一返回给外部app，外部app只需接收数据即可
+ 提供一些基础功能，如查看天气（小友会自动定位到当前位置）、新闻、菜谱、创建日程、创建会议、找人、打电话、发短信等等基础功能
+ 多端能力。小友VUI SDK全面覆盖Android、iOS、web生态，无论PC端、移动端、智能端都可使用。

另外，小友VUI SDK提供两个不同的版本：
+ IM版本的SDK依托于IM的长连接机制实现通信，方便已经集成了IM的用户，只需在IM服务器进行简单配置，即可集成VUI能力
+ 非IM版本的SDK，使不需要IM的用户也可使用VUI能力，只需在本地工程内配置相应秘钥，即可使用
# 一、集成准备
## 1.1 官网地址
   [官网地址:](https://iuap.yonyoucloud.com)
   
   [文档地址:](https://iuap.yonyoucloud.com/doc/instantmessaging.html#/md-build/exclusive_cloud_instantmessaging/articles/product/6-/xiaoyou/ios/小友集成文档IM版.md?key=小友集成文档IOSIM版)
## 1.2下载小友SDK
   小友移动端iOS [SDK下载地址:](https://iuap.yonyoucloud.com/doc/instantmessaging.html#/md-build/exclusive_cloud_instantmessaging/articles/product/11-/download.md?key=相关下载)
## 1.3申请百度语音服务账号
	由于小友SDK的语音识别等能力使用百度语音服务，因此，需要用户自行创建账号以获取授权使用相关服务。地址:http://ai.baidu.com
	用户创建百度账号及应用后，获取appid、apikey、secretkey，后续集成过程中会使用。
# 二、SDK集成
## 2.1集成小友SDK到APP
	demo工程默认使用测试机器人进行体验，用户可申请用户自己的机器人（可根据用户自己的业务配置知识库等）
	demo工程包含小友SDK、百度语音SDK,References文件夹可直接拖入用户的原生工程内。
	对于AFNetworking和SDWebImage两个第三方库，若用户工程内已使用，则不用拖入。
## 2.2依赖的类库
	XiaoYou.framework
	libBaiduSpeechSDK.a 需要自行下载该语音库,官网下载的demo中包含此库
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
    configuration.nickname = @"张三";
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
