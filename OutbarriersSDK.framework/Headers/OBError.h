//
//  OBError.h
//  OutbarriersSDK
//
//  Created by Chema Kinon on 18/11/16.
//  Copyright © 2016 Digitalilusion S.L. All rights reserved.
//

#ifndef OBError_h
#define OBError_h

typedef enum {
    
    NO_ERROR,
    LOCATION_DISABLED
    
} OBErrorCode;

@interface OBError : NSObject

@property (nonatomic) OBErrorCode errorCode;
@property (nonatomic, strong) NSString* errorString;

+(OBError*) newError:(OBErrorCode)error;


@end

#endif /* OBError_h */
