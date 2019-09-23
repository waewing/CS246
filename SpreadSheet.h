#include <iostream>
#include <string>
using namespace std;

class SpreadSheet{

  private:
    double *grid; // .1
    int columns; // .1 total .2
    int rows; // .1 total .3

  public:
    SpreadSheet(){ columns = 10; rows = 15; *grid = 0.0;}; // .1 total .4

    SpreadSheet(const SpreadSheet& obj){ // .1 total .5
      columns = obj.columns;
      rows = obj.rows;
      grid = new double [columns,rows];
    }
  
  SpreadSheet operator=(const SpreadSheet rhs){ //.1 total .6
      if(this != &rhs)
      {
        columns = rhs.columns;
        rows = rhs.rows;
        grid = new double [columns, rows];
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
      if(coordinate <= 26 && rows <= 99)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    
};

int main() {
  
}
