### `usleep()`
Suspende la ejcución del programa duratne un número especificado de microsegundos. Si todo sale bien devuelve 0 y sino -1 estableciendo `errno` con el número de error correspondiente.

```C
int	usleep(useconds_t usec);
```
- `usec` Número de miccrosegundos para suspender la ejecución.

### `gettimeofday()`
Obtiene la hora actual. Sevuelv 0 si funciona y -1 si no.


```C
int	gettimeofday(timeval *tv, timezone *tz);
```
- `tv` Estructura que almacena el tiempo actual en segundos y microsegundos.
	```C
	struct timeval
	{
		long	tv_sec;
		long	tv_usec;
	}
	```
- `tz` Estructura que almacena los minutos al oeste del meridiano de Greenwich y el tipo de ajuste horario.
	```C
	int	tz_minuteswest;
	int	tz_dsttime;
	```

---

# Funciones de `pthread.h`

POSIX (_Portable Operative System Interface_) es un estandar para garantizar la compatibilidad entre sistemas operativos Unix y garantizar que los programas escritos en un sistema puedan ejecutarse en otro sin muchas modificaciones.

_POSIX Threads_ (`thread.h`) es una biblioteca para manejar hilos en sistemas Unix y la cual usaremos para realizar este proyecto.

## Funiones para gestionar hilos.
### 1. `pthread_create()`
Crear un nuevo hilo de ejecución.

```C
int	pthread_create(pthread_t *thread,
					const thread_attr_t *attr,
					void *(*routine)(void *),
					void *arg);
```
- `thread` Punteroo a una variable `pthread_t` donde se almacenará el ID del hilo creado.
- `attr` Atributos del hilo, en caso de ser `NULL`, se usan los atributos por defeccto.
- `routine` Función que ejecutará el hilo.
- `arg`Argumento pasado a la función.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

#### Ejemplo de uso
```C
#include <pthread.h>
#include <stdio.h>

void *routine(void *arg)
{
	printf("Hilo ejecutándose...\n");
	return (NULL);
}

int	main(void)
{
	thread_t	thread;

	pthread_create(&thread, NULL, routine, NULL);
	...
	return (0);
}
```

### 2. `pthread_join()`
Espera que un hilo termine.
```C
int	pthreadd_join(pthread_t thread, void *retval)
```
- `thread` ID del hilo a esperar.
- `retval` Puntero donde se almacenará el valor de retorno del hilo que puede ser `NULL`.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

#### Ejemmplo de uso
```C
#include <pthread.h>
#include <stdio.h>

void *routine(void *arg)
{
	printf("Hilo en ejecución...\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, routine, NULL);
	if (!pthread_join(thread, NULL))
		printf("El hilo ha finalizado.\n");
	return (0);
}
```

### 3. `pthread_detach()`
Seara un hilo para que se limpie automáticamente cuando termine sin necesidad de llamar a `pthread_join`.

```C
int	pthread_detach(pthread_t thread);
```
- `thread` ID del hilo a separar.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

#### Ejemplo de uso
```C
#include <pthread.h>
#include <stdio.h>

void *routine(void *arg)
{
	printf("Hilo en ejecución...\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, routine, NULL);
	if (!pthread_join(thread, NULL))
		printf("El hilo se ha separado y se limpia automáticamente.\n");
	return (0);
}
```

## Funciones para gestionar mutex.
En esta sección no hay ejemplos de uso de cada función, para ver cómo jugar con mutex ir a [este apartado](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/apuntes.md#ejemplo-b%C3%A1sico-con-hilos-y-mutex).
### 1. `pthread_mutex_init()`
Inicializar un mutex.

```C
int	pthread_mutex_init(pthread_mutex_t *mutex,
						cconst pthread_mutexattr_t *attr);
```
- `mutex`Puntero a la variable mutex.
- `attr`Atributos del mutex, en caso de ser `NULL`, se usan llos valores por defecto.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

### 2. `pthread_mutex_destroy()`
Liberar recursos asociados a un mutex.

```C
int	pthread_mutex_destroy(pthread_mutex_t *mutex);
```
- `mutex` Mutex a destruir.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

### 3. `pthread_mutex_lock()`
Bloquea un mutex, en caso de que otro hilo ya lo tenga bloqueado se queda en espera.
```C
int	pthread_mutex_lock(pthread_mutex_t *mutex);
```
- `mutex` Mutex a bloquear.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.

### 4. `pthread_mutex_unlock()`
Desbloquea un mutex permitiendo que otro hilos lo usen.
```C
int	pthread_mutex_unlock(pthread_mutex_t *mutex);
```

- `mutex` Mutex a desbloquear.

#### Valores de retorno
- `0` En caso de que se ejecute correctamente.
- Número de error en caso de fallar.
