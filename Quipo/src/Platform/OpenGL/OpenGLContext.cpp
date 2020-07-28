#include "qppch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Quipo {

  OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
    : m_WindowHandle(windowHandle)
  {
    QP_CORE_ASSERT(windowHandle, "Window handle is null!");
  }

  void OpenGLContext::Init()
  {
    glfwMakeContextCurrent(m_WindowHandle);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QP_CORE_ASSERT(status, "Failed to initialize Glad!");

    QP_CORE_INFO("OpenGL Info:");
    QP_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
    QP_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
    QP_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
  }

  void OpenGLContext::SwapBuffers()
  {
    glfwSwapBuffers(m_WindowHandle);
  }

}
