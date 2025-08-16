#include "PmergeMe.hpp"

void mergeVector(std::vector<int>& leftvect, std::vector<int>& rightvect, std::vector<int>& origvect)
{
    int leftsize = origvect.size() / 2;
    int rightsize = origvect.size() - leftsize;
    int i = 0; //
    int l = 0; // indicies for each array
    int r = 0; //

    //check conditions for merging
    while (l < leftsize && r < rightsize)
    {
        if (leftvect[l] < rightvect[r])
        {
            origvect[i] = leftvect[l];
            i++;
            l++;
        }
        else
        {
            origvect[i] = rightvect[r];
            i++;
            r++;
        }
    }
    while (l < leftsize)
    {
        origvect[i] = leftvect[l];
        i++;
        l++;
    }
    while (r < rightsize)
    {
        origvect[i] = rightvect[r];
        i++;
        r++;
    }
}

void mergeSortVector(std::vector<int>& nums)
{
    size_t len = nums.size();
    if (len <= 1)
        return;
    int middle = len/2;
    //create sub arrays that part the original at half
    std::vector<int> leftarray;
    leftarray.reserve(middle);
    std::vector<int> rightarray;
    leftarray.reserve(len - middle);

    //copy the content of original array into the left and right array
    for (int i = 0; i < len; i++)
    {
        if (i < middle)
            leftarray.push_back(nums[i]);
        else
        {
            rightarray.push_back(nums[i]);
        }
    }
    //divide
    mergeSortVector(leftarray);
    mergeSortVector(rightarray);
    mergeVector(leftarray, rightarray, nums);
    
}

int main(int ac, char** av)
{
    // PmergeMe merg(av + 1);
    std::vector<int> nums;
    nums.reserve(ac - 1);
    for (size_t i = 1; i < ac; i++)
    {
        nums.push_back(atoi(av[i]));
    }
    
    mergeSortVector(nums);
    for (size_t i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
}
