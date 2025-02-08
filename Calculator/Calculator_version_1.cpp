#include <iostream>
#include <limits> // For input validation
#include <fstream>  // for file storage

using namespace std;

// Function prototypes
int addition(int var1, int var2);
int subtraction(int var1, int var2);
int multiplication(int var1, int var2);
int division(int var1, int var2);

int main() 
{
    int var1, var2=0;
    int result =0;    char opt = 0; // Use char for operator input
    bool continuousCalculation = true;

    ofstream outfile("result.txt", ios::app);

    if(!outfile)
    {
        cerr << "Error:could not open the file\n"<< endl;
        return 1;
    }

    while (continuousCalculation) 
    {
        cout << "Enter first number: " << endl;
        cin >> var1;

        //Input validation for second number


        cout << "Enter the operation (+, -, *, /) or Q to quit: " << endl;
        cin >> opt;


        if (opt == 'q' || opt == 'Q') {
            continuousCalculation = false;
            break;
        }

        cout << "Enter second number: " << endl;
        cin >> var2;

        //Input validation for second number
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error:invalid input please check\n"<< endl;
            continue;
        }
       
        switch (opt) {
            case '+':
                result = addition(var1, var2);
                cout << "Result: " << result << "\n\n" << endl;

                outfile << var1 << "+"<< var2 << "="<< result << endl;
                break;

            case '-':
                result = subtraction(var1, var2);
                cout << "Result: " <<result << "\n\n" << endl;
                outfile << var1 << "-"<< var2 << "="<< result << endl;
                break;

            case '*':
                 result = multiplication(var1, var2);
                cout << "Result: " <<result << "\n\n" << endl;
                outfile << var1 << "*"<< var2 << "="<< result << endl;
                break;

            case '/':
                if (var2 == 0) {
                    cout << "Error: Division b55y zero!\n\n" << endl;
                } else {
                    result = division(var1, var2);
                    cout << "Result: " << result << "\n\n" << endl;
                    outfile << var1 << "/"<< var2 << "="<< result << endl;
                }
                break;

            default:
                cout << "Invalid operator! Please use +, -, *, /, or Q to quit.\n\n" << endl;
        }
    }
    outfile.close();
    cout << "file is closed \n"<<endl;
    return 0;
}

// Function definitions
int addition(int var1, int var2) {
    return var1 + var2;
}

int subtraction(int var1, int var2) {
    return var1 - var2;
}

int multiplication(int var1, int var2) {
    return var1 * var2;
}

int division(int var1, int var2) {
    return var1 / var2; // Division by zero is handled in main()
}
