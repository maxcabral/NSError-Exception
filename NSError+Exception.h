//
//  NSError+Exception.h
//
//  Created by Maxwell Cabral on 2/1/14.
//  Copyright (c) 2014 Maxwell Cabral. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
A handy wrapper for throwing NSErrors as NSExceptions (if you're into that kind of thing)

Suppose you have the following code:

  NSError *error;
  BOOL success = [[NSFileManager defaultManager] moveItemAtPath:@"/start"
                                                          toPath:@"/end"
                                                           error:&error];

And error is non-nil but most of your logic deals with NSExceptions rather than NSErrors.
Rather than having a corner case where you need to pass in NSErrors, you can simply throw the NSError

  if (!success) {
      [error throw];
  }

Your code will either crash or be handled by your @try/@catch/@finally block.

The logic used is along the lines of:

  @throw [NSException exceptionWithName:@"NSError" reason:self.debugDescription userInfo:@{ @"NSError" : self }];

You can provide a more informative exception name by sending the - (void)throwWithName:(NSString*)name message instead.

NSException/NSError information:

http://nshipster.com/nserror/

http://club15cc.com/code/objective-c/dispelling-nsexception-myths-in-ios-can-we-use-try-catch-finally

https://developer.apple.com/library/mac/documentation/cocoa/reference/foundation/Classes/NSException_Class/Reference/Reference.html

https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSError_Class/Reference/Reference.html
*/
@interface NSError (Exception)
/**
  Creates an exception with the name "NSError", setting the reason to the debugDescription.
  The Error instance is added to the UserInfo dictionary under the key "NSError".
*/
- (void)throw;
/**
  Creates an exception with the given name, setting the reason to the debugDescription.
  The Error instance is added to the UserInfo dictionary under the key "NSError".
*/
- (void)throwWithName:(NSString*)name;
@end
