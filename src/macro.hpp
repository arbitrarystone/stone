#ifndef __STONE_MACRO_H__
#define __STONE_MACRO_H__

#include <string.h>
#include <assert.h>
#include "log.hpp"
#include "util.hpp"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#   define STONE_LIKELY(x)       __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#   define STONE_UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
#   define STONE_LIKELY(x)      (x)
#   define STONE_UNLIKELY(x)      (x)
#endif

/// 断言宏封装
#define STONE_ASSERT(x) \
    if(STONE_UNLIKELY(!(x))) { \
        STONE_LOG_ERROR(STONE_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << stone::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

/// 断言宏封装
#define STONE_ASSERT2(x, w) \
    if(STONE_UNLIKELY(!(x))) { \
        STONE_LOG_ERROR(STONE_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << stone::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

#endif

/*
#ifndef __STONE_MACRO_HPP__
#define __STONE_MACRO_HPP__
#include <assert.h>
#include <string.h>
#include "util.hpp"

#if defined __GNUC__ || defined __llvm__
#   define STONE_LICKLY(x)       __builtin_expect(!!(x), 1)
#   define STONE_UNLICKLY(x)     __builtin_expect(!!(x), 0)
#else
#   define STONE_LICKLY(x)      (x)
#   define STONE_UNLICKLY(x)    (x)
#endif

#define STONE_ASSERT(x) \
    if(STONE_UNLICKLY(!(x))){ \
        STONE_LOG_ERROR(STONE_LOG_ROOT())<<"ASSERTION:"#x \
            <<"\nbacktrace\n" \
            <<stone::BacktraceToString(100,2,"    "); \
        assert(x); \
    }
#define STONE_ASSERT2(x,w) \
     if(STONE_UNLICKLY(!(x))){ \
        STONE_LOG_ERROR(STONE_LOG_ROOT())<<"ASSERTION:"#x \
            <<"\n"<<w \
            <<"\nbacktrace\n" \
            <<stone::BacktraceToString(100,2,"    "); \
        assert(x); \
    }

#endif */
