#include "ExampleLayer.h"

ExampleLayer::ExampleLayer()
  : Quipo::Layer("ExampleLayer"), m_CameraController(1280.0f/ 720.0f) {}

void ExampleLayer::OnAttach()
{
  m_VertexArray = Quipo::VertexArray::Create();

  float vertices[20] = {
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
  };

  m_VertexBuffer = Quipo::VertexBuffer::Create(vertices, sizeof(vertices));
  Quipo::BufferLayout layout = {
    { Quipo::ShaderDataType::Float3, "a_Position" },
    { Quipo::ShaderDataType::Float2, "a_TexCoord" }
  };
  m_VertexBuffer->SetLayout(layout);
  m_VertexArray->AddVertexBuffer(m_VertexBuffer);

  uint32_t indices[6] = {
    0, 1, 2,
    2, 3, 0
  };

  m_IndexBuffer = Quipo::IndexBuffer::Create(indices, 6);
  m_VertexArray->SetIndexBuffer(m_IndexBuffer);

  m_Shader = Quipo::Shader::Create("Sandbox/assets/shaders/Texture.glsl");
  m_Shader->Bind();

  m_Texture = Quipo::Texture2D::Create("Sandbox/assets/textures/cloud.png");
}

void ExampleLayer::OnDetach()
{
}

void ExampleLayer::OnUpdate(Quipo::Timestep ts)
{
  if (Quipo::Input::IsKeyPressed(QP_KEY_A))
    QP_INFO("Key \'A\' is pressed!");

    Quipo::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
    Quipo::RenderCommand::Clear();

    m_Shader->Bind();
    m_Texture->Bind(0);
    m_Shader->SetInt("u_Texture", 0);
    m_Shader->SetMat4("u_ViewProjection", m_CameraController.GetCamera().GetViewProjectionMatrix());
    Quipo::RenderCommand::DrawIndexed(m_VertexArray, 6);

    m_CameraController.OnUpdate(ts);
}

void ExampleLayer::OnEvent(Quipo::Event& e)
{
  m_CameraController.OnEvent(e);
}
