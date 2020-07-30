#include "qppch.h"
#include "VertexArray.h"

#include "Quipo/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Quipo {

  Ref<VertexArray> VertexArray::Create()
  {
    switch (Renderer::GetAPI())
    {
      case RendererAPI::API::None:     QP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
      case RendererAPI::API::OpenGL:   return CreateRef<OpenGLVertexArray>();
    }

    QP_CORE_ASSERT(false, "Unknown RendererAPI!");
    return nullptr;
  }

}
