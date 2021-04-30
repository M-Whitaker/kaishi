//
// Created by Matt Whitaker on 18/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_VIEW_H_
#define KAISHIENGINE_INCLUDE_KAISHI_VIEW_H_

namespace Kaishi {

class View {
 public:
  virtual void onAttach() = 0;
  virtual void onDetach() = 0;
  virtual void renderLoop() = 0;
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_VIEW_H_
