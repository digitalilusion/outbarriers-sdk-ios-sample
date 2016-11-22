//
//  OBAPIResolveRequest.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 17/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBAPIResolveRequest_h
#define OBAPIResolveRequest_h

@interface OBAPIResolveRequest : NSObject
    
@property (strong, nonatomic) NSString* uuid;
@property (nonatomic) NSInteger major;
@property (nonatomic) NSInteger minor;
@property (nonatomic) double lat;
@property (nonatomic) double lng;
@property (nonatomic) BOOL isGPS;

-(OBAPIResolveRequest*) initWithUUID:(NSString*)uuid withMajor:(NSInteger)major withMinor:(NSInteger)minor;


@end

#endif /* OBAPIResolveRequest_h */
