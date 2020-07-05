int		ft_power(int num, int power)
{
	int		rez;

	rez = 1;
	if (power == 0)
		return (1);
	while (power-- > 0)
		rez *= num;
	return (rez);
}
