//
//  AppDelegate.swift
//  EmAdsSDK
//
//  Created by 876224031@qq.com on 06/08/2024.
//  Copyright (c) 2024 876224031@qq.com. All rights reserved.
//

import UIKit
import EmAds

let kAppId = "26" // 混合

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow? // 若去掉， GDTModSDK会有几率crash


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        window = UIWindow(frame: UIScreen.main.bounds)
        window!.rootViewController = UIStoryboard(name: "Main", bundle: nil).instantiateInitialViewController()!
        window!.makeKeyAndVisible()
        
        let obj = UserDefaults.standard.string(forKey: "EmSDK_LOGENABLED") ?? "on"
        let logEnabled = (obj == "on")
        
        let appid = UserDefaults.standard.string(forKey: "EmSDK_APPID") ?? kAppId
        EmAdsSDK.initSDK(launchOptions: launchOptions, isDebug: logEnabled, emlAppId: appid, idfaEnabled: true) { err in
            if err.code == .succeed {
                
            }
        }
        
        

        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}




internal let DEMO_TAG = "DemoDebug"
internal func SDemoDebugLog<T: StringProtocol>(_ message: T, fileName: String = #file, methodName: String = #function, lineNumber: Int = #line) {
    
#if DEBUG
    //获取当前时间
    let now = Date()
    // 创建一个日期格式器
    let dformatter = DateFormatter()
    dformatter.dateFormat = "yyyy/MM/dd HH:mm:ss.SSS"
    // 要把路径最后的字符串截取出来
    let lastName = ((fileName as NSString).pathComponents.last!)
    let fullMessage = "\(DEMO_TAG) [\(dformatter.string(from: now))] [\(lastName)][line \(lineNumber)]# \(message)"
    print(fullMessage)
    NotificationCenter.default.post(name: kNotificationNameLogTextAppend, object: fullMessage)
#endif
}

internal let kNotificationNameLogTextAppend = Notification.Name.init("NotificationNameLogTextAppend")
