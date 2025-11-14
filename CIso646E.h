/******************************************************************************
* \file      CIso646E.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Iso 646 macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CISO646E_H
#define CISO646E_H		20260101L



#if !defined(__cplusplus)

	#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199409L || defined(__TINYC__)

		#define and    &&
		#define and_eq &=
		#define bitand &
		#define bitor  |
		#define compl  ~
		#define not    !
		#define not_eq !=
		#define or     ||
		#define or_eq  |=
		#define xor    ^
		#define xor_eq ^=

	#else

		#include <iso646.h>

	#endif

#else

	#if __cplusplus < 199711L

		#define and    &&
		#define and_eq &=
		#define bitand &
		#define bitor  |
		#define compl  ~
		#define not    !
		#define not_eq !=
		#define or     ||
		#define or_eq  |=
		#define xor    ^
		#define xor_eq ^=

	#elif __cplusplus < 202002L

		#include <ciso646>

	#endif

#endif



#endif /* CISO646E_H */
