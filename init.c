#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	data_init(t_fractal *fractal)
{
	fractal->iterations_defintion = 42; 
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}


static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,KeyPress,KeyPressMask,key_handler,fractal);
	mlx_hook(fractal->mlx_window,ButtonPress,ButtonPressMask,mouse_handler,fractal);
	mlx_hook(fractal->mlx_window,DestroyNotify,StructureNotifyMask,close_handler,fractal);
	mlx_hook(fractal->mlx_window,MotionNotify,PointerMotionMask,julia_track,fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,WIDTH,HEIGHT,fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,&fractal->img.bpp,&fractal->img.line_len,&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
