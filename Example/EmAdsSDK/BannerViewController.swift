//
//  BannerViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/24.
//

import Foundation
import UIKit
import EmAds

class BannerViewController: UIViewController {

    @IBOutlet weak var adContannerView: UIView!
    var banner: EmBanner?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func btnBannerClickedAction(_ sender: UIButton) {
        SDemoDebugLog("self.banner.loadAndShow()")
        self.banner = EmBanner.init(viewController: self, adContainer: self.adContannerView, delegate: self)
        self.banner!.loadAndShow()
    }
    
    @IBAction func btnBannerClickedAction2(_ sender: UIButton) {
        SDemoDebugLog("self.banner.loadOnly()")
        self.banner = EmBanner.init(viewController: self, adContainer: self.adContannerView, delegate: self)
        self.banner!.loadOnly()
    }
    
    @IBAction func btnBannerClickedAction3(_ sender: UIButton) {
        SDemoDebugLog("self.banner.show()")
        self.banner?.show()
    }
    
    
    @IBAction func btnBannerClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.banner.destroy()")
        self.banner?.destroy()
    }
    
    
    deinit {
        SDemoDebugLog("BannerViewController deinit")
    }
}

extension BannerViewController: EmBannerDelegate {
    
    func onAdSucceed() {
        SDemoDebugLog("EmBannerDelegate onAdSucceed")
    }
    
    func onAdClose() {
        SDemoDebugLog("EmBannerDelegate onAdClose")
    }
    
    func onAdExposure() {
        SDemoDebugLog("EmBannerDelegate onAdExposure")
    }
    
    func onAdFailed(error: EmAdError) {
        SDemoDebugLog("EmBannerDelegate onAdFailed \(error)")
    }
    
    func onAdClicked() {
        SDemoDebugLog("EmBannerDelegate onAdClicked")
    }
    
    
}
