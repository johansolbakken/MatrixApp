//
//  MatrixPrinter.hpp
//  matrixutil
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef MatrixPrinter_hpp
#define MatrixPrinter_hpp

#include "Matrix.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

namespace MatrixUtil {
    
    class MatrixPrinter
    {
    public:
        template<class T>
        static void PrintMatrix(const Matrix<T>& matrix)
        {
            for (size_t i = 0; i < matrix.GetHeight(); i++)
            {
                for (size_t j = 0; j < matrix.GetWidth(); j++)
                {
                    std::cout << matrix[i][j];
                    if (j < matrix.GetWidth() - 1) std::cout << "\t";
                }
                std::cout << std::endl;
            }
        }
    };
    
    template<class T>
    static std::string AsString(const Matrix<T>& matrix)
    {
        std::stringstream s;
        for (size_t i = 0; i < matrix.GetHeight(); i++)
        {
            for (size_t j = 0; j < matrix.GetWidth(); j++)
            {
                s << matrix.GetData(i, j);
                if (j < matrix.GetWidth() - 1)
                    s << "\t";
            }
            if (i < matrix.GetHeight() - 1) s << "\n";
        }
        return s.str();
    }
    
    template<class T>
    static std::string AsString(const std::shared_ptr<Matrix<T>>& matrix)
    {
        std::stringstream s;
        for (size_t i = 0; i < matrix->GetHeight(); i++)
        {
            for (size_t j = 0; j < matrix->GetWidth(); j++)
            {
                s << matrix->GetData(i, j);
                if (j < matrix->GetWidth() - 1)
                    s << "\t";
            }
            if (i < matrix->GetHeight() - 1) s << "\n";
        }
        return s.str();
    }
}

#endif
