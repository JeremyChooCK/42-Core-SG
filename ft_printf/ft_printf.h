/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:52:19 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/16 16:52:24 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_uitoa(int n);
int		ft_itoa(int n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_printhex(unsigned int n, char c);
int		ft_printhexp(unsigned long n);
int		ft_printaddress(unsigned long n);
int		ft_printf(const char *str, ...);

#endif
