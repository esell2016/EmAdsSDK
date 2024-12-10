//
//  EmWinStatusObject.h
//  EmCore
//
//  Created by eselltech on 2024/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmWinStatusObject : NSObject

@property (nonatomic, assign) NSInteger duration;

@property (nonatomic, copy) NSString *materialUrl;

@property (nonatomic, assign) NSInteger secondPrice;//分
// 二价渠道  1        百度2        优量汇 3        穿山甲 4        快手
@property (nonatomic, assign) NSInteger secondChannel;

@end

NS_ASSUME_NONNULL_END

