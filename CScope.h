/******************************************************************************
* \file      CScope.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Scope macros
* \details
*
* \see		 https://github.com/ignackodotcom
*			 https://en.cppreference.com/w/c
*            and other resources
******************************************************************************/

#ifndef CSCOPE_H
#define CSCOPE_H		20260101L



#ifndef SCOPE_GLOBAL
	#define SCOPE_GLOBAL
#endif

#ifndef SCOPE_GLOBAL_EXTERN
	#define SCOPE_GLOBAL_EXTERN		extern
#endif



#ifndef SCOPE_FILE
	#define SCOPE_FILE				static
#endif



#ifndef SCOPE_BLOCK
	#define SCOPE_BLOCK
#endif

#ifndef SCOPE_BLOCK_PERMANENT
	#define SCOPE_BLOCK_PERMANENT	static
#endif



#endif /* CSCOPE_H */
