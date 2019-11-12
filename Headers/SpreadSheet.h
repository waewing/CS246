#include <iostream>
#include <sstream>
#include <string>
#include <locale>
using namespace std;

template <class T>
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
      grid = new double [columns*rows]; 
        for(int i = 0; i < columns; i++)
        {
          for(int j = 0; j < rows; j++)
          {
           *(grid + i*rows+j) = 0.0;
          }
        } 
      }

    SpreadSheet(const SpreadSheet& obj){ // .1 total .5
      columns = obj.columns;
      rows = obj.rows;
      grid = new double [columns*rows];
    }
  
  SpreadSheet operator=(const SpreadSheet rhs){ //.1 total .6
      if(this != &rhs)
      {
        columns = rhs.columns;
        rows = rhs.rows;
        grid = new double [columns*rows];
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
      if(isalpha(columns) && isdigit(rows))
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
           return grid[columns*rows] = coordinate;
         }
         else
         {
           throw "Invalid Coordinate";
         }
     }
   
      
   	std::string ToString() const //.4 total 1.7
	    {
			std::stringstream out;

			out << "[";

			for(int i = 0;i < columns;i++)
			  {
          for(int j = 0;j < rows;j++)
          {
            out << *(grid + i*rows+j) <<"\n";
          }
			  }

			out << "]";
			return out.str();
		}
      
      friend std::ostream& operator<<(std::ostream& out,const SpreadSheet& obj) //.1 total 1.8
		{
			out << obj.ToString();
			return out;
		}
	
	const double GetCell(string coordinate) // .2 total 2.0
	{
		if(IsCoordinate(coordinate) == true)
		{
			return grid[columns*rows] = coordinate;
		}
		else
		{
			throw "Invalid Coordinate";		
		}
  }
		
	void SetCell(string coordinate, double value) //.2 total 2.2
	{
		if(IsCoordinate(coordinate) == true)
		{
			return grid[columns*rows] = coordinate;
		}
		else
		{
			throw "Invalid Coordinate";		
		}	
	}
		
	double operator[](string coordinate) //.2 total 2.4
	{
		if(IsCoordinate(coordinate) == true)
		{
			return grid[columns*rows] = coordinate;
		}
		else
		{
			throw "Invalid Coordinate";		
		}	
	}
		
  double& operator[](string coordinate) const //.2 total 2.6
	{
		if(IsCoordinate(coordinate) == true)
		{
			return grid[columns*rows] = coordinate;
		}
		else
		{
			throw "Invalid Coordinate";		
		}	
	}
		
	bool InsertColumnBefore(char newc) //.4 total 3.0
	{
		if(isalpha(newc) == true)
		{
      grid = grid[newc];
			grid = new double [columns];
      for(int i = 0; i < columns; i++)
      {
          grid[i] = 0;
      }
			return true;
      }
      else
      {
        return false;
      }
	}

  bool InsertColumnAfter(char newc) // .4 totals 3.4
  {
    if(isalpha(newc) == true)
		{
      grid = grid[newc + 1];
			grid = new double [columns];
      for(int i = 0; i < columns; i++)
      {
          grid[i] = 0;
      }
			return true;
      }
      else
      {
        return false;
      }
  }

  bool InsertRowBefore(int newr) //.4 total 3.8
	{
		if(isdigit(newr) == true)
		{
      grid = grid[newr];
			grid = new double [rows];
      for(int i = 0; i < rows; i++)
      {
          grid[i] = 0;
      }
			return true;
      }
      else
      {
        return false;
      }
	}


  bool InsertRowAfter(int newr) //.4 total 4.2
	{
		if(isdigit(newr) == true)
		{
      grid = grid[newr + 1];
			grid = new double [rows];
      for(int i = 0; i < rows; i++)
      {
          grid[i] = 0;
      }
			return true;
      }
      else
      {
        return false;
      }
	}

  	bool RemoveColumnBefore(char rmc) //.4 total 4.6
	{
		if(isalpha(rmc) == true)
		{
			delete grid[rmc-1];
			return true;
      }
      else
      {
        return false;
      }
	}

    bool RemoveColumnAfter(char rmc) //.4 total 5.0
	{
		if(isalpha(rmc) == true)
		{
			delete grid[rmc+1];
			return true;
      }
      else
      {
        return false;
      }
	}	
};
