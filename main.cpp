#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>

const int ROW=21;
const int COLUMN=21;
const float ORIGINX=-1;
const float ORIGINY=1;
const float WIDTH=0.1;
const bool DEBUG=false;

using namespace std;
//Prototypez
void Step(int worldArray[][COLUMN+1]);
void CountNeighbors(int worldArray[][COLUMN+1],int tempArray[][COLUMN+1],int rowSize, int columnSize);
void Display(int worldArray[][COLUMN+1]);
void LoadArray(int worldArray[][COLUMN+1]);
void CopyArray(int worldArray[][COLUMN+1],int tempWorld[][COLUMN+1]);
void CopyWall(int worldArray[][COLUMN+1]);
void Save(int worldArray[][COLUMN+1]);
void Load(int worldArray[][COLUMN+1]);
void Translate(int i, int j, int &screenX, int &screenY);
void Kill(int worldArray[][COLUMN+1]);
int GetRandomNum(int lo, int hi);
void RandomGenerator(int worldArray[][COLUMN+1]);
void InfiniteLoop(int worldArray[][COLUMN+1]);
void SavePart(int worldArray[][COLUMN+1], int &length, int &width);
void LoadPart(int worldArray[][COLUMN+1], int length, int width);

int main()
{
    int worldArray[ROW+1][COLUMN+1];
    int length,width;
    bool valid=true;
    char choice;
    LoadArray(worldArray);
    Display(worldArray);
    while(valid)
    {
        cin>>choice;

        switch(choice)
        {
        case 's':
        case 'S':
            Step(worldArray);
            Display(worldArray);
            break;
        case'a':
        case'A':
            Save(worldArray);
            cout<<"Information Saved..."<<endl;
            break;
        case'L':
        case'l':
            cout<<"Now loading..."<<endl;
            Load(worldArray);
            Display(worldArray);
            cout<<"Done Loading..."<<endl;
            break;
        case'r':
        case'R':
            RandomGenerator(worldArray);
            Display(worldArray);
            break;
        case'k':
        case'K':
            Kill(worldArray);
            Display(worldArray);
            break;
        case'i':
        case'I':
            InfiniteLoop(worldArray);
            break;
        case't':
        case'T':
            SavePart(worldArray,length,width);
            Display(worldArray);
            break;
        case'd':
        case'D':
            LoadPart(worldArray,length,width);
            Display(worldArray);
            break;
        case 'x':
        case 'X':
            valid=false;
            break;
        }

    }
    return 0;
}

void Step(int worldArray[][COLUMN+1])
{
    int tempWorld[ROW+1][COLUMN+1];

    CopyWall(worldArray);
    CopyArray(worldArray,tempWorld);

    for(int i=0;i<ROW;i++)
    {
        for(int z=0;z<COLUMN;z++)
        {
            CountNeighbors(worldArray,tempWorld,i,z);
        }
    }

    CopyArray(tempWorld,worldArray);

    if(DEBUG)Display(worldArray);
    if(DEBUG)cout<<"-------------"<<endl;

    CopyWall(worldArray);


}
void CopyArray(int worldArray[][COLUMN+1],int tempWorld[][COLUMN+1])
{
    for(int i=0;i<ROW+1;i++)
    {
        for(int z=0;z<COLUMN+1;z++)
        {
            tempWorld[i][z]=worldArray[i][z];
        }
    }
}

void CountNeighbors(int worldArray[][COLUMN+1],int tempArray[][COLUMN+1],int rowSize,int columnSize)
{

    int neighbor=0;

//    if(DEBUG)cout<<"["<<rowSize<<"]"<<"["<<columnSize<<"]"<<endl;

    for(int i=(rowSize-1);i<=(rowSize+1);i++)
    {
        for(int z=(columnSize-1);z<=(columnSize+1);z++)
        {

//            if(DEBUG)cout<<"ARRAY: "<<i<<" "<<z<<" "<<worldArray[i][z]<<endl;

            if(worldArray[i][z]==1)
            {
                neighbor++;
            }

        }
    }

    if(worldArray[rowSize][columnSize]==1)
    {
        neighbor--;
    }
//    if(DEBUG)cout<<"NEIGHBOR: "<<neighbor<<endl;
    if(neighbor<2)
    {
        tempArray[rowSize][columnSize]=0;
    }
    else if(neighbor==2)
    {
        if(worldArray[rowSize][columnSize]==0)
        {
            tempArray[rowSize][columnSize]=0;
        }
        else if(worldArray[rowSize][columnSize]==1)
        {
            tempArray[rowSize][columnSize]=1;
        }
        else
        {
            cout<<"it borke"<<endl;
        }
    }
    else if(neighbor==3)
    {
       tempArray[rowSize][columnSize]=1;
    }
    else if(neighbor>=4)
    {
       tempArray[rowSize][columnSize]=0;
    }
    else
    {
        cout<<"It broke";
    }

}

