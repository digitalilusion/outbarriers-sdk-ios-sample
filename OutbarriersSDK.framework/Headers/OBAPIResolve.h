//
//  OBAPIResolve.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 3/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPIResolve_h
#define OBAPIResolve_h

#import "OBOutbeacon.h"

@interface OBAPIResolve : NSObject

@property (strong, nonatomic) OBOutbeacon* outbeacon;
@property (nonatomic) NSInteger rssi;
@property (strong, nonatomic) NSString* proximity;
@property (strong, nonatomic) NSString* uuid;

- (NSString*) description;
+ (OBAPIResolve*) parse:(NSData*)data;


@end

typedef OBAPIResolve OBOutbeaconMatch;


#endif /* OBAPIResolve_h */
