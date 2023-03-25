#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int , int);
char Getch(short int x,short int y);

void topHeader();
void maze();
void printPlayer(int x, int y);
void erase(int x, int y);
void generatebullet(int , int);
void movebullet();
void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();
void bulletCollisionWithEnemy();
void printScore();
void printEnemy();
void tempprintEnemy();
void eraseEnemy();
void temperaseEnemy();
void horizontalMovingEnemy();
void tempverticalMovingEnemy();
void intelligentMovingEnemy();
void eraseintelligentEnemy();
void printintelligentEnemy();

int bxs[1000];
int bys[1000];
bool isBulletActive[1000];
int bulletcount = 0;
int x = 8;
int y = 8;
int evx = 70;
int evy = 8; 
int ehx = 8;
int ehy = 25; 
int eix = 20;
int eiy = 30; 
int score = 0;
string enemyDirection = "up";
string enemyDir = "right";

main()
{
system("cls");

  bool runningame = true;
  topHeader();
  maze();
  printPlayer(x,y);
  while(runningame)
  {
    printScore();
    if(GetAsyncKeyState(VK_LEFT))
     {  
        movePlayerLeft();
     }
    if(GetAsyncKeyState(VK_RIGHT))
     {
        movePlayerRight();
     }
    if(GetAsyncKeyState(VK_UP))
     {
        movePlayerUp();
     }
    if(GetAsyncKeyState(VK_DOWN))
     {
        movePlayerDown();
     }
     if(GetAsyncKeyState(VK_SPACE))
     {
        generatebullet(x,y);
     }
     if(GetAsyncKeyState(VK_ESCAPE))
     {
        runningame = false;
     }
     movebullet();
     horizontalMovingEnemy();
     tempverticalMovingEnemy();
     intelligentMovingEnemy();
     bulletCollisionWithEnemy();
   
     Sleep(100);
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

void printPlayer(int x, int y)
{
  gotoxy(x,y);
  char box = 219;
  char player1[6] = {box,box,box,'-','-','>'};
  char player2[6] = {'0',' ','0',' ',' ',' '};
  for(int i = 0;i < 6;i++)
  {
    cout << player1[i];
  }
  gotoxy(x,y+1);
  for(int i = 0;i < 6;i++)
  {
    cout << player2[i];
  }
}

void printEnemy()
{
  gotoxy(ehx,ehy);
  char box = 219;
  char enemy1[4] = {' ',' ',box,box,};
  char enemy2[4] = {'<','-',box,box,};
  char enemy3[4] = {' ',' ',box,box,};
  for(int i = 0;i < 4;i++)
  {
    cout << enemy1[i];
  }
  gotoxy(ehx,ehy+1);
  for(int i = 0;i < 4;i++)
  {
    cout << enemy2[i];
  }
  gotoxy(ehx,ehy+2);
  for(int i = 0;i < 4;i++)
  {
    cout << enemy3[i];
  }
}

void eraseEnemy()
{
  gotoxy(ehx,ehy);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
  gotoxy(ehx,ehy+1);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
  gotoxy(ehx,ehy+2);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
}

void tempprintEnemy()
{
  gotoxy(evx,evy);
  int size = 6;
  char enemy1[6] = {' ',' ',' ','-','-','-'};
  char enemy2[6] = {'<','=','=','(','-',')'};
  char enemy3[6] = {' ',' ',' ','\\',' ','/'};
  char enemy4[6] = {' ',' ',' ','*','*','*'};
  for(int i = 0;i < size;i++)
  {
    cout << enemy1[i];
  }
  gotoxy(evx,evy+1);
  for(int i = 0;i < size;i++)
  {
    cout << enemy2[i];
  }
  gotoxy(evx,evy+2);
  for(int i = 0;i < size;i++)
  {
    cout << enemy3[i];
  }
  gotoxy(evx,evy+3);
  for(int i = 0;i < size;i++)
  {
    cout << enemy4[i];
  }

}

void temperaseEnemy()
{
  gotoxy(evx,evy);
  int size = 6;
  for(int i = 0;i < size;i++)
  {
    cout << " ";
  }
  gotoxy(evx,evy+1);
  for(int i = 0;i < size;i++)
  {
    cout << " ";
  }
  gotoxy(evx,evy+2);
  for(int i = 0;i < size;i++)
  {
    cout << " ";
  }
  gotoxy(evx,evy+3);
  for(int i = 0;i < size;i++)
  {
    cout << " ";
  }

}

void horizontalMovingEnemy()
{
  if(enemyDir == "left")
  {
    char nextLocation = Getch(ehx-1,ehy);
    if(nextLocation == ' ')
    {
      eraseEnemy();
      ehx--;
      printEnemy();
    }
    if(nextLocation == '|')
    {
      enemyDir = "right";
    }

  }

  if(enemyDir == "right")
  {
    char nextLocation = Getch(ehx+4,ehy);
    if(nextLocation == ' ')
    {
      eraseEnemy();
      ehx++;
      printEnemy();
    }
    if(nextLocation == '|')
    {
      enemyDir = "left";
    }

  }
}

void tempverticalMovingEnemy()
{
  if(enemyDirection == "up")
  {
    char nextLocation = Getch(evx,evy-1);
    if(nextLocation == ' ')
    {
      temperaseEnemy();
      evy--;
      tempprintEnemy();
    }
    if(nextLocation == '#')
    {
      enemyDirection = "down";
    }

  }

  if(enemyDirection == "down")
  {
    char nextLocation = Getch(evx,evy+4);
    if(nextLocation == ' ')
    {
      temperaseEnemy();
      evy++;
      tempprintEnemy();
    }
    if(nextLocation == '#')
    {
      enemyDirection = "up";
    }

  }
}


void erase(int x, int y)
{
  gotoxy(x,y);
  for(int i = 0;i < 6;i++)
  {
    cout << " ";
  }
  gotoxy(x,y+1);
  for(int i = 0;i < 6;i++)
  {
    cout << " ";
  }
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
cout << "   ############################################################################## "<< endl;
}

void topHeader()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 9;
    SetConsoleTextAttribute(hConsole, k);
    cout << "\t\t\t" << "   $$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "\t\t\t" << "   &&&&               &&&&" << endl;
    cout << "\t\t\t" << "   &&&&   SHOOTING    &&&&" << endl;
    cout << "\t\t\t" << "   &&&&               &&&&" << endl;
    cout << "\t\t\t" << "   $$$$$$$$$$$$$$$$$$$$$$$" << endl;
}

void generatebullet(int x, int y)
{
  bxs[bulletcount] = x + 6;
  bys[bulletcount] = y;
  isBulletActive[bulletcount] = true;
  gotoxy(x+6,y);
  cout << "+";
  bulletcount++;
}


void movebullet()
{
  for(int i = 0;i < bulletcount;i++)
  {
    if(isBulletActive[i] == true)
    {
      char nextLocation = Getch(bxs[i]+1,bys[i]);
      if(nextLocation != ' ')
      {
        gotoxy(bxs[i],bys[i]);
        cout << " ";
        isBulletActive[i] = false;
      }
      else
      {
        gotoxy(bxs[i],bys[i]);
        cout << " ";
        bxs[i] = bxs[i] + 1;
        gotoxy(bxs[i],bys[i]);
        cout << "+";
      }
    }
  }
}


void movePlayerLeft()
{
  char nextLocation = Getch(x-1,y);
  if (nextLocation == ' ')
  {
    erase(x,y);
    x = x - 1;
    printPlayer(x,y);
  }
}

void movePlayerRight()
{
  char nextLocation = Getch(x+6,y);
  if (nextLocation == ' ')
  {
    erase(x,y);
    x = x + 1;
    printPlayer(x,y);
  }
}

void movePlayerUp()
{
  char nextLocation = Getch(x,y-1);
  if (nextLocation == ' ')
  {
    erase(x,y);
    y = y - 1;
    printPlayer(x,y);
  }
}

void movePlayerDown()
{
  char nextLocation = Getch(x,y+2);
  if (nextLocation == ' ')
  {
    erase(x,y);
    y = y + 1;
    printPlayer(x,y);
  }
}

void bulletCollisionWithEnemy()
{
  for(int i = 0;i < bulletcount;i++)
  {
    if(isBulletActive[i] == true)
    {
      if(bxs[i] + 1 == evx && (bys[i]== evy || bys[i] == evy + 1 || bys[i] == evy + 2 || bys[i] == evy + 3) )
      {
        score++;
      }
      if(bxs[i] + 1 == ehx && (bys[i]== ehy || bys[i] == ehy + 1 || bys[i] == ehy + 2 ) )
      {
        score++;
      }
    }
  }

}

void printScore()
{
  gotoxy(5,35);
  cout << "Score : " << score;
}

void printintelligentEnemy()
{
  gotoxy(eix,eiy);
  char box = 219;
  char enemy1[4] = {' ','=',box,box,};
  char enemy2[4] = {'<','=',box,box,};
  char enemy3[4] = {' ','=',box,box,};
  for(int i = 0;i < 4;i++)
  {
    cout << enemy1[i];
  }
  gotoxy(eix,eiy+1);
  for(int i = 0;i < 4;i++)
  {
    cout << enemy2[i];
  }
  gotoxy(eix,eiy+2);
  for(int i = 0;i < 4;i++)
  {
    cout << enemy3[i];
  }
}

void eraseintelligentEnemy()
{
  gotoxy(eix,eiy);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
  gotoxy(eix,eiy+1);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
  gotoxy(eix,eiy+2);
  for(int i = 0;i < 4;i++)
  {
    cout << " ";
  }
}


void intelligentMovingEnemy()
{
  char rightLocation = Getch(eix+1,eiy);
  char leftLocation = Getch(eix-1,eiy);
  char upLocation = Getch(eix,eiy+1);
  char downLocation = Getch(eix,eiy-1);
  if(rightLocation != ' ' || leftLocation != ' ' || upLocation != ' ' || downLocation != ' ')
    // break; /// There is a error.
  if(x < eix)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eix--;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  if(x > eix)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eix++;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  if(y > eiy)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eiy++;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  if(y < eiy)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eiy--;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
}