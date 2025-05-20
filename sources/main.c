/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:04:17 by psevilla          #+#    #+#             */
/*   Updated: 2025/05/20 18:27:14 by psevilla         ###   ########.fr       */
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
		ft_print_str("Wrong number of arguments\n");
	if (errno == 2)
		ft_print_str("First argument is not a number\n");	// Nº de filósofos
	if (errno == 3)
		ft_print_str("Second argument is not a number\n");	// Tiempo pa morir
	if (errno == 4)
		ft_print_str("Third argument is not a number\n");	// Tiempo pa comer
	if (errno == 5)
		ft_print_str("Forth argument is not a number\n");	// Tiempo pa dormir
	if (errno == 6)
		ft_print_str("Fifth argument is not a number\n");	// Veces pa comer
	exit(1);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		input_error;

	input_error = check_args(argc, argv);
	if (input_error)
		exit_failure(input_error);
	init_table(&table, argv);
	print_table(&table);
	// start_dinner(&table);
	return (0);
}
