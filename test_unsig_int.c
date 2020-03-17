#include "ft_printf.h"

void	test_uns_int(char *str, void *num)
{
	int a, b;
	a = printf(str, num);
	printf("print =       ");
	printf("%d\n", a);
	b = ft_printf(str, num);
	printf("my print =    ");
	printf("%d\n\n", b);
	if (a != b)
		printf("----------------FAIL------------->\n\n");
}

void	test_unsig_int_arg1(ULL_int num)
{
	static char	a01;
	printf("----------------------------UNSIGNED---INTEGER------------------------>\n");
	// test_uns_int("1--->_%\n"5, 9);
	// test_uns_int("1--->_%hhp5\n", (unsigned char)255);
	test_uns_int("1--->_%-7p5\n", &a01);
	test_uns_int("1--->_%-7.5p\n", &a01);
	test_uns_int("1--->_%-7.510p\n", &a01);
	test_uns_int("1--->_%-7.56p\n", &a01);
	test_uns_int("1--->_%-8.53p\n", &a01);
	
	test_uns_int("2--->_%7p\5n", &a01);
	test_uns_int("2--->_%7.p5\n", &a01);
	test_uns_int("2--->_%7.150p\n", &a01);
	test_uns_int("2--->_%7.65p\n", &a01);
	test_uns_int("2--->_%8.35p\n", &a01);
	
	test_uns_int("3--->_%07p5\n", &a01);
	test_uns_int("3--->_%07.5p\n", &a01);
	test_uns_int("3--->_%07.510p\n", &a01);
	test_uns_int("3--->_%07.56p\n", &a01);
	test_uns_int("3--->_%08.53p\n", &a01);
	
	test_uns_int("4--->_%+7p5\n", &a01);
	test_uns_int("4--->_%+7.5p\n", &a01); // 1
	test_uns_int("4--->_%+7.510p\n", &a01);
	test_uns_int("4--->_%+7.56p\n", &a01);
	test_uns_int("4--->_%+8.53p\n", &a01);
	
	test_uns_int("5--->_%+075p\n", &a01);
	test_uns_int("5--->_%+075.p\n", &a01); // 2
	test_uns_int("5--->_%+075.10p\n", &a01);
	test_uns_int("5--->_%+075.6p\n", &a01);
	test_uns_int("5--->_%+085.3p\n", &a01);
	
	test_uns_int("6--->_%+ 75p\n", &a01);
	test_uns_int("6--->_%+ 75.p\n", &a01);
	test_uns_int("6--->_%+ 75.10p\n", &a01);
	test_uns_int("6--->_%+ 75.6p\n", &a01);
	test_uns_int("6--->_%+ 85.3p\n", &a01);
	
	test_uns_int("7--->_% +057p\n", &a01);
	test_uns_int("7--->_% +057.p\n", &a01); // 3
	test_uns_int("7--->_% +057.10p\n", &a01);
	test_uns_int("7--->_% +057.6p\n", &a01);
	test_uns_int("7--->_% +058.3p\n", &a01);
	
	test_uns_int("8--->_%- 057p\n", &a01);
	test_uns_int("8--->_%- 057.p\n", &a01);
	test_uns_int("8--->_%- 057.10p\n", &a01);
	test_uns_int("8--->_%- 057.6p\n", &a01);
	test_uns_int("8--->_%- 058.3p\n", &a01);
	printf("------------------------l----UNSIGNED---INTEGER----l-------------------->\n");

	test_uns_int("1l--->_%-7lp\n", &a01);
	test_uns_int("1l--->_%-7.5lp\n", &a01);
	test_uns_int("1l--->_%-7.510lp\n", &a01);
	test_uns_int("1l--->_%-7.56lp\n", &a01);
	test_uns_int("1l--->_%-8.53lp\n", &a01);

	test_uns_int("2l--->_%7lp\n", &a01);
	test_uns_int("2l--->_%7.lp\n", &a01);
	test_uns_int("2l--->_%7.150lp\n", &a01);
	test_uns_int("2l--->_%7.65lp\n", &a01);
	test_uns_int("2l--->_%8.35lp\n", &a01);

	test_uns_int("3l--->_%07lp\n", &a01);
	test_uns_int("3l--->_%07.5lp\n", &a01);
	test_uns_int("3l--->_%07.510lp\n", &a01);
	test_uns_int("3l--->_%07.56lp\n", &a01);
	test_uns_int("3l--->_%08.53lp\n", &a01);

	test_uns_int("4l--->_%+7lp\n", &a01);
	test_uns_int("4l--->_%+7.5lp\n", &a01); // 1
	test_uns_int("4l--->_%+7.510lp\n", &a01);
	test_uns_int("4l--->_%+7.56lp\n", &a01);
	test_uns_int("4l--->_%+8.53lp\n", &a01);

	test_uns_int("5l--->_%+075lp\n", &a01);
	test_uns_int("5l--->_%+075.lp\n", &a01); // 2
	test_uns_int("5l--->_%+075.10lp\n", &a01);
	test_uns_int("5l--->_%+075.6lp\n", &a01);
	test_uns_int("5l--->_%+085.3lp\n", &a01);

	test_uns_int("6l--->_%+ 75lp\n", &a01);
	test_uns_int("6l--->_%+ 75.lp\n", &a01);
	test_uns_int("6l--->_%+ 75.10lp\n", &a01);
	test_uns_int("6l--->_%+ 75.6lp\n", &a01);
	test_uns_int("6l--->_%+ 85.3lp\n", &a01);

	test_uns_int("7l--->_% +057lp\n", &a01);
	test_uns_int("7l--->_% +057.lp\n", &a01); // 3
	test_uns_int("7l--->_% +057.10lp\n", &a01);
	test_uns_int("7l--->_% +057.6lp\n", &a01);
	test_uns_int("7l--->_% +058.3lp\n", &a01);

	test_uns_int("8l--->_%- 057lp\n", &a01);
	test_uns_int("8l--->_%- 057.lp\n", &a01);
	test_uns_int("8l--->_%- 057.10lp\n", &a01);
	test_uns_int("8l--->_%- 057.6lp\n", &a01);
	test_uns_int("8l--->_%- 058.3lp\n", &a01);

	printf("------------------------ll----UNSIGNED---INTEGER----ll-------------------->\n");

	test_uns_int("1ll--->_%-7llp\n", &a01);
	test_uns_int("1ll--->_%-7.5llp\n", &a01);
	test_uns_int("1ll--->_%-7.510llp\n", &a01);
	test_uns_int("1ll--->_%-7.56llp\n", &a01);
	test_uns_int("1ll--->_%-8.53llp\n", &a01);

	test_uns_int("2ll--->_%7llp\n", &a01);
	test_uns_int("2ll--->_%7.llp\n", &a01);
	test_uns_int("2ll--->_%7.150llp\n", &a01);
	test_uns_int("2ll--->_%7.65llp\n", &a01);
	test_uns_int("2ll--->_%8.35llp\n", &a01);

	test_uns_int("3ll--->_%07llp\n", &a01);
	test_uns_int("3ll--->_%07.5llp\n", &a01);
	test_uns_int("3ll--->_%07.510llp\n", &a01);
	test_uns_int("3ll--->_%07.56llp\n", &a01);
	test_uns_int("3ll--->_%08.53llp\n", &a01);

	test_uns_int("4ll--->_%+7llp\n", &a01);
	test_uns_int("4ll--->_%+7.5llp\n", &a01); // 1
	test_uns_int("4ll--->_%+7.510llp\n", &a01);
	test_uns_int("4ll--->_%+7.56llp\n", &a01);
	test_uns_int("4ll--->_%+8.53llp\n", &a01);

	test_uns_int("5ll--->_%+075llp\n", &a01);
	test_uns_int("5ll--->_%+075.llp\n", &a01); // 2
	test_uns_int("5ll--->_%+075.10llp\n", &a01);
	test_uns_int("5ll--->_%+075.6llp\n", &a01);
	test_uns_int("5ll--->_%+085.3llp\n", &a01);

	test_uns_int("6ll--->_%+ 75llp\n", &a01);
	test_uns_int("6ll--->_%+ 75.llp\n", &a01);
	test_uns_int("6ll--->_%+ 75.10llp\n", &a01);
	test_uns_int("6ll--->_%+ 75.6llp\n", &a01);
	test_uns_int("6ll--->_%+ 85.3llp\n", &a01);

	test_uns_int("7ll--->_% +057llp\n", &a01);
	test_uns_int("7ll--->_% +057.llp\n", &a01); // 3
	test_uns_int("7ll--->_% +057.10llp\n", &a01);
	test_uns_int("7ll--->_% +057.6llp\n", &a01);
	test_uns_int("7ll--->_% +058.3llp\n", &a01);

	test_uns_int("8ll--->_%- 057llp\n", &a01);
	test_uns_int("8ll--->_%- 057.llp\n", &a01);
	test_uns_int("8ll--->_%- 057.10llp\n", &a01);
	test_uns_int("8ll--->_%- 057.6llp\n", &a01);
	test_uns_int("8ll--->_%- 058.3llp\n", &a01);

}

