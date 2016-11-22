//
//  ViewController.m
//  SampleOutbarriersSDK
//
//  Created by JM Robles on 2/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//       Unless required by applicable law or agreed to in writing, software
//       distributed under the License is distributed on an "AS IS" BASIS,
//       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//       See the License for the specific language governing permissions and
//       limitations under the License.
//
//


#import "ViewController.h"
#import "AppDelegate.h"

@interface ViewController  ()

@end

@implementation ViewController

double lat = 0.0;
double lng = 0.0;
bool hasCoordinates = false;
CLLocationManager* locationManager;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    locationManager = [[CLLocationManager alloc] init];
    locationManager.delegate = self;
    locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) didOBManagerReady {
    NSLog(@"Manager ready!");
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.bStart setEnabled:true];
        [self.bNearby setEnabled:true];
        [self.swGPS setEnabled:true];
        [self.lStatus setText:@"ready"];
        [self log:@"OB Manager ready"];

    });
    
}
- (void) didOBMatch:(OBOutbeaconMatch *)match {
    NSLog(@"OB Match!");
    if (match == nil) {
        NSLog(@"Null match");
        return;
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        [self log:[NSString stringWithFormat:@"-> Outbeacon detected: %@ - %@",match.outbeacon.name, match.uuid]];
    });
}

- (void) didNearestOutbeacons:(NSArray<OBOutbeaconDistance *> *)beacons {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self log:[NSString stringWithFormat:@"Count nearest beacons: %d", [beacons count]]];
        for (OBOutbeaconDistance* obd in beacons) {
            [self log:[NSString stringWithFormat:@"- %@ at %d m", obd.local.name, (int)obd.distance]];
        }
    });
}
#pragma mark private

- (void) log:(NSString*)line {
    NSString* all = [NSString stringWithFormat:@"%@\n%@", self.lLog.text, line];
    [self.lLog setText:all];
}
- (void) getGPSCoordinates {
    
    [locationManager startUpdatingLocation];
    
    
    
}
- (IBAction)handleStartStopClick:(id)sender {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        AppDelegate* app = (AppDelegate*) [[UIApplication sharedApplication] delegate];
        OBManager* obm = [app getOBManager];
        
        if ([obm isScanning]) {
            [obm stopDetection];
            [self.lStatus setText:@"stopped"];
            [self log:@"scanning stopped"];
            [self.bStart setTitle:@"Start scanning" forState:UIControlStateNormal];
            [self.bNearby setEnabled:true];
            [self.swGPS setEnabled:true];
            
        } else {
            obm.enabledGPS = [self.swGPS isOn];
            if (![obm startDetection]) {
                    [self.lStatus setText:@"error starting detection"];
                return;
            }
            [self.lStatus setText:@"scanning"];
            [self log:[NSString stringWithFormat:@"scanning started %@", ([self.swGPS isOn] ? @"with GPS" : @"without GPS")]];
            [self.bStart setTitle:@"Stop scanning" forState:UIControlStateNormal];
            [self.bNearby setEnabled:false];
            [self.swGPS setEnabled:false];
        }
        
        
    });
    
}
- (IBAction)handleGetNearbyClick:(id)sender {
    NSLog(@"Get nearby beacons click");
    if (!hasCoordinates) {
        NSLog(@"Getting coordinates first");
        [self getGPSCoordinates];
        dispatch_async(dispatch_get_main_queue(), ^{
            UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Alert" message:@"Determinating GPS Coordinates first. Re-Click when ready" preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action){
            }];
            [alert addAction:okAction];
            [self presentViewController:alert animated:YES completion:nil];
            [self log:@"getting GPS coordinates"];
           
        });
        
        return;
    }
    AppDelegate* app = (AppDelegate*) [[UIApplication sharedApplication] delegate];
    OBManager* obm = [app getOBManager];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self log:@"getting nearest beacons"];
    });
    [obm getNearestAtLat:lat andLng:lng insideRadius:30000];
    
    
}
#pragma mark LocationManager delagates

- (void) locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray<CLLocation *> *)locations {
    CLLocation* location = [locations lastObject];
    NSLog(@"latitude %.6f, longitude %.6f, accuracy %f\n",
         location.coordinate.latitude,
         location.coordinate.longitude,
          location.horizontalAccuracy);
    [locationManager stopUpdatingLocation];
    lat = location.coordinate.latitude;
    lng = location.coordinate.longitude;
    hasCoordinates = true;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self log:[NSString stringWithFormat:@"GPS coordinates: (%.6f,%.6f)", lat, lng]];
        [self.lPosition setText:[NSString stringWithFormat:@"(%.6f,%.6f)", lat, lng]];
    });
    
    
}
@end
