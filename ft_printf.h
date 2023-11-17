/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:43:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/17 15:00:14 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXBASE_MIN "0123456789abcdef"
# define HEXBASE_MAJ "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char const *s, int fd, int *cnt);
void	ft_putchar_fd(char c, int fd, int *cnt);
void	print_arg(char c, va_list args, int *cnt, long *j);
void	ft_putnbr_hex(long unsigned int nbr, char *base, int *cnt);
void	ft_putnbr(int nbr, int *cnt);
void	ft_putnbr_u(unsigned int nbr, int *cnt);
#endif