#ifndef GaussCalculator_hpp
#define GaussCalculator_hpp

#include <MatrixUtil.hpp>

#include <memory>

namespace Gauss
{
    
    class Calculator
    {
    public:
        Calculator();
        ~Calculator();
        
        inline std::shared_ptr<MatrixUtil::Matrix<int>> GetA() const { return m_A; }
        inline std::shared_ptr<MatrixUtil::Matrix<int>> GetB() const { return m_B; }
        
        void ResetA(size_t width, size_t height);
        void ResetB(size_t width, size_t height);
        
    private:
        std::shared_ptr<MatrixUtil::Matrix<int>> m_A;
        std::shared_ptr<MatrixUtil::Matrix<int>> m_B;
    };
    
}

#endif
