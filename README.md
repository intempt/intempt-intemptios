# Overview

iOS SDK enables you to track user interactions within the iOS app and manage its configuration via the console. 

The initialized iOS SDK source will automatically collect the following events with data-rich properties:

- **Interaction event**. Aggregates all action events within the app. For example, the user clicks on a link, or button, or types text into a form.
- **Launch event** - gathers data on the launch time (timestamp when the iOS app was opened), app name (_e.g., Intempt Demo Shop App_), iOS device (OS version, device name), geolocation (city, country) screen size (_e.g., 667 x 376 px_) also records unique _visitorId_ and _eventId_ values.
- **Scene event** - gets all the data from the UI structure - how and when (timestamp) your user transitions from one view to another. For example, the user goes from the main app view (Intemp_Demo_Shop.ViewController) to the login view (log_in.ViewController) – the event records this transition.
- **Consent**. Get user consent for using his data for specified purposes (e.g., marketing).
- **Location**- get the user's country and city  - if the user provides permission.

You can also track custom events following the guide below.

<br />

# How to setup iOS SDK

## Requirements <a name="Requirements"></a>

- iOS 12.0+
- Minimum Xcode 10.0

## Getting Started

### Integration

1. First, download SDK from <https://github.com/intempt/intempt-intemptios>. Then open the folder frameworks.

<img width="706" alt="1" src="https://user-images.githubusercontent.com/93919087/210720450-8a56e7a7-a127-439d-ab98-852ce3ac03fd.png">

2. Copy `Intempt.xcframework` into your project directory and then Drag & Drop `Intempt.xcramework` in your iOS app.

<img width="1383" alt="2" src="https://user-images.githubusercontent.com/93919087/210720580-073dcaf6-b874-430a-a728-05e0101d7826.png">
<img width="1375" alt="3" src="https://user-images.githubusercontent.com/93919087/210720771-766ae41a-8f5e-410f-8e65-ac788e87b6c3.png">

3. `Intempt.xcframework` must set to `Embed & Sign`, Select your project `Traget -> Build Phase` expand `Embed Framework` and press `+` add `Intempt.xcframework`

<img width="1375" alt="4" src="https://user-images.githubusercontent.com/93919087/210721318-6eaa1b46-0156-4e56-be9b-a7772b03c976.png">

<img width="1372" alt="5" src="https://user-images.githubusercontent.com/93919087/210721474-28ad3020-2034-4d43-89dd-eae94b307531.png">

make sure in `Target ->General->Framework, Libraries and Embded Contents` `Embed & Sign` is selected.  
<img width="1392" alt="6" src="https://user-images.githubusercontent.com/93919087/210721568-a07f28f5-6b74-4d90-8c73-14afa2b21e51.png">

If you have followed the above steps then you will be able to compile without any error.

### Swift :

If Xcode 11.3 or above

Go to AppDelegate.swift file

```swift
import Intempt
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        ///Your code here
        
        //Initialize Intempt SDK
        let intemptConfig = IntemptConfig(queueEnabled: true, withItemsInQueue: 7, withTimeBuffer: 15, withInitialDelay: 0.3, withInputTextCaptureDisabled: false)
        IntemptTracker.tracking(withOrgId: "Your Organization Id", withProjectId: "Your project Id", withSourceId: "Your Source ID", withToken: "Your Token", withConfig: intemptConfig) { (status, result, error) in
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
        
        return true
    }
```

Access the `ViewController.swift` file and then paste the copied source snippet into the `viewDidLoad` function: 

```swift
import Intempt
  override func viewDidLoad() {
        super.viewDidLoad()
      
     //Initialize Intempt SDK
        let intemptConfig = IntemptConfig(queueEnabled: true, withItemsInQueue: 7, withTimeBuffer: 15, withInitialDelay: 0.3, withInputTextCaptureDisabled: false)
        IntemptTracker.tracking(withOrgId: "Your Organization Id", withProjectId: "Your Project Id", withSourceId: "Your Source ID", withToken: "Your Token", withConfig: intemptConfig) { (status, result, error) in
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
```

### Objective C :

If you are using Xcode 11.3 or above, go to `AppDelegate.m` file and paste the copied source snippet like the following:

```objectivec
@import Intempt;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Your code here
    
    //initalize intempt SDK
    IntemptConfig *intemptConfig  = [[IntemptConfig alloc]initWithQueueEnabled:YES withItemsInQueue:7 withTimeBuffer:15 withInitialDelay:0.3 withInputTextCaptureDisabled:NO];
    [IntemptTracker trackingWithOrgId:@"Your Organization Id" withProjectId:@"Your Project ID" withSourceId:@"Your Source ID" withToken:@"Your Token" withConfig:intemptConfig onCompletion:^(BOOL status, id result, NSError *error) {
        
    }];
    
    return YES;
}
```

Else you will have the `ViewController.m` file and then paste the copied source snippet like the following:

```objectivec
@import Intempt
- (void)viewDidLoad {
    [super viewDidLoad];
    
     //initalize intempt SDK
    IntemptConfig *intemptConfig  = [[IntemptConfig alloc]initWithQueueEnabled:YES withItemsInQueue:7 withTimeBuffer:15 withInitialDelay:0.3 withInputTextCaptureDisabled:NO];
    [IntemptTracker trackingWithOrgId:@"Your Organization Id" withProjectId:@"Your Project ID" withSourceId:@"Your Source ID" withToken:@"Your Token" withConfig:intemptConfig onCompletion:^(BOOL status, id result, NSError *error) {
        
    }];
}
```

### Get Organization ID, Project ID, API key and Source ID

 Copy the Source ID, Project Id, Organization Id, and API Key in your Xcode app for the iOS SDK initialization. 

<img width="1432" alt="7" src="https://user-images.githubusercontent.com/93919087/210728514-448a632d-6c05-4064-8a7f-c3cc59623540.png">

<img width="1423" alt="8" src="https://user-images.githubusercontent.com/93919087/210728524-28d7ce0b-5a4d-4bdc-836e-946d1aaadcbb.png">
<img width="1410" alt="9" src="https://user-images.githubusercontent.com/93919087/210729161-e76ade7a-2bcf-48b1-bb2e-0a59ccb8d893.png">

### Events Tracking

iOS SDK supports both auto-tracked and custom events. Auto-tracked events are automatically tracked when SDK is initialized; for custom events, you must write a custom event tracking code for your app. 

These are the auto-tracked events supported by the SDK:

- Application Launch Tracking
- Screen tracking
- Interaction tracking
- Consent
- Location (depends on the application, if a user of the app has allowed location permission, then country and city-level location is tracked)

#### Get VisitorId from framework

```swift
let visitorId = IntemptClient.shared()?.getVisitorId()
```

#### Identifying visitors

Provide email or phone number.

```swift
IntemptTracker.identify("test@example.com", withProperties: nil) { (status, result, error) in 
    if(status) {
        //Do something
    }
}
```

#### Consent <a name="Consent"></a>

You can record your app consent with builtin consent events.

#### Accept Consent

```swift
let config = IntemptConsentConfig(acceptWithValildUntil: "unlimited", userId: IntemptClient.shared().getVisitorId(), category:"offers")
config.message = "Yes email me offers, styles and promotions"
config.email = "\(emailTxt.text!)"
IntemptTracker.consent(config) { status, result, error in
   
}
```

for valid_until either 'unlimited' can be passed or future timestamp e.g. '1528114618'.  
There are more options and alternate methods for accepting consent, please read the documentation or explore SDK.  
Please read more about consent and available categories <https://app.intempt.com/privacy/consents>

#### Reject Consent

```swift
let config = IntemptConsentConfig(rejectWithUserId: IntemptClient.shared().getVisitorId()), category:"offers")
config.message = "Yes email me offers, styles and promotions"
config.email = "\(emailTxt.text!)"
IntemptTracker.consent(config) { status, result, error in

}
```

There are more options and alternate methods for rejecting consent, please read the documentation or explore SDK.  
Please note that before you call consent, Intempt SDK should be initalized.  
NOTE: It is necessary to set user identity before calling consent events. It can be done like this 

```swift
IntemptTracker.identify("test@example.com", withProperties: nil) { (status, result, error) in 
    if(status) {
        //Do something
    }
}
```

#### Tracking custom events

Depending on the project requirements, you can create custom events to track any user action within the app.

To add a custom event, follow these steps:

- Select Organization -> Source -> Collections
- "Add collection" from the right panel to the existing collections list

<img width="1426" alt="10" src="https://user-images.githubusercontent.com/93919087/210729952-fff64e08-dfd7-4b66-82aa-39a527d7ee13.png">

- "Add field" to the added collection (add as many fields as required)

<img width="1411" alt="11" src="https://user-images.githubusercontent.com/93919087/210729958-045b566d-2d70-41ad-a5ba-105e91127b11.png">

- Set field type (the data from the app needs to match - if an app has a string field and you create an integer field in the schema builder, the data will not be ingested).

<img width="1417" alt="12" src="https://user-images.githubusercontent.com/93919087/210729964-929e112a-740a-4460-a570-4c3d94df9db2.png">

> 📘 Important
> 
> If you want to link the events with the visitor session, then add "sessionId" as the foreign key of the "Session" collection into that collection.

Every custom event schema must have `timestamp of type long` and `eventId of type string` fields; otherwise, your custom event will not be saved, and you will get a bad request error.

> 🚧 Be careful!
> 
> Please be careful when renaming - collection and field names  
> always start with lowercase.

The schema of the  example event 'flight-booking' looks like this:

```swift
let arrayData = [{       
                "flightId" : 1,
                "bookingDate" : "2020-05-26",
                "bookingId": 2,
                "bookingStatus" : "booked"
              }]
        IntemptTracker.track("flight-booking", withProperties: arrayData as? [Any]) { (status, result, error) in
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
```

<img width="380" alt="13" src="https://user-images.githubusercontent.com/93919087/210730118-b2459c7a-5364-41dc-ba8a-5cf701c725c6.png">

> 📘 Important
> 
> eventId, sessionId, timestamp values are automatically added with the payload - you don't need to include while sending custom event.

#### Disable Text Capture

Call this method if you want to disable capturing input texts like UItextField, UItextView. By default its `false`. Secure entries are also excluded for privacy.

```swift
IntemptTracker.disableTextInput(true)
```

#### Disable auto-tracked events

Call this method if you want to disable default tracking. This action is persistent; once disabled, the developer must enable it again to track default events.

```swift
IntemptClient.disableTracking()
```

#### Enable auto-tracked events

Call this method if you disabled tracking and want to enable it again.

```swift
IntemptClient.enableTracking()
```

#### Enable event logging

Call this method if you want to see the logs of all generated events, and errors for debugging purposes. By default, logging is disabled

```swift
IntemptClient.enableLogging()
```

#### Disable event logging

Call this method if you don't want to see any log output in the console.

```swift
IntemptClient.disableLogging()
```

#### Reset tracking session

Call this method to reset the tracking session. It will end the previous session and start a new session.

```swift
IntemptClient.shared().validateTrackingSession()
```

#### End tracking session

Call this method to end the tracking session.

```swift
IntemptClient.shared().endTrackingSession()
```

#### Start tracking session

Call this method in order to start a new tracking session.

```swift
IntemptClient.shared().startTrackingSession()
```

## Tracking iOS14 & later and ATT Security Framework

Our iOS SDK does not require enabling IDFA because data is not forwarded to any external services or linked with third-party data. Analytics is captured to observe the user behavior and visualizations of app usage and improve user experience based on their activities. So with the default configuration, there is no need to add Apple Tracking Transparency permission in info.plist and ask for user consent. However, if your app has other external integrations or you have implemented custom events that track users or share user data with 3rd party services, then you have to include it.

## Privacy - Location Permission

iOS SDK itself doesn't ask the user for location permission and doesn't fetch the user's location. However, the SDK has reference to CoreLocations framework, and if the app (where SDK is integrated)  has obtained user consent for Location then SDK will track the user's location of the city, region, and country. 

As the SDK has reference to the CoreLocations framework so it is required to add `Privacy - Location` in info.plist with explaining the purpose of location fetch and usage.

