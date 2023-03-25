#include<iostream>
#include<windows.h>
using namespace std;

void topHeader();
void temptopHeader();
void maze();
void gotoxy(int , int);
char Getch(short int x,short int y);
void printsh1(int x, int y);
void printsh2(int x, int y);
void printsh3(int x, int y);
void printsh4(int x, int y);
void printsh5(int x, int y);
void erasesh1(int x, int y);
void erasesh2(int x, int y);
void erasesh3(int x, int y);
void erasesh4(int x, int y);
void erasesh5(int x, int y);
void erase(int x, int y);
void scoreprint();
int score = 0;

main()
{

    system("cls");

    temptopHeader();
    maze();
    gotoxy(5,45);
    cout << "S";
    gotoxy(85,26);
    cout << "Score :   0";
    bool runningame = true;
    int x=40;
    int y=9;
    int sh = 0;
    printsh1(x,y);
    while(runningame)
    {   char ch = 219;
        sh = sh % 5;
        x = 40;
        y = 9;
        if(sh == 0)
            printsh1(x,y);
        else if(sh == 1)
            printsh2(x,y);
        else if(sh == 2)
            printsh3(x,y);
        else if(sh == 3)
            printsh4(x,y);
        else if(sh == 4)
            printsh5(x,y);
        scoreprint();
        while(true)
        {
            if(GetAsyncKeyState(VK_LEFT))
            {  
                char nextLocation = Getch(x-1,y);
                if (nextLocation == ' ')
                {
                    if(sh == 0)
                    {
                        erasesh1(x,y);
                        x = x - 1;
                        printsh1(x,y);
                    }
                    else if(sh == 1)
                    {
                        erasesh2(x,y);
                        x=x-1;
                        printsh2;  
                    }
                    else if(sh == 2)
                    {
                        erasesh3(x,y);
                        x = x - 1;
                        printsh3(x,y);
                    }
                    else if(sh == 3)
                    {
                        erasesh4(x,y);
                        x = x - 1;
                        printsh4(x,y);
                    }
                    else if(sh == 4)
                    {
                        erasesh5(x,y);
                        x = x - 1;
                        printsh5(x,y);
                    }
                }
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {   
                char nextLocation = Getch(x+1,y+1);
                if(nextLocation == ' ')
                {
                    if(sh == 0)
                    {
                        erasesh1(x,y);
                        x = x + 1;
                        printsh1(x,y);
                    }
                    else if(sh == 1)
                    {
                        erasesh2(x,y);
                        x = x + 1;
                        printsh2(x, y);  
                    }
                    else if(sh == 2)
                    {
                        erasesh3(x,y);
                        x = x + 1;
                        printsh3(x,y);
                    }
                    else if(sh == 3)
                    {
                        erasesh4(x,y);
                        x = x + 1;
                        printsh4(x,y);
                    }
                    else if(sh == 4)
                    {
                        erasesh5(x,y);
                        x = x + 1;
                        printsh5(x,y);
                    }
                }
            }
                char nextLocation = Getch(x,y+1);
                char nextLocation1 = Getch(x+1,y+1);
                char nextLocation2 = Getch(x+2,y+1);
                char nextLocation3 = Getch(x+3,y+1);
                char nextLocation4 = Getch(x+4,y+1);
                if (nextLocation == ' ')
                {
                    if(sh == 0)
                    {
                        erasesh1(x,y);
                        y = y + 1;
                        printsh1(x,y);
                    }
                    else if(sh == 1 && nextLocation1 == ' ')
                    {
                        erasesh2(x,y);
                        y = y + 1;
                        printsh2(x, y);
                        //printsh2;  
                    }
                    else if(sh == 2 && nextLocation1 == ' ' && nextLocation2 == ' ')
                    {
                        erasesh3(x,y);
                        y = y + 1;
                        printsh3(x,y);
                    }
                    else if(sh == 3 && nextLocation1 == ' ' && nextLocation2 == ' ' && nextLocation3 == ' ')
                    {
                        erasesh4(x,y);
                        y = y + 1;
                        printsh4(x,y);
                    }
                    else if(sh == 4 && nextLocation1 == ' ' && nextLocation2 == ' ' && nextLocation3 == ' ' && nextLocation4 == ' ')
                    {
                        erasesh5(x,y);
                        y = y + 1;
                        printsh5(x,y);
                    }
                }
    
                char upLocation = Getch(x,y-1);
                if (upLocation == '#')
                {
                    runningame = false;
                    break;
                }
                if (nextLocation == '#'|| nextLocation == ch || nextLocation1 == ch || nextLocation2 == ch || nextLocation3 == ch || nextLocation4 == ch)
                {
                    sh++;
                    break;
                }

            if(GetAsyncKeyState(VK_ESCAPE))
            {
                runningame = false;
            }
            Sleep(100);
        }
    }



}



char Getch(short int x,short int y)
{
  CHAR_INFO ci;
  COORD xy = {0,0};
  SMALL_RECT rect = {x,y,x,y};
  COORD coordBufSize;
  coordBufSize.X=1;
  coordBufSize.Y=1;  
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize,xy, &rect) ? ci.Char.AsciiChar : ' ';
}


