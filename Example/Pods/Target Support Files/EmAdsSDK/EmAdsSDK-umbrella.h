#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "EmAds-Swift.h"
#import "EmAds.h"
#import "EmAds-Swift.h"
#import "EmAds.h"
#import "EmAdBanner.h"
#import "EmAdBannerDelegate.h"
#import "EmAdBaseAdAdapter.h"
#import "EmAdBaseDelegate.h"
#import "EmAdCommonDelegate.h"
#import "EmAdFullScreenVideo.h"
#import "EmAdFullScreenVideoDelegate.h"
#import "EmAdInterstitial.h"
#import "EmAdInterstitialDelegate.h"
#import "EmAdLog.h"
#import "EmAdNativeExpress.h"
#import "EmAdNativeExpressDelegate.h"
#import "EmAdNativeExpressView.h"
#import "EmAdRewardVideo.h"
#import "EmAdRewardVideoDelegate.h"
#import "EmAdSdkConfig.h"
#import "EmAdSplash.h"
#import "EmAdSplashDelegate.h"
#import "EmAdsStatusObject.h"
#import "EmAdSupplierModel.h"
#import "EmBaseAdObject.h"
#import "EmBaseAdRuleManager.h"
#import "EmCGSizeWrapper.h"
#import "EmCore.h"
#import "InnerEmAdError.h"
#import "EmAdBanner.h"
#import "EmAdBannerDelegate.h"
#import "EmAdBaseAdAdapter.h"
#import "EmAdBaseDelegate.h"
#import "EmAdCommonDelegate.h"
#import "EmAdFullScreenVideo.h"
#import "EmAdFullScreenVideoDelegate.h"
#import "EmAdInterstitial.h"
#import "EmAdInterstitialDelegate.h"
#import "EmAdLog.h"
#import "EmAdNativeExpress.h"
#import "EmAdNativeExpressDelegate.h"
#import "EmAdNativeExpressView.h"
#import "EmAdRewardVideo.h"
#import "EmAdRewardVideoDelegate.h"
#import "EmAdSdkConfig.h"
#import "EmAdSplash.h"
#import "EmAdSplashDelegate.h"
#import "EmAdsStatusObject.h"
#import "EmAdSupplierModel.h"
#import "EmBaseAdObject.h"
#import "EmBaseAdRuleManager.h"
#import "EmCGSizeWrapper.h"
#import "EmCore.h"
#import "InnerEmAdError.h"
#import "KSAd.h"
#import "KSAdBiddingAdModel.h"
#import "KSAdCouponData.h"
#import "KSAdDeviceInfoEnum.h"
#import "KSAdExportManager.h"
#import "KSAdExposureReportParam.h"
#import "KSAdExtraDataModel.h"
#import "KSAdImage.h"
#import "KSAdInfoData.h"
#import "KSAdInteractionType.h"
#import "KSAdLiveBaseData.h"
#import "KSAdLiveInfoData.h"
#import "KSAdLiveShopData.h"
#import "KSAdNativeAdExtraDataModel.h"
#import "KSAdNativeAdStatusInfo.h"
#import "KSAdNativeStyleControl.h"
#import "KSAdPermission.h"
#import "KSAdPlayableDemoViewController.h"
#import "KSAdSDK-umbrella.h"
#import "KSAdSDK.h"
#import "KSAdSDKConfiguration.h"
#import "KSAdSDKError.h"
#import "KSAdSDKLogLevelDefine.h"
#import "KSAdSDKManager.h"
#import "KSAdShowDirection.h"
#import "KSAdSplashAdExtraDataModel.h"
#import "KSAdUserInfo.h"
#import "KSDrawAd.h"
#import "KSDrawAdsManager.h"
#import "KSEUExtraInfo.h"
#import "KSFeedAd.h"
#import "KSFeedAdsManager.h"
#import "KSFullscreenVideoAd.h"
#import "KSInnerVideoAd.h"
#import "KSInterstitialAd.h"
#import "KSMaterialMeta.h"
#import "KSNativeAd.h"
#import "KSNativeAdRelatedView.h"
#import "KSNativeAdsManager.h"
#import "KSRewardedVideoAd.h"
#import "KSRewardedVideoAdDefines.h"
#import "KSRewardedVideoModel.h"
#import "KSSplashAdView.h"
#import "KSVideoAd.h"
#import "KSVideoAdView.h"
#import "KSAd.h"
#import "KSAdBiddingAdModel.h"
#import "KSAdCouponData.h"
#import "KSAdDeviceInfoEnum.h"
#import "KSAdExportManager.h"
#import "KSAdExposureReportParam.h"
#import "KSAdExtraDataModel.h"
#import "KSAdImage.h"
#import "KSAdInfoData.h"
#import "KSAdInteractionType.h"
#import "KSAdLiveBaseData.h"
#import "KSAdLiveInfoData.h"
#import "KSAdLiveShopData.h"
#import "KSAdNativeAdExtraDataModel.h"
#import "KSAdNativeAdStatusInfo.h"
#import "KSAdNativeStyleControl.h"
#import "KSAdPermission.h"
#import "KSAdPlayableDemoViewController.h"
#import "KSAdSDK-umbrella.h"
#import "KSAdSDK.h"
#import "KSAdSDKConfiguration.h"
#import "KSAdSDKError.h"
#import "KSAdSDKLogLevelDefine.h"
#import "KSAdSDKManager.h"
#import "KSAdShowDirection.h"
#import "KSAdSplashAdExtraDataModel.h"
#import "KSAdUserInfo.h"
#import "KSDrawAd.h"
#import "KSDrawAdsManager.h"
#import "KSEUExtraInfo.h"
#import "KSFeedAd.h"
#import "KSFeedAdsManager.h"
#import "KSFullscreenVideoAd.h"
#import "KSInnerVideoAd.h"
#import "KSInterstitialAd.h"
#import "KSMaterialMeta.h"
#import "KSNativeAd.h"
#import "KSNativeAdRelatedView.h"
#import "KSNativeAdsManager.h"
#import "KSRewardedVideoAd.h"
#import "KSRewardedVideoAdDefines.h"
#import "KSRewardedVideoModel.h"
#import "KSSplashAdView.h"
#import "KSVideoAd.h"
#import "KSVideoAdView.h"

FOUNDATION_EXPORT double EmAdsSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char EmAdsSDKVersionString[];
