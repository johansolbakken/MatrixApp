//
//  GaussCommandInvoker.hpp
//  gauss
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef GaussCommandInvoker_hpp
#define GaussCommandInvoker_hpp

#include "GaussCommand.hpp"
#include "GaussScale.hpp"

namespace Gauss {
    
    class CommandInvoker
    {
    public:
        CommandInvoker(std::shared_ptr<GaussCommand> command);
        ~CommandInvoker();
        
        void ExecuteCommand();
        
        inline void SetCommand(std::shared_ptr<GaussCommand> command) { m_Command = command; }
        
    private:
        std::shared_ptr<GaussCommand> m_Command = nullptr;
    };
    
}

#endif /* GaussCommandInvoker_hpp */
