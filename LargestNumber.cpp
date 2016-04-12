#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

string Solve(const vector<int> &A)
{
    int  i = 0;
    vector<int> temp(A.size());
    for( i = 0; i < A.size(); i++)
    {
        temp[i] = A[i];
    }

    sort(temp.begin(), temp.end(), [](int i, int j)
         {
            string is = std::to_string(i);

                string js = std::to_string(j);

                int value1 =  i * pow(10, js.size() ) + j;
                int value2 =  j* pow(10, is.size()) + i;

                return value1> value2 ? true : false;
         });
    string s;
    for ( auto iter  = temp.begin(); iter != temp.end(); iter++)
    {
        if ( *iter == 0)
        {
        string st = std::to_string(*iter);
        s.append(st);
        break;
    }
    else
    {
        string st = std::to_string(*iter);
        s.append(st);
    }
    }
    return s;
}
int main()
{
   vector<int> numbers(10);
   for ( int i = 0; i < 10; i++)
   {
       cin>>numbers[i];
   }
   cout<<Solve(numbers);
}
