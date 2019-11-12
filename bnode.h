#ifndef BNODE_H
#define BNODE_H
#include <iostream>
#include <string>
using namespace ds;

template <class T>
class BNode
{
private:
    BNode<T>* left;
    BNode<T>* right;
    T data;
    // bool leaf;
public:
    BNode() : BNode(NULL,NULL) {}
    
    BNode(BNode<T>* left, BNode<T>* right)
    {
        this->left = left;
        this->right = right;
    }

    BNode<T>* GetLeft() {return left;}
    
    const BNode<T>* GetLeft() const {return left;}
    
    BNode<T>* GetRight() {return right;}
    
    const BNode<T>* GetRight() const {return right;}

    void SetLeft(const BNode<T>* left)
    {
        this->left = left;
    }

    void SetRight(const BNode<T>* right)
    {
        this->right = right;
    }
 
    T& GetData()
    {
        return data;
    }

    void SetData(const T& data)
    {
        this -> data = data;
    }

    std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

    friend std::ostream& operator<<(std::ostream& out,const BNode<T>& obj)
		{
			out << obj.ToString();
			return out;
		}


();
};


#endif