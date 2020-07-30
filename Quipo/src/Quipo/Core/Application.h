#pragma once

#include "Quipo/Core/Core.h"
#include "Quipo/Core/Window.h"

#include "Quipo/Core/LayerStack.h"

#include "Quipo/Events/Event.h"
#include "Quipo/Events/ApplicationEvent.h"
#include "Quipo/Events/MouseEvent.h"
#include "Quipo/Events/KeyEvent.h"

#include "Quipo/Renderer/Buffer.h"
#include "Quipo/Renderer/Shader.h"
#include "Quipo/Renderer/VertexArray.h"

namespace Quipo {

  class Application
  {
  public:
    Application(const std::string& name = "Quipo Application");
    virtual ~Application();

    void Run();
    void OnEvent(Event& e);

    void Close();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    inline Window& GetWindow() { return *m_Window; }
    inline static Application& Get() { return *s_Instance; }
  private:
    bool OnWindowClose(WindowCloseEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);
  private:
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
    bool m_Minimized = false;

    LayerStack m_LayerStack;

    Ref<VertexArray> m_VertexArray;
    Ref<VertexBuffer> m_VertexBuffer;
    Ref<IndexBuffer> m_IndexBuffer;
    Ref<Shader> m_Shader;
  private:
    static Application* s_Instance;
  };

  Application* CreateApplication();

}
