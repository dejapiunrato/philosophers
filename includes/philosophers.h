#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <unistd.h>   // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>  // pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
#include <limits.h>
# include "libft.h"

# define PHILO_MAX 200

typedef	struct s_table
{
	long	philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals;
	int		input_error;
	// Añadir movidas
}	t_table;

typedef	struct s_philo
{
	pthread_t	thread;
	int			id;
	int			eating;
	int			meals_eaten;
	// Añadir movidas
}	t_philo;

// initialization
int	init_table(t_table *table, char	**argv);
int	check_args(int argc, char **argv);

// utils
int	is_number(char *s);

#endif
