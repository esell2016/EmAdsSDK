
# 历史版本，iOS EmAdsSDK更新日志

## 2024-07-04      SDK 1.0.6
1、修复已知问题，优化超时逻辑

## 2024-06-19      SDK 1.0.5
1、增加idfa的开关，增加对应的SDK初始化方法，详见代码集成部分
2、增加对iOS 17的支持，增加.xcprivacy文件
3、修复部分已知问题

## 2024-06-16      SDK 1.0.3
1、增加使用Cocoapods自动集成

## 2024-06-05      SDK 1.0.3
1、EmCore.framework,EmAds.framework代码内部处理

## 2024-06-03      SDK 1.0.2
1、重构瀑布流规则代码；
2、增加竞价规则代码；

## 2024-05-22      SDK 1.0.1
1、优化SDK， 快手渠道的Intersititial广告声音无法关闭的问题
2、将其它渠道视频广告能关闭的声音关闭掉
「
快手的只有插屏Interstitial可以关，其它的也关不掉
百度联盟 的都不能关闭
优量汇的，NativeExpress RewardVideo FullScreenVideo Interstitial 可以关闭， Banner&Splash忽略
穿山甲的，都没有设置静音的功能
」

## 2024-05-21      SDK 1.0.0 
1、修复EmAds.framework 1.0.0 iOS 12 运行crash 的问题

## 2024-05-20      SDK 1.0.0 
1、版本修改，EmAds.framework 1.0.0, 版本号不改变，支持iOS 9+（含iOS 9）手动导入&通过编译，不crash， 但仅支持iOS 13+ 才能初始化成功并展示广告，优化LOG输出；
2、增加iOS 13-，调用SDK初始化方法时，返回错误code 20988；

## 2024-05-15      SDK 1.0.0 
1、初始版本，EmAds.framework 1.0.0，支持iOS 13+（含iOS 13）手动导入，完善Objective-C和Swift 的引入代码说明；


# 接入前提：
本SDK与百度联盟，穿山甲，优量汇，快手联盟的SDK有冲突，若您的项目已经集成，请先移除。

# 使用Cocoapods自动集成
## 在Podfile 中增加
```ruby
pod 'EmAdsSDK', '~> 1.0.6'
``` 
  
## 在info.plist 增加
```Objective-C
    SKAdNetworkItems - Array
    item0 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>r3y5dwb26t.skadnetwork</string>
    item1 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>238da6jt44.skadnetwork</string>
    item2 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>22mmun2rn5.skadnetwork</string>


    App Transport Security Settings - Dictionary
    <key>NSAllowsArbitraryLoads</key>
    <true/>
   

    NSUserTrackingUsageDescription 对应值 "APP需要使用您的IDFA跟踪展示广告信息" //值可自定义
```
## 代码集成见【三、代码集成】
    
## FAQ: 在Xcode 15环境中使用 pod install 安装运行后build, 您可能会遇到错误：
```
    Sandbox: rsync.samba(12698) deny(1) file-write-create /Users/shrek/Library/Developer/Xcode/DerivedData/PhotoPC-dejmlgrmwbxazrgvfwpxvhadwsuy/Build/Products/Debug-iphonesimulator/PhotoPC.app/Frameworks/Alamofire.framework/.Alamofire.ihLdr1

    Sandbox: rsync.samba(12698) deny(1) file-write-create /Users/shrek/Library/Developer/Xcode/DerivedData/PhotoPC-dejmlgrmwbxazrgvfwpxvhadwsuy/Build/Products/Debug-iphonesimulator/PhotoPC.app/Frameworks/Alamofire.framework/.Info.plist.vn2fty
    】
    
    要解决此错误，您可以尝试在BuildSetting中 将User Script Sandboxing 设置为NO。
```
# 手动集成

## 一、库文件说明(目前仅支持真机)
```
    baidumobadsdk.bundle—— 百度联盟的资源文件
    CSJAdSDK.bundle —— 穿山甲联盟的资源文件
    EmAds.framework —— EmAdsSDK
    EmCore.framework —— EmAdsSDK内部引擎&基础代码
    KSAdSDK.xcframework —— 快手联盟的SDK
    README —— 接入文档
```
    注意： 本SDK支持iOS 9+ （含iOS 9）编译通过，但所有广告位均只支持iOS 13 + （含iOS 13），  针对 < iOS 13 系统，执行初始化代码时会提示初始化不成功，抛出20988错误码。

## 二、手动导入SDK

### 1、将EmAdsSDK-1.0.6/EmAdsSDK/frameworks 文件夹（README文件可以不需要）拖进Xcode Project工程， 勾选copy items if needed

### 2、选中目标Target, 切换到General选项卡, 滑动到Frameworks, Libraries, and Embedded Content栏, 将EmAds.framework，EmCore.framework，KSAdSDK.xcframework的Embed属性设置为Embed & Sign

### 3、选中目标Target，在其info 配置中添加配置
```
    SKAdNetworkItems - Array
    item0 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>r3y5dwb26t.skadnetwork</string>
    item1 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>238da6jt44.skadnetwork</string>
    item2 - Dictionary
        <key>SKAdNetworkIdentifier</key>
        <string>22mmun2rn5.skadnetwork</string>


    App Transport Security Settings - Dictionary
    <key>NSAllowsArbitraryLoads</key>
    <true/>

    Privacy - Tracking Usage Description 对应值 "APP需要使用您的IDFA跟踪展示广告信息"
```
### 4、导入系统库：暂不需要手动导入

