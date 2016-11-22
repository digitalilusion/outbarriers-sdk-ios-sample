//
//  OBManagerDelegate.h
//  OutbarriersSDK
//
//  Created by chema on 6/10/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBManagerDelegate_h
#define OBManagerDelegate_h

#import "OBError.h"
#import "OBOutbeaconDistance.h"

@protocol OBManagerDelegate <NSObject>

- (void) didIsReady;
- (void) didErrorFound:(OBError*)error;
- (void) didOBMatch:(OBOutbeaconMatch *) sender;
- (void) didNearestOutbeacons:(NSArray<OBOutbeaconDistance*>*)beacons;


@end


#endif /* OBManagerDelegate_h */
