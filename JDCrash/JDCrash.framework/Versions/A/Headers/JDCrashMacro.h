//
//  JDCrashMacro.h
//  JDCrash
//
//  Copyright © 2018年 JD.COM. All rights reserved.
//

#ifndef JDCrashMacro_h
#define JDCrashMacro_h

#if __has_feature(nullability)
#define JDC_NONNULL                __nonnull
#define JDC_NULLABLE               __nullable
#define JDC_ASSUME_NONNULL_BEGIN   _Pragma("clang assume_nonnull begin")
#define JDC_ASSUME_NONNULL_END     _Pragma("clang assume_nonnull end")
#else
#define JDC_NONNULL
#define JDC_NULLABLE
#define JDC_START_NONNULL
#define JDC_END_NONNULL
#endif

#endif /* JDCrashMacro_h */
