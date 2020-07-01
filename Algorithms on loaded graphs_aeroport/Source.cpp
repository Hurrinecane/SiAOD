/*
6. Имеются расписания вылетов самолетов в ряде аэропортов.
Требуется по начальному и конечному пунктам предложить маршрут с возможными пересадками, оптимальный по одному из следующих критериев:
а) наименьшая суммарная стоимость билетов;
б) минимальное суммарное расстояние.
При выборе маршрута считать, что пересадка допустима, если интервал времени между прилетом самолета и последующем вылетом составляет не менее 2 часов.
*/

#include <iostream>
#include <string>
#include <fstream>

int string_to_int(std::string s)
{
	int num = 0;
	for (int i = 0; i < s.length(); ++i) {
		num *= 10;
		num += s[i] - '0';
	}
	return num;
}

int main()
{
	int flights[5][5] = {};
	int flights_info[5][5] = {};

	std::ifstream f_flights("flights.txt");
	while (!f_flights.eof())
	{
		int number;
		f_flights >> number;

		f_flights.get();
		std::string s;
		std::getline(f_flights, s);
		int space = 0;
		int num = 0;
		while ((space = s.find(" ")) != -1) {
			num = string_to_int(s.substr(0, space));
			flights[number][num] = 1;
			s = s.substr(space + 1);
		}
		num = string_to_int(s.substr(0, space));

		flights[number][num] = 1;
	}
	f_flights.close();

	printf("# ");
	for (int i = 0; i < 5; ++i)
		printf("%d ", i);
	printf("\n");

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", i);
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ", flights[i][j]);
		}
		printf("\n");
	}

	f_flights.open("flights_info.txt");
	while (!f_flights.eof())
	{
		int first;
		f_flights >> first;

		f_flights.get();
		std::string s;
		std::getline(f_flights, s);
		int space = 0;
		int second = 0;
		int dist = 0;
		while ((space = s.find(" ")) != -1) {

			second = string_to_int(s.substr(0, space));

			s = s.substr(space + 1);
			dist = string_to_int(s);

			flights_info[first][second] = dist;
		}
	}
	f_flights.close();

	printf("\n# ");
	for (int i = 0; i < 5; ++i)
		printf("%d ", i);
	printf("\n");

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", i);
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ", flights_info[i][j]);
		}
		printf("\n");
	}
}