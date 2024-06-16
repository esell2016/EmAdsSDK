//
//  IndexViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/5/2.
//

import Foundation
import UIKit
import EmAds

class IndexViewController: UIViewController {
    @IBOutlet weak var appidText: UITextField!
    @IBOutlet weak var logEnabledSwitch: UISwitch!
    override func viewDidLoad() {
        super.viewDidLoad()
        let obj = UserDefaults.standard.string(forKey: "EmSDK_LOGENABLED") ?? "on"
        let logEnabled = (obj == "on")
        self.logEnabledSwitch.isOn = logEnabled
        
        let appid = UserDefaults.standard.string(forKey: "EmSDK_APPID") ?? kAppId
        self.appidText.text = appid
    }
    
    @IBAction func hideKeyboard(_ sender: UIButton) {
        self.view.endEditing(true)
    }
    @IBAction func valueChanged(_ sender: UISwitch) {
        if sender.isOn {
            EmAdsSDK.setLogWindow(isShow: true)
        } else {
            
            EmAdsSDK.setLogWindow(isShow: false)
        }
        
//        URLSessionTaskMetrics
    }
    
    
    
    
    @IBAction func logEnabled(_ sender: UISwitch) {
//        let logEnabled = sender.isOn
    }
    
    @IBAction func exit(_ sender: UIButton) {
        UserDefaults.standard.setValue(self.logEnabledSwitch.isOn ? "on" : "off", forKey: "EmSDK_LOGENABLED")
        UserDefaults.standard.setValue(self.appidText.text, forKey: "EmSDK_APPID")
        fatalError("exit 0")
    }
}
