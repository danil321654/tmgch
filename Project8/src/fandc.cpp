#include"fandc.h"

void loadscreen()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	SetConsoleScreenBufferSize(hWnd, bufferSize);
	HWND hwnd = GetConsoleWindow();
	int th = GetSystemMetrics(SM_CYSCREEN);
	int tw = GetSystemMetrics(SM_CXSCREEN);
	MoveWindow(hwnd, tw/2-512, th/2-300 , 1024, 592, TRUE);
	bufferSize.X = 70;
	bufferSize.Y = 16;
	
	
	SetConsoleCursorPosition(hWnd, bufferSize);
	for (int i = 0; i < 15; i++) {
		if(i%3==1)
		{std::cout << R"(
				     ###       ####     ##      ##    #####    #  #      ##
				   ##        ##  ##    ###   ####    ##     #######   ####
				  ## ###    ######    ##  ##  ##    ####     #  #      ##
				 ##  ##    ##  ##    ##      ##    ##     #######     ##
				 ####     ##  ##    ##      ##    #####    #  #      ##)" << std::endl; ;
		}

		else if (i % 3 == 0)
		{std::cout << R"(
				 ###       ####     ##      ##    #####    #  #      ##
				##        ##  ##    ###    ###    ##     ########  ####
				## ###    ######    ##  ##  ##    ####     #  #      ##
				##  ##    ##  ##    ##      ##    ##     ########    ##
				 ####     ##  ##    ##      ##    #####    #  #      ##)" << std::endl; }

		else if (i % 3 == 2)
		{std::cout << R"(
				 ###       ####     ##      ##    #####    #  #      ##
				 ##        ##  ##    ####   ###    ##     #######   ####
				  ## ###    ######    ##  ##  ##    ####     #  #      ##
				   ##  ##    ##  ##    ##      ##    ##     #######     ##
				     ####     ##  ##    ##      ##    #####    #  #      ##)" << std::endl; ;
		}

		Sleep(250);
		system("cls");
		SetConsoleCursorPosition(hWnd, bufferSize);
		}
	}
void printmenu()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 70;
	bufferSize.Y = 10;

	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(40);
	std::cout.setf(std::ios::left);
	std::cout << R"(
									 New Game 

									Load Game

									  Credits

									     Exit)" << std::endl;
	bufferSize.X = 35;
	bufferSize.Y = 40;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Majestic Danilo Inc. 2018. All rights reserved.";
}
int menu()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 70;
	bufferSize.Y = 11;
	char c = 0;
	bufferSize.X = 85;
	SetConsoleCursorPosition(hWnd, bufferSize);
	
		printmenu();
	while (c != 13)
	{

		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout << "            " << std::endl;
		if (c == 80) if (bufferSize.Y != 17) bufferSize.Y = bufferSize.Y + 2;
		if (c == 72) if (bufferSize.Y != 11) bufferSize.Y = bufferSize.Y - 2;
		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout << "<<<<<<<<<<<<" << std::endl;
		c = _getch();
	}
	if (bufferSize.Y == 17) {
		if (rusure()) return 0;
		else menu();
	}
	else if (bufferSize.Y == 15) {
		credits(); return 0;
	}
	else if (bufferSize.Y == 13)loadgame(0, " ");
	else loadgame(1, ngame()); 
	}
