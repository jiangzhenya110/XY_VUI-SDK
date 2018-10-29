//
//  XiaoYouViewController.h
//  MOLI
//
//  Created by Chenly on 2017/12/21.
//

#import <UIKit/UIKit.h>

#import "XiaoYouDefines.h"

@class XiaoYouViewController;
@class XiaoYouConfiguration;

@protocol XiaoYouViewControllerDelegate <NSObject>

- (void)xy_viewController:(XiaoYouViewController *)viewController
     handleActionWithInfo:(NSDictionary<NSString *,id> *)info
                 callback:(void (^)(XiaoYouActionStatus status, NSDictionary *info))callback;

@end

@interface XiaoYouViewController : UIViewController <UIImagePickerControllerDelegate>

@property (nonatomic, weak) id<XiaoYouViewControllerDelegate> delegate;
@property (nonatomic, assign) BOOL autoRestoreNavigationBar; // 自动还原导航栏，默认 YES
- (void)restoreNavigationBar; // 还原导航栏

@property (nonatomic, strong) XiaoYouConfiguration *configuration;
@property (nonatomic, copy) NSDictionary *customParameters;
@property (nonatomic, assign) BOOL isHideHelp;//是否显示帮助

@end
