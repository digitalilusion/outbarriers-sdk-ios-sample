//
//  OBAPIPayload.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 17/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPIPayload_h
#define OBAPIPayload_h

@interface OBAPIPayload : NSObject

@property (strong, nonatomic) NSString* uuid;
@property (strong, nonatomic) NSDictionary* payload;

+ (OBAPIPayload*) parse:(NSData*)data;

@end

#endif /* OBAPIPayload_h */
