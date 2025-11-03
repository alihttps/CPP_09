#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
    public:
        static double get_time_us();
        static std::vector<int> generateJacobsthal(int n);
        static void binaryInsert(std::vector<int>& vec, int value);
        static void mergeInsertionSort(std::vector<int>& nums);
        static void binaryInsert(std::deque<int>& vec, int value);
        static void mergeInsertionSort(std::deque<int>& nums);
        static void print(int ac, char** av);
        static void print_cont1(const std::vector<int>& vec);
        static void print_cont2(const std::deque<int>& deq);
        ~PmergeMe();
};

#endif