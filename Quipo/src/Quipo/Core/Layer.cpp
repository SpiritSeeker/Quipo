#include "qppch.h"
#include "Layer.h"

namespace Quipo {

  Layer::Layer(const std::string& layerName)
    : m_DebugName(layerName) {}

  Layer::~Layer()
  {
  }

}
