//
//  EmAdSplash.h
//  Demo
//
//  Created by CherryKing on 2020/11/19.
//

/*
 Outside ——
                EmAdSplash      —— waterFallRuleManager —— 瀑布流逻辑
                                —— biddingRuleManager   —— 竞价逻辑
 
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EmCore/EmBaseAdObject.h>
#import <EmCore/EmAdSdkConfig.h>
#import <EmCore/EmAdSplashDelegate.h>
#import <EmCore/EmBaseAdRuleManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdSplash : EmBaseAdObject

/// 广告方法回调代理
@property (nonatomic, weak) id<EmAdSplashDelegate> delegate;

/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;

/// 设置广告Logo
@property (nonatomic, strong) UIImage *logoImage;

/// 广告未加载出来时的占位图
@property (nonatomic, strong) UIImage *backgroundImage;

/// 总超时时间
@property (nonatomic, assign) NSInteger splashTimeout;

@property (nonatomic, copy) void(^blockLoadStartChannel)(EmAdSupplier *supplier);

@property (nonatomic, copy) void(^blockLoadChannelError)(EmAdSupplier *supplier, NSError *err);

@property (nonatomic, copy) void(^blockLoadChannelSucceed)(EmAdSupplier *supplier);

//竞价
@property (nonatomic, copy) void(^blockStartBidding)(NSArray<EmLoadStatusObject *> *statusObjects);

@property (nonatomic, copy) void(^blockEndBidding)(EmLoadStatusObject *_Nullable statusObject, NSError *_Nullable err);


- (instancetype)initWithJsonDic:(NSDictionary *_Nonnull)jsonDic
                 viewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
