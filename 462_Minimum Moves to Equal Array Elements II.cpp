//Given a non-empty integer array, 
//find the minimum number of moves required to make all array elements equal, 
//where a move is incrementing a selected element by 1 
//or decrementing a selected element by 1.
//You may assume the array's length is at most 10,000.
// 
//Example:
//Input:
//[1,2,3]
//Output:
//2
// 
//Explanation:
//Only two moves are needed (remember each move increments or decrements one element):
//[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int length = nums.size();
        int mid = nums[length/2];
        int result = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
        {
            result = result + abs(*iter - mid);
        }
        return result;
    }
};

//Best solution:
class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        int sz = nums.size();
        nth_element(begin(nums), next(begin(nums), sz / 2), end(nums));
        int val = *next(begin(nums), sz / 2), result = 0;
        for (const auto & i : nums) {
            result += abs(i - val);
        }
        return result;
    }
};