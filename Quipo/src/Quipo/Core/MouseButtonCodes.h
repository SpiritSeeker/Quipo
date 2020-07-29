#pragma once

namespace Quipo
{
  typedef enum class MouseCode : uint16_t
  {
    // From glfw3.h
    Button0                = 0,
    Button1                = 1,
    Button2                = 2,
    Button3                = 3,
    Button4                = 4,
    Button5                = 5,
    Button6                = 6,
    Button7                = 7,

    ButtonLast             = Button7,
    ButtonLeft             = Button0,
    ButtonRight            = Button1,
    ButtonMiddle           = Button2
  } Mouse;

  inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
  {
    os << static_cast<int32_t>(mouseCode);
    return os;
  }
}

#define QP_MOUSE_BUTTON_0      ::Quipo::Mouse::Button0
#define QP_MOUSE_BUTTON_1      ::Quipo::Mouse::Button1
#define QP_MOUSE_BUTTON_2      ::Quipo::Mouse::Button2
#define QP_MOUSE_BUTTON_3      ::Quipo::Mouse::Button3
#define QP_MOUSE_BUTTON_4      ::Quipo::Mouse::Button4
#define QP_MOUSE_BUTTON_5      ::Quipo::Mouse::Button5
#define QP_MOUSE_BUTTON_6      ::Quipo::Mouse::Button6
#define QP_MOUSE_BUTTON_7      ::Quipo::Mouse::Button7
#define QP_MOUSE_BUTTON_LAST   ::Quipo::Mouse::ButtonLast
#define QP_MOUSE_BUTTON_LEFT   ::Quipo::Mouse::ButtonLeft
#define QP_MOUSE_BUTTON_RIGHT  ::Quipo::Mouse::ButtonRight
#define QP_MOUSE_BUTTON_MIDDLE ::Quipo::Mouse::ButtonMiddle
