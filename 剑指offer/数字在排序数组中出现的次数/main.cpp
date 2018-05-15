class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int count =0;
        bool flag = false;

        sort(data.begin(), data.end());
        for(auto i:data)
        {
            if(k==i)
            {
                count++;
                if(!flag)
                    flag = true;
                continue;
            }
            if(flag)
                return count;
        }
        
        return count;
    }
};