# Libft
My implementation of some of the Standard C Library functions including some additional ones.

### What is libft?
Libft is an individual project at 42 that requires us to re-create some standard C library functions including some additional ones that can be used later to build a library of useful functions for the rest of the program.

Disclaimer: *Reinventing the wheel is bad, 42 makes us do this just so we can have a deeper understanding of data structures and basic algorithms. At 42 we're not allowed to use some standard libraries on our projects, so we have to keep growing this library with our own functions as we go farther in the program.*

### What's in my libft?

CTYPE        | INPUT_OUTPUT     | LIST              | MEMORY            | STRING
:----------: | :--------------: | :---------------: | :---------------: | :----------------:
ft_isalnum.c | ft_printf.c      | ft_lstadd_back.c  | ft_bzero.c        | ft_atoi.c
ft_isalpha.c | ft_putchar.c     | ft_lstadd_front.c | ft_calloc.c       | ft_atol.c
ft_isascii.c | ft_putchar_fd.c  | ft_lstclear.c     | ft_matrix_free.c  | ft_itoa.c
ft_isdigit.c | ft_putendl_fd.c  | ft_lstdelone.c    | ft_matrix_free_h.c| ft_matrix_height.c
ft_isprint.c | ft_putnbr.c      | ft_lstiter.c      | ft_memchr.c       | ft_split.c
ft_tolower.c | ft_putnbr_fd.c   | ft_lstlast.c      | ft_memcmp.c       | ft_strchr.c
ft_toupper.c | ft_putstr.c      | ft_lstmap.c       | ft_memcpy.c       | ft_strdup.c
||             ft_putstr_fd.c   | ft_lstnew.c       | ft_memmove.c      | ft_striteri.c
||             get_next_line.c  | ft_lstsize.c      | ft_memset.c       | ft_strjoin.c
||||                                                                    | ft_strlcat.c
||||                                                                    | ft_strlcpy.c   
||||                                                                    | ft_strlen.c
||||                                                                    | ft_strmapi.c
||||                                                                    | ft_strncmp.c
||||                                                                    | ft_strnstr.c
||||                                                                    | ft_strrchr.c
||||                                                                    | ft_strrstr.c
||||                                                                    | ft_strstr.c
||||                                                                    | ft_strtrim.c
||||                                                                    | ft_substr.c
||||                                                                    | ft_strcharjoin.c

Notes:
- Most of the the files and function names are namespaced with an **ft** in front. It stands for Fourty Two
- I update this list almost every month with new personal functions.
- If you don't know what a function does, refer to the header files in /inc directory.

### How does it work?

The goal is to create a library called libft.a from the source files so I can later use that library from other projects at 42.

To create that library you need to run these commands in your terminal:

	git clone https://github.com/mahdemir/libft
	cd libft
	make

You should see a *libft.a* file and some object files (.o) in a hidden *.build/* directory.

Now to clean up (removing the .o files), call `make clean`

### How do I use the library?

First you need to copy your code in to the root of the *libft* folder.

You have to tell the compiler where your library resides and which library it is using:

`cc prog_name.c -L - -lft`

-L takes the path to your library. `.` (current directory) in this case<br>
-l takes the name of your library. This is the set of characters that come after `lib` in your library name.

Now just run your executable and enjoy!

That's it! If you're having some problems, just send me a tweet. If you think your problem is due to my code or this README, create a new issue. I'll definitely check it out.

## 🌳 Folder structure
```
.
├── Makefile
├── README.md
├── inc
│   ├── ft_printf.h
│   ├── get_next_line.h
│   └── libft.h
└── src
    ├── ctype
    │   ├── ft_isalnum.c
    │   ├── ft_isalpha.c
    │   ├── ft_isascii.c
    │   ├── ft_isdigit.c
    │   ├── ft_isprint.c
    │   ├── ft_tolower.c
    │   └── ft_toupper.c
    ├── input_output
    │   ├── ft_printf
    │   │   ├── ft_printf.c
    │   │   └── ft_printf_utils.c
    │   ├── ft_putchar.c
    │   ├── ft_putchar_fd.c
    │   ├── ft_putendl_fd.c
    │   ├── ft_putnbr.c
    │   ├── ft_putnbr_fd.c
    │   ├── ft_putstr.c
    │   ├── ft_putstr_fd.c
    │   └── get_next_line
    │       ├── get_next_line.c
    │       └── get_next_line_utils.c
    ├── list
    │   ├── ft_lstadd_back.c
    │   ├── ft_lstadd_front.c
    │   ├── ft_lstclear.c
    │   ├── ft_lstdelone.c
    │   ├── ft_lstiter.c
    │   ├── ft_lstlast.c
    │   ├── ft_lstmap.c
    │   ├── ft_lstnew.c
    │   └── ft_lstsize.c
    ├── memory
    │   ├── ft_bzero.c
    │   ├── ft_calloc.c
    │   ├── ft_matrix_free.c
    │   ├── ft_matrix_free_h.c
    │   ├── ft_memchr.c
    │   ├── ft_memcmp.c
    │   ├── ft_memcpy.c
    │   ├── ft_memmove.c
    │   └── ft_memset.c
    └── string
        ├── ft_atoi.c
        ├── ft_atol.c
        ├── ft_itoa.c
        ├── ft_matrix_height.c
        ├── ft_split.c
        ├── ft_strcharjoin.c
        ├── ft_strchr.c
        ├── ft_strdup.c
        ├── ft_striteri.c
        ├── ft_strjoin.c
        ├── ft_strlcat.c
        ├── ft_strlcpy.c
        ├── ft_strlen.c
        ├── ft_strmapi.c
        ├── ft_strncmp.c
        ├── ft_strnstr.c
        ├── ft_strrchr.c
        ├── ft_strrstr.c
        ├── ft_strstr.c
        ├── ft_strtrim.c
        └── ft_substr.c
```
