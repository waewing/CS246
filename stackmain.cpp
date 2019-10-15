#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "stack.h"
using namespace std;
using namespace ds;


void ReverseFile(ifstream& in)
    {
        Stack<char> stack;
        char ch;
        while(in >> ch)
        {
            if(ch != ' ' && ch != '\n')
            {
                stack.Push(ch);
            }
        }

        ofstream out("reverse.txt");
        while(!stack.IsEmpty())
        {
            out << stack.Top();
            stack.Pop();
        }
        out.close();
    }

int main()
{
    
    return 0;
}