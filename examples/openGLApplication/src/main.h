//
// Created by Matt Whitaker on 24/04/2021.
//

#ifndef EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_
#define EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_

class Application : public Kaishi::KaishiApplication {
  using Kaishi::KaishiApplication::KaishiApplication;
 public:
  int renderLoop(Kaishi::Window* window) override;
};

#endif // EXAMPLES_OPENGLAPPLICATION_SRC_MAIN_H_
