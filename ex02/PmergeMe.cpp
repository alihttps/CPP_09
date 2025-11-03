#include "PmergeMe.hpp"

double PmergeMe::get_time_us()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1e6) + tv.tv_usec;
}

std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    if (n == 0)
        return jacob;
    jacob.push_back(1);

    for (int i = 2; i <= n; ++i)
        jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);

    return jacob;
}

void PmergeMe::binaryInsert(std::vector<int>& vec, int value)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    vec.insert(vec.begin() + left, value);
}

void PmergeMe::mergeInsertionSort(std::vector<int>& nums)
{
    size_t n = nums.size();
    if (n <= 1)
        return;

    std::vector<int> pend;
    std::vector<int> mainChain;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = nums[i];
        int b = nums[i + 1];
        if (a < b)
        {
            pend.push_back(a);
            mainChain.push_back(b);
        }
        else
        {
            pend.push_back(b);
            mainChain.push_back(a);
        }
    }

    if (n % 2 != 0)
        pend.push_back(nums[n - 1]);

    mergeInsertionSort(mainChain);

    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    for (size_t j = 1; j < jacob.size() && jacob[j] < (int)pend.size(); ++j)
    {
        int index = jacob[j];
        if (!inserted[index])
        {
            binaryInsert(mainChain, pend[index]);
            inserted[index] = true;
        }
    }

    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!inserted[i])
            binaryInsert(mainChain, pend[i]);
    }

    nums = mainChain;
}

void PmergeMe::binaryInsert(std::deque<int>& vec, int value)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    vec.insert(vec.begin() + left, value);
}

void PmergeMe::mergeInsertionSort(std::deque<int>& nums)
{
    size_t n = nums.size();
    if (n <= 1)
        return;

    std::deque<int> pend;
    std::deque<int> mainChain;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = nums[i];
        int b = nums[i + 1];
        if (a < b)
        {
            pend.push_back(a);
            mainChain.push_back(b);
        }
        else
        {
            pend.push_back(b);
            mainChain.push_back(a);
        }
    }

    if (n % 2 != 0)
        pend.push_back(nums[n - 1]);

    mergeInsertionSort(mainChain);

    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    for (size_t j = 1; j < jacob.size() && jacob[j] < (int)pend.size(); ++j)
    {
        int index = jacob[j];
        if (!inserted[index])
        {
            binaryInsert(mainChain, pend[index]);
            inserted[index] = true;
        }
    }

    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!inserted[i])
            binaryInsert(mainChain, pend[i]);
    }

    nums = mainChain;
}

void PmergeMe::print(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_cont1(const std::vector<int>& cont)
{
    for (size_t i = 0; i < cont.size(); ++i)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::print_cont2(const std::deque<int>& cont)
{
    for (size_t i = 0; i < cont.size(); ++i)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
}