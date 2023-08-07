//
//  IntemptExperiments.h
//  Intempt
//
//  Created by MacBook on 02/08/2023.
//  Copyright © 2023 Intempt. All rights reserved.
//

#ifndef IntemptExperiments_h
#define IntemptExperiments_h

@import UIKit;

typedef void(^CompletionHandler)(BOOL status, id result, NSError *error);

@interface IntemptExperiments : NSObject

@property (nonatomic, copy) CompletionHandler completion;

+ (IntemptExperiments*)sharedClient;

/**
 Call this method from ScenseDelegate's `scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions)` or AppDelegate's  `application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?)`  Alternatively you can call this method at any ViewController's  `viewDidLoad` method. Wherever you call it will initilaze & track the whole app.
 @param orgId  Your Intempt Organization ID generated from intempt developer console
 @param projectId  Your Intempt Project ID generated from intempt developer console
 @param sourceId Your Intempt Source ID generated from intempt developer console
 @param token Your Intempt Source Token generated from intempt developer console
*/
- (void)initWithOrgId:(NSString*)orgId withProjectId:(NSString*)projectId withSourceId:(NSString*)sourceId withToken:(NSString*)token onCompletion:(CompletionHandler)handler;

/**
 @param userIdentifier simple user identifier. It can be username, phonenumber, email, ... Has to be unique in the project. Required for show item only once
 @param experimentId  required
 @param device  optional
 @param uri  optional
*/
- (void)chooseVariantWithUserIdentifier:(NSString*)userIdentifier experimentId:(NSString*)experimentId device:(NSString*)device uri:(NSString*)uri onCompletion:(CompletionHandler)handler;

/**
 @param profileIdentifier  It can be username, phonenumber, email, ... Has to be unique in the project. Required for show item only once
 @param experimentId  required
 @param device  optional
 @param uri  optional
 */
- (void)chooseVariantWithProfileIdentifier:(NSString*)profileIdentifier experimentId:(NSString*)experimentId device:(NSString*)device uri:(NSString*)uri onCompletion:(CompletionHandler)handler;

/**
 @param userIdentifier simple user identifier. It can be username, phonenumber, email, ... Has to be unique in the project. Required for show item only once
 @param device  optional
 @param uri  optional
*/
- (void)chooseClientExperimentVariantWithUserIdentifier:(NSString*)userIdentifier device:(NSString*)device uri:(NSString*)uri onCompletion:(CompletionHandler)handler;

/**
 @param profileIdentifier  It can be username, phonenumber, email, ... Has to be unique in the project. Required for show item only once
 @param device  optional
 @param uri  optional
 */
- (void)chooseClientExperimentVariantWithProfileIdentifier:(NSString*)profileIdentifier  device:(NSString*)device uri:(NSString*)uri onCompletion:(CompletionHandler)handler;

@end

#endif
