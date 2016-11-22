//
//  OBAPISync.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 3/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPISync_h
#define OBAPISync_h


@interface OBAPISync : NSObject

@property (nonatomic) BOOL offline;
@property (nonatomic) BOOL internal;
@property (nonatomic) BOOL status;
@property (strong, nonatomic) NSString* pubkey;
// TODO: offline beacons

+ (OBAPISync*) parse:(NSData*)data;

@end


#endif /* OBAPISync_h */
