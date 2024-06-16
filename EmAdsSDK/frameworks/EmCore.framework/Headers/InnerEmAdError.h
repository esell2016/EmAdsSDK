//
//  InnerEmAdError.h
//  Demo
//
//  Created by CherryKing on 2020/11/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 策略相关
typedef NS_ENUM(NSUInteger, InnerEmAdErrorCode) {
    InnerEmAdErrorCode_101    =    101,
    InnerEmAdErrorCode_102    =    102,
    InnerEmAdErrorCode_103    =    103,
    InnerEmAdErrorCode_104    =    104,
    InnerEmAdErrorCode_105    =    105,
    InnerEmAdErrorCode_110    =    110,
    InnerEmAdErrorCode_111    =    111,
    InnerEmAdErrorCode_112    =    112,
    InnerEmAdErrorCode_113    =    113,
    InnerEmAdErrorCode_114    =    114,
    InnerEmAdErrorCode_115    =    115,
    InnerEmAdErrorCode_116    =    116,
    InnerEmAdErrorCode_117    =    117
};

@interface InnerEmAdError : NSObject

+ (instancetype)errorWithCode:(InnerEmAdErrorCode)code;

+ (instancetype)errorWithCode:(InnerEmAdErrorCode)code obj:(id)obj;

- (NSError *)toNSError;

@end

NS_ASSUME_NONNULL_END
