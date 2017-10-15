//Given two arrays, write a function to compute their intersection.
// 
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// 
//Note:
//Each element in the result must be unique.
//The result can be in any order.

//6ms
class Solution1
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        int mark;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        //nums1.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
        {
            if (nums1[i] == nums2[j])
            {
                if (result.size() == 0 || nums1[i] != mark)
                {
                    result.push_back(nums1[i]);
                    mark = nums1[i];
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else //if (nums1[i] > nums2[j])
            {
                j++;
            }
        }
        return result;
    }
};

//12ms
class Solution2
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        set<int>::iterator it1 = s1.begin();
        set<int>::iterator it2 = s2.begin();
        while(it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 == *it2)
            {
                result.push_back(*it1);
                it1++;
                it2++;
            }
            else if (*it1 < *it2)
            {
                it1++;
            }
            else //if (*it1 > *it2)
            {
                it2++;
            }
        }
        return result;
    }
};

//关于set，本题用到以下特性：
//1.set中的元素是唯一的，向同一个set插入同一个元素多次，它只会保存一个。
//2.set中的元素值是有序的，如依次插入5 6 3 2 7，迭代器从头依次打印2 3 5 6 7。

//map标准规定的复杂度基于平衡二叉树，插入删除查找都是最坏logn，所以最后加起来和排序的复杂度一样。
//hash一般是期望线性最坏平方。
//bitmap和数据范围大小有关系，只有数据范围小于logn的时候才有点价值。所谓伪多项式。