//
//  EmAdNativeExpress.h
//  AdvanceSDKDev
//
//  Created by CherryKing on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//


#import <EmCore/EmBaseAdObject.h>
#import <UIKit/UIKit.h>
#import <EmCore/EmAdSdkConfig.h>
#import <EmCore/EmAdNativeExpressDelegate.h>
#import <EmCore/EmCGSizeWrapper.h>
#import <EmCore/EmBaseAdRuleManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdNativeExpress: EmBaseAdObject
/// 广告方法回调代理
@property (nonatomic, weak) id<EmAdNativeExpressDelegate> delegate;

@property (nonatomic, assign) CGSize adSize;

@property (nonatomic, copy) void(^blockLoadStartChannel)(EmAdSupplier *supplier);

@property (nonatomic, copy) void(^blockLoadChannelError)(EmAdSupplier *supplier, NSError *err);

@property (nonatomic, copy) void(^blockLoadChannelSucceed)(EmAdSupplier *supplier);


//竞价
@property (nonatomic, copy) void(^blockStartBidding)(NSArray<EmLoadStatusObject *> *statusObjects);

@property (nonatomic, copy) void(^blockEndBidding)(EmLoadStatusObject *_Nullable statusObject, NSError *_Nullable err);


/// 构造函数
/// @param jsonDic 数据
/// @param viewController viewController
/// @param size 尺寸
- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic
                 viewController:(UIViewController *)viewController
                         adSize:(CGSize)size;


@end


NS_ASSUME_NONNULL_END


