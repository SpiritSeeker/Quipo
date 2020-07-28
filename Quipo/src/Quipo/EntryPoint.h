#pragma once

extern Quipo::Application* Quipo::CreateApplication();

int main(int argc, char const *argv[])
{
  Quipo::Application* app = Quipo::CreateApplication();
  app->Run();
  delete app;
  return 0;
}
