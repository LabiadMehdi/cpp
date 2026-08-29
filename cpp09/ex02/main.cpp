#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmerge(argc, argv);

        std::vector<int> before = pmerge.getVector();
        std::cout << "Before: ";
        for (size_t i = 0; i < before.size(); i++)
            std::cout << before[i] << " ";
        std::cout << std::endl;

        struct timeval startVec, endVec;
        gettimeofday(&startVec, NULL);
        pmerge.sortVector();
        gettimeofday(&endVec, NULL);
        double vecTime = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec);

        struct timeval startDeq, endDeq;
        gettimeofday(&startDeq, NULL);
        pmerge.sortDeque();
        gettimeofday(&endDeq, NULL);
        double deqTime = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);

        std::vector<int> after = pmerge.getVector();
        std::cout << "After: ";
        for (size_t i = 0; i < after.size(); i++)
            std::cout << after[i] << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << before.size()
                   << " elements with std::vector : " << vecTime << " us" << std::endl;
        std::cout << "Time to process a range of " << before.size()
                   << " elements with std::deque : " << deqTime << " us" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}