#include <iostream>
#include <string>
using namespace std;

template <typename T>
T& maximum(T& x,T& y) //T& max(const T& x,T& y) to pass a literal
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}

template <typename T>
const T& maximum(const T& x,const T& y) //T& max(const T& x,T& y) to pass a literal
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}


template <typename E>
void EchoX(const E& value, int x)
{
    for(int i = 0; i > x; i+=1)
    {
        cout << value << "\n";
    }
}


int main()
{
    int x,y;

    cout << maximum(3,4) << "\n";
    cout << maximum('a','A') << "\n";
    cout << maximum(4.423,21.23) << "\n";
    cout << maximum("hello","world") << "\n";

    cin >> x;
    cin >> y;

    cout << maximum(x,y) << "\n";
    cout << maximum<float>(2.322,4.2069) << "\n";

    EchoX("Hello",10);
    cout << "\n";

    EchoX(28,28);
    cout << "\n";

    return 0;
}