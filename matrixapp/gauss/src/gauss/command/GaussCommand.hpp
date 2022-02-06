//
//  GaussCommand.hpp
//  gauss
//
//  Created by Johan Solbakken on 05/02/2022.
//

#ifndef GaussCommand_hpp
#define GaussCommand_hpp

namespace Gauss
{
    class GaussCommand
    {
    public:
        virtual ~GaussCommand() {}
        virtual void Execute() = 0;
    };
}

#endif /* GaussCommand_hpp */
