//
//  IdentityMatrix.hpp
//  matrixutil
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef IdentityMatrix_hpp
#define IdentityMatrix_hpp

#include "Matrix.hpp"

namespace MatrixUtil
{
    template<class T>
    Matrix<T> Identity(size_t n)
    {
        Matrix<T> matrix{ n, n };
        
        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 1;
        }
        
        return matrix;
    }
}


#endif /* IdentityMatrix_hpp */