## 三、代码集成

### 1、 在AppDelegate 中添加属性window，GDTModSDK 的BUG，若去掉， GDTModSDK有概率Crash
#### Swift
```Swift
    var window: UIWindow?
```
#### Objective-C
```Objective-C
    @property (nonatomic, strong) UIWindow *window;
```
### 2、 增加初始化代码
#### Swift
在入口AppDelegate类中的 func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool 方法中增加下方代码：
```Swift
    import EmAds
    //调用此方法 默认idfaEnabled 为不开启状态
    EmAdsSDK.initSDK(launchOptions: launchOptions, isDebug: true, emlAppId: "填写你易售申请的APPID") { err in
        if err.code == .succeed {
                    //初始化成功，每次启动仅有一次执行
        } else {
                    //初始化失败，此逻辑可能会多次执行
        }
    }
    
    或者
    //调用此方法 idfaEnabled = true 为开启状态，必须在info.plist 增加NSUserTrackingUsageDescription
    EmAdsSDK.initSDK(launchOptions: launchOptions, isDebug: true, emlAppId: "填写你易售申请的APPID", idfaEnabled: true) { err in
        if err.code == .succeed {
                    //初始化成功，每次启动仅有一次执行
        } else {
                    //初始化失败，此逻辑可能会多次执行
        }
    }
    
        
    isDebug = true 表示控制台输出SDK内部日志
```
#### Objective-C
在入口AppDelegate类 的方法 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 中增加下方代码：
```Objective-C 
    #import <EmAds/EmAds.h>
    //调用此方法 默认idfaEnabled 为不开启状态
    [EmAdsSDK initSDKWithLaunchOptions:launchOptions isDebug:YES emlAppId:@"填写你易售申请的APPID" resultHandler:^(EmAdError * _Nonnull err) {
        if(err.code == EmAdErrorCodeSucceed) {
            //初始化成功，每次启动仅有一次执行
        } else {
            //初始化失败，此逻辑可能会多次执行
        }
    }];
        
    或者
    //调用此方法 idfaEnabled = true 为开启状态，必须在info.plist 增加NSUserTrackingUsageDescription
    [EmAdsSDK initSDKWithLaunchOptions:launchOptions isDebug:YES emlAppId:@"填写你易售申请的APPID" idfaEnabled:YES resultHandler:^(EmAdError * _Nonnull err) {
        if(err.code == EmAdErrorCodeSucceed) {
            //初始化成功，每次启动仅有一次执行
        } else {
            //初始化失败，此逻辑可能会多次执行
        }
    }];
    isDebug = YES 表示控制台输出SDK内部日志
```

### 3、广告集成
#### 1、Splash 广告集成
#### Swift
```Swift
    import EmAds
    class SplashViewController: UIViewController {
        var splash: EmSplash?
        override func viewDidLoad() {
            super.viewDidLoad()
        }

        @IBAction func btnClickedAction(_ sender: UIButton) {
            self.splash = EmSplash.init(viewController: self, delegate: self)
            self.splash!.loadAndShow()  //加载并展示
        }
        
        @IBAction func btnClickedAction4(_ sender: UIButton) {
            self.splash?.destroy()      //销毁， 关闭广告时也会自动销毁， 可以重复调用
        }
        
    }

    extension SplashViewController: EmSplashDelegate {
        func onSplashComplete() {
            //广告倒计时结束的回调， 有些渠道不会执行此回调，会走onAdClose 回调
        }
        
        func onSplashSkip() {
            //广告跳过动作的回调， 有些渠道不会执行此回调，会走onAdClose 回调
        }
        
        func onAdSucceed() {
             //广告加载成功的回调
        }
        
        func onAdClose() {
             //广告被关闭的回调 
        }
        
        func onAdExposure() {
             //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError) {
            //广告获取错误的回调，获取未能获取到广告等错误
        }
        
        func onAdClicked() {
            //广告被点击的回调
        }
    }
```    
           
#### Objective-C
```Objective-C
    #import <EmAds/EmAds.h>

    @interface SplashViewController ()<EmSplashDelegate>

    @property (nonatomic, strong) EmSplash *splash;

    @end

    @implementation SplashViewController

    - (void)viewDidLoad {
        [super viewDidLoad];
        // Do any additional setup after loading the view.
    }

    - (IBAction)splashBtnAction:(UIButton *)sender {
        self.splash = [[EmSplash alloc] initWithViewController:self delegate:self];
        [self.splash loadAndShow]; //加载并展示
    }

    - (IBAction)splashBtnAction4:(UIButton *)sender {
        if(self.splash != nil) {
            [self.splash destroy]; //销毁， 关闭广告时也会自动销毁， 可以重复调用
        }
    }


    #pragma mark EmSplashDelegate


    - (void)onAdClicked { 
        SOCDemoDebugLog(@"EmSplashDelegate onAdClicked");   //广告被点击的回调
    }

    - (void)onAdClose { 
        SOCDemoDebugLog(@"EmSplashDelegate onAdClose");     //广告被关闭的回调
    }

    - (void)onAdExposure { 
        SOCDemoDebugLog(@"EmSplashDelegate onAdExposure");  //广告被曝光的回调
        
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error { //广告获取错误的回调，获取未能获取到广告等错误
        NSString *str = [NSString stringWithFormat:@"EmSplashDelegate onAdExposure error: %@", error];
        SOCDemoDebugLog(str);
    }

    - (void)onAdSucceed { 
        SOCDemoDebugLog(@"EmSplashDelegate onAdSucceed");   //广告加载成功的回调
        
    }

    - (void)onSplashComplete { 
        SOCDemoDebugLog(@"EmSplashDelegate onSplashComplete");  //广告倒计时结束的回调，有些渠道不会执行此回调，会走onAdClose 回调
    }

    - (void)onSplashSkip {
        SOCDemoDebugLog(@"EmSplashDelegate onSplashSkip");  //广告跳过动作的回调， 有些渠道不会执行此回调，会走onAdClose 回调
    }

    @end
```
## 2、Interstitial 广告集成
    
