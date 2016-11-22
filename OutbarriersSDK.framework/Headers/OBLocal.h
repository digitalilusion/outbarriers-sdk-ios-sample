//
//  OBLocal.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 17/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBLocal_h
#define OBLocal_h

@interface OBLocal : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* uuid;
@property (nonatomic, strong) NSString* city;
@property (nonatomic, strong) NSString* category;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* web;
@property (nonatomic, strong) NSString* email;
@property (nonatomic) NSInteger zip;

+ (OBLocal*) parse:(NSDictionary*)dict;


@end
#endif /* OBLocal_h */