void LoadArray(int worldArray[][COLUMN+1])
{
    for(int a=0;a<ROW+1;a++)
    {
        for(int z=0;z<COLUMN+1;z++)
        {
            worldArray[a][z]=0;
        }
    }
    worldArray[5][5]=1;
    worldArray[5][6]=1;
    worldArray[5][7]=1;
    worldArray[6][5]=1;
    worldArray[7][6]=1;

}
void Display(int worldArray[][COLUMN+1])
{
    for(int i=0;i<ROW+1;i++)
    {
        for(int z=0;z<COLUMN+1;z++)
        {
            cout<<worldArray[i][z];
        }
        cout<<endl;
    }
}
void CopyWall(int worldArray[][COLUMN+1])
{
    if(DEBUG)cout<<"The loop is working"<<endl;

    int tempArray[ROW+1][COLUMN+1];

    CopyArray(worldArray,tempArray);

    for(int i=0;i<ROW+1;i++)
    {
        tempArray[0][i]=worldArray[ROW-1][i];

        tempArray[ROW][i]=worldArray[1][i];

    }

    for(int z=0;z<COLUMN+1;z++)
    {

        tempArray[z][0]=worldArray[z][COLUMN-1];
        tempArray[z][COLUMN]=worldArray[z][1];
    }

    tempArray[0][0]=worldArray[COLUMN-1][ROW-1];
    tempArray[0][COLUMN]=worldArray[ROW-1][1];
    tempArray[ROW][0]=worldArray[1][COLUMN-1];
    tempArray[ROW][COLUMN]=worldArray[1][1];

    CopyArray(tempArray,worldArray);

    if(DEBUG)Display(worldArray);
    if(DEBUG)cout<<"-------------"<<endl;


}
void Save(int worldArray[][COLUMN+1])
{
    if(DEBUG)cout<<"save"<<endl;
    int i;

    ofstream file1;
    file1.open("file1.txt");
    if(file1.fail())
    {
        cout<<"fail"<<endl;
        exit(0);
    }


    for(int i=0;i<ROW+1;i++)
    {
        for(int z=0;z<COLUMN+1;z++)
        {
            file1<<worldArray[i][z]; if(DEBUG) cout<<worldArray[i][z];
            file1<<" ";
        }
        file1<<endl;
    }


   file1.close();

}
void Load(int worldArray[][COLUMN+1])
{
    int i,j,num;
    ifstream file1;

    if(DEBUG) cout<<"loading opening file..."<<endl;

    file1.open("file1.txt");
    if(file1.fail())
    {
        cout<<"Filed to open the file."<<endl;
        exit(0);
    }


    if(DEBUG) cout<<"reading file..."<<endl;

        for(i=0;i<ROW+1;i++)
        {
            for(j=0;j<COLUMN+1;j++)
            {
                 if(DEBUG) cout<<"num: "<<num<<endl;

                 file1>>worldArray[i][j]; if(DEBUG) cout<<"success cout"<<endl;
                    if(DEBUG) cout<<"worldArray: "<<worldArray[i][j]<<endl;
            }
        }


    file1.close();

    if(DEBUG) cout<<"closing file..."<<endl;
}

void Translate(int i,int j,float &screenX,float &screenY)
{
    screenX = ORIGINX+WIDTH*(j-1);
    screenY = ORIGINY-WIDTH*(i-1);

}

void TranslateBack(int &i,int &j,float screenX,float screenY)
{
    i = ((ORIGINY-screenY)/WIDTH)+1;
    j = ((screenX-ORIGINX)/WIDTH)+1;
}

void Kill(int worldArray[][COLUMN+1])
{
    int i,j;

    for(i=0;i<ROW+1;i++)
    {
        for(j=0;j<COLUMN+1;j++)
        {
            worldArray[i][j] = 0;
        }
    }
}

void RandomGenerator(int worldArray[][COLUMN+1])
{
    int count;

    srand((unsigned)time(0));

    for(count=1;count<=50;count++)
    {
        worldArray[GetRandomNum(1,20)][GetRandomNum(1,20)] = 1;
    }
}

int GetRandomNum(int lo, int hi)
{
    int range = hi-lo+1;
    int randomNumber = lo + (rand() % range);
    return randomNumber;

}

void InfiniteLoop(int worldArray[][COLUMN+1])
{
    char num='t'; if(DEBUG) cout<<"infinitloop"<<endl;

    while(num!='p')
    {
        Sleep(100);
        Step(worldArray);
        Display(worldArray);
    }
}

void SavePart(int worldArray[][COLUMN+1],int &length,int &width)
{
    int i,j,startI,startJ,endI,endJ;
    ofstream file1;
    file1.open("file1.txt");
    if(file1.fail())
    {
        cout<<"fail"<<endl;
        exit(0);
    }

    cout<<"start: ";
    cin>>startI;
    cin>>startJ;

    cout<<"end: ";
    cin>>endI;
    cin>>endJ;

    length = endJ-startJ+1;
    width = endI-startI+1;

    for(i=startI;i<=endI;i++)
    {
        for(j=startJ;j<=endJ;j++)
        {
            file1<<worldArray[i][j]<<" ";
        }

        file1<<endl;
    }

    file1.close();
}

void LoadPart(int worldArray[][COLUMN+1],int length, int width)
{
    int i,j,startI,startJ;

    ifstream file1;
    file1.open("file1.txt");
    if(file1.fail())
    {
        cout<<"Filed to open the file."<<endl;
        exit(0);
    }

    Kill(worldArray);

    cout<<"start: ";
    cin >>startI;
    cin>>startJ;

    for(i=startI;i<(startI+width);i++)
    {
        for(j=startJ;j<(startJ+length);j++)
        {
           file1>>worldArray[i][j];
        }
    }

    file1.close();
}
