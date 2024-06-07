//
//  ViewController.swift
//  ExampleIntempt
//
//  Created by MacBook on 07/06/2024.
//

import UIKit
import Intempt

class ViewController: UIViewController {

    let email = "sampleappuser@xy.com"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }

    @IBAction func setIdentity( sendder:AnyObject){
        
        Intempt.identify(email) { (status, result, error) in
            if(status) {
                if let dictResult = result as? [String: Any] {
                    print(dictResult)
                }
            }
            else {
                if let error = error {
                    print(error.localizedDescription)
                }
            }
        }
    }
    
    @IBAction func consentApproved( sendder:AnyObject){
        
        Intempt.consent(IntemptConsentAction.accept, consentsExpirationTime: "unlimited", category:"Offers", email: email, message: "Yes email me offers, styles and promotions") { status, result, error in
            print(error ?? status)
        }
    }

    @IBAction func sendCustomeEvent( sender: AnyObject? ) {
        
        let objData:[String:Any] = [
            "flightId" : 1,
            "bookingDate" : "2024-06-07",
            "bookingId": 2,
            "bookingStatus" : "booked"
          ]
        
        Intempt.track("flight-booking", data: objData) { (status, result, error) in
            if(status) {
                if let dictResult = result as? [String: Any] {
                    print(dictResult)
                }
            }
            else {
                if let error = error {
                    print(error.localizedDescription)
                }
            }
        }
        
    }
}

