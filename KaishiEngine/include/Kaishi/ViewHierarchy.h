//
// Created by Matt Whitaker on 19/04/2021.
//

#ifndef KAISHIENGINE_INCLUDE_KAISHI_VIEWHIERARCHY_H_
#define KAISHIENGINE_INCLUDE_KAISHI_VIEWHIERARCHY_H_

#include "kaipch.h"

#include <vector>

#include "View.h"

namespace Kaishi {

class ViewHierarchy {
 private:
  std::vector<View*> m_RenderViews;
  std::vector<View*> m_GuiViews;
 public:
  void addView(View *view);
  void addGUIView(View *view);
  std::vector<View*> getViews();
};

}  // namespace Kaishi

#endif  // KAISHIENGINE_INCLUDE_KAISHI_VIEWHIERARCHY_H_
