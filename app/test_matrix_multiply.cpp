#include "ra/matrix_multiply.hpp"
// #include <cmath>
// #include <ctime>
// #include <iostream>
// #include <cassert>
// #include <iomanip>

// template<class T>
// void print_matrix(std::size_t m, std::size_t n, const T* a)
// {
//     for( std::size_t i=0; i<n; ++i)
//     {
//         for (std::size_t j = 0; j<m; ++j)
//         {
//             std::cout << std::setw(3) << *(a+n*i+j) << ',' << ' ';
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
    
// }

// template<class T>
// void test_naive(std::size_t m, std::size_t n)
// {
//     std::size_t s = m*n;
//     T a[s];
//     T b[s];
//     //to compare against
//     T c[s];
//     //feed random number gen
//     std::srand((unsigned)time(NULL));
//     for(std::size_t i =0; i< s; ++i)
//     {
//         //making sure I don't get huge numbers for elements
//         *a++ = rand() %100;
//     }
//     ra::cache::matrix_transpose<T>(a,m,n,b);
//     ra::cache::naive_matrix_transpose<T>(a,m,n,c);
    
//     for( std::size_t i=0; i<n; ++i)
//     {
//         for (std::size_t j = 0; j<m; ++j)
//         {
//             assert(b[n*i +j] = c[n*i +j]);
//         }
//     }
//     print_matrix(m,n,a);    
//     print_matrix(m,n,b);
//     print_matrix(m,n,c);
    
// }

int main()
{
    // test_naive<int>(3,2);
    return 0;
    
}
