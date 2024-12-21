/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:23:52 by cshingai          #+#    #+#             */
/*   Updated: 2024/12/20 21:41:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int		ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);
int		print_format(const char *str, va_list args, int idx);
int		ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_putnbr_hex(unsigned long nbr, int type);
int		ft_putnbr_dec(unsigned int n);
int		ft_put_pointer(unsigned long nbr, int type);
int		print_format_hash(unsigned long nbr, char type);

#endif
