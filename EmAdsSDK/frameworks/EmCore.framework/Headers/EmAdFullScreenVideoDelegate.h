//
//  EmAdFullScreenVideoDelegate.h
//  AdvanceSDKDev
//
//  Created by CherryKing on 2020/4/13.
//  Copyright © 2020 bayescom. All rights reserved.
//

#ifndef EmAdFullScreenVideoDelegate_h
#define EmAdFullScreenVideoDelegate_h

#import <EmCore/EmAdBaseDelegate.h>

@protocol EmAdFullScreenVideoDelegate <EmAdBaseDelegate>

@optional
/// 视频播放完成
- (void)emAdFullScreenVideoOnAdPlayFinish;


@end

#endif
