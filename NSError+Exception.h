//
//  NSError+Exception.h
//  ttyl
//
//  Created by Maxwell Cabral on 2/1/14.
//  Copyright (c) 2014 ttyl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSError (Exception)
- (void)throw;
- (void)throwWithName:(NSString*)name;
@end
