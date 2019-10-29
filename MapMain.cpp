#include <iostream>
#include <string>
#include <cctype>
#include "linkedmap.h"
using namespace std;

void Mode(char str[])
{
    for(int i = 0 ; i < 6; i++)
    {   
        cout << tolower(str[i]);
    }
    return;
}

int main() 
{
    char text[] = "Hello";
    Mode(text);
    cout << "\n";

    return 0;
}