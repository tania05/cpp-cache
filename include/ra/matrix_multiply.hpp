#include <cstdio>
#include <iostream>

namespace ra::cache
 {
     //n rows
     //p columns

template <class T>
void base_multiply(const T*a , const T* b, std::size_t startRowA, std::size_t startColA, std::size_t startColB, std::size_t m, std::size_t n, std::size_t p, T* c, std::size_t om, std::size_t on, std::size_t op)
{
    for(std::size_t i=startRowA; i< m; ++i)
    {
        for(std::size_t j=startColB; j< p; ++j)
        {
            // T sum = T(0);
            for(std::size_t k = startColA; k< n; ++k)
            {
                
                // if(acc == true)
                    c[op*i + j] += a[on*i +k] * b[op*k+j];
                // else
                    // c[op*i + j] = a[on*i +k] * b[op*k+j];
            }
        }
    }
} 


template<class T>
void comult(const T*a , const T* b, std::size_t startRowA, std::size_t startColA, std::size_t startColB, std::size_t m, std::size_t n, std::size_t p, T* c, std::size_t om, std::size_t on, std::size_t op)
{
    
    size_t sizeRowA = m-startRowA;
    size_t sizeColA = n-startColA;
    size_t sizeColB = p-startColB;
    if(sizeRowA * sizeColA * sizeColB <= 64)
    {
        base_multiply(a,b,startRowA,startColA,startColB,m,n,p,c,om,on,op);
        return;
    }
    //case 1 // override the destination
    if((sizeRowA >= sizeColA) && (sizeRowA>=sizeColB))
    {
        size_t mid = (sizeRowA) /2 + sizeRowA%2;
        comult(a,b,startRowA,startColA,startColB,startRowA+mid,n,p,c,om,on,op);
        comult(a,b,startRowA+mid,startColA,startColB,m,n,p,c,om,on,op);
        return;
    }
    //case 3 //override the destination
    else if((sizeColB>=sizeRowA) && (sizeColB>=sizeColA))
    {
        size_t mid = (sizeColB) /2 + sizeColB%2;
        comult(a,b,startRowA,startColA,startColB,m,n,startColB+mid,c,om,on,op);
        comult(a,b,startRowA,startColA,startColB+mid,m,n,p,c,om,on,op);
        return;
    }
    //case 2
    else
    {
        size_t mid = (sizeColA) /2 + sizeColA%2;
        comult(a,b,startRowA,startColA,startColB,m,startColA+mid,p,c,om,on,op);
        comult(a,b,startRowA,startColA+mid,startColB,m,n,p,c,om,on,op);
    }
}

    template <class T>
    void naive_matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c)
    {
        for(std::size_t i=0; i< m; ++i)
        {
            for(std::size_t j=0; j< p; ++j)
            {
                // T sum = T(0);
                for(std::size_t k = 0; k< n; ++k)
                {
                    
                    c[p*i + j] += a[n*i +k] * b[p*k+j];
                }
            }
        }
    }


    template <class T>
    void matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c)
    {
        comult(a,b,0,0,0,m,n,p,c,m,n,p);   
    }
 }