#### Swift
```Swift
    import EmAds
    class InterstitialViewController: UIViewController {
        var interstitial: EmInterstitial?
        override func viewDidLoad() {
            super.viewDidLoad()
        }

        @IBAction func btnInterstitialClickedAction(_ sender: UIButton) {
            self.interstitial = EmInterstitial.init(viewController: self, delegate: self)
            self.interstitial!.loadAndShow() //加载并展示广告
        }
        
        @IBAction func btnInterstitialClickedAction2(_ sender: UIButton) {
            self.interstitial = EmInterstitial.init(viewController: self, delegate: self)
            self.interstitial!.loadOnly()   //只加载广告，但不展示
        }
        
        @IBAction func btnInterstitialClickedAction3(_ sender: UIButton) {
            self.interstitial?.show()       //展示已经加载的广告，与loadOnly() 配合使用
        }
        
        
        @IBAction func btnInterstitialClickedAction4(_ sender: UIButton) {
            self.interstitial?.destroy()    //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
    }

    extension InterstitialViewController: EmInterstitialDelegate {
        
        func onAdSucceed() {
            //广告加载成功的回调
        }
        
        func onAdClose() {
            //广告被关闭的回调
        }
        
        func onAdExposure() {
            //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError) {
            //广告获取错误的回调，获取未能获取到广告等错误
        }
        
        func onAdClicked() {
            //广告被点击的回调
        }
        
        
    }
```
#### Objective-C
```Objective-C
    #import <EmAds/EmAds.h>

    @interface InterstitialViewController ()<EmInterstitialDelegate>

    @property (nonatomic, strong) EmInterstitial *interstitial;

    @end

    @implementation InterstitialViewController

    - (void)viewDidLoad {
        [super viewDidLoad];
        // Do any additional setup after loading the view.
    }

    - (IBAction)interstitialBtnAction:(UIButton *)sender {
        self.interstitial = [[EmInterstitial alloc] initWithViewController:self delegate:self];
        [self.interstitial loadAndShow];    //加载并展示广告
    }


    - (IBAction)interstitialBtnAction2:(UIButton *)sender {
        self.interstitial = [[EmInterstitial alloc] initWithViewController:self delegate:self];
        [self.interstitial loadOnly];   //只加载广告，但不展示
    }


    - (IBAction)interstitialBtnAction3:(UIButton *)sender {
        if(self.interstitial != nil) {
            [self.interstitial show];   //展示已经加载的广告，与loadOnly 配合使用
        }
    }


    - (IBAction)interstitialBtnAction4:(UIButton *)sender {
        if(self.interstitial != nil) {
            [self.interstitial destroy];     //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
    }



    #pragma mark EmInterstitialDelegate

    - (void)onAdClicked {
        //广告被点击的回调
    }

    - (void)onAdClose {
        //广告被关闭的回调
    }

    - (void)onAdExposure {
        //广告被曝光的回调
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error {
        //广告获取错误的回调，获取未能获取到广告等错误
    }

    - (void)onAdSucceed {
        //广告加载成功的回调
    }

    @end
```
## 3、 Banner 广告集成
        
#### Swift
```Swift
    import EmAds
    class BannerViewController: UIViewController {

        @IBOutlet weak var adContannerView: UIView!
        var banner: EmBanner?
        
        override func viewDidLoad() {
            super.viewDidLoad()
        }

        @IBAction func btnBannerClickedAction(_ sender: UIButton) {
            self.banner = EmBanner.init(viewController: self, adContainer: self.adContannerView, delegate: self)
            self.banner!.loadAndShow() //加载并展示广告
        }
        
        @IBAction func btnBannerClickedAction4(_ sender: UIButton) {
            self.banner?.destroy()  //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁， 销毁时会从界面移除
        }
        
    }

    extension BannerViewController: EmBannerDelegate {
        
        func onAdSucceed() {
            //广告加载成功的回调
        }
        
        func onAdClose() {
            //广告被关闭的回调
        }
        
        func onAdExposure() {
            //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError) {
            //广告获取错误的回调，获取未能获取到广告等错误
        }
        
        func onAdClicked() {
            //广告被点击的回调
        }
    }
```
        
#### Objective-C
```Objective-C
    #import <EmAds/EmAds.h>

    @interface BannerViewController ()<EmBannerDelegate>

    @property (nonatomic, strong) EmBanner *banner;
    @property (weak, nonatomic) IBOutlet UIView *adContainnerView;

    @end

    @implementation BannerViewController

    - (void)viewDidLoad {
        [super viewDidLoad];
    }

    - (IBAction)bannerBtnAction:(UIButton *)sender {
        self.banner = [[EmBanner alloc] initWithViewController:self adContainer:self.adContainnerView delegate:self];
        [self.banner loadAndShow];  //加载并展示广告
    }

    - (IBAction)bannerBtnAction4:(UIButton *)sender {
        [self.banner destroy];  //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁， 销毁时会从界面移除
    }



    #pragma mark EmBannerDelegate


    - (void)onAdClicked {
        //广告被点击的回调
    }

    - (void)onAdClose {
        //广告被关闭的回调
    }

    - (void)onAdExposure {
        //广告被曝光的回调
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error {
        //广告获取错误的回调，获取未能获取到广告等错误
    }

    - (void)onAdSucceed {
        //广告加载成功的回调
    }
    @end
```

