# fract-ol

## Introducción a MiniLibX

### Inicialización
Para poder usar esta librería hay que incluir la cabecera `<mlx.h>` o tener el código fuente de la librería en el proyecto y compilar todas sus funciones desde el _Makefile_.


Para inicializar la conexión con el sistema gráfico se usa [`mlx_init()`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_init).

```C
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	return (0);
}
```
Este código no muestra nada en pantalla poque todavía no se ha creado una ventana.

---

### Crear de una ventana
Usaremos la función [`mlx_new_window()`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_new_window) para crear una ventana con las dimensione que queramos y [`mlx_loop`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_loop) para mantener la aplicación abierta.

Ejemplo:
```C
#include <mlx.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 1920, 1024, "Hola Caracola");
	if (!win)
	{
		mlx_destroy_display(mlx); // Explicado más abajo.
		free(mlx);
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}
```
---

### Cerrar una ventana
Para cerrar una ventana haremos uso de la función [`mlx_destroy_window()`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_destroy_window) para cerrar la ventana y [`mlx_destroy_display()`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_destroy_display) para cerrar la conexión con el servidor de gráficos de linux.

Ejemplo:
```C
#include <mlx.h>

int	close_window(void *param)
{
	void **params;
	void *mlx;
	void *win;

	params = (void **)param;
	mlx = params[0];
	win = params[1];
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(0);
}
```

La funciópn `close_window()` cierra la ventana almacenada en el puntero `param`. Más abajo se explica cómo hacer esto.

---

### Capturar un evento
Un evento es una señal proveniente del teclado o ratón, sirve para indicar a un programa que haga una acción cuándo esto pase. En el ejemplo anterior detectamos que el botón de cerrar ventana se ha clickado y por lo tanto mandamos al programa que cierre la ventana.
Para capturar eventos se hace uso de [`mlx_hook()`](https://github.com/dejapiunrato/fract-ol/blob/main/MiniLibX_functions.md#mlx_hook).

Ejemplo:
```C
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*params[2];

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 1920, 1024, "Hola Caracola");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	params[0] = mlx;
	params[1] = win;
	mlx_hook(win, 17, 0, close_window, params);
	mlx_loop(mlx);
}
```
Este código funciona de la siguiente forma:
1. Crea una instancia de _MiniLibX_.
2. Crea una ventana nueva en dicha instancia.
3. Almacena la instancia y la ventana en `params[2]`.
4. En caso de que se clique el botón "cerrar ventana" se llama a `close_window` que cierra la ventana.
6. Mantiene abierta la instancia con `mlx_loop()`

### Dibujar píxeles en una imagen
