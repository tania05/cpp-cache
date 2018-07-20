#include <cstdio>
#include <iostream>

namespace ra::cache
{


std::size_t get_n1(std::size_t n)
{
    //we round up if the next digit is 5 or more, otherwise round down.
    //find the closest number to the square root
    std::size_t n1 = (std::size_t)(std::sqrt(float(n)) + 0.5 );
    std::size_t m1, m2;
    m1 = m2 = n1;
    
    // std::cout << "n1: " << n1 << std::endl;
            
    
    //find upper and lower number close to square root
    while((n%m1 !=0) && (n%m2 !=0))
    {
        if(n%m1 !=0)
        {
            // cout << "incrementing m1 " << n%m1 << " " << m1 << endl;
            ++m1;
        }
            
        if(n%m2 !=0)
        {
        //   cout << "decrementing m2 " << n%m2 << " " << m2 << endl;
             
            --m2;
        }
    }
    
    return (n%m1) == 0  ? m1 : m2;
}

template <class T>
void base_dft(T* x)
{
    // for(std::size_t i = startRow; i< row; ++i)
    // {   
    //     // T sum = T(0);
    //     for(std::size_t j = startCol; j< col; ++j)
    //     {   
    //         T sum = T(0);
    //         for(std::size_t k = startCol; k<col; ++k )
    //         {
    //             std::size_t matrix_i = (n2*i +k);
    //             T wn_ij = wFactors<T>((col-startCol), matrix_i, j);
    //             sum+=x[matrix_i] * wn_ij;
    //         }
            
    //             c[n2*i +j]+=sum ;
    //     }
        
    // }
    
    T temp = *x;
    *x += *(x+1);
    *(x+1) = temp  - *(x+1);
    
}

  template <class T>
  void forward_fft(T* x, std::size_t n)
  {
    //step 1: find n1 and n2
    std::size_t n1 = get_n1(n);
    std::size_t n2 = n/n1;
    
    //step 2: transpose matrix A 
    
    DFT(x,n1,n2);
    
    //step3 : inner summation
    
    
  }
}
