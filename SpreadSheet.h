#include <iostream>
#include <string>
#include <locale>
using namespace std;

class SpreadSheet{

  private:
    double *grid; // .1
    int columns; // .1 total .2
    int rows; // .1 total .3

  public:
    SpreadSheet()// .1 total .4
      {
      columns = 10; 
      rows = 15; 
      *grid = new int[columns*rows]; 
        for(int i = 0; i < columns; i++)
        {
          for(int j = 0; j < rows; j++)
          {
           *(grid + i*rows+j) = 0;
          }
        } 

    SpreadSheet(const SpreadSheet& obj){ // .1 total .5
      columns = obj.columns;
      rows = obj.rows;
      grid = new double [columns][rows];
    }
  
  SpreadSheet operator=(const SpreadSheet rhs){ //.1 total .6
      if(this != &rhs)
      {
        columns = rhs.columns;
        rows = rhs.rows;
        grid = new double [columns][rows];
      }
      return *this;
    }
    
    ~SpreadSheet(){ delete[]grid; } // .1 total .7
    
    int Columns(){ // .1 total .8
      return columns;
    }
    
    int Rows(){ // .1 total .9
      return rows;
    }
    
    const bool IsCoordinate(string coordinate){ //.2 total 1.1
      if(islanum(columns) && isalnum(rows))
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  
    const int GetIndex(string coordinate){ //.2 total 1.3
      if(IsCoordinate(coordinate) == true)
         {
           return coordinate;
         }
         else
         {
           throw "Invalid Coordinate";
         }
     }
  
    const int GetCell(string coordinate){ //.2 total 1.5
      if(IsCoordinate(coordinate) == true)
         {
           return coordinate;
         }
         else
         {
           throw "Invalid Coordinate";
         }
     }
         
         
};



int main() {
  
}
