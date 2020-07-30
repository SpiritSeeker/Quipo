#include "qppch.h"
#include "Application.h"

#include "Quipo/Core/Core.h"

#include <glad/glad.h>

#include "Quipo/Renderer/RenderCommand.h"

namespace Quipo {

  Application* Application::s_Instance = nullptr;

  Application::Application(const std::string& name)
  {
    s_Instance = this;

    m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(name)));
    m_Window->SetEventCallback(QP_BIND_EVENT_FN(Application::OnEvent));
    m_Window->SetVSync(true);

    ////////////////////////////////////////////////
    /////// OpenGL code: To be removed later ///////
    m_VertexArray = VertexArray::Create();

    float vertices[12] = {
      -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.5f,  0.5f, 0.0f,
      -0.5f,  0.5f, 0.0f
    };

    m_VertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));
    BufferLayout layout = {
      { ShaderDataType::Float3, "a_Position" }
    };
    m_VertexBuffer->SetLayout(layout);
    m_VertexArray->AddVertexBuffer(m_VertexBuffer);

    uint32_t indices[6] = {
      0, 1, 2,
      2, 3, 0
    };

    m_IndexBuffer = IndexBuffer::Create(indices, 6);
    m_VertexArray->SetIndexBuffer(m_IndexBuffer);

    m_Shader = Shader::Create("Sandbox/assets/shaders/FlatColor.glsl");
    m_Shader->Bind();
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
      ////////////////////////////////////////////////
      RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
      RenderCommand::Clear();

      m_Shader->Bind();
      m_Shader->SetFloat4("u_Color", { 0.7f, 0.1f, 0.2f, 1.0f });
      RenderCommand::DrawIndexed(m_VertexArray, 6);
      ////////////////////////////////////////////////
      if (!m_Minimized)
      {
        for (Layer* layer : m_LayerStack)
          layer->OnUpdate();
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
    return false;
  }

}