### 4、 NativeExpress 广告集成（相对特殊，需要自行处理关闭逻辑）

#### Swift
```Swift
    import EmAds
    class NativeExpressViewController: UIViewController {
        
        var nativeExpress: EmNativeExpress?
        
        fileprivate var dataArray: [Any] = [] // TableView数据源 = 开发商的数据源 + 广告， 可能多种类型
        
        fileprivate var adExpressViews: NSMutableArray = NSMutableArray.init() // 存放拉取成功的广告，用于手动展示
        
        fileprivate lazy var tblView: UITableView = {
            var tbl: UITableView = UITableView.init(frame: self.view.bounds, style: .plain)
            tbl.register(UITableViewCell.self, forCellReuseIdentifier: "nativeexpresscell")
            tbl.register(ExamTableViewCell.self, forCellReuseIdentifier: "ExamTableViewCell")
            
            tbl.delegate = self
            tbl.dataSource = self
            tbl.tableFooterView = UIView.init()
            return tbl
        }()
        
        
        override func viewDidLoad() {
            super.viewDidLoad()
            // Do any additional setup after loading the view.
            self.tblView.frame = CGRect.init(x: 0, y: 400, width: self.view.bounds.width, height: self.view.bounds.height - 400)
            self.view.addSubview(self.tblView)
        }
        
        //测试数据
        func rePrepareTestData() {
            let obj1 = ExamCellModel.init()
            obj1.title = "1、 双12开抢春运火车票！成都至广州可购夜间动车票"
            obj1.subtitle = "2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。"
            obj1.tag = "新闻"
            obj1.ctime = "12-11 12:17"
            obj1.cellh = 100
            obj1.showtype = 1
            let obj2 = ExamCellModel.init()
            obj2.title = "2、 双12开抢春运火车票！成都至广州可购夜间动车票"
            obj2.subtitle = "2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。"
            obj2.tag = "新闻"
            obj2.ctime = "12-11 12:17"
            obj2.cellh = 100
            obj2.showtype = 1
            let obj3 = ExamCellModel.init()
            obj3.title = "3、 双12开抢春运火车票！成都至广州可购夜间动车票"
            obj3.subtitle = "2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。"
            obj3.tag = "新闻"
            obj3.ctime = "12-11 12:17"
            obj3.cellh = 100
            obj3.showtype = 1
            self.dataArray = [obj1, obj2, obj3]
        }
        
        @IBAction func btnClickedAction(_ sender: UIButton) {
            self.dataArray = []
            self.adExpressViews = []
            self.tblView.reloadData()
            
            self.rePrepareTestData()
            
            self.nativeExpress = EmNativeExpress.init(viewController: self, 
                                                      delegate: self,
                                                      adSize: CGSizeMake(self.view.bounds.size.width, 0))
            self.nativeExpress!.loadAndShow() //加载并展示广告
            
        }
        
        @IBAction func btnClickedAction2(_ sender: UIButton) {
            self.dataArray = []
            self.adExpressViews = []
            self.tblView.reloadData()
            
            self.rePrepareTestData()
            
            self.nativeExpress = EmNativeExpress.init(viewController: self, 
                                                      delegate: self,
                                                      adSize: CGSizeMake(self.view.bounds.size.width, 0))
            self.nativeExpress!.loadOnly()  //加载但不展示广告
            
        }
        
        /// 手动展示广告
        @IBAction func btnClickedAction3(_ sender: UIButton) {
            if self.nativeExpress?.isLoadAndShow == true {
                SDemoDebugLog("请先调用self.nativeExpress.loadOnly()")
                return
            }
            
            if self.nativeExpress?.isLoaded != true {
                SDemoDebugLog("广告未加载成功或广告加载中")
                return
            }
            
            self.showNativeAds() //展示广告，信息流广告比较特殊，需要自行处理展示逻辑
        }
        
        
        @IBAction func btnnativeExpressClickedAction4(_ sender: UIButton) {
            self.nativeExpress?.destroy()   //销毁广告，信息流广告比较特殊，需要自行处理从界面删除逻辑

            self.dataArray.removeAll()
            self.adExpressViews.removeAllObjects()
            self.tblView.reloadData()
        }
        
        
        
        /// 信息流广告比较特殊, 渲染逻辑需要自行处理
        func showNativeAds() {
            //模拟将拉取的广告放在第二个位置
            for i in 0 ..< self.adExpressViews.count {
                if let v = self.adExpressViews[i] as? EmNativeExpressView {
                    v.render() //不能缺少
                    
                    var isInArray = false
                    for it in self.dataArray {
                        if let tIt = it as? EmNativeExpressView, tIt == v {
                            isInArray = true
                            break
                        }
                    }
                    if isInArray {//广告已经在列表中了
                        return
                    }
                    self.dataArray.insert(v, at: 1)
                }
            }
            
            if self.adExpressViews.count == 0 {
                self.rePrepareTestData()
            }
            self.tblView.reloadData()
        }
        
        deinit {
            SDemoDebugLog("NativeExpressViewController deinit")
        }
    }

    extension NativeExpressViewController: UITableViewDelegate, UITableViewDataSource {
        func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
            return self.dataArray.count
        }
        
        func numberOfSections(in tableView: UITableView) -> Int {
            return 1
        }
        
        func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
            let item = self.dataArray[indexPath.row]
            if item is ExamCellModel {
                return (item as! ExamCellModel).cellh!
            } else {
                if let ex = (item as? EmNativeExpressView)?.expressView {   //从返回的广告View直接获取高度进行布局
                    return ex.frame.size.height
                }
            }
            return 0
        }
        
        
        func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
            let item = self.dataArray[indexPath.row]
            if item is ExamCellModel {//展示集成商的自己的数据
                let cell = tableView.dequeueReusableCell(withIdentifier: "ExamTableViewCell", for: indexPath) as! ExamTableViewCell
                cell.selectionStyle = .none
                cell.setItem(item as! ExamCellModel)
                return cell
            } else {//展示广告数据源
                if let ex = (item as? EmNativeExpressView)?.expressView {
                    let eItemView = item as! EmNativeExpressView
                    let cell = tableView.dequeueReusableCell(withIdentifier: "nativeexpresscell", for: indexPath)
                    cell.selectionStyle = .none
                    
                    let subView = cell.contentView.viewWithTag(1000)
                      
                    let superview = subView?.superview
                    if superview != nil {
                        subView?.removeFromSuperview()
                    }
                      
                    let view = ex
                    view.tag = 1000
                    cell.contentView.addSubview(view)
                    cell.accessibilityIdentifier = "nativeTemp_ad"
                    eItemView.trackImpression() // 【必须注意的是 必须要调用，否则影响到计费， 必须确认展示在界面后，才能调用此方法】
                    return cell
                }
            }
            return UITableViewCell.init()
        }
        
        
    }

    extension NativeExpressViewController: EmNativeExpressDelegate {
        func onAdSucceed(adViews: [EmNativeExpressView]?, nativeExpressAd: EmNativeExpress) {
            //广告被加载成功的回调
            //需要手动处理界面自动展示的逻辑
            if nativeExpressAd.isLoadAndShow {
                self.adExpressViews = NSMutableArray(array: adViews ?? [])
                self.showNativeAds()
            } else {//如果是加载后并手动展示
                self.adExpressViews = NSMutableArray(array: adViews ?? [])
            }
            
        }
        
        func onAdClose(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
            //广告被关闭的回调
            //需要手动执行界面移除
            let tAdExpressViews = NSMutableArray.init(array: self.adExpressViews)
            for i in 0 ..< tAdExpressViews.count {
                if let tAd = tAdExpressViews[i] as? EmNativeExpressView, tAd.isEqual(adView) {//注意：此处不能用=或==判断
                    self.adExpressViews.removeObject(at: i)
                    tAd.destoryExpressView()
                    break
                }
            }
            self.showNativeAds()
        }
        
        func onAdExposure(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
            //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError, nativeExpressAd: EmNativeExpress) {
            //广告获取错误的回调，获取未能获取到广告等错误
        }
        
        func onAdClicked(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
            //广告被点击的回调
        }
        
        func onAdRenderSuccess(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
            //广告被渲染成功的回调， 不是所有渠道都会执行此回调
        }
        
        func onAdRenderFailed(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
            //广告被渲染失败的回调， 不是所有渠道都会执行此回调
        }
        
    }
```

