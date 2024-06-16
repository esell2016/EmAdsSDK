//
//  InterstitialViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/23.
//

import Foundation
import UIKit
import EmAds

class InterstitialViewController: UIViewController {
    var interstitial: EmInterstitial?
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnInterstitialClickedAction(_ sender: UIButton) {
        SDemoDebugLog("self.interstitial.loadAndShow()")
        self.interstitial = EmInterstitial.init(viewController: self, delegate: self)
        self.interstitial!.loadAndShow()
    }
    
    @IBAction func btnInterstitialClickedAction2(_ sender: UIButton) {
        SDemoDebugLog("self.interstitial.loadOnly()")
        self.interstitial = EmInterstitial.init(viewController: self, delegate: self)
        self.interstitial!.loadOnly()
    }
    
    @IBAction func btnInterstitialClickedAction3(_ sender: UIButton) {
        SDemoDebugLog("self.interstitial.show()")
        self.interstitial?.show()
    }
    
    
    @IBAction func btnInterstitialClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.interstitial.destroy()")
        self.interstitial?.destroy()
    }
    
    
    deinit {
        SDemoDebugLog("InterstitialViewController deinit")
    }
}

extension InterstitialViewController: EmInterstitialDelegate {
    
    func onAdSucceed() {
        SDemoDebugLog("EmInterstitialDelegate onAdSucceed")
    }
    
    func onAdClose() {
        SDemoDebugLog("EmInterstitialDelegate onAdClose")
    }
    
    func onAdExposure() {
        SDemoDebugLog("EmInterstitialDelegate onAdExposure")
    }
    
    func onAdFailed(error: EmAdError) {
        SDemoDebugLog("EmInterstitialDelegate onAdFailed \(error)")
    }
    
    func onAdClicked() {
        SDemoDebugLog("EmInterstitialDelegate onAdClicked")
    }
    
    
}
