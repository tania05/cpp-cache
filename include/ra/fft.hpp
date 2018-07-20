#include "matrix_transpose.hpp"
#include <type_traits>
#include <iostream>
#include <cmath>
#include <complex.h>
#include <ctime>
#include <complex>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdint>


namespace ra::cache
{
  std::size_t get_n1(std::size_t n)
  {
      //we round up if the next digit is 5 or more, otherwise round down.
      //find the closest number to the square root
      std::size_t n1 = (std::size_t)(std::sqrt(float(n)) + 0.5 );
      std::size_t m1, m2;
      m1 = m2 = n1;
      
      //find upper and lower number close to square root
      while((n%m1 !=0) && (n%m2 !=0))
      {
          if(n%m1 !=0)
          {
              ++m1;
          }       
          if(n%m2 !=0)
          {
              --m2;
          }
      }
      return (n%m1) == 0  ? m1 : m2;
  }


  template <class T>
  void  multiply_twiddle(T*x, std::size_t row, std::size_t col, std::size_t n)
  {   
      // conditional type casting, such that we can use double and float when we need, accordingly
      // using ctype = typename std::conditional<std::is_same<T, std::complex<double>>::value, double, float>::type;
      const T wn = T(std::cos(2* M_PI/n), std::sin(2*M_PI/n));
      
      //Access the elements in terms of row and column from the given matrix. Also get twiddle accoridng the value of i, j and n;
      for(size_t i = 0; i < row; ++i)
      {
          for(size_t j = 0; j< col; ++j )
          {
            *(x+ col*i +j) *= std::pow(wn, T( -T(i) * T(j) ) ); 
          }
      }
  }

  template <class T>
  void base_dft(T* x)
  {
    // given a sequence of matrix of size 2, do the two-point DFT, manual.
      T temp = *x;
      *x += *(x+1);
      *(x+1) = temp  - *(x+1);
      
  }

  template <class T>
  void DFT(T* x, std::size_t row_size, std::size_t col_size)
  {
    //base case
      if(col_size ==1)
      {
          return;
          
      } else if (row_size * col_size <= 2) {
            base_dft(x);
            return;
      }
      
      ra::cache::naive_matrix_transpose<T>(x,row_size,col_size,x);
    

      //each row will have size row_size after matrix transposition above
      std::size_t r = get_n1(row_size);
      std::size_t c = row_size/r;
      
      //for each row, recurse
      for(size_t i = 0; i < col_size; ++i)
      {
          DFT(x+(row_size*i),r,c);
      }
      
      //matrix has been transposed before, make sure row and columns are reversed.
      multiply_twiddle(x, col_size,row_size, col_size*row_size);
          
      ra::cache::naive_matrix_transpose<T>(x,col_size,row_size,x);
      
      //After the preceeding transpose, the the matrix will have row and colum sizes to back to what it was before.
      //New sizes of row and columns on each of the recurrence sequence that follows 
      //will have their values dependednt on the column size
      //col_size is the new n for the splitting sequence for recurrence
      r = get_n1(col_size);
      c = col_size/r;
      
      //recurrence
      for(size_t i = 0; i < row_size; ++i)
      {
          DFT(x+(col_size*i),r,c);
      }
      
      //final step
      ra::cache::naive_matrix_transpose<T>(x,row_size,col_size,x);
  }

  template <class T>
  void forward_fft(T* x, std::size_t n)
  {
    //step 1: find n1 and n2
    std::size_t n1 = get_n1(n);
    std::size_t n2 = n/n1;

    //send for recursion
    DFT(x,n1,n2);
  }
}
