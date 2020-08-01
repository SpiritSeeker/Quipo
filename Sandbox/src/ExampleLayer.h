#pragma once

#include <Quipo.h>

class ExampleLayer : public Quipo::Layer
{
public:
  ExampleLayer();
  virtual ~ExampleLayer() = default;

  virtual void OnAttach() override;
  virtual void OnDetach() override;
  virtual void OnUpdate(Quipo::Timestep ts) override;
  virtual void OnEvent(Quipo::Event& e) override;
};
