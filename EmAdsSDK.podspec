#
# Be sure to run `pod lib lint EmAdsSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'EmAdsSDK'
  s.version          = '1.0.7'
  #  summary 在140 个字符以内
  s.summary      = "EmAdsSDK 是一款广告变现的 SDK，由Esell公司研发，将百度、穿山甲、快手、腾讯广告联盟集合到一起，支持瀑布和竞价方式展示广告，使您的收益最大化。"


# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
        EmAdsSDK初始化
  Swift 语言:
        在入口AppDelegate类中的 func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool 方法中增加下方代码：
            import EmAds
            EmAdsSDK.initSDK(launchOptions: launchOptions, isDebug: true, emlAppId: "填写你易售申请的APPID") { err in
                if err.code == .succeed {
                    //初始化成功，每次启动仅有一次执行
                } else {
                    //初始化失败，此逻辑可能会多次执行
                }
            }
        
    Objective-C语言:
        在入口AppDelegate类 的方法 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中增加下方代码：
            #import <EmAds/EmAds.h>
            [EmAdsSDK initSDKWithLaunchOptions:launchOptions isDebug:YES emlAppId:@"填写你易售申请的APPID" resultHandler:^(EmAdError * _Nonnull err) {
                if(err.code == EmAdErrorCodeSucceed) {
                    //初始化成功，每次启动仅有一次执行
                } else {
                    //初始化失败，此逻辑可能会多次执行
                }
            }];
                       DESC

  s.homepage         = 'https://github.com/esell2016/EmAdsSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author        = { "esell2016" => "zhengqisi@eselltech.com" }
  # s.source           = { :git => 'https://github.com/esell2016/EmAdsSDK.git', :tag => "v#{s.version}" }
  s.source           = { :git => 'https://github.com/esell2016/EmAdsSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform     = :ios, '9.0'
  s.ios.deployment_target = '9.0'
   # 指定支持的架构
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'arm64',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386 x86_64'
  }
  s.user_target_xcconfig = {
    'VALID_ARCHS' => 'arm64',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386 x86_64'
  }

  s.requires_arc = true

  # s.source_files = 'EmAdsSDK/XCFrameworks/**/*'
  s.vendored_frameworks = [
    'EmAdsSDK/frameworks/KSAdSDK.xcframework',
    'EmAdsSDK/frameworks/EmCore.framework',
    'EmAdsSDK/frameworks/EmAds.framework'
  ]
      
      
  s.resource_bundles = {
  #   'EmAdsSDK' => ['EmAdsSDK/Assets/*.png']
    'EmAdsSDK' => ['EmAdsSDK/frameworks/*.bundle']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
