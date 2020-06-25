class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[nums[0]];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }

        hare = 0;
        while (hare != tortoise)
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return tortoise; 
    }
};
