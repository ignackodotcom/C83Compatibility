/******************************************************************************
* \file      CTypeof.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Typeof macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CTYPEOF_H
#define CTYPEOF_H		20260101L



/******************************************************************************
* TYPEOF
*
* present since C23 and doesnt exist in C++
*/
#ifndef TYPEOF

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define TYPEOF(expr)						typeof(expr)
			#define SPECIFIER_TYPEOF_SUPPORTED			1
		#else
			/* pre C23 */
			#define TYPEOF(expr)
			#define SPECIFIER_TYPEOF_SUPPORTED			0
		#endif

	#else

		/* doesnt exist in C++ */
		#define TYPEOF(expr)
		#define SPECIFIER_TYPEOF_SUPPORTED				0

	#endif

#endif


/******************************************************************************
* TYPEOF_UNQUAL
*
* present since C23 and doesnt exist in C++
*/
#ifndef TYPEOF_UNQUAL

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define TYPEOF_UNQUAL(expr)					typeof_unqual(expr)
			#define SPECIFIER_TYPEOF_UNQUAL_SUPPORTED	1
		#else
			/* pre C23 */
			#define TYPEOF_UNQUAL(expr)
			#define SPECIFIER_TYPEOF_UNQUAL_SUPPORTED	0
		#endif

	#else

		/* doesnt exist in C++ */
		#define TYPEOF_UNQUAL(expr)
		#define SPECIFIER_TYPEOF_UNQUAL_SUPPORTED		0

	#endif

#endif



#endif /* CTYPEOF_H */
