#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "graph.h"
#include "linkedlist.h"
#include "stack.h"
#include "staticqueue.h"

using namespace std;


/*
template <class T>
void ParseString(string command, string arg1, string arg2)
{
  ds::StaticQueue<char> que;
  string str;
  cin >> str;
  for(int i = 0; str[i] != '\0';i++)
  {
    que.Enqueue(str[i]);
  }

  int count = 0;
  while(count != 3)
  {
    for(int i=0; count < 1;i++)
    {
      command[i] = que.Peek();
      que.Dequeue();
      if(que.Peek() == ' ')
      {
      count += 1;
      }
    }

    while(que.Peek() == ' ')
    {
      que.Dequeue();
    }

    for(int i=0; count < 2;i++)
    {
      arg1[i] = que.Peek();
      que.Dequeue();
      if(que.Peek() == ' ')
      {
      count += 1;
      }
    }

    while(que.Peek() == ' ')
    {
      que.Dequeue();
    }

    for(int i=0; count < 3;i++)
    {
      arg2[i] = que.Peek();
      que.Dequeue();
      if(que.Peek() == ' ')
      {
      count += 1;
      } 
    }

    while(que.Peek() == ' ')
    {
      que.Dequeue();
    }
  }
}



void ChangeDirectory()
  {

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
      return; 
    }
    else if(root->GetChild() != NULL)
    {
      ds::LinkedList<T>* tmp = root;
      tmp = tmp->GetChild();
      while(tmp->GetSibling() != NULL)
      {
        tmp = root;
        tmp= tmp->GetChild();
        while(tmp->GetSibling() != NULL)
        {
          tmp = tmp->GetSibling();
        }
        tmp->RemoveFromBack();
      }
      tmp->RemoveFromBack();
    }
  }

*/



/*
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
 string arg2;
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
   cout << "C:\\root" << arg1 << "> ";
   cin >> command;
 }
}



int main() {

  Shell<string>();
}
