//
//  GaussCommandInvoker.cpp
//  gauss
//
//  Created by Johan Solbakken on 05/02/2022.
//

#include "GaussCommandInvoker.hpp"

namespace Gauss
{
    CommandInvoker::CommandInvoker(std::shared_ptr<GaussCommand> command)
    {
        
    }
    
    CommandInvoker::~CommandInvoker()
    {
        
    }
    
    void CommandInvoker::ExecuteCommand()
    {
        m_Command->Execute();
    }
}
