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
  Application app = Application((char *) "My Application", 1.0);

  printf("Application name: %s\n", app.getName());

  return 0;
}
