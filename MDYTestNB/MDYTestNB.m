//
//  MDYTestNB.m
//  tt
//
//  Created by deyou on 2018/6/21.
//  Copyright © 2018年 马德友. All rights reserved.
//

#import "MDYTestNB.h"
#import <UIKit/UIKit.h>

@implementation MDYTestNB

-(void)test{
    NSLog(@"测试成功");
    UIAlertView * alt = [[UIAlertView alloc] initWithTitle:@"测试" message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:@"cancel",nil];
    [alt show];
}

@end
