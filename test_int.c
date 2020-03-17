#include "ft_printf.h"

void	test_int(char *str, int64_t num)
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

void	test_int_arg1(int64_t num)
{
	// printf("----------------------------INTEGER------------------------>\n");
	// test_int("%.0d", 0);
	// test_int("1--->_%#-7o\n", num);
	// test_int("1--->_%#-7.o\n", num);
	// test_int("1--->_%#-7.10o\n", num);
	// test_int("1--->_%#-7.6o\n", num);
	// test_int("1--->_%#-8.3o\n", num);

	// test_int("2--->_%#7o\n", num);
	// test_int("2--->_%#7.o\n", num);
	// test_int("2--->_%#7.10o\n", num);
	// test_int("2--->_%#7.6o\n", num);
	// test_int("2--->_%#8.3o\n", num);

	// test_int("3--->_%#07o\n", num);
	// test_int("3--->_%#07.o\n", num);
	// test_int("3--->_%#07.10o\n", num);
	// test_int("3--->_%#07.6o\n", num);
	// test_int("3--->_%#08.3o\n", num);
	
	// test_int("4--->_%#7o\n", num);
	// test_int("4--->_%#7.o\n", num); // 1
	// test_int("4--->_%#7.10o\n", num);
	// test_int("4--->_%#7.6o\n", num);
	// test_int("4--->_%#8.3o\n", num);

	// test_int("5--->_%#07o\n", num);
	// test_int("5--->_%#07.o\n", num); // 2
	// test_int("5--->_%#07.10o\n", num);
	// test_int("5--->_%#07.6o\n", num);
	// test_int("5--->_%#08.3o\n", num);

	// test_int("6--->_%# 7o\n", num);
	// test_int("6--->_%# 7.o\n", num);
	// test_int("6--->_%# 7.10o\n", num);
	// test_int("6--->_%# 7.6o\n", num);
	// test_int("6--->_%# 8.3o\n", num);

	// test_int("7--->_% #07o\n", num);
	// test_int("7--->_% #07.o\n", num); // 3
	// test_int("7--->_% #07.10o\n", num);
	// test_int("7--->_% #07.6o\n", num);
	// test_int("7--->_% #08.3o\n", num);

	// test_int("8--->_%- #07o\n", num);
	// test_int("8--->_%- #07.o\n", num);
	// test_int("8--->_%- #07.10o\n", num);
	// test_int("8--->_%- #07.6o\n", num);
	// test_int("8--->_%- #08.3o\n", num);

	// printf("-----------------------l-----INTEGER----l-------------------->\n");

	// test_int("1l--->_%#-7lo\n", num);
	// test_int("1l--->_%#-7.lo\n", num);
	// test_int("1l--->_%#-7.10lo\n", num);
	// test_int("1l--->_%#-7.6lo\n", num);
	// test_int("1l--->_%#-8.3lo\n", num);

	// test_int("2l--->_%#7lo\n", num);
	// test_int("2l--->_%#7.lo\n", num);
	// test_int("2l--->_%#7.10lo\n", num);
	// test_int("2l--->_%#7.6lo\n", num);
	// test_int("2l--->_%#8.3lo\n", num);

	// test_int("3l--->_%#07lo\n", num);
	// test_int("3l--->_%#07.lo\n", num);
	// test_int("3l--->_%#07.10lo\n", num);
	// test_int("3l--->_%#07.6lo\n", num);
	// test_int("3l--->_%#08.3lo\n", num);	
	
	// test_int("4l--->_%#7lo\n", num);
	// test_int("4l--->_%#7.lo\n", num); // 1
	// test_int("4l--->_%#7.10lo\n", num);
	// test_int("4l--->_%#7.6lo\n", num);
	// test_int("4l--->_%#8.3lo\n", num);
	
	// test_int("5l--->_%#07lo\n", num);
	// test_int("5l--->_%#07.lo\n", num); // 2
	// test_int("5l--->_%#07.10lo\n", num);
	// test_int("5l--->_%#07.6lo\n", num);
	// test_int("5l--->_%#08.3lo\n", num);
	
	// test_int("6l--->_%# 7lo\n", num);
	// test_int("6l--->_%# 7.lo\n", num);
	// test_int("6l--->_%# 7.10lo\n", num);
	// test_int("6l--->_%# 7.6lo\n", num);
	// test_int("6l--->_%# 8.3lo\n", num);
	
	// test_int("7l--->_% #07lo\n", num);
	// test_int("7l--->_% #07.lo\n", num); // 3
	// test_int("7l--->_% #07.10lo\n", num);
	// test_int("7l--->_% #07.6lo\n", num);
	// test_int("7l--->_% #08.3lo\n", num);
	
	// test_int("8l--->_%- 07lo\n", num);
	// test_int("8l--->_%- 07.lo\n", num);
	// test_int("8l--->_%- 07.10lo\n", num);
	// test_int("8l--->_%- 07.6lo\n", num);
	// test_int("8l--->_%- 08.3lo\n", num);

	printf("-----------------------ll-----INTEGER----ll-------------------->\n");

	// test_int("1ll--->_%#-7llo\n", num);
	test_int("1ll--->_%#-7.llo\n", num);
	// test_int("1ll--->_%#-7.10llo\n", num);
	// test_int("1ll--->_%#-7.6llo\n", num);
	// test_int("1ll--->_%#-8.3llo\n", num);

	// test_int("2ll--->_%#7llo\n", num);
	test_int("2ll--->_%#7.llo\n", num);
	// test_int("2ll--->_%#7.10llo\n", num);
	// test_int("2ll--->_%#7.6llo\n", num);
	// test_int("2ll--->_%#8.3llo\n", num);

	// test_int("3ll--->_%#07llo\n", num);
	test_int("3ll--->_%#07.llo\n", num);
	// test_int("3ll--->_%#07.10llo\n", num);
	// test_int("3ll--->_%#07.6llo\n", num);
	// test_int("3ll--->_%#08.3llo\n", num);
	
	// test_int("4ll--->_%#7llo\n", num);
	test_int("4ll--->_%#7.llo\n", num); // 1
	// test_int("4ll--->_%#7.10llo\n", num);
	// test_int("4ll--->_%#7.6llo\n", num);
	// test_int("4ll--->_%#8.3llo\n", num);
	
	// test_int("5ll--->_%#07llo\n", num);
	test_int("5ll--->_%#07.llo\n", num); // 2
	// test_int("5ll--->_%#07.10llo\n", num);
	// test_int("5ll--->_%#07.6llo\n", num);
	// test_int("5ll--->_%#08.3llo\n", num);
	
	// test_int("6ll--->_%# 7llo\n", num);
	test_int("6ll--->_%# 7.llo\n", num);
	// test_int("6ll--->_%# 7.10llo\n", num);
	// test_int("6ll--->_%# 7.6llo\n", num);
	// test_int("6ll--->_%# 8.3llo\n", num);
	
	// test_int("7ll--->_% #07llo\n", num);
	test_int("7ll--->_% #07.llo\n", num); // 3
	// test_int("7ll--->_% #07.10llo\n", num);
	// test_int("7ll--->_% #07.6llo\n", num);
	// test_int("7ll--->_% #08.3llo\n", num);
	
	// test_int("8ll--->_%- #07llo\n", num);
	test_int("8ll--->_%- #07.llo\n", num);
	// test_int("8ll--->_%- #07.10llo\n", num);
	// test_int("8ll--->_%- #07.6llo\n", num);
	// test_int("8ll--->_%- #08.3llo\n", num);
}































