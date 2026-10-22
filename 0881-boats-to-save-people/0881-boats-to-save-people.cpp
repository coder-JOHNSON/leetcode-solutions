class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(begin(people),end(people));
        int i = 0, j = n - 1;
        int boat = 0;
        
        while(i <= j){
            if(people[i] + people[j] <= limit){
                j--;
                i++;
                boat += 1;
            }
            else{
                j--;
                boat += 1;
            }
        }
        return boat;
    }
};