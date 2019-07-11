#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <windows.h>
#include <cstring.h>
/**************************************************
Program: Game of Life
Purpose:
	Input:
   Output:
**************************************************/
const int TOPX=5;const int Y_SIZE=40; const int X_SIZE=70;
const int TOPY=5;const char char_Alive='x';const char char_Dead='.';
void Init(int array[][Y_SIZE+2]);
/************************                      
Function: Init(int )
Purpose: To initiate an array to be all '0'
Argument: an array
Return: change the value of each cell of array to '0'
************************/
void ShowWorld(int array[][Y_SIZE+2]);
/****************************
Function: ShowWorld(int array)
Purpose: Show the array to the screen
Argument: an array
Return: don't return but print the cell in the array into screen
****************************/
void PutCell(int i, int j, bool Alive);
/****************************
Function PutCell()
Purpose: Use to mark the position the alive or dead
Argument: 2 int and 1 boolean variables
Return: Mark the cell (i,j) as alive or dead
****************************/
void Step(int array[][Y_SIZE+2]);
/****************************
Function Step()
Purpose: Function of step- for one generation of cell lives
Argument: The main array included the cell lives
****************************/
int Neighbor(int array[][Y_SIZE+2],int x, int y);
/****************************
Function: Neighbor(int array, int )
Purpose: Return the numbers of alive cell among point (x,y)
Argument: the main array and 2 int x,y as the point (x,y)
Return: The numbers of alive cell among (x,y)
****************************/
void WriteIn(ofstream &fout,int array[][Y_SIZE+2]);
/****************************
Function: WriteIn()
Purpose: Use to write the data of array into a file
Argument: the array and the file need to be written in
 ***************************/
