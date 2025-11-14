/******************************************************************************
* \file      CStrgCls.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Storage class macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CSTRGCLS_H
#define CSTRGCLS_H		20260101L



/******************************************************************************
* AUTO
* 
* present since C KR and pre C++ 98
* 
* a little trick to ensure compatibility in c and c++, 
* auto declaration must be empty in c++
*/
#ifndef AUTO

	#ifndef __cplusplus

		/* C */
		#define AUTO							auto
		#define SPECIFIER_AUTO_SUPPORTED		1

	#else
		
		/* C++ */
		#define AUTO
		#define SPECIFIER_AUTO_SUPPORTED		1

	#endif

#endif


/******************************************************************************
* CONST
* 
* present since C89 and pre C++ 98
*/
#ifndef CONST

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC__) || defined(__STDC_VERSION__)
			/* C89 and higher */
			#define CONST						const
			#define SPECIFIER_CONST_SUPPORTED	1
		#else
			/* pre C89 */
			#define CONST
			#define SPECIFIER_CONST_SUPPORTED	0
		#endif

	#else

		/* C++ */
		#define CONST							const
		#define SPECIFIER_CONST_SUPPORTED		1

	#endif

#endif


/******************************************************************************
* CONSTEXPR
* 
* present since C23 and C++ 11
*/
#ifndef CONSTEXPR

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define CONSTEXPR						constexpr
			#define SPECIFIER_CONSTEXPR_SUPPORTED	1
		#else
			/* pre C23 */
			#define CONSTEXPR
			#define SPECIFIER_CONSTEXPR_SUPPORTED	0
		#endif

	#else

		/* C++ */
		#if __cplusplus >= 201103L
			/* C++11 and higher */
			#define CONSTEXPR						constexpr
			#define SPECIFIER_CONSTEXPR_SUPPORTED	1
		#else
			/* pre C++11 */
			#define CONSTEXPR
			#define SPECIFIER_CONSTEXPR_SUPPORTED	0
		#endif

	#endif

#endif


/******************************************************************************
* EXTERN
* 
* present since C KR and pre C++ 98
*/
#ifndef EXTERN

	#define EXTERN								extern
	#define SPECIFIER_EXTERN_SUPPORTED			1

#endif


/******************************************************************************
* INLINE
* 
* present since C99 and C++ 98
*/
#ifndef INLINE

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
			/* C99 and higher */
			#define INLINE						inline
			#define SPECIFIER_INLINE_SUPPORTED	1
		#else
			/* pre C99 */
			#define INLINE
			#define SPECIFIER_INLINE_SUPPORTED	0
		#endif

	#else

		/* C++ */
		#if __cplusplus >= 199711L
			/* C++98 and higher */
			#define INLINE						inline
			#define SPECIFIER_INLINE_SUPPORTED	1
		#else
			/* pre C++98 */
			#define INLINE
			#define SPECIFIER_INLINE_SUPPORTED	0
		#endif

	#endif

#endif


/******************************************************************************
* REGISTER
* 
* present since C KR and pre C++ 98, removed in C++ 17
*/
#ifndef REGISTER

	#ifndef __cplusplus

		/* C */
		#define REGISTER							register
		#define SPECIFIER_REGISTER_SUPPORTED		1

	#else

		/* C++ */
		#if __cplusplus < 201703L
			#define REGISTER						register
			#define SPECIFIER_REGISTER_SUPPORTED	1
		#else
			#define REGISTER
			#define SPECIFIER_REGISTER_SUPPORTED	0
		#endif

	#endif

#endif


/******************************************************************************
* RESTRICT
* 
* present since C99 not a part of the C++ standard
*/
#ifndef RESTRICT

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		/* C99 and higher */
		#define RESTRICT						restrict
		#define SPECIFIER_RESTRICT_SUPPORTED	1
	#else
		/* pre C99 */
		#define RESTRICT
		#define SPECIFIER_RESTRICT_SUPPORTED	0
	#endif

#endif


/******************************************************************************
* STATIC
* 
* present since C KR and pre C++ 98
*/
#ifndef STATIC

	#define STATIC								static
	#define SPECIFIER_STATIC_SUPPORTED			1

#endif


/******************************************************************************
* VOLATILE
* 
* present since C89 and C++ 98
*/
#ifndef VOLATILE

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC__) || defined(__STDC_VERSION__)
			/* C89 and higher */
			#define VOLATILE						volatile
			#define SPECIFIER_VOLATILE_SUPPORTED	1
		#else
			/* pre C89 */
			#define VOLATILE
			#define SPECIFIER_VOLATILE_SUPPORTED	0
		#endif

	#else

		/* C++ */
		#if __cplusplus >= 199711L
			/* C++98 and higher */
			#define VOLATILE						volatile
			#define SPECIFIER_VOLATILE_SUPPORTED	1
		#else
			/* pre C++98 */
			#define VOLATILE
			#define SPECIFIER_VOLATILE_SUPPORTED	0
		#endif

	#endif

#endif



/******************************************************************************
* Example of use
*
* ...
* STATIC INLINE int TestCStrgCls(int* RESTRICT x)
* {
* 	AUTO int autoVar = 0;
* 	CONST int autoVar2 = 0;
* 	CONSTEXPR float f = 23.0f;
* 	EXTERN int externVar;
* 	REGISTER int registerVar = 0;
* 	STATIC int staticVar = 0;
* 	VOLATILE int volatileVar = 0;
* 
* 	return *x * *x;
* }
* ...
*
*/



#endif /* CSTRGCLS_H */
