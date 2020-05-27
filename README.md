## Intempt - iOS SDK

[Intempt](https://intempt.com/?utm_campaign=sdk&utm_medium=docs&utm_source=github) is an API-first platform for developers and marketers who are dissatisfied with high-maintenance personalizaton software. Our product is a personalization infrastructure through API and easy-to-use Console that provides a quicker way to build personalized applications. Unlike legacy personalization software we have:

* an API-first SaaS platform that enables personliazation of both digital and physical human activity
* a management console that helps cut down maintenance and reporting overhead
* an infrastructure to scale up user activity in no time

This is a library to facilitate automatic tracking of anonymous and logeed in traffic on your objective-c or swift app.

You can find the full API documentation on [dev.intempt.com](https://dev.intempt.com).

Contents:

* [1](https://github.com/intempt/intempt-intempt-ios-sdk#download) - Download [download](https://dev.intempt.com/#customization-for-web)
* [2](https://github.com/intempt/intempt-ios-sdk#requirements) - Requirements [requirements](https://dev.intempt.com/#customization-for-web)
* [3](https://github.com/intempt/intempt-ios-sdk#install) - Install [install](https://dev.intempt.com/#customization-for-web)
* [4](https://github.com/intempt/intempt-ios-sdk#swift) - Swift [swift](https://dev.intempt.com/#customization-for-web)
* [5](https://github.com/intempt/intempt-ios-sdk#objective-c) - Objective-C [objective-c](https://dev.intempt.com/#customization-for-web)
* [6](https://github.com/intempt/intempt-ios-sdk#identifying-visitors) - How to identify a user [identify](https://dev.intempt.com/#customization-for-web)
* [7](https://github.com/intempt/intempt-ios-sdk#custom-event) - How to record a custom event [custom event](https://dev.intempt.com/#customization-for-web)
* [8](https://github.com/intempt/intempt-ios-sdk#tracking-revenue-with-trackcharge) - How to track revenue [track charge](https://dev.intempt.com/#customization-for-web)
* [9](https://github.com/intempt/intempt-ios-sdk#events-collections-and-properties) - Events, Collections & Properties [event collection properties](https://dev.intempt.com/#events-collections-and-properties)
* [10](https://github.com/intempt/intempt-ios-sdk#ios-events) - Event primer [event](https://dev.intempt.com/#customization-for-web)
* [11](https://github.com/intempt/intempt-ios-sdk#event-properties) - Properties primer [property](https://dev.intempt.com/#properties)
* [12](https://github.com/intempt/intempt-ios-sdk#demo-ios-app) - iOS Demo App [ios-demo-app](https://dev.intempt.com/#properties)


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
 Intempt.track("flight-booking", withProperties: arrayData, error: nil)
```
```json 
   arrayData =      [
                {       
             "flightId" : "1",
            "bookingDate" : "2020-05-26",
            "bookingId": "2",
            "bookingStatus" : "booked"
        }
    ]
``` 

### Tracking Revenue with trackcharge

Notice the key intempt.visit.trackcharge in the sample code above. If you use this key in the event details, the value will be recorded as revenue in the Intempt app. This allows you to assess the revenue impact of campaigns.

Collections do not need to be predefined in the Intempt app.As soon as the tracker logs an event with a new collection name, that collection of events will be available in the app.

### Events, Collections, and Properties
An event is a discrete interaction that occurs on your site. Events are organized by type into collections. Events have properties, key-value pairs that record relevant information about the event.

For example, a user clicks on UIButton

1. It belongs to the interactions collection. (The interaction type is "Action".)

2. The properties including in this event like time of click, other attributes of related elements during the event action and the  action event belongs to which View Controller etc all will be automatically tracked once this tracker code SDK is added in the existing application.


### iOS Events
Events as recorded by the tracker code are conceptually somewhat different than events as defined in the Intempt app.
On the iOS side, events will soon be renamed to actions.

Event collections are organized in a tree structure.

Profile
Launch
Scene
identify
interaction
custom

Because of this hierarchy, any event can be filtered or accessed based on the properties associated with something further up the tree.

For example, if you wanted to find all button clicks associated with a particular visit, you can do that.

Custom events logged manually using the Rest API appear with whatever collection name was assigned, under the custom collection.

### Event Properties
Events have properties, key-value pairs the record information about the event.

Properties are grouped into two collections:

fixed — Properties that are (relatively) stable, related to the profile,launch or the scene. This includes things like device name,osVersion,app name and geolocaiton etc.

timeseries — Properties that are specific to a particular interaction. This includes element-specific details, time stamps, and anything recorded as part of custom events.

When logging a custom event, you can pass in any existing property key names, as well as define your own.

# intempt Proximity SDK - iOS

Install an intempt beacon At your preferable place.Add this SDK in your existing application. Thus it will help you to know about your entry and exit range.
This sdk supports any kind of beacon that allows you to change the UUID in the vendors Beacon Manager. The UUID is a unique broadcasting number which allows Intempt to know which types of beacons to look for. You can think of it like tuning to a radio station.

Today, Intempt’s mobile SDK looks for ONE UUID by default. Use any of them with your existing beacons to enable them with Intempt.

### Key components

intempt  Proximity SDK is built on top of two key components: _

- Entry -  when you are enter a  region.

- Exit -  when you are exit  a  region.
# Installation
### Swift Language :
``` swift
IntemptClient.shared()?.uuidString("0fdb9b40-cf82-4362-ba5d-246f094f5c2a");
IntemptClient.shared()?.delegate = self
Protocol Delegate - intemptDelegate
/*Helps to detect the entry time , when application entered the monitoring region*/
func  didEnterRegion(_ entryTime: String!) {
}
/*Helps to detect the exit time , when application exits the monitoring region*/

func  didExitRegion(_ exitTime: String!) {

}
```

### Objective C Language  :
``` swift
[[IntemptClient  sharedClient] uuidString:@"0fdb9b40-cf82-4362-ba5d-246f094f5c2a"];
[[IntemptClient  sharedClient] setDelegate:self];
Protocol Delegate - intemptDelegate
/*Helps to detect the entry time , when application entered the monitoring region.*/
-(void)didEnterRegion:(NSString*)entryTime;
/*Helps to detect the exit time,when application exits the monitoring region.*/
-(void)didExitRegion:(NSString*)exitTime;
```

### Demo iOS App
1. Add the framework in the application. once it launches, it will show the following pop up. click on "Allow While Using App". 

2. Thus you are enabling the keys to track your location details.

3. In the following demo application, after running it will display a Login Screen. On clicking the login button it fires the IdentifyVisitor function.

4. Here on every touch event the tracker will fetch event details.

5. On clicking payment button , purchase custom event will be fired in this project.

