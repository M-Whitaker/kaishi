//
// Created by Matt Whitaker on 28/02/2021.
//

#include <iostream>

#include <Kaishi/Application.h>

class Application : public Kaishi::KaishiApplication {
  using Kaishi::KaishiApplication::KaishiApplication;
};

int
main(int argc, const char **argv) {
  Application app = Application((char *) "openGLApplication", 1.0);
  std::cout << "Application name: " << app.getName() << "\n";

  app.mainLoop();

  return 0;
}