void	test_unsig_int_arg2(ULL_int num)
{
	static char	a01;
	printf("------------------------h----UNSIGNED---INTEGER----h-------------------->\n");

	test_uns_int("1h--->_%-7hp\n", &a01);
	test_uns_int("1h--->_%-7.5hp\n", &a01);
	test_uns_int("1h--->_%-7.510hp\n", &a01);
	test_uns_int("1h--->_%-7.56hp\n", &a01);
	test_uns_int("1h--->_%-8.53hp\n", &a01);

	test_uns_int("2h--->_%7hp\n", &a01);
	test_uns_int("2h--->_%7.hp\n", &a01);
	test_uns_int("2h--->_%7.150hp\n", &a01);
	test_uns_int("2h--->_%7.65hp\n", &a01);
	test_uns_int("2h--->_%8.35hp\n", &a01);

	test_uns_int("3h--->_%07hp\n", &a01);
	test_uns_int("3h--->_%07.hp\n", &a01);
	test_uns_int("3h--->_%07.510hp\n", &a01);
	test_uns_int("3h--->_%07.56hp\n", &a01);
	test_uns_int("3h--->_%08.53hp\n", &a01);

	test_uns_int("4h--->_%+7hp\n", &a01);
	test_uns_int("4h--->_%+7.5hp\n", &a01); // 1
	test_uns_int("4h--->_%+7.510hp\n", &a01);
	test_uns_int("4h--->_%+7.56hp\n", &a01);
	test_uns_int("4h--->_%+8.53hp\n", &a01);

	test_uns_int("5h--->_%+075hp\n", &a01);
	test_uns_int("5h--->_%+075.hp\n", &a01); // 2
	test_uns_int("5h--->_%+075.10hp\n", &a01);
	test_uns_int("5h--->_%+075.6hp\n", &a01);
	test_uns_int("5h--->_%+085.3hp\n", &a01);

	test_uns_int("6h--->_%+ 75hp\n", &a01);
	test_uns_int("6h--->_%+ 75.hp\n", &a01);
	test_uns_int("6h--->_%+ 75.10hp\n", &a01);
	test_uns_int("6h--->_%+ 75.6hp\n", &a01);
	test_uns_int("6h--->_%+ 85.3hp\n", &a01);

	test_uns_int("7h--->_% +057hp\n", &a01);
	test_uns_int("7h--->_% +057.hp\n", &a01); // 3
	test_uns_int("7h--->_% +057.10hp\n", &a01);
	test_uns_int("7h--->_% +057.6hp\n", &a01);
	test_uns_int("7h--->_% +058.3hp\n", &a01);

	test_uns_int("8h--->_%- 057hp\n", &a01);
	test_uns_int("8h--->_%- 057.hp\n", &a01);
	test_uns_int("8h--->_%- 057.10hp\n", &a01);
	test_uns_int("8h--->_%- 057.6hp\n", &a01);
	test_uns_int("8h--->_%- 058.3hp\n", &a01);

	printf("------------------------hh----UNSIGNED---INTEGER----hh-------------------->\n");

	test_uns_int("1hh--->_%-7hhp\n", &a01);
	test_uns_int("1hh--->_%-7.5hhp\n", &a01);
	test_uns_int("1hh--->_%-7.510hhp\n", &a01);
	test_uns_int("1hh--->_%-7.56hhp\n", &a01);
	test_uns_int("1hh--->_%-8.53hhp\n", &a01);

	test_uns_int("2hh--->_%7hhp\n", &a01);
	test_uns_int("2hh--->_%7.hhp\n", &a01);
	test_uns_int("2hh--->_%7.150hhp\n", &a01);
	test_uns_int("2hh--->_%7.65hhp\n", &a01);
	test_uns_int("2hh--->_%8.35hhp\n", &a01);

	test_uns_int("3hh--->_%07hhp\n", &a01);
	test_uns_int("3hh--->_%07.5hhp\n", &a01);
	test_uns_int("3hh--->_%07.510hhp\n", &a01);
	test_uns_int("3hh--->_%07.56hhp\n", &a01);
	test_uns_int("3hh--->_%08.53hhp\n", &a01);

	test_uns_int("4hh--->_%+7hhp\n", &a01);
	test_uns_int("4hh--->_%+7.5hhp\n", &a01); // 1
	test_uns_int("4hh--->_%+7.510hhp\n", &a01);
	test_uns_int("4hh--->_%+7.56hhp\n", &a01);
	test_uns_int("4hh--->_%+8.53hhp\n", &a01);

	test_uns_int("5hh--->_%+075hhp\n", &a01);
	test_uns_int("5hh--->_%+075.hhp\n", &a01); // 2
	test_uns_int("5hh--->_%+075.10hhp\n", &a01);
	test_uns_int("5hh--->_%+075.6hhp\n", &a01);
	test_uns_int("5hh--->_%+085.3hhp\n", &a01);

	test_uns_int("6hh--->_%+ 75hhp\n", &a01);
	test_uns_int("6hh--->_%+ 75.hhp\n", &a01);
	test_uns_int("6hh--->_%+ 75.10hhp\n", &a01);
	test_uns_int("6hh--->_%+ 75.6hhp\n", &a01);
	test_uns_int("6hh--->_%+ 85.3hhp\n", &a01);

	test_uns_int("7hh--->_% +057hhp\n", &a01);
	test_uns_int("7hh--->_% +057.hhp\n", &a01); // 3
	test_uns_int("7hh--->_% +057.10hhp\n", &a01);
	test_uns_int("7hh--->_% +057.6hhp\n", &a01);
	test_uns_int("7hh--->_% +058.3hhp\n", &a01);

	test_uns_int("8hh--->_%- 057hhp\n", &a01);
	test_uns_int("8hh--->_%- 057.hhp\n", &a01);
	test_uns_int("8hh--->_%- 057.10hhp\n", &a01);
	test_uns_int("8hh--->_%- 057.6hhp\n", &a01);
	test_uns_int("8hh--->_%- 058.3hhp\n", &a01);

	printf("------------------------L----UNSIGNED---INTEGER----L-------------------->\n");

	test_uns_int("1L--->_%-7Lp\n", &a01);
	test_uns_int("1L--->_%-7.5Lp\n", &a01);
	test_uns_int("1L--->_%-7.510Lp\n", &a01);
	test_uns_int("1L--->_%-7.56Lp\n", &a01);
	test_uns_int("1L--->_%-8.53Lp\n", &a01);

	test_uns_int("2L--->_%7Lp5\n", &a01);
	test_uns_int("2L--->_%7.Lp\n", &a01);
	test_uns_int("2L--->_%7.150Lp\n", &a01);
	test_uns_int("2L--->_%7.65Lp\n", &a01);
	test_uns_int("2L--->_%8.35Lp\n", &a01);

	test_uns_int("3L--->_%07Lp\n", &a01);
	test_uns_int("3L--->_%07.5Lp\n", &a01);
	test_uns_int("3L--->_%07.510Lp\n", &a01);
	test_uns_int("3L--->_%07.56Lp\n", &a01);
	test_uns_int("3L--->_%08.53Lp\n", &a01);

	test_uns_int("4L--->_%+7Lp\n", &a01);
	test_uns_int("4L--->_%+7.Lp\n", &a01); // 1
	test_uns_int("4L--->_%+7.510Lp\n", &a01);
	test_uns_int("4L--->_%+7.56Lp\n", &a01);
	test_uns_int("4L--->_%+8.53Lp\n", &a01);

	test_uns_int("5L--->_%+075Lp\n", &a01);
	test_uns_int("5L--->_%+075.Lp\n", &a01); // 2
	test_uns_int("5L--->_%+075.10Lp\n", &a01);
	test_uns_int("5L--->_%+075.6Lp\n", &a01);
	test_uns_int("5L--->_%+085.3Lp\n", &a01);

	test_uns_int("6L--->_%+ 75Lp\n", &a01);
	test_uns_int("6L--->_%+ 75.Lp\n", &a01);
	test_uns_int("6L--->_%+ 75.10Lp\n", &a01);
	test_uns_int("6L--->_%+ 75.6Lp\n", &a01);
	test_uns_int("6L--->_%+ 85.3Lp\n", &a01);

	test_uns_int("7L--->_% +057Lp\n", &a01);
	test_uns_int("7L--->_% +057.Lp\n", &a01); // 3
	test_uns_int("7L--->_% +057.10Lp\n", &a01);
	test_uns_int("7L--->_% +057.6Lp\n", &a01);
	test_uns_int("7L--->_% +058.3Lp\n", &a01);

	test_uns_int("8L--->_%- 057Lp\n", &a01);
	test_uns_int("8L--->_%- 057.Lp\n", &a01);
	test_uns_int("8L--->_%- 057.10Lp\n", &a01);
	test_uns_int("8L--->_%- 057.6Lp\n", &a01);
	test_uns_int("8L--->_%- 058.3Lp\n", &a01);
}