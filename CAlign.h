/******************************************************************************
* \file      CAlign.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Align macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CALIGN_H
#define CALIGN_H		20260101L



/******************************************************************************
* \brief
*	The ALIGNAS macro in C/C++ is used to specify the alignment requirement 
*   for a variable or type, 
*   allowing developers to control how data is aligned in memory.
*
* \param
*	expr - The alignment requirement in bytes.
*
* \return
*   None
*
* \note
*   present since C11 and C++11
*
* \code
*   ...
*   ALIGNAS(16) int alignedVar = 0;
*	...
* \endcode
*
*/
#ifndef ALIGNAS

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define ALIGNAS(expr)					alignas(expr)
			#define SPECIFIER_ALIGNAS_SUPPORTED		1
		#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
			/* C11 and C17 */
			#define ALIGNAS(expr)					_Alignas(expr)
			#define SPECIFIER_ALIGNAS_SUPPORTED		1
		#else
			/* pre C11 */
			#define ALIGNAS(expr)
			#define SPECIFIER_ALIGNAS_SUPPORTED		0
		#endif

	#else

		#if __cplusplus >= 201103L
			/* C++11 and higher */
			#define ALIGNAS(expr)					alignas(expr)
			#define SPECIFIER_ALIGNAS_SUPPORTED		1
		#else
			/* pre C++11 */
			#define ALIGNAS(expr)
			#define SPECIFIER_ALIGNAS_SUPPORTED		0
		#endif

	#endif

#endif /* ALIGNAS */


/******************************************************************************
* \brief
*	The ALIGNOF macro in C/C++ is used to obtain the alignment requirement of a 
*   given type or expression, utilizing the alignof operator.
*
* \param
*	expr - The type or expression whose alignment requirement is to be determined.
*
* \return
*   The alignment requirement in bytes.
*
* \note
*   present since C11 and C++11
*
* \code
*   ...
*   size_t alignment = ALIGNOF(int);
*	...
* \endcode
*
*/
#ifndef ALIGNOF

	#ifndef __cplusplus

		/* C */
		#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
			/* C23 and higher */
			#define ALIGNOF(expr)					alignof(expr)
			#define SPECIFIER_ALIGNOF_SUPPORTED		1
		#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && __STDC_VERSION__ < 202311L
			/* C11 and C17 */
			#define ALIGNOF(expr)					_Alignof(expr)
			#define SPECIFIER_ALIGNOF_SUPPORTED		1
		#else
			/* pre C11 */
			#define ALIGNOF(expr)					0
			#define SPECIFIER_ALIGNOF_SUPPORTED		0
		#endif

	#else
	
		/* C++ */
		#if __cplusplus >= 201103L
			/* C++11 and higher */
			#define ALIGNOF(expr)					alignof(expr)
			#define SPECIFIER_ALIGNOF_SUPPORTED		1
		#else
			/* pre C++11 */
			#define ALIGNOF(expr)					0
			#define SPECIFIER_ALIGNOF_SUPPORTED		0
		#endif

	#endif

#endif /* ALIGNOF */


/******************************************************************************
* \brief
*	Align a given value up to the specified alignment.
*
* \param
*	value - The original value to be aligned.
* \param
*	alignment - The alignment boundary that the value should conform to.
*
* \return
*	The smallest value greater than or equal to `value` that is a multiple of `alignment`.
*
* \note
*
* \code
*   ...
*   value = ALIGN_UP(24, 16);
*	...
* \endcode
*
*/
#define ALIGN_UP(value, alignment) \
	(size_t)(((value) + ((alignment) - 1)) & ~((alignment) - 1))


/******************************************************************************
* \brief
*	Align a given value down to the specified alignment.
*
* \param
*	value - The original value to be aligned.
* \param
*	alignment - The alignment boundary that the value should conform to.
*
* \return
*	The largest value less than or equal to `value` that is a multiple of `alignment`.
*
* \note
*
* \code
*   ...
*   value = ALIGN_DOWN(24, 16);
*	...
* \endcode
*
*/
#define ALIGN_DOWN(value, alignment) (size_t)((value) & ~((alignment) - 1))


/******************************************************************************
* \brief
*	Check if a value is aligned to the specified alignment.
*
* \param
*	value - The value to be checked.
* \param
*	alignment - The alignment boundary to check against.
*
* \return
*	Non-zero (true) if `value` is aligned to `alignment`, zero (false) otherwise.
*
* \note
*
* \code
*   ...
*   b = IS_ALIGNED(24, 16);
*	...
* \endcode
*
*/
#define IS_ALIGNED(value, alignment) \
	((((size_t)(value)) & (((size_t)(alignment)) - 1)) == 0)


/******************************************************************************
* \brief
*	Align a pointer to the nearest higher aligned address.
*
* \param
*	ptr - The pointer to be aligned.
* \param
*	alignment - The alignment boundary that the pointer should conform to.
*
* \return
*	A pointer that is aligned to the specified `alignment`.
*
* \note
*
* \code
*   ...
*   ptr = ALIGN_PTR(ptr, 16);
*	...
* \endcode
*
*/
#define ALIGN_PTR(ptr, alignment) \
	((void *)ALIGN_UP((size_t)(ptr), (size_t)(alignment)))


/******************************************************************************
* \brief
*	Align a size value up to the nearest multiple.
*
* \param
*	value - The size value to be aligned.
* \param
*	multiple - The multiple to align the value to.
*
* \return
*	The nearest size value that is a multiple of `multiple`.
*
* \note
*
* \code
*   ...
*   value = ALIGN_SIZE(24, 16);
*	...
* \endcode
*
*/
#define ALIGN_SIZE(value, multiple) \
	(size_t)(((value) + (multiple) - 1) / (multiple) * (multiple))



#endif /* CALIGN_H */
