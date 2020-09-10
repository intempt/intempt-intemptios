# Intempt SDK for iOS

[Intempt](https://intempt.com/?utm_campaign=sdk&utm_medium=docs&utm_source=github) is an API-first platform for developers and marketers who are dissatisfied with high-maintenance personalizaton software. Our product is a personalization infrastructure through API and easy-to-use Console that provides a quicker way to build personalized applications. Unlike legacy personalization software we have:

* An API-first SaaS platform that enables personliazation of both digital and physical human activity
* A management console that helps cut down maintenance and reporting overhead
* An infrastructure to scale up user activity in no time

This is a library to facilitate automatic tracking of anonymous and logged in traffic on your Objective-C or Swift app.

You can find the full API documentation on [dev.intempt.com](https://dev.intempt.com).

## Contents

* [1](https://github.com/intempt/intempt-intempt-ios-sdk#download) - Download [SDK](https://dev.intempt.com/#customization-for-web)
* [2](https://github.com/intempt/intempt-ios-sdk#requirements) - Check [requirements](https://dev.intempt.com/#customization-for-web)
* [3](https://github.com/intempt/intempt-ios-sdk#install) - Install [SDK](https://dev.intempt.com/#customization-for-web)
* [4](https://github.com/intempt/intempt-ios-sdk#swift) - Swift [guide](https://dev.intempt.com/#customization-for-web)
* [5](https://github.com/intempt/intempt-ios-sdk#objective-c) - Objective-C [guide](https://dev.intempt.com/#customization-for-web)
* [6](https://github.com/intempt/intempt-ios-sdk#identifying-visitors) - How to [identify](https://dev.intempt.com/#customization-for-web) a user 
* [7](https://github.com/intempt/intempt-ios-sdk#custom-event) - How to record a [custom event](https://dev.intempt.com/#customization-for-web)
* [8](https://github.com/intempt/intempt-ios-sdk#tracking-revenue-with-trackcharge) - How to [track](https://dev.intempt.com/#customization-for-web) revenue 
* [9](https://github.com/intempt/intempt-ios-sdk#events-collections-and-properties) - Custom [Events, Collections & Properties](https://dev.intempt.com/#events-collections-and-properties)
* [10](https://github.com/intempt/intempt-ios-sdk#ios-events) - Event [primer](https://dev.intempt.com/#customization-for-web)
* [11](https://github.com/intempt/intempt-ios-sdk#event-properties) - Properties [primer](https://dev.intempt.com/#properties)
* [12](https://github.com/intempt/intempt-ios-sdk#demo-ios-app) - iOS [demo app](https://dev.intempt.com/#properties)

### Download

Download the `Intempt.framework` available in this repo.

#### Demo
You can test the functionality of this framework with the demo app located over [here](https://github.com/intempt/intempt-ios-demo).

### Requirements

- Minimum iOS 12.0+
- Minimum Xcode 10.0+

### Installation

1. Drag & drop the `Intempt.framework` into your iOS project, underneath your project's folder and **NOT** in the `Frameworks` folder (if exits).

2. Select Project --> General --> Frameworks, Libraries, and Embedded Content and the newly installed `Intempt.framework` must set to `Embed & Sign`. If you didn't download it, please go and download it from [here](https://github.com/intempt/intempt-ios-sdk#download).

3. Next go to the app's `Info.plist` file and add the following privacy keys.

| Key | Value |
| ------ | ------ |
| Privacy - Location Always Usage Description | Location used to track where you are |
| Privacy - Location When In Use Usage Description | Location used to track where you are |
| Privacy - Location Always and When In Use Usage Description | Location used to track where you are |

4. You will need to [log in](https://app.intempt.com/) to Intempt App and create an iOS source.

5. Copy the code snippet generated and paste it just like shown in the following, whether you are using Swift or Objective-C.

#### Swift:

If you are using Xcode 11.3 or above go to `SceneDelegate.swift` file and paste the copied source snippet into the `scene` function:

``` swift
import Intempt
func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {       
       IntemptTracker.tracking(withOrgId: "Your Organization ID", andSourceId: "Your Source ID", andToken: "Your Token")
    
       guard let _ = (scene as? UIWindowScene) else { return }
   }
```

Else you will have the `ViewController.m` file and then paste the copied source snippet into the `viewDidLoad` function:

``` swift
import Intempt
  override func viewDidLoad() {
        super.viewDidLoad()
        IntemptTracker.tracking(withOrgId: "Your Organization ID", andSourceId: "Your Source ID", andToken: "Your Token")
}
```

#### Objective-C:

If you are using Xcode 11.3 or above go to `SceneDelegate.m` file and paste the copied source snippet like the following:

``` objectivec
@import Intempt;
- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    [IntemptTracker trackingWithOrgId:@"Your Organization ID" andSourceId:@"Your Source ID" andToken:@"Your Token"];
}
```

Else you will have the `ViewController.m` file and then paste the copied source snippet like the following:

``` objectivec
@import Intempt
- (void)viewDidLoad {
    [super viewDidLoad];
    [IntemptTracker trackingWithOrgId:@"Your Organization ID" andSourceId:@"Your Source ID" andToken:@"Your Token"];
}
```

### Get VisitorId From Framework

``` swift
let visitorId = IntemptClient.shared()?.getVisitorId()
```

### Identifying Visitors
Provide email or phone number.

``` swift
IntemptTracker.identify("test@example.com", withProperties: nil, error: nil)
```

### Custom Event

When using this you can create a custom event based on the needs of the project and that will help you keep track of event details with that custom method.

```swift 
let arrayData = [{       
                "flightId" : "1",
                "bookingDate" : "2020-05-26",
                "bookingId": "2",
                "bookingStatus" : "booked"
              }]
             
IntemptTracker.track("flight-booking", withProperties: arrayData, error: nil)
```

### Tracking Revenue with `trackcharge`

Notice the key `intempt.visit.trackcharge` in the sample code above. If you use this key in the event details, the value will be recorded as revenue in the Intempt app. This allows you to assess the revenue impact of campaigns.

Collections do not need to be predefined in the Intempt app. As soon as the tracker logs an event with a new collection name, that collection of events will be available in the app.

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
Identify
Interaction
Custom

Because of this hierarchy, any event can be filtered or accessed based on the properties associated with something further up the tree.

For example, if you wanted to find all button clicks associated with a particular visit, you can do that.

Custom events logged manually using the Rest API appear with whatever collection name was assigned, under the custom collection.

### Event Properties

Events have properties, key-value pairs the record information about the event.

Properties are grouped into two collections:

fixed — Properties that are (relatively) stable, related to the profile,launch or the scene. This includes things like device name,osVersion,app name and geolocaiton etc.

timeseries — Properties that are specific to a particular interaction. This includes element-specific details, time stamps, and anything recorded as part of custom events.

When logging a custom event, you can pass in any existing property key names, as well as define your own.


### Demo iOS App

1. Add the framework to the application and once it launches, it will show the a permission pop-up to allow sharing your location. You will have to click on "Allow While Using App". 

2. This enables the keys to track your location details.

3. In the following demo application, after running it will display a Login Screen. After clicking the login button it loads up Intempt's IdentifyVisitor function.

4. On every touch event the tracker will fetch event details.

5. After clicking on the payment button, and successfully going on with a purchase, the purchase custom event will be triggered in the application.

## Intempt Proximity

Install an Intempt beacon At your preferable place.Add this SDK in your existing application. Thus it will help you to know about your entry and exit range.
This sdk supports any kind of beacon that allows you to change the UUID in the vendors Beacon Manager. The UUID is a unique broadcasting number which allows Intempt to know which types of beacons to look for. You can think of it like tuning to a radio station.

Today, Intempt’s mobile SDK looks for ONE UUID by default. Use any of them with your existing beacons to enable them with Intempt.

### Key Components

Intempt Proximity SDK is built on top of two key components:

- Entry - when you are enter a region.

- Exit - when you are exit a region.


Go to app's Info.plist file and add the privacy keys.


| Key | Value |
| ------ | ------ |
| Privacy - Location Always Usage Description | Location used to track where you are |
| Privacy - Location When In Use Usage Description | Location used to track where you are |
| Privacy - Location Always and When In Use Usage Description | Location used to track where you are |
| Privacy - Bluetooth Always Usage Description | Bluetooth used to track where you are |


#### Swift:

``` swift
import Intempt
  override func viewDidLoad() {
  		super.viewDidLoad()
        IntemptTracker.beacon(withOrgId: "Your Organization ID", andSourceId: "Your Source ID", andToken: "Your Token", andDeviceUUID:"Beacon device UUID")
        IntemptClient.shared()?.delegate = self
}
```

Next implement this methods:

``` swift
/*Helps to detect the entry time , when application entered the monitoring region*/
func  didEnterRegion(_ beaconData: CLBeacon!) {
}

/*Helps to detect the exit time , when application exits the monitoring region*/
func  didExitRegion(_ beaconData: CLBeacon!) {
}
```

#### Objective-C:


``` objectivec
@import Intempt;
- (void)viewDidLoad {
    [super viewDidLoad];
    [IntemptTracker beaconWithOrgId:@"Your Organization ID" andSourceId:@"Your Source ID" andToken:@"Your Token" andDeviceUUID:@"Beacon device UUID"];
    IntemptClient.sharedClient.delegate = self;
}
```

Next implement this methods:

``` objectivec
/*Helps to detect the entry time , when application entered the monitoring region*/
- (void)didEnterRegion:(CLBeacon*)beaconData {
}

/*Helps to detect the exit time , when application exits the monitoring region*/
- (void)didExitRegion:(CLBeacon*)beaconData {
}
```


