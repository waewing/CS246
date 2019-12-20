#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "vector.h"
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
using namespace std;




void ParseString(string& a, string& b)
{
  ds::Queue<char> que;
  string str;
  string command;
  string arg1;
  getline(cin,str);
  for(int i = 0; str[i] != '\0';i++)
  {
    que.Enqueue(str[i]);
  }

  int count = 0;

  if(que.IsEmpty() || que.Peek() == ' ')
  {
    count+=2;
  } 

  while(count < 1)
  {
    while(count < 1)
    {
      command = command + que.Peek();
      que.Dequeue();
      if(que.Peek() == ' ')
      {
      count += 1;
      }
      else if(que.IsEmpty())
      {
        a = command;
        count += 2;
      }
    }

    while(que.Peek() == ' ')
    {
      que.Dequeue();
    }
    a = command;
    if(que.IsEmpty())
    {
      count+=1;
    }
  }

  while(count < 2)
  {
    while(count < 2)
    {
      arg1 = arg1 + que.Peek();
      que.Dequeue();
      if(que.IsEmpty())
      {
        count +=1;
      }
    }
   b = arg1;
  }
}


/*
// definition of parse from prof

Vector<string> Parsing(string str)
{
  Vector<string> values;
  string word= " ";
  int n = str.size();
  for(int i= 0;i < n; i+=1)
  {
    if(str[i] == ' ')
    {
      values.Add(word);
      word = " ";
    }
    else
    {
      word = word + str[i];
    }
  }
  values.Add(word);
}




}

*/


template <class T>
void List(ds::Node<T>* root)
  {
    if(root == NULL) //if root is null do nothing
    {
      return;
    }
    else if(root->GetChild() == NULL) // if root has no child
    {
      cout << root->GetData() <<"\n";
    }
    else if(root->GetChild()->GetSibling() == NULL) // if root has a child
    {
      ds::Node<T>* tmp = root;
      cout << tmp->GetData() <<"\n";
      tmp = tmp->GetChild();
      cout << tmp->GetData() <<"\n";
    }
    else // if root has multiple children (siblings)
    {
      ds::Node<T>* tmp = root;
      cout << tmp->GetData() <<"\n";
      tmp = tmp->GetChild();
      cout << tmp->GetData() <<"\n";

      while(tmp->GetSibling() != NULL)
      {
        tmp = tmp->GetSibling();
        cout << tmp->GetData() <<"\n";
      }
    }
  }
  
  
/*

template <class T>
void Remove(ds::Node<T>* root,string name)
  {
    if(root->GetChild() == NULL && root->GetSibling() == NULL)
    {
      throw "Cannot be removed";
    }
    else if(root->GetChild() != NULL)
    {
      throw "Cannot be removed";
    }
    else if()
  }






template <class T>
void Touch(ds::Node<T>* root, string name)
  {
    ofstream of;
    root->SetData(of.open(name));
    of.close();
  }
  
*/


template <class T>
void MakeDirectory(ds::Node<T>*& root,string name)
  {
    if(root == NULL) // in case root is null 
    {
      root = new ds::Node<T>(name);
    }
    else if(root->GetChild() == NULL) // where root exists but child doesnt
    {
      root->SetChild(new ds::Node<T>(name));
    }
    else //where root has a child but the child has no siblings
    {
      ds::Node<T>* tmp = root;
      tmp = tmp->GetChild();
      while(tmp->GetSibling() != NULL)
      {
        tmp = tmp->GetSibling();
      }
      tmp->SetSibling(new ds::Node<T>(name));
    }
  }



template <class T>
void Shell()
{

 string command;
 string arg1;
 ds::Node<T>* root = NULL;

 cout << "\t CS246 Project Shell\n\n";

 while (command != "exit")
 {
   if(command == "cd")
   {
     
   }
   else if(command == "ls")
   {
     List(root);
   }
   else if(command == "rm")
   {
    // Remove(root,arg1);
   }
   else if(command == "mkdir")
   {
     MakeDirectory(root,arg1);
   }
   else if(command == "touch")
   {

   }
   else if(command != "\0")
   {
     cout << "Error: unkown command\n";
   }
   cout << "C:\\root> ";
   ParseString(command,arg1);
 }
}


int main() {

  Shell<string>();
  
return 0;
}
