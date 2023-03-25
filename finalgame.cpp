#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int , int);
char Getch(short int x,short int y);

void playerMenu();
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
void gameOver();
void gameInstructions();
void gameRules();
void generateEnemyBullets();

int bxs[1000];
int bys[1000];
bool isBulletActive[1000];
int bulletcount = 0;
int ebxs[10000];
int ebys[10000];
bool eisBulletActive[10000];
int ebulletcount = 0;
int x = 8;
int y = 8;
int evx = 70;
int evy = 8; 
int ehx = 8;
int ehy = 12; 
int eix = 72;
int eiy = 30; 
int score = 0;
int health = 4;
string enemyDirection = "up";
string enemyDir = "right";
bool runningame = true;

main()
{
  system("cls");

  int choice;
  while(choice != 4)
  {
    playerMenu();
    cin >> choice;
    if(choice == 1)
    {
      gameRules();
    }
    else if(choice == 2)
    {
      gameInstructions();
    }
    else if(choice == 3)
    {
        system("cls");

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
          generateEnemyBullets();
          bulletCollisionWithEnemy();
        
          Sleep(100);
        }
        gameOver();
        choice = 4;

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
  char box = 218;
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
    if(nextLocation != '+' && nextLocation != ' ')
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
    if(nextLocation != '+' && nextLocation != ' ')
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
    cout  << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout  << "   &&&&                                                                      &&&&" << endl;
    cout  << "   &&&&                            SHOOTING TANK                             &&&&" << endl;
    cout  << "   &&&&                                                                      &&&&" << endl;
    cout  << "   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
}


void playerMenu()
{
  system("cls");
  topHeader();
  cout << "1-       RULES" << endl ;
  cout << "2-       INSTRUCTIONS" << endl; 
  cout << "3-       START GAME" << endl;
  cout << "4-       EXIT" << endl;
  // cout << "\t\t\t"<< "5-       " << endl;
  cout << "ENTER YOUR CHOICE : ";
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

void generateEnemyBullets()
{
  ebxs[ebulletcount] = evx-1;
  ebys[ebulletcount] = evy;
  eisBulletActive[bulletcount] = true;
  gotoxy(evx-1,evy);
  cout << ".";
  ebulletcount++;
  cout << ebulletcount;
  for(int i = 0;i < ebulletcount;i++)
  {
    if(eisBulletActive[i] == true)
    {
      char nextLocation = Getch(ebxs[i]-1,ebys[i]);
      if(nextLocation != ' ')
      {
        gotoxy(ebxs[i],ebys[i]);
        cout << " ";
        eisBulletActive[i] = false;
      }
      else
      {
        gotoxy(ebxs[i],ebys[i]);
        cout << " ";
        ebxs[i] = ebxs[i] - 1;
        gotoxy(ebxs[i],ebys[i]);
        cout << ".";
      }
    }
  }
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
  for(int i = 0;i < ebulletcount;i++)
  {
    if(eisBulletActive[i] == true)
    {
      if(ebxs[i] - 1 == x && ebys[i] == y )
      {
        health--;
      }
      if(ebxs[i] == x+1 && ebys[i] == y )
      {
        health--;
      }

    }
  }


}

void printScore()
{
  gotoxy(5,37);
  cout << "Score : " << score ;
  gotoxy(5,38);
  cout << "Health : " << health;
}

void printintelligentEnemy()
{
  /*gotoxy(eix,eiy);
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
  }*/
  char enemy1[6] = {' ',',','-','-','.',' '};
  char enemy2[6] = {'|',' ','o','o',' ','|'};
  char enemy3[6] = {'|',' ','~','~',' ','|'};
  char enemy4[6] = {'|','/','\\','/','\\','|'};
  gotoxy(eix,eiy);
  for(int i = 0;i < 6;i++)
  {
    cout << enemy1[i];
  }
  gotoxy(eix,eiy+1);
  for(int i = 0;i < 6;i++)
  {
    cout << enemy2[i];
  }
  gotoxy(eix,eiy+2);
  for(int i = 0;i < 6;i++)
  {
    cout << enemy3[i];
  }
  gotoxy(eix,eiy+3);
  for(int i = 0;i < 6;i++)
  {
    cout << enemy4[i];
  }
}

void eraseintelligentEnemy()
{
  /*gotoxy(eix,eiy);
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
  }*/
  gotoxy(eix,eiy);
  for(int i = 0;i < 6;i++)
  {
    cout << " ";
  }
  gotoxy(eix,eiy+1);
  for(int i = 0;i < 6;i++)
  {
    cout << " ";
  }
  gotoxy(eix,eiy+2);
  for(int i = 0;i < 6;i++)
  {
    cout << " ";
  }
  gotoxy(eix,eiy+3);
  for(int i = 0;i < 6;i++)
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
  char box = 219;
  if(rightLocation == box || leftLocation == '>' || upLocation == '0' || downLocation == box)
  {
    eraseintelligentEnemy();
    eix = 72;
    eiy = 30; 
    health--;
  }
  if(health == 0)
    runningame = false;
  if(x < eix)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eix--;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  else if(x > eix)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eix++;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  else if(y > eiy)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eiy++;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
  else if(y < eiy)
  {
    gotoxy(eix,eiy);
    eraseintelligentEnemy();
    eiy--;
    gotoxy(eix,eiy);
    printintelligentEnemy();

  }
}

void gameOver()
{
  system("cls");
  topHeader();
  cout <<  " ######      ###    ##     ## ########     #######  ##     ## ######## ########       "  << endl;
  cout <<  "##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##     "  << endl; 
  cout <<  "##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##      "  << endl;
  cout <<  "##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########       "  << endl;
  cout <<  "##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##        "  << endl;
  cout <<  "##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##       "  << endl;
  cout <<  " ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##      "  << endl << endl;
  cout <<  "Total Score  :  " << score;            
  getch();                                                              

}

void gameInstructions()
{
  cout <<  "This game is a shooting game." << endl;
  cout <<  "Tank is the main character of game." << endl; 
  cout <<  "There are three enemies in the game." << endl;   
  cout <<  "Use Up button to move tank up." << endl;     
  cout <<  "Use Down button to move tank down." << endl;     
  cout <<  "Use Left button to move tank left." << endl;      
  cout <<  "Use Right button to move tank right." << endl;  
  cout <<  "Use Space button to fire bullet." << endl; 
  getch();       
}
void gameRules()
{
  cout <<  "When the bullet hits the enemy score increases." << endl;
  cout <<  "When chasing emeny reaches tank health decreases." << endl; 
  cout <<  "When the health is reduced to zero. Game is over" << endl;       
  getch();   
}
