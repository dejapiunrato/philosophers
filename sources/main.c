/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:04:17 by psevilla          #+#    #+#             */
/*   Updated: 2025/05/21 19:14:50 by psevilla         ###   ########.fr       */
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

int	exit_failure(int errno)
{
	if (errno == 1)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	if (errno == 2)
		ft_putstr_fd("Invalid philosophers number\n", 2);
	if (errno == 3)
		ft_putstr_fd("Invalid time to die\n",2);
	if (errno == 4)
		ft_putstr_fd("Invalid time to eat\n",2 );
	if (errno == 5)
		ft_putstr_fd("Invalid time to sleep\n",2);
	if (errno == 6)
		ft_putstr_fd("Invalid number of times each philosopher must eat\n",2);
	if (errno == 7)
		ft_putstr_fd("Maximum number of philosophers exceeded\n", 2);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (i);
	if (ft_atol(argv[1]) > PHILO_MAX)
		return (7);
	while (i != argc)
	{
		if (is_number(argv[i]) || ft_atol(argv[i]) <= 0)
			return (++i);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	table.input_error = check_args(argc, argv);
	if (table.input_error)
		return (exit_failure(table.input_error));
	init_table(&table, argv);
	print_table(&table);
	// start_dinner(&table);
	return (0);
}
