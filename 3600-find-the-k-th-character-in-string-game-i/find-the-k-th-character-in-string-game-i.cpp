class Solution {
public:
    char generator(int k,string s)
    {
        if(s.size()>=k)
            return s[k-1];

        int n=s.size();
        for(int i=0;i<n;i++)
        {
            s=s+char(s[i]+1);
        }

        return generator(k,s);
    }
   char kthCharacter(int k) 
    {
        string s="a";
        return generator(k,s);    
    }
};