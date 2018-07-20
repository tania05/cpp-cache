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
void DFT(T* x, std::size_t row_size, std::size_t col_size)
{
    if(col_size ==1)
    {
        return;
        
    } else if (row_size * col_size <= 2) {
          base_dft(x);
          return;
    }
    
    std::cout << "ROW AND ROCLUMN SIZE" << std::endl;
    std::cout << row_size << std::endl;
    std::cout << col_size << std::endl;
    
    std::cout << "***********" << std::endl << std::endl;
    
    naive_matrix_transpose<T>(x,row_size,col_size,x);
   

    //each row will have size row_size after matrix transposition
    std::size_t r = get_n1(row_size);
    std::size_t c = row_size/r;
    
    //for each row
    for(size_t i = 0; i < col_size; ++i)
    {
        std::cout<< "For each i ...... " << i << std::endl;
        
        std::cout << "After transposition " << std::endl << std::endl;
    
        print_matrix<T>(col_size,row_size,x);
        std::cout << "Matrix dim .... " << r << " " << c << std::endl;
        std::cout << "value initial int x .. " << x[row_size*i] << std::endl << std::endl;
        DFT(x+(row_size*i),r,c);
    }
    
    
        std::cout << "Before Twiddle " << std::endl << std::endl;
    
        print_matrix<T>(col_size,row_size,x);
    
    //matrix has been transposed before, make sure row and columns are reversed.
    multiply_twiddle(x, col_size,row_size, col_size*row_size);
    
    std::cout << "After twiddle " << std::endl << std::endl;
    
    print_matrix<T>(col_size,row_size,x);
        
    naive_matrix_transpose<T>(x,col_size,row_size,x);
    
    std::cout << "After Second transpose " << std::endl << std::endl;
    
    print_matrix<T>(row_size,col_size,x);
    
    
    r = get_n1(col_size);
    c = col_size/r;
    
    for(size_t i = 0; i < row_size; ++i)
    {
        
        std::cout << "value initial int x  IN SECOND LOOP.. " << x[col_size*i] << std::endl << std::endl;
        DFT(x+(col_size*i),r,c);
    }
    
    std::cout << "After Second DFT " << std::endl << std::endl;
    
    print_matrix<T>(row_size,col_size,x);
    
    naive_matrix_transpose<T>(x,row_size,col_size,x);
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
