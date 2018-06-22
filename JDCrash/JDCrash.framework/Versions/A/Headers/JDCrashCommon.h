//
//  JDCrashCommon.h
//  JDCrash
//
//  Copyright © 2018年 JD.COM. All rights reserved.
//

#ifndef JDCrashCommon_h
#define JDCrashCommon_h

/**
 WebView加载URL的类型
 */
typedef NS_ENUM(NSUInteger, JDCrashLoadWebViewURLType) {
    JDCrashOpenWebViewURLTypeExternal,  // 从WebView加载用户指定的URL
    JDCrashOpenWebViewURLTypeInnner,    // 从WebView内部触发加载的URL
};

#endif /* JDCrashCommon_h */
