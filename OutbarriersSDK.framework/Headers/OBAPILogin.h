//
//  OBAPILogin.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 2/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPILogin_h
#define OBAPILogin_h

@interface OBAPILogin : NSObject

@property (strong, nonatomic) NSString* access_token;
@property (strong, nonatomic) NSString* scope;
@property (strong, nonatomic) NSString* token_type;
@property (nonatomic) NSInteger expires_in;
@property (strong, nonatomic) NSDate* expires_date;


+ (OBAPILogin*) parse:(NSData*)data;

@end

#endif /* OBAPILogin_h */
