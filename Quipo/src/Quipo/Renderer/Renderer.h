#pragma once

#include "Quipo/Renderer/RenderCommand.h"

#include "Quipo/Renderer/Shader.h"

namespace Quipo {

  class Renderer
  {
  public:
    static void Init();
    static void OnWindowResize(uint32_t width, uint32_t height);

    static void Begin();
    static void End();

    static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& viewProjection = glm::mat4(1.0f), const glm::mat4& transform = glm::mat4(1.0f));

    inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
  };

}
