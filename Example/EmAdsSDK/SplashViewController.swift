//
//  SplashViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/11.
//

import UIKit
import Foundation
import EmAds

class SplashViewController: UIViewController {
    var splash: EmSplash?
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnClickedAction(_ sender: UIButton) {
        SDemoDebugLog("self.splash.loadAndShow()")
        self.splash = EmSplash.init(viewController: self, delegate: self)
        self.splash!.loadAndShow()
    }
    
    @IBAction func btnClickedAction2(_ sender: UIButton) {
        SDemoDebugLog("self.splash.loadOnly()")
        self.splash = EmSplash.init(viewController: self, delegate: self)
        self.splash!.loadOnly()
    }
    
    @IBAction func btnClickedAction3(_ sender: UIButton) {
        SDemoDebugLog("self.splash.show()")
        self.splash?.show()
    }
    
    @IBAction func btnClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.splash.destroy()")
        self.splash?.destroy()
    }
    
    
    deinit {
        SDemoDebugLog("SplashViewController deinit")
    }
}


extension SplashViewController: EmSplashDelegate {
    func onSplashComplete() {
        SDemoDebugLog("EmSplashDelegate onSplashComplete")
    }
    
    
    func onSplashSkip() {
        SDemoDebugLog("EmSplashDelegate onSplashSkip")
    }
    
    func onAdSucceed() {
        SDemoDebugLog("EmSplashDelegate onAdSucceed")
    }
    
    func onAdClose() {
        SDemoDebugLog("EmSplashDelegate onAdClose")
    }
    
    func onAdExposure() {
        SDemoDebugLog("EmSplashDelegate onAdExposure")
    }
    
    func onAdFailed(error: EmAdError) {
        SDemoDebugLog("EmSplashDelegate onAdFailed \(error)")
    }
    
    func onAdClicked() {
        SDemoDebugLog("EmSplashDelegate onAdClicked")
    }
    
    
}
