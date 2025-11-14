# C83Compatibility and Extensions

## A library to ensure elementary compatibility between C and C++ versions where possible, plus extensions

3rd edition of the library

part of the C83Project<br>
support for 8.3 file naming conventions with the exception of the main include and code files<br>
support C89 and higher editions<br>

<br>

### C/C++ Alignment macros
This section provides macros related to data alignment in C and C++.

```c
    ALIGNAS(expr) /* work since C11 or C++11 */
```
The ALIGNAS macro in C/C++ is used to specify the alignment requirement of a variable or type.

To check if ALIGNAS is supported, you can use the SPECIFIER_ALIGNAS_SUPPORTED macro if is set to 1.

```c
    ALIGNOF(expr) /* work since C11 or C++11, returns 0 if not supported */
```
The ALIGNOF macro in C/C++ is used to determine the alignment requirement of a type or variable.

To check if ALIGNOF is supported, you can use the SPECIFIER_ALIGNOF_SUPPORTED macro if is set to 1.
```c
    ALIGN_UP(value, alignment)
    ALIGN_DOWN(value, alignment)
```
The ALIGN_UP and ALIGN_DOWN macros in C/C++ are used to adjust a given value to the nearest higher or lower multiple of a specified alignment, respectively.

```c
    IS_ALIGNED(value, alignment)
```
The IS_ALIGNED macro in C/C++ is used to check if a given value is aligned to a specified alignment boundary.

```c
    ALIGN_PTR(ptr, alignment)
```
The ALIGN_PTR macro in C/C++ is used to align a pointer to a specified alignment boundary.

```c
    ALIGN_SIZE(value, multiple)
```
The ALIGN_SIZE macro in C/C++ is used to adjust a given size value to be a multiple of a specified value.

Example of use:
```c
    ... 
    ALIGNAS(16) int alignedInt;

    size_t alignment = ALIGNOF(int);
    ...
```
<br>

### C/C++ Deprecated attribute macro
This section provides a macro to mark functions or variables as deprecated.
```c
    DEPRECATED(msg)
```
To check if the DEPRECATED macro is supported, you can use the SPECIFIER_DEPRECATED_SUPPORTED macro if is set to 1.

Example of use:
```c
    ... 
    DEPRECATED("Use NewFunction instead")
    void OldFunction(void) { return; }
    ...
```
<br>

### C/C++ Direction macros
This section provides macros for indicating input and output parameters.
```c
    IN
    OUT
```

Example of use:
```c
    ... 
    void ProcessData(IN int inputData, OUT int* outputData) 
    {
        *outputData = inputData * 2;
        return;
    }
    ...
```
<br>

### C/C++ Iso646 macros
This section provides macros for alternative operator representations from the ISO 646 standard.
```c
    and
    and_eq
    bitand
    bitor
    compl
    not
    not_eq
    or
    or_eq
    xor
    xor_eq
```

Example of use:
```c
    ... 
    if (a and b) { ... }
    ...
```
<br>

### C/C++ No return attribute macro
This section provides a macro to indicate that a function does not return.
```c
    NORETURN
```
To check if the NORETURN macro is supported, you can use the SPECIFIER_NORETURN_SUPPORTED macro if is set to 1.

Example of use:
```c
    ... 
    NORETURN void FatalError(const char* message) 
    {
        fprintf(stderr, "Fatal Error: %s\n", message);
        exit(1);
    }
    ...
```
<br>

### C/C++ NULL macro
This section provides the NULL macro for representing null pointers.
```c
    NULL
```

Example of use:
```c
    ... 
    int* ptr = NULL;

    if (ptr == NULL) 
    {
        // Handle null pointer case
    }
    ...
```
<br>

### C/C++ Scope macros
This section provides macros for defining variable and function scope.
```c
    SCOPE_GLOBAL
    SCOPE_GLOBAL_EXTERN

    SCOPE_FILE

    SCOPE_BLOCK
    SCOPE_BLOCK_PERMANENT
```

Example of use:
```c
    ... 
    SCOPE_GLOBAL int globalVar = 0;

    SCOPE_FILE int fileVar = 0;

    SCOPE_FILE void Function(void) 
    {
        SCOPE_BLOCK int blockVar = 0;
        ...
    }
    ...
```
<br>

### C/C++ Stdarg va_copy macro
This section provides the va_copy macro for copying variable argument lists.
```c
    va_copy(dest, src)
```

