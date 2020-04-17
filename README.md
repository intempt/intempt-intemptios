## Intempt - iOS SDK

[Intempt](https://intempt.com/?utm_campaign=sdk&utm_medium=docs&utm_source=github) is an API-first platform for developers and marketers who are dissatisfied with high-maintenance personalizaton software. Our product is a personalization infrastructure through API and easy-to-use Console that provides a quicker way to build personalized applications. Unlike legacy personalization software we have:

* an API-first SaaS platform that enables personliazation of both digital and physical human activity
* a management console that helps cut down maintenance and reporting overhead
* an infrastructure to scale up user activity in no time

This is a library to facilitate automatic tracking of anonymous and logeed in traffic on your objective-c or swift app.

You can find the full API documentation on [dev.intempt.com](https://dev.intempt.com).

Contents:

* [1](https://github.com/intempt/intempt-intemptjs#install-and-initialize-script) - Downliad [download](https://dev.intempt.com/#customization-for-web)
* [2](https://github.com/intempt/intempt-intemptjs#identifying-visitors) - Requirements [requirements](https://dev.intempt.com/#customization-for-web)
* [3](https://github.com/intempt/intempt-intemptjs#identifying-visitors) - Install [install](https://dev.intempt.com/#customization-for-web)
* [4](https://github.com/intempt/intempt-intemptjs#recording-custom-events) - Swift [swift](https://dev.intempt.com/#customization-for-web)
* [5](https://github.com/intempt/intempt-intemptjs#tracking-revenue-with-trackcharge) - Objective-C [objective-c](https://dev.intempt.com/#customization-for-web)

* [6](https://github.com/intempt/intempt-intemptjs#events-collections-and-properties) - Events, Collections & Properties [event collection properties](https://dev.intempt.com/#events-collections-and-properties)
* [7](https://github.com/intempt/intempt-intemptjs#tracker-events) - Event primer [event](https://dev.intempt.com/#customization-for-web)
* [8](https://github.com/intempt/intempt-intemptjs#event-properties) - Properties primer [property](https://dev.intempt.com/#properties)


### Download :
Download intempt.framework from https://github.com/intempt/intempt-objc-swift-sdk.
 Then Drag & Drop intempt.Framework in your iOS Project.

### Requirements
- Minimum iOS 12.0+
- Minimum Xcode 10.0

### Install
Open Project-->General-> Frameworks,Libraries, and Embedded Content 
Intempt.framework must set to  Embed & Sign
|<img src="https://github.com/intempt/iOS-Tracker-sdk/blob/master/screenshots/1.png" width="1200">|

Next go to app's  Info.Plist file and add the privacy key.

| Key | Value |
| ------ | ------ |
| Privacy - Location Always Usage Description   |$(PRODUCT_NAME) location use |
| Privacy - Location When In Use Usage Description | $(PRODUCT_NAME) location use |
| Privacy - Location Always and When In Use Usage Description | $(PRODUCT_NAME) location use 

### Swift :
If Xcode 11.3 or above
go to SceneDelegate.swift File
``` swift
import intempt
func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {       
       Intempt.tracking(withOrgId: "playground", andSourceId: "76765820017905664", andToken: "g2t2epJv/Ge/bcxLnsRZRVBjORiaEdA/.CzKQ2qSvrjASvv80xD2uD2CYrzzYh94FwrWh3qpVi+UQhzGmnr/4rR+Nm8GfHR0t")
        
        guard let _ = (scene as? UIWindowScene) else { return }
   }

Else

Goto ViewController.mt File
import intempt
  override func viewDidLoad() {
        super.viewDidLoad()
       Intempt.tracking(withOrgId: "playground", andSourceId: "76765820017905664", andToken: "g2t2epJv/Ge/bcxLnsRZRVBjORiaEdA/.CzKQ2qSvrjASvv80xD2uD2CYrzzYh94FwrWh3qpVi+UQhzGmnr/4rR+Nm8GfHR0t")
}
```
### Objective C :
If Xcode 11.3 or above
go to SceneDelegate.m File
``` swift
@import intempt;

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    [Intempt trackingWithOrgId:@"playground" andSourceId:@"76765820017905664" andToken:@"g2t2epJv/Ge/bcxLnsRZRVBjORiaEdA/.CzKQ2qSvrjASvv80xD2uD2CYrzzYh94FwrWh3qpVi+UQhzGmnr/4rR+Nm8GfHR0t"];
}

Else
Goto ViewController.m File
@import intempt
- (void)viewDidLoad {
    [super viewDidLoad];

    [Intempt trackingWithOrgId:@"playground" andSourceId:@"76765820017905664" andToken:@"g2t2epJv/Ge/bcxLnsRZRVBjORiaEdA/.CzKQ2qSvrjASvv80xD2uD2CYrzzYh94FwrWh3qpVi+UQhzGmnr/4rR+Nm8GfHR0t"];


}
```

### Identifying Visitors
``` swift
Intempt.identify("test@intempt.com", withProperties: nil, error: nil)
```
### Custom event
On using this a user can create a custom event based on the need of the project and can track the event details with that custom method.
``` swift
 Intempt.track(collectionName, withProperties: arraydata, error: nil)
```
example :
``` swift
 Intempt.track("purchase", withProperties: arrayData, error: nil)
```
```json 
   arrayData =      [
                {
            "items":             [
                                {
                    "itemName":  "Slim Jean",
                    "price":"180",
                    "qty"  "2"
                },
                                {
                    "itemName":  "Trousers",
                    "price":  "80",
                    "qty":  "2",
                },
            ],
            "qtyTotal" : "4",
            "totalPrice": "260",
        }
    ]
``` 
### DemoTracking App
Add the framework in the application. once it launches, it will show the following pop up. click on "Allow While Using App". Thus you are enabling the keys to track your location details.
<img src="https://github.com/intempt/iOS-Tracker-sdk/blob/master/screenshots/2.png" width=“50>

In the following demo application, after running it will display a Login Screen. On clicking the login button it fires the IdentifyVisitor function .
<img src="https://github.com/intempt/iOS-Tracker-sdk/blob/master/screenshots/3.png" width=“50>

Here on every touch event the tracker will fetch event details.
<img src=https://github.com/intempt/iOS-Tracker-sdk/blob/master/screenshots/4.png" width=“50>


On clicking payment button , purchase custom event will be fired in this project 
<img src="https://github.com/intempt/iOS-Tracker-sdk/blob/master/screenshots/5.png" width=“50>




