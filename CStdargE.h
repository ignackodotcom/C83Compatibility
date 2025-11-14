/******************************************************************************
* \file      CStdargE.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Stdarg extension macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CSTDARGE_H
#define CSTDARGE_H		20260101L


#ifndef __cplusplus
	#include <stdarg.h>
#else
	#if __cplusplus < 199711L
		#include <stdarg.h>
	#else
		#include <cstdarg>
	#endif
#endif 



#ifndef va_copy

	/******************************************************************************
	* \brief
	*	The va_copy macro is used to create a copy of a variable argument list, 
	*   allowing the destination to reference the same arguments as the source.
	*
	* \param
	*	dst - Destination param.
	* \param
	*	src - Source param.
	*
	* \return
	*	Nothing (void).
	*
	* \code
	*   ...
	* \endcode
	*
	*/
	#if defined(_MSC_VER)

		#define va_copy(dest,src)       ((dest) = (src))

	#elif defined(__GNUC__)

		#define va_copy(dest,src)       __va_copy(dest, src)

	#elif defined(__WATCOMC__)

		#define va_copy(dest,src)       memcpy((dest), (src), sizeof (va_list))

	#elif defined(__SDCC) || defined(SDCC)

		#define va_copy(dst, src)		((void)((dst) = (src)))

	#else

		#define va_copy(dst, src)		((void)((dst) = (src)))

	#endif

#endif /* va_copy */



#endif /* CSTDARGE_H */
