//
//  EmAdInterstitial.h
//  AdvanceSDKExample
//
//  Created by CherryKing on 2020/4/7.
//  Copyright © 2020 Mercury. All rights reserved.
//

#import <EmCore/EmBaseAdObject.h>
#import <UIKit/UIKit.h>

#import <EmCore/EmAdSdkConfig.h>
#import <EmCore/EmAdInterstitialDelegate.h>
#import <EmCore/EmBaseAdRuleManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdInterstitial : EmBaseAdObject
/// 广告方法回调代理
@property (nonatomic, weak) id<EmAdInterstitialDelegate> delegate;

@property (nonatomic, copy) void(^blockLoadStartChannel)(EmAdSupplier *supplier);

@property (nonatomic, copy) void(^blockLoadChannelError)(EmAdSupplier *supplier, NSError *err);

@property (nonatomic, copy) void(^blockLoadChannelSucceed)(EmAdSupplier *supplier);

//竞价
@property (nonatomic, copy) void(^blockStartBidding)(NSArray<EmLoadStatusObject *> *statusObjects);

@property (nonatomic, copy) void(^blockEndBidding)(EmLoadStatusObject *_Nullable statusObject, NSError *_Nullable err);

- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic
                           xFor:(NSInteger)ruleType
                 viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
