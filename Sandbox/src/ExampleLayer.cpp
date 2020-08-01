#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
  : Quipo::Layer("ExampleLayer") {}

void ExampleLayer::OnAttach()
{
}

void ExampleLayer::OnDetach()
{
}

void ExampleLayer::OnUpdate(Quipo::Timestep ts)
{
  if (Quipo::Input::IsKeyPressed(QP_KEY_A))
    QP_INFO("Key \'A\' is pressed!");
}

void ExampleLayer::OnEvent(Quipo::Event& e)
{
}
