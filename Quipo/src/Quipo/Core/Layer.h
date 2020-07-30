#pragma once

#include "Quipo/Events/Event.h"

namespace Quipo {

  class Layer
  {
  public:
    Layer(const std::string& layerName = "Layer");
    virtual ~Layer();

    virtual void OnAttach() = 0;
    virtual void OnDetach() = 0;
    virtual void OnUpdate() = 0;
    virtual void OnEvent(Event& e) = 0;

    inline const std::string& GetName() const { return m_DebugName; }
  protected:
    std::string m_DebugName;
  };

}
