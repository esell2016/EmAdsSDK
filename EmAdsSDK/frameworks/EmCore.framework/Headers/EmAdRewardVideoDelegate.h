//
//  EmAdRewardVideoProtocol.h
//  AdvanceSDKDev
//
//  Created by CherryKing on 2020/4/9.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef EmAdRewardVideoProtocol_h
#define EmAdRewardVideoProtocol_h

#import <EmCore/EmAdBaseDelegate.h>

@protocol EmAdRewardVideoDelegate <EmAdBaseDelegate>
@optional

/// 广告视频缓存完成
- (void)emAdRewardVideoOnAdVideoCached;

/// 广告视频播放完成
- (void)emAdRewardVideoAdDidPlayFinish;

/// 广告到达激励时间
- (void)emAdRewardVideoAdDidRewardEffective;

@end

#endif
