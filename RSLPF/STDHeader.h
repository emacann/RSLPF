#ifndef __STDHEADER_H__
#define __STDHEADER_H__

////////////////////////////////////////////////////////////////////////////////
// C++ version

#ifdef __cplusplus

#if	__cplusplus > 199711L	// C++11
#define NULL	nullptr
#else	// C++97 or older
#define	NULL	0			
#endif

#endif // __cplusplus

////////////////////////////////////////////////////////////////////////////////
// Visual Studio Options

#ifdef	_MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif	// _MSC_VER

////////////////////////////////////////////////////////////////////////////////
// Integer size stuff

typedef	signed char			int8;
typedef	unsigned char		uint8;

typedef	signed short		int16;
typedef	unsigned short		uint16;

typedef	signed int			int32;
typedef	unsigned int		uint32;

typedef	signed long long	int64;
typedef	unsigned long long	uint64;

#define	INT8_MIN			(-127i8 - 1)
#define	INT8_MAX			(127i8)
#define	UINT8_MAX			(0xFFui8)

#define	INT16_MIN			(-32767i16 - 1)
#define	INT16_MAX			(32767i16)
#define	UINT16_MAX			(0xffffui16)

#define	INT32_MIN			(-2147483647i32 - 1)
#define	INT32_MAX			(2147483647i32)
#define	UINT32_MAX			(0xFFFFFFFFui32)

#define	INT64_MIN			(-9223372036854775807i64 - 1)
#define	INT64_MAX			(9223372036854775807i64)
#define	UINT64_MAX			(0xFFFFFFFFFFFFFFFFui64)

////////////////////////////////////////////////////////////////////////////////
// Macros

/// Return maximum between two numbers
#define MAX(a,b)			(a) > (b) ? (a) : (b)
/// Return minimum between two numbers
#define MIN(a,b)			(a) < (b) ? (a) : (b)
/// Return absolute value of a number
#define ABS(a)				(a) > 0	? (a) : (-a)

#endif	// __STDHEADER_H__