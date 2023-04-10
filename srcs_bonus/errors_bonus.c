#include "../include/so_long_bonus.h"

// Function to returns feedback for errors that are related to the initialization of the game
void	ft_error_init(int n)
{
	if (n == 38)
		ft_printf("%sError\nCheck library compatibility!", COLOR_RED);
	if (n == 1)
		ft_printf("%sError\nOperation not permitted. Please, check if you are in the correct path.\n", COLOR_RED);
	if (n == 2)
		ft_printf("%sError\nNo such file or directory|", COLOR_RED);
	exit(n);
}

// Function to returns feedback for errors that are related to the map
void	ft_error_map(int n)
{
	if (n == 21)
		ft_printf("%sError\n This is a directory. \n", COLOR_RED);
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		ft_printf("%sError\n Usage: ./so_long <filename>.ber \n", COLOR_RED);
	else if (n == 61)
		ft_printf("%sError\n Try create one valid map! \n", COLOR_RED);
	exit(n);
}