#### Objective-C
        
```Objective-C
    #import <EmAds/EmAds.h>

    @interface NativeExpressViewController ()<EmNativeExpressDelegate, UITableViewDelegate, UITableViewDataSource>

    @property (nonatomic, strong) EmNativeExpress *nativeExpress;

    @property (nonatomic, strong) NSMutableArray* dataArray;
    @property (nonatomic, strong) NSMutableArray* adExpressViews;

    @property (nonatomic, strong) UITableView* tblView;

    @end

    @implementation NativeExpressViewController

    - (UITableView *)tblView {
        if (_tblView == nil) {
            _tblView = [[UITableView alloc] initWithFrame:self.view.bounds style:(UITableViewStylePlain)];
            [_tblView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"nativeexpresscell"];
            [_tblView registerClass:[ExamTableViewCell class] forCellReuseIdentifier:@"ExamTableViewCell"];
            _tblView.delegate = self;
            _tblView.dataSource = self;
        }
        return _tblView;
    }

    - (void)viewDidLoad {
        [super viewDidLoad];
        
        self.tblView.frame = CGRectMake(0, 400, self.view.bounds.size.width, self.view.bounds.size.height - 400);
        [self.view addSubview:self.tblView];
    }

    //测试数据
    - (void)rePrepareTestData {
        ExamCellModel* obj1 = [[ExamCellModel alloc] init];
        obj1.title = @"1、 双12开抢春运火车票！成都至广州可购夜间动车票";
        obj1.subtitle = @"2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。";
        obj1.tag = @"新闻";
        obj1.ctime = @"12-11 12:17";
        obj1.cellh = 100;
        obj1.showtype = 1;
        ExamCellModel* obj2 = [[ExamCellModel alloc] init];
        obj2.title = @"2、 双12开抢春运火车票！成都至广州可购夜间动车票";
        obj2.subtitle = @"2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。";
        obj2.tag = @"新闻";
        obj2.ctime = @"12-11 12:17";
        obj2.cellh = 100;
        obj2.showtype = 1;
        ExamCellModel* obj3 = [[ExamCellModel alloc] init];
        obj3.title = @"3、 双12开抢春运火车票！成都至广州可购夜间动车票";
        obj3.subtitle = @"2019年的日历越来越薄，以201x开头的年份也即将结束，一年一度的春运大幕即将拉开。";
        obj3.tag = @"新闻";
        obj3.ctime = @"12-11 12:17";
        obj3.cellh = 100;
        obj3.showtype = 1;
        self.dataArray = [[NSMutableArray alloc] initWithArray:@[obj1, obj2, obj3]];
    }

    - (IBAction)btnAction:(UIButton *)sender {
        self.dataArray = [[NSMutableArray alloc] init];
        self.adExpressViews =  [[NSMutableArray alloc] init];
        [self.tblView reloadData];
        
        [self rePrepareTestData];
        
        
        self.nativeExpress = [[EmNativeExpress alloc] initWithViewController:self delegate:self adSize:(CGSizeMake(self.view.bounds.size.width, 0))];
        [self.nativeExpress loadAndShow]; //加载并展示广告
    }


    - (IBAction)btnAction2:(UIButton *)sender {
        self.dataArray = [[NSMutableArray alloc] init];
        self.adExpressViews =  [[NSMutableArray alloc] init];
        [self.tblView reloadData];
        
        [self rePrepareTestData];

        self.nativeExpress = [[EmNativeExpress alloc] initWithViewController:self delegate:self adSize:(CGSizeMake(self.view.bounds.size.width, 0))];
        [self.nativeExpress loadOnly];  //加载但不展示广告
    }


    - (IBAction)btnAction3:(UIButton *)sender {
        if (self.nativeExpress != nil) {
            if(self.nativeExpress.isLoadAndShow) {
                NSLog(@"请先调用[self.nativeExpress loadOnly]");
                return;
            }
            
            if(!self.nativeExpress.isLoaded) {
                NSLog(@"广告未加载成功或广告加载中");
                return;
            }
            
            [self showNativeAd];//展示广告，信息流广告比较特殊，需要自行处理展示逻辑

        }
    }


    - (IBAction)btnAction4:(UIButton *)sender {
        if (self.nativeExpress != nil) {
            [self.nativeExpress destroy]; //销毁广告，信息流广告比较特殊，需要自行处理从界面删除逻辑
        }
        [self.dataArray removeAllObjects];
        [self.adExpressViews removeAllObjects];
        [self.tblView reloadData];
    }

    // 信息流广告比较特殊, 渲染逻辑需要自行处理
    - (void)showNativeAd {
        for (NSInteger i = 0; i < self.adExpressViews.count; i++) {
            EmNativeExpressView *av = self.adExpressViews[i];
            [av render];//不能缺少
            Boolean isInArray = NO;
            for (NSInteger j = 0; j < self.dataArray.count; j++) {
                id it = self.dataArray[j];
                if(it == av) {
                    break;
                }
            }
            if (isInArray) {
                return;
            }
            [self.dataArray insertObject:self.adExpressViews[i] atIndex:1];
        }
        
        if (self.adExpressViews.count == 0) {
            [self rePrepareTestData];
        }
        [self.tblView reloadData];

    }

    #pragma mark  UITableViewDelegate, UITableViewDataSource

    - (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
        return  1;
    }

    - (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
        return self.dataArray.count;
    }

    - (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
        if ([self.dataArray[indexPath.row] isKindOfClass:[ExamCellModel class]]) {
            return ((ExamCellModel *)self.dataArray[indexPath.row]).cellh;
        } else {
            CGFloat height = ([self.dataArray[indexPath.row] expressView]).frame.size.height; //从返回的广告View直接获取高度进行布局
            NSLog(@"=======> %f", height);
            return height;
        }
    }

    - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
        UITableViewCell *cell;
        if ([self.dataArray[indexPath.row] isKindOfClass:[ExamCellModel class]]) {
            cell = [tableView dequeueReusableCellWithIdentifier:@"ExamTableViewCell"];
            ((ExamTableViewCell *)cell).item = self.dataArray[indexPath.row];
            return cell;
        } else {
            cell = [tableView dequeueReusableCellWithIdentifier:@"nativeexpresscell" forIndexPath:indexPath];
            cell.selectionStyle = UITableViewCellSelectionStyleNone;

            UIView *subView = (UIView *)[cell.contentView viewWithTag:1000];
            if ([subView superview]) {
                [subView removeFromSuperview];
            }
            UIView *view = [self.dataArray[indexPath.row] expressView];

            view.tag = 1000;
            [cell.contentView addSubview:view];
            cell.accessibilityIdentifier = @"nativeTemp_ad";
            id item = self.dataArray[indexPath.row];
            EmNativeExpressView *eItemView = (EmNativeExpressView *)item;
            [eItemView trackImpression];    // 【必须注意的是 必须要调用，否则影响到计费， 必须确认展示在界面后，才能调用此方法】
            return cell;
        }
    }


    #pragma mark EmNativeExpressDelegate


    - (void)onAdSucceedWithAdViews:(NSArray<EmNativeExpressView *> * _Nullable)adViews nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd {
        //广告被加载成功的回调
        //需要手动处理界面自动展示的逻辑
        if (nativeExpressAd.isLoadAndShow) {
            self.adExpressViews = [[NSMutableArray alloc] initWithArray: adViews];
            [self showNativeAd];
        } else {
            self.adExpressViews = [[NSMutableArray alloc] initWithArray: adViews];
        }
    }

    - (void)onAdClickedWithAdView:(EmNativeExpressView * _Nullable)adView nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd { 
        //广告被点击的回调
    }

    - (void)onAdCloseWithAdView:(EmNativeExpressView * _Nullable)adView nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd {
        //广告被关闭的回调
        //需要手动执行界面移除
        
        NSMutableArray *tAdExpressViews = [[NSMutableArray alloc] initWithArray: self.adExpressViews];
        for(int i = 0; i < tAdExpressViews.count; i++) {
            EmNativeExpressView *tAd = (EmNativeExpressView *)tAdExpressViews[i];
            if([tAd isEqual:adView]) {//注意：此处不能用=或==判断
                [self.adExpressViews removeObjectAtIndex:i];
                [tAd destoryExpressView];
                break;
            }
        }
        [self showNativeAd];
    }

    - (void)onAdExposureWithAdView:(EmNativeExpressView * _Nullable)adView nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd { 
        //广告被曝光的回调
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd {
        //广告获取错误的回调，获取未能获取到广告等错误 
    }

    - (void)onAdRenderFailedWithAdView:(EmNativeExpressView * _Nullable)adView nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd { 
        //广告被渲染失败的回调， 不是所有渠道都会执行此回调
    }

    - (void)onAdRenderSuccessWithAdView:(EmNativeExpressView * _Nullable)adView nativeExpressAd:(EmNativeExpress * _Nonnull)nativeExpressAd { 
        //广告被渲染成功的回调， 不是所有渠道都会执行此回调
        
    }


    @end
```

