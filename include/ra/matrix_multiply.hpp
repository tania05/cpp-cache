#include <cstdio>
#include <iostream>

namespace ra::cache
 {
     //n rows
     //p columns
    template <class T>
    void naive_matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c)
    {
        for(int i=0; i< m; ++i)
        {
            for(int j=0; j< p; ++j)
            {
                T sum = T(0);
                for(int k = 0; k< n; ++k)
                {
                    // cout << "a: "<<a[n*i +k] <<endl;
                    // cout << "b: " << b[p*k+j] <<endl;
                    
                    sum += a[n*i +k] * b[p*k+j];
                }
                // cout << "Index: "<< p*i +j << endl;
                c[p*i + j] = sum;
            }
        }
    }

    template <class T>
    void matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c);
 }
