#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
using namespace std;

long long isPrime( long long n)
{
    if ( n == 2)
    {
        return 0;
    }
    else
    {
        long long i;
        for(i = 2; i< sqrt(n); i++)
        {
            if ( (n% i) == 0)
            {
                return i;
            }
        }
        return 0;
    }
}
long long calculate(vector<long long> s, long long base, long long n)
{
    long long i = 0;
    long long val = 0;
    long long l = n;
    for (; i < l; i++)
    {
        val =  val + s[i] * pow(base, (l - 1 - i));
    }
    return val;

}


int main()
{
 long long t;
 cin>>t;
 long long value = t;
 while(value--)
 {
     long long n,j;
     cin>>n;
     cin>>j;
     vector<long long> s(n);
     vector<long long> divisors;


     cout<<"Case #"<<t - value<<":"<<endl;
     long long i;
     long long counter = 0;

      for (i = pow(2, n- 1) + 1; (i<= pow(2, n +1) - 1) && (counter != j); i++)
     {

            divisors.clear();
            //cout<<"Loop"<<endl;
         long long str = i;
         long long w = 0;
            while(str != 0)
            {
                s [w] = str%2;
                str = str/2;
                w++;
            }
            //cout<<s[n -1]<<endl;
            if ( s[0] == 1 && s[n-1] == 1)
            {
                long long k = 2;
                for ( k = 2; k<=10; k ++)
                {
                    long long val = calculate(s, k, n);
                    if (isPrime(val))
                    {
                        divisors.push_back(isPrime(val));
                    }
                }
                if ( divisors.size() == 9)
                {
                    counter++;
                    for( long long d = 0; d < n; d++)
                    {
                        cout<<s[d];
                    }
                    for ( long long d = 0; d< 9; d++)
                    {
                        cout<<" "<<divisors[d];
                    }
                    cout<<endl;
                }
            }
     }

     }
 }


