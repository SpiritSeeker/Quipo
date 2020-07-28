#pragma once

namespace Quipo {

  class Application
  {
  public:
    Application(const std::string& name = "Quipo Application");
    virtual ~Application();

    void Run();

    void Close();

    inline static Application& Get() { return *s_Instance; }
  private:
    bool m_Running = true;
  private:
    static Application* s_Instance;
  };

  Application* CreateApplication();

}
