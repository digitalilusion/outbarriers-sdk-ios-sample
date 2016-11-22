//
//  OBUtil.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 2/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBUtil_h
#define OBUtil_h

@interface OBUtil : NSObject

+ (NSString*) getModel;
+ (NSString*) getInstallationID;
+ (NSString*) getHash:(NSString*)uuid andMajor:(NSInteger)major andMinor:(NSInteger)minor;

@end

#endif /* OBUtil_h */
