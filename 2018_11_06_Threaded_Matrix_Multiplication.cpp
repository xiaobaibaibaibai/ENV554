#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void multiply(int a[][80], int b[][150], int c[][150], int i1, int i2, int j1, int j2, int k)
{
	int i, j, m;
	int ret = 0;
	for (i = i1; i <= i2; i++)
		for (j = j1; j <= j2; j++) {
			ret = 0;
			for (m = 0; m < k; m++) ret += a[i][m] * b[m][j];
			c[i][j] = ret;
		}
}


void multiply1(int a[][8], int b[][15], int c[][15], int i1, int i2, int j1, int j2, int k)
{
	int i, j, m;
	int ret = 0;
	for (i = i1; i <= i2; i++)
		for (j = j1; j <= j2; j++) {
			ret = 0;
			for (m = 0; m < k; m++) ret += a[i][m] * b[m][j];
			c[i][j] = ret;
		}
}

int main() {
	int i, j;

	/*
	int a[100][80];
	int b[80][150];
	int c[100][150];
	for (i = 0; i < 100; i++)
		for (j = 0; j < 80; j++)
			a[i][j] = 1;
	for (i = 0; i < 80; i++)
		for (j = 0; j < 150; j++)
			b[i][j] = 1;
	//multiply(a, b, c, 0,100,0,150,80);
	thread t1(multiply, a, b, c, 0, 49, 0, 74, 80);
	thread t2(multiply, a, b, c, 0, 49, 75, 149, 80);
	thread t3(multiply, a, b, c, 50, 99, 0, 74, 80);
	thread t4(multiply, a, b, c, 50, 99, 75, 149, 80);
	*/

	int a[10][8];
	int b[8][15];
	int c[10][15];
	for (i = 0; i < 10; i++)
		for (j = 0; j < 8; j++)
			a[i][j] = 1;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 15; j++)
			b[i][j] = 1;

	thread t1(multiply1, a, b, c, 0, 4, 0, 7, 8);
	thread t2(multiply1, a, b, c, 0, 4, 8, 14, 8);
	thread t3(multiply1, a, b, c, 5, 9, 0, 7, 8);
	thread t4(multiply1, a, b, c, 5, 9, 8, 14, 8);

	t1.join();
	t2.join();
	t3.join();
	t4.join();


	for (i = 0; i < 10; i++)
	{
		cout << endl;
		for (j = 0; j < 15; j++)
			cout << "  " << c[i][j];
	}

	getchar();
	getchar();
	return 0;
}
