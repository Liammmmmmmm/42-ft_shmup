/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:01:53 by lilefebv          #+#    #+#             */
/*   Updated: 2024/11/23 14:43:41 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
#include <unistd.h>

/**
 * @brief zero a byte string
 * 
 * The ft_bzero() function erases the data in the n bytes of the memory starting 
 * at the location pointed to by s, by writing zeros (byte containing '\0') 
 * to that area.
 * 
 * @param pointer Pointer to the memory area to be cleared.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *pointer, size_t n);

/**
 * @brief Scans the first n bytes of memory for the first occurrence of c.
 *
 * The ft_memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c. Both c and the bytes of
 * the memory area pointed to by s are interpreted as unsigned char.
 *
 * @param s Pointer to the memory area to be scanned.
 * @param c Character to search for in the memory area.
 * @param n Number of bytes to search.
 * 
 * @return A pointer to the matching byte, or NULL if the character is
 *         not found within the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of two memory areas.
 *
 * The ft_memcmp() function compares the first n bytes (each interpreted
 * as unsigned char) of the memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * 
 * @return An integer less than, equal to, or greater than zero if the first
 *         n bytes of s1 are found to be respectively less than, equal to, or
 *         greater than the first n bytes of s2. For a nonzero return value,
 *         the sign is determined by the sign of the difference between the
 *         first pair of bytes (interpreted as unsigned char). If n is zero,
 *         the return value is zero.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The ft_memcpy() function copies n bytes from memory area src to
 * memory area dest. The memory areas must not overlap. Use ft_memmove()
 * if the memory areas do overlap.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The ft_memmove() function copies n bytes from memory area src to
 * memory area dest. The memory areas may overlap: copying takes place
 * as though the bytes in src are first copied into a temporary array
 * that does not overlap src or dest, and the bytes are then copied from
 * the temporary array to dest.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills memory with a constant byte.
 *
 * The ft_memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param pointer Pointer to the memory area to be filled.
 * @param val The constant byte to fill the memory with.
 * @param n Number of bytes to fill.
 * 
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *pointer, int val, size_t n);

/**
 * @brief Allocates memory for an array of elements and initializes it to zero.
 *
 * The ft_calloc() function allocates unused space for an array of number
 * elements, each of whose size in bytes is size. The space is initialized
 * to all bits 0.
 *
 * @param number The number of elements to allocate.
 * @param size The size of each element.
 * 
 * @return A pointer to the allocated space, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t number, size_t size);

/**
 * @brief Tests whether a character is alphanumeric.
 *
 * The ft_isalnum() function tests whether the character c is an alphanumeric
 * character, meaning it is either a letter (alphabetic character) or a digit.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is an alphanumeric character; 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Tests whether a character is alphabetic.
 *
 * The ft_isalpha() function checks whether the character c is an alphabetic
 * character, which includes both uppercase and lowercase letters.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is an alphabetic character; 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Tests whether a character is a valid ASCII character.
 *
 * The ft_isascii() function checks whether the character c is a 7-bit unsigned
 * char value that fits into the ASCII character set.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a valid ASCII character; 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Tests whether a character is a digit.
 *
 * The ft_isdigit() function checks whether the character c is a digit
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a digit; 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Tests whether a character is printable.
 *
 * The ft_isprint() function checks whether the character c is any printable
 * character, including space.
 *
 * @param c The character to test, represented as an int. The value should be
 *          representable as an unsigned char. Any other value results in
 *          undefined behavior.
 * 
 * @return A non-zero value if c is a printable character; 0 otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Calculates the length of a string.
 *
 * The ft_strlen() function calculates the length of the string pointed to by
 * s, excluding the terminating null byte ('\0').
 *
 * @param str A pointer to the string whose length is to be calculated.
 * 
 * @return The number of bytes in the string pointed to by str.
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Applies a function to each character of a string with its index.
 *
 * The ft_striteri() function iterates over the string pointed to by s,
 * applying the function f to each character of the string. The index of
 * each character is passed as the first argument to the function f,
 * and the character is passed by reference (as a pointer) so it can be
 * modified if needed.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character, which takes the index 
 *          and the character (as a pointer) as arguments.
 * 
 * @return None. The function modifies the string in-place if needed.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Applies a function to each character of a string and creates a new
 *        string.
 *
 * The ft_strmapi() function applies the function f to each character of the
 * string s, passing the index of each character as the first argument and the
 * character itself as the second argument. A new string is created using
 * malloc(), where each character is the result of applying f to the
 * corresponding character in s.
 *
 * If the memory allocation fails, the function returns NULL.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character, which takes the index 
 *          and the character as arguments, and returns the modified character.
 * 
 * @return A new string with the modified characters, or NULL if memory
 *         allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Appends a string to a destination buffer with size limitation.
 *
 * The ft_strlcat() function appends the null-terminated string src to the
 * end of the null-terminated string dest. It appends at most size - 
 * ft_strlen(dest) - 1 characters, ensuring the result is null-terminated.
 * The total length of the string it tried to create (initial length of dest
 * plus length of src) is returned.
 *
 * @param dest The destination buffer to append the string to.
 * @param src The source string to append.
 * @param size The size of the destination buffer, including space for the 
 *             null terminator.
 * 
 * @return The total length of the string it tried to create (initial length
 *         of dest plus length of src).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Copies a string to a destination buffer with size limitation.
 *
 * The ft_strlcpy() function copies up to size - 1 characters from the
 * string src to dst, ensuring the result is null-terminated.
 * The total length of the string it tried to create (the length of src) is
 * returned.
 *
 * @param dest The destination buffer to copy the string to.
 * @param src The source null-terminated string to copy.
 * @param size The size of the destination buffer, including space for the
 *             null terminator.
 * 
 * @return The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Duplicates a string by allocating memory for a copy.
 *
 * The ft_strdup() function allocates memory for a new string that is a
 * duplicate of the string s. The new string is null-terminated. Memory is
 * allocated using malloc(), and it can be freed using free().
 *
 * @param str The string to duplicate.
 * 
 * @return A pointer to the newly allocated duplicate string, or NULL if memory
 *         allocation fails.
 */
