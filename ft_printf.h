/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:31:33 by alappas           #+#    #+#             */
/*   Updated: 2024/04/14 00:42:56 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf_s(char *s);
int		ft_printf_d(int n);
int		ft_printf_p(unsigned long long ptr);
int		ft_printf_x(unsigned long long v, int ascii);
int		ft_printf_undec(unsigned int n);
int		ft_printf(const char *s, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_len(uintptr_t v, int base);

#endif