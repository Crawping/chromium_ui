// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/ui/views/frame/contents_container.h"

ContentsContainer::ContentsContainer(views::View* active_web_view)
    : active_web_view_(active_web_view),
      active_top_margin_(0) {
  AddChildView(active_web_view_);
}

ContentsContainer::~ContentsContainer() {
}

bool ContentsContainer::SetActiveTopMargin(int margin) {
  if (active_top_margin_ == margin)
    return false;

  active_top_margin_ = margin;
  // Make sure we layout next time around. We need this in case our bounds
  // haven't changed.
  InvalidateLayout();
  return true;
}

void ContentsContainer::Layout() {
  int content_y = active_top_margin_;
  int content_height = std::max(0, height() - content_y);

  active_web_view_->SetBounds(0, content_y, width(), content_height);

  // Need to invoke views::View in case any views whose bounds didn't change
  // still need a layout.
  views::View::Layout();
}

const char* ContentsContainer::GetClassName() const {
  return "ContentsContainer";
}
