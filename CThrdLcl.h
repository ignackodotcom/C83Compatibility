/******************************************************************************
* \file      CThrdLcl.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Thread local Storage class macro
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CTHRDLCL_H
#define CTHRDLCL_H		20260101L



/******************************************************************************
* THREAD_LOCAL
*
* present since C11 and C++ 11
*/
#ifndef THREAD_LOCAL

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define THREAD_LOCAL						thread_local
			#define SPECIFIER_THREAD_LOCAL_SUPPORTED	1
		#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
			/* C11 and C17 */
			#define THREAD_LOCAL						_Thread_local
			#define SPECIFIER_THREAD_LOCAL_SUPPORTED	1
		#else
			/* pre C11 */
			#define THREAD_LOCAL
			#define SPECIFIER_THREAD_LOCAL_SUPPORTED	0
		#endif

	#else

		#if __cplusplus >= 201103L
			/* C++11 and higher */
			#define THREAD_LOCAL						thread_local
			#define SPECIFIER_THREAD_LOCAL_SUPPORTED	1
		#else
			/* pre C++11 */
			#define THREAD_LOCAL
			#define SPECIFIER_THREAD_LOCAL_SUPPORTED	0
		#endif

	#endif

#endif



#endif /* CTHRDLCL_H */