### 5、RewardVideo 广告集成
    
#### Swift
```Swift
    import EmAds
    class RewardVideoViewController: UIViewController {
        var rewardVideo: EmRewardVideo?
        override func viewDidLoad() {
            super.viewDidLoad()
        }

        @IBAction func btnClickedAction(_ sender: UIButton) {
            self.rewardVideo = EmRewardVideo.init(viewController: self, delegate: self)
            self.rewardVideo!.loadAndShow()  //加载并展示广告
        }
        
        @IBAction func btnClickedAction2(_ sender: UIButton) {
            self.rewardVideo = EmRewardVideo.init(viewController: self, delegate: self)
            self.rewardVideo!.loadOnly()     //加载但不展示广告
        }
        
        @IBAction func btnClickedAction3(_ sender: UIButton) {
            self.rewardVideo?.show()        //展示已加载的广告，与loadOnly()配套使用
        }
        
        @IBAction func btnClickedAction4(_ sender: UIButton) {
            self.rewardVideo?.destroy()     //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
        
    }


    extension RewardVideoViewController: EmRewardVideoDelegate {
        
        func onAdSucceed() {
            //广告被加载成功的回调
        }
        
        func onAdClose() {
            //广告被关闭的回调
        }
        
        func onAdExposure() {
            //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError) {
            //广告获取错误的回调，获取未能获取到广告等错误 
        }
        
        func onAdClicked() {
            //广告被点击的回调
        }
        
        func onVideoCached() {
            //广告被缓存的回调，少部分渠道会执行，可以不用过于关注
        }
        
        func onVideoComplete() {
            //广告播放结束的回调
        }
        
        func onVideoSkip() {
            //广告被跳过操作的回调， 有些渠道不会执行，会走onAdClose回调
        }
        
        func onAdReward() {
            //广告到了激励时间的回调
            //TODO： 您可以在此给用户分配激励权益   
        }
        
        func onRewardServerInf(inf: EARewardServerCallBackInf) {
            //备用回调，暂时没有用到
        }
        
    }
```
        
