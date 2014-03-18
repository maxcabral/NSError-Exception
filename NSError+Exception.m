//
//  NSError+Exception.m
//  ttyl
//
//  Created by Maxwell Cabral on 2/1/14.
//  Copyright (c) 2014 ttyl. All rights reserved.
//

#import "NSError+Exception.h"

@implementation NSError (Exception)
- (void)throw
{
    [self throwWithName:@"NSError"];
}

- (void)throwWithName:(NSString*)name
{
    NSLog(@"NSError being thrown: %@",self.debugDescription);
    @throw [NSException exceptionWithName:name
                                   reason:self.debugDescription
                                 userInfo:@{ @"NSError" : self }];
}
@end
