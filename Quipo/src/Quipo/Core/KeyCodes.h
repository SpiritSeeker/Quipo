#pragma once

namespace Quipo
{
  typedef enum class KeyCode : uint16_t
  {
    // From glfw3.h
    Space               = 32,
    Apostrophe          = 39, /* ' */
    Comma               = 44, /* , */
    Minus               = 45, /* - */
    Period              = 46, /* . */
    Slash               = 47, /* / */

    D0                  = 48, /* 0 */
    D1                  = 49, /* 1 */
    D2                  = 50, /* 2 */
    D3                  = 51, /* 3 */
    D4                  = 52, /* 4 */
    D5                  = 53, /* 5 */
    D6                  = 54, /* 6 */
    D7                  = 55, /* 7 */
    D8                  = 56, /* 8 */
    D9                  = 57, /* 9 */

    Semicolon           = 59, /* ; */
    Equal               = 61, /* = */

    A                   = 65,
    B                   = 66,
    C                   = 67,
    D                   = 68,
    E                   = 69,
    F                   = 70,
    G                   = 71,
    H                   = 72,
    I                   = 73,
    J                   = 74,
    K                   = 75,
    L                   = 76,
    M                   = 77,
    N                   = 78,
    O                   = 79,
    P                   = 80,
    Q                   = 81,
    R                   = 82,
    S                   = 83,
    T                   = 84,
    U                   = 85,
    V                   = 86,
    W                   = 87,
    X                   = 88,
    Y                   = 89,
    Z                   = 90,

    LeftBracket         = 91,  /* [ */
    Backslash           = 92,  /* \ */
    RightBracket        = 93,  /* ] */
    GraveAccent         = 96,  /* ` */

    World1              = 161, /* non-US #1 */
    World2              = 162, /* non-US #2 */

    /* Function keys */
    Escape              = 256,
    Enter               = 257,
    Tab                 = 258,
    Backspace           = 259,
    Insert              = 260,
    Delete              = 261,
    Right               = 262,
    Left                = 263,
    Down                = 264,
    Up                  = 265,
    PageUp              = 266,
    PageDown            = 267,
    Home                = 268,
    End                 = 269,
    CapsLock            = 280,
    ScrollLock          = 281,
    NumLock             = 282,
    PrintScreen         = 283,
    Pause               = 284,
    F1                  = 290,
    F2                  = 291,
    F3                  = 292,
    F4                  = 293,
    F5                  = 294,
    F6                  = 295,
    F7                  = 296,
    F8                  = 297,
    F9                  = 298,
    F10                 = 299,
    F11                 = 300,
    F12                 = 301,
    F13                 = 302,
    F14                 = 303,
    F15                 = 304,
    F16                 = 305,
    F17                 = 306,
    F18                 = 307,
    F19                 = 308,
    F20                 = 309,
    F21                 = 310,
    F22                 = 311,
    F23                 = 312,
    F24                 = 313,
    F25                 = 314,

    /* Keypad */
    KP0                 = 320,
    KP1                 = 321,
    KP2                 = 322,
    KP3                 = 323,
    KP4                 = 324,
    KP5                 = 325,
    KP6                 = 326,
    KP7                 = 327,
    KP8                 = 328,
    KP9                 = 329,
    KPDecimal           = 330,
    KPDivide            = 331,
    KPMultiply          = 332,
    KPSubtract          = 333,
    KPAdd               = 334,
    KPEnter             = 335,
    KPEqual             = 336,

    LeftShift           = 340,
    LeftControl         = 341,
    LeftAlt             = 342,
    LeftSuper           = 343,
    RightShift          = 344,
    RightControl        = 345,
    RightAlt            = 346,
    RightSuper          = 347,
    Menu                = 348
  } Key;

  inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
  {
    os << static_cast<int32_t>(keyCode);
    return os;
  }
}

