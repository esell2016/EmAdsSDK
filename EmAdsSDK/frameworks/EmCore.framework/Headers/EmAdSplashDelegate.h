//
//  EmAdSplashProtocol.h
//  AdvanceSDKExample
//
//  Created by CherryKing on 2020/4/8.
//  Copyright © 2020 Mercury. All rights reserved.
//

#ifndef EmAdSplashProtocol_h
#define EmAdSplashProtocol_h

#import <EmCore/EmAdBaseDelegate.h>

@protocol EmAdSplashDelegate <EmAdBaseDelegate>

@optional
/// 广告点击跳过
#pragma 百度广告不支持该回调
- (void)emAdSplashOnAdSkipClicked;

/// 广告倒计时结束回调 百度广告不支持该回调
#pragma 百度广告不支持该回调
- (void)emAdSplashOnAdCountdownToZero;


@end

#endif 
