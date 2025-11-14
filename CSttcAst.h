/******************************************************************************
* \file      CSttcAst.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Static assert macro
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CSTTCAST_H
#define CSTTCAST_H		20260101L



/******************************************************************************
* STATIC_ASSERT
*
* present since C11 and C++ 11
*/
#ifndef STATIC_ASSERT

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define STATIC_ASSERT(expr,msg)				static_assert(expr,msg)
			#define SPECIFIER_STATIC_ASSERT_SUPPORTED	1
		#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
			/* C11 and C17 */
			#define STATIC_ASSERT(expr,msg)				_Static_assert(expr,msg)
			#define SPECIFIER_STATIC_ASSERT_SUPPORTED	1
		#else
			/* pre C11 */
			#define STATIC_ASSERT(expr,msg)
			#define SPECIFIER_STATIC_ASSERT_SUPPORTED	0
		#endif

	#else

		#if __cplusplus >= 201103L
			/* C++11 and higher */
			#define STATIC_ASSERT(expr,msg)				static_assert(expr,msg)
			#define SPECIFIER_STATIC_ASSERT_SUPPORTED	1
		#else
			/* pre C++11 */
			#define STATIC_ASSERT(expr,msg)
			#define SPECIFIER_STATIC_ASSERT_SUPPORTED	0
		#endif

	#endif

#endif



/******************************************************************************
* Example of use
*
* ...
* STATIC_ASSERT(EOS == '\0', "EOS must be a character 0");
* ...
*/



#endif /* CSTTCAST_H */
