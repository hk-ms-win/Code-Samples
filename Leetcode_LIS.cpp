class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> valVector(nums.size(),1);
    int i, j;
    for( i = 0; i< nums.size(); i++)
    for ( j = 0; j <= i; j++)
    {
    	if ( nums[j] < nums[i])
    	{
    	      if( valVector[i] < (valVector[j] + 1))
    	      {
    	           valVector[i] = valVector[j] + 1;
    	      }
    	}
    }
    if (!nums.empty())
    {
    std::vector<int>::iterator result = std::max_element(valVector.begin(), valVector.end());
    return *result;
    }
    else
    {
     return 0;
    }
    }
};