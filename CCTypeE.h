/******************************************************************************
* \file      CCTypeE.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     ctype.h/c extension macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CCTYPEE_H
#define CCTYPEE_H		20260101L



#ifndef __cplusplus
	#include <ctype.h>
#else
	#if __cplusplus < 199711L
		#include <ctype.h>
	#else
		#include <cctype>
	#endif
#endif


/******************************************************************************
* \brief
*	Chech if value is ascii character.
*
* \param
*	c - Character value.
*
* \return
*	True if is ascii, false if not.
*
* \code
*   ...
*   printf("isascii('A')   = %d\n", isascii('A'));
*	...
* \endcode
*
*/
#ifndef isascii
#define isascii(c)		(((c) <= 0x7F)?1:0)
#endif

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
*   printf("isbdigit('1')   = %d\n", isbdigit('1'));
*	...
* \endcode
*
*/
#ifndef isbdigit
#define isbdigit(c)		(((c) >= '0' && (c) <= '1')?1:0)
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
*   printf("isodigit('7')   = %d\n", isodigit('7'));
*	...
* \endcode
*
*/
#ifndef isodigit
#define isodigit(c)		(((c) >= '0' && (c) <= '7')?1:0)
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
	*   printf("isblank(' ')   = %d\n", isblank(' '));
	*	...
	* \endcode
	*
	*/
#ifndef _MSC_VER
	#ifndef isblank
		#define isblank(c)		(((c) == '\t' || (c) == ' ')?1:0)
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
*   printf("islowervowel('a')   = %d\n", islowervowel('a'));
*	...
* \endcode
*
*/
#ifndef islowervowel
#define islowervowel(c)		(((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u' || (c) == 'y')?1:0)
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
*   printf("isuppervowel('a')   = %d\n", isuppervowel('a'));
*	...
* \endcode
*
*/
#ifndef isuppervowel
#define isuppervowel(c)		(((c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U' || (c) == 'Y')?1:0)
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
*   printf("isvowel('a')   = %d\n", isvowel('a'));
*	...
* \endcode
*
*/
#ifndef isvowel
#define isvowel(c)			((islowervowel(c) || isuppervowel(c))?1:0)
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
*   printf("islowerconsonant('a')   = %d\n", islowerconsonant('a'));
*	...
* \endcode
*
*/
#ifndef islowerconsonant
#define islowerconsonant(c)	(((c) >= 'a' && (c) <= 'z' && !islowervowel(c))?1:0)
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
*   printf("isupperconsonant('a')   = %d\n", isupperconsonant('a'));
*	...
* \endcode
*
*/
#ifndef isupperconsonant
#define isupperconsonant(c)	(((c) >= 'A' && (c) <= 'Z' && !isuppervowel(c))?1:0)
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
*   printf("isconsonant('a')   = %d\n", isconsonant('a'));
*	...
* \endcode
*
*/
#ifndef isconsonant
#define isconsonant(c)		((islowerconsonant(c) || isupperconsonant(c))?1:0)
#endif


/******************************************************************************
* \brief
*	Value to ascii.
*
* \param
*	c - value.
*
* \return
*	Ascii character.
*
* \code
*   ...
*   printf("toascii(0x130) = '%c'\n", toascii(0x130));
*	...
* \endcode
*
*/
#ifndef toascii
#define toascii(c)		((c) & 0x7F)
#endif



#endif /* CCTYPEE_H */
