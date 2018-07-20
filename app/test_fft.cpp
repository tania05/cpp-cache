#include "ra/fft.hpp"
#include <iostream>
#include <cmath>
#include <complex.h>
#include <ctime>
#include <complex>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdint>

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
void test_naive(std::size_t n)
{
    T a[n] = {0};
    T b[n] = {0};
    T c[n] = {0};
    
    std::srand((unsigned)time(NULL));
    // for(std::size_t i =0; i< n; ++i)
    // {
    //     //making sure I don't get huge numbers for elements
    //     a[i] = T(std::rand() %10, std::rand() %3);
    //     std::cout << a[i] << std::endl;
    // }
    
    // a[0] = T(0,1);
    // a[1] = T(9,2);
    // a[2] = T(6,7);
    // a[3] = T(1,4);
    
    for(std::size_t i =0; i< n; ++i)
    {
        //making sure I don't get huge numbers for elements
        a[i] = T(std::rand() %5, std::rand() %5);
        std::cout << a[i] << std::endl;
    }
    // std::srand((unsigned)time(NULL));
    // for(std::size_t i =0; i< n*p; ++i)
    // {
    //     //making sure I don't get huge numbers for elements
    //     b[i] = rand() %10;
    // }
    
    size_t m = ra::cache::get_n1(n);
    size_t p = n/m;
    std::cout << m << std::endl;
    
    std::cout << p << std::endl;
    
    // print_matrix<T>(m,p,a);
    // base_dft<T>(a);
    ra::cache::forward_fft(a,n);
    print_matrix<T>(m,p,a);
}

int main()
{
    // test_naive<std::complex<double>>(32768);
    // test_naive<std::complex<double>>(4096);
    // test_naive<std::complex<double>>(1024);
    // test_naive<std::complex<double>>(512);
    // test_naive<std::complex<double>>(256);
    // test_naive<std::complex<double>>(128);
    // test_naive<std::complex<double>>(64);
    // test_naive<std::complex<double>>(32);
    
    // test_naive<std::complex<float>>(65536);
    
    return 0;
}

