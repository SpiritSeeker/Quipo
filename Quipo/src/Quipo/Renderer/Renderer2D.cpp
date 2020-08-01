#include "qppch.h"
#include "Renderer2D.h"

#include "Quipo/Core/Core.h"

#include "Quipo/Renderer/Buffer.h"
#include "Quipo/Renderer/VertexArray.h"
#include "Quipo/Renderer/Shader.h"

#include "Quipo/Renderer/RenderCommand.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Quipo {

  struct Renderer2DStorage
  {
    Ref<VertexArray> QuadVertexArray;
    Ref<Shader> TextureShader;
    Ref<Texture2D> WhiteTexture;
  };

  static Renderer2DStorage s_Data;

  void Renderer2D::Init()
  {
    s_Data.QuadVertexArray = VertexArray::Create();

    float vertices[20] = {
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
       0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
      -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    Ref<VertexBuffer> vertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));
    BufferLayout layout = {
      { ShaderDataType::Float3, "a_Position" },
      { ShaderDataType::Float2, "a_TexCoord" }
    };
    vertexBuffer->SetLayout(layout);
    s_Data.QuadVertexArray->AddVertexBuffer(vertexBuffer);

    uint32_t indices[6] = {
      0, 1, 2,
      2, 3, 0
    };

    Ref<IndexBuffer> indexBuffer = IndexBuffer::Create(indices, 6);
    s_Data.QuadVertexArray->SetIndexBuffer(indexBuffer);

    s_Data.WhiteTexture = Texture2D::Create(1, 1);
    uint32_t whiteTextureData = 0xffffffff;
    s_Data.WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

    s_Data.TextureShader = Shader::Create("Sandbox/assets/shaders/Texture.glsl");
    s_Data.TextureShader->Bind();
    s_Data.TextureShader->SetInt("u_Texture", 0);
  }

  void Renderer2D::Shutdown()
  {
  }

  void Renderer2D::BeginScene(const OrthographicCamera& camera)
  {
    s_Data.TextureShader->Bind();
    s_Data.TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
  }

  void Renderer2D::EndScene()
  {
  }

  void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
  {
    DrawQuad({ position.x, position.y, 0.0f }, size, color);
  }

  void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
  {
    s_Data.WhiteTexture->Bind();
    s_Data.TextureShader->SetInt("u_TilingFactor", 1);
    s_Data.TextureShader->SetFloat4("u_Color", color);

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                            * glm::scale(glm::mat4(1.0f), glm::vec3({ size.x, size.y, 1.0f }));
    s_Data.TextureShader->SetMat4("u_Transform", transform);

    s_Data.QuadVertexArray->Bind();
    RenderCommand::DrawIndexed(s_Data.QuadVertexArray);
  }

  void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, Ref<Texture2D>& texture, int tilingFactor, const glm::vec4& color)
  {
    DrawQuad({ position.x, position.y, 1.0f }, size, texture, tilingFactor, color);
  }

  void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, Ref<Texture2D>& texture, int tilingFactor, const glm::vec4& color)
  {
    texture->Bind();
    s_Data.TextureShader->SetInt("u_TilingFactor", tilingFactor);
    s_Data.TextureShader->SetFloat4("u_Color", color);

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                            * glm::scale(glm::mat4(1.0f), glm::vec3({ size.x, size.y, 1.0f }));
    s_Data.TextureShader->SetMat4("u_Transform", transform);

    s_Data.QuadVertexArray->Bind();
    RenderCommand::DrawIndexed(s_Data.QuadVertexArray);
  }

  void Renderer2D::DrawRotatedQuad(const glm::vec2& position, float rotation, const glm::vec2& size, const glm::vec4& color)
  {
    DrawRotatedQuad({ position.x, position.y, 0.0f }, rotation, size, color);
  }

  void Renderer2D::DrawRotatedQuad(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& color)
  {
    s_Data.WhiteTexture->Bind();
    s_Data.TextureShader->SetInt("u_TilingFactor", 1);
    s_Data.TextureShader->SetFloat4("u_Color", color);

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                            * glm::rotate(glm::mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f })
                            * glm::scale(glm::mat4(1.0f), glm::vec3({ size.x, size.y, 1.0f }));
    s_Data.TextureShader->SetMat4("u_Transform", transform);

    s_Data.QuadVertexArray->Bind();
    RenderCommand::DrawIndexed(s_Data.QuadVertexArray);
  }

  void Renderer2D::DrawRotatedQuad(const glm::vec2& position, float rotation, const glm::vec2& size, Ref<Texture2D>& texture, int tilingFactor, const glm::vec4& color)
  {
    DrawRotatedQuad({ position.x, position.y, 1.0f }, rotation, size, texture, tilingFactor, color);
  }

  void Renderer2D::DrawRotatedQuad(const glm::vec3& position, float rotation, const glm::vec2& size, Ref<Texture2D>& texture, int tilingFactor, const glm::vec4& color)
  {
    texture->Bind();
    s_Data.TextureShader->SetInt("u_TilingFactor", tilingFactor);
    s_Data.TextureShader->SetFloat4("u_Color", color);

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), position)
                            * glm::rotate(glm::mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f })
                            * glm::scale(glm::mat4(1.0f), glm::vec3({ size.x, size.y, 1.0f }));
    s_Data.TextureShader->SetMat4("u_Transform", transform);

    s_Data.QuadVertexArray->Bind();
    RenderCommand::DrawIndexed(s_Data.QuadVertexArray);
  }

}
