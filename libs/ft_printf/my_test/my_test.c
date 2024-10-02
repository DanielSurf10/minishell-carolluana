/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:00:23 by cshingai          #+#    #+#             */
/*   Updated: 2024/01/11 17:12:01 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	// char x[] = "foi?";
	// int h = 255;
	int count_original, count_mine;

	// count_mine = ft_printf("%c%d%s\n", 'a', 15, x);
	// count_original = printf("%c%d%s\n", 'a', 15, x);
	// printf("original %i - minha - %i\n", count_original, count_mine);


	// count_mine = ft_printf("sem argumentos: %s\n", (char *) 0);
	// count_original = printf("sem argumentos: %s\n", (char *) 0);
	// printf("original %i - minha - %i\n", count_original, count_mine);


	// count_mine = ft_printf("hex: %X\n", h);
	// count_original = printf("hex: %X\n", h);
	// printf("original %i - minha - %i\n", count_original, count_mine);

	// count_mine = ft_printf("dec: %u\n", 48);
	// count_original = printf("dec: %u\n", 48);
	// printf("original %i - minha - %i\n", count_original, count_mine);

	// count_mine = ft_printf("perc: %%\n");
	// count_original = printf("perc: %%\n");
	// printf("original %i - minha - %i\n", count_original, count_mine);

	count_mine = ft_printf(0);
	count_original = printf(0);
	printf("original %i - minha - %i\n", count_original, count_mine);

	return 0;
}
