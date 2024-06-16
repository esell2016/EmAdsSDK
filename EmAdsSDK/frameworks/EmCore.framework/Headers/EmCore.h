//
//  EmCore.h
//  EmCore
//
//  Created by Alan on 2024/4/21.
//

#import <Foundation/Foundation.h>

//! Project version number for EmCore.
FOUNDATION_EXPORT double EmCoreVersionNumber;

//! Project version string for EmCore.
FOUNDATION_EXPORT const unsigned char EmCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <EmCore/PublicHeader.h>


//#import <EmCore/BdSplashAdapter.h>
//#import <EmCore/GdtSplashAdapter.h>
//#import <EmCore/CsjSplashAdapter.h>
//#import <EmCore/KsSplashAdapter.h>
#import <EmCore/EmAdSplash.h>

//百度不支持Interstitial
//#import <EmCore/GdtInterstitialAdapter.h>
//类已去掉，还在对应目录中，但未拖入工程
//#import <EmCore/CsjInterstitialProAdapter.h>
//#import <EmCore/CsjInterstitialAdapter.h>
//#import <EmCore/KsInterstitialAdapter.h>
#import <EmCore/EmAdInterstitial.h>

//#import <EmCore/BdBannerAdapter.h>
//#import <EmCore/GdtBannerAdapter.h>
//#import <EmCore/CsjBannerAdapter.h>
#import <EmCore/EmAdBanner.h>

//#import <EmCore/BdRewardVideoAdapter.h>
//#import <EmCore/GdtRewardVideoAdapter.h>
//#import <EmCore/CsjRewardVideoAdapter.h>
//#import <EmCore/KsRewardVideoAdapter.h>
#import <EmCore/EmAdRewardVideo.h>

//#import <EmCore/BdFullScreenVideoAdapter.h>
//#import <EmCore/GdtFullScreenVideoAdapter.h>
//#import <EmCore/CsjFullScreenVideoAdapter.h>
//#import <EmCore/KsFullScreenVideoAdapter.h>
#import <EmCore/EmAdFullScreenVideo.h>

//#import <EmCore/BdNativeExpressAdapter.h>
//#import <EmCore/GdtNativeExpressAdapter.h>
//#import <EmCore/CsjNativeExpressAdapter.h>
//#import <EmCore/KsNativeExpressAdapter.h>
#import <EmCore/EmAdNativeExpressView.h>
#import <EmCore/EmAdNativeExpress.h>

#import <EmCore/EmAdCommonDelegate.h>
#import <EmCore/EmAdBannerDelegate.h>
#import <EmCore/EmAdFullScreenVideoDelegate.h>
#import <EmCore/EmAdRewardVideoDelegate.h>
#import <EmCore/EmAdInterstitialDelegate.h>
#import <EmCore/EmAdNativeExpressDelegate.h>
#import <EmCore/EmAdSplashDelegate.h>
#import <EmCore/EmAdBaseDelegate.h>

//#import <EmCore/UIApplication+EmAds.h>
#import <EmCore/EmAdLog.h>
#import <EmCore/EmAdSdkConfig.h>


//#import <EmCore/EmAdModel.h>
//#import <EmCore/NSObject+EmAdModel.h>
//#import <EmCore/EmAdClassInfo.h>

#import <EmCore/InnerEmAdError.h>
#import <EmCore/EmAdSupplierModel.h>


#import <EmCore/EmAdBaseAdAdapter.h>
#import <EmCore/EmAdsStatusObject.h>
#import <EmCore/EmBaseAdObject.h>

#import <EmCore/EmBaseAdRuleManager.h>
//#import <EmCore/EmWaterFallAdRuleManager.h>
//#import <EmCore/EmBiddingAdRuleManager.h>
#import <EmCore/EmCGSizeWrapper.h>

