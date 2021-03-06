// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/ui/views/frame/native_browser_frame_factory.h"

#include "chrome/ui/views/frame/browser_frame_win.h"

NativeBrowserFrame* NativeBrowserFrameFactory::Create(
    BrowserFrame* browser_frame,
    BrowserView* browser_view) {
  return new BrowserFrameWin(browser_frame, browser_view);
}
