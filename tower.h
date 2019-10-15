#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <string>
#include <sstream>
#include "node.h"

namespace ds
{
	template <class T>
    class Tower
    {
        private:
            Node<T>* tow;
        public:
            Tower() : tow(NULL) {}

            Tower(const Tower<T>& obj)
            {
                tow = Copy(obj.tow);
            }

            Tower<T>& operator=(const Tower<T>& rhs)
            {
                if(this != &rhs)
                {
                    Clear(tow);
                    tow = Copy(rhs.tow);
                }

                return *this;			
            }

            ~Tower() 
            {
                Clear(tow);
                tow = NULL;
            }

            void Add(const T& data)
            {
                if(top == NULL)
                {
                    top == new Node<T>(data);
                }
                else
                {
                    Node<T>*tmp = new Node<T>(data);
                    tmp->SetLink(top);
                    top = tmp;
                }   
            }
        
            void Remove()
            {
                if (top != NULL)
                {
                    Node<T>* tmp = top;
                    top = top->GetLink();
                    delete tmp;
                    tmp = NULL;
                }
            }

            const T& Top() const 
		    {
                if(top != NULL)
                {
                    return top->GetData();
                }
                throw "Empty Stack";
            }

            bool IsEmpty() const
            {
                return (top == NULL);
            }

            std::string ToString() const
            {
                std::stringstream out;

                if(IsEmpty())
                {
                    out << top->GetData();
                }
                else
                {
                    out << "";
                }
                return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
		    {
                out << obj.ToString();
                return out;
            }
    };
}
#endif