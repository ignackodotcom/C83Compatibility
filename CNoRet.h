/******************************************************************************
* \file      CNoRet.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Noreturn macro
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CNORET_H
#define CNORET_H		20260101L



/******************************************************************************
* NORETURN
*/
#ifndef NORETURN

	#ifndef __cplusplus

		#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L

			/* C89 - C99 */
			#define NORETURN
			#define SPECIFIER_NORETURN_SUPPORTED		0


		#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L

			/* C11 - C17 */
			#define NORETURN							_Noreturn
			#define SPECIFIER_NORETURN_SUPPORTED		1

		#else

			/* C23 and higher */
			#define NORETURN							[[noreturn]]
			#define SPECIFIER_NORETURN_SUPPORTED		1

		#endif

	#else /* ifndef __cplusplus */

		#if __cplusplus < 201103L

			/* CPP98 */
			#define NORETURN
			#define SPECIFIER_NORETURN_SUPPORTED		0

		#else

			/* CPP11 and higher */
			#define NORETURN							[[noreturn]]
			#define SPECIFIER_NORETURN_SUPPORTED		1

		#endif

	#endif /* ifndef __cplusplus */

#endif /* NORETURN */



/******************************************************************************
* Example of use
*
* ...
* NORETURN void TestCNoRet(void)
* {
* 	while (1)
* 	{
* 		// Infinite loop
* 	}
* }
* ...
*
*/



#endif /* CNORET_H */
