#include <iostream>
#include <array>
#include <vector>
#include <string>

#define OutVec(nums) \
        for(auto& num : nums)   \
            std::cout << num << ",";    \
        std::cout << std::endl;

//binaryfind
int32_t BinaryFind(const std::vector<uint32_t>& nums, uint32_t num)
{
    if(nums.empty())
        return 0;
    uint32_t low = 0;
    uint32_t high = nums.size() - 1;
    while (low < high)
    {
        uint32_t mid = low + ((high - low) >> 1);
        num < nums[mid]  ? high = mid : low = mid + 1; 
    }
    
    return --low;
}


//冒泡排序
void BubbleSort(std::vector<uint32_t>& nums)
{
    if(nums.empty())
        return;
    for(uint32_t i = 0; i < nums.size() - 1; ++i)
    {
        bool hasswap = false;
        for(uint32_t j = 0; j < nums.size() - 1; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                std::swap(nums[j], nums[j+1]);
                hasswap = true;
            }
        }

        OutVec(nums)
        //两两之间都是有序,那就是有序
        if(!hasswap)
            break;
    }
}

//选择排序
void SelectSort(std::vector<uint32_t>& nums)
{
    if(nums.empty())
        return;
    for(uint32_t i = 0; i < nums.size() - 1; ++i)
    {
        uint32_t pos = i;
        for(uint32_t j = i + 1; j < nums.size(); ++j)
        {
            if(nums[j] < nums[pos])
            {
                pos = j;
            }
        }

        if(pos != i)
            std::swap(nums[pos], nums[i]);
        OutVec(nums)
    }
}

//插入排序
void InsertSort(std::vector<uint32_t>& nums)
{
    if(nums.empty())
        return;
    for(uint32_t i = 1; i < nums.size(); ++i)
    {
        uint32_t currentNum = nums[i];
        for(uint32_t j = i; j > 0 && nums[j-1] > currentNum; --j)
        {
            std::swap(nums[j], nums[j-1]);
        }
        OutVec(nums)
    }
}



//快速排序
void QuickSortImpl(std::vector<uint32_t>& nums, uint32_t start, uint32_t end)
{
    uint32_t i = start;
    uint32_t j = end;
    if (start < end)
    {
        uint32_t base = nums[i];    //设置基准数为i,即为startwhile (i < j)
        while(i < j) 
        {
            for(;  i < j && nums[j] >= base; --j)     //找到比基准数小的数字
            {}
            nums[i] = nums[j];
            for(; i < j && nums[i] <= base; ++i)     //找到比基准数小的数字
            {}
            nums[j] = nums[i];
            nums[i]=base;                            //即将这个数设置为base
            OutVec(nums)
        }
        QuickSortImpl(nums, start, i - 1);
        QuickSortImpl(nums, j + 1, end);
    }
}

void QuickSort(std::vector<uint32_t>& nums)
{
    if(nums.empty())
        return;
    QuickSortImpl(nums, 0, nums.size() - 1);
}

int main()
{
    std::vector<uint32_t> nums = {44, 3, 43, 8, 6, 7, 5, 9, 10, 20};
    QuickSort(nums);

    int32_t index = BinaryFind(nums, 20);
    if(nums[index] == 20)
    {
        std::cout << "found 20 index:" << index << std::endl;
    }
    else
    {
        std::cout << "not found 20 index:" << index << std::endl;
    }

    return 0;
}