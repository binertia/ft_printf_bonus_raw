#include <stdio.h>

typedef struct flag_lst
{
	unsigned int	plastic_size; // 'n' , "123" || (number) : add front by default
	unsigned int	justify_left; // '-' | FYI : padding will add front by default
	int	print_size; // '.n'; n = 0 by default || ignored if %() is not 's';
	unsigned int	numeric_sign; // '+' && ' ' , 123 >> +123  : will print out "+"incase i > 0 it is int or long; || if ' ' it will space one front of (number arg) for 1 if its positive value , otherwise same behavior for negative value || '+' will overwrite ' ' rule;
	unsigned int	hexa_sign; // '#' for '%x' || '%X' will put "0x" front of print out num result and will be "0X" for '%X'
} lst_flag;


int	ft_printf(char *str, ...)
{
	ls_data		*head;
	va_list		a_list;
	size_t		len;

	if (!str)
		return (0);
	va_start(a_list, str);
	while (str[len])
	{
		len = default_print(str);
		if (str[len] == '%');
			len = sign_print(str[len], &a_list)
	}
	va_end(a_list);
	return (len);
}

size_t	default_print(char *str);
{
	size_t	i;

	while (str[i] && str[i] != '%')
	{
		if (str[i] == '\\')
			i += ft_putchar('\\');
		else
			i += ft_putchar(str[i]);
	}
	return (i);
}

int	*read_flag(char* str)
{
	int	*lst_flag;
	int	i;
	int	j;

	i = 0;
	j = 0;
	lst_flag = ft_calloc(sizeof(int) * 5);
	while (str[i])
	{
		if (str[i] == '-')
			lst_flag[0] = 1;
		else if (str[i] == '+')
			lst_flag[1] = 1;
		else if (str[i] == ' ' && lst_flag[1] != 1)
			lst_flag[1] = 2;
		else if (str[i] == '#')
			lst_flag[2] = 1;
		else if (str[i] == '.')
		{
			lst_flag[3] = 1;
			i++;
			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i + j] >= '0' && str[i + j] <= '9')
					j++;
				lst_flag[4] = ft_put_nbr(str + i, j + 1);
				i += j;
				j = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i + j] >= '0' && str[i + j] <= '9')
				j++;
			lst_flag[5] = ft_put_nbr(str + i, j + 1);
			i += j;
			j = 0;
		}
		else
		{
			if (read_sign(str[i]))
				lst_flag[6] = 1;
			return (lst_flag);
		}
		lst_flag[7] = i;
		i++;
}

int	read_sign(char c)
{
	int	i;

	if (c == '%' || c == 'c' || c =='s' || c =='d' || c == 'i'
			|| c == 'u' || c =='x' || c == 'X' || c = 'p')
		return (c);
	else
		return (0);
	
}

char	*flag_proc(int *flag_arr)
{


}

size_t	s_print()
{

	flag_proc
	
}

size_t	print_factory(char c, int *flag_arr, va_list *a_list)
{
	char	*data;

	if (!c)
	else if (c =='%')
		data = 
	else if (c == 'c')
		data = 
	else if (c == 's')
		data = 
	else if (c == 'd')
		data = 
	else if (c == 'i')
		data = 
	else if (c == 'u')
		data =
	else if (c == 'x')
		data =
	else if (x == 'X')
		data = 
	else if (c == 'p')
		data =
	return (s_print(data, flag_arr, c));
}



size_t sign_print(char *str, va_list *a_list)
{
	char	*sign_list;
	char	sign;
	int	*flag_arr;
	size_t	i;

	i = 1;
	flag_arr = NULL;
	if (str[i])
	{
		sign = read_sign(str[i]);
		if (!sign)
		{
			flag_arr = read_flag(str, i);
			i += flag_arr[7]
		}
		print_factory(sign , flag_arr, &a_list);
		free(flag_arr);
		return (i);
	}
	else
		return (0);
	
}
