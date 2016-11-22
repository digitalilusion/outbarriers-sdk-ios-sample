//
//  OBOutbeaconDistance.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 17/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBOutbeaconDistance_h
#define OBOutbeaconDistance_h

#import "OBLocal.h"

@interface OBOutbeaconDistance : NSObject

@property (nonatomic) double distance;
@property (strong, nonatomic) OBLocal* local;

+ (OBOutbeaconDistance*) parse:(NSData*)data;
+ (OBOutbeaconDistance*) parseWithDict:(NSDictionary*)dict;

@end

#endif /* OBOutbeaconDistance_h */
