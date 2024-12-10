//
//  EmTempBaseAdapter.h
//  EmCore
//
//  Created by Alan on 2024/5/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <EmCore/EmAdSupplierModel.h>
#import <EmCore/EmAdsStatusObject.h>
#import <EmCore/EmBaseAdRuleManager.h>


NS_ASSUME_NONNULL_BEGIN

@interface EmBaseAdObject : NSObject

/// 读取当前策略的各个状态值
@property (nonatomic, strong, readonly) NSMutableArray<EmAdsStatusObject *> *statusObjectList;
@property (nonatomic, strong, readonly) NSString *no;

@property (nonatomic, assign, readonly) NSInteger ruleType;

/// 瀑布流模式 0-正常模式 1-并行模式
@property (nonatomic, assign) NSInteger waterFillModel;
/// 并行请求模式  0-固定的数量代码位并行请求 1-相同代码位并行请求
@property (nonatomic, assign) NSInteger waterFillParallelModel;
/// 瀑布流并行请求数
@property (nonatomic, assign) NSInteger waterFillParallelNum;
/// 单次请求超时时间
@property (nonatomic, assign) NSInteger onceTimeout;
/// 总请求超时时间
//@property (nonatomic, assign) NSInteger allTimeout;
/// 竞价总请求超时时间
@property (nonatomic, assign) NSInteger biddingAllTimeout;
/// 瀑布流总请求超时时间
@property (nonatomic, assign) NSInteger waterAllTimeout;

/// 控制器(在一次广告周期中 不可更改, 不然会引起未知错误)
@property(nonatomic, weak) UIViewController *viewController;

/// 渠道比例映射
@property (nonatomic, strong) NSDictionary *channelMap;

/// 初始化方法
/// @param jsonDic  策略广告的策略信息 json格式请参考 DataJson目录下的.json文件
- (instancetype)initWithJsonDic:(NSDictionary *_Nonnull)jsonDic xFor:(NSInteger)ruleType;

///所有策略都执行失败， 广告对象加载规则过程只会执行一次
@property (nonatomic, copy) void(^blockLoadAllChannelFailed)(NSError *_Nonnull err);

/// 策略执行后，可以调用Query接口， 广告对象加载规则过程只会执行一次
@property (nonatomic, copy) void(^blockNeedAdReportQuery)(void);

@property (nonatomic, copy) void(^blockLog)(NSString *msg);

/// 判断传入的JSON是否有效
+ (BOOL)validJson:(NSDictionary *)jsonDic xFor:(NSInteger)ruleType;

/// 加载广告
- (void)loadAdOnly;

/// 展示广告,  与loadAdOnly 配对使用
- (nullable NSError *)showAd;

/// 加载并展现（需要注意的是，nativeExpress不支持此方法调用，需要在外面处理显示逻辑）
- (void)loadAndShowAd;

/// 销毁
- (void)destorySelf;

/// getter
- (EmBaseAdRuleManager *)getCurrentRuleManager;

///所有规则渠道未请求，SDK暂不支持的渠道类型, YES 表示不支持
- (BOOL)isUnSupportChannel;
//请求过的广告都返回空或者未请求
- (BOOL)isAllEmpty;

@end

NS_ASSUME_NONNULL_END
