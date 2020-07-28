#pragma once

#include "Quipo/GraphicsContext.h"

struct GLFWwindow;

namespace Quipo {

  class OpenGLContext : public GraphicsContext
  {
  public:
    OpenGLContext(GLFWwindow* windowHandle);

    virtual void Init() override;
    virtual void SwapBuffers() override;
  private:
    GLFWwindow* m_WindowHandle;
  };

}
