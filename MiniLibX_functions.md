# Funciones de MiniLibX
En este documento intentaré explicar con detalle las funciones de la _MiniLib_ que use en el proyecto.

---

### `mlx_init()`
Función para crear una instancia de _MiniLibX_, devuelve un puntero que representa dicha instancia o `NULL` si algo falló.

Prototipo:
```C
void	*mlx_init();
```

---

### `mlx_new_window()`
Función para crear una nueva ventana, devuelve un puntero a la ventana creada o `NULL` en caso de que algo falle.

Prototipo:
```C
void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title);
```
- `xvar` Puntero a una estructura `t_xvar` que contiene información sobre la conexión con el sistema gráfico de linux.
- `size_x` Ancho de la ventana en píxeles.
- `size_y` Alto de la ventana en píxeles.
- `title`Nombre de la ventana.

---

### `mlx_loop()`
Mantener una instancia de _MiniLibX_ en ejecución, esto es útil para poder manejar eventos (lo que pasa cuándo se pulsa una tecla o se mueve el ratón).
Esta función devuelve siempre `0`.
Prototipo:
```C
int	mlx_loop(t_xvar *xvar);
```
- `xvar` Puntero a una estructura `t_xvar` que representa la instancia de _MiniLibX_ que se quiere mantener en ejecución.

---

### `mlx_destroy_window()`
Función para cerrar una ventana.
Prototipo:
```C
int	mlx_destroy_window(t_xvar *xvar,t_win_list *win);
```
- `xvar` Instancia de _MiniLibX_ que tiene la ventana abierta.
- `win` Ventana que se quiere cerrar.

---

