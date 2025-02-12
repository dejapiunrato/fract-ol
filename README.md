# fract-ol

## Introducción a MiniLibX

### Inicialización
Para poder usar esta librería hay que incluir la cabecera `<mlx.h>` o tener el código fuente de la librería en el proyecto y compilar todas sus funciones desde el _Makefile_.


Para inicializar la conexión con el sistema gráfico se usa [`mlx_init()`]() que devuelve un puntero `(void *)` que representa la instancia de MiniLibX.

```C
#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
```
Este código no muestra nada en pantalla poque todavía no se ha creado una ventana.

Prototipo de `mlx_init()`
```C
void	*mlx_init();
```

