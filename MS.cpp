
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
/************************************************************
Multiple Mathematical Operations
_________________________________________________________
This program is meant to calculate a varying amount of inputs
dependent on the operation chosen. Most of the operations are
mathmetical concepts many have worked on such addition and its
counterparts. Other operations include absolute value, square
root, quadratics, and the pythagorean formula.
_________________________________________________________
INPUT:
op: Name of operation to be chosen  -> input from user
num1: first number to be inputted -> input from user
num2: second number to be inputted if operation requires-> input from user
num3: third number to be inputted if operation requires -> input from user
OUTPUT:
cout: the program will output the equation used to evaluate
      with the inputs used displayed as well. Then the result
      will display.
 ***********************************************************/
int main() {

  // Constants
  string op;                      // INPUT - String that points to operations
  float num1,num2,num3;           // INPUT - Input values
  float rt1, rt2;                 // INPUT - Outputs for quadratic operation

  // Here the user prompted to choose an operation
  // and then inputs the corresponding amount of inputs
  cout << "Please choose an operation: " << endl;
  cin >> op;
  if (op == "fabs" || op == "sqrt" || op == "addition" || op == "subtraction" || op == "multiplication" || op == "division" || op == "pythagorean" || op == "quadratic"){
  cout << "Enter your first number: " << endl;
  cin >> num1;
  }
  if (op == "addition" || op == "subtraction" || op == "multiplication" || op == "division" || op == "pythagorean" || op == "quadratic") {
    cout << "Enter your second number: " << endl;
    cin >> num2;
  }

  if (op == "quadratic"){
    cout << "Enter your third number: " << endl;
    cin >> num3;
  }
  // Processes an addition operation
  if (op == "addition"){
    cout << "Equation: " << num1 << " + " << num2 << "\n" << "\n";
    cout << "Results: " << num1 + num2 << "\n";
    return 0;
  }
  // Processes a subtraction operation
  if (op == "subtraction"){
    cout << "Equation: " << num1 << " - " << num2 << "\n" << "\n";
    cout << "Results: " << num1 - num2 << "\n";
    return 0;
  }
  // Processes a multiplication operation
  if (op == "multiplication"){
    cout << "Equation: " << num1 << " * " << num2  << endl << "\n";
    cout << "Results: " << num1 * num2 << "\n";
    return 0;
  }
  // Processes a division operation and checks for errors
  if (op == "division"){
    cout << "Equation: " << num1 << " / " << num2 << "\n";
    if (num2 == 0){
      cout << "\n" << "Error: Cannot divide by zero.\n";

    }
    else
      cout << " = " << num1 / num2 << endl;
    return 0;
  }
  // Processes an absolute value operation
  if (op == "fabs"){
    cout << "Equation: " << "fabs(" << num1 << ")" << " \n" << "\n";
    cout << "Results: " << fabs(num1) << "\n";
    return 0;
  }
  // Processes a square root operation and possible errors
  if (op == "sqrt"){
    cout << "Equation: " << "sqrt(" << num1 << ")" << "\n" << "\n";

    if (num1 < 0){
      cout << "Error: Cannot take square root of a negative number.\n";
    }
    else
      cout << "Results: " << sqrt(num1) << "\n";
    return 0;
  }
  // Processes a quadratic polynomial roots and its errors
  if (op == "quadratic"){
    rt1 = (-num2 + sqrt((num2 * num2)- 4 * num1 * num3))/(2*num1);

    rt2 = (-num2 - sqrt((num2 * num2)- 4 * num1 * num3))/(2*num1);

    cout << "Equation: " << num1 << "x^2 + " << num2 << "x + " << num3 << " = 0" << endl << "\n";

    if (((num2 * num2)- 4 * num1 * num3) < 0){
      cout << "Error: Cannot take square root of a negative number." << endl;
    }
    else if (num1 == 0){
        cout << "Error: Cannot divide by zero.\n";
    }
    else
      cout << "Results: " << rt1 << ", " << rt2 << "\n";
    return 0;
    }
    // Processes the pythagorean formula
    if (op == "pythagorean"){
      cout <<  "Equation: sqrt(" << num1 << "^2" << " + " << num2 << "^2)" << endl << "\n";
      cout << "Results: " << sqrt((num1 * num1) + (num2 * num2)) << endl;
      return 0;
    }
    // Processes this statement when none of the above operations are inputted
  else
  cout << "Error: Operation not supported.\n";
}


