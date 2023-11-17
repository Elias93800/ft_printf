/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:44:37 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/17 15:04:29 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(long unsigned int nbr, char *base, int *cnt)
{
	if ((long)nbr == LONG_MIN)
	{
		ft_putstr_fd("8000000000000000", 1, cnt);
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', 1, cnt);
	}
	if (nbr >= ft_strlen(base))
		ft_putnbr_hex(nbr / ft_strlen(base), base, cnt);
	ft_putchar_fd(base[nbr % ft_strlen(base)], 1, cnt);
}

void	ft_putnbr(int nbr, int *cnt)
{
	if (nbr == INT_MIN)
		return (ft_putstr_fd("-2147483648", 1, cnt));
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', 1, cnt);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, cnt);
	ft_putchar_fd((nbr % 10) + 48, 1, cnt);
}

void	print_arg(char c, va_list args, int *cnt, long *j)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1, cnt);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1, cnt);
	else if (c == 'p')
	{
		*j = va_arg(args, size_t);
		if (*j == 0)
			ft_putstr_fd("(nil)", 1, cnt);
		else
			return (ft_putstr_fd("0x", 1, cnt), ft_putnbr_hex(*j, HEXBASE_MIN,
					cnt));
	}
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), cnt);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), cnt);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), cnt);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), HEXBASE_MIN, cnt);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), HEXBASE_MAJ, cnt);
	else if (c == '%')
		ft_putchar_fd('%', 1, cnt);
}

void	ft_putnbr_u(unsigned int nbr, int *cnt)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10, cnt);
	ft_putchar_fd((nbr % 10) + 48, 1, cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cnt;
	long	j;

	va_start(args, str);
	i = 0;
	j = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_arg(str[++i], args, &cnt, &j);
		else
			ft_putchar_fd(str[i], 1, &cnt);
		i++;
	}
	return (cnt);
}

// int	main(void)
// {
// 	ft_printf(" %x ", LONG_MAX);
// 	printf(" %x ", LONG_MAX);
// 	return (0);
// }