// From glfw3.h
#define QP_KEY_SPACE           ::Quipo::Key::Space
#define QP_KEY_APOSTROPHE      ::Quipo::Key::Apostrophe    /* ' */
#define QP_KEY_COMMA           ::Quipo::Key::Comma         /* , */
#define QP_KEY_MINUS           ::Quipo::Key::Minus         /* - */
#define QP_KEY_PERIOD          ::Quipo::Key::Period        /* . */
#define QP_KEY_SLASH           ::Quipo::Key::Slash         /* / */
#define QP_KEY_0               ::Quipo::Key::D0
#define QP_KEY_1               ::Quipo::Key::D1
#define QP_KEY_2               ::Quipo::Key::D2
#define QP_KEY_3               ::Quipo::Key::D3
#define QP_KEY_4               ::Quipo::Key::D4
#define QP_KEY_5               ::Quipo::Key::D5
#define QP_KEY_6               ::Quipo::Key::D6
#define QP_KEY_7               ::Quipo::Key::D7
#define QP_KEY_8               ::Quipo::Key::D8
#define QP_KEY_9               ::Quipo::Key::D9
#define QP_KEY_SEMICOLON       ::Quipo::Key::Semicolon     /* ; */
#define QP_KEY_EQUAL           ::Quipo::Key::Equal         /* = */
#define QP_KEY_A               ::Quipo::Key::A
#define QP_KEY_B               ::Quipo::Key::B
#define QP_KEY_C               ::Quipo::Key::C
#define QP_KEY_D               ::Quipo::Key::D
#define QP_KEY_E               ::Quipo::Key::E
#define QP_KEY_F               ::Quipo::Key::F
#define QP_KEY_G               ::Quipo::Key::G
#define QP_KEY_H               ::Quipo::Key::H
#define QP_KEY_I               ::Quipo::Key::I
#define QP_KEY_J               ::Quipo::Key::J
#define QP_KEY_K               ::Quipo::Key::K
#define QP_KEY_L               ::Quipo::Key::L
#define QP_KEY_M               ::Quipo::Key::M
#define QP_KEY_N               ::Quipo::Key::N
#define QP_KEY_O               ::Quipo::Key::O
#define QP_KEY_P               ::Quipo::Key::P
#define QP_KEY_Q               ::Quipo::Key::Q
#define QP_KEY_R               ::Quipo::Key::R
#define QP_KEY_S               ::Quipo::Key::S
#define QP_KEY_T               ::Quipo::Key::T
#define QP_KEY_U               ::Quipo::Key::U
#define QP_KEY_V               ::Quipo::Key::V
#define QP_KEY_W               ::Quipo::Key::W
#define QP_KEY_X               ::Quipo::Key::X
#define QP_KEY_Y               ::Quipo::Key::Y
#define QP_KEY_Z               ::Quipo::Key::Z
#define QP_KEY_LEFT_BRACKET    ::Quipo::Key::LeftBracket   /* [ */
#define QP_KEY_BACKSLASH       ::Quipo::Key::Backslash     /* \ */
#define QP_KEY_RIGHT_BRACKET   ::Quipo::Key::RightBracket  /* ] */
#define QP_KEY_GRAVE_ACCENT    ::Quipo::Key::GraveAccent   /* ` */
#define QP_KEY_WORLD_1         ::Quipo::Key::World1        /* non-US #1 */
#define QP_KEY_WORLD_2         ::Quipo::Key::World2        /* non-US #2 */

