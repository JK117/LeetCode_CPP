//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
    }
};

//Top Solution
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> vtoi = {};
        for (int i=0; i<nums.size(); i++)
        {
            if (vtoi.find(target-nums[i])!=vtoi.end())
            {
                return vector <int> ({vtoi[target-nums[i]],i});
            }
            vtoi[nums[i]]=i;
        }
    }
};