//
//  EmAdCommonDelegate.h
//  Pods
//
//  Created by MS on 2021/1/16.
//

#ifndef EmAdCommonDelegate_h
#define EmAdCommonDelegate_h

// 策略相关的代理
@protocol EmAdCommonDelegate <NSObject>

@optional

/// 成功加载 并返回 加载的队列的标识
- (void)emAdSuccessSortTag:(NSString *_Nonnull)sortTag;

/// 失败
/// @param error 聚合SDK的错误
/// @param description 每个渠道的错误详情, 部分情况下为nil  key的命名规则: 渠道名-index
- (void)emAdFailedWithError:(NSError *_Nonnull)error description:(NSDictionary *_Nullable)description;

/// 内部渠道开始加载时调用
- (void)emAdSupplierWillLoad:(NSString *_Nonnull)supplierId;
@end

#endif /* EmAdBaseDelegate_h */
