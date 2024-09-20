//
//  EmAdsStatusObject.h
//  EmCore
//
//  Created by Alan on 2024/5/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmAdsStatusObject : NSObject

@property (nonatomic, assign) NSInteger slotId;

@property (nonatomic, assign) NSInteger slotType;

@property (nonatomic, assign) NSInteger bdFlag;

@property (nonatomic, assign) NSInteger ylhFlag;

@property (nonatomic, assign) NSInteger csjFlag;

@property (nonatomic, assign) NSInteger ksFlag;


@property (nonatomic, copy) NSString *channelAppCode;
@property (nonatomic, copy) NSString *channelSlotCode;

@property (nonatomic, assign) NSInteger channel;
@property (nonatomic, assign) NSInteger duration;
@property (nonatomic, assign) NSInteger closeType;
@property (nonatomic, assign) NSInteger price;//分
@property (nonatomic, assign) NSInteger clicked;
@property (nonatomic, copy) NSString *materialUrl;

@property (nonatomic, assign) NSInteger secondPrice;//分
// 二价渠道  1        百度2        优量汇 3        穿山甲 4        快手
@property (nonatomic, assign) NSInteger secondChannel;


- (instancetype)init;


@property (nonatomic, assign) NSInteger bdNoAdFlag; // -1 表示默认， 1表示无广告， 2表示有广告

@property (nonatomic, assign) NSInteger ylhNoAdFlag;

@property (nonatomic, assign) NSInteger csjNoAdFlag;

@property (nonatomic, assign) NSInteger ksNoAdFlag;

@property (nonatomic, assign) NSInteger ruleType; // 规则类型，混合规则时（值为2），isUnSupportChannel恒为NO
///请求过的广告都返回空或者未请求
- (BOOL)isAllEmpty;

/// 所有规则渠道未请求，SDK暂不支持的渠道类型, YES 表示不支持
- (BOOL)isUnSupportChannel;
@end

NS_ASSUME_NONNULL_END


typedef enum : NSInteger {
    ChannelStatusNoAdFlagDefault    = -1,   //默认值
    ChannelStatusNoAdFlagNone       = 1,    //返回广告为空
    ChannelStatusNoAdFlagHas        = 2,    //有广告
} ChannelStatusNoAdFlag;


///广告来源 1        百度2        优量汇 3        穿山甲 4        快手

typedef enum : NSUInteger {
    ChannelAdFromTypeBD = 1, //百度
    ChannelAdFromTypeYLH = 2, //优量汇
    ChannelAdFromTypeCSJ = 3, //穿山甲
    ChannelAdFromTypeKS = 4, //  快手
} ChannelAdFromType;



typedef enum : NSUInteger {
    ChannelStatusFlagNone = 0, //未请求
    ChannelStatusFlagReqNoResponse = 1, //请求未响应
    ChannelStatusFlagReqAndResponse = 2, //请求并响应
    ChannelStatusFlagReqTimeOut = 3, //请求超时
    ChannelStatusFlagReqError = 4 //请求错误
} ChannelStatusFlag;



//1 CLICK_SKIP    跳过 2    COUNT_DOWN_OVER    点击倒计时结束 3    CLICK_JUMP    点击跳转 4    VIDEO_PLAYER_COMPLETE    视频类广告播放完成
typedef enum : NSUInteger {
    ChannelCloseTypeSkip = 1, //跳过或手动点击关闭
    ChannelCloseTypeCountDownOver = 2, //点击倒计时结束
    ChannelCloseTypeJump = 2, //点击跳转
    ChannelCloseTypeVideoPlayerCompleted = 3 //视频类广告播放完成
} ChannelCloseType;

typedef enum : NSUInteger {
    ChannelClickTypeNone = 0, //未点击
    ChannelClickTypeClicked = 1 //已点击
} ChannelClickType;
/*
 
 
 
 ///广告位ID
 var slotId: String?

 ///广告位类型
 var slotType: Int?

 ///0        未请求
 ///1        请求未响应
 ///2        请求并响应
 ///3        请求超时
 ///4        请求错误

 var bdFlag: Int?

 var ylhFlag: Int?

 var csjFlag: Int?

 var ksFlag: Int?

 */
