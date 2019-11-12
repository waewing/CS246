#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "stack.h"
using namespace std;
using namespace ds;


bool IsOperator(char op)
{
  if(op == '+' || op == '-' || op == '*' || op == '/')
  {
    return true;
  }
  return false;
}

bool IsOperand(char op)
{
  if(op >= '0' && op <= '9')
  { 
    return true;
  }
	if(op >= 'a' && op <= 'z')
  { 
    return true;
  }
	if(op >= 'A' && op <= 'Z')
  {
  return true;
  }
	return false;
}

int OperatorValue(char op)
{
	int value = -1; 
	if (op == '+')
  {
    value = 1;
  }
	if (op == '-')
  {
    value = 1;
  }
	if (op == '*')
  {
    value = 2;
  }
  if (op == '/')
  {
    value = 2;
  }
	return value;
}

int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

int Precedence(char op1, char op2)
  {
    int op1Value = OperatorValue(op1);
    int op2Value = OperatorValue(op2);
 
    if(op1Value == op2Value)
    {
      if(IsRightAssociative(op1))
      {
        return false;
      }
      else 
      {
        return true;
      }
    }
    else if(op1Value > op2Value)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

string InFixtoPostFix(string str)
  {
    Stack <char> stack;
    string result = " ";
    int n = str.length();

    for(int i = 0; i < n; i++)
    {

      if(IsOperator(str[i]))
      {
        while(!stack.IsEmpty() && stack.Top() != '(' && Precedence(stack.Top(),str[i]))
        {
          result += stack.Top();
          stack.Pop();
        }
        stack.Push(str[i]);
      }

      else if(IsOperand(str[i]))
      {
        {
          result += str[i];
        }
      }

      else if (str[i] == '(') 
      {
        stack.Push(str[i]);
      }

      else if(str[i] == ')') 
      {
        while(!stack.IsEmpty() && stack.Top() !=  '(') 
        {
          result += stack.Top();
          stack.Pop();
        }
        stack.Pop();
      }
    }
    while(!stack.IsEmpty())
      {
        result += stack.Top();
        stack.Pop();
      }

    return result;
  }

  void ModeofArray(int *arr,int n) // used in mode 
  {
    int element = 0;
    int count = 0;
    
    for(int i = 0; i < n ; i++)
    {
      int tmpelement = arr[i];
      int tmpcount = 0;
      for(int j=0; j < n; j++)
        {
          if(arr[j] == tmpelement)
          {
            tmpcount++;
          }
        }

      if(tmpcount > count)
      {
        element = tmpelement;
        count = tmpcount;
      }
    }
  }

  int Mode(ifstream& infile)
  {
    infile.open("int.txt");
    int size;
    int *arr = new int[size];
    for(int i = 0;!infile.eof(); i++)
    {
       infile >> arr[i];
       size++;
    }

      int element = 0;
      int count = 0;

      for(int i = 0; i < size ; i++)
      {
        int tmpelement = arr[i];
        int tmpcount = 0;
        for(int j=0; j < size; j++)
          {
            if(arr[j] == tmpelement)
            {
              tmpcount++;
            }
          }

        if(tmpcount > count)
        {
          element = tmpelement;
          count = tmpcount;
        }
      }

      return element;
  }
  

int main() {


    /*
     Call for Mode function 3.0 points

    ifstream infile;
    cout << "Mode of the file is: " << Mode(infile) << "\n";
    */

    /*
    Call for InFixtoPostFix 1.5 points = 4.5 total

    string test = "A+B*(C+D)";
    cout << InFixtoPostFix(test) <<"\n";
    */



    /*
      Test of ModeofArray with random array

      int size;
      cout << "What is Array Size? : ";
      cin >> size;
      srand(time(NULL));
      int *arr = new int[size];
      for(int i = 0; i < size; i++)
      {
        arr[i] = rand() % 10 + 1;
        cout << "Element " << i << " is: " << arr[i] << "\n";
      }
      ModeofArray(arr,size);
      */
}
