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
int menu();
void printmenu();
void printingamemenu();
void printpetstatus(int,int,int,int,int,double);
bool rusure();
void loadgame(bool,std::string);
class pet
{
	public:
	int hngr, mood, skil, hlth, enrg;
	double time,age;
	static int action(int*,double,int);
};