void Play(int array[][Y_SIZE+2],bool circular);
/****************************
Function Play(int array,bool circular)
Purpose: Play function- nonstop generation of cell lives
Argument: The main array included cell alive/dead
****************************/
void ReadIn(ifstream &fin, int array[][Y_SIZE+2]);
/****************************
Function ReadIn()
Purpose: Use to read the data into the array from a file
Argument: The file that read from and the array should be saved into
****************************/
int Random(int lo, int hi);
/****************************
Function Random()
Purpose: Random a number from integer lo to hi
Argument: two integers lo and hi
Return: random number from lo to hi
****************************/
main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
   ifstream fin;
   ofstream fout;
   bool t=true;
	char c;
   while (t==true)
   {
   	system("cls");
   	int World[X_SIZE+2][Y_SIZE+2];
      Init(World);
      fin.open("Life.ini");
      char current_file[20];
      bool circular=true;
      if (fin.fail())
      {
      	fin.close();
         strcpy(current_file,"Default.ini");
      }
      else
      {
         fin>>current_file;
      }
      fin.close();
   	cout<<"----Welcome to Game Of Life----"<<endl;
      cout<<"[F]ile "<<current_file<<" [S]ave [L]oad S[t]ep [G]o [P]ause [C]ircular [R]andom Cl[e]ar [Q]uit "<<endl;
      char ch;
      ShowWorld(World);
      char pl;
            pl=getch();
            int x=TOPX;int y=TOPY;
            while (pl!='q')
            {
               gotoxy(x,y);
            	switch(pl)
            	{
            		case 0: //arrow key...
         		  		ch = getch();
                 		switch (ch)
                 		{
                 	 		case 'H' : if (y>TOPY)
                        	{
                        		gotoxy(x,y-1); y=y-1;
                           }
                           break;
                   		case 'P':  if (y<(TOPY+Y_SIZE-2))
                        	{
                        		gotoxy(x,y+1); y++;
                           }
                        	break;
                   		case 'M':  if (x<(TOPX+X_SIZE-2))
                        	{
                           	gotoxy(x+1,y);x++;
                           }
                           break;
                   		case 'K':  if (x>TOPX)
                        	{
                           	gotoxy(x-1,y);x--;
                           }
                           break;
                 		}
                     break;
      				case 'f':
         				{
                     	ShowWorld(World);
         					cout<<endl<<"New file_name: ";cin>>current_file;
            				fout.open("Life.ini");
            				fout<<current_file;
            				fout.close();
            				system("cls");
            				cout<<"----Welcome to Game Of Life----"<<endl;
      						cout<<"[F]ile "<<current_file<<" [S]ave [L]oad S[t]ep [G]o [P]ause [C]ircular [R]andom Cl[e]ar [Q]uit "<<endl;
            				ShowWorld(World);
         				}
                     break;
      				case 'l':
         			{
         				fin.open(current_file);
            			if (fin.fail())
            			{
            				fin.close();
               			fin.open("Default.ini");
                        if (fin.fail())
               			{
               				Init(World);
                  			ShowWorld(World);
               			}
               			else
               			{
               				Init(World);
               				ReadIn(fin,World);
               				ShowWorld(World);
                     	}
               		fin.close();
            			}
            			else
            			{
            				Init(World);
            				ReadIn(fin,World);
               			ShowWorld(World);
            			}
            			fin.close();
         			}
         			break;
         			case 's':
         {
          	fout.open(current_file);
            if (!fout.fail())
            {
            	WriteIn(fout,World);
            }
            else
            {
            	ShowWorld(World);
            	cout<<endl<<"Saving Error"<<endl;
            }
         }
         break;
      				/*case 'i':
         			{
                  	char ch;
                  	ch=getch();
                  	while (ch!='i')
                  	{
                  		switch (ch)
                  		{   */
                  			case  'x':
                  			case 'X':
                  			case 13:  // 'x' key
                  			{
                           	if (World[x+1-TOPX][y+1-TOPY]==0)
                     			{
                     				cout<<"x"; World[x+1-TOPX][y+1-TOPY]=1;
                     			}
                     			else
                     			{
                     				cout<<".";World[x+1-TOPX][y+1-TOPY]=0;
                     			}
                           	ShowWorld(World);
                           }
                  			break;
         case 't':
         {
         	if (circular)
            {
            	for (int i=0;i<X_SIZE;i++)
            	{
            		World[i][0]=World[i][Y_SIZE-1];
               	World[i][Y_SIZE]=World[i][1];
            	}
            	for (int i=0;i<Y_SIZE;i++)
            	{
            		World[0][i]=World[X_SIZE-1][i];
               	World[X_SIZE][i]=World[1][i];
            	}
            }
         	Step(World);
            ShowWorld(World);
         }
         break;
         case 'g': Play(World,circular);
         	break;
         case 'c':
         {
         	circular=(!circular);
            if (!circular)
            {
            	for (int i=0;i<X_SIZE;i++)
      	   	{
            		World[i][0]=0;
               	World[i][Y_SIZE]=0;
            	}
            	for (int i=0;i<Y_SIZE;i++)
            	{
            		World[0][i]=0;
               	World[X_SIZE][i]=0;
            	}
            }
         }
         break;
         case 'r':
         {
         	for (int i=0;i<100;i++)
            {
            	int j=Random(0,X_SIZE);
               int k=Random(0,Y_SIZE);
               World[j][k]=1;
            }
            ShowWorld(World);
         }
         break;
         case 'e':
         {
         	Init(World);
            ShowWorld(World);
         }
      }
      pl=getch();
      }
      cout<<endl;
   	cout<<"You want to do it again(Y/N)? ";cin>>c;
   	t=(c=='Y')|(c=='y');
   }
}
void WriteIn(ofstream &fout,int array[][Y_SIZE+2])
{
	for (int i=1;i<X_SIZE;i++)
   for (int j=1;j<Y_SIZE;j++)
   {
   	if (array[i][j]==1) fout<<i<<" "<<j<<endl;
   }
   fout.close();
}
void ReadIn(ifstream &fin, int array[][Y_SIZE+2])
{
	int x,y;
	while (!fin.eof())
   {
   	fin>>x>>y;
      if (fin.fail()) break;
      array[x][y]=1;
   }
}
void ShowWorld(int array[][Y_SIZE+2])
{
	bool Alive=true;
	for (int i=1;i<X_SIZE;i++)
    for (int j=1;j<Y_SIZE;j++)
    {
    	if (array[i][j]==1) PutCell(i,j,Alive);
      else PutCell(i,j,!Alive);
    }
}
void PutCell(int i, int j, bool Alive)
{
	gotoxy(TOPX+i-1,TOPY+j-1);
   if (Alive) cout<<char_Alive; else cout<<char_Dead;
}
void Play(int array[][Y_SIZE+2], bool circular)
{
	char pl='0';
   while (!kbhit())
   {
   	if (circular)
      {
      	for (int i=1;i<X_SIZE;i++)
      	  {
            	array[i][0]=array[i][Y_SIZE-1];
               array[i][Y_SIZE]=array[i][1];
            }
            for (int i=1;i<Y_SIZE;i++)
            {
            	array[0][i]=array[X_SIZE-1][i];
               array[X_SIZE][i]=array[1][i];
            }
      }
      Sleep(10);
   	Step(array);
      ShowWorld(array);
   }
}
void Step(int array[][Y_SIZE+2])
{
	int temp;
	int TempWorld[X_SIZE+2][Y_SIZE+2];
   Init(TempWorld);
	for (int i=1;i<X_SIZE;i++)
    for (int j=1;j<Y_SIZE;j++)
    {
    	temp=Neighbor(array,i,j);
    	if ((temp==3)|(temp==2))
      {
      	TempWorld[i][j]=array[i][j];
      	if ((temp==3)&&(array[i][j]==0)) TempWorld[i][j]=1;
      }
      else TempWorld[i][j]=0;
    }
    for (int i=1;i<X_SIZE;i++)
     for (int j=1;j<Y_SIZE;j++)
      array[i][j]=TempWorld[i][j];
}
int Neighbor(int array[][Y_SIZE+2],int x, int y)
{
	int temp=0;
	for (int i=x-1;i<=x+1;i++)
    for (int j=y-1;j<=y+1;j++)
     temp=temp+array[i][j];
    return (temp-array[x][y]);
}
void Init(int array[][Y_SIZE+2])
{
	for (int i=0;i<X_SIZE+1;i++)
    for (int j=0;j<Y_SIZE+1;j++)
     array[i][j]=0;
}
int Random(int lo, int hi)
{
	int r;
   int range=(hi-lo)+1;
   r = lo+int(range*rand()/(RAND_MAX + 1.0));
   return r;
}
