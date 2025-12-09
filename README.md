# C83Compatibility and Extensions

## A library to ensure elementary compatibility between C and C++ versions where possible, plus extensions

3rd edition of the library

part of the C83Project<br>
support for 8.3 file naming conventions with the exception of the main include and code files<br>
support C89 and higher editions<br>
<br>

### Alignment macros
This section provides macros related to data alignment in C and C++.

```c
    #define ALIGNAS(expr)               ... /* valid from C11 and C++ 11 */
```
The ALIGNAS macro in C/C++ is used to specify the alignment requirement of a variable or type.

To check if ALIGNAS is supported, you can use the SPECIFIER_ALIGNAS_SUPPORTED macro if is set to 1.

```c
    #define ALIGNOF(expr)               ... /* valid from C11 and C++ 11, returns 0 if not supported */
```
The ALIGNOF macro in C/C++ is used to determine the alignment requirement of a type or variable.

To check if ALIGNOF is supported, you can use the SPECIFIER_ALIGNOF_SUPPORTED macro if is set to 1.
```c
    #define ALIGN_UP(value, alignment)   ...
    #define ALIGN_DOWN(value, alignment) ...
```
The ALIGN_UP and ALIGN_DOWN macros in C/C++ are used to adjust a given value to the nearest higher or lower multiple of a specified alignment, respectively.

```c
    #define IS_ALIGNED(value, alignment) ...
```
The IS_ALIGNED macro in C/C++ is used to check if a given value is aligned to a specified alignment boundary.

```c
    #define ALIGN_PTR(ptr, alignment)   ...
```
The ALIGN_PTR macro in C/C++ is used to align a pointer to a specified alignment boundary.

```c
    #define ALIGN_SIZE(value, multiple) ...
```
The ALIGN_SIZE macro in C/C++ is used to adjust a given size value to be a multiple of a specified value.

Example of use:
```c
    ... 
    struct sse_t
    {
        ALIGNAS(16) float sse_data[4];
    };

    printf("alignment of sse_t is %zu\n", ALIGNOF(struct sse_t));
    ...
```
<br>

### Deprecated attribute macro
This section provides a macro to mark functions or variables as deprecated.
```c
    #define DEPRECATED(msg)         ...
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

### Direction macros
This section provides macros for indicating input and output parameters.
```c
    #define IN                      ...
    #define OUT                     ...
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

### Iso646 macros
This section provides macros for alternative operator representations from the ISO 646 standard.
```c
    #define and                     ...
    #define and_eq                  ...
    #define bitand                  ...
    #define bitor                   ...
    #define compl                   ...
    #define not                     ...
    #define not_eq                  ...
    #define or                      ...
    #define or_eq                   ...
    #define xor                     ...
    #define xor_eq                  ...
```

Example of use:
```c
    ... 
    if (a and b) { ... }
    ...
```
<br>

### SIZE_T_MAX macro
This section provides a macro for finding the maximum for size_t.
```c
    #define SIZE_T_MAX              ...
```
<br>

### No return attribute macro
This section provides a macro to indicate that a function does not return.
```c
    #define NORETURN                ... /* valid from C11 and C++ 11 */
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

### NULL macro
This section provides the NULL macro for representing null pointers.
```c
    #define NULL                    ...
```

Example of use:
```c
    ... 
    int* ptr = NULL;

    if (ptr == NULL) 
    {
        /* Handle null pointer case */
    }
    ...
```
<br>

### Scope macros
This section provides macros for defining variable and function scope.
```c
    #define SCOPE_GLOBAL            ...
    #define SCOPE_GLOBAL_EXTERN     ...

    #define SCOPE_FILE              ...

    #define SCOPE_BLOCK             ...
    #define SCOPE_BLOCK_PERMANENT   ...
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

### Stdarg va_copy macro
This section provides the va_copy macro for copying variable argument lists.
```c
    #define va_copy(dest, src)      ...
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
        /* Use args1 and args2 as needed */
        va_end(args1);
        va_end(args2);
    }
    ...
```
<br>

### Storage class macros
This section provides macros for storage class specifiers in C and C++.
```c
    #define AUTO                    ... /* valid from CKR and pre C++ 98 */
    #define CONST                   ... /* valid from C89 and pre C++ 98 */
    #define CONSTEXPR               ... /* valid from C23 and C++ 11 */
    #define EXTERN                  ... /* valid from CKR and pre C++ 98 */
    #define INLINE                  ... /* valid from C99 and C++ 98 */
    #define REGISTER                ... /* valid from CKR and pre C++ 98, removed in C++ 17 */
    #define RESTRICT                ... /* valid from C99, not a part of the C++ standard */
    #define STATIC                  ... /* valid from CKR and pre C++ 98 */
    #define VOLATILE                ... /* valid from C89 and C++ 98 */
```
To check if each storage class macro is supported, you can use the corresponding SPECIFIER_<STORAGE_CLASS>_SUPPORTED macros if are set to 1.

Example of use:
```c
    ... 
    AUTO int autoVar = 0;
    CONST int constantVar = 42;
    CONSTEXPR float g = 33.0f;
    EXTERN int externalVar;
    INLINE void InlineFunction(void) { staticVar++; return; }
    REGISTER int registerVar = 0;
    float * RESTRICT a;
    STATIC int staticVar = 0;
    VOLATILE int volatileVar = 0;
    ...
```
<br>

### End of string macro
This section provides a macro for the end of string character.
```c
    #define EOS                     ...
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

### Static assert macro
This section provides a macro for compile-time assertions.
```c
    #define STATIC_ASSERT(expr,msg) ... /* valid from C11 and C++ 11 */
```
To check if the STATIC_ASSERT macro is supported, you can use the SPECIFIER_STATIC_ASSERT_SUPPORTED macro if is set to 1.

Example of use:
```c
    ... 
    STATIC_ASSERT(sizeof(int) == 4, "int must be 4 bytes");
    ...
```
<br>

### Thread local storage macro
This section provides a macro for thread-local storage.
```c
    #define THREAD_LOCAL            ... /* valid from C11 and C++ 11 */
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

### Type qualifier macros
This section provides macros for type qualifiers in C and C++.
```c
    #define ATOMIC                  ... /* valid from C11, not in C++ */
    #define COMPLEX                 ... /* valid from C99, not in C++ */
    #define DECIMAL32               ... /* valid from C23, not in C++ */
    #define DECIMAL64               ... /* valid from C23, not in C++ */
    #define DECIMAL128              ... /* valid from C23, not in C++ */
    #define IMAGINARY               ... /* valid from C99, not in C++ */
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

### C type macros
This section provides additional character classification and conversion macros.
```c
    #define isascii(c)              ...
    #define isbdigit(c)             ...
    #define isodigit(c)             ...
    #define isblank(c)              ...
    #define islowervowel(c)         ...
    #define isuppervowel(c)         ...
    #define isvowel(c)              ...
    #define islowerconsonant(c)     ...
    #define isupperconsonant(c)     ...
    #define isconsonant(c)          ...
    #define toascii(c)              ...
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

### W C type macros
This section provides wide character classification macros.
```c
    #define iswbdigit(c)            ...
    #define iswodigit(c)            ...
    #define iswblank(c)             ...
    #define iswlowervowel(c)        ...
    #define iswuppervowel(c)        ...
    #define iswvowel(c)             ...
    #define iswlowerconsonant(c)    ...
    #define iswupperconsonant(c)    ...
    #define iswconsonant(c)         ...
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
2025 11 19 More detailed description in this readme.md file<br>
2025 12 09 Added SIZE_T_MAX macro<br>
<br>
