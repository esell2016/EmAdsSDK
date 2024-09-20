//
//  EmBaseAdRuleManager.h
//  EmCore
//
//  Created by Alan on 2024/5/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <EmCore/EmAdSdkConfig.h>
#import <EmCore/InnerEmAdError.h>
#import <EmCore/EmAdLog.h>
#import <EmCore/EmAdsStatusObject.h>
#import <EmCore/EmAdNativeExpressView.h>
#import <EmCore/EmCGSizeWrapper.h>
#import <EmCore/EmAdBaseAdAdapter.h>


#if __has_include(<EmCore/EmAdSupplierModel.h>)
#import <EmCore/EmAdSupplierModel.h>
#else
#import "EmAdSupplierModel.h"
#endif

#define WeakSelf(type) __weak typeof(type) weak##type = type;
#define StrongSelf(type) __strong typeof(weak##type) strong##type = weak##type;

NS_ASSUME_NONNULL_BEGIN

// 用于记录竞价时，各个渠道的拉取状态
@interface EmLoadStatusObject : NSObject

//@property (nonatomic, assign) NSString *TAG;
@property (nonatomic, assign) BOOL sLoadStatus;
@property (nonatomic, assign) BOOL sLoadedStatus;
@property (nonatomic, strong, nullable) NSError *err;
@property (nonatomic, strong, nullable) EmAdBaseAdAdapter *adapter;
@property (nonatomic, strong, nullable) EmAdSupplier *supplier;
- (BOOL)noLoad;
- (BOOL)isResponse;
- (BOOL)loadSucceed;
- (BOOL)loadError;
- (BOOL)isTimeout;
@end


// 用于执行策略的父类
@interface EmBaseAdRuleManager: NSObject

/// 记录当前策略渠道的各个状态值
@property (nonatomic, strong, nonnull) EmAdsStatusObject *statusObject;

@property (nonatomic, strong, nonnull) EmAdsStatusObject *mixBiddingStatusObject;
@property (nonatomic, strong, nonnull) EmAdsStatusObject *mixWaterfallStatusObject;

/// 总超时时间
@property (nonatomic, assign) NSInteger splashTimeout;

/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!  只有splash 广告类型会使用
@property (nonatomic, assign) BOOL showLogoRequire;

@property (nonatomic, assign) BOOL refreshBannerInterval;


/// 设置广告Logo  只有splash 广告类型会使用
@property (nonatomic, strong) UIImage *logoImage;

/// 广告未加载出来时的占位图  只有splash 广告类型会使用
@property (nonatomic, strong) UIImage *backgroundImage;

/// 只有splash 广告类型会使用
@property (nonatomic, strong) UIImageView *bgImgV;

/// 控制器(在一次广告周期中 不可更改, 不然会引起未知错误)
@property(nonatomic, weak) UIViewController *viewController;

@property(nonatomic, weak) UIView *bannerContainnerView;

@property (nonatomic, strong) EmCGSizeWrapper *nativeExpressAdSizeWrapper;

@property (nonatomic, assign) BOOL isLoadAndShow;

- (void)destoryRule;

- (instancetype)init;
/// 判断传入的JSON是否有效
+ (BOOL)validJson:(NSDictionary *)jsonDic xFor:(NSInteger)ruleType;


//sModel 可能是EmAdSupplierModel（竞价和瀑布） 可能是EmAdMixSupplierModel（混合）
- (void)startRuleEngineWith:(id)sModel;

- (NSError *)showAdWhenRuleFinished;


// 给Adapter 子类调用的方法，需要注意的是有些广告只会调用部分方法， 比如播放之类的只有视频才会调用
- (void)startLoadAdWith: (EmAdSupplier *_Nonnull)supplier;

- (void)loadAdErrorWith: (EmAdSupplier *_Nonnull)supplier err: (NSError *_Nonnull)error;

- (void)loadAdSucceedWith: (EmAdSupplier *_Nonnull)supplier;

- (void)exposureAdSucceedWith: (EmAdSupplier *_Nonnull)supplier;

- (void)closeAdWith: (EmAdSupplier *_Nonnull)supplier;

- (void)clickAdWith: (EmAdSupplier *_Nonnull)supplier;

- (void)skipAdWith: (EmAdSupplier *_Nonnull)supplier;

- (void)playFinishWith: (EmAdSupplier *_Nonnull)supplier err: (nullable NSError *)error;

- (void)splashOnAdCountdownToZero: (EmAdSupplier *_Nonnull)supplier;

- (void)videoDidDownload: (EmAdSupplier *_Nonnull)supplier url:(NSString *_Nonnull)urlString duration: (NSInteger)duration;

- (void)rewardVideoDidRewardEffective:(id)effectiveObj withSupplier:(EmAdSupplier *_Nonnull)supplier;



/// nativeExpress广告准备发起load
- (void)nativeExpressStartLoadAdWith: (EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告拉取失败
- (void)nativeExpressLoadAdWithError:(NSError *_Nonnull)error tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告数据拉取成功
- (void)nativeExpressOnAdLoadSuccess:(nullable NSArray<EmAdNativeExpressView *> *)views tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告曝光
- (void)nativeExpressOnAdShow:(nullable EmAdNativeExpressView *)adView tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告点击
- (void)nativeExpressOnAdClicked:(nullable EmAdNativeExpressView *)adView tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告渲染成功
- (void)nativeExpressOnAdRenderSuccess:(nullable EmAdNativeExpressView *)adView tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告渲染失败
- (void)nativeExpressOnAdRenderFail:(nullable EmAdNativeExpressView *)adView tSupplier:(EmAdSupplier *_Nonnull)supplier;

/// nativeExpress广告被关闭 (注: 百度广告(百青藤), 不支持该回调, 若使用百青藤,则该回到功能请自行实现)
- (void)nativeExpressOnAdClosed:(nullable EmAdNativeExpressView *)adView tSupplier:(EmAdSupplier *_Nonnull)supplier;


@end

NS_ASSUME_NONNULL_END
