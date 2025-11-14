/******************************************************************************
* \file      CTpQlfr.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Type qualifier macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CTPQLFR_H
#define CTPQLFR_H		20260101L



/******************************************************************************
* ATOMIC
*
* since C11, not a part of the C++ standard
*/
#ifndef ATOMIC

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
		/* C11 and higher */
		#ifndef __STDC_NO_ATOMICS__
			#define ATOMIC						_Atomic
			#define SPECIFIER_ATOMIC_SUPPORTED	1
		#else
			#define ATOMIC
			#define SPECIFIER_ATOMIC_SUPPORTED	0
		#endif
	#else
		/* pre C11 */
		#define ATOMIC
		#define SPECIFIER_ATOMIC_SUPPORTED		0
	#endif

#endif /* ATOMIC */


/******************************************************************************
* COMPLEX
* 
* since C99, not a part of the C++ standard
*/
#if defined(__TINYC__)
	#define __STDC_NO_COMPLEX__
#endif

#ifndef COMPLEX

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		/* C99 and higher */
		#ifndef __STDC_NO_COMPLEX__
			#define COMPLEX						_Complex
			#define SPECIFIER_COMPLEX_SUPPORTED	1
		#else
			#define COMPLEX
			#define SPECIFIER_COMPLEX_SUPPORTED	0
		#endif
	#else
		/* pre C99 */
		#define COMPLEX
		#define SPECIFIER_COMPLEX_SUPPORTED		0
	#endif

#endif /* COMPLEX */


/******************************************************************************
* DECIMAL32
*
* since C23, not a part of the C++ standard
*/
#ifndef DECIMAL32

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
		/* C23 and higher */
		#ifdef __STDC_IEC_60559_DFP__
			#define DECIMAL32						_Decimal32
			#define SPECIFIER_DECIMAL32_SUPPORTED	1
		#else
			#define DECIMAL32
			#define SPECIFIER_DECIMAL32_SUPPORTED	0
		#endif
	#else
		/* pre C23 */
		#define DECIMAL32
		#define SPECIFIER_DECIMAL32_SUPPORTED		0
	#endif

#endif /* DECIMAL32 */


/******************************************************************************
* DECIMAL64
*
* since C23, not a part of the C++ standard
*/
#ifndef DECIMAL64

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
		/* C23 and higher */
		#ifdef __STDC_IEC_60559_DFP__
			#define DECIMAL64						_Decimal64
			#define SPECIFIER_DECIMAL64_SUPPORTED	1
		#else
			#define DECIMAL64
			#define SPECIFIER_DECIMAL64_SUPPORTED	0
		#endif
	#else
		/* pre C23 */
		#define DECIMAL64
		#define SPECIFIER_DECIMAL64_SUPPORTED		0
	#endif

#endif /* DECIMAL64 */


/******************************************************************************
* DECIMAL128
*
* since C23, not a part of the C++ standard
*/
#ifndef DECIMAL128

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
		/* C23 and higher */
		#ifdef __STDC_IEC_60559_DFP__
			#define DECIMAL128						_Decimal128
			#define SPECIFIER_DECIMAL128_SUPPORTED	1
		#else
			#define DECIMAL128
			#define SPECIFIER_DECIMAL128_SUPPORTED	0
		#endif
	#else
		/* pre C23 */
		#define DECIMAL128
		#define SPECIFIER_DECIMAL128_SUPPORTED		0
	#endif

#endif /* DECIMAL128 */


/******************************************************************************
* IMAGINARY
*
* since C99, not a part of the C++ standard
*/
#ifndef IMAGINARY

	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		/* C99 and higher */
		#ifdef _Imaginary_I
			#define IMAGINARY						_Imaginary
			#define SPECIFIER_IMAGINARY_SUPPORTED	1
		#else
			#define IMAGINARY
			#define SPECIFIER_IMAGINARY_SUPPORTED	0
		#endif	
	#else
		/* pre C99 */
		#define IMAGINARY
		#define SPECIFIER_IMAGINARY_SUPPORTED		0
	#endif

#endif /* IMAGINARY */



/******************************************************************************
* Example of use
*
* ...
* void TestCTpQlfr(void)
* {
* #if SPECIFIER_ATOMIC_SUPPORTED == 1
* 	ATOMIC int atomicVar = 0;
* #endif
* #if SPECIFIER_COMPLEX_SUPPORTED == 1
* 	COMPLEX double complexVar = 0.0 + 0.0i;
* #endif
* #if SPECIFIER_DECIMAL32_SUPPORTED == 1
* 	DECIMAL32 decimalVar = 0.0DD;
* #endif
* #if SPECIFIER_DECIMAL64_SUPPORTED == 1
* 	DECIMAL64 decimalVar = 0.0DD;
* #endif
* #if SPECIFIER_DECIMAL128_SUPPORTED == 1
* 	DECIMAL128 decimalVar = 0.0DDDD;
* #endif
* #if SPECIFIER_IMAGINARY_SUPPORTED == 1
* 	IMAGINARY float imaginaryVar = 0.0Fi;
* #endif
* 
* 	return;
* }
* ...
*
*/



#endif /* CTPQLFR_H */