void	test_int_arg2(int64_t num)
{
	printf("-----------------------L-----INTEGER----L-------------------->\n");

	test_int("1L--->_%-7Lo\n", num);
	test_int("1L--->_%-7.Lo\n", num);
	test_int("1L--->_%-7.10Lo\n", num);
	test_int("1L--->_%-7.6Lo\n", num);
	test_int("1L--->_%-8.3Lo\n", num);
	
	test_int("2L--->_%7Lo\n", num);
	test_int("2L--->_%7.Lo\n", num);
	test_int("2L--->_%7.10Lo\n", num);
	test_int("2L--->_%7.6Lo\n", num);
	test_int("2L--->_%8.3Lo\n", num);
	
	test_int("3L--->_%07Lo\n", num);
	test_int("3L--->_%07.Lo\n", num);
	test_int("3L--->_%07.10Lo\n", num);
	test_int("3L--->_%07.6Lo\n", num);
	test_int("3L--->_%08.3Lo\n", num);
	test_int("4L--->_%#7Lo\n", num);
	
	test_int("4L--->_%#7.Lo\n", num); // 1
	test_int("4L--->_%#7.10Lo\n", num);
	test_int("4L--->_%#7.6Lo\n", num);
	test_int("4L--->_%#8.3Lo\n", num);
	
	test_int("5L--->_%#07Lo\n", num);
	test_int("5L--->_%#07.Lo\n", num); // 2
	test_int("5L--->_%#07.10Lo\n", num);
	test_int("5L--->_%#07.6Lo\n", num);
	test_int("5L--->_%#08.3Lo\n", num);
	
	test_int("6L--->_%# 7Lo\n", num);
	test_int("6L--->_%# 7.Lo\n", num);
	test_int("6L--->_%# 7.10Lo\n", num);
	test_int("6L--->_%# 7.6Lo\n", num);
	test_int("6L--->_%# 8.3Lo\n", num);
	
	test_int("7L--->_% #07Lo\n", num);
	test_int("7L--->_% #07.Lo\n", num); // 3
	test_int("7L--->_% #07.10Lo\n", num);
	test_int("7L--->_% #07.6Lo\n", num);
	test_int("7L--->_% #08.3Lo\n", num);
	
	test_int("8L--->_%- 07Lo\n", num);
	test_int("8L--->_%- 07.Lo\n", num);
	test_int("8L--->_%- 07.10Lo\n", num);
	test_int("8L--->_%- 07.6Lo\n", num);
	test_int("8L--->_%- 08.3Lo\n", num);

	printf("-----------------------h-----INTEGER----h-------------------->\n");

	test_int("1h--->_%-7ho\n", num);
	test_int("1h--->_%-7.ho\n", num);
	test_int("1h--->_%-7.10ho\n", num);
	test_int("1h--->_%-7.6ho\n", num);
	test_int("1h--->_%-8.3ho\n", num);
	
	test_int("2h--->_%7ho\n", num);
	test_int("2h--->_%7.ho\n", num);
	test_int("2h--->_%7.10ho\n", num);
	test_int("2h--->_%7.6ho\n", num);
	test_int("2h--->_%8.3ho\n", num);
	
	test_int("3h--->_%07ho\n", num);
	test_int("3h--->_%07.ho\n", num);
	test_int("3h--->_%07.10ho\n", num);
	test_int("3h--->_%07.6ho\n", num);
	test_int("3h--->_%08.3ho\n", num);
	
	test_int("4h--->_%#7ho\n", num);
	test_int("4h--->_%#7.ho\n", num); // 1
	test_int("4h--->_%#7.10ho\n", num);
	test_int("4h--->_%#7.6ho\n", num);
	test_int("4h--->_%#8.3ho\n", num);
	
	test_int("5h--->_%#07ho\n", num);
	test_int("5h--->_%#07.ho\n", num); // 2
	test_int("5h--->_%#07.10ho\n", num);
	test_int("5h--->_%#07.6ho\n", num);
	test_int("5h--->_%#08.3ho\n", num);
	
	test_int("6h--->_%# 7ho\n", num);
	test_int("6h--->_%# 7.ho\n", num);
	test_int("6h--->_%# 7.10ho\n", num);
	test_int("6h--->_%# 7.6ho\n", num);
	test_int("6h--->_%# 8.3ho\n", num);
	
	test_int("7h--->_% #07ho\n", num);
	test_int("7h--->_% #07.ho\n", num); // 3
	test_int("7h--->_% #07.10ho\n", num);
	test_int("7h--->_% #07.6ho\n", num);
	test_int("7h--->_% #08.3ho\n", num);
	
	test_int("8h--->_%- 07ho\n", num);
	test_int("8h--->_%- 07.ho\n", num);
	test_int("8h--->_%- 07.10ho\n", num);
	test_int("8h--->_%- 07.6ho\n", num);
	test_int("8h--->_%- 08.3ho\n", num);

	printf("-----------------------hh-----INTEGER----hh-------------------->\n");

	test_int("1hh--->_%-7hho\n", num);
	test_int("1hh--->_%-7.hho\n", num);
	test_int("1hh--->_%-7.10hho\n", num);
	test_int("1hh--->_%-7.6hho\n", num);
	test_int("1hh--->_%-8.3hho\n", num);

	test_int("2hh--->_%7hho\n", num);
	test_int("2hh--->_%7.hho\n", num);
	test_int("2hh--->_%7.10hho\n", num);
	test_int("2hh--->_%7.6hho\n", num);
	test_int("2hh--->_%8.3hho\n", num);

	test_int("3hh--->_%07hho\n", num);
	test_int("3hh--->_%07.hho\n", num);
	test_int("3hh--->_%07.10hho\n", num);
	test_int("3hh--->_%07.6hho\n", num);
	test_int("3hh--->_%08.3hho\n", num);

	test_int("4hh--->_%#7hho\n", num);
	test_int("4hh--->_%#7.hho\n", num); // 1
	test_int("4hh--->_%#7.10hho\n", num);
	test_int("4hh--->_%#7.6hho\n", num);
	test_int("4hh--->_%#8.3hho\n", num);

	test_int("5hh--->_%#07hho\n", num);
	test_int("5hh--->_%#07.hho\n", num); // 2
	test_int("5hh--->_%#07.10hho\n", num);
	test_int("5hh--->_%#07.6hho\n", num);
	test_int("5hh--->_%#08.3hho\n", num);

	test_int("6hh--->_%# 7hho\n", num);
	test_int("6hh--->_%# 7.hho\n", num);
	test_int("6hh--->_%# 7.10hho\n", num);
	test_int("6hh--->_%# 7.6hho\n", num);
	test_int("6hh--->_%# 8.3hho\n", num);

	test_int("7hh--->_% #07hho\n", num);
	test_int("7hh--->_% #07.hho\n", num); // 3
	test_int("7hh--->_% #07.10hho\n", num);
	test_int("7hh--->_% #07.6hho\n", num);
	test_int("7hh--->_% #08.3hho\n", num);

	test_int("8hh--->_%- 07hho\n", num);
	test_int("8hh--->_%- 07.hho\n", num);
	test_int("8hh--->_%- 07.10hho\n", num);
	test_int("8hh--->_%- 07.6hho\n", num);
	test_int("8hh--->_%- 08.3hho\n", num);
}