#include "qppch.h"
#include "LayerStack.h"

namespace Quipo {

  LayerStack::LayerStack()
  {
  }

  LayerStack::~LayerStack()
  {
    for (Layer* layer : m_Layers)
    {
      layer->OnDetach();
      delete layer;
    }
  }

  void LayerStack::PushLayer(Layer* layer)
  {
    m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
    m_LayerInsertIndex++;
  }

  void LayerStack::PushOverlay(Layer* overlay)
  {
    m_Layers.emplace_back(overlay);
  }

  void LayerStack::PopLayer(Layer* layer)
  {
    auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
    if (it != m_Layers.begin() + m_LayerInsertIndex)
    {
      layer->OnDetach();
      m_Layers.erase(it);
      m_LayerInsertIndex--;
    }
    else
      QP_CORE_WARN("Layer \"{0}\" not in LayerStack!", layer->GetName());
  }

  void LayerStack::PopOverlay(Layer* overlay)
  {
    auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
    if (it != m_Layers.begin() + m_LayerInsertIndex)
    {
      overlay->OnDetach();
      m_Layers.erase(it);
    }
    else
      QP_CORE_WARN("Overlay \"{0}\" not in LayerStack!", overlay->GetName());
  }


}