char	*ft_strdup(const char *str);

/**
 * @brief Concatenates two strings into a new allocated string.
 *
 * The ft_strjoin() function concatenates the string s1 with the string s2,
 * and returns a new string that contains the result. The memory for the new 
 * string is allocated using malloc(), and it must be freed by the caller when
 * no longer needed.
 * 
 * If there is insufficient memory available for allocation, the function will
 * return NULL.
 *
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * 
 * @return A new string containing the concatenation of s1 and s2, or NULL if
 *         memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Splits a string into an array of substrings using a delimiter.
 *
 * The ft_split() function splits the string s into an array of substrings,
 * separated by the delimiter character c. The resulting array of substrings
 * is terminated by a NULL pointer.
 * 
 * The memory for the resulting array and substrings is allocated using 
 * malloc().
 * If memory allocation fails, the function will return NULL.
 *
 * @param s The string to split.
 * @param c The delimiter character used to split the string.
 * 
 * @return A array of strings resulting from the split, or NULL if memory
 *         allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Trims characters from the beginning and end of a string.
 *
 * The ft_strtrim() function allocates memory and returns a new string which is
 * a copy of the string s1, with all characters from the set 'set' removed from
 * the beginning and end of the string. The characters in 'set' are not removed
 * from the middle of the string.
 *
 * The memory for the new string is allocated using malloc(). If memory
 * allocation fails, the function returns NULL.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove from the beginning and end of s1.
 * 
 * @return A new string with the specified characters removed from the
 *         beginning and end of s1, or NULL if memory allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Creates a substring from the given string, starting at a specified
 *        index.
 *
 * This function allocates (using malloc) and returns a new string derived
 * from the string 's'. The new string starts from the index 'start' and has
 * a maximum length of 'len'. If the starting index is greater than the length
 * of the string, an empty string is returned.
 * If memory allocation fails, NULL is returned.
 *
 * @param s The string from which the new substring is created.
 * @param start The starting index in the original string.
 * @param len The maximum length of the new substring.
 *
 * @return A new string starting at 'start' with a length of up to 'len',
 *         or NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Converts an integer to a string.
 *
 * Allocates memory (using malloc) and returns a string representing the
 * integer 'n'. Negative numbers are handled correctly.
 *
 * @param n The integer to convert.
 *
 * @return A string representing the integer, or NULL if allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Locate the first occurrence of a character in a string.
 *
 * The ft_strchr() function returns a pointer to the first occurrence of
 * the character 'c' in the string 's'.
 *
 * @param s The string to search in.
 * @param c The character to locate (represented as an integer).
 *
 * @return A pointer to the first occurrence of 'c' in 's', or NULL if
 * the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locate the last occurrence of a character in a string.
 *
 * The ft_strrchr() function returns a pointer to the last occurrence of
 * the character 'c' in the string 's'.
 *
 * @param s The string to search in.
 * @param c The character to locate (represented as an integer).
 *
 * @return A pointer to the last occurrence of 'c' in 's', or NULL if the
 *         character is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compare two strings up to a specified number of characters.
 *
 * The ft_strncmp() function compares at most 'n' bytes of the strings 's1' 
 * and 's2', stopping at the null terminator if encountered before reaching 'n'
 * bytes. The comparison is done using unsigned char values.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of bytes to compare.
 *
 * @return An integer less than, equal to, or greater than 0, indicating
 *         whether 's1' is less than, equal to, or greater than 's2'. 
 *         If the strings are equal up to 'n' characters, 0 is returned.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locate the first occurrence of a substring within a string, 
 *        searching up to a specified length.
 *
 * The ft_strnstr() function finds the first occurrence of the string 'little' 
 * within the string 'big', but only searches up to 'len' characters. 
 * Characters that appear after	a `\0' character are not  searched. 
 *
 * @param big The string in which to search.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search.
 *
 * @return A pointer to the first character of the first occurrence of 'little' 
 *         within 'big'. If 'little' is an empty string, 'big' is returned. 
 *         If 'little' is not found, NULL is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Convert a given character to its lowercase equivalent.
 *
 * The ft_tolower() function takes an integer 'c' and returns the 
 * corresponding lowercase character if 'c' is an uppercase letter. 
 * Otherwise, it returns the character unchanged.
 *
 * @param c The character to convert.
 * 
 * @return The lowercase equivalent of 'c' if 'c' is an uppercase letter,
 *         otherwise, returns 'c' unchanged.
 */
