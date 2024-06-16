//
//  RewardVideoViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/27.
//

import Foundation
import UIKit
import EmAds


class RewardVideoViewController: UIViewController {
    var rewardVideo: EmRewardVideo?
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnClickedAction(_ sender: UIButton) {
        SDemoDebugLog("self.rewardVideo.loadAndShow()")
        self.rewardVideo = EmRewardVideo.init(viewController: self, delegate: self)
        self.rewardVideo!.loadAndShow()
    }
    
    @IBAction func btnClickedAction2(_ sender: UIButton) {
        SDemoDebugLog("self.rewardVideo.loadOnly()")
        self.rewardVideo = EmRewardVideo.init(viewController: self, delegate: self)
        self.rewardVideo!.loadOnly()
    }
    
    @IBAction func btnClickedAction3(_ sender: UIButton) {
        SDemoDebugLog("self.rewardVideo.show()")
        self.rewardVideo?.show()
    }
    
    @IBAction func btnClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.rewardVideo.destroy()")
        self.rewardVideo?.destroy()
    }
    
    
    deinit {
        SDemoDebugLog("RewardVideoViewController deinit")
    }
}


extension RewardVideoViewController: EmRewardVideoDelegate {
    
    
    func onAdSucceed() {
        SDemoDebugLog("EmRewardVideoDelegate onAdSucceed")
    }
    
    func onAdClose() {
        SDemoDebugLog("EmRewardVideoDelegate onAdClose")
        
    }
    
    func onAdExposure() {
        
        SDemoDebugLog("EmRewardVideoDelegate onAdExposure")
    }
    
    func onAdFailed(error: EmAdError) {
        SDemoDebugLog("EmRewardVideoDelegate onAdFailed \(error)")
    }
    
    func onAdClicked() {
        SDemoDebugLog("EmRewardVideoDelegate onAdClicked")
        
    }
    
    func onVideoCached() {
        
        SDemoDebugLog("EmRewardVideoDelegate onVideoCached")
    }
    
    func onVideoComplete() {
        SDemoDebugLog("EmRewardVideoDelegate onVideoComplete")
        
    }
    
    func onVideoSkip() {
        SDemoDebugLog("EmRewardVideoDelegate onVideoSkip")
        
    }
    
    func onAdReward() {
        //MARK: TODO 此处可以调用执行发放奖励的逻辑
        SDemoDebugLog("EmRewardVideoDelegate onAdReward")
        
    }
    
    func onRewardServerInf(inf: EARewardServerCallBackInf) {
        
        SDemoDebugLog("EmRewardVideoDelegate onRewardServerInf")
    }
    
}

