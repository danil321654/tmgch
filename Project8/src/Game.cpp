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
		file1 << ava(fname) << " 0 100 0 100 100 0"<< std::endl;
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

void pet::action(int *a, double tm, int act)
{
	switch (act)
	{
	case 1:
	{
		*a = *a + 2 * tm;
		if (*a > 100)*a = 100;
		for (int i = 0; i < tm; i++)
		{

			system("cls");
			std::cout << "playing";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);

		}
		break;
	}
	case 2:
	{
		*a = *a - 2 * tm;
		if (*a < 0)*a = 0;
		for (int i = 0; i < tm; i++)
		{

			system("cls");
			std::cout << "feeding";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);

		}
		break;
	}
	case 3:
	{
		*a = *a + tm;
		if (*a > 100)*a = 100;
		for (int i = 0; i < tm; i++)
		{

			system("cls");
			std::cout << "curing";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);

		}
		break;
	}
	case 4:
	{
		*a = *a + tm / 2;
		if (*a > 100)*a = 100;
		for (int i = 0; i < tm; i++)
		{

			system("cls");
			std::cout << "training";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);

		}
		break;
	}
	case 5:
	{
		*a = *a + tm;
		if (*a > 100)*a = 100;
		for (int i = 0; i < tm; i++)
		{

			system("cls");
			std::cout << "sleeping";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);
			std::cout << ".";
			Sleep(250);

		}
		break;
	}
	case 6:
	{
		*a = *a - tm;
		break;
	}
	case 7:
	{
		*a = *a + tm;
		break;
	}
	}
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
	system("cls");
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	bufferSize.X = 20;
	if (av == 0) bufferSize.Y = 7;
	else bufferSize.Y = 11;
	SetConsoleCursorPosition(hWnd, bufferSize);// peremeshenie kursora
	std::cout << pctr << std::endl;
	std::cout << fname << std::endl;
	printingamemenu();
	printpetstatus();
	while (1)
	{
		printpetstatus2(tuz.hngr , tuz.mood , tuz.skil , tuz.hlth ,tuz.enrg, tuz.age);
		
		if (prsdkey == 80)
		{
			if (y != 38 && y != 28)
			{
				
				bufferSize.Y = y;
				bufferSize.X = 54;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cout.width(50);
				std::cout << std::right << "    " << std::endl;
				y = y + 2;
			}
			else if (y == 28) { 
				bufferSize.Y = y;
				bufferSize.X = 54;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cout.width(50);
				std::cout << std::right << "    " << std::endl;
				y = 38;
			}
		}
		if (prsdkey == 72)
		{
			if (y != 20 && y != 38) {
				bufferSize.Y = y;
				bufferSize.X = 54;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cout.width(50);
				std::cout << std::right << "    " << std::endl;
				y = y - 2;
			}
			else if (y == 38)
			{
				bufferSize.Y = y;
				bufferSize.X = 54;
				SetConsoleCursorPosition(hWnd, bufferSize);
				std::cout.width(50);
				std::cout << std::right << "    " << std::endl;
				y = 28;
			}
		}
		bufferSize.Y = y;
		bufferSize.X = 54;
		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout.width(50);
		std::cout << std::right << ">>>>" << std::endl;
		prsdkey = _getch();
		if (prsdkey == 13)
		{
			double time=0;
			while (time > 10 || time < 5)
			{
				system("cls");
				setlocale(LC_ALL, "");
				HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
				COORD bufferSize = { 1200, 600 }; //izmenenie bufera
				bufferSize.X = 40;
				bufferSize.Y = 8;
				SetConsoleCursorPosition(hWnd, bufferSize);
				if(y!=38)std::cout << "Duration of an activity? (in sec, 4<time<11)" << std::endl;
				bufferSize.X = 40;
				bufferSize.Y = 9;
				SetConsoleCursorPosition(hWnd, bufferSize);
				if (y != 38)std::cin>>time;
				else time = 5;
			}
			if (y == 20&&tuz.enrg>20&&tuz.hngr<80) {
				pet::action(&tuz.mood, time, play);
				pet::action(&tuz.enrg, time, 6);
				pet::action(&tuz.hngr, time, 7);
			}
			else
			{
				bufferSize.X = 40;
				bufferSize.Y = 9;
				SetConsoleCursorPosition(hWnd, bufferSize);
				if (tuz.enrg <= 20)std::cout << "too low energy" << std::endl;
				else if (tuz.hngr > 80) std::cout << "too hungry" << std::endl;
			}

			if (y == 22) pet::action(&tuz.hngr, time, feed);
			if (y == 24 && tuz.enrg > 20 && tuz.hngr < 80) {
				pet::action(&tuz.skil, time, train);
				pet::action(&tuz.enrg, time, 6);
				pet::action(&tuz.hngr, time, 7);
			}
			else
			{
				bufferSize.X = 40;
				bufferSize.Y = 9;
				SetConsoleCursorPosition(hWnd, bufferSize);
				if (tuz.enrg <= 20)std::cout << "too low energy" << std::endl;
				else if (tuz.hngr > 80) std::cout << "too hungry" << std::endl;
			}
			if (y == 26) pet::action(&tuz.hlth, time, cure);
			if (y == 28) pet::action(&tuz.enrg, time, sleep);
			if (y == 38)
			{
				int a;
				saveorno(&a);
				if (a == 0)
				{
					std::ofstream writesv(filname, std::ios::trunc);
					writesv << av  <<" "<< tuz.hngr << " " << tuz.mood << " " << tuz.skil << " " << tuz.hlth << " " << tuz.enrg << " " << tuz.age;
					return;
				}
				if (a == 1) return;
			}
			system("cls");
			printpetstatus();
			std::cout << pctr << std::endl;
			std::cout << fname << std::endl;
			printingamemenu();
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
	std::cout <<  std::right << "Train" << std::endl;
	bufferSize.Y = 26;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout <<  std::right << "Cure" << std::endl;
	bufferSize.Y = 28;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout << std::right << "Sleep" << std::endl;
	bufferSize.Y = 38;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(50);
	std::cout << std::right << "Exit" << std::endl;
}
void printpetstatus()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 5;
	bufferSize.Y = 4;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Hunger: " <<  std::endl;
	bufferSize.X = 23;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Mood: " <<  std::endl;
	bufferSize.X = 41;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Skills: " <<  std::endl;
	bufferSize.X = 59;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Health: " <<  std::endl;
	bufferSize.X = 77;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Energy: " <<  std::endl;
	bufferSize.X = 95;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Age: " <<  " yo" << std::endl;
}
void printpetstatus2(int hngr, int mood, int skil, int hlth, int enrg, double age)
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 13;
	bufferSize.Y = 4;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << hngr << std::endl;
	bufferSize.X = 29;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << mood << std::endl;
	bufferSize.X = 49;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout <<  skil << std::endl;
	bufferSize.X = 67;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout <<  hlth << std::endl;
	bufferSize.X = 85;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout <<  enrg << std::endl;
	bufferSize.X = 100;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << age << " yo" << std::endl;
}
