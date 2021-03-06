#include "qppch.h"
#include "Renderer.h"

#include "Quipo/Renderer/Renderer2D.h"

namespace Quipo {

  void Renderer::Init()
  {
    RenderCommand::Init();
    Renderer2D::Init();
  }

  void Renderer::OnWindowResize(uint32_t width, uint32_t height)
  {
    RenderCommand::SetViewport(0, 0, width, height);
  }

  void Renderer::Begin()
  {
  }

  void Renderer::End()
  {
  }

  void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& viewProjection, const glm::mat4& transform)
  {
    shader->Bind();
    shader->SetMat4("u_ViewProjection", viewProjection);
    shader->SetMat4("u_Transform", transform);

    vertexArray->Bind();
    RenderCommand::DrawIndexed(vertexArray);
  }

}
