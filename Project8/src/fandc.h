#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include <io.h>

void loadscreen();
std::string ngame();
std::string shwcat();
std::string shwdog();
bool ava(std::string);
void gamepr(std::string);
class game {
	public: 
	int menu();
	void printmenu();
	bool rusure();
	std::string loadgame(bool,std::string);
};
class pet
{
	public:
	int hngr, mood, skil, hlth;
	double time,age;
	int action(int*,double,int);
};