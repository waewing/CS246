#ifndef BBNODE_H
#define BBNODE_H
#include <iostream>
#include <string>
using namespace ds;

template <class T>
class BBNode
{
    private:
    BBNode<T>* left;
    BBNode<T>* right;
    BBNode<T>* parent;
    T data;
    //bool leaf;

    public:

    BBNode() : BBNode(NULL,NULL,NULL) {}

    BNode(BBNode<T>* left, BBNode<T>* right,BBNode<T>* parent)
    {
        this->left = left;
        this->right = right;
        this->parent = parent;
    }

    BBNode<T>* GetLeft() {return left;}
    
    const BBNode<T>* GetLeft() const {return left;}
    
    BBNode<T>* GetRight() {return right;}
    
    const BBNode<T>* GetRight() const {return right;}

    BBNode<T>* GetParent() {return parent;}

    const BBNode<T>* GetParent() const {return parent;}

    void SetLeft(const BBNode<T>* left)
    {
        this->left = left;
    }

    void SetRight(const BBNode<T>* right)
    {
        this->right = right;
    }

    void SetParent(const BBNode<T>* parent)
    {
        this->parent = parent;
    }

    T& GetData()
    {
        return data;
    }

    void SetData(const T& data)
    {
        this -> data = data;
    }

    BBNode<T>* Copy(BBNode<T>* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BBNode<T>* tmp = new BBNode<T>(root->GetData());
        tmp->SetParent(parent);
        tmp->SetLeft(Copy(tmp,root->GetLeft()));
        tmp->SetRight(Copy(tmp,root->GetRight()));
        return tmp;
    }

    void Clear(BBNode<T>*& root)
    {
        if(root != NULL)
        {
            Clear(root->GetLeft());
            Clear(root->GetRight());
            root->SetParent(NULL);
            delete root;
            root = NULL;  
        }
    }
    void infix(BBNode<T>* root)
    {
        if(root != NULL)
        {
            infix(root->GetLeft());
            std::cout << root->GetData();
            infix(root->GetRight());
        }
    }

    void prefix(BBNode<T>* root)
    {
        if(root != NULL)
        {
            std::cout << root->GetData();
            infix(root->GetLeft());
            infix(root->GetRight());
        }
    }

    void postfix(BBNode<T>* root)
    {
        if(root != NULL)
        {
            infix(root->GetLeft());
            infix(root->GetRight());
            std::cout << root->GetData();
        }
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


};


#endif