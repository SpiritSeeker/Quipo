#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
  : Quipo::Layer("ExampleLayer"), m_CameraController(1280.0f/ 720.0f) {}

void ExampleLayer::OnAttach()
{
  m_Texture = Quipo::Texture2D::Create("Sandbox/assets/textures/cloud.png");
}

void ExampleLayer::OnDetach()
{
}

void ExampleLayer::OnUpdate(Quipo::Timestep ts)
{
  Quipo::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1.0f });
  Quipo::RenderCommand::Clear();

  Quipo::Renderer2D::BeginScene(m_CameraController.GetCamera());

  Quipo::Renderer2D::DrawQuad(glm::vec2({ -0.25f, -0.25f }), glm::vec2(0.45f), glm::vec4({ 0.0f, 0.6f, 0.9f, 1.0f }));
  Quipo::Renderer2D::DrawQuad(glm::vec2({ -0.25f,  0.25f }), glm::vec2(0.45f), glm::vec4({ 0.9f, 0.3f, 0.1f, 1.0f }));
  Quipo::Renderer2D::DrawQuad(glm::vec2({  0.25f,  0.25f }), glm::vec2(0.45f), glm::vec4({ 0.5f, 0.7f, 0.0f, 1.0f }));
  Quipo::Renderer2D::DrawQuad(glm::vec2({  0.25f, -0.25f }), glm::vec2(0.45f), glm::vec4({ 1.0f, 0.7f, 0.0f, 1.0f }));

  Quipo::Renderer2D::DrawQuad(glm::vec2({ -0.5f, -0.5f }), glm::vec2(0.25f), m_Texture, 2, glm::vec4({ 1.0f, 1.0f, 1.0f, 0.5f }));

  Quipo::Renderer2D::EndScene();

  m_CameraController.OnUpdate(ts);
}

void ExampleLayer::OnEvent(Quipo::Event& e)
{
  m_CameraController.OnEvent(e);
}
