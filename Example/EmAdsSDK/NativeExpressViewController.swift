//
//  NativeExpressViewController.swift
//  emadsdemo
//
//  Created by Alan on 2024/4/25.
//

import Foundation
import UIKit
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
        SDemoDebugLog("self.nativeExpress.loadAndShow()")
        self.nativeExpress = EmNativeExpress.init(viewController: self, 
                                                  delegate: self,
                                                  adSize: CGSizeMake(self.view.bounds.size.width, 0))
        self.nativeExpress!.loadAndShow()
    }
    
    @IBAction func btnClickedAction2(_ sender: UIButton) {
        self.dataArray = []
        self.adExpressViews = []
        self.tblView.reloadData()
        
        self.rePrepareTestData()
        SDemoDebugLog("self.nativeExpress.loadOnly()")
        self.nativeExpress = EmNativeExpress.init(viewController: self, 
                                                  delegate: self,
                                                  adSize: CGSizeMake(self.view.bounds.size.width, 0))
        self.nativeExpress!.loadOnly()
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
        
        SDemoDebugLog("self.showNativeAds()")
        self.showNativeAds()
    }
    
    
    @IBAction func btnnativeExpressClickedAction4(_ sender: UIButton) {
        SDemoDebugLog("self.nativeExpress.destroy() 1")
        self.nativeExpress?.destroy()
        SDemoDebugLog("self.nativeExpress.destroy() 2")
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
            if let ex = (item as? EmNativeExpressView)?.expressView {
                print("height \(ex.frame.size.height)")
                return ex.frame.size.height
            }
        }
        return 0
    }
    
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let item = self.dataArray[indexPath.row]
        if item is ExamCellModel {
            let cell = tableView.dequeueReusableCell(withIdentifier: "ExamTableViewCell", for: indexPath) as! ExamTableViewCell
            cell.selectionStyle = .none
            cell.setItem(item as! ExamCellModel)
            return cell
        } else {
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
                eItemView.trackImpression()
                return cell
            }
        }
        return UITableViewCell.init()
    }
    
    
}

extension NativeExpressViewController: EmNativeExpressDelegate {
    func onAdSucceed(adViews: [EmNativeExpressView]?, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdSucceed")
        //如果是加载后并自动展示
        if nativeExpressAd.isLoadAndShow {
            self.adExpressViews = NSMutableArray(array: adViews ?? [])
            self.showNativeAds()
        } else {//如果是加载后并手动展示
            self.adExpressViews = NSMutableArray(array: adViews ?? [])
        }
        
    }
    
    func onAdClose(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdClose")
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
        SDemoDebugLog("EmNativeExpressDelegate onAdExposure")
    }
    
    func onAdFailed(error: EmAdError, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdFailed \(error)")
    }
    
    func onAdClicked(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdClicked")
    }
    
    func onAdRenderSuccess(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdRenderSuccess")
    }
    
    func onAdRenderFailed(adView: EmNativeExpressView?, nativeExpressAd: EmNativeExpress) {
        SDemoDebugLog("EmNativeExpressDelegate onAdRenderFailed")
    }
    
}



// MARK: 下方均为demo测试使用， 不必过于关注

fileprivate class ExamCellModel: NSObject {
    var title: String?
    var subtitle: String?
    var tag: String?
    var ctime: String?
    var cellh: CGFloat?
    var showtype: Int?
}

fileprivate let GlobleHeight = UIScreen.main.bounds.size.height
fileprivate let GlobleWidth = UIScreen.main.bounds.size.width
fileprivate let imgBgColor = UIColor.init(red: 0.81, green: 0.81, blue: 0.82, alpha: 1.00)
fileprivate let edge = 15.0

