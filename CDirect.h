/******************************************************************************
* \file      CDirect.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Direction macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CDIRECT_H
#define CDIRECT_H		20260101L



/* IN macro signals that the parameter is input */
#ifndef IN
	#define IN
	#define SPECIFIER_IN_SUPPORTED		0
#endif


/* OUT macro signals that the parameter is output */
#ifndef OUT
	#define OUT
	#define SPECIFIER_OUT_SUPPORTED		0
#endif



/******************************************************************************
* Example of use
*
* ...
* void function(IN int param1, IN int param2, OUT int* param3)
* {
* ...
* }
* ...
*
*/



#endif /* CDIRECT_H */
