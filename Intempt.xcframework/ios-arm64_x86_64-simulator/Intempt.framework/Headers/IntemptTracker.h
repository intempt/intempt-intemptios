//
//  Intempt.h
//  intempt
//
//  Created by Intempt on 18/03/20.
//  Copyright © 2020 Intempt. All rights reserved.
//

#ifndef Intempt_h
#define Intempt_h
@import UIKit;

typedef NS_ENUM(NSInteger, IntemptConsentAction) {
    IntemptConsentActionAccept,
    IntemptConsentActionReject
};

typedef void(^CompletionHandler)(BOOL status, id result, NSError *error);

@interface Intempt : NSObject

@property (nonatomic, copy) CompletionHandler completion;

/**
 Call this method from ScenseDelegate's `scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions)` or AppDelegate's  `application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?)` for your app to start tracker during launch. Alternatively you can call this method at any ViewController's  `viewDidLoad` method. Wherever you call it will initilaze & track the whole app.
 @param orgName  Your Intempt Organization Name generated from intempt developer console
 @param projectName  Your Intempt Project Name generated from intempt developer console
 @param sourceId Your Intempt Source ID generated from intempt developer console
 @param apiKey Your Intempt apiKey generated from intempt developer console
 @param intemptConfig A configuration object specifying settings like queueEnabled, timeBuffer, retryLimit, initialDelay, retryDelay, isInputTextCaptureEnabled. For more details please look into `IntemptConfig` class.
 @note iOS 13 above should implement it on ScenseDelegate
*/
+ (void)initialize:(NSString*)orgName projectName:(NSString*)projectName sourceId:(NSString*)sourceId apiKey:(NSString*)apiKey intemptConfig:(id)intemptConfig onCompletion:(CompletionHandler)handler;

/**
 Call this to authorize geo location always (iOS 8 and above). You must also add NSLocationAlwaysUsageDescription string to Info.plist to
 authorize geo location always (foreground and background), call this BEFORE doing anything else with ITClient.
 @note From iOS 13 user can't grant location tracking 'always' from app. A user need to go to app settings to manually enable it.
 */
+ (void)authorizeGeoLocationAlways;

/**
 Call this to authorize geo location when in use (iOS 8 and above). You must also add NSLocationWhenInUsageDescription string to Info.plist to
 authorize geo location when in use (foreground), call this BEFORE doing anything else with ITClient.
 */
+ (void)authorizeGeoLocationWhenInUse;

/**
 Call this to disable tracking, By default tracking is enabled. NOTE: this settings is persistent, once disabled it will remain disabled even app is killed and relaucnhed, To renable tracking 'optIn' function should be called.
  NOTE: IntemptSDK respect  and follow Apple rules,  so if Device->Settings->Privacy->Tracking is disabled, then intemptSDK will  not track anything, its  on Developer to ask the user to enable the tracking in appropriate way, e.g showing a nice screen by explaning why user should allow tracking.
 */
+ (void)optOut;

/**
 Call this to enable tracking. By default it's enabled.
 */
+ (void)optIn;

/**
 Call this to disable touch tracking, By default touch tracking is enabled. NOTE: this settings is persistent, once disabled it will remain disabled even app is killed and relaucnhed, To renable touch tracking 'enableTouchTracking' function should be called.
 */
+ (void)disableTouchTracking;

/**
 Call this to enable touch tracking. By default it's enabled.
 */
+ (void)enableTouchTracking;

/**
 Returns whether or not touch tracking is currently enabled.
 
 @return true if touch tracking is enabled, false if disabled.
 */
+ (Boolean)isTouchTrackingEnabled;

/**
 Returns whether or not tracking is currently enabled.
 
 @return true if tracking is enabled, false if disabled.
 */
+ (Boolean)isUserOptIn;

/**
 Call this to disable debug logging.
 */
+ (void)disableLogging;

/**
 Call this to enable debug logging. By default it's disabled.
 */
+ (void)enableLogging;

/**
 clear all cached data and generate new profileId, it also remove cached userId and sessionId
 */
+ (void)logout;

/**
 Returns whether or not logging is currently enabled.
 
 @return true if logging is enabled, false if disabled.
 */
+ (Boolean)isLoggingEnabled;

/**
Get Intempt Visitor ID
@return visitior ID
*/
+ (NSString *)getVisitorId;

/**
Get SessionId
@return SessionId
*/
+ (NSString *)getSessionId;

/**
Get profileId
@return profileId
*/
+ (NSString *)getProfileId;

/**
 Get Intempt SDK Version
 @return The current SDK version.
 */
+ (NSString *)sdkVersion;


