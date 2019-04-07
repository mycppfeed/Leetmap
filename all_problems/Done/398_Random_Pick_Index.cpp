/* 
 * Problem Description
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
Show Company Tags
Show Tags
Show Similar Problems

 * Solution
select the new element with prob 1/n


 * Tags
 Reservoir Sampling
*/

#include"header.h"
class Solution {
    private:
    vector<int> n;
public:
    Solution(vector<int> nums) {
        n = nums;
        
    }
    
    int pick(int target) {
        int sz = n.size();
        int count = 0;
        int res;
        
        for(int i =0 ; i < sz; i++) {
            if(n[i] != target) continue;
            count++;
            if(1 == count) res = i;
            else 
              if(0 == (rand()%count)) res = i;
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main() {
  Solution S;

  return 0;
}
