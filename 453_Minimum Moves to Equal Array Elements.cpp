//Given a non-empty integer array of size n, 
//find the minimum number of moves required to make all array elements equal, 
//where a move is incrementing n - 1 elements by 1.
// 
//Example:
//Input: [1,2,3]
//Output: 3
// 
//Explanation:
//Only three moves are needed (remember each move increments two elements):
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int minNum = nums[0];
        int n = nums.size();
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            sum = sum + *iter;
        }
        int count = sum - minNum * n;
        return count;
    }
};

//元素数量：n
//原所有元素和：sum
//最小元素：minNum
//最大元素：maxNum
//步数：count
//sum + (n - 1) * count = maxNum * n
//maxNum = minNum + count

//Best solution:
class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        return accumulate(begin(nums), end(nums), 0ll) - nums.size() * *min_element(begin(nums), end(nums));
    }
};