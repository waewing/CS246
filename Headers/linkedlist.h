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
    template <class T> 
        class Iterator
        {
            public:
                virtual bool HasNext() const = 0;
                virtual T& Next() = 0;
        };

        template <class T> 
        class SIterator : public Iterator<T>
        {
            private:
                Node<T>* root;
            public:
                SIterator() : SIterator(NULL) {}
                SIterator(Node<T>*& root) : root(root) {}
                bool HasNext() const{ return(root != NULL) ; }
                T& Next()
                {
                    T value = root->GetData();
                    root = root->GetLink();
                    return value;
                }
        };

        Iterator<T>* GetIterator()
        {
            return new SIterator(root);
        }

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

        void RemoveFromBack()
        {
            if(head != NULL)
            {
                if(head->GetLink() == NULL)
                {
                    delete[] head;
                    head = NULL;
                }
                else
                {
                    Node<T>* tmp = head;
                    while(tmp->GetLink()->GetLink() != NULL)
                    {
                        tmp = tmp->GetLink();
                    }
                    Node<T> olddata = tmp->GetLink();
                    tmp->SetLink(NULL);
                    delete[] olddata;
                    olddata = NULL;
                }
                size -= 1;
            }
        }      

        void RemoveFromFront()
        {
            if(head != NULL)
            {
                Node<T>* tmp = head;
                head = head->GetLink();
                tmp->SetLink(NULL);
                delete[] tmp;
                tmp = NULL;
                size -= 1;
            }
        }     

        void Remove(const T& value)
        {
            if(head != NULL)
            {
                if(head->GetData() == value)
                {
                    RemoveFromFront();
                }
                else
                {
                    Node<T>* tmp = head;

                    while(tmp->GetLink != NULL && tmp->GetLink()->GetData() != value)
                    {
                        tmp=tmp->GetLink();
                    }

                    if(tmp->GetLink() != NULL)
                    {
                        Node<T>* olddata = tmp->GetLink();
                        tmp->SetLink(olddata->GetLink());
                        delete olddata;
                        olddata = NULL;
                        size -=1 ;
                    }
                }
                
            }
        }

        bool IsEmpty() const
        {
            return head==NULL;
        }

        int Length() const
        {
            return size;
        }


        T& operator[](int index)
        {
            if(index >= 0 && index < size)
            {
                Node<T>* tmp=head;
                for(int i = 0; i < index; i += 1)
                {
                    tmp = tmp->GetLink();
                }
                return tmp->GetData();
            }
            throw "Out of Bounds";
        }

       const T& operator[](int index) const
        {
            if(index >= 0 && index < size)
            {
                Node<T>* tmp=head;
                for(int i = 0; i < index; i += 1)
                {
                    tmp = tmp->GetLink();
                }
                return tmp->GetData();
            }
            throw "Out of Bounds";
        }
        

    };
}



#endif



