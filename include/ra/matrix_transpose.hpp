#include <iostream>
#include <cstdio>

namespace ra::cache{
  // result to be written to b
  //elements sorted in row-major order
  //
  template<class T>
  void base_transpose(const T* matrix, T * matrixb,std::size_t startX, std::size_t startY, std::size_t x, std::size_t y, std::size_t ox, std::size_t oy)
    {
        for(std::size_t i = startX; i< x; ++i)
        {
            for(std::size_t j = startY; j< y; ++j)
            {
                matrixb[ox*j + i] = matrix[oy*i + j];
            }
        }
  }

  template<class T>
  void cotrans(const T* matrix, T * matrixb,std::size_t startX, std::size_t startY, std::size_t x, std::size_t y, std::size_t ox, std::size_t oy) {
      if ((x-startX)*(y-startY) <= 64) {
          base_transpose(matrix,matrixb,startX,startY,x,y,ox,oy);
          return;
      }
    
    //Row is the biggest
      if ((x-startX) >= (y-startY)) {
          std::size_t xmid = (x-startX) / 2 + (x-startX)%2 ;
          //split first half
          cotrans(matrix,matrixb,startX, startY, startX+xmid, y, ox, oy);
          //split second half
          cotrans(matrix,matrixb,startX+xmid, startY, x, y, ox, oy );
          return;
      }
      //column is the biggest
      else
      {
          std::size_t ymid = (y - startY)/ 2 + (y-startY)%2;
          //split the first half
          cotrans(matrix,matrixb,startX, startY, x, startY+ymid,ox, oy);
          //split the second half
          cotrans(matrix,matrixb,startX, startY+ymid, x, y,ox, oy );    
      }   
  }

  template<class T>
  void matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b)
  {
    if(a !=b){
      cotrans<T>(a,b,0,0,m,n,m,n); 
    }
    else{
      T aux[m*n] = {0};
      //transpose into aux
      cotrans<T>(a,aux,0,0,m,n,m,n);
      //copy into b
      std::copy(aux, aux + m*n, b);

    }
  }

  template<class T>
  void naive_matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b)
  {
    if(a!=b)
    {
      base_transpose<T>(a,b,0,0,m,n,m,n);
    }
    else{
        T aux[m*n] = {0};
        //transpose into aux
        base_transpose<T>(a,aux,0,0,m,n,m,n);
        //copy into b
        std::copy(aux, aux + m*n, b);

      }
    
  }

}
