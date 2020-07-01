#include <string>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int const max_students = 10;
int N = 0;
string names[max_students];
int friends[max_students][max_students];

void initialize_array(int(&arr)[max_students][max_students], int max_num) {
	for (int i = 0; i < max_num; ++i) {
		for (int j = 0; j < max_num; ++j) {
			arr[i][j] = 0;
		}
	}
}

int string_to_int(string s) {
	int num = 0;
	for (int i = 0; i < s.length(); ++i) {
		num *= 10;
		num += s[i] - '0';
	}
	return num;
}

int Breadth_Friend_Search(int first, int second)
{
	int* List = new int[max_students];
	int Count, Head;
	int i;
	int depth = 0;
	bool visited[max_students] = {};

	for (i = 0; i < max_students; i++)
		List[i] = 0;
	Count = Head = 0;

	List[Count++] = first;
	visited[first] = true;
	while (Head < Count)
	{
		first = List[Head++];
		cout << first + 1 << endl;

		for (i = 0; i < max_students; i++)
			if (friends[first][i] && !visited[i])
			{
				if (i == second)
					return depth;

				List[Count++] = i;
				visited[i] = true;
			}
		depth++;
	}
}

int find_number_of_student(string st) {
	for (int i = 0; i < N; ++i) {
		if (names[i] == st) return i;
	}
	return -1;
}

int main()
{
	ifstream f_names("students.txt");
	while (!f_names.eof()) {
		int number;
		f_names >> number;
		f_names.get();
		string student;
		f_names >> student;

		if (student == "") continue;

		names[number] = student;
		cout << "Students " << student << "\n";
		cout << "number " << number << "\n";
		++N;
	}

	ifstream f_friends("friends.txt");
	while (!f_friends.eof()) {
		int number;
		f_friends >> number;


		f_friends.get();
		string s;
		getline(f_friends, s);
		int space = 0;
		int num = 0;
		while ((space = s.find(" ")) != -1) {
			num = string_to_int(s.substr(0, space));
			friends[number][num] = 1;
			s = s.substr(space + 1);
		}
		num = string_to_int(s.substr(0, space));

		friends[number][num] = 1;
	}

	printf("# ");


	for (int i = 0; i < max_students; ++i)
		printf("%d ", i);
	printf("\n");


	for (int i = 0; i < max_students; ++i)
	{
		printf("%d ", i);
		for (int j = 0; j < max_students; ++j)
		{
			printf("%d ", friends[i][j]);
		}
		printf("\n");

	}

	while (true)
	{
		string st1, st2;
		int st1_num;
		int st2_num;

		do
		{
			cout << "Input name of first student: ";
			cin >> st1;
			st1_num = find_number_of_student(st1);
			if (st1_num == -1)
				cout << "Incorrect name" << endl;
		} while (st1_num == -1);
		do
		{
			cout << "Input name of second student: ";
			cin >> st2;
			st2_num = find_number_of_student(st2);
			if (st2_num == -1)
				cout << "Incorrect name" << endl;
		} while (st2_num == -1);

		int path[max_students];
		for (int i = 0; i < max_students; i++)
			path[i] = friends[st1_num][i];

		int depth;
		depth = Breadth_Friend_Search(st1_num, st2_num);
		cout << "Students " << st1 << " and " << st2 << " are introdused through " << depth << " weeks" << endl;
	}

	return 0;
}