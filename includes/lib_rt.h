
#ifndef LIB_RT_H
# define LIB_RT_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>


// array
char	**ft_alloc_2d_tab(int x, int y);
void	ft_free_2d_tab(char **tab);

// conversion
int				ft_atoi(const char *nptr);
float			ft_atof(char *str);
int				ft_atol(const char *nptr);
int				ft_atoll(const char *nptr);
unsigned int	ft_atoui(const char *nptr);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_lltoa(long long n);
char			*ft_lutoa_base(unsigned long long n, char *base);

// get_next_line
char			*get_next_line(int fd);

// mem
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);

// print
int				ft_print_address_fd(int fd, intptr_t address);
int				ft_print_char_fd(int fd, int n);
int				ft_printfd(int fd, const char *s, ...);
int				ft_print_hexa_fd(int fd, unsigned long long n, int is_upper);
int				ft_print_integer_fd(int fd, int n);
int				ft_print_str_fd(int fd, const char *s);
int				ft_print_unsigned_fd(int fd, unsigned int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);

// string
int ft_isalnum(char chr);
int	ft_strisalnum(char *string);
int	ft_isalpha(char caract);
int ft_isstralpha(char *str);
int	ft_isdigit(char caract);
int	ft_strisdigit(char *str);
char	**ft_split(char *str, char *sep);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char *s1, char *s2, int mode);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t size);
char	*ft_strcat(char *dest, char *src);
int	ft_isascii(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
