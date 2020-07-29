#pragma once

namespace Quipo {

  class GraphicsContext
  {
  public:
    virtual void Init() = 0;
    virtual void SwapBuffers() = 0;
  };

}
