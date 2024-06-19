//
//  EmAdLog.h
//  Example
//
//  Created by CherryKing on 2019/11/5.
//  Copyright © 2019 CherryKing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EmCore/EmAdSdkConfig.h>

@class EmAdLog;



#define EAD_LEVEL_FATAL_LOG(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:EmAdLogLevel_Fatal]

#define EAD_LEVEL_ERROR_LOG(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:EmAdLogLevel_Error]

#define EAD_LEVEL_WARING_LOG(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:EmAdLogLevel_Warning]


#define EAD_LEVEL_INFO_LOG(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:EmAdLogLevel_Info]


#define EAD_LEVEL_DEBUG_LOG(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__] level:EmAdLogLevel_Debug]


//1只有甲方开发才打印输出， 默认对外的值为0
#define DEBUGEnvForUS 0

#if DEBUGEnvForUS == 1
    #define EmAdLog(format,...)  [EmAdLog customLogWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]
#else
    #define EmAdLog(format,...)
#endif

//#define EmAdLogJSONData(data)  [EmAdLog logJsonData:data]

NS_ASSUME_NONNULL_BEGIN


@interface EmAdLog : NSObject

// 日志输出方法
+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString level:(EmAdLogLevel)level;

+ (void)customLogWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;

// 记录data类型数据
//+ (void)logJsonData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
