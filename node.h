#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>
 template <class T>
 class Node
 {
     
     private:

     T data;
     Node<T>* link;
 }