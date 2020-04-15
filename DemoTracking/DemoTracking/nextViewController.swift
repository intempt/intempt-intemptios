//
//  nextViewController.swift
//  DemoTracking
//
//  Created by Tanay Bhattacharjee on 04/04/20.
//  Copyright © 2020 Tanay Bhattacharjee. All rights reserved.
//

import UIKit

class nextViewController: UIViewController {
    @IBOutlet var img: UIImageView!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    
    @IBAction func clickValuechange( sender: AnyObject? ) {
        if sender?.tag == 0
        {
            self.img.image = UIImage.init(named: "1.jpeg")
        }
        else  if sender?.tag == 1
        {
            self.img.image = UIImage.init(named: "2.jpeg")
        }
        else
        {
            self.img.image = UIImage.init(named: "3.jpeg")
            
            
        }
        
    }
    
    
    @IBAction func back( sender: AnyObject? ) {
        self.navigationController?.popViewController(animated: true)
    }
    @IBAction func clickcustomEvent( sender: AnyObject? ) {
        let s =  self.storyboard?.instantiateViewController(identifier: "customeventViewController") as! customeventViewController
        self.navigationController?.pushViewController(s, animated: true)
    }
    
}
