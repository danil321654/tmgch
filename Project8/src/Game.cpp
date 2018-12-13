#include"fandc.h"
std::string ngame() 
{
	system("cls");
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	bufferSize.X = 20;
	bufferSize.Y = 11; //izmenenie koordinat tochki
	SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
	std::cout << "Name your pet: " << std::endl;
	std::string petname;
	bufferSize.X = 36;
	bufferSize.Y = 11;
	SetConsoleCursorPosition(hWnd, bufferSize);
	getline(std::cin, petname);
	system("cls");
	return petname;

}
void loadgame(bool x,std::string fname)
{
	system("cls");

	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	CreateDirectory("saves", NULL);
	if (x==1)
	{
		
		std::ifstream file;
		std::string fname1 = "saves//" + fname + ".txt";
		const char * finame = fname1.c_str();
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
		
		std::ofstream file1;
		file1.open(finame);
		file1 << ava(fname) << "0 100 0 100 100 0"<< std::endl;
		gamepr(fname);
	}
	else
	{
			bufferSize.X = 20;
			bufferSize.Y = 11; //izmenenie koordinat tochki
			SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
			std::cout << "What is name of your pet?" << std::endl;
		std::string a,d;
		bufferSize.X = 49;
		SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
		getline(std::cin, a);
		d = "saves//" + a + ".txt";
		const char * finame = d.c_str();
		std::ifstream file;
		file.open(finame);
		if (!file) 
		{
			system("cls");
			bufferSize.X = 20;
			bufferSize.Y = 11; //izmenenie koordinat tochki
			SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
			std::cout << "There's no such pet!!!!" << std::endl;
			char c = 0;
			while (c != 13) c = _getch();
			menu();
		}
		gamepr(a);
	}
	
}

int pet::action(int *a, double tm, int)
{
	return 1;
}
void gamepr(std::string fname)
{
	enum actions{ play = 1, feed,cure,train ,sleep};
	std::string fname2 = "saves//" + fname + ".txt";
	const char * filname = fname2.c_str();
	std::ifstream readsv(filname);
	pet tuz;
	bool av;
	std::string pctr;
	readsv >>av>> tuz.hngr >> tuz.mood >> tuz.skil >> tuz.hlth >>tuz.enrg>> tuz.age;
	if (av) pctr = shwcat();
	else pctr = shwdog();
	char prsdkey=0;
	int y=20;
	while (1)
	{
		system("cls");
		setlocale(LC_ALL, "");
		HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
		COORD bufferSize = { 1200, 600 }; //izmenenie bufera
		bufferSize.X = 20;
		if(av==0) bufferSize.Y = 7;
		else bufferSize.Y = 11;
		SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
		std::cout << pctr << std::endl;
		std::cout << fname << std::endl;
		printingamemenu();
		printpetstatus(tuz.hngr , tuz.mood , tuz.skil , tuz.hlth ,tuz.enrg, tuz.age);
		
		if (prsdkey == 80)
		{
			if (y != 38 &&y!=30) y = y + 2;
			if (y ==30) y = 38;
		}
		if (prsdkey == 72)
		{
			if (y != 20 && y != 38)	y = y - 2;
			if (y == 38) y = 28;
		}
		bufferSize.Y = y;
		bufferSize.X = 55;
		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout.width(50);
		std::cout << std::right << ">>>>" << std::endl;
		prsdkey = _getch();
		if (prsdkey == 13)
		{
			double time=0;
			while (time > 20 || time < 5)
			{
				system("cls");
				setlocale(LC_ALL, "");
				HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
				COORD bufferSize = { 1200, 600 }; //izmenenie bufera
				bufferSize.X = 40;
				bufferSize.Y = 8;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cout << "Duration of an activity?" << std::endl;
				bufferSize.X = 40;
				bufferSize.Y = 9;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cin>>time;
			}
			if (y == 20) pet::action(&tuz.mood, time, 1);
			if (y == 22) pet::action(&tuz.mood, time, 2);
			if (y == 24) pet::action(&tuz.mood, time, 1);
			if (y == 26) pet::action(&tuz.mood, time, 1);
			if (y == 35) pet::action(&tuz.mood, time, 1);
		}

	}
	
}
void printingamemenu()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; 
	bufferSize.X = 60;
	bufferSize.Y = 20;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout <<  std::right << "Play" << std::endl;
	bufferSize.Y = 22;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout <<  std::right << "Feed" << std::endl;

	bufferSize.Y = 24;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout <<  std::right << "Cure" << std::endl;
	bufferSize.Y = 26;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout <<  std::right << "Train" << std::endl;
	bufferSize.Y = 28;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout << std::right << "Sleep" << std::endl;
	bufferSize.Y = 38;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout << std::right << "Exit" << std::endl;
}
void printpetstatus(int hngr, int mood, int skil,int hlth, int enrg, double age)
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 5;
	bufferSize.Y = 4;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Hunger: " << hngr << std::endl;
	bufferSize.X = 23;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Mood: " << mood << std::endl;
	bufferSize.X = 41;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Skills: " << skil << std::endl;
	bufferSize.X = 59;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Health: " << hlth << std::endl;
	bufferSize.X = 77;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Energy: " << enrg << std::endl;
	bufferSize.X = 95;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Age: " << age << " yo" << std::endl;
}