#### Objective-C
    
```Objective-C
    #import <EmAds/EmAds.h>

    @interface RewardVideoViewController ()<EmRewardVideoDelegate>

    @property (nonatomic, strong) EmRewardVideo *rewardVideo;

    @end

    @implementation RewardVideoViewController

    - (void)viewDidLoad {
        [super viewDidLoad];
        // Do any additional setup after loading the view.
    }

    - (IBAction)rewardVideoBtnAction:(UIButton *)sender {
        self.rewardVideo = [[EmRewardVideo alloc] initWithViewController:self delegate:self];
        [self.rewardVideo loadAndShow]; //加载并展示广告
    }


    - (IBAction)rewardVideoBtnAction2:(UIButton *)sender {
        self.rewardVideo = [[EmRewardVideo alloc] initWithViewController:self delegate:self];

        [self.rewardVideo loadOnly];//加载但不展示广告
    }


    - (IBAction)rewardVideoBtnAction3:(UIButton *)sender {
        if(self.rewardVideo != nil) {
            [self.rewardVideo show]; //展示已加载的广告，与loadOnly配套使用
        }
    }



    - (IBAction)rewardVideoBtnAction4:(UIButton *)sender {
        if(self.rewardVideo != nil) {
            [self.rewardVideo destroy]; //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
    }


    #pragma mark EmRewardVideoDelegate


    - (void)onAdClicked {
        //广告被点击的回调
    }

    - (void)onAdClose {
        //广告被关闭的回调
    }

    - (void)onAdExposure {
        //广告被曝光的回调
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error {
        //广告获取错误的回调，获取未能获取到广告等错误 
    }

    - (void)onAdSucceed {
        //广告被加载成功的回调
    }


    - (void)onAdReward {
        //广告到了激励时间的回调
        //TODO： 您可以在此给用户分配激励权益   
    }

    - (void)onRewardServerInfWithInf:(EARewardServerCallBackInf * _Nonnull)inf {
        //备用回调，暂时没有用到
    }

    - (void)onVideoCached {
        //广告被缓存的回调，少部分渠道会执行，可以不用过于关注
    }

    - (void)onVideoComplete {
        //广告播放结束的回调
    }

    - (void)onVideoSkip {
        //广告被跳过操作的回调， 有些渠道不会执行，会走onAdClose回调
    }


    @end
```

