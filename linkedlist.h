#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>
#include <string>
#include "node.h"

namespace ds
{

template <class T> 
class LinkedList
{
    private:

        Node<T>*head;
        int size;
    
    public:

        LinkedList(): head(NULL), size(0){};
        LinkedList(const LinkedList<T>& obj)
        {
            size = obj.size;
            head = Copy(obj.head);
        }
        LinkedList<T>& operator=(const LinkedList<T>& rhs)
        {
            if(this != &rhs)
            {
                size = rhs.size;
                Clear(head);
                head = Copy(rhs.head);
            }
            return *this;
        }

        ~LinkedList()
        {
            Clear(head);
        }

        void InsertInFront(const T& data)
        {
            if(head == NULL)
            {
                head = new Node<T>(data);
            }
            else
            {
                Node<T>* tmp = new Node<T>(data);
                tmp->SetLink(head);
                head = tmp;
            }
            size+=1;
        }

        void InsertInBack(const T& data)
        {
            if(head == NULL)
            {
                head = new Node<T>(data);
            }
            else
            {
                Node<T>* tmp = head;
                while(tmp->GetLink() != NULL)
                {
                tmp = tmp->GetLink();
                }
                tmp->SetLink(new Node<T>(data));
            }
            size+=1;
        }

        void InsertBefore(const T& value,  const T& data)
        {
            if(head != NULL)
            {
                if(head->GetData() == value)
                {
                    InsertInFront(data);
                }
                else
                {
                    Node<T>* tmp = head;
                    while(tmp->GetLink() != NULL && tmp->GetData() != value)
                    {
                        tmp=tmp->GetLink();
                    }
                    if(tmp->GetLink() != NULL)
                    {
                        Node<T>* newdata = new Node<T>(data);
                        newdata->SetLink(tmp->GetLink());
                        tmp->SetLink(newdata);
                        size+=1;
                    }
                }
                
            }
        }

        void InsertAfter(const T& value, const T& data)
        {
            if(head != NULL)
            {
                Node<T>* tmp=head;
                while(tmp->GetData() != value && tmp != NULL)
                {
                    tmp = tmp->GetLink();
                }
                if(tmp->GetLink() != NULL)
                {
                    Node<T>* newdata = new Node<T>(data);
                    newdata->SetLink(tmp->GetLink());
                    tmp->SetLink(newdata);
                    size+=1;
                }
            }
        }           
    };
}



