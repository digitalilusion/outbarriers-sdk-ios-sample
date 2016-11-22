//
//  OBAPI.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 2/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    DISCONNECTED,
    LOGGED,
    READY,
    RESOLVING
} OBAPIState;

@protocol OBAPIDelegate;

@interface OBAPI : NSObject
@property(weak, nonatomic) id<OBAPIDelegate> delegate;

- (void) loginWithAPIKey:(NSString*)apiKey andSecret:(NSString*) apiSecret;
- (void) sync;
- (void) resolve:(NSString*)uuid withMajor:(NSInteger)major withMinor:(NSInteger)minor withRSSI:(NSInteger)rssi withBattery:(NSInteger)batt;
- (void) resolveWithLat:(double)lat withLng:(double)lng withAccuracy:(double)radius;
- (void) setPayload:(NSDictionary*) dict forOutbeaconUUID:(NSString*)uuid;
- (void) getNearestForLat:(double)lat withLng:(double)lng insideRadius:(NSInteger)radius;
- (BOOL) isReady;


@end
