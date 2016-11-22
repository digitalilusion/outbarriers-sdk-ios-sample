//
//  OBAPINearest.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 17/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPINearest_h
#define OBAPINearest_h

@interface OBAPINearest : NSObject

@property (strong, nonatomic) NSArray* beacons;

+(OBAPINearest*) parse:(NSData*)data;

@end

#endif /* OBAPINearest_h */
