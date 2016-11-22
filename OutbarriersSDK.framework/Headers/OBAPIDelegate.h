//
//  OBAPIDelegate.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 2/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPIDelegate_h
#define OBAPIDelegate_h

#import "OBAPILogin.h"
#import "OBAPISync.h"
#import "OBAPIResolve.h"
#import "OBAPIResolveRequest.h"
#import "OBAPINearest.h"
#import "OBAPIPayload.h"


@protocol OBAPIDelegate

- (void) receivedLogin:(OBAPILogin*) login;
- (void) receivedSync:(OBAPISync*) sync;
- (void) receivedResolve:(OBAPIResolve*) resolved forRequest:(OBAPIResolveRequest*) request;
- (void) receivedPayload:(OBAPIPayload*) payload;
- (void) receivedNearest:(OBAPINearest*) nearest;

@end

#endif /* OBAPIDelegate_h */
