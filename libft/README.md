# libft

Este proyecto consiste en crear una librería con funciones generales, muchas de ellas incluidas en la librería estandar de C:
| | |
| :--- | :--- |
| Nombre de programa | libft.a |
| **Archivos a entregar** | Makefile, libft.h ft_*.c |
| **Makefile** | NAME, all, clean, fclean, re |
| **Funciones autorizadas** | Instrucciones abajo |
| **Descripción** | Escribe tu propia libería: un conjunto de funciones que será una herramienta muy útil a lo largo del cursus. |

## Parte 1 - Funciones de libc
Para implementar las siguientes funciones no es necesario el uso de ninguna función.
| Función | Descripción |
| :--- | :--- |
| [ft_isalpha](https://github.com/dejapiunrato/libft/blob/main/ft_isalpha.c) | Devuelve 1 si el entero pasado como parámetro corresponde con una letra en la tabla ascii y 0 si no. |
| [ft_isdigit](https://github.com/dejapiunrato/libft/blob/main/ft_isdigit.c) | Devuelve 1 si el entero pasado como parámetro corresponde con un número en la tabla ascii y 0 si no. | 
| [ft_isalnum](https://github.com/dejapiunrato/libft/blob/main/ft_isalnum.c) | Devuelve 1 si el entero pasado como parámetro corresponde con un número o una letra en la tabla ascii y 0 si no. |
| [ft_isascii](https://github.com/dejapiunrato/libft/blob/main/ft_isascii.c) | Devuelve 1 si el enetro pasado como parámetro corresponde con un carácter de la tabla ascii y 0 si no. |
| [ft_isprint](https://github.com/dejapiunrato/libft/blob/main/ft_isprint.c) | Devuelve 1 si el entero pasado como parámetro corresponde conun carácter imprimible de la tabla ascii y 0 si no. |
| [ft_strlen](https://github.com/dejapiunrato/libft/blob/main/ft_strlen.c) | Devuelve el número de carácteres que contiene la cadena de texto pasada como parámetro. |
| [ft_memset](https://github.com/dejapiunrato/libft/blob/main/ft_memset.c) | Rellena una región de la memoria con un carácter concreto. |
| [ft_bzero](https://github.com/dejapiunrato/libft/blob/main/ft_bzero.c) | Rellena una región de la memoria con ceros. |
| [ft_memcpy](https://github.com/dejapiunrato/libft/blob/main/ft_memcpy.c) | Copia el contenido de una región de la memoria en otra. |
| [ft_memmove](https://github.com/dejapiunrato/libft/blob/main/ft_memmove.c) | Copia el contenido de una región de la memoria en otra, pero si estas se solapan, copia desde atrás hacia delante para evitar sobrescrituras. El resultado esperado es el mismo que de memcpy, pero de forma más segura al tener en cuenta solapamientos de memoria. |
| [ft_strlcpy](https://github.com/dejapiunrato/libft/blob/main/ft_strlcpy.c) | Copia un número dado de carácteres de una cadena de origen en una de destino y devuelve el tamaño de la cadena de origen. |
| [ft_strlcat](https://github.com/dejapiunrato/libft/blob/main/ft_strlcat.c) | Concatena una cadena de origen en otra de destino, siempre que haya espacio para ello, si no lo hay concatena lo que pueda y devuelve la suma del tamaño de ambas cadenas. |
| [ft_toupper](https://github.com/dejapiunrato/libft/blob/main/ft_toupper.c) | Pasa una letra pasada como parámetro a mayúscula. |
| [ft_tolower](https://github.com/dejapiunrato/libft/blob/main/ft_tolower.c) | Pasa una letra pasada como parámetro a minúscula. |
| [ft_strchr](https://github.com/dejapiunrato/libft/blob/main/ft_strchr.c) | Busca la primera aparición de un carácter dentro de una cadena y devuelve un puntero a esa posición. |
| [ft_strrchr](https://github.com/dejapiunrato/libft/blob/main/ft_strrchr.c) | Busca la última aparición de un carácter dentro de una cadena y devuelve un puntero a esa pocisión. |
| [ft_strncmp](https://github.com/dejapiunrato/libft/blob/main/ft_strncmp.c) | Compara dos cadenas hasta una posición *n*, si la primera es más larga que la primera, devuelve un número positivo, si es alrevés, uno negativo y si son iguales hasta donde se han comparado, un 0. |
| [ft_memchr](https://github.com/dejapiunrato/libft/blob/main/ft_memchr.c) | Busca la primera aparición de un carácter en los primeros *n* bytes de un bloque de memoria y devuelve un puntero a su posición. |
| [ft_memcmp](https://github.com/dejapiunrato/libft/blob/main/ft_memcmp.c) | Compara dos bloques de momoria los primeros *n* bytes, devuelve un valor positivo si el primer bloque es mayor que el segundo, negativo si es al revés y 0 si son iguales. |
| [ft_strnstr](https://github.com/dejapiunrato/libft/blob/main/ft_strnstr.c) | Busca la primera aparición de una subcadena dentro de los primeros *n* carácteres a analizar y devuelve un puntero al inicio de la subcadena. |
| [ft_atoi](https://github.com/dejapiunrato/libft/blob/main/ft_atoi.c) | Convierte una cadena que contenga un número al principio en el entero que representa, teniendo en cuenta el signo e ignorando los espacios del principio y del final |

Para implementar las dos funciones siguientes hay que hacer uso de la función malloc():
| Función | Descripción |
| :--- | :--- |
| [ft_calloc](https://github.com/dejapiunrato/libft/blob/main/ft_calloc.c) | Reserva un espacio de la memoria de un tamaño en bytes dado y lo rellena con ceros. |
| [ft_strdup](https://github.com/dejapiunrato/libft/blob/main/ft_strdup.c) | Duplica una cadena de texto dada. |

## Parte 2 - Funciones adicionales
| | |
| :--- | :--- |
| **Nombre de función** | [ft_substr.c](https://github.com/dejapiunrato/libft/blob/main/ft_substr.c) |
| **Prototipo** | ```char *ft_substr(char const *s, unsigned int start, size_t len);``` |
| **Parámetros** | **s**: La cadena a partir de la cual crear una subcadena.<br>**start**: El índice del carácter en *s* desde el qu empezar la subcadena.<br>**len**: La longitud máxima de la subcadena. |
| **Valor devuelto** | Un puntero al primer carácter de la subcadena resultado o NULL si falla la reserva de memoria. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Reserva la memoria necesaria para crear la subcdena de s.<br>La substring empieza en *start* y tiene una longitud máxima *len*. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_strjoin](https://github.com/dejapiunrato/libft/blob/main/ft_strjoin.c) |
| **Prototipo** |```char *ft_strjoin(char const *s1, char const *s2);``` |
| **Parámetros** | **s1**: La primera cadena.<br>**s2**: La cadena que debe ser añadida a *s1*. |
| **Valor devuelto** | Puntero al primer carácter de la cadena resultado de unir *s2* a *s1*. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Reserva memoria para una string resultado de la concatenación de *s1* y *s2*. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_strtrim](https://github.com/dejapiunrato/libft/blob/main/ft_strtrim.c) |
| **Prototipo** | ```char *ft_strtrim(char const *s1, char const *set);``` |
| **Parámetros** | **s1**: La cadena que debe ser recortada.<br>**set**: Carácteres a eliminar de la cadena. |
| **Valor devuelto** | Una cadena igual a *s1* pero sin los carácteres contenidos en *set* que haya al principio y al final. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Elimina todos los carácteresde contenidos en la cadena *set* desde el principio y desde el final de *s1* hasta encontrar un carácter no contenido en *set*. La cadena resultante tiene que ser una nueva cadena que haya reservado memoria. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_split](https://github.com/dejapiunrato/libft/blob/main/ft_split.c) |
| **Prototipo** | ```char **ft_split(char const *s, char c);``` |
| **Parámetros** | **s**: Cadena a separar en palabras.<br>**c**: Carácter delimitador de palabras. |
| **Valor devuelto** | Un arreglo de cadenas de texto, cada elemento del arreglo es una palabra contenida en *s* o NULL si falla la reserva de memoria. |
| **Funciones autorizadas** | malloc y free |
| **Descripción** | Reserva memoria para un arreglo de cadenas resultante de dibidir *s* en subcadenas utilizando el carácter *c* como delimitador de palabras. El array debe terminar con un puntero NULL. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_itoa](https://github.com/dejapiunrato/libft/blob/main/ft_itoa.c) |
| **Prototipo** | ```char *ft_itoa(int n);``` |
| **Parámetros** | **n**: Entero a convertir. |
| **Valor devuelto** | Una cadena que represente el número pasado como parámetro o NULL en caso de fallar la asignación de memoria. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Reserva memoria para una cadena que represente el entero pasado como parámetro, debe manejar números negativos. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_strmapi](https://github.com/dejapiunrato/libft/blob/main/ft_strmapi.c) |
| **Prototipo** | ```ft_strmapi(char const *s, char (*f*)(unsigned int, char));``` |
| **Parámetros** | **s**: Cadena de texto sobre la que iterar.<br>**f**: Función que aplicar a cada carácter. |
| **Valor devuelto** | Cadena resultante de aplicar la función *f* a cada carácter de la cadena o NULL en caso de fallar la asignación de memoria. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Aplica la función *f* a cada carácter de la cadena *s*, recibe como parametros el índice correspondinete a la posición de cada carácter en la cadena y el propio carácter. Crea una nueva cadena resltado de la aplciación de *f* sobre cada carácter. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_striteri](https://github.com/dejapiunrato/libft/blob/main/ft_striteri.c) |
| **Prototipo** | void ft_striteri(char *s, void (*f)(unsigned int, char\*));``` |
| **Parámetros** | **s**: Cadena que iterar.<br>**f**: Función a aplicar en cada carácter. |
| **Valor devuelto** | La cadena creada tras la aplicación de *f* en cada carácter de la cadena *s* o NULL en caso de que falle la asignación de memoria. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Aplica sobre cada carácter de *s* la función *f*, esta recibe como parámetros la posición del carácter y un puntero al mismo, que podrá modificar su contenido en caso de ser necesario. |

| | |
| :--- | :--- | 
| **Nombre de función** | [ft_putchar_fd](https://github.com/dejapiunrato/libft/blob/main/ft_putchar_fd.c) |
| **Prototipo** | ```void ft_putchar_fd(char c, int fd);``` |
| **Parámetros** | **c**: Carácter a enviar.<br>**fd**: El *file descriptor* sobre el que escribir. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | write |
| **Descripción** | Envia el carácter *c* al *file descriptor* especificado. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_putstr_fd](https://github.com/dejapiunrato/libft/blob/main/ft_putstr_fd.c) |
| **Prototipo** | ```ft_putstr_fd(char *s, int fd);``` |
| **Parámetros** | **s**: Cadena de texto a enviar.<br>**fd**: El *file descriptor* sobre el que escribir. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | write |
| **Descripción** | Envía la cadena *s* al *file descriptor* especificado. |

| | |
| :--- | :--- | 
| **Nombre de función** | [ft_putendl_fd](https://github.com/dejapiunrato/libft/blob/main/ft_putendl_fd.c) |
| **Prototipo** | ```void ft_putendl_fd(char *s, int fd);``` |
| **Parámetros** | **s**: Cadena de texto a enviar.<br>**fd**: El *file descriptor* sobre el que escribir. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | write |
| **Descripción** | Envía la cadena *s* al *file descriptor* dado, seguida de un salto de línea. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_putnbr_fd](https://github.com/dejapiunrato/libft/blob/main/ft_putnbr_fd.c) |
| **Prototipo** | ```void ft_putnbr_fd(int n, int fd);``` |
| **Parámetros** | **n**: Número a enviar.<br>**fd**: El *file descriptor* sobre el que escribir. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | write |
| **Descripción** | Envía el número *n* al *file descriptor* indicado. |

## Parte bonus
Para hacer esta parte hay que añadir la siguiente estructura en "libft.h".
```c
typedef struct	s_list
{
	void		*content;
 	struct s_list	*next;
}	t_list;
```

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstnew](https://github.com/dejapiunrato/libft/blob/main/ft_lstnew_bonus.c) |
| **Prototipo** | ```t_list *ft_lstnew(void *content);``` |
| **Parámetros** | **content**: El contenido con el que crear el nodo. |
| **Valor devuelto** | El nuevo nodo. |
| **Funciones autorizadas** | malloc |
| **Descripción** | Crea un nuevo nodo. La variable miembro *content* se inicializa con el valor contenido del parametro *content*. La variable *next*, con NULL. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstadd_front](https://github.com/dejapiunrato/libft/blob/main/ft_lstadd_front_bonus.c) |
| **Prototipo** | ```void ft_lstadd_front(t_list **lst, t_list *new);``` |
| **Parámetros** | **lst**: La dirección de un puntero al primer nodo de una lista.<br>**new**: Un puntero al nodo que añadir al principio de la lista.
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | Ninguna. |
| **Descripción** | Añada el nodo *new* al principio de la lista *lst*. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstsize](https://github.com/dejapiunrato/libft/blob/main/ft_lstsize_bonus.c) |
| **Prototipo** | ```int ft_lstsize(t_list *lst);``` |
| **Parámetros** | **lst**: Puntero al inicio de una lista. |
| **Valor devuelto** | Tamaño de la lista. |
| **Funciones autorizadas** | Ninguna. |
| **Descripción** | Cuenta el número de nodos de una lista dada. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstlast](https://github.com/dejapiunrato/libft/blob/main/ft_lstlast_bonus.c) |
| **Prototipo** | ```t_list *ft_lstlast(t_list *lst);``` |
| **Parámetros** | **lst**: Puntero al inicio de una lista. |
| **Valor devuelto** | Puntero al último nodo de una lista. |
| **Funciones autorizadas** | Ninguna.
| **Descripción** | Devuelve el último nodo de una lista. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstadd_back](https://github.com/dejapiunrato/libft/blob/main/ft_lstadd_back_bonus.c) |
| **Prototipo** | ```void ft_lstadd_back(t_list **lst, t_list *new);``` |
| **Parámetros** | **lst**: Puntero al primer nodo de una lista.<br>**new**: Puntero a un nodo que añadir a la lista. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | Ninguna. |
| **Descripción** | Añade le nodo *new* al final de la lista *lst*. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstdelone](https://github.com/dejapiunrato/libft/blob/main/ft_lstdelone_bonus.c) |
| **Prototipo** | ```void ft_lstdelone(t_list *lst, void (*del)(void *));``` |
| **Parámetros** | **lst**: el nodo a liberar.<br>**del**: Un puntero a una función utilizada para liberar el contenido del nodo. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | Ninguna. |
| **Descripción** | Toma como parámetro un nodo *lst* y libera la memoria del contenido utilizando la función *del^dada como parámetro, además de liberar el nodo. La memoria de *next* no debe liberarse. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstclear](https://github.com/dejapiunrato/libft/blob/main/ft_lstclear_bonus.c) |
| **Prototipo** | ```void ft_lstclear(t_list **lst, void (*del)(void *));``` |
| **Parámetros** | **lst**: Dirección de un puntero a un nodo.<br>**del**: Puntero a una función que elimina el ocntenido de un nodo.
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | free |.
| **Descripción** | Elimina y libera el nodo *lst* y todos los siguientes utilizando la función *del*. Al final, el puntero a la lista debe ser NULL. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstiter](https://github.com/dejapiunrato/libft/blob/main/ft_lstiter_bonus.c) |
| **Prototipo** | ```void ft_lstiter(t_list *lst, void (*f)(void *));``` |
| **Parámetros** | **lst**: Puntero al primer nodo de una lista.<br>**F**: Puntero a la función que utilizará cada nodo. |
| **Valor devuelto** | Nada. |
| **Funciones autorizadas** | Ninguna. |
| **Descripción** | Itera sobre la lista *lst* y aplica la función *f* en cada nodo. |

| | |
| :--- | :--- |
| **Nombre de función** | [ft_lstmap](https://github.com/dejapiunrato/libft/blob/main/ft_lstmap_bonus.c) |
| **Prototipo** | ```t_list *ft_lstmap(t_list *lst, void *(\*f)(void *), void (*del)(void *));``` |
| **Parámetros** | **lst**: Puntero al primer nodo de una listt.<br>**f**: Dirección de un puntero a una función usada en la iteración de cada elemento de la lista.<br>**del**: Puntero a una función para eliminar el contenido de un nodo, si es necesario. |
| **Valor devuelto** | Nueva lista o NULL si la reserva de memoria falla. |
| **Funciones autorizadas** | malloc y free |
| **Descripción** | Itera la lista *lst* y aplica la función *f* al contenido de cada nodo. Crea una lista resltante de la aplicación correcta y sucesiva de la función *f* sobre cada nodo. La función *del* se utiliza para eliminar el contenido de un nodo, si hace falta. |
