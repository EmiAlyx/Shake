#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
#define WID 100
#define GOALS "goals.txt"
#define HIG 25
struct body {
	int x;
	int y;
};
class snake {
public:
	struct body b1[20*60];
	int length;
	snake();
	void reset();
	void get_long();
	bool ifclash();

};
class food {
public:
	int x;
	int y;
	food();
	food(body[],int);
	void reset(body[], int);
};