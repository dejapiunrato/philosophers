# Apuntes
Auí hay un resumen de cosas que he leido y me han parecido importantes par imiplementar mi código.

## Programación secuencial
La programacción secuencial es aquella en la que las instrucciones se ejecutan una or una en orden en un solo hilo de ejecución. Esto quiere decir que cada operación espera a la anterior terine y es más fácil de depurar, pero no se utilizan los múltiles núcleos del procesador.

## Programación concurrente
En la programación concurrente se hacen uso de varios hilos para que se puedan ejecutar varias tareas de forma alterna o simultanea sin necesitar a que una instrucción termine para iniciar la siguiente. Esto acelera muchos procesos al hacerse uso de varios núcleos de la CPU.

## Hilos (threads)

Un hilo es una secuencia de operaciones dentro de un proceso que el sistema operativo gestiona de forma automática.

Cada hilo dentro de un proceso tiene algunas caracterísiticas propias y otras compartidas con el resto de hilos del proceso:

### Características propias
- **ID:** Identificador del proceso.
- _**Stack:**_ Cada  hilo tienne un stack de memoria propio para gestionar variables locales, direcciones de retorno y datos temporales. Esto permite que un hilo no interveenga en otro.
- **Puntero:** Un puntero que indica en qué punto del código se está ejcutando el hilo.
- **Registro del procesador:** 	Cada hilo gestiona sus registros de la CPU.

### Caraccterísticas compartidas
- **Memoria virtual:** Memoria virtual del proceso.
- **Código del programa:** Código ejecutable en lenguaje máquina del programa.
- _**Heap:**_ Memoria dinámica, todos los hilos pueden escribir y leer en la memoria dinámica asignada con `malloc()`.
- **Bibliotecas:** Todas las bibliotecas cargadas en memoria son accesibles  desde cualquier hilo.
- _**File Descriptors:**_ Si un proceso abre un archivo, todos los sus hilos tienen acceso a él.

Crear o cambiar entre hilos requiere muchos menos recursos para la CPU que crear o cambiar entre procesos.

---

#### Simil chulo de ChatGPT para explicar esto:

Imagina que un proceso es como una casa y los hilos son personas viviendo en esa casa.

Cada persona (hilo) tiene su propia mochila (stack), su propia agenda (instruction pointer) y su propia memoria de trabajo (registros del procesador).

Pero todos comparten la misma cocina (heap), la misma televisión (código del programa), los mismos utensilios (bibliotecas) y las mismas llaves de la casa (descriptores de archivos).

Así, si una persona cocina comida en la cocina (modifica el heap), cualquier otra persona en la casa puede comer de la misma olla (acceder a los datos en el heap).

---

### Manejo básico de hilos con `pthread.h`
_POSIX Threads_ (`thread.h`) es una biblioteca para manejar hilos en sistemas Unix y la cual usaremos para realizar este proyecto.

Para crear un hilo se hace uso de [`pthread_create()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#1-pthread_create), en función de para qué se uso este hilo tendremos que usar [`pthread_join()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#2-pthread_join) o [`pthread_detach()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#3-pthread_detach):

1. [`pthread_join()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#2-pthread_join) sirve cuando hay que esperar a que termine la ejecución del hilo porque los resultados del hilo son necesarios para continuar o porque quieres asegurarte de que el hilo ha terminado de antes de que el programa finalice.
2. [`pthread_detach()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#3-pthread_detach)) libera los recursos utilizados por el hilo automáticamente al terminar su ejecución, se usa cuando no hace falta recoger los datos.

En casoo de no hacer ni _join_ ni _detach_ no se liberan los recursos y se traducce en una fuga de memoria.

| Caso            | ¿Necesitas esperar el hilo? | ¿Quieres que el sistema lo libere automáticamente? | Solución            |
|-----------------|-----------------------------|--------------------------------|------------------|
| Sí              | Sí                          | No                             | `pthread_join()`  |
| No              | No                          | Sí                             | `pthread_detach()` |
| No haces nada   | ❌                          | ❌                             | ❌ **Error: Fuga de memoria** |


## Mutex
El nombre viene de "Exclusión Mutua" (En inglés: _Mutual Exclusion_) y es un mecanismo de sincronización de hilos para evitar que accedan simultáneamente a recursos compartido como la memoria, variables o archivos.

El mutex asegura que cuando un hilo accede a un recurso, este queda  bloqueado para los demás que intenten acceder hasta que el primero lo haya liberado. Es una forma de solventar un problema llamado _race condition_, que ocurre cuando el acceso simultaneo a recursos genera resultados inesperados.

Un mutex sigue el siguiente procceso:
1. `thread_1` accede a un recurso
2. Se bloquea el recurso para el resto de hilos.
3. `thread_2` intenta acceder al recurso.
4. `thread_2` se pone en espera.
5. `thread_1` libera el recurso.
6. `thread_2` accede.
7. Se bloquea el recurso para el resto de hilos.
8. ...

Las funciones básicas de gestión de mutex son:
1. [`pthread_mutex_init()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#1-pthread_mutex_init) Iniciar mutex.
2. [`pthread_mutex_destroy()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#2-pthread_mutex_destroy) Elimiar mutex.
3. [`pthread_mutex_lock()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#3-pthread_mutex_lock) Bloquear mutex.
4. [`pthread_mutex_unlock()`](https://github.com/dejapiunrato/philosophers/blob/main/apuntes/funciones.md#4-pthread_mutex_unlock) Desbloquear mutex.

### Ejemplo básico con hilos y mutex
```C
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef pthread_mutex_t mutex_t;

mutex_t		mutex;
int		i = 0;

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
	int		error;

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
```
