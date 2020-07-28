#include "qppch.h"
#include "Application.h"

namespace Quipo {

  Application* Application::s_Instance = nullptr;

  Application::Application(const std::string& name)
  {
    s_Instance = this;
  }

  Application::~Application()
  {
  }

  void Application::Close()
  {
    m_Running = false;
  }

  void Application::Run()
  {
    while (m_Running)
    {
    }
  }

}
