#include <iostream>
#include <string>
#include <cctype>
#include "linkedmap.h"
using namespace std;
using namespace ds;

char Mode(string str)
{
    LinkedMap <char,int> map;
    char ch;
    int max = 1;
    for(int i = 0 ; str[i] != '\0'; i++)
    {   
        ch = tolower(str[i]);
        if(islower(ch))
        {
            if(map.HasKey(ch))
            {
                map[ch]++;
            }
            else
            {
                map.Put(ch,1);
            }
            if(max < map[ch])
            {
                max = map[ch];
            }
        }
    }
    if(map.IsEmpty())
    {
        return '\0';
    }
    for (char i = 'a' ; i<= 'z'; i+= 1)
    {
        if(max == map[i])
        {
            return i;
        }
    }

}
    


int main() 
{
    string text = "Hello";
    cout << Mode(text) << "\n";

    return 0;
}