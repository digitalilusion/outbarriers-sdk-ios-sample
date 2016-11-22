//
//  OBOutbeacon.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 3/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBOutbeacon_h
#define OBOutbeacon_h

@interface OBOutbeacon : NSObject

@property (strong, nonatomic) NSString* uuid;
@property (strong, nonatomic) NSString* name;
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (strong, nonatomic) NSString* location;
@property (strong, nonatomic) NSString* accesibility;
@property (strong, nonatomic) NSString* url;
@property (strong, nonatomic) NSDictionary* payload;

+ (OBOutbeacon*) parse:(NSData*)data;
+ (OBOutbeacon*) parseWithDict:(NSDictionary*)dict;

@end


#endif /* OBOutbeacon_h */
