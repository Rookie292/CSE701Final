
#include <iostream>
#include <algorithm>
#include "bigint.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

void demo()

{   //two constructors
    BigInt num1;
    BigInt num2(-1234678291346789);
    cout << "num1:"<<num1<<"  ";
    cout << "num2:"<<num2<<"\n";
    // + and =+ overload
    cout << "num1 + num2 = "<< num1 + num2<<'\n';
    cout  << "num1 += num2 ";
    num1+=num2;
    cout << "num1:" << num1<< '\n' ;
    // constructor from string
    try
    {
        BigInt num3("+348d7793fff");
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
    // constructor from string
    BigInt num4("+83648264728920303");
    // = overload
    num2 = num4;
    cout << "num1:"<<num1<<"  "<< "num2:"<<num2<<"  "<< "num4:"<<num4<<"\n";
    // - and -= overload
    cout  << "num1 -= num2 ";
    num1-=num2;
    cout << "num1:" << num1<< '\n' ;
    cout << "num1 - num2 = "<< num1 - num2<<'\n';
    // * and *= overload
    BigInt num5(-1);
    cout << "num1:"<<num1<<"  "<< "num5:"<<num5<<"\n";
    cout  << "num1 *= num5 ";   
    num1*=num5;
    cout << "num1:" << num1<< '\n' ;
    BigInt num6 = num1 * num5;
    cout << "num6 = num1 * num5\n";
    cout << "num6:" << num6<< '\n' ;
    // - overload
    -num6;
    cout << "num6:" << num6<< '\n' ;
    cout << "num1:"<<num1<<"  "<< "num2:"<<num2<<"  "<< "num4:"<<num4<<"  "<< "num5:"<<num5<<"  "<< "num6:"<<num6<<"\n";
    // comparison operator overload
    cout << "num2 == num4 result:"<<(num2 == num4)<<'\n';
    num2 = 0;
    cout << "num1:"<<num1<<"  "<< "num2:"<<num2<<"  "<< "num4:"<<num4<<"  "<< "num5:"<<num5<<"  "<< "num6:"<<num6<<"\n";
    cout << "num2 != num4 result:"<<(num2 != num4)<<'\n';
    cout << "num1 >= num4 result:"<<(num1 >= num4)<<'\n';
    cout << "num1 <= num4 result:"<<(num1 <= num4)<<'\n';
    num1 = "0";
    cout << "num1:"<<num1<<"  "<< "num2:"<<num2<<"  "<< "num4:"<<num4<<"  "<< "num5:"<<num5<<"  "<< "num6:"<<num6<<"\n";
    cout << "num1 > num2 result:"<<(num1 > num2)<<'\n';
    cout << "num1 < num5 result:"<<(num1 > num5)<<'\n';
    cout << endl;
}

int main()
{
    //here is a demo
    demo();
    // the following shows that read input from demo.txt file.
    try
    {
        ifstream input("demo.txt");
        if (!input.is_open())
        {
            cout << "Error opening file! You should create a demo.txt file to give the input and there is a demo.\n";
            cout << "String in demo.txt:\n" << "1234\n" << "0\n" << "+\n";
            cout << "The output in the terminal will be like\n";
            BigInt demo1(1234);
            BigInt demo2;
            cout << demo1 << "+" << demo2 << '\n';
            cout << "Result: " << demo1 + demo2 << '\n';
            return -1;
        }
        string s;             // a string to hold each line
        vector<string> token; // a vector to store each line.
        vector<BigInt> num;   // a vector to store each dight string

        while (getline(input, s))
        {
            token.push_back(s);
        }
        for (size_t i = 0; i < token.size() - 1; i++)
        {
            BigInt temp(token[i]);
            num.push_back(temp);
        }
        string operation = token.back();
        if (operation == "+")
        {
            cout << num[0] << "+" << num[1] << '\n';
            cout << "Result: " << num[0] + num[1] << '\n';
        }
        else if (operation == "+=")
        {

            cout << num[0] << "+=" << num[1] << '\n';
            num[0] += num[1];
            cout << "Result: " << num[0] << '\n';
        }
        else if (operation == "-" && num.size() == 2)
        {
            cout << num[0] << "-" << num[1] << '\n';
            cout << "Result: " << num[0] - num[1] << '\n';
        }
        else if (operation == "-=")
        {

            cout << num[0] << "-=" << num[1] << '\n';
            num[0] -= num[1];
            cout << "Result: " << num[0] << '\n';
        }
        else if (operation == "*")
        {
            cout << num[0] << "*" << num[1] << '\n';
            cout << "Result: " << num[0] * num[1] << '\n';
        }
        else if (operation == "*=")
        {

            cout << num[0] << "*=" << num[1] << '\n';
            num[0] *= num[1];
            cout << "Result: " << num[0] << '\n';
        }
        else if (operation == "-" && num.size() == 1)
        {
            cout << num[0] << '\n';
            -num[0];
            cout << "Result: " << num[0] << '\n';
        }
        else if (operation == "==")
        {
            cout << num[0] << "==" << num[1] << '\n';
            cout << "Result: " << (num[0] == num[1]) << '\n';
        }
        else if (operation == "!=")
        {
            cout << num[0] << "!=" << num[1] << '\n';
            cout << "Result: " << (num[0] != num[1]) << '\n';
        }
        else if (operation == "<")
        {
            cout << num[0] << "<" << num[1] << '\n';
            cout << "Result: " << (num[0] < num[1]) << '\n';
        }
        else if (operation == ">")
        {
            cout << num[0] << ">" << num[1] << '\n';
            cout << "Result: " << (num[0] > num[1]) << '\n';
        }
        else if (operation == "<=")
        {
            cout << num[0] << "<=" << num[1] << '\n';
            cout << "Result: " << (num[0] <= num[1]) << '\n';
        }
        else if (operation == ">=")
        {
            cout << num[0] << ">=" << num[1] << '\n';
            cout << "Result: " << (num[0] >= num[1]) << '\n';
        }
        else if (operation == "=")
        {
            cout << "num1:" << num[0] << "  "
                 << "num2:" << num[1] << '\n';
            cout << "operation: num1 = num2" << '\n';
            num[0] = num[1];
            cout << "num1:" << num[0] << "  "
                 << "num2:" << num[1] << '\n';
        }
        else
        {
            cout << "Please give another valid operation in demo.txt file" << endl;
        }
        input.close();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}