### `mlx_hook()`
Esta función detecta un evento y aplica una función que recibe como parámetro.
Prototipo:
```C
int	mlx_hook(t_win_list *win, int x_event, int x_mask, int (*funct)(),void *param);
```
- `win` Puntero a la ventana en la que se quiere registrar el evento.
- `x_event` Tipo de evento que se desea capturar.
	
	<details>
  <summary>Lista de eventos:</summary>
  <table>
    <tr>
      <th>Código Numérico</th>
      <th>Evento</th>
      <th>Descripción</th>
    </tr>
    <tr>
      <td>2</td>
      <td>KeyPress</td>
      <td>Se activa cuando una tecla es presionada.</td>
    </tr>
    <tr>
      <td>3</td>
      <td>KeyRelease</td>
      <td>Se activa cuando una tecla es soltada.</td>
    </tr>
    <tr>
      <td>4</td>
      <td>ButtonPress</td>
      <td>Se activa cuando se presiona un botón del ratón.</td>
    </tr>
    <tr>
      <td>5</td>
      <td>ButtonRelease</td>
      <td>Se activa cuando se suelta un botón del ratón.</td>
    </tr>
    <tr>
      <td>6</td>
      <td>MotionNotify</td>
      <td>Se activa cuando el ratón se mueve.</td>
    </tr>
    <tr>
      <td>7</td>
      <td>EnterNotify</td>
      <td>Se activa cuando el cursor entra en la ventana.</td>
    </tr>
    <tr>
      <td>8</td>
      <td>LeaveNotify</td>
      <td>Se activa cuando el cursor sale de la ventana.</td>
    </tr>
    <tr>
      <td>9</td>
      <td>FocusIn</td>
      <td>Se activa cuando la ventana gana el foco.</td>
    </tr>
    <tr>
      <td>10</td>
      <td>FocusOut</td>
      <td>Se activa cuando la ventana pierde el foco.</td>
    </tr>
    <tr>
      <td>11</td>
      <td>KeymapNotify</td>
      <td>Se activa cuando el estado del teclado cambia.</td>
    </tr>
    <tr>
      <td>12</td>
      <td>Expose</td>
      <td>Se activa cuando una parte de la ventana debe redibujarse.</td>
    </tr>
    <tr>
      <td>13</td>
      <td>GraphicsExpose</td>
      <td>Se activa cuando un área gráfica debe redibujarse.</td>
    </tr>
    <tr>
      <td>14</td>
      <td>NoExpose</td>
      <td>Se activa cuando no hay necesidad de redibujar.</td>
    </tr>
    <tr>
      <td>15</td>
      <td>VisibilityNotify</td>
      <td>Se activa cuando cambia la visibilidad de la ventana.</td>
    </tr>
    <tr>
      <td>16</td>
      <td>CreateNotify</td>
      <td>Se activa cuando se crea una ventana.</td>
    </tr>
    <tr>
      <td>17</td>
      <td>DestroyNotify</td>
      <td>Se activa cuando una ventana es destruida.</td>
    </tr>
    <tr>
      <td>18</td>
      <td>UnmapNotify</td>
      <td>Se activa cuando una ventana es ocultada.</td>
    </tr>
    <tr>
      <td>19</td>
      <td>MapNotify</td>
      <td>Se activa cuando una ventana es mostrada.</td>
    </tr>
    <tr>
      <td>20</td>
      <td>MapRequest</td>
      <td>Se activa cuando una ventana solicita ser mostrada.</td>
    </tr>
    <tr>
      <td>21</td>
      <td>ReparentNotify</td>
      <td>Se activa cuando una ventana cambia de padre.</td>
    </tr>
    <tr>
      <td>22</td>
      <td>ConfigureNotify</td>
      <td>Se activa cuando la ventana cambia de tamaño o posición.</td>
    </tr>
    <tr>
      <td>23</td>
      <td>ConfigureRequest</td>
      <td>Se activa cuando una ventana solicita cambiar su tamaño o posición.</td>
    </tr>
    <tr>
      <td>24</td>
      <td>GravityNotify</td>
      <td>Se activa cuando cambia la gravedad de la ventana.</td>
    </tr>
    <tr>
      <td>25</td>
      <td>ResizeRequest</td>
      <td>Se activa cuando una ventana solicita ser redimensionada.</td>
    </tr>
    <tr>
      <td>26</td>
      <td>CirculateNotify</td>
      <td>Se activa cuando cambia el orden de apilamiento de la ventana.</td>
    </tr>
    <tr>
      <td>27</td>
      <td>CirculateRequest</td>
      <td>Se activa cuando una ventana solicita cambiar su orden de apilamiento.</td>
    </tr>
    <tr>
      <td>28</td>
      <td>PropertyNotify</td>
      <td>Se activa cuando una propiedad de la ventana cambia.</td>
    </tr>
    <tr>
      <td>29</td>
      <td>SelectionClear</td>
      <td>Se activa cuando la selección actual es limpiada.</td>
    </tr>
    <tr>
      <td>30</td>
      <td>SelectionRequest</td>
      <td>Se activa cuando otra aplicación solicita la selección.</td>
    </tr>
    <tr>
      <td>31</td>
      <td>SelectionNotify</td>
      <td>Se activa cuando se responde a una solicitud de selección.</td>
    </tr>
    <tr>
      <td>32</td>
      <td>ColormapNotify</td>
      <td>Se activa cuando cambia el mapa de colores de la ventana.</td>
    </tr>
    <tr>
      <td>33</td>
      <td>ClientMessage</td>
      <td>Se usa para enviar mensajes personalizados a la ventana.</td>
    </tr>
    <tr>
      <td>34</td>
      <td>MappingNotify</td>
      <td>Se activa cuando cambia el mapeo del teclado o ratón.</td>
    </tr>
    <tr>
      <td>35</td>
      <td>GenericEvent</td>
      <td>Evento genérico usado por extensiones de X11.</td>
    </tr>
  </table>
</details>

