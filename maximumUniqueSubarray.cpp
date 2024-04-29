class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> map; //declare and initialize an unordered hash map storing frequencies of keys as values
        int sum = 0; //holds sum
        int maxVal = 0; //hold max sum value
        int start = 0; //start value
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++; //increments frequency of key corresponding to value in nums vector
            sum += nums[i]; //adds value to sum
            while (map[nums[i]] >1) { //while frequency of that key is >1
                map[nums[start]]--; //decrement the frequency of that key
                sum -=nums[start]; //subtract the redundant value from the sum
                start++; //increment start value of subarray
            }
            maxVal = max(maxVal, sum);


        }
        return maxVal;
    }
};