bool rusure()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	system("cls");
	
	char c = 0;
	while (c != 13)
	{
		
		bufferSize.Y = 12;
		bufferSize.X = 54;
		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout << "Are you sure?" << std::endl;
		bufferSize.X = 20;
		bufferSize.Y = 13;
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
	if(bufferSize.X == 24)return 1;
	else return 0;
}
bool ava(std::string name)
{
	system("cls");

	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE); //захватывает консоль
	COORD bufferSize = { 1200, 600 }; //izmenenie bufera
	bufferSize.X = 40;
	bufferSize.Y = 10;

	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout.width(40);

	std::string pets[2];
	pets[1] = shwcat();
	pets[0] = shwdog();
	system("cls");
	bufferSize.X = 40;
	bufferSize.Y = 5;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << name;
	bufferSize.X = 75;
	bufferSize.Y = 10;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << pets[1];
	char c = 0;
	bool d = 0;
	while (c != 13)
	{
		c = _getch();
		if (c == 75 && d)
		{
			system("cls");
			bufferSize.X = 40;
			bufferSize.Y = 5;
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << name;
			bufferSize.X = 75;
			bufferSize.Y = 10;
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << pets[d];
			d = 0;
		}
		else if (c == 77 && !d)
		{
			system("cls");
			bufferSize.X = 40;
			bufferSize.Y = 5;
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << name;
			bufferSize.X = 75;
			bufferSize.Y = 10;
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << pets[d];
			d = 1;
		}
	}
	return !d;
}
std::string shwcat()
{
	return R"(
              ,
              \`-._           __
               \\  `-..____,.'  `.
                :`.         /    \`.
                :  )       :      : \
                 ;'        '   ;  |  :
                 )..      .. .:.`.;  :
                /::...  .:::...   ` ;
                ; _ '    __        /:\
                `:o>   /\o_>      ;:. `.
               `-`.__ ;   __..--- /:.   \
               === \_/   ;=====_.':.     ;
                ,/'`--'...`--....        ;
                     ;                    ;
                   .'                      ;
                 .'                        ;
               .'     ..     ,      .       ;
              :       ::..  /      ;::.     |
             /      `.;::.  |       ;:..    ;
            :         |:.   :       ;:.    ;
            :         ::     ;:..   |.    ;
             :       :;      :::....|     |
             /\     ,/ \      ;:::::;     ;
           .:. \:..|    :     ; '.--|     ;
          ::.  :''  `-.,,;     ;'   ;     ;
       .-'. _.'\      / `;      \,__:      \
       `---'    `----'   ;      /    \,.,,,/
                          `----`    )";
}
std::string shwdog()
{
	return  R"(
                ,
             __.                                              
          .-".'                      .--.            _..._    
        .' .'                     .'    \       .-""  __ ""-. 
       /  /                     .'       : --..:__.-""  ""-. \
      :  :                     /         ;.d$$    sbp_.-""-:_:
      ;  :                    : ._       :P .-.   ,"TP        
      :   \                    \  T--...-; : d$b  :d$b        
       \   `.                   \  `..'    ; $ $  ;$ $        
        `.   "-.                 ).        : T$P  :T$P        
          \..---^..             /           `-'    `._`._     
         .'        "-.       .-"                     T$$$b    
        /             "-._.-"               ._        '^' ;   
       :                                    \.`.         /    
       ;                                -.   \`."-._.-'-'     
      :                                 .'\   \ \ \ \         
      ;  ;                             /:  \   \ \ . ;        
     :   :                            ,  ;  `.  `.;  :        
     ;    \        ;                     ;    "-._:  ;        
    :      `.      :                     :         \/         
    ;       /"-.    ;                    :                    
   :       /    "-. :                  : ;                    
   :     .'        T-;                 ; ;        
   ;    :          ; ;                /  :        
   ;    ;          : :              .'    ;       
  :    :            ;:         _..-"\     :       
  :     \           : ;       /      \     ;      
  ;    . '.         '-;      /        ;    :      
  ;  \  ; :)          :     :         :    '-.      
  '.._L.:-'           :     ;          ;    . `. 
                       ;    :          :  \  ; :) 
                       :    '-..       '.._L.:-'  
                        ;     , `.                
                        :   \  ; :)               
                        '..__L.:-' )";
}
void saveorno(int *bol)
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	system("cls");

	char c = 0;

	bufferSize.Y = 12;
	bufferSize.X = 54;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Do you want to save?" << std::endl;
	bufferSize.X = 6;
	bufferSize.Y = 14;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "YES						NO						Cancel" << std::endl;
	int x = 10;
	bufferSize.X = x;
	while (c != 13)
	{
		
		

		if (c == 77 && x == 10)
		{
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << "            " << std::endl;
			x = 59;
			bufferSize.X = x;
		}
		else if (c == 77 && x == 59) {
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << "            " << std::endl;
			x = 111;
			bufferSize.X = x;
		}
		else if (c == 75 && x == 59) {
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << "            " << std::endl;
			x = 10;
			bufferSize.X = x;
		}
		else if (c == 75 && x == 111) {
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << "            " << std::endl;
			x = 59;
			bufferSize.X = x;
		}
		SetConsoleCursorPosition(hWnd, bufferSize);
		std::cout << "<<<<<<<<<<<<" << std::endl;
		c = _getch();

	}
	if (bufferSize.X == 10) *bol=0;
	else if (bufferSize.X == 59) *bol = 1;
	else if (bufferSize.X == 111) *bol = 2;
}
void credits()
{
	setlocale(LC_ALL, "");
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 1200, 600 };
	bufferSize.X = 35;
	int y = 40;
	bufferSize.Y = y;
	SetConsoleCursorPosition(hWnd, bufferSize);
	std::cout << "Majestic Danilo Inc. 2018. All rights reserved.";
		while (y > 0)
		{
			system("cls");
			y--;
			bufferSize.Y = y;
			SetConsoleCursorPosition(hWnd, bufferSize);
			std::cout << "Majestic Danilo Inc. 2018. All rights reserved.";
			Sleep(100);
	}
		system("cls");
		menu();
}