#include <Quipo.h>

class Sandbox : public Quipo::Application
{
public:
  Sandbox()
    : Quipo::Application("Sandbox")
  {
  }

  ~Sandbox()
  {
  }
};

Quipo::Application* Quipo::CreateApplication()
{
  return new Sandbox();
}
