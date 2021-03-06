#include "ra/matrix_transpose.hpp"
#include <cmath>
#include <ctime>
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
void test_naive(std::size_t m, std::size_t n)
{
    std::size_t s = m*n;
    T a[s];
    T b[s];
    //to compare against
    T c[s];
    T d[s];
    //feed random number gen

    //to check for double transpose
    T og[s];
    std::srand((unsigned)time(NULL));
    for(std::size_t i =0; i< s; ++i)
    {
        //making sure I don't get huge numbers for elements
        a[i] = rand() %100;
        og[i] = a[i];
        d[i] = rand() %100;

    }
    // std::cout << "Rrere" << std::endl;
    // print_matrix(m,n,d);
    // std::cout << "Done" << std::endl;
    
    ra::cache::matrix_transpose<T>(a,m,n,b);
    ra::cache::naive_matrix_transpose<T>(a,m,n,c);
    ra::cache::naive_matrix_transpose<T>(d,m,n,d);
    
    for( std::size_t i=0; i<m*n; ++i)
    {
        assert(b[i]==c[i]);
    }

    std::cout << "a" << std::endl;
    // print_matrix(m,n,a);    
    std::cout << "b" << std::endl;
    // print_matrix(n,m,b);
    std::cout << "og" << std::endl;
    // print_matrix(n,m,og);
    // print_matrix(n,m,c);
    // print_matrix(n,m,d); 

    ra::cache::naive_matrix_transpose<T>(a,m,n,a); // itself
    std::cout << "a" << std::endl;
    // print_matrix(m,n,a);    

    ra::cache::naive_matrix_transpose<T>(a,m,n,a); // itself

    std::cout << "a" << std::endl;
    // print_matrix(m,n,a);
    for( std::size_t i=0; i<m*n; ++i)
    {
        assert(b[i]==c[i]);
        assert(og[i]==a[i]);
    };    
    
}

int main()
{
    // test_naive<int>(512,512);
    test_naive<int>(3,3);
    return 0;
    
}
