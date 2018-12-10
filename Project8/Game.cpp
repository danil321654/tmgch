#include"fandc.h"
std::string gampr() 
{
	system("cls");
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	bufferSize.X = 20;
	bufferSize.Y = 11; //izmenenie koordinat tochki
	SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
	std::cout << "Name your pet: " << std::endl;
	std::string a;
	bufferSize.X = 36;
	bufferSize.Y = 11;
	SetConsoleCursorPosition(hWnd, bufferSize);
	getline(std::cin, a);
	system("cls");
	return a;

}
std::string *game::loadgame(bool x,std::string fname)
{
	system("cls");

	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	if (x==1)
	{
		fname = fname + ".txt";
		const char * finame = fname.c_str();
		std::ifstream file;
		file.open(finame);

		if (file)
		{
			char c = 0;
			while (c != 13)
				{
				bufferSize.X = 35;
				bufferSize.Y = 11; //izmenenie koordinat tochki
				SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
				std::cout << "There is already pet with that name" << std::endl;
				bufferSize.X = 40;
				bufferSize.Y = 13; //izmenenie koordinat tochki
				SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
				std::cout << "Overwrite old pet?" << std::endl;
					bufferSize.X = 20;
					bufferSize.Y = 17;
					SetConsoleCursorPosition(hWnd, bufferSize);
					std::cout << "YES										NO" << std::endl;
					bufferSize.X = 24;
					if (c == 75) if (bufferSize.X != 24) bufferSize.X = 24;
					if (c == 77) if (bufferSize.X != 76) bufferSize.X = 99;
					SetConsoleCursorPosition(hWnd, bufferSize);
					std::cout << "<<<<<<<<<<<<" << std::endl;
					c = _getch();
					system("cls");

				}
			if (bufferSize.X != 24) menu(); 
		}
		
		std::ofstream file1(fname);
		std::string *b = &fname;
	}
	else
	{
			bufferSize.X = 20;
			bufferSize.Y = 11; //izmenenie koordinat tochki
			SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
			std::cout << "What is name of your pet?" << std::endl;
		std::string a;
		bufferSize.X = 49;
		SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
		getline(std::cin, a);
		std::string *b = &a;
		*b = *b + ".txt";
		const char * finame = a.c_str();
		std::ifstream file1;
		file1.open(finame);
		if (!file1) 
		{
			system("cls");
			bufferSize.X = 20;
			bufferSize.Y = 11; //izmenenie koordinat tochki
			SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
			std::cout << "There's no such pet!!!!" << std::endl;
			char c = 0;
			while (c != 13) c = _getch();
			menu();
			return 0;
		}
	}
	bufferSize.X = 40;
	bufferSize.Y = 5;

	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << fname;
	ava();
}

/*int pet::action(int *a, double tm, int)
{

}*/