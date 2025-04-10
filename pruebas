#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef pthread_mutex_t mutex_t;

mutex_t		mutex;
int			i = 0;

void *increment(void *arg)
{
	pthread_mutex_lock(&mutex);
	i++;
	printf("Thread %ld: i = %d\n", (long)arg, i);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	int			error;

	error = pthread_mutex_init(&mutex, NULL);
	if (error)
		exit (EXIT_FAILURE);
	error = pthread_create(&tid1, NULL, increment, (void *)1);
	if (error)
		exit (EXIT_FAILURE);
	error = pthread_create(&tid2, NULL, increment, (void *)2);
	if (error)
		exit (EXIT_FAILURE);
	error = pthread_join(tid1, NULL);
	if (error)
		exit (EXIT_FAILURE);
	error = pthread_join(tid2, NULL);
	if (error)
		exit (EXIT_FAILURE);
	error = pthread_mutex_destroy(&mutex);
	if (error)
		exit (EXIT_FAILURE);
	return (0);
}
