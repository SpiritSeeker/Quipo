#pragma once

#include "Quipo/Renderer/OrthographicCamera.h"

namespace Quipo {

  class Renderer2D
  {
  public:
    static void Init();
    static void Shutdown();

    static void BeginScene(const OrthographicCamera& camera);
    static void EndScene();

    // Draw Primitives
    static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
  };

}
