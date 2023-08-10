//
//  IntemptConsentConfig.h
//  Intempt
//
//  Created by MacBook on 01/08/2023.
//  Copyright © 2023 Intempt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IntemptConsentConfig : NSObject

/** accept/reject
 */
@property (nonatomic,assign) Boolean action;

/** full quotation of the consent message that the customer reacted to.
 */

/** Multiple options:
 unlimited
 <timestamp> - Timestamp of the expiration date
 Manual definition
 @Required: Yes, when action is accept
 */
@property (nonatomic,strong) NSString *validUntil;

/** User profile id, required to be together with source name
 @Required: No, required if masterId and userId are not provided
 */
@property (nonatomic,strong) NSString *profileId;

/** User master id
 @Required: No, required if profileId and userId are not provided
 */
@property (nonatomic,strong) NSString *masterId;

/** User identifier value
 @Required: No if profileId and masterId are not provided,
 */
@property (nonatomic,strong) NSString *userId;

/** Full quotation of the consent message that the customer reacted to.
 @Required: No,
 */
@property (nonatomic,strong) NSString *message;

/** email of the person who provided the consent.
 @Required: No,
 */
@property (nonatomic,strong) NSString *email;

/** Multiple options:
 web_store - Manually created consent in the application.
 api - API which uses basic authentication
 MOBILE - tracked from a an ios app

 @Required: Yes, is generated automatically if consent framework is enabled
 */
@property (nonatomic,strong) NSString *source;

/** sourceId value
 @Required: Yes, if soure is provided. If profile id is not required: null
 */
@property (nonatomic,strong) NSString *sourceId;

/** The ID of the consent category, as defined in project settings.
 Manual definition. If its empty - action will be assigned on all consents categories
 @Required: No
 */
@property (nonatomic,strong) NSString *category;


-(id)initAcceptWithValildUntil:(NSString*)validUntil userId:(NSString*)userId category:(NSString*)category;
-(id)initAcceptWithValildUntil:(NSString*)validUntil profileId:(NSString*)profileId  sourceId:(NSString*)sourceId category:(NSString*)category;
-(id)initRejectWithUserId:(NSString*)userId category:(NSString*)category;
-(id)initRejectWithProfileId:(NSString*)profileId sourceId:(NSString*)sourceId category:(NSString*)category;


@end

NS_ASSUME_NONNULL_END
