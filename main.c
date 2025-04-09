#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && argv[1] != "mandelbrot" || argc == 4 && argv[1] == "julia")
	{
		fractal.name = av[1];
		if (fractal.name == "julia")
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd("Usage = ./fractol mandelbrot\n or \n./fractol julia <value_1> <value_2>\n", 2);
		exit(EXIT_FAILURE);
	}
}
