/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:04:17 by psevilla          #+#    #+#             */
/*   Updated: 2025/04/10 18:34:50 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_table(t_table *table)
{
	if (!table)
	{
		printf("Error: La tabla no es válida.\n");
		return ;
	}
	printf("Contenido de la estructura t_table:\n");
	printf("Número de filósofos: %ld\n", table->philosophers);
	printf("Tiempo para morir: %ld ms\n", table->time_to_die);
	printf("Tiempo para comer: %ld ms\n", table->time_to_eat);
	printf("Tiempo para dormir: %ld ms\n", table->time_to_sleep);
	printf("Número de comidas: %ld\n", table->meals);
}

void	exit_failure(int errno)
{
	if (errno == 1)
		ft_print_str("INTRODUCE CORRECT NUMBER OF ARGUMENTS");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
		exit_failure(1);
	if (init_table(&table, argv))
		return (1);
	print_table(&table);
	// start_dinner(&table);
	return (0);
}
