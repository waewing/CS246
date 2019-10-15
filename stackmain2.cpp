#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include "stack.h"
using namespace std;
using namespace ds;


bool Format(char* str)
    {
        bool swtch = false;
        Stack<char> stack;
        if(str == NULL)
        {
            return true;
        }
        else 
        {
            int i = 0;
            while(str[i] != '\0' && !swtch)
            {   
                if(str[i] == '0')
                {
                    stack.Push('0');
                }
                else if(str[i] == '1')
                {
                    swtch = true;
                }
                else
                {
                    return false;
                }
            }

            if(!swtch)
            {
                return false;
            }
            else
            {
                while(str[i] != '\0')
                {
                    if(str[i] == '1')
                    {
                        stack.Pop();
                        if(stack.IsEmpty())
                        {
                            return false;
                        }
                        else
                        {
                            stack.Pop();
                        }
                        i++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }    
        }
        return stack.IsEmpty();
    }

int main()
{
    
}