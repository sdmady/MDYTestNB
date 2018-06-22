//
//  JDCrash.h
//  JDCrash
//
//  Copyright © 2018年 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JDCrashMacro.h"
#import "JDCrashConfig.h"
#import "JDCrashCommon.h"

JDC_ASSUME_NONNULL_BEGIN

@interface JDCrash : NSObject

/**
 启动Crash跟踪
 应用崩溃时本地会记录日志,下一次启动时上传

 @param config JDCrash相关配置
 */
+ (void)startWithConfig:(JDCrashConfig *)config;

/**
 记录UIViewController访问

 @param className   UIViewController类名
 @param extra       随UIViewController类名额外记录的信息，长度200以内，超过部分会截断
 */
+ (void)markViewController:(NSString *)className extra:(NSString *)extra;

/**
 记录WebView URL访问

 @param url     URL
 @param type    WebView加载URL的类型：
                JDCrashOpenWebViewURLTypeExternal   : 从WebView加载用户指定的URL
                JDCrashOpenWebViewURLTypeInnner     : 从WebView内部触发加载的URL
 */
+ (void)markWebViewURL:(NSString *)url type:(JDCrashLoadWebViewURLType)type;

/**
 *  获取当前JDCrash版本
 *  V1.0.1
 *
 *  @return JDCrash版本
 */
+ (NSString *)version;

@end

JDC_ASSUME_NONNULL_END



