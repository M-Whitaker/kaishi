//
// Created by Matt Whitaker on 17/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_UTILS_MATH_H_
#define KAISHIENGINE_INCLUDE_KAISHI_UTILS_MATH_H_

namespace Kaishi {

class Math {
 public:
  static int max(int a, int b) {
    if (a >= b) {
      return a;
    } else {
      return b;
    }
  }
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_UTILS_MATH_H_
