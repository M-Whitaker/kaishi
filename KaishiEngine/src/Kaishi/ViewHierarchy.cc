//
// Created by Matt Whitaker on 19/04/2021.
//

#include "ViewHierarchy.h"

namespace Kaishi {

void ViewHierarchy::addView(View *view) {
  m_RenderViews.push_back(view);
}
void ViewHierarchy::addGUIView(View *view) {
  m_GuiViews.push_back(view);
}

}  // namespace Kaishi
