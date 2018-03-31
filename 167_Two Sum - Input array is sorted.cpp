//Given an array of integers that is already sorted in ascending order, 
//find two numbers such that they add up to a specific target number.
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2. 
//Please note that your returned answers (both index1 and index2) are not zero-based.
//You may assume that each input would have exactly one solution and you may not use the same element twice.
// 
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        std::unordered_map<int, int> u_map;
        std::vector<int> result;

        for (int i = 0; i < numbers.lenght; i++)
        {
            int temp = target - numbers[i];
            if (u_map.find(temp) != u_map.end())
            {
                result.push_back(numbers[i]);
                result.push_back(temp);
            }
        }

        return result;
    }
};