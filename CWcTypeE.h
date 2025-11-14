/******************************************************************************
* \file      CWcTypeE.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     wctype.h/c extension macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CWCTYPEE_H
#define CWCTYPEE_H		20260101L



#ifndef __cplusplus
	
	/* C95 and higher */
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L
		#include <wctype.h>
	#endif

#else

	/* C++98 and higher */
	#if __cplusplus >= 199711L
		#include <cwctype>
	#endif

#endif



#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L || (defined(__cplusplus) && __cplusplus >= 199711L)


/******************************************************************************
* \brief
*	Chech if value is binary digit character.
*
* \param
*	c - Character value.
*
* \return
*	True if is binary digit, false if not.
*
* \code
*   ...
*   printf("iswbdigit(L'1')   = %d\n", iswbdigit(L'1'));
*	...
* \endcode
*
*/
#ifndef iswbdigit
#define iswbdigit(c)		(((c) >= L'0' && (c) <= L'1')?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is octal digit character.
*
* \param
*	c - Character value.
*
* \return
*	True if is octal digit, false if not.
*
* \code
*   ...
*   printf("iswodigit(L'7')   = %d\n", iswodigit(L'7'));
*	...
* \endcode
*
*/
#ifndef iswodigit
#define iswodigit(c)		(((c) >= L'0' && (c) <= L'7')?1:0)
#endif


#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L || (defined(__cplusplus) && __cplusplus < 201103L)

/******************************************************************************
* \brief
*	Chech if value is blank character.
*
* \param
*	c - Character value.
*
* \return
*	True if is blank, false if not.
*
* \code
*   ...
*   printf("iswblank(L' ')   = %d\n", iswblank(L' '));
*	...
* \endcode
*
*/
#ifndef _MSC_VER
	#ifndef iswblank
		#define iswblank(c)		(((c) == L'\t' || (c) == L' ')?1:0)
	#endif
#endif

#endif /* !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L || (defined(__cplusplus) && __cplusplus < 201103L) */


/******************************************************************************
* \brief
*	Chech if value is lower vowel.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswlowervowel(L'a')   = %d\n", iswlowervowel(L'a'));
*	...
* \endcode
*
*/
#ifndef iswlowervowel
#define iswlowervowel(c)		(((c) == L'a' || (c) == L'e' || (c) == L'i' || (c) == L'o' || (c) == L'u' || (c) == L'y')?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is upper vowel.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswuppervowel(L'a')   = %d\n", iswuppervowel(L'a'));
*	...
* \endcode
*
*/
#ifndef iswuppervowel
#define iswuppervowel(c)		(((c) == L'A' || (c) == L'E' || (c) == L'I' || (c) == L'O' || (c) == L'U' || (c) == L'Y')?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is vowel.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswvowel(L'a')   = %d\n", iswvowel(L'a'));
*	...
* \endcode
*
*/
#ifndef iswvowel
#define iswvowel(c)			((iswlowervowel(c) || iswuppervowel(c))?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is lower consonant.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswlowerconsonant(L'a')   = %d\n", iswlowerconsonant(L'a'));
*	...
* \endcode
*
*/
#ifndef iswlowerconsonant
#define iswlowerconsonant(c)	(((c) >= L'a' && (c) <= L'z' && !iswlowervowel(c))?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is upper consonant.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswupperconsonant(L'a')   = %d\n", iswupperconsonant(L'a'));
*	...
* \endcode
*
*/
#ifndef iswupperconsonant
#define iswupperconsonant(c)	(((c) >= L'A' && (c) <= L'Z' && !iswuppervowel(c))?1:0)
#endif


/******************************************************************************
* \brief
*	Chech if value is consonant.
*
* \param
*	c - Character value.
*
* \return
*	True if is, false if not.
*
* \code
*   ...
*   printf("iswconsonant(L'a')   = %d\n", iswconsonant(L'a'));
*	...
* \endcode
*
*/
#ifndef iswconsonant
#define iswconsonant(c)		((iswlowerconsonant(c) || iswupperconsonant(c))?1:0)
#endif


#endif /* defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L || (defined(__cplusplus) && __cplusplus >= 199711L) */



#endif /* CWCTYPEE_H */