### 6、 FullScreenVideo 广告集成
 
#### Swift
```Swift
    import EmAds
    class FullScreenVideoViewController: UIViewController {
        var fullScreenVideo: EmFullScreenVideo?
        override func viewDidLoad() {
            super.viewDidLoad()
        }

        @IBAction func btnClickedAction(_ sender: UIButton) {
            self.fullScreenVideo = EmFullScreenVideo.init(viewController: self, delegate: self)
            self.fullScreenVideo!.loadAndShow() //加载并展示广告
        }
        
        @IBAction func btnClickedAction2(_ sender: UIButton) {
            self.fullScreenVideo = EmFullScreenVideo.init(viewController: self, delegate: self)
            self.fullScreenVideo!.loadOnly() //加载但不展示广告
        }
        
        @IBAction func btnClickedAction3(_ sender: UIButton) {
            self.fullScreenVideo?.show() //展示已加载的广告，与loadOnly()配套使用
        }
        
        @IBAction func btnClickedAction4(_ sender: UIButton) {
            self.fullScreenVideo?.destroy() //销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
    }


    extension FullScreenVideoViewController: EmFullScreenVideoDelegate {
        
        func onAdSucceed() {
            //广告被加载成功的回调
        }
        
        func onAdClose() {
            //广告被关闭的回调
        }
        
        func onAdExposure() {
            //广告被曝光的回调
        }
        
        func onAdFailed(error: EmAdError) {
            //广告获取错误的回调，获取未能获取到广告等错误 
        }
        
        func onAdClicked() {
            //广告被点击的回调
        }
        
        func onVideoCached() {
            //广告被缓存的回调，少部分渠道会执行，可以不用过于关注
        }
        
        func onVideoComplete() {
            //广告播放结束的回调
        }
        
        func onVideoSkip() {
            //广告被跳过操作的回调， 有些渠道不会执行，会走onAdClose回调
        }
        
    }
```  
#### Objective-C 
   
```Objective-C 
    #import <EmAds/EmAds.h>

    @interface FullScreenVideoViewController ()<EmFullScreenVideoDelegate>

    @property (nonatomic, strong) EmFullScreenVideo *fullScreenVideo;

    @end

    @implementation FullScreenVideoViewController

    - (void)viewDidLoad {
        [super viewDidLoad];
        // Do any additional setup after loading the view.
    }

    - (IBAction)fullScreenVideoBtnAction:(UIButton *)sender {
        self.fullScreenVideo = [[EmFullScreenVideo alloc] initWithViewController:self delegate:self];
        [self.fullScreenVideo loadAndShow]; //加载并展示广告
    }


    - (IBAction)fullScreenVideoBtnAction2:(UIButton *)sender {
        self.fullScreenVideo = [[EmFullScreenVideo alloc] initWithViewController:self delegate:self];
        [self.fullScreenVideo loadOnly];//加载但不展示广告
    }


    - (IBAction)fullScreenVideoBtnAction3:(UIButton *)sender {
        if(self.fullScreenVideo != nil) {
            [self.fullScreenVideo show]; //展示已加载的广告，与loadOnly配套使用
        }
    }



    - (IBAction)fullScreenVideoBtnAction4:(UIButton *)sender {
        if(self.fullScreenVideo != nil) {
            [self.fullScreenVideo destroy];//销毁广告，可以多次调用，也可以不手动调用，如果广告对象的携带者self被销毁， 广告也会自动销毁
        }
    }


    #pragma mark EmFullScreenVideoDelegate


    - (void)onAdClicked {
        //广告被点击的回调
    }

    - (void)onAdClose {
        //广告被关闭的回调
    }

    - (void)onAdExposure {
        //广告被曝光的回调
    }

    - (void)onAdFailedWithError:(EmAdError * _Nonnull)error {
        //广告获取错误的回调，获取未能获取到广告等错误 
    }

    - (void)onAdSucceed {
        //广告被加载成功的回调
    }


    - (void)onVideoCached {
        //广告被缓存的回调，少部分渠道会执行，可以不用过于关注
    }

    - (void)onVideoComplete {
        //广告播放结束的回调
    }

    - (void)onVideoSkip {
        //广告被跳过操作的回调， 有些渠道不会执行，会走onAdClose回调
    }


    @end
```

## 四、SDK错误码

    0       成功
    9901    ⼴告返回的数据为空，⼀般为渠道⼴告⽆填充
    9905    当前策略中⽆有效的SDK渠道，或渠道信息为空
    9906    策略调度时发⽣异常，不支持的渠道
    9907    未获取到策略，appid 请求配置错误
    -2009   数据解析错误
    20999   网络断开
    20997   appid 重试请求配置多次错误
    20996   SDK初始化失败
    20989   SDK未启用
    20995   加载开屏广告失败
    20994   加载插屏广告失败
    20993   加载Banner广告失败
    20992   加载原生模板，信息流广告失败
    20991   加载激励视频广告失败
    20990   加载全屏视频广告失败
    20988   UnSupport iOS Version

