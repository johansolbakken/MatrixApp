//
//  GaussScale.hpp
//  gauss
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef GaussScale_hpp
#define GaussScale_hpp

#include <memory>
#include "../GaussCalculator.hpp"
#include "GaussCommand.hpp"

namespace Gauss {
    
    class ScaleCommand : public GaussCommand
    {
    public:
        ScaleCommand(std::shared_ptr<Calculator> calculator);
        virtual ~ScaleCommand();
        virtual void Execute() override;
        
        inline void SetRow(int row) { m_Row = row; }
        
    private:
        int m_Row = 0;
        std::shared_ptr<Calculator> m_Calculator;
    };
    
}

#endif /* GaussScale_hpp */
