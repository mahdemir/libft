/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:05:53 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 18:05:16 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/********** LIBRARIES *********************************************************/

# include <unistd.h> // write()
# include <stdlib.h> // malloc(), free()
# include <stdarg.h> // va_list(), va_start(), va_arg(), va_end()
# include "ft_printf.h" // ft_printf()
# include "get_next_line.h" // get_next_line()

/********** STRUCTS ***********************************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/********** CTYPE *************************************************************/

// Checks if the character is alphanumeric.
int		ft_isalnum(int c);

// Checks if the character is alphabetic.
int		ft_isalpha(int c);

// Checks if the character is ASCII.
int		ft_isascii(int c);

// Checks if the character is decimal digit.
int		ft_isdigit(int c);

// Checks if the character is printable.
int		ft_isprint(int c);

// Converts uppercase letters to lowercase.
int		ft_tolower(int c);

// Converts lowercase letters to uppercase.
int		ft_toupper(int c);

/********** LIST **************************************************************/

// Push content at the end of a singly linked list.
void	ft_lstadd_back(t_list **lst, t_list *new);

// Push content at the beginning of a singly linked list.
void	ft_lstadd_front(t_list **lst, t_list *new);

// Free a singly linked list.
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Takes as a parameter a node and frees the memory of the node’s content
** using the function ’del’ given as a parameter and free the node.
** The memory of ’next’ is not freed. */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// Iterates the list ’lst’ and applies the function ’f’ on the content.
void	ft_lstiter(t_list *lst, void (*f)(void *));

// Returns the last element if it exists.
t_list	*ft_lstlast(t_list *lst);

/* Iterates the list ’lst’ and applies the function ’f’ on the content of
** each node.  Creates a new list resulting of the successive applications
** of the function ’f’.  The ’del’ function is used to delete the
** content of a node if needed. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Creates a new element with malloc. Returns NULL on error.
t_list	*ft_lstnew(void *content);

// Returns the size of a singly linked list.
int		ft_lstsize(t_list *lst);

/********** MEMORY ************************************************************/

// Writes n zeroed bytes to s.
void	ft_bzero(void *s, size_t n);

/* Allocates enough space for count objects that are size bytes of memory each
** and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero.
** Returns NULL on error. */
void	*ft_calloc(size_t count, size_t size);

// Free complete matrix
void	ft_free_matrix(void **arr, int len);

// Locates the first occurrence of c in s.
void	*ft_memchr(const void *s, int c, size_t n);

// Compares n bytes (each interpreted as unsigned char) of s1 and s2.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Copies n bytes from src to dst.
void	*ft_memcpy(void *dst, const void *src, size_t n);

// Copies len bytes from src to dst without overlapping.
void	*ft_memmove(void *dst, const void *src, size_t len);

// Writes len bytes of value c to b.
void	*ft_memset(void *b, int c, size_t len);

/********** STDIO *************************************************************/

// Outputs a character to standard output.
void	ft_putchar(char c);

// Outputs a string to given file descriptor.
void	ft_putchar_fd(char c, int fd);

// Outputs a string with a newline to given file descriptor.
void	ft_putendl_fd(char *s, int fd);

// Outputs an integer to standard output.
void	ft_putnbr_fd(int n, int fd);

// Outputs an integer to given file descriptor.
void	ft_putnbr_fd(int n, int fd);

// Outputs a string to standard output.
void	ft_putstr(char *s);

// Outputs a string to given file descriptor.
void	ft_putstr_fd(char *s, int fd);

/********** STRING ************************************************************/

// Converts the string str to integer representation.
int		ft_atoi(const char *str);

// Converts an int to a string, and returns a pointer to it.
char	*ft_itoa(int n);

/* Allocates and returns an array of strings obtained by splitting s
** using all characters from set as delimiters.
** If the given set is empty, all spaces are delimiters by default.
** The array is ended by a NULL pointer.
** Returns NULL on error. */
char	**ft_split(char const *s, char c);

/* Locates the first occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is '\0', the functions locate
** the terminating '\0'. */
char	*ft_strchr(const char *s, int c);

/* Locates the last occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is '\0', the functions locate
** the terminating '\0'. */
char	*ft_strrchr(const char *s, int c);

/* Allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.
** Returns NULL on error. */
char	*ft_strdup(const char *s1);

/* Applies the function ’f’ on each character of the string
** passed as argument, passing its index as first argument. Each
** character is passed by address to ’f’ to be modified if necessary. */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* Allocates and returns a new string,
** result of the concatenation of s1 and s2.
** The passed arguments can be NULL.
** Returns NULL on error. */
char	*ft_strjoin(char const *s1, char const *s2);

/* Appends string src to the end of dst.
** It will append at most dstsize - strlen(dst) - 1 characters. */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// Returns the length of the string s.
size_t	ft_strlen(const char *s);

/* Applies the function f to each character of the string s
** to create a new string resulting from successive applications of f. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Compares not more than n characters.
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Locates the first occurrence of the null-terminated string little
** in the string big */
char	*ft_strstr(const char *big, const char *little);

/* Locates the first occurrence of the null-terminated string little
** in the string big, where not more than len characters are searched. */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* Locates the last occurrence of the null-terminated string little
** in the string big */
char	*ft_strrstr(const char *big, const char *little);

/* Allocates and returns a copy of the string s1, without the characters
** specified in the set at the beginning and the end of the string.
** If the given set is empty, all spaces are delimiters by default. */
char	*ft_strtrim(char const *s1, char const *set);

/* Allocates and returns a substring from the string s.
** The substring begins at index start and is of maximum size len.
** Returns NULL on error. */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
