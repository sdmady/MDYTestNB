//
//  JDCrashLogger.h
//  JDCrash
//
//  Copyright © 2018年 JD.COM. All rights reserved.
//

#import <CoreFoundation/CoreFoundation.h>

/**
 JDCrashLogger日志级别
 */
typedef NS_ENUM(NSUInteger, JDCrashLoggerLevel) {
    JDCrashLoggerLevelNone,     // 不输出
    JDCrashLoggerLevelError,    // 只输出JDCrashLoggerLevelError级别
    JDCrashLoggerLevelWarn,     // 只输出JDCrashLoggerLevelError、JDCrashLoggerLevelWarn级别
    JDCrashLoggerLevelInfo,     // 只输出JDCrashLoggerLevelError、JDCrashLoggerLevelWarn、 JDCrashLoggerLevelInfo级别
    JDCrashLoggerLevelDebug,    // 只输出JDCrashLoggerLevelError、JDCrashLoggerLevelWarn、 JDCrashLoggerLevelInfo、JDCrashLoggerLevelDebug级别
    JDCrashLoggerLevelTrace,    // 输出所有级别日志
};

#ifdef __OBJC__
    void jdclog_logObjC(JDCrashLoggerLevel level,
                        const char* file,
                        int line,
                        const char* function,
                        CFStringRef fmt, ...);
    #define _JDCLog(LEVEL,FILE,LINE,FUNCTION,FMT,...) jdclog_logObjC(LEVEL,FILE,LINE,FUNCTION,(__bridge CFStringRef)FMT,##__VA_ARGS__)
#else // __OBJC__
    #define _JDCLog(LEVEL,FILE,LINE,FUNCTION,FMT,...)
#endif // __OBJC__

#define JDCLog(LEVEL, FMT, ...) \
                                _JDCLog(LEVEL, \
                                __FILE__, \
                                __LINE__, \
                                __PRETTY_FUNCTION__, \
                                FMT, \
                                ##__VA_ARGS__)

// 输出日志方法
#define JDCLOG_ERROR(FMT, ...)  JDCLog(JDCrashLoggerLevelError, FMT, ##__VA_ARGS__)
#define JDCLOG_WARN(FMT, ...)   JDCLog(JDCrashLoggerLevelWarn, FMT, ##__VA_ARGS__)
#define JDCLOG_INFO(FMT, ...)   JDCLog(JDCrashLoggerLevelInfo, FMT, ##__VA_ARGS__)
#define JDCLOG_DEBUG(FMT, ...)  JDCLog(JDCrashLoggerLevelDebug, FMT, ##__VA_ARGS__)
#define JDCLOG_TRACE(FMT, ...)  JDCLog(JDCrashLoggerLevelTrace, FMT, ##__VA_ARGS__)


