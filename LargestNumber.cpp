string Solution::largestNumber(const vector<int> &A) {
    
    int  i = 0;
    vector<int> temp(A.begin(), A.end());

    sort(temp.begin(), temp.end(), [](int i, int j)
         {
            string is = std::to_string(i);

                string js = std::to_string(j);
                int sis = is.size();
                int sij = js. size();
                long long value1 = i;
                long long value2 = j;
                while( sij != 0)
                {
                    value1 *= 10;
                    sij--;
                    
                }
                while( sis != 0)
                {
                    value2 *= 10;
                    sis--;
                    
                }

                value1 += j;
                value2 += i;

                return value1> value2;
         });
    string s;
    for ( auto iter  = temp.begin(); iter != temp.end(); iter++)
    {
        if ( *temp.begin() == 0)
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
