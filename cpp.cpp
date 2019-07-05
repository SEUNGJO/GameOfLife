#include <iostream>
#include<cstdlib>

using namespace std;
const int ROWS=22+2;
const int COLS=80+2;

int main()
{
    int count=0;
    int step=0;
    char ans;
    char life[ROWS][COLS];
    char temp[ROWS][COLS];
    char blank[ROWS][COLS];
    // Add outline
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;i<COLS;j++)
        {
            life[0][j]='+';
            life[ROWS-1][j]='+';
            life[i][COLS-1]='+';
            life[i][0]='+';
        }
    }
    //display life array
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<life[i][j];
            cout<<endl;
        }
    }
    //clear
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            life[i][j]=' ';
        }
    }
    //copy life array to temp and blank
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            temp[i][j]=life[i][j];
            blank[i][j]=life[i][j];
        }
    }
    int choice;
    cout<<"one two";
    for(int i=1;i<ROWS-1;i++)
    {
        for(int j=1;j<COLS-1;j++)
        {
            cout<<" options "<<i<<" row"<<j<<" col";
            cin>>choice;
            switch(choice)
            {
            case 1:
                life[i][j]='*';
                break;
            case 2:
                life[i][j]=' ';
                break;
            case 3:
                i=ROWS;
                j=COLS;
                break;
            case 4:
                i=i++;
                j=0;
                break;

            }
        }
    }
    //display
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout<<life[i][j];
        }
        cout<<endl;
    }
    do{
        step++;
            for(int i=1;i<ROWS-1;i++)
        {
            for(int j=1;j<COLS-1;j++)
            {
                if(life[i][j]=='*') count++;
                if(life[i-1][j]=='*') count++;
                if(life[i-1][j+1]=='*') count++;
                if(life[i][j-1]=='*') count++;
                if(life[i][j+1]=='*') count++;
                if(life[i+1][j-1]=='*') count++;
                if(life[i+1][j]=='*') count++;
                if(life[i+1][j+1]=='*') count++;
                if(count==3&&life[i][j]==' ') temp[i][j]='*';
                else if(count==2||count==3&&life[i][j]=='*') temp[i][j]='*';
                else temp[i][j]=' ';
            }

        }
            cout<<"step "<<step<<endl;
            for(int i=0;i<ROWS;i++)
            {
                for(int j=0;j<COLS;j++)
                {
                    life[i][j]=temp[i][j];
                    cout<<temp[i][j];
                }
            }
            for(int i=0;i<ROWS;i++)
            {
                for(int j=0;j<COLS;j++)
                {
                    temp[i][j]=blank[i][j];
                }
            }
            cin>>ans;
    }while(ans=='y'||ans=='Y');
    return 0;
}
