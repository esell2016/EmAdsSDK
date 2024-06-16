//
//  EmAdNativeExpressView.h
//  AdvanceSDK
//
//  Created by MS on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdNativeExpressView : NSObject

- (instancetype)initWithViewController:(UIViewController *)controller;
// 信息流view
@property (nonatomic, strong) UIView *expressView;

@property (nonatomic, strong) id ksFeedAd;
//// 渠道标识
//@property (nonatomic, copy) NSString *identifier;

- (void)render;

// 百度需要在nativeExpress展示在界面的时候上报给百度官方, 不然计费可能不准确
- (void)trackImpression;
- (void)destroyExpressView;

@end

NS_ASSUME_NONNULL_END
