#include "fractol.h"

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

double	ft_atoivrgl(char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;
	int i;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	int i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != '.' && str[i])
	{
		integer_part = (integer_part * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		pow /= 10;
		fractional_part = fractional_part + (str[i] - 48) * pow;
		i++;
	}
	return ((integer_part + fractional_part) * sign);
}
