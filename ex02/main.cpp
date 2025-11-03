#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cout << "Error : not enough arguments" << std::endl;
        return 1;
    }

    {
        std::cout << "Before: ";
        PmergeMe::print(ac, av);
        std::vector<int> nums;
        for (int i = 1; i < ac; ++i)
        nums.push_back(std::atoi(av[i]));

        double start = PmergeMe::get_time_us();
        PmergeMe::mergeInsertionSort(nums);
        double end = PmergeMe::get_time_us();
        double duration_us = end - start;
        std::cout << "After:  ";
        PmergeMe::print_cont1(nums);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << duration_us << " us" << std::endl;
    }
    {
        std::cout << "Before: ";
        PmergeMe::print(ac, av);
        std::deque<int> nums;
        for (int i = 1; i < ac; ++i)
            nums.push_back(std::atoi(av[i]));
        double start = PmergeMe::get_time_us();
        PmergeMe::mergeInsertionSort(nums);
        double end = PmergeMe::get_time_us();
        double duration_us = end - start;
        std::cout << "After:  ";
        PmergeMe::print_cont2(nums);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << duration_us << " us" << std::endl;
    }
    
    return 0;
}
