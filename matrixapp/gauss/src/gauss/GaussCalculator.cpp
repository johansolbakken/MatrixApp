#include "GaussCalculator.hpp"

namespace Gauss {
    
    Calculator::Calculator()
    {
        m_A = std::make_shared<MatrixUtil::Matrix<int>>(2, 2);
        m_B = std::make_shared<MatrixUtil::Matrix<int>>(2, 2);
    }
    
    Calculator::~Calculator()
    {
        
    }
    
    void Calculator::ResetA(size_t width, size_t height)
    {
        m_A.reset(new MatrixUtil::Matrix<int>(width, height));
    }
    
    void Calculator::ResetB(size_t width, size_t height)
    {
        m_B.reset(new MatrixUtil::Matrix<int>(width, height));
    }
}
