//
//  EmAdNativeExpressProtocol.h
//  AdvanceSDKDev
//
//  Created by CherryKing on 2020/4/9.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef EmAdNativeExpressProtocol_h
#define EmAdNativeExpressProtocol_h

#import <EmCore/EmAdCommonDelegate.h>

@class EmAdNativeExpressView;

@protocol EmAdNativeExpressDelegate <EmAdCommonDelegate>

@optional
/// 广告数据拉取成功
- (void)emAdNativeExpressOnAdLoadSuccess:(nullable NSArray<EmAdNativeExpressView *> *)views;

/// 广告曝光
- (void)emAdNativeExpressOnAdShow:(nullable EmAdNativeExpressView *)adView;

/// 广告点击
- (void)emAdNativeExpressOnAdClicked:(nullable EmAdNativeExpressView *)adView;

/// 广告渲染成功
- (void)emAdNativeExpressOnAdRenderSuccess:(nullable EmAdNativeExpressView *)adView;

/// 广告渲染失败
- (void)emAdNativeExpressOnAdRenderFail:(nullable EmAdNativeExpressView *)adView;

/// 广告被关闭 (注: 百度广告(百青藤), 不支持该回调, 若使用百青藤,则该回到功能请自行实现)
- (void)emAdNativeExpressOnAdClosed:(nullable EmAdNativeExpressView *)adView;

@end

#endif
