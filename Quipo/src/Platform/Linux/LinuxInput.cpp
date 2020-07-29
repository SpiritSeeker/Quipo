#include "qppch.h"
#include "Quipo/Core/Input.h"

#include "Quipo/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Quipo {

  bool Input::IsKeyPressed(KeyCode keycode)
  {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, static_cast<int32_t>(keycode));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
  }

  bool Input::IsMouseButtonPressed(MouseCode button)
  {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
    return state == GLFW_PRESS;
  }

  std::pair<float, float> Input::GetMousePosition()
  {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return { (float)xpos, (float)ypos };
  }

  float Input::GetMouseX()
  {
    auto pos = GetMousePosition();
    return pos.first;
  }

  float Input::GetMouseY()
  {
    auto pos = GetMousePosition();
    return pos.second;
  }

}
