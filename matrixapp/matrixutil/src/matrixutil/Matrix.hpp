//
//  Matrix.hpp
//  matrixutil
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>

namespace MatrixUtil
{
    template<class T>
    class Matrix
    {
    public:
        Matrix(size_t width, size_t height) : m_Width(width), m_Height(height)
        {
            m_Matrix = new T*[height];
            
            for (size_t i = 0; i < height; i++)
            {
                m_Matrix[i] = new T[width];
                
                for (size_t j = 0; j < width; j++)
                {
                    m_Matrix[i][j] = 0;
                }
            }
        }
        
        ~Matrix() {
            for (size_t i = 0; i < m_Height; i++)
            {
                delete[] m_Matrix[i];
            }
            delete[] m_Matrix;
        }
        
        T* operator[](size_t i) {
            return m_Matrix[i];
        }
        
        inline size_t GetWidth() const { return m_Width; }
        inline size_t GetHeight() const { return m_Height; }
        inline T GetData(size_t i, size_t j) const { return m_Matrix[i][j]; }
        
    private:
        const size_t m_Width, m_Height;
        T** m_Matrix;
    };
}



#endif /* Matrix_hpp */
