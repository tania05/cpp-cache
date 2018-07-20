#include <cstdio>
#include <iostream>


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


namespace ra::cache
{
  template <class T>
  void forward_fft(T* x, std::size_t n);
}