/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param userId An Identity i.e, email address or phone number
 @param eventTitle custom title (Optional)
 @param userAttributes A dictionary of user properties (Optional)
*/
+ (void)identify:(NSString*)userId eventTitle:(NSString*)eventTitle userAttributes:(NSDictionary*)userAttributes onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param userId An Identity i.e, email address or phone number
 @param eventTitle custom title (Optional)
*/
+ (void)identify:(NSString*)userId eventTitle:(NSString*)eventTitle onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param userId An Identity i.e, email address or phone number
*/
+ (void)identify:(NSString*)userId onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier for group (email or phone no.) for your app.
 @param eventTitle custom title (Optional)
 @param accountId accountId
 @param userAttributes A dictionary of user properties (Optional)
*/
+ (void)group:(NSString*)eventTitle accountId:(NSString*)accountId userAttributes:(NSDictionary*)userAttributes onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier for group (email or phone no.) for your app.
 @param eventTitle custom title (Optional)
 @param accountId accountId
*/
+ (void)group:(NSString*)eventTitle accountId:(NSString*)accountId onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier for group (email or phone no.) for your app.
 @param accountId accountId
*/
+ (void)group:(NSString*)accountId onCompletion:(CompletionHandler)handler;

/**
 Use this method when you specific tracking information to server
 @param eventTitle eventTitle
 @param data  An object of user properties which are required to be trcked  (Optional)
*/
+ (void)track:(NSString*)eventTitle data:(NSDictionary*)data onCompletion:(CompletionHandler)handler;

/**
 Use this method when you specific tracking information to server
 @param eventTitle eventTitle
 @param userId logged in user id, email/phone or any unique identity (Optional)
 @param accountId logged in user id, email/phone or any unique identity (Optional)
 @param data  An object of user properties which are required to be trcked  (Optional)
 @param accountAttributes  An object of account's properties (Optional)
 @param userAttributes  An object of attributes properties (Optional)
*/
+ (void)record:(NSString*)eventTitle userId:(NSString*)userId accountId:(NSString*)accountId  data:(NSDictionary*)data accountAttributes:(NSDictionary*)accountAttributes userAttributes:(NSDictionary*)userAttributes onCompletion:(CompletionHandler)handler;

/**
Use this Instance method when you want to add a specific event
@param userId  current userId
@param anotherUserId A new userId
*/
+ (void)alias:(NSString *)userId anotherUserId:(NSString *)anotherUserId withCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param action 'accept' or 'reject''
 @param category category e.g news, marketing
 @param email email of the user
 @param consentsExpirationTime 'unlimited' or timestamp
 @param message messsage
*/
+ (void)consent:(IntemptConsentAction)action consentsExpirationTime:(NSString*)consentsExpirationTime category:(NSString*)category email:(NSString*)email message:(NSString*)message onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param action 'accept' or 'reject''
 @param email email of the user
 @param consentsExpirationTime 'unlimited' or timestamp
 @param message messsage
*/
+ (void)consents:(IntemptConsentAction)action consentsExpirationTime:(NSString*)consentsExpirationTime email:(NSString*)email message:(NSString*)message onCompletion:(CompletionHandler)handler;

/**
 Use this method when you want to set a unique identifier (email or phone no.) for your app.
 @param action 'accept' or 'reject''
*/
+ (void)consents:(IntemptConsentAction)action onCompletion:(CompletionHandler)handler;


/**
Use this Instance method when you want to add a specific event
@param names  array of experiments name
*/
+ (void)chooseExperimentsByNames:(NSArray*)names withCompletion:(CompletionHandler)handler;

/**
Use this Instance method when you want to add a specific event
@param groups  array of experiments name
*/
+ (void)chooseExperimentsByGroups:(NSArray*)groups withCompletion:(CompletionHandler)handler;

/**
Use this Instance method when you want to add a specific event
@param names  array of experiences name
*/
+ (void)choosePersonalizationsByNames:(NSArray*)names withCompletion:(CompletionHandler)handler;

/**
Use this Instance method when you want to add a specific event
@param groups  array of experiences name
*/
+ (void)choosePersonalizationsByGroups:(NSArray*)groups withCompletion:(CompletionHandler)handler;


+ (void)productAdd:(NSString *)productId
                       quantity:(NSNumber * _Nullable)quantity
                    onCompletion:(CompletionHandler)handler;

// Declare the method for recording an ordered product list
+ (void)productOrdered:(NSArray<NSDictionary *> *)params onCompletion:(CompletionHandler)handler;


// Declare the method for viewing a product
+ (void)productView:(NSString *)productId
                      onCompletion:(CompletionHandler)handler;

@end
#endif

