// Name: Wayne Ewing
// Program: Make a  shell

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "linkedlist.h"
#include "queue.h"
using namespace std;




void ParseString(string& a, string& b) // assign two strings a single string seperated by a space
{
  char str[1024];
  cin.getline(str,1024);
  char * pch;
  pch = strtok (str," "); //tokenizes str up to first space
  if (pch != NULL)
  {
    a = pch; //assigns the part of str before a space to a
    pch = strtok (NULL, " "); //gets rid of the space
  }
  if(pch == NULL)
  {
    b = ""; //if the pointer pch holds nothing else assign b to be empty
  }
  if (pch != NULL)
  {
    b = pch; //if pch isnt empty assign b to the remaining characters
    pch = strtok (NULL, " "); // remove any more spaces
  }

  while (pch != NULL)
  {
    pch = strtok (NULL, " "); //if there is anything else left set it to null
  }
}



template <class T>
void List(ds::Node<T>* root)
  {
    if(root == NULL) //if root is null do nothing
    {
      return;
    }
    else if(root->GetChild() == NULL) // if root has no child
    {
      cout << root->GetName() <<"\n";
    }
    else if(root->GetChild()->GetSibling() == NULL) // if root has a child
    {
      ds::Node<T>* tmp = root;
      cout << tmp->GetName() <<"\n";
      tmp = tmp->GetChild();
      cout << tmp->GetName() <<"\n";
    }
    else // if root has multiple children (siblings)
    {
      ds::Node<T>* tmp = root;
      cout << tmp->GetName() <<"\n";
      tmp = tmp->GetChild();
      cout << tmp->GetName() <<"\n";

      while(tmp->GetSibling() != NULL)
      {
        tmp = tmp->GetSibling();
        cout << tmp->GetName() <<"\n";
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
    if(name == "")
    {
      cout << "Directory can't have a NULL name.\n";
      return;
    }
    /*
    ds::Node<T>* checkname = root->GetChild();  // check for duplicate names
    while(checkname->GetSibling() != NULL)
    {
      if(name == checkname->GetName())
      {
      cout << "Error: Can't have duplicate names in same directory.";
      return;
      }
    }
    */

    if(root == NULL) // in case root is null 
    {
      root = new ds::Node<T>();
      root->SetName(name);
    }
    else if(root->GetChild() == NULL) // where root exists but child doesnt
    {
      root->SetChild(new ds::Node<T>());
      root->GetChild()->SetName(name);
      root->GetChild()->SetParent(root);
    }
    else //where root has a child but the child has no siblings
    {
      ds::Node<T>* tmp = root;
      tmp = tmp->GetChild();

      while(tmp->GetSibling() != NULL)
      {
        tmp = tmp->GetSibling();
      }

      tmp->SetSibling(new ds::Node<T>());
      tmp->GetSibling()->SetName(name);
      tmp->GetSibling()->SetPsibling(root);
    }
  }

  

template <class T>
void ChangeDirectory(ds::Node<T>* root, string name)
{

  
}



template <class T>
void Shell()
{

 string command;
 string arg1;
 string directory = "root";
 ds::Node<T>* root = NULL;


 cout << "\n\t\t CS246 Project Shell\n\n";

 while (command != "exit")
 {
   
   if(command == "ls")
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
   else if(command == "cd")
   {
     ChangeDirectory(root,arg1);
     directory = arg1;
   }
   else if(command != "\0")
   {
     cout << "Error: unkown command\n";
   }
   cout << "C:\\" << directory <<">";
   ParseString(command,arg1);
 }
}


int main ()
{
  Shell<string>();
  return 0;
}
