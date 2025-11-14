/******************************************************************************
* \file      CNull.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Universal Null macro definition
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CNULL_H
#define CNULL_H		20260101L



#ifndef NULL

	#if defined(SDCC) || defined(__SDCC)
	
		#define NULL		(0)

	#elif !defined(__cplusplus)

		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			#define NULL	nullptr
		#else
			#define NULL	((void*)0)
		#endif

	#else

		#if __cplusplus >= 201103L
			#define NULL	nullptr
		#else
			#define NULL	(0)
		#endif

	#endif

#endif



#endif /* CNULL_H */
