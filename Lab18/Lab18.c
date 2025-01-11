#include <stdio.h>
#include <time.h>
#include <locale.h>

struct tm* mytime;

struct point
{
	float x;
	float y;
	char name;
};

typedef struct point Point;

void put_point(Point z);
float dist(Point z, Point w);

void main()
{
	setlocale(LC_ALL, "RUS");

	Point b, a;

	a = (Point){ 1.f, 2.f, 'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	printf("point %c (%.1f, %.1f)", b.name, b.x, b.y);

	system("pause");

	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("ћосковское врем€ %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

	system("pause");

	printf("до воскресень€ %d дней и %d часов", ((7 - mytime->tm_wday) % 7), (24 - mytime->tm_hour));
}

void put_point(Point z)
{
	printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w)
{
	float one = z.x - w.x;
	float two = z.y - w.y;

	one = pow(one, 2);
	two = pow(two, 2);

	float sum = one + two;
	sum = sqrt(sum);

	return sum;
}
