#include "ra/matrix_multiply.hpp"
#include <cmath>
#include <ctime>
#include <complex>
#include <iostream>
#include <cassert>
#include <iomanip>

template<class T>
void print_matrix(std::size_t m, std::size_t n, const T* a)
{
    for( std::size_t i=0; i<m; ++i)
    {
        for (std::size_t j = 0; j<n; ++j)
        {
            std::cout << std::setw(3) << *(a+n*i+j) << ',' << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}

template<class T>
void test_naive(std::size_t m, std::size_t n, std::size_t p)
{
    T c[m*p] = {0};
    
    T d[m*p] = {0};
    T a[m*n] = {0};
    T b[n*p] = {0};
        T start1 = 1;
        T start2 = 1;

    std::srand((unsigned)time(NULL));
    for(std::size_t i =0; i< m*n; ++i)
    {
        //making sure I don't get huge numbers for elements
        a[i] = start1++;
        
    }
    
    std::srand((unsigned)time(NULL));
    for(std::size_t i =0; i< n*p; ++i)
    {
        //making sure I don't get huge numbers for elements
        b[i] = start2++;
    }
    
    ra::cache::naive_matrix_multiply<T>(a,b,m,n,p,c);
    ra::cache::matrix_multiply<T>(a,b,m,n,p,d);
        
    // cotrans(a,b,0,0,2,2,2,2);
    for(std::size_t i = 0; i < m*p; ++i)
    {
        assert(d[i] == c[i]);
    }

    print_matrix(m,n,a);
    
    print_matrix(n,p,b);

    print_matrix(m,p,d);
    
    print_matrix(m,p,c);
}

int main()
{
    // test_naive<int>(512,512,512);
    test_naive<double>(12,15,6);
    // test_naive<std::complex<double>>(3,2,3);
    
    return 0;
    
}
