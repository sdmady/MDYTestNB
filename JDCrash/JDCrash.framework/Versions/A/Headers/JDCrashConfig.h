//
//  JDCrashConfig.h
//  JDCrash
//
//  Copyright © 2018年 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JDCrashMacro.h"
#import "JDCrashLogger.h"

JDC_ASSUME_NONNULL_BEGIN

@interface JDCrashConfig : NSObject

/**
 *  ==========必填参数==========
 *  应用程序ID
 *  注册crash服务后所分配的AppID
 */
@property (nonatomic, copy) NSString *appID;

/**
 *  ==========必填参数==========
 *  应用程序版本
 *  默认为【General】-【Version】中所设置的字段
 *  默认取值为 [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]
 */
@property (nonatomic, copy) NSString *appVersion;

/**
 *  ==========必填参数==========
 *  应用程序build号
 *  默认为【General】-【Build】中所设置的字段
 *  默认取值为 [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"];
 */
@property (nonatomic, copy) NSString *appBuild;

/**
 *  设备唯一标识
 *  默认取值为 [[[[NSUUID UUID] UUIDString] lowercaseString] stringByReplacingOccurrencesOfString:@"-" withString:@""];
 *  如果设置为nil或@"",上报崩溃日志时设备唯一标识会使用默认值。
 *  ================================================================================
 *  @@@注意@@@：该默认值所用取值方案每次启动都会变化
 *  @@@推荐方案@@@：为了崩溃日志与App数据匹配，强烈建议设置为与App自身同样的设备ID方案
 *  ================================================================================
 */
@property (nonatomic, copy) NSString *deviceID;

/**
 *  渠道ID
 *  默认为【AppStore】
 */
@property (nonatomic, copy) NSString *channelID;

/**
 *  用户ID
 *  默认为【nil】
 */
@property (nonatomic, copy) NSString *userID;

/**
 *  添加控制台日志到崩溃日志
 *  默认为【NO】,设置为YES后,当应用通过JDCrashLogger.h中所提供的方法打印的日志会记录到沙盒，再次启动时会随崩溃日志一起上报
 *  输出的日志可在分析崩溃日志作为一个参考，尽可能的打印少量关键信息，以减少最终上报数据大小
 *  控制台日志最多记录200条，如超过200条，上报只截取最后200条
 */
@property (nonatomic, assign, getter=isAddConsoleLogToReportEnable) BOOL enableAddConsoleLogToReport;

/**
 *  设置日志级别
 *  默认为【JDCrashLoggerLevelNone】(不输出)
 */
@property (nonatomic, assign) JDCrashLoggerLevel loggerLevel;

/**
 *  设置debug模式
 *  默认为【NO】(关闭),设置YES后,上报崩溃数据时控制台会有相关日志输入
 *  Release版本建议设置为【NO】
 */
@property (nonatomic, assign, getter=isDebugModeEnabled) BOOL enableDebugMode;

/**
 *  获取默认配置
 *
 *  @return 默认配置
 */
+ (instancetype)defaultConfig;

@end

JDC_ASSUME_NONNULL_END
