//
//  EmAdFullScreenVideo.h
//  AdvanceSDKDev
//
//  Created by CherryKing on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#import <EmCore/EmBaseAdObject.h>
#import <UIKit/UIKit.h>
#import <EmCore/EmAdSdkConfig.h>
#import <EmCore/EmAdFullScreenVideoDelegate.h>
#import <EmCore/EmBaseAdRuleManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdFullScreenVideo : EmBaseAdObject
/// 广告方法回调代理
@property (nonatomic, weak) id<EmAdFullScreenVideoDelegate> delegate;

- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic
                           xFor:(NSInteger)ruleType
                 viewController:(UIViewController *)viewController;

//外部调用
@property (nonatomic, copy) void(^blockLoadStartChannel)(EmAdSupplier *supplier);

@property (nonatomic, copy) void(^blockLoadChannelError)(EmAdSupplier *supplier, NSError *err);

@property (nonatomic, copy) void(^blockLoadChannelSucceed)(EmAdSupplier *supplier);


//竞价
@property (nonatomic, copy) void(^blockStartBidding)(NSArray<EmLoadStatusObject *> *statusObjects);

@property (nonatomic, copy) void(^blockEndBidding)(EmLoadStatusObject *_Nullable statusObject, NSError *_Nullable err);


@end

NS_ASSUME_NONNULL_END
