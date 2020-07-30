#include "qppch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Quipo {

  RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
