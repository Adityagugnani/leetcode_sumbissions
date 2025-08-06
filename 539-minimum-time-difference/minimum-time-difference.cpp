class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector <int> minutes;

        for(int i =0; i<timePoints.size();i++){
            string current = timePoints[i];
            int hours = stoi(current.substr(0,2));
            int mins = stoi(current.substr(3,2));
            int totalMinutes = hours*60 +mins;
            minutes.push_back(totalMinutes);
        }
        
        sort(minutes.begin(),minutes.end());

        int minimum = INT_MAX;
        int n = minutes.size();

        for(int i=0;i<n-1;i++){
            int diff = minutes[i+1]-minutes[i];
            minimum = min(minimum,diff);
        }
       int lastDiff = (minutes[0]+1440 - minutes[n-1]);
       minimum = min(minimum,lastDiff);

       return minimum;
    }
};