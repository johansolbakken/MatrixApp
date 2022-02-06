#ifndef Application_hpp
#define Application_hpp

#include "Core.hpp"
#include <Gauss.hpp>

#include "input/Menu.hpp"

namespace MatrixApp
{
    class Application
    {
    public:
        Application(Application& other) = delete;
        void operator=(const Application&) = delete;
        static Application& GetInstance();
        ~Application();
        
        void Run();
        void Update();
        
    protected:
        Application();
        
    private:
        static Application* s_Instance;
        Ref<Gauss::Calculator> m_Calculator;
    };
}

#endif
