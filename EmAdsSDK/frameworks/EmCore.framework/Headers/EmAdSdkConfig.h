//
//  EmAdSdkConfig.h
//  advancelib
//
//  Created by allen on 2019/9/12.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EmAdLogLevel) {
    EmAdLogLevel_None  = 0, // 不打印
    EmAdLogLevel_Fatal,
    EmAdLogLevel_Error,
    EmAdLogLevel_Warning,
    EmAdLogLevel_Info,
    EmAdLogLevel_Debug,
};


// MARK: ======================= SDK =======================
extern NSString *const AdvanceSdkVersion;

extern NSString *const SDK_TAG_GDT;
extern NSString *const SDK_TAG_CSJ;
extern NSString *const SDK_TAG_KS;
extern NSString *const SDK_TAG_BAIDU;

extern NSString *const EmAdSdkTypeAdName;
extern NSString *const EmAdSdkTypeAdNameSplash;
extern NSString *const EmAdSdkTypeAdNameBanner;
extern NSString *const EmAdSdkTypeAdNameInterstitial;
extern NSString *const EmAdSdkTypeAdNameFullScreenVideo;
extern NSString *const EmAdSdkTypeAdNameNativeExpress;
extern NSString *const EmAdSdkTypeAdNameRewardVideo;

@interface EmAdSdkConfig : NSObject
/// SDK版本
+ (NSString *)sdkVersion;

+ (NSString *)getBDSDKVersion;
+ (NSString *)getKsSDKVersion;
+ (NSString *)getCsjSDKVersion;
+ (NSString *)getGdtSDKVersion;


+ (UIWindow *)getRootWindow;

+ (instancetype)shareInstance;

/// 控制台log级别
/// 0 不打印
/// 1 打印fatal
/// 2 fatal + error
/// 3 fatal + error + warning
/// 4 fatal + error + warning + info
/// 5 全部打印
@property (nonatomic, assign) EmAdLogLevel level;

@end

NS_ASSUME_NONNULL_END
