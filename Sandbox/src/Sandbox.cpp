#include <Quipo.h>
#include <Quipo/Core/EntryPoint.h>

#include "ExampleLayer.h"

class Sandbox : public Quipo::Application
{
public:
  Sandbox()
    : Quipo::Application("Sandbox")
  {
    PushLayer(new ExampleLayer());
  }

  ~Sandbox()
  {
  }
};

Quipo::Application* Quipo::CreateApplication()
{
  return new Sandbox();
}
