//
//  MatrixOperator.hpp
//  matrixutil
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef MatrixOperator_hpp
#define MatrixOperator_hpp

#include "Matrix.hpp"
#include <stdexcept>

namespace MatrixUtil
{
    template<class T>
    Matrix<T> Add(const Matrix<T>& a, const Matrix<T>& b)
    {
        if (a.GetWidth() != b.GetWidth() || a.GetHeight() != b.GetHeight())
        {
            throw std::runtime_error("Matrices A and B are not compatible!");
        }
        
        Matrix<T> result {a.GetWidth(), a.GetHeight()};
        
        for (size_t i = 0; i < a.GetHeight(); i++)
        {
            for (size_t j = 0; j < a.GetWidth(); j++)
            {
                result[i][j] = a.GetData(i, j) + b.GetData(i, j);
            }
        }
        
        return result;
    }
    
    template<class T>
    Matrix<T> Scale(const Matrix<T>& mat, T c) {
        Matrix<T> result { mat.GetWidth(), mat.GetHeight() };
        
        for (size_t i = 0; i < mat.GetHeight(); i++)
        {
            for (size_t j = 0; j < mat.GetWidth(); j++)
            {
                result[i][j] = mat.GetData(i, j) * c;
            }
        }
        
        return result;
    }
    
    template<class T>
    Matrix<T> Multiply(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.GetWidth() != b.GetHeight()) {
            throw std::runtime_error("Matrices A and B are not compatible");
        }
        
        size_t height = a.GetHeight();
        size_t width = b.GetWidth();
        
        Matrix<T> result { width, height };
        
        for (size_t r = 0; r < height; r++)
        {
            for (size_t c = 0; c < width; c++)
            {
                for (size_t k = 0; k < a.GetWidth(); k++) {
                    result[r][c] += a.GetData(r, k) * b.GetData(k, c);
                }
            }
        }
        
        return result;
    }
}

#endif /* MatrixOperator_hpp */
