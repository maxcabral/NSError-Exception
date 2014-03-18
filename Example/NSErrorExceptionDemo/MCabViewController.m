//
//  MCabViewController.m
//  NSErrorExceptionDemo
//
//  Created by Maxwell Cabral on 3/17/14.
//  Copyright (c) 2014 Maxwell Cabral. All rights reserved.
//

#import "MCabViewController.h"
#import <NSError+Exception/NSError+Exception.h>

@interface MCabViewController ()
@property (weak) IBOutlet UITextView *outputTextView;
@end

@implementation MCabViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)throwSafe:(id)sender
{
    @try {
        [self badFileMove];
    }
    @catch (NSException *exception) {
        self.outputTextView.text = exception.description;
        NSError *originalError = exception.userInfo[@"NSError"];
        NSLog(@"%@",originalError);
    }
}

- (IBAction)throwUnsafe:(id)sender
{
    [self badFileMove];
}

- (void)badFileMove
{
    NSError *error;
    BOOL success = [[NSFileManager defaultManager] moveItemAtPath:@"/start"
                                                           toPath:@"/end"
                                                            error:&error];
    if (!success) {
        [error throw];
    }
}

@end
