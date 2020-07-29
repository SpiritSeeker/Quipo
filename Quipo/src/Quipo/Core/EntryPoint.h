#pragma once

extern Quipo::Application* Quipo::CreateApplication();

int main(int argc, char const *argv[])
{
  Quipo::Log::Init();
  QP_CORE_WARN("Initialized Quipo!");

  Quipo::Application* app = Quipo::CreateApplication();
  app->Run();
  delete app;
  return 0;
}
