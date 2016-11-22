//
//  OBManager.h
//  OutbarriersSDK
//
//  Created by chema on 6/10/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#include "OBAPIDelegate.h"
#include "OBManagerDelegate.h"



@interface OBManager : NSObject <OBAPIDelegate, CLLocationManagerDelegate>

@property id<OBManagerDelegate> delegate;
@property (strong, nonatomic) CLLocationManager* locationManager;
@property (nonatomic) BOOL enabledGPS;

- (OBManager*) initWithDelegate:(id<OBManagerDelegate>)	delegate;
- (OBManager*) initWithDelegate:(id<OBManagerDelegate>)	delegate andAPIKey:(NSString*)apiKey andAPISecret:(NSString*)apiSecret;
- (BOOL) startDetection;
- (BOOL) stopDetection;
- (BOOL) setPayload:(NSDictionary*)data forOutbeacon:(OBOutbeacon*) obo;
- (BOOL) getNearestAtLat:(double)lat andLng:(double)lng insideRadius:(NSInteger) radius;
- (BOOL) isScanning;



@end
