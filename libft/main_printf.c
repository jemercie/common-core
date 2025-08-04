/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:52:19 by jemercie          #+#    #+#             */
/*   Updated: 2022/11/08 11:59:57 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char *str;
	str = "j'écris ratata";

	ft_printf("ft_c : %c\n", 'a');
	printf("pf_c : %c", 'a');
	ft_printf("ft_str : %s\n", str);
	printf("pf_str : %s\n", str)
	ft_printf("ft_x : %x\n", 590);
	printf("pf_x : %x\n", 590);
	return (0);
}