Go to the app's Info.plist file and add the privacy keys.

| Key                                                         | Value                                                                          |
| ----------------------------------------------------------- | ------------------------------------------------------------------------------ |
| Privacy - Location Always Usage Description                 | Location used to track where you are and showing most relevant content to you. |
| Privacy - Location When In Use Usage Description            | Location used to track where you are and showing most relevant content to you  |
| Privacy - Location Always and When In Use Usage Description | Location used to track where you are and showing most relevant content to you  |

## Experiments <a name="Experiments"></a>

An Experiment is essentially just changes. With the A/B Testing so you can run experiments to test ideas and see the impact they have on key metrics. Want to see if your new checkout screen is actually driving more purchases? Want to try out a new ad format to see if it increases revenue? Use Experiments with A/B Testing to get insight into which changes are helping you achieve your goals.

### How to use a Server-side <a name="Server-side"></a>

Required:  
1: a key from API keys menu; example 36e82934fff945278268971cd3b4d32e.8911b9bc1e3f469a863a7e047cd51fdc  
2: an existing experiment; example id: 99afebd5-885e-48de-9789-704f7ff12437  
3: organization id and project id  
4: add our sdk  
Before you go for coding, you need to setup your experiment with the variants. It can be done with experiment builder <https://help.intempt.com/docs/experiment-builder>. E.g if you want to experiment different profiles for different users, You can add variants as simple key value pair each.  
<img width="1200" alt="variants" src="https://github.com/niazi619/intemptSDK/assets/93919087/47e38a46-fed3-45b7-b50b-b4ad4fa48b13">  
<img width="1107" alt="variant-profile" src="https://github.com/niazi619/intemptSDK/assets/93919087/d54917b1-b224-4970-94a1-f85667a61a92">

### Instantiate the experiments API

First of all instantiate the experiments SDK. 

```swift
let experiment = IntemptExperiments.sharedClient()
experiment?.initWithOrgId(<YOUR_INTEMPT_ORG_ID>, withProjectId: <YOUR_INTEMPT_PROJECT_ID>, withSourceId: <YOUR_INTEMPT_SOURCE_ID>, withToken: IntemptOptions.token, onCompletion: { status, result, error in
})
```

### Choose variant with the user identifier

Pass a user identifier (email, phone, any unique value which you has set as identity) to below method. It will return the response in the completion handler. 'result' is the key value dictionary which can be wraped to NSDictioary or as? [String:Any].

```swift
let experiment = IntemptExperiments.sharedClient()
experiment?.chooseVariant(withUserIdentifier: <User Identifier>, experimentId: <Experiment ID>, device: "MOBILE", uri: "", onCompletion: { status, result, error in
})
```

Based on experiment setup, above method will return result or error. E.g in example of profile case below will be response. In the application/game set profie based on the resutl.

```
{
  "profile_shape": "circle"
}
```

### Choose variant with the profile identifier

Pass a profile identifier (email, phone, any unique value which you has set as identity) to below method. It will return the response in the completion handler. 'result' is the key value dictionary which can be wraped to NSDictioary or as? [String:Any].

```swift
let experiment = IntemptExperiments.sharedClient()
experiment?.chooseVariant(withProfileIdentifier: IntemptClient.shared().getVisitorId(), experimentId: <Experiment ID>,device: nil, uri: nil, onCompletion: { status, result, error in
  
})
```

Based on experiment setup, above method will return result or error. E.g in example of profile case below will be response. In the application/game set profie based on the resutl.

```
{
  "profile_shape": "round"
}
```

if error code is 204, it means no variant available; Possible reasons: 1. the user is not in the target audiance 2. not yet active, out of schedule  
NOTE: It is necessary to set user identity before calling experiements. It can be done like this. If you are going to set identity and call experiement method simultaneously, then first identitty should be set and in completion handler experiment method call should be made. Its because if you call experiment before the identity, experiment will return 204 error code.

```swift
IntemptTracker.identify("test@example.com", withProperties: nil) { (status, result, error) in 
    if(status) {
        //Do something
    }
}
```

## Troubleshooting

