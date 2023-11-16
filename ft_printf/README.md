### ft_printf Project Overview

The ft_printf project was an enriching experience that focused on recreating the `printf()` function from the standard C library. The main learning outcome was mastering variadic functions, which are functions like `printf()` that can take a variable number of arguments. This was both challenging and fascinating, as it demanded an understanding of how to access these arguments using macros from `stdarg.h` such as `va_start`, `va_arg`, `va_copy`, and `va_end`.

Key points learned:

-   **Variadic Functions**: The core learning involved variadic functions that accept an indefinite number of arguments, teaching how to manage them effectively.
-   **Custom Library Creation**: The project led to the creation of a custom library `libftprintf.a`, incorporating the newly coded `ft_printf` function.
-   **Conversion Specifiers**: The function had to handle various conversion specifiers like `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`, which are used to format different types of data.