fileprivate class ExamTableViewCell: UITableViewCell {
    var separatorLine: UIView?
    var titleLabel: UILabel?
    var inconLable: UILabel?
    var sourceLable: UILabel?
    var closeIncon: UIImageView?
    var img: UIImageView?
    var bigImg: UIImageView?
    var img1: UIImageView?
    var img2: UIImageView?
    var img3: UIImageView?
    
    var item: ExamCellModel!
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        self.buildupView()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func buildupView() {
        // 分割线
        let separatorLine = UIView(frame: CGRect(x: edge, y: 0.0, width: GlobleWidth - edge * 2, height: 0.5))
        separatorLine.backgroundColor = UIColor(red: 0.91, green: 0.91, blue: 0.94, alpha: 1.0)
        self.separatorLine = separatorLine
        self.contentView.addSubview(separatorLine)
          
        // 标题标签
        let titleLabel = UILabel()
        titleLabel.numberOfLines = 2
        titleLabel.font = UIFont.systemFont(ofSize: 18)
        titleLabel.textColor = .black
        self.titleLabel = titleLabel
        self.contentView.addSubview(titleLabel)
          
        // 来源标签
        let sourceLabel = UILabel()
        sourceLabel.font = UIFont.systemFont(ofSize: 12)
        sourceLabel.textColor = .black
        self.sourceLable = sourceLabel
        self.contentView.addSubview(sourceLabel)
          
        // 图标标签（注意：这里使用了 UILabel 来显示图标，通常我们会使用 UIImageView）
        let inconLabel = UILabel()
        inconLabel.font = UIFont.systemFont(ofSize: 10)
        inconLabel.textColor = .red
        inconLabel.textAlignment = .center
        inconLabel.clipsToBounds = true
        inconLabel.layer.cornerRadius = 3
        inconLabel.layer.borderWidth = 0.5
        inconLabel.layer.borderColor = UIColor.red.cgColor
        self.inconLable = inconLabel
        self.contentView.addSubview(inconLabel)
          
        // 关闭图标
        let closeIcon = UIImageView(image: UIImage(named: "feedClose"))
        self.closeIncon = closeIcon
        self.contentView.addSubview(closeIcon)
    }
    
    func setItem(_ item: ExamCellModel) {
        self.item = item
        // 假设 item 已经在 Swift 文件中定义，并且与 Objective-C 中的 item 具有相同的属性和结构
          
        self.titleLabel!.attributedText = CellBuilder.titleAttributeText(item.title)
        self.sourceLable!.attributedText = CellBuilder.subtitleAttributeText(item.ctime)
        self.inconLable!.text = item.tag
          
        // 设置 _inconLabel 的 frame
        self.inconLable!.frame = CGRect(x: edge, y: item.cellh! - 12.0 - edge, width: 27.0, height: 14.0)
          
        if let tag = item.tag, !tag.isEmpty {
            self.inconLable!.isHidden = false
            self.sourceLable!.frame = CGRect(x: self.inconLable!.frame.origin.x + self.inconLable!.frame.size.width + edge, y: self.inconLable!.frame.origin.y + 1.0, width: 200.0, height: 12.0)
        } else {
            self.inconLable!.isHidden = true
            self.sourceLable!.frame = CGRect(x: edge, y: self.inconLable!.frame.origin.y, width: 200.0, height: 12.0)
        }
          
        // 设置 _closeIcon 的 frame
        self.closeIncon!.frame = CGRect(x: GlobleWidth - 10.0 - edge, y: item.cellh! - 10.0 - edge, width: 10.0, height: 10.0)
          
        // 从父视图中移除图片视图
        self.img?.removeFromSuperview()
        self.bigImg?.removeFromSuperview()
        self.img1?.removeFromSuperview()
        self.img2?.removeFromSuperview()
        self.img3?.removeFromSuperview()
        
        // 假设 item、titleLabel、bigImg、img、contentView 和 GlobleWidth 已经在 Swift 文件中定义
          
        if item.showtype == 1 {
            titleLabel!.frame = CGRect(x: edge, y: edge, width: GlobleWidth - edge * 2.0, height: 50.0)
        } else if item.showtype == 2 {
            titleLabel!.frame = CGRect(x: edge, y: edge, width: GlobleWidth - edge * 2, height: 50)
              
            let bigImgFrame = CGRect(x: edge, y: titleLabel!.frame.maxY + edge, width: GlobleWidth - edge * 2, height: (GlobleWidth - edge * 2) * 0.6)
            bigImg = UIImageView(frame: bigImgFrame)
            bigImg!.backgroundColor = UIColor(red: 0.74, green: 0.75, blue: 0.76, alpha: 1.0)
            contentView.addSubview(bigImg!)
        } else if item.showtype == 3 {
            let imgFrame = CGRect(x: GlobleWidth - edge - 120, y: edge, width: 120, height: 80)
            img = UIImageView(frame: imgFrame)
            img!.backgroundColor = UIColor(red: 0.74, green: 0.75, blue: 0.76, alpha: 1.0)
            contentView.addSubview(img!)
              
            titleLabel!.frame = CGRect(x: edge, y: edge, width: GlobleWidth - 120 - edge * 3, height: 50)
        } else if item.showtype == 4 {
            titleLabel!.frame = CGRect(x: edge, y: edge, width: GlobleWidth - edge * 2, height: 50.0)
              
            let img1Frame = CGRect(x: edge, y: titleLabel!.frame.maxY + edge, width: (GlobleWidth - edge * 2.0 - 10.0) / 3.0, height: 80.0)
            img1 = UIImageView(frame: img1Frame)
            img1!.backgroundColor = UIColor(red: 0.74, green: 0.75, blue: 0.76, alpha: 1.0)
            contentView.addSubview(img1!)
              
            let img2OriginX = img1Frame.maxX + 5
            let img2Frame = CGRect(x: img2OriginX, y: self.titleLabel!.frame.maxY + edge, width: (GlobleWidth - edge * 2 - 10.0) / 3, height: 80)
            img2 = UIImageView(frame: img2Frame)
            img2!.backgroundColor = UIColor(red: 0.74, green: 0.75, blue: 0.76, alpha: 1.0)
            contentView.addSubview(img2!)
              
            let img3OriginX = img2Frame.maxX + 5
            let img3Frame = CGRect(x: img3OriginX, y: titleLabel!.frame.maxY + edge, width: (GlobleWidth - edge * 2.0 - 10.0) / 3.0, height: 80.0)
            img3 = UIImageView(frame: img3Frame)
            img3!.backgroundColor = UIColor(red: 0.74, green: 0.75, blue: 0.76, alpha: 1.0)
            contentView.addSubview(img3!)
        }
    }
}


class CellBuilder {
    public class func titleAttributeText(_ text: String?) -> NSAttributedString? {
        guard let text = text else {
            return nil
        }
          
        var attributes: [NSAttributedString.Key: Any] = [:]
          
        let titleStrStyle = NSMutableParagraphStyle()
        titleStrStyle.lineSpacing = 5
        titleStrStyle.alignment = .justified
          
        attributes[.font] = UIFont.systemFont(ofSize: 17)
        attributes[.paragraphStyle] = titleStrStyle
          
        return NSAttributedString(string: text, attributes: attributes)
    }
    
    public class func subtitleAttributeText(_ text: String?) -> NSAttributedString? {
        guard let text = text else {
            return nil
        }
          
        let attributes: [NSAttributedString.Key: Any] = [
            .font: UIFont.systemFont(ofSize: 12),
            .foregroundColor: UIColor.lightGray
        ]
          
        return NSAttributedString(string: text, attributes: attributes)
    }
}

