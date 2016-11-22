//
//  AppDelegate.m
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

#import "AppDelegate.h"

#import <OutbarriersSDK/OutbarriersSDK.h>
#import "ViewController.h"


@interface AppDelegate  ()

@end

@implementation AppDelegate  


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.obm = [[OBManager alloc] initWithDelegate:self];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
#pragma mark Public API
- (BOOL) isOBScanning {
    if (self.obm == nil) {
        return false;
    }
    return [self.obm isScanning];
    
}
- (OBManager*) getOBManager {
    return self.obm;
}
#pragma mark OB Manager delegate

- (void) didIsReady {
    
    NSLog(@"OB is ready to start detection!");
    ViewController* viewController = (ViewController*) [[[UIApplication sharedApplication] keyWindow] rootViewController];
    [viewController didOBManagerReady];
    
}

- (void) didOBMatch:(OBOutbeaconMatch *)match {

    NSLog(@"OB match! => %@", match);
    ViewController* viewController = (ViewController*) [[[UIApplication sharedApplication] keyWindow] rootViewController];
    [viewController didOBMatch:match];

}

- (void) didErrorFound:(OBError *)error {
    
    NSLog(@"OB Error found => %@", error.errorString);
}
- (void) didNearestOutbeacons:(NSArray<OBOutbeaconDistance *> *)beacons {
    NSLog(@"OB Outbeacons near: %lu", (unsigned long)[beacons count]);
    ViewController* viewController = (ViewController*) [[[UIApplication sharedApplication] keyWindow] rootViewController];
    [viewController didNearestOutbeacons:beacons];
}
@end
