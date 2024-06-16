//
//  EmAdBaseDelegate.h
//  Pods
//
//  Created by MS on 2020/12/9.
//

#ifndef EmAdBaseDelegate_h
#define EmAdBaseDelegate_h

#import <EmCore/EmAdCommonDelegate.h>

// 策略相关的代理
@protocol EmAdBaseDelegate <EmAdCommonDelegate>

@optional

/// 广告曝光成功
- (void)emAdExposured;

/// 广告点击回调
- (void)emAdClicked;

/// 广告数据请求成功后调用
- (void)emAdUnifiedViewDidLoad;

/// 广告关闭的回调
- (void)emAdDidClose;

@end

#endif /* EmAdBaseDelegate_h */
