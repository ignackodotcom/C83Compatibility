/******************************************************************************
* \file      CDeprec.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Deprecated macro
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CDEPREC_H
#define CDEPREC_H		20260101L



/******************************************************************************
* DEPRECATED
*/
#ifndef DEPRECATED

	#ifndef __cplusplus

		/* C deprecation */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			#define DEPRECATED(msg)						[[deprecated(msg)]]
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#elif defined(_MSC_VER)
			#define DEPRECATED(msg)						__declspec(deprecated(msg))
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#elif defined(__GNUC__) || defined(__clang__)
			#define DEPRECATED(msg)						__attribute__((deprecated(msg)))
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#else
			#define DEPRECATED(msg)
			#define SPECIFIER_DEPRECATED_SUPPORTED		0
		#endif

	#else

		/* C++ deprecation */
		#if __cplusplus >= 201402L
			#define DEPRECATED(msg)						[[deprecated(msg)]]
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#elif defined(_MSC_VER)
			#define DEPRECATED(msg)						__declspec(deprecated(msg))
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#elif defined(__GNUC__) || defined(__clang__)
			#define DEPRECATED(msg)						__attribute__((deprecated(msg)))
			#define SPECIFIER_DEPRECATED_SUPPORTED		1
		#else
			#define DEPRECATED(msg)
			#define SPECIFIER_DEPRECATED_SUPPORTED		0
		#endif

	#endif

#endif /* DEPRECATED */



/******************************************************************************
* Example of use
*
* ...
* DEPRECATED("Use new_function() instead")
* void old_function();
* ...
* DEPRECATED("Use new_variable instead")
* extern int old_variable;
* ...
*/



#endif /* CDEPREC_H */
