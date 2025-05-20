/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:04:23 by psevilla          #+#    #+#             */
/*   Updated: 2025/05/20 18:30:18 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_table(t_table *table, char	**argv)
{
	table->philosophers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->meals = ft_atol(argv[5]);
	else
		table->meals = 0;
	return (0);
}

static	int	is_number(char *s)
{
	int	i;

	while(s[i++])
	{
		if (ft_isdigit(s[i]))
			return (1);
	}
	return(0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (i);
	while (i++ != argc)
	{
		if (!is_number(argv[i]))
			return (++i);
		printf("%s\n", argv[i]);
	}
	return (0);
}