int		ft_tolower(int c);

/**
 * @brief Convert a given character to its uppercase equivalent.
 *
 * The ft_toupper() function takes an integer 'c' and returns the 
 * corresponding uppercase character if 'c' is a lowercase letter. 
 * Otherwise, it returns the character unchanged.
 *
 * @param c The character to convert.
 * 
 * @return The uppercase equivalent of 'c' if 'c' is a lowercase letter,
 *         otherwise, returns 'c' unchanged.
 */
int		ft_toupper(int c);

/**
 * @brief Convert a string to an integer.
 *
 * The ft_atoi() function converts the initial portion of the string 
 * pointed to by 'str' to an integer. The function skips any leading 
 * whitespace characters and processes any digits until a non-digit 
 * character is encountered.
 *
 * @param str The string to convert.
 * 
 * @return The converted integer value or 0 if no valid conversion is
 *         possible.
 */
int		ft_atoi(const char *str);

/**
 * @brief Write a character to a file descriptor.
 *
 * The ft_putchar_fd() function writes the character 'c' to the file 
 * descriptor 'fd'. It uses write() to output the character.
 *
 * @param c The character to write.
 * @param fd The file descriptor where the character will be written.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string followed by a newline to a file descriptor.
 *
 * The ft_putendl_fd() function writes the string 's' followed by a newline
 * character to the file descriptor 'fd'. It uses write().
 *
 * @param s The string to write.
 * @param fd The file descriptor where the string will be written.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Write an integer to a file descriptor.
 *
 * The ft_putnbr_fd() function writes the integer 'n' to the file 
 * descriptor 'fd'. It uses write() to output the integer as a string
 * representation.
 *
 * @param n The integer to write.
 * @param fd The file descriptor where the integer will be written.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Write a string to a file descriptor.
 *
 * The ft_putstr_fd() function writes the string 's' to the file 
 * descriptor 'fd'. It outputs the string using write().
 *
 * @param s The string to write.
 * @param fd The file descriptor where the string will be written.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Structure representing an element of a linked list.
 *
 * The `t_list` structure is used to represent an element in a generic 
 * linked list. Each element contains a pointer to data of type `void*` 
 * and a pointer to the next element in the list.
 *
 * @param content A pointer to the content of the list element. The type
 *                of the content is generic (`void*`), allowing storage 
 *                of any type of data.
 * @param next A pointer to the next element in the list. If the current 
 *             element is the last one, this pointer is `NULL`.
 */
