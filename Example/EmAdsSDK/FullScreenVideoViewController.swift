//
//  FullScreenVideoViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/27.
//

import Foundation
import UIKit
import EmAds

class FullScreenVideoViewController: UIViewController {
    var fullScreenVideo: EmFullScreenVideo?
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnClickedAction(_ sender: UIButton) {
        SDemoDebugLog("self.fullScreenVideo.loadAndShow()")
        self.fullScreenVideo = EmFullScreenVideo.init(viewController: self, delegate: self)
        self.fullScreenVideo!.loadAndShow()
    }
    
    @IBAction func btnClickedAction2(_ sender: UIButton) {
        SDemoDebugLog("self.fullScreenVideo.loadOnly()")
        self.fullScreenVideo = EmFullScreenVideo.init(viewController: self, delegate: self)
        self.fullScreenVideo!.loadOnly()
    }
    
    @IBAction func btnClickedAction3(_ sender: UIButton) {
        SDemoDebugLog("self.fullScreenVideo.show()")
        self.fullScreenVideo?.show()
    }
    
    @IBAction func btnClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.fullScreenVideo.destroy()")
        self.fullScreenVideo?.destroy()
    }
    
    
    deinit {
        SDemoDebugLog("FullScreenVideoViewController deinit")
    }
}


extension FullScreenVideoViewController: EmFullScreenVideoDelegate {
    
    
    func onAdSucceed() {
        SDemoDebugLog("EmFullScreenVideoDelegate onAdSucceed")
    }
    
    func onAdClose() {
        SDemoDebugLog("EmFullScreenVideoDelegate onAdClose")
        
    }
    
    func onAdExposure() {
        SDemoDebugLog("EmFullScreenVideoDelegate onAdExposure")
        
    }
    
    func onAdFailed(error: EmAdError) {
        SDemoDebugLog("EmFullScreenVideoDelegate onAdFailed \(error)")
    }
    
    func onAdClicked() {
        SDemoDebugLog("EmFullScreenVideoDelegate onAdClicked")
        
    }
    
    func onVideoCached() {
        SDemoDebugLog("EmFullScreenVideoDelegate onVideoCached")
        
    }
    
    func onVideoComplete() {
        SDemoDebugLog("EmFullScreenVideoDelegate onVideoComplete")
        
    }
    
    func onVideoSkip() {
        
        SDemoDebugLog("EmFullScreenVideoDelegate onVideoSkip")
    }
    
}