### Building failed because the linked and embedded framework 'Intempt.xcframework' was built for iOS + iOS Simulator

You may face this error if you have used the Intempt universal framework. To resolve this, please follow the below steps.

Select your project `Target -> Build Settings` and search `Validate Workspace` Set Value to NO; if its already NO, then set it to YES once and then set it again to NO. This is a workaround as sometimes xcode doesn't understand, so toggling the value between YES/NO  solves it.

<img width="1389" alt="Validate Workspace" src="https://user-images.githubusercontent.com/93919087/144868225-3b68ab16-baa2-43bd-bfe0-d15f91b74401.png">

### Apple App Store uploading issue of invalid unsupported architectures

If you have added `intempt.framework` as `universal` then, when submitting to the Apple App Store, it will show the error of simulator architectures. To resolve this issue, please select your project `Target -> Build Phase` and select `+` sign and add `New Run Script Phase`. It will add an empty script below.

Expand it and put the below script, as shown in the screenshot below

```run script
# skip if we run in debug
if [ "$CONFIGURATION" == "Debug" ]; then
echo "Skip frameworks cleaning in debug version"
exit 0
fi

APP_PATH="${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/"

# This script loops through the frameworks embedded in the application and
# removes unused architectures.
find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK
do
FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"

EXTRACTED_ARCHS=()

for ARCH in $ARCHS
do
echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
done

echo "Merging extracted architectures: ${ARCHS}"
lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
rm "${EXTRACTED_ARCHS[@]}"

echo "Replacing original executable with thinned version"
rm "$FRAMEWORK_EXECUTABLE_PATH"
mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"

done
```

<img width="1198" alt="10" src="https://user-images.githubusercontent.com/93919087/144419018-82fb85a5-6e4a-402e-90f2-c6bda30039d5.png">

### dyld: Library not loaded: @rpath/Intempt.framework/Intempt

`Intempt.xcframework` must set to `Embed & Sign`

<img width="1243" alt="4" src="https://user-images.githubusercontent.com/93919087/144225710-c4b4c9d0-a24f-4fc6-97ae-c82834185d27.png">

### Intempt no such module found

Sometimes xcode behaves strangely and does not link properly, so first delete `Intempt.xcframework` from your project, `clean build` and delete `Drived Data`  
then again, follow the steps to add the framework:

Copy `Intempt.xcramework` into your project directory and then Drag & Drop `Intempt.xcframework` in your iOS app.  
<img width="1417" alt="2" src="https://user-images.githubusercontent.com/93919087/144225626-73c69b69-cc2f-4f91-8b46-e7d832871460.png">  
<img width="1244" alt="3" src="https://user-images.githubusercontent.com/93919087/144225684-83c33889-52e1-4f0f-adbb-1806cbb55d44.png">

`Intempt.xcframework` must set to `Embed & Sign`, Select your project `Traget -> Build Phase` expand `Embed Framework` and press `+` add `Intempt.xcframework`

<img width="1384" alt="adding Intempt into Build Phase" src="https://user-images.githubusercontent.com/93919087/144842029-09e9454d-3990-4265-9086-2d8bd2b3fc97.png">
<img width="1378" alt="Screenshot 2021-12-03 at 12 04 13 PM" src="https://user-images.githubusercontent.com/93919087/144560810-03b1c091-2060-448f-a257-8e7fb0ae6527.png">

make sure in `Target ->General->Framework, Libraries and Embded Contents` `Embed & Sign` is selected.

<img width="1243" alt="4" src="https://user-images.githubusercontent.com/93919087/144225710-c4b4c9d0-a24f-4fc6-97ae-c82834185d27.png">

### No data visible on app.intempt.com console dashboard

For performance and efficiency purposes, the iOS SDK sends events as batch periodically; it may take a few seconds to appear your events on the console.

### Events not sending, taking too long

if you see your events are captured and shown in debug mode but sent too late on the intempt server, then you need to check these configurations:

- `TimeBuffer` its value is in seconds - SDK sends data to the server periodically based on the value of this parameter.
- `ItemsInQueue` its value is the number of events; if you set the value to 10, SDK will wait until 10 or more events are captured then it sends