typedef struct s_list
{
	void			*content;	/** List content. */
	struct s_list	*next;		/** Pointer to the next element. */
}					t_list;

/**
 * @brief Creates a new list element.
 * 
 * This function allocates memory for a new list element, sets the `content`
 * member to the provided value, and initializes the `next` pointer to NULL.
 * 
 * @param content The content to initialize the new list element with.
 * 
 * @return A pointer to the newly created list element. NULL if memory
 *         allocation fails.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds a new element to the front of the list.
 * 
 * This function adds the element `new` to the front of the list.
 * 
 * @param lst A pointer to the pointer to the first element in the list.
 * @param new A pointer to the new element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in the list.
 * 
 * This function traverses the list and counts the number of elements until
 * it reaches the end.
 * 
 * @param lst The start of the list.
 * 
 * @return The number of elements in the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element in the list.
 * 
 * This function traverses the list until it reaches the last element.
 * 
 * @param lst Element of the list.
 * 
 * @return The last element in the list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new element to the end of the list.
 * 
 * This function adds the element `new` to the end of the list.
 * 
 * @param lst A pointer to the pointer to the first element in the list.
 * @param new A pointer to the new element to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees a single list element.
 * 
 * Frees the memory of the element passed as an argument using the 'del'
 * function then with free(3). There memory of `next` must not be free.
 * 
 * @param frist A pointer to the first element in the list.
 * @param lst The element to free.
 * @param del A function pointer that deletes the content of the element.
 */
void	ft_lstdelone(t_list **first, t_list *lst, void (*del)(void*));

/**
 * @brief Clears the entire list by freeing all elements.
 *
 * Deletes and frees the memory of the element passed in parameter, and all
 * the elements that follow, to using `del` and free(3). Finally, the initial
 * pointer must be set to NULL
 * 
 * @param lst A pointer to the pointer to the first element in the list.
 * @param del A function pointer that deletes the content of each element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates over the list and applies a function to each element's
 *        content.
 *
 * This function iterates through the entire list and applies the function
 * `f` to the content of each element in the list.
 * 
 * @param lst A pointer to the first element in the list.
 * @param f A function pointer to the function to apply to each element's
 *          content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates over the list and creates a new list by applying
 *        a function to each element's content.
 * 
 * This function creates a new list by applying the function `f` to the
 * content of each element in the original list. The `del` function is used
 * with free if necessary during the creation of the new list.
 * 
 * @param lst A pointer to the first element in the list.
 * @param f A function pointer to the function to apply to each element's
 *          content.
 * @param del A function pointer to the function used to delete the content
 *            of an element if needed.
 * 
 * @return A pointer to the new list created by applying `f` to each
 *         element's content, or NULL if memory allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Get the previous element in a chained list
 * 
 * This function return the previous element of the list. It only work if
 * every content of each element of the list is **UNIQUE**.
 * 
 * @param first A pointer to the first element in the list.
 * @param actual The element after the one you want
 * 
 * @return The previous element of the list, or NULL if you give the first
 *         element of the liste or an invalid one
 */
t_list	*ft_lstgetprev(t_list *first, t_list *actual);

#endif
