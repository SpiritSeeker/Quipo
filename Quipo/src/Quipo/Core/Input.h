#pragma once

#include "Quipo/Core/Core.h"
#include "Quipo/Core/KeyCodes.h"
#include "Quipo/Core/MouseButtonCodes.h"

namespace Quipo {

  class Input
  {
  public:
    static bool IsKeyPressed(KeyCode keycode);

    static bool IsMouseButtonPressed(MouseCode button);
    static std::pair<float, float> GetMousePosition();
    static float GetMouseX();
    static float GetMouseY();
  };

}
