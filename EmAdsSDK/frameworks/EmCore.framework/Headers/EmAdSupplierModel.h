//
//  EmAdSupplierModel.h
//  Demo
//
//  Created by CherryKing on 2020/11/18.
//

#import <Foundation/Foundation.h>

@class EmAdSupplierModel;
@class EmAdSetting;
@class EmAdSupplier;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Object interfaces
//策略信息
@interface EmAdSupplierModel : NSObject

@property (nonatomic, strong) NSMutableArray<EmAdSetting *> *rules;
@property (nonatomic, strong) NSMutableArray<EmAdSupplier *> *suppliers;
@property (nonatomic, copy) NSString *sortTag;
@property (nonatomic, assign) NSInteger ruleType;   //1 瀑布流 2竞价
@property (nonatomic, assign) NSInteger slotId;     //策略id

@end

//策略中的单条规则信息
@interface EmAdSetting : NSObject

@property (nonatomic, strong) NSMutableArray<NSNumber *> *sort;
@property (nonatomic, assign) NSInteger percent;
@property (nonatomic, copy)   NSString *tag;

@end

//渠道信息
@interface EmAdSupplier : NSObject
@property (nonatomic, copy)   NSString *appId;
@property (nonatomic, copy)   NSString *adspotId;
@property (nonatomic, copy)   NSString *tag;
@property (nonatomic, strong)   NSNumber *index;
@property (nonatomic, assign) NSInteger adType;
@property (nonatomic, assign) NSInteger ecpm; // 20240605日后新增
@property (nonatomic, assign) NSInteger idfaEnabled; //20240618
@property (nonatomic, copy)   NSString *idfa;

//渠道  1        百度2        优量汇 3        穿山甲 4        快手
@property (nonatomic, assign, readonly) NSInteger channelType;


@end

NS_ASSUME_NONNULL_END
