# NSError+Exception

[![Version](http://cocoapod-badges.herokuapp.com/v/NSError+Exception/badge.png)](http://cocoadocs.org/docsets/NSError+Exception)
[![Platform](http://cocoapod-badges.herokuapp.com/p/NSError+Exception/badge.png)](http://cocoadocs.org/docsets/NSError+Exception)

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

## Usage

To run the example project; clone the repo, and run `pod install` from the Example directory first.

## Requirements

None! Happy day! Well... NSError, but if you don't have that you're in bad shape.

## Installation

NSError+Exception is available through [CocoaPods](http://cocoapods.org), to install
it simply add the following line to your Podfile:

    pod "NSError+Exception"

## Author

Maxwell Cabral, max@maxcabral.com

## License

NSError+Exception is available under the MIT license. See the LICENSE file for more info.

