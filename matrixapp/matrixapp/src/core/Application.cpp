#include "Application.hpp"

namespace MatrixApp
{
    Application* Application::s_Instance {nullptr};
    
    Application& Application::GetInstance()
    {
        if (s_Instance == nullptr)
        {
            s_Instance = new Application();
        }
        
        return *s_Instance;
    }
    
    Application::Application()
    {
        m_Calculator = std::make_shared<Gauss::Calculator>();
    }
    
    Application::~Application()
    {
        
    }
    
    void Application::Run()
    {
        std::cout << MatrixUtil::AsString(m_Calculator->GetA()) << std::endl;
    }
    
    void Application::Update()
    {
        
    }
}
