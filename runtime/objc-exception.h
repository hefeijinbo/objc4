/*
 * Copyright (c) 2002-2003, 2006-2007 Apple Inc.  All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __OBJC_EXCEPTION_H_
#define __OBJC_EXCEPTION_H_

#include <objc/objc.h>
#include <stdint.h>

typedef id _Nonnull (*objc_exception_preprocessor)(id _Nonnull exception);
typedef int (*objc_exception_matcher)(Class _Nonnull catch_type,
                                      id _Nonnull exception);
typedef void (*objc_uncaught_exception_handler)(id _Null_unspecified /* _Nonnull */ exception);
typedef void (*objc_exception_handler)(id _Nullable unused,
                                       void * _Nullable context);

/** 
 * Throw a runtime exception. This function is inserted by the compiler
 * where \c @throw would otherwise be.
 * 
 * @param exception The exception to be thrown.
 */
OBJC_COLD OBJC_EXPORT OBJC_NORETURN void
objc_exception_throw(id _Nonnull exception)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_COLD OBJC_EXPORT OBJC_NORETURN void
objc_exception_rethrow(void)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_EXPORT id _Nonnull
objc_begin_catch(void * _Nonnull exc_buf)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_EXPORT void
objc_end_catch(void)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_COLD OBJC_EXPORT OBJC_NORETURN void
objc_terminate(void)
    OBJC_AVAILABLE(10.8, 6.0, 9.0, 1.0, 2.0);

OBJC_EXPORT objc_exception_preprocessor _Nonnull
objc_setExceptionPreprocessor(objc_exception_preprocessor _Nonnull fn)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_EXPORT objc_exception_matcher _Nonnull
objc_setExceptionMatcher(objc_exception_matcher _Nonnull fn)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

OBJC_EXPORT objc_uncaught_exception_handler _Nonnull
objc_setUncaughtExceptionHandler(objc_uncaught_exception_handler _Nonnull fn)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);

#if !TARGET_OS_EXCLAVEKIT
// Not for iOS.
OBJC_EXPORT uintptr_t
objc_addExceptionHandler(objc_exception_handler _Nonnull fn,
                         void * _Nullable context)
    OBJC_OSX_AVAILABLE_OTHERS_UNAVAILABLE(10.5);

OBJC_EXPORT void
objc_removeExceptionHandler(uintptr_t token)
    OBJC_OSX_AVAILABLE_OTHERS_UNAVAILABLE(10.5);
#endif // !TARGET_OS_EXCLAVEKIT

#endif  // __OBJC_EXCEPTION_H_

