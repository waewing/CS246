#ifndef test.h
#define test.h
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Shape
{
    double *sides;
    int sidesCount;

    public:

        Shape(): sides(NULL), sidesCount(0) {}; // default constructor
        Shape(const Shape& obj) // copy constructor  
        {  
            if(obj.sides == NULL)
            {
                sides = NULL;
                sidesCount(0);
            }
            else
            {
                sidesCount = obj.sidesCount;
                sides = new double [sidesCount];
                for(int i = 0;<sidesCount;i+=1)
                    {
                        sides[i] = obj.sides[i];
                    }
            }  
        }  
        Shape& operator=(const Shape& rhs) //ovlerloaded assignment operator
            {
                if(this != &rhs)
                    {
                        if(rhs.sides == NULL)
                        {
                            sides = NULL;
                            sidesCount(0);
                        }
                        else
                        {
                            sidesCount = rhs.sidesCount;
                            sides = new double [sidesCount];
                                for(int i = 0;<sidesCount;i+=1)
                                    {
                                        sides[i] = rhs.sides[i];
                                    }       
                          
                        }
                        return *this;
            }
        ~Shape()
        {
            delete[]sides;
        }

        Shape(int sides): sidesCount(sides) // overloaded constructor
        {
            if(sidesCount <= 0)
            {
                sidesCount = 3;
            }

            this-> sides = new double[sidesCount];
            for(int = 0; i < sidesCount; i+=1)
            {
                sides[i] = 1.0;
            } 
        }
        // Encapsulation
        int GetSides() const
        {
            return sidesCount;
        }
        
        int GetSides()
        {
            return sidesCount;  // sidesCount is read-only cannot be modified by setters
        }

        const double& GetSide(int index) const
        {
            if(index>= 0 && index < sidesCount)
            {
                return sides[index];
            }
            throw "Out of Bounds";
        }

        double& GetSide(int index) 
        {
            
            if(index >= 0 && index < sidesCount) 
            {
                return sides[index];
            }
            throw "Out of Bounds";
        }

        void SetSide(int index, double value)
        {
            if (index >= 0 && index < sidesCount && value > 0)
            {
                    sides[index] = value; // sides is read-write
            }
        }

        const double& operator[](int index) const // overloaded access operator read only
        {
            if(index >= 0 && index < sidesCount)
            {
                return sides[index];
            }
            throw "Out of Bounds";
        }

        double& operator[](int index)
        {
            if(index >= 0 && index < sidesCount)
            {
                return sides[index];
            }
            throw "Out of Bounds";

        }

        // ecapsulation is the process of making your fields private



        virtual double Perimeter() const = 0; // pure virtual function
        virtual double Perimeter() = 0;

        virtual double Area() const = 0;
        virtual double Area() = 0;

        string ToString() const
        {
            stringstream out;
            out << "[ ";
            for(int i = 0; i < sidesCount; i += 1)
            {
                out << sides[i];
                if(i+1 != sidesCount)
                {
                    out < ",";
                }
            }
            out << "]";
            return out.str();
        }

        friend ostream& operator<<(ostream& out, const Shape& obj)
        {
            out << obj.ToString();
            return out;
        }

};

class Rectangle: public Shape //Inheritance
{

    Rectangle(): /* member initilization list : */ Shape(2){}

    Rectangle(double length, double width): Rectangle() 
    {
        if(length>0 && width >0)
        {
            SetSide(0,(length < width)?(length):(width));
            SetSide(1,(length > width)?(length):(width));
        }
    }

    Rectangle(const Rectangle& obj): Shape(dynamic_cast<const Shape&>(obj)){}

    Rectangle& operator=(const Rectangle& rhs)
    {
        if(this != rhs)
        {
            Shape::operator=(dynamic_cast<const Shape&>(rhs));
        }
        return *this;
    }

    public:

        ~Rectangle(){}
        
        void SetWidth(double value)
        {
            if (GetSide(1) >= value & value > 0)
            {
                SetSide(0,value);
            }
        }

        void SetLength(double value)
        {
            if(GetSide(0) <= value && value > 0)
            {
                SetSide(1,value);
            }
        }

        double GetWidth()
        {
            return GetSide(0);
        }

        double GetLength()
        {
            return GetSide(1);
        }
        
        double Perimeter() const
        {
            return 2*(GetSide(0)+GetSide(1));
        }

        double Perimeter()
        {
            return 2*(GetSide(0)+GetSide(1));
        }

        double Area() const
        {
            return (GetSide(0)*GetSide(1));
        }

        double Area()
        {
            return (GetSide(0)*GetSide(1));
        }

    friend ostream& operator<<(ostream& out, const Rectangle& obj)
    {
        out << obj.ToString();
        return out;
    }

    private:

        using Shape::GetSide;
        using Shape::SetSide;
        using Shape::GetSides;
        using Shape::GetSide const;

};

#endif

            
