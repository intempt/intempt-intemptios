//
//  customeventViewController.swift
//  DemoTracking
//
//  Created by Tanay Bhattacharjee on 10/04/20.
//  Copyright © 2020 Tanay Bhattacharjee. All rights reserved.
//

import UIKit
import intempt
class customeventViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    @IBAction func back( sender: AnyObject? ) {
        self.navigationController?.popViewController(animated: true)
    }
    @IBAction func payment( sender: AnyObject? ) {
        let dic = NSMutableDictionary()
        let dic2 = NSMutableDictionary()
        var ary = NSMutableArray()
        let arrData = NSMutableArray()
        let dic1 = NSMutableDictionary()
        dic1.setValue("Slim Jean", forKey: "itemName");
        dic1.setValue("180", forKey: "price");
        dic1.setValue("2", forKey: "qty");
        dic2.setValue("Trousers", forKey: "itemName");
        dic2.setValue("80", forKey: "price");
        dic2.setValue("2", forKey: "qty");
        dic.setValue("260", forKey: "totalPrice");
        dic.setValue("4", forKey: "qtyTotal");
        ary = [dic1,dic2];
        dic.setValue(ary, forKey: "items");
        arrData.add(dic)
        
        ///customEvent ///
        Intempt.track("purchase", withProperties: arrData, error: nil)
        
    }
}
