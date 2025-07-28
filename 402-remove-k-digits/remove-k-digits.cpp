class Solution {
public:
    string removeKdigits(string num, int k) {
        string t = "";

        for(char&ch:num) {
            while(t.size() && ch < t.back() && k) {
                t.pop_back();
                k--;
            }

            if(t == "") {
                if(ch != '0') t += ch;
            } else {
                t += ch;
            }
        }

        while(t.size() && k) {
            t.pop_back();
            k--;
        }

        return t==""? "0":t;
    }
};