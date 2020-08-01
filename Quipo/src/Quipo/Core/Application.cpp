#include "qppch.h"
#include "Application.h"

#include "Quipo/Core/Core.h"

#include "Quipo/Core/Timestep.h"
#include <GLFW/glfw3.h>

#include "Quipo/Renderer/RenderCommand.h"
#include "Quipo/Renderer/Renderer.h"

namespace Quipo {

  Application* Application::s_Instance = nullptr;

  Application::Application(const std::string& name)
  {
    s_Instance = this;

    m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(name)));
    m_Window->SetEventCallback(QP_BIND_EVENT_FN(Application::OnEvent));
    m_Window->SetVSync(true);

    Renderer::Init();

    ////////////////////////////////////////////////
    /////// OpenGL code: To be removed later ///////

    ////////////////////////////////////////////////
  }

  Application::~Application()
  {
  }

  void Application::Close()
  {
    m_Running = false;
  }

  void Application::PushLayer(Layer* layer)
  {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
  }

  void Application::PushOverlay(Layer* overlay)
  {
    m_LayerStack.PushOverlay(overlay);
    overlay->OnDetach();
  }

  void Application::OnEvent(Event& e)
  {
    EventDispatcher dispatcher(e);

    dispatcher.Dispatch<WindowCloseEvent>(QP_BIND_EVENT_FN(Application::OnWindowClose));
    dispatcher.Dispatch<WindowResizeEvent>(QP_BIND_EVENT_FN(Application::OnWindowResize));

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
    {
      if (e.Handled)
        break;
      (*it)->OnEvent(e);
    }
  }

  void Application::Run()
  {
    while (m_Running)
    {
      float time = (float)glfwGetTime(); // Platform::GetTime()
      Timestep timestep = time - m_LastFrameTime;
      m_LastFrameTime = time;

      ////////////////////////////////////////////////

      ////////////////////////////////////////////////
      if (!m_Minimized)
      {
        for (Layer* layer : m_LayerStack)
          layer->OnUpdate(timestep);
      }

      m_Window->OnUpdate();
    }
  }

  bool Application::OnWindowClose(WindowCloseEvent& e)
  {
    m_Running = false;
    return true;
  }

  bool Application::OnWindowResize(WindowResizeEvent& e)
  {
    if (e.GetWidth() == 0 || e.GetHeight() == 0 )
    {
      m_Minimized = true;
      return false;
    }

    m_Minimized = false;
    Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
    
    return false;
  }

}
