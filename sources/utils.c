/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:04:26 by psevilla          #+#    #+#             */
/*   Updated: 2025/05/21 19:02:56 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return(0);
}