- `x_mask` Una máscara que expecifica qué eventos se quieren capturar.

	<details>
  <summary>Lista de máscaras</summary>
  <table>
    <tr>
      <th>Decimal</th>
      <th>Hexadecimal</th>
      <th>Máscara</th>
      <th>Descripción</th>
    </tr>
    <tr>
      <td>0</td>
      <td>0x000000</td>
      <td>NoEventMask</td>
      <td>No escucha ningún evento.</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0x000001</td>
      <td>KeyPressMask</td>
      <td>Escucha eventos de presión de tecla.</td>
    </tr>
    <tr>
      <td>2</td>
      <td>0x000002</td>
      <td>KeyReleaseMask</td>
      <td>Escucha eventos de liberación de tecla.</td>
    </tr>
    <tr>
      <td>4</td>
      <td>0x000004</td>
      <td>ButtonPressMask</td>
      <td>Escucha eventos de presión de botón del ratón.</td>
    </tr>
    <tr>
      <td>8</td>
      <td>0x000008</td>
      <td>ButtonReleaseMask</td>
      <td>Escucha eventos de liberación de botón del ratón.</td>
    </tr>
    <tr>
      <td>16</td>
      <td>0x000010</td>
      <td>EnterWindowMask</td>
      <td>Escucha cuando el cursor entra en la ventana.</td>
    </tr>
    <tr>
      <td>32</td>
      <td>0x000020</td>
      <td>LeaveWindowMask</td>
      <td>Escucha cuando el cursor sale de la ventana.</td>
    </tr>
    <tr>
      <td>64</td>
      <td>0x000040</td>
      <td>PointerMotionMask</td>
      <td>Escucha el movimiento del cursor.</td>
    </tr>
    <tr>
      <td>128</td>
      <td>0x000080</td>
      <td>PointerMotionHintMask</td>
      <td>Reduce la cantidad de eventos de movimiento del cursor.</td>
    </tr>
    <tr>
      <td>256</td>
      <td>0x000100</td>
      <td>Button1MotionMask</td>
      <td>Escucha el movimiento del cursor con el botón 1 presionado.</td>
    </tr>
    <tr>
      <td>512</td>
      <td>0x000200</td>
      <td>Button2MotionMask</td>
      <td>Escucha el movimiento del cursor con el botón 2 presionado.</td>
    </tr>
    <tr>
      <td>1024</td>
      <td>0x000400</td>
      <td>Button3MotionMask</td>
      <td>Escucha el movimiento del cursor con el botón 3 presionado.</td>
    </tr>
    <tr>
      <td>2048</td>
      <td>0x000800</td>
      <td>Button4MotionMask</td>
      <td>Escucha el movimiento del cursor con el botón 4 presionado.</td>
    </tr>
    <tr>
      <td>4096</td>
      <td>0x001000</td>
      <td>Button5MotionMask</td>
      <td>Escucha el movimiento del cursor con el botón 5 presionado.</td>
    </tr>
    <tr>
      <td>8192</td>
      <td>0x002000</td>
      <td>ButtonMotionMask</td>
      <td>Escucha el movimiento del cursor con cualquier botón presionado.</td>
    </tr>
    <tr>
      <td>16384</td>
      <td>0x004000</td>
      <td>KeymapStateMask</td>
      <td>Escucha cambios en el estado del teclado.</td>
    </tr>
    <tr>
      <td>32768</td>
      <td>0x008000</td>
      <td>ExposureMask</td>
      <td>Escucha eventos cuando una ventana necesita ser redibujada.</td>
    </tr>
    <tr>
      <td>65536</td>
      <td>0x010000</td>
      <td>VisibilityChangeMask</td>
      <td>Escucha cambios en la visibilidad de la ventana.</td>
    </tr>
    <tr>
      <td>131072</td>
      <td>0x020000</td>
      <td>StructureNotifyMask</td>
      <td>Escucha cambios en la estructura de la ventana.</td>
    </tr>
    <tr>
      <td>262144</td>
      <td>0x040000</td>
      <td>ResizeRedirectMask</td>
      <td>Escucha solicitudes de cambio de tamaño de la ventana.</td>
    </tr>
    <tr>
      <td>524288</td>
      <td>0x080000</td>
      <td>SubstructureNotifyMask</td>
      <td>Escucha cambios en la estructura de las subventanas.</td>
    </tr>
    <tr>
      <td>1048576</td>
      <td>0x100000</td>
      <td>SubstructureRedirectMask</td>
      <td>Escucha solicitudes de cambio de estructura de subventanas.</td>
    </tr>
    <tr>
      <td>2097152</td>
      <td>0x200000</td>
      <td>FocusChangeMask</td>
      <td>Escucha eventos de cambio de foco de la ventana.</td>
    </tr>
    <tr>
      <td>4194304</td>
      <td>0x400000</td>
      <td>PropertyChangeMask</td>
      <td>Escucha cambios en las propiedades de la ventana.</td>
    </tr>
    <tr>
      <td>8388608</td>
      <td>0x800000</td>
      <td>ColormapChangeMask</td>
      <td>Escucha cambios en el mapa de colores de la ventana.</td>
    </tr>
    <tr>
      <td>16777216</td>
      <td>0x1000000</td>
      <td>OwnerGrabButtonMask</td>
      <td>Evita que otras aplicaciones intercepten eventos de botón mientras están presionados.</td>
    </tr>
  </table>
</details>


- `funct` Una función a la que se llamará cuándo ocurra el evento, esta función tiene que tener la firma `int (*funct)`, es decir, debe retornar un entero.
- `param` Es un puntero a lso datos que se la pasarán a la función `funct`.

