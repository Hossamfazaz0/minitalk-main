#include "minitalk.h"
int	ft_atoi(const char *str)
{
	long int	result;
	long int	result2;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result2 = result;
		result = result * 10 + (*str++ - '0');
		if (result < result2 && sign == -1)
			return (0);
		if (result < result2 && sign == 1)
			return (-1);
	}
	return (sign * result);
}