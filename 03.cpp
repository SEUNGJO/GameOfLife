#include <iostream>
#include <cmath>

using namespace std;

int main()
{




        // output the class heading to the screen
        cout << "*********************************************************\n";
        cout << " Lab #1 : Assignment 03\n";
        cout << "*********************************************************\n";


        string operation;
        int quadratic, addition;
        cout <<"Please choose an operator :";
        cin >> operation;


    if(operation = quadratic)
    {
        float a, b, c, x1, x2, determinant, realPart, imaginaryPart;

        cout << "Enter your first number :";
        cin >> a;
        cout << "Enter your second number :";
        cin >> b;
        cout << "Enter your third number :";
        cin >> c;

        cout<< "Equation is :"<< a<<"*x^2 + "<<b<< "*x + "<<c<< "=0";


            determinant = b*b - 4*a*c; //discriminant

         if (determinant > 0) {
                 x1 = (-b + sqrt(determinant)) / (2*a);
                 x2 = (-b - sqrt(determinant)) / (2*a);
                 cout << "\nRoots are real and different." << endl;
                 cout << "x1 = " << x1 << endl;
                 cout << "x2 = " << x2 << endl;
             }

             else if (determinant == 0) {
                 cout << "\nRoots are real and same." << endl;
                 x1 = (-b + sqrt(determinant)) / (2*a);
                 cout << "x1 = x2 =" << x1 << endl;
             }

             else {
                 realPart = -b/(2*a);
                 imaginaryPart =sqrt(-determinant)/(2*a);
                 cout << "\nRoots are complex and different."  << endl;
                 cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
                 cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
             }

    }

    else if(operation=addition)
    {
        float a;
        float b;
        cout << "Enter your first number :";
        cin >> a;
        cout << "Enter your second number :";
        cin >> b;
        cin.ignore();
        cout<< "Equation is :"<<a<< "+"<<b;
        int result = a+b;
        cout << "\nResult is" << " "<<result<<endl;
        cin.get();
    }

    else if(operation==division)
    {
        float a, b, c;
        cout <<"Enter your first number :";
        cin >> a;
        cout <<"Enter your second number :";
        cin >> b;
        c = a/b;
        if(b == 0)
        {
            cout <<" Error: cannot devide by zero";
        }
        else
        {
        cout<< "Equation is :"<<a<<"/"<<b;
        cout <<"\nResult is:"<<c<<endl;
    }
    }
    else if(operation==squareroot)
    {
        double a, x;
        cout <<"Enter your first number :";
        cin >> a;
        x = sqrt(a);
        if(a<0)
        {
            cout <<"Cannot take square root of a negative number\n";
        }
        else
        {
           cout <<"Equation is: sqrt"<<"("<<a<<")"<<endl;
           cout <<"Result is :"<<x<<endl;
        }
    }

    else if(operation==pythagorean)
    {
        float a, b, c;
        while (a >0 && b > 0);
        cout <<"\nEnter your first number :";
        cin >> a;
        cout << "\nEnter your second number :";
        cin >> b;
        c = sqrt(a*a+b*b);
        cout<<"Equation is: sqrt"<<"("<<a<<"^2"<<" + "<<b<<"^2"<<")"<<endl;
        cout <<"Result is :"<<c<<endl;

    }

    else if(operation==floatabs)
    {
        int a;
        cout <<"Enter your first number :";
        cin >> a;

        cout<<"Equation is: fabs"<<"("<<a<<")"<<endl;
        cout <<"Result is:"<<fabs(a)<<endl;
    }

    else if(operation==modolus)
    {
        cout <<"Error: Operation is not supported\n";
    }
    return 0;
    }


    return 0;
}

