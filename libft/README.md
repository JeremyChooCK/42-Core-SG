# Libft - Your Custom C Library

Libft is a fundamental project in the 42 curriculum, where you create your own C library consisting of various standard functions, as well as some additional ones. This library is a valuable resource that you can use in future projects at 42 and beyond.

## Project Structure

### .c Files\
All your functions will be implemented in separate `.c` files.

### .h (Header)\
Your header file (`libft.h`) serves two main purposes:\
1\. **Include Standard Headers:** Instead of including standard libraries like `<unistd.h>` in all your `.c` files, include them once in your header. All your `.c` files will read these includes from your header file.\
2\. **Function Prototypes:** Declare function prototypes in the header file. This allows you to use functions from one `.c` file in another by including `"libft.h"`.

### Makefile\
The `Makefile` is your build automation tool. Instead of manually compiling each file, you define compilation rules in the `Makefile`. Using the `make` command, you can easily compile your entire project.

## Key Functions

### Functions from `<ctype.h>`\
- `ft_isalpha`: Check for alphabetic characters.\
- `ft_isdigit`: Check for digits (0-9).\
- `ft_isalnum`: Check for alphanumeric characters.\
- `ft_isascii`: Check if a character fits into the ASCII character set.\
- `ft_isprint`: Check for printable characters.\
- `ft_toupper`: Convert a character to uppercase.\
- `ft_tolower`: Convert a character to lowercase.

### Functions from `<string.h>`\
- `ft_memset`: Fill memory with a constant byte.\
- `ft_strlen`: Calculate the length of a string.\
- `ft_bzero`: Zero a byte string.\
- `ft_memcpy`: Copy memory area.\
- `ft_memmove`: Copy memory area, handling overlapping regions.\
- `ft_strlcpy`: Copy a string to a specific size.\
- `ft_strlcat`: Concatenate strings to a specific size.\
- `ft_strchr`: Locate a character in a string.\
- `ft_strrchr`: Locate a character in a string from the end.\
- `ft_strncmp`: Compare two strings up to a specific size.\
- `ft_memchr`: Scan memory for a character.\
- `ft_memcmp`: Compare memory areas.\
- `ft_strnstr`: Locate a substring in a string up to a specific size.\
- `ft_strdup`: Duplicate a string.

### Functions from `<stdlib.h>`\
- `ft_atoi`: Convert a string to an integer.\
- `ft_calloc`: Allocate memory and initialize it with zeros.

### Additional Functions\
- `ft_substr`: Extract a substring from a string.\
- `ft_strjoin`: Concatenate two strings.\
- `ft_strtrim`: Trim specified characters from the beginning and end of a string.\
- `ft_split`: Split a string into an array of substrings using a specified delimiter.\
- `ft_itoa`: Convert an integer to a string.\
- `ft_strmapi`: Apply a function to each character of a string.\
- `ft_striteri`: Apply a function to each character of a string with its index.\
- `ft_putchar_fd`: Output a character to a file descriptor.\
- `ft_putstr_fd`: Output a string to a file descriptor.\
- `ft_putendl_fd`: Output a string to a file descriptor followed by a new line.\
- `ft_putnbr_fd`: Output a number to a file descriptor.

### Linked List Functions\
- `ft_lstnew`: Create a new list element.\
- `ft_lstadd_front`: Add an element at the beginning of a list.\
- `ft_lstsize`: Count the number of elements in a list.\
- `ft_lstlast`: Return the last element of a list.\
- `ft_lstadd_back`: Add an element at the end of a list.\
- `ft_lstclear`: Delete and free a list.\
- `ft_lstiter`: Apply a function to each element of a list.\
- `ft_lstmap`: Apply a function to each element of a list, creating a new list.

## How to Use the Library

1\. **Clone the Repository:**\
   ```git clone <repository-url>``` \
   ```cd libft```

2\. **Compile the Library:**\
   ```make``` \
   This command compiles all your `.c` files and creates the `libft.a` static library file.

3\. **Link with Your Project:**\
   When compiling your projects, include the `libft.a` library file and the header file in your compilation command:\
   ```gcc -o my_project my_project.c -L. -lft -I.```

4\. **Run Your Executable:**\
   ```./my_project```

## Testing Your Library

You can use the [Libft Tester](https://github.com/pasqualerossi/42-Cursus-Tester) to validate your functions. This tool automates the testing process and helps ensure the correctness of your implementations.
