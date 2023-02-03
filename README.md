# Table of contents
1. [Requirements](#Requirements)
2. [Getting Started](#GettingStarted)
   1. [Integration](#Integration)
   2. [Get Organization ID Project Id and Source ID](#OrganizationIDandSourceID)
   3. [Events Tracking](#EventsTracking)
   4. [Get VisitorId From Framework](#GetVisitorIdFromFramework)
   5. [Identifying Visitors](#IdentifyingVisitors)
   6. [Consent](#Consent)
   7. [Custom Event](#CustomEvent)
   8. [Disable TextCapture](#DisableTextCapture)
   9. [Disable Default Event Tracking](#DisableDefaultEventTracking)
   10. [Enable Default Event Tracking](#EnableDefaultEventTracking)
   11. [Enable Event Logging](#EnableEventLogging)
   12. [Disable Event Logging](#DisableEventLogging)
   13. [Reset Tracking Session](#ResetTrackingSession)
   14. [End Tracking Session](#EndTrackingSession)
   15. [Start Tracking Session](#StartTrackingSession)
   16. [iOS14&Later and ATTTransportSecurity](#iOS14)
   17. [Privacy Location](#Privacy)
3. [Troubleshooting](#Troubleshooting)
   1. [Building for iOS, but the linked and embedded framework 'Intempt.framework' was built for iOS + iOS Simulator.](#Universalframework)
   2. [Unsupported Architectures](#unsupportedarchitectures)
   3. [dyld: Library not loaded](#dyldLibrarynotloaded)
   4. [Intempt no such module found](#nosuchmodulefound)
   5. [No data visible on app.intempt.com](#nodatafound)
   6. [Events not sending, taking too long](#sendingtakingtoolong)



# Intempt iOS SDK

## Requirements <a name="Requirements"></a>
- iOS 12.0+
- Minimum Xcode 10.0


## Getting Started <a name="GettingStarted"></a>

### Integration: <a name="Integration"></a>
1. At first download sdk from https://github.com/intempt/intempt-intemptios. Then open the folder frameworks.

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

Goto AppDelegate.swift file

``` swift
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
Else you will have the `ViewController.swift` file and then paste the copied source snippet into the `viewDidLoad` function: 

``` swift
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

If you are using Xcode 11.3 or above go to `AppDelegate.m` file and paste the copied source snippet like the following:

``` objectivec
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

``` objectivec
@import Intempt
- (void)viewDidLoad {
    [super viewDidLoad];
    
     //initalize intempt SDK
    IntemptConfig *intemptConfig  = [[IntemptConfig alloc]initWithQueueEnabled:YES withItemsInQueue:7 withTimeBuffer:15 withInitialDelay:0.3 withInputTextCaptureDisabled:NO];
    [IntemptTracker trackingWithOrgId:@"Your Organization Id" withProjectId:@"Your Project ID" withSourceId:@"Your Source ID" withToken:@"Your Token" withConfig:intemptConfig onCompletion:^(BOOL status, id result, NSError *error) {
        
    }];
}
```
### Get Organization ID, Project Id, Token and Source ID <a name="OrganizationIDandSourceID"></a>
To get your organization Id and source Id you need to create your account on https://app.staging.intempt.com
- 1 Create Organization
- 2 Create Project
- 3 Create Source
- 4 Copy Source ID, Project Id, Organization Id and Token/API Key in your Xcode app for IntemptSDK initialization. 

<img width="1432" alt="7" src="https://user-images.githubusercontent.com/93919087/210728514-448a632d-6c05-4064-8a7f-c3cc59623540.png">

<img width="1423" alt="8" src="https://user-images.githubusercontent.com/93919087/210728524-28d7ce0b-5a4d-4bdc-836e-946d1aaadcbb.png">
<img width="1410" alt="9" src="https://user-images.githubusercontent.com/93919087/210729161-e76ade7a-2bcf-48b1-bb2e-0a59ccb8d893.png">



### Events Tracking <a name="EventsTracking"></a>

IntemptSDK track different type events, some of these are default and some are custom, default events are automatically started tracking when SDK is initialized and for custom events developer have to write code whereever required. Below types events are in IntemptSDK
- Application Launch Tracking (Default, automatically tracked)
- Screen Tracking (Default, automatically tracked)
- Interaction Tracking (Default, automatically tracked)
- Consent (Default, automatically tracked)
- Location (Depending on application, if user of the app has allowed location permission then country, city level location is tracked)
- Identity (Manual, Developer have to implement it)
- Custom (Developer have to create schema and implement in app)

#### Get VisitorId From Framework <a name="GetVisitorIdFromFramework"></a>

``` swift
let visitorId = IntemptClient.shared()?.getVisitorId()
```
#### Identifying Visitors <a name="IdentifyingVisitors"></a>
Provide email or phone number.

``` swift
IntemptTracker.identify("test@example.com", withProperties: nil) { (status, result, error) in 
    if(status) {
        //Do something
    }
}
```

#### Consent <a name="Consent"></a>
You can record your app consent with builtin event.

``` swift
IntemptTracker.consent("Marketing", withProperties: "Yes, email me offers, style updates and special invites to sales and events.") { (status, result, error) in 
    if(status) {
        //Do something
    }
}
```

#### Custom Event <a name="CustomEvent"></a>
On using this a user can create a custom event based on the need of the project and can track the event details with that custom method.
To add custom event below should be flow

- 1 Visit the Intempt Console https://app.staging.intempt.com/sources/
- 2 Select Organization -> Source -> Schema
- 3 'Add collection' from the right panel(Schema Builder) to the exisiting collections list
- 5 'Add field' to the added collection, add as many fields as required.
- 6 Set field type carefully e.g if the data from app is string and field type set in int then there will be error.
- 7 If you want to link the events with the visitor session then add 'sessionId' as foreign key of 'Session' collection into that collection

Every custom event schema must have `timestamp of type long` and `eventId of type string` fields, otherwise your custom event will not be saved and you will get bad request error.

**Please becarefull when renaming, Collection and Field name 
always start with small letter**

<img width="1426" alt="10" src="https://user-images.githubusercontent.com/93919087/210729952-fff64e08-dfd7-4b66-82aa-39a527d7ee13.png">
<img width="1411" alt="11" src="https://user-images.githubusercontent.com/93919087/210729958-045b566d-2d70-41ad-a5ba-105e91127b11.png">
<img width="1417" alt="12" src="https://user-images.githubusercontent.com/93919087/210729964-929e112a-740a-4460-a570-4c3d94df9db2.png">


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
`eventId, sessionId, timestamp values are automatically added, you don't need to include while sending custom event`

Schema of above example 'flight-booking' looks like below screenshot
<img width="380" alt="13" src="https://user-images.githubusercontent.com/93919087/210730118-b2459c7a-5364-41dc-ba8a-5cf701c725c6.png">


#### Disable Text Capture <a name="DisableTextCapture"></a>
Call this method if you want to disable capturing input texts like UItextField, UItextView. By default its `false`. Secure entries are also excluded for privacy.

```swift 
IntemptTracker.disableTextInput(true)
```

#### Disable Default Event Tracking <a name="DisableDefaultEventTracking"></a>
Call this method if you want to disable default tracking. This action is persistent, once disabled then developer must need to enable again when want to track default events again.

```swift 
IntemptClient.disableTracking()
```

#### Enable Default Event Tracking <a name="EnableDefaultEventTracking"></a>
Call this method if you had disabled tracking and want to enable again.

```swift 
IntemptClient.enableTracking()
```

#### Enable Event Logging <a name="EnableEventLogging"></a>
Call this method if you want to see the logs of all generated events, errors for debug purposes. By default logging is disabled

```swift 
IntemptClient.enableLogging()
```
#### Disable Event Logging <a name="DisableEventLogging"></a>
Call this method if you want not see any output in console.

```swift 
IntemptClient.disableLogging()
```

#### Reset Tracking Session <a name="ResetTrackingSession"></a>
Call this method in order to reset tracking session. It will end previous session and start new session.

```swift 
IntemptClient.shared().validateTrackingSession()
```
#### End Tracking Session <a name="EndTrackingSession"></a>
Call this method in order to end tracking session.

```swift 
IntemptClient.shared().endTrackingSession()
```
#### Start Tracking Session <a name="StartTrackingSession"></a>
Call this method in order to start a new tracking session.

```swift 
IntemptClient.shared().startTrackingSession()
```

## Tracking iOS14 & later and ATTTransportSecurity framework <a name="iOS14"></a>
Intempt itself does not get IDFA and doesn't track user by default. Data is not forwarded to any external services, and is not linked with any third-party data. Also events captured are not linked to user indentity and not used for user tracking purpose. Analytic are captured to observe the user behavior, viuslations of app usage and improving user experience based on user activities in the app. So with the default configuration there is no need for adding Apple Tracking Transparency permission in info.plist and asking user consent. Also don't include Apple Tracking Transparency framework in your app. However if your app has other external integrations or you have implemented custom events which track user or share user data with other then you have to include it.

## Privacy - Location Permission <a name="Privacy"></a>
IntemptSDK itself doesn't ask user for the location permission and doesn't fetch user location. However IntemptSDK has refence to CoreLocations framework and if the app(where IntemptSDK integrated) already have obtained user consent for Location then IntemptSDK track user location of city, region, country level. As the IntemptSDK has reference to CoreLocations framework so it is required to add `Privacy - Location` in info.plist with explaining the purpose of location fetch and usage.

Go to app's Info.plist file and add the privacy keys.

| Key | Value |
| ------ | ------ |
| Privacy - Location Always Usage Description | Location used to track where you are and showing most relevant content to you.|
| Privacy - Location When In Use Usage Description | Location used to track where you are and showing most relevant content to you |
| Privacy - Location Always and When In Use Usage Description | Location used to track where you are and showing most relevant content to you |


## Troubleshooting <a name="Troubleshooting"></a>
### Building for iOS, but the linked and embedded framework 'Intempt.xcframework' was built for iOS + iOS Simulator. <a name="Universalframework"></a>
If you have used intempt universal framework then you may face this error. To resolve this please follow below steps.

Select your project `Target -> Build Settings` and search `Validate Workspace` Set Value to NO, if its already NO, then set to YES once and then set again to NO. This is workaround as sometimes xcode doesn't understand, so toggeling the value between YES/NO it worked.

<img width="1389" alt="Validate Workspace" src="https://user-images.githubusercontent.com/93919087/144868225-3b68ab16-baa2-43bd-bfe0-d15f91b74401.png">


### Appstore uploading issue of invalid unsupported architectures. <a name="unsupportedarchitectures"></a>

If you have added `intempt.framework` as `universal` then when submitting to app store Apple will show error of simulator architectures. To resolve this issue please select your project `Target -> Build Phase` and select `+` sign and add `New Run Script Phase`. It will add an empty runscript below, expand it and put the below script as shown in below screen shot.

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

### dyld: Library not loaded: @rpath/Intempt.framework/Intempt  <a name="dyldLibrarynotloaded"></a>

`Intempt.xcframework` must set to `Embed & Sign`

<img width="1243" alt="4" src="https://user-images.githubusercontent.com/93919087/144225710-c4b4c9d0-a24f-4fc6-97ae-c82834185d27.png">

### Intempt no such module found <a name="nosuchmodulefound"></a>

Sometimes xcode behaves strange and not link properly, so first delete `Intempt.xcframework` from your project, `clean build` and delete `Drived Data`
then again follow belwo steps to add framework

Copy `Intempt.xcramework` into your project directory and then Drag & Drop `Intempt.xcframework` in your iOS app.
<img width="1417" alt="2" src="https://user-images.githubusercontent.com/93919087/144225626-73c69b69-cc2f-4f91-8b46-e7d832871460.png">
<img width="1244" alt="3" src="https://user-images.githubusercontent.com/93919087/144225684-83c33889-52e1-4f0f-adbb-1806cbb55d44.png">

`Intempt.xcframework` must set to `Embed & Sign`, Select your project `Traget -> Build Phase` expand `Embed Framework` and press `+` add `Intempt.xcframework`

<img width="1384" alt="adding Intempt into Build Phase" src="https://user-images.githubusercontent.com/93919087/144842029-09e9454d-3990-4265-9086-2d8bd2b3fc97.png">
<img width="1378" alt="Screenshot 2021-12-03 at 12 04 13 PM" src="https://user-images.githubusercontent.com/93919087/144560810-03b1c091-2060-448f-a257-8e7fb0ae6527.png">

make sure in `Target ->General->Framework, Libraries and Embded Contents` `Embed & Sign` is selected.

<img width="1243" alt="4" src="https://user-images.githubusercontent.com/93919087/144225710-c4b4c9d0-a24f-4fc6-97ae-c82834185d27.png">

### No data visible on app.intempt.com console dashboard <a name="nodatafound"></a>

For performance and efficiency purpose IntemptSDK send events as batch periodically, it may take few seconds to appear your events on console.

### Events not sending, taking too long <a name="sendingtakingtoolong"></a>

if you see your events are captured and shown in log in debug mode but sent too late on intempt server, then in such case you need to check two below things in your intemptSDK initalization.
- `TimeBuffer' its value is in seconds, if sdk send data to server periodically based on value of this parameter
- `ItemsInQueue` its value is number of events, if you set value to 10, IntemptSDK will wait untill 10 or more events are captured then it sends