Example of use:
```c
    ... 
    void ExampleFunction(int count, ...) 
    {
        va_list args1;
        va_start(args1, count);
        va_list args2;
        va_copy(args2, args1);
        // Use args1 and args2 as needed
        va_end(args1);
        va_end(args2);
    }
    ...
```
<br>

### C/C++ Storage class macros
This section provides macros for storage class specifiers in C and C++.
```c
    AUTO
    CONST
    CONSTEXPR
    EXTERN
    INLINE
    REGISTER
    RESTRICT
    STATIC
    VOLATILE
```
To check if each storage class macro is supported, you can use the corresponding SPECIFIER_<STORAGE_CLASS>_SUPPORTED macros if are set to 1.

Example of use:
```c
    ... 
    AUTO int autoVar = 0;
    CONST int constantVar = 42;
    CONSTEXPR int ConstantExpressionFunction(void) { return 42; }
    EXTERN int externalVar;
    INLINE void InlineFunction(void) { staticVar++; return; }
    REGISTER int registerVar = 0;
    RESTRICT void RestrictedFunction(int* RESTRICT ptr) { *ptr += 1; return; }
    STATIC int staticVar = 0;
    VOLATILE int volatileVar = 0;
    ...
```
<br>

### C/C++ End of string macro
This section provides a macro for the end of string character.
```c
    EOS
```

Example of use:
```c
    ... 
    char str[] = "Hello, World!" EOS;

    if (str[13] == EOS) 
    {
        /* End of string reached */
    }
    ...
```
<br>

### C/C++ Static assert macro
This section provides a macro for compile-time assertions.
```c
    STATIC_ASSERT(expr,msg)
```
To check if the STATIC_ASSERT macro is supported, you can use the SPECIFIER_STATIC_ASSERT_SUPPORTED macro if is set to 1.

Example of use:
```c
    ... 
    STATIC_ASSERT(sizeof(int) == 4, "int must be 4 bytes");
    ...
```
<br>

### C/C++ Thread local storage macro
This section provides a macro for thread-local storage.
```c
    THREAD_LOCAL
```
To check if the THREAD_LOCAL macro is supported, you can use the SPECIFIER_THREAD_LOCAL_SUPPORTED macro if is set to 1.

Example of use:
```c
    ... 
    THREAD_LOCAL int threadLocalVar = 0;

    void ThreadFunction(void) 
    {
        threadLocalVar++;
        return;
    }
    ...
```
<br>

### C/C++ Type qualifier macros
This section provides macros for type qualifiers in C and C++.
```c
    ATOMIC       /* since C11, not in C++ */
    COMPLEX      /* since C99, not in C++ */
    DECIMAL32    /* since C23, not in C++ */
    DECIMAL64    /* since C23, not in C++ */
    DECIMAL128   /* since C23, not in C++ */
    IMAGINARY    /* since C99, not in C++ */
```
To check if each type qualifier macro is supported, you can use the corresponding SPECIFIER_<TYPE_QUALIFIER>_SUPPORTED macros if are set to 1.

Example of use:
```c
    ... 
    ATOMIC int atomicVar = 0;
    COMPLEX double complexVar = 0.0 + 0.0i;
    DECIMAL32 decimal32Var = 0.0DD;
    DECIMAL64 decimal64Var = 0.0DL;
    DECIMAL128 decimal128Var = 0.0DQ;
    IMAGINARY double imaginaryVar = 0.0i;
    ...
```
<br>

### C/C++ C type macros
This section provides additional character classification and conversion macros.
```c
    isascii(c)
    isbdigit(c)
    isodigit(c)
    isblank(c)
    islowervowel(c)
    isuppervowel(c)
    isvowel(c)
    islowerconsonant(c)
    isupperconsonant(c)
    isconsonant(c)
    toascii(c)
```

Example of use:
```c
    ... 
    if (isvowel('A')) 
    {
        /* 'A' is a vowel */
    }

    char ascii = toascii('A'); /* Converts 'A' to its ASCII equivalent */
    ...
```
<br>

### C/C++ W C type macros
This section provides wide character classification macros.
```c
    iswbdigit(c)
    iswodigit(c)
    iswblank(c)
    iswlowervowel(c)
    iswuppervowel(c)
    iswvowel(c)
    iswlowerconsonant(c)
    iswupperconsonant(c)
    iswconsonant(c)
```

Example of use:
```c
    ... 
    if (iswvowel(L'A')) 
    {
        /* 'A' is a vowel */
    }
    ...
```

# Updates
<br>
