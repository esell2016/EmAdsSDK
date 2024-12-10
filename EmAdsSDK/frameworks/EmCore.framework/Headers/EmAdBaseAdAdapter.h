//
//  EmAdBaseAdAdapter.h
//  AdvanceSDK
//
//  Created by MS on 2021/10/12.
//

#import <Foundation/Foundation.h>

#import <EmCore/EmAdLog.h>
#import <EmCore/EmAdSupplierModel.h>

@class EmAdSupplier;

//EmAdBaseAdAdapter 的子类需要实现的协议
@protocol EmAdSubAdapterDelegate <NSObject>

@required
- (void)innerLoad;

- (void)innerShowAd;

- (void)innerDeallocAdapter;

@end

NS_ASSUME_NONNULL_BEGIN
//所有adapter 的基类
@interface EmAdBaseAdAdapter : NSObject

@property (nonatomic, strong) EmAdSupplier *supplier; //渠道信息对象

- (instancetype)initWithSupplier:(EmAdSupplier *)supplier mgr:(id)adspotMgr;


//竞价
//确保广告拉取成功后调用
- (NSInteger)getECPM; //获取价格，单位分


/// 竞价胜利调用
/// - Parameters:
///   - bidEcpm: 胜利的价格(我方)
///   - lossbidEcpm: 失败方的价格（对方）
///   - supplier: 失败方的信息（对方）
- (void)biddingSucceed:(NSInteger)bidEcpm lossEcpm:(NSInteger)lossbidEcpm supplier:(EmAdSupplier *_Nullable)supplier;


/// 竞价失败调用
/// - Parameters:
///   - bidEcpm: 胜利方的价格（对方）
///   - winnerBidType: 胜利方的竞价类型, 固定为3 表示bidding
///   - supplier: 胜利方的信息
- (void)biddingFailed:(NSInteger)bidEcpm winnerBidType:(NSInteger)bidType supplier:(EmAdSupplier *_Nullable)supplier;

// 处理不同平台错误提示命名不一致的问题
- (NSError *)unifyErrorDescription:(NSError *)error fromKey:(NSString *)errorDescKey;

@end

//在规则引擎中调用，放Extension中是不想让其被重载， 此处只关注加载和展示（load and show 的逻辑在manager中处理和EmBaseAdObject的相关子类中处理）
@interface EmAdBaseAdAdapter(PrivateMethod)

- (void)loadAd;

- (void)showAd;

- (void)destoryAdapter;



@end

NS_ASSUME_NONNULL_END