/* Function keys */
#define QP_KEY_ESCAPE          ::Quipo::Key::Escape
#define QP_KEY_ENTER           ::Quipo::Key::Enter
#define QP_KEY_TAB             ::Quipo::Key::Tab
#define QP_KEY_BACKSPACE       ::Quipo::Key::Backspace
#define QP_KEY_INSERT          ::Quipo::Key::Insert
#define QP_KEY_DELETE          ::Quipo::Key::Delete
#define QP_KEY_RIGHT           ::Quipo::Key::Right
#define QP_KEY_LEFT            ::Quipo::Key::Left
#define QP_KEY_DOWN            ::Quipo::Key::Down
#define QP_KEY_UP              ::Quipo::Key::Up
#define QP_KEY_PAGE_UP         ::Quipo::Key::PageUp
#define QP_KEY_PAGE_DOWN       ::Quipo::Key::PageDown
#define QP_KEY_HOME            ::Quipo::Key::Home
#define QP_KEY_END             ::Quipo::Key::End
#define QP_KEY_CAPS_LOCK       ::Quipo::Key::CapsLock
#define QP_KEY_SCROLL_LOCK     ::Quipo::Key::ScrollLock
#define QP_KEY_NUM_LOCK        ::Quipo::Key::NumLock
#define QP_KEY_PRINT_SCREEN    ::Quipo::Key::PrintScreen
#define QP_KEY_PAUSE           ::Quipo::Key::Pause
#define QP_KEY_F1              ::Quipo::Key::F1
#define QP_KEY_F2              ::Quipo::Key::F2
#define QP_KEY_F3              ::Quipo::Key::F3
#define QP_KEY_F4              ::Quipo::Key::F4
#define QP_KEY_F5              ::Quipo::Key::F5
#define QP_KEY_F6              ::Quipo::Key::F6
#define QP_KEY_F7              ::Quipo::Key::F7
#define QP_KEY_F8              ::Quipo::Key::F8
#define QP_KEY_F9              ::Quipo::Key::F9
#define QP_KEY_F10             ::Quipo::Key::F10
#define QP_KEY_F11             ::Quipo::Key::F11
#define QP_KEY_F12             ::Quipo::Key::F12
#define QP_KEY_F13             ::Quipo::Key::F13
#define QP_KEY_F14             ::Quipo::Key::F14
#define QP_KEY_F15             ::Quipo::Key::F15
#define QP_KEY_F16             ::Quipo::Key::F16
#define QP_KEY_F17             ::Quipo::Key::F17
#define QP_KEY_F18             ::Quipo::Key::F18
#define QP_KEY_F19             ::Quipo::Key::F19
#define QP_KEY_F20             ::Quipo::Key::F20
#define QP_KEY_F21             ::Quipo::Key::F21
#define QP_KEY_F22             ::Quipo::Key::F22
#define QP_KEY_F23             ::Quipo::Key::F23
#define QP_KEY_F24             ::Quipo::Key::F24
#define QP_KEY_F25             ::Quipo::Key::F25

/* Keypad */
#define QP_KEY_KP_0            ::Quipo::Key::KP0
#define QP_KEY_KP_1            ::Quipo::Key::KP1
#define QP_KEY_KP_2            ::Quipo::Key::KP2
#define QP_KEY_KP_3            ::Quipo::Key::KP3
#define QP_KEY_KP_4            ::Quipo::Key::KP4
#define QP_KEY_KP_5            ::Quipo::Key::KP5
#define QP_KEY_KP_6            ::Quipo::Key::KP6
#define QP_KEY_KP_7            ::Quipo::Key::KP7
#define QP_KEY_KP_8            ::Quipo::Key::KP8
#define QP_KEY_KP_9            ::Quipo::Key::KP9
#define QP_KEY_KP_DECIMAL      ::Quipo::Key::KPDecimal
#define QP_KEY_KP_DIVIDE       ::Quipo::Key::KPDivide
#define QP_KEY_KP_MULTIPLY     ::Quipo::Key::KPMultiply
#define QP_KEY_KP_SUBTRACT     ::Quipo::Key::KPSubtract
#define QP_KEY_KP_ADD          ::Quipo::Key::KPAdd
#define QP_KEY_KP_ENTER        ::Quipo::Key::KPEnter
#define QP_KEY_KP_EQUAL        ::Quipo::Key::KPEqual

#define QP_KEY_LEFT_SHIFT      ::Quipo::Key::LeftShift
#define QP_KEY_LEFT_CONTROL    ::Quipo::Key::LeftControl
#define QP_KEY_LEFT_ALT        ::Quipo::Key::LeftAlt
#define QP_KEY_LEFT_SUPER      ::Quipo::Key::LeftSuper
#define QP_KEY_RIGHT_SHIFT     ::Quipo::Key::RightShift
#define QP_KEY_RIGHT_CONTROL   ::Quipo::Key::RightControl
#define QP_KEY_RIGHT_ALT       ::Quipo::Key::RightAlt
#define QP_KEY_RIGHT_SUPER     ::Quipo::Key::RightSuper
#define QP_KEY_MENU            ::Quipo::Key::Menu