void gotoxy(int x , int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


void maze()
{
cout << "   ############################################################################## "<< endl; 
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ############################################################################## "<< endl;
}

void printsh1(int x, int y)
{
    gotoxy(x,y);
    char ch = 219;
    cout << ch;

}

void printsh2(int x, int y)
{
    gotoxy(x,y);
    char ch = 219;
    char sh[2] = {ch, ch};
    // for(int i = 0; i < 2; i++){
    //     cout << sh[i];
    // }
    cout << ch << ch;

}

void printsh3(int x, int y)
{
    gotoxy(x,y);
    char ch = 219;
    char sh1[3] = {ch,ch,ch};
    for(int i = 0;i < 3;i++)
    {
        cout << sh1[i];

    }

}

void printsh4(int x, int y)
{
    gotoxy(x,y);
    char ch = 219;
    cout << ch << ch << ch << ch;

}

void printsh5(int x, int y)
{
    gotoxy(x,y);
    char ch = 219;
    char sh1[5] = {ch,ch,ch,ch,ch};
    for(int i = 0;i < 5;i++)
    {
        cout << sh1[i];

    }

}


void erase(int x, int y)
{
  gotoxy(x,y);
  // char er[3] = {' ',' ', ' '};
  for(int i = 0;i < 7;i++)
  {
    // cout << er[i];
    cout << ' ';

  }
}
void erasesh1(int x, int y)
{
  gotoxy(x,y);
  cout << ' ';

}
void erasesh2(int x, int y)
{
  gotoxy(x,y);
    cout << "  ";

}

void erasesh3(int x, int y)
{
  gotoxy(x,y);
  cout << "   ";

}

void erasesh4(int x, int y)
{
  gotoxy(x,y);
  cout << "    ";

}

void erasesh5(int x, int y)
{
  gotoxy(x,y);
  cout << "     ";

}


void temptopHeader()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int k = 9;
  SetConsoleTextAttribute(hConsole, k);
  cout << "\t\t"<< " $$$$$$$$\\         $$\\               $$\\ " << endl;           
  cout << "\t\t"<< " \\__$$  __|        $$ |              \\__|   " << endl;       
  cout << "\t\t"<< "    $$ | $$$$$$\\ $$$$$$\\    $$$$$$\\  $$\\  $$$$$$$\\" << endl;
  cout << "\t\t"<< "    $$ |$$  __$$\\_ $$  _|  $$  __$$\\ $$ |$$  _____|" << endl;
  cout << "\t\t"<< "    $$ |$$$$$$$$ | $$ |    $$ |  \\__|$$ |\\$$$$$$\\  " << endl;
  cout << "\t\t"<< "    $$ |$$   ____| $$ |$$\\ $$ |      $$ | \\____$$\\ " << endl;
  cout << "\t\t"<< "    $$ |\\$$$$$$$\\  \\$$$$  |$$ |      $$ |$$$$$$$  |" << endl;
  cout << "\t\t"<< "    \\__| \\_______|  \\____/ \\__|      \\__|\\_______/  " << endl;
}


void scoreprint()
{
    char ch = 219;
    char currentLocation;
    int check = 0;
    bool isNotFilled = true;
    for( int y = 45; y >= 43 ; y--) // ( int y = 9; y <= 26 ; y++)
    {
        //check = 0;
        for( int x = 5; x <= 78;x++)
        {
            currentLocation = Getch(x,y);
            if(currentLocation == ch)
            {
                check++;
            }
            if(currentLocation != ch)
            {
                isNotFilled = true;
            }
        }
        
        if(check > 20) // real is 73
        {
            cout << "check: " << check;
            score = score + 10;
            gotoxy(95,26);
            cout << score;
        }
    }
}