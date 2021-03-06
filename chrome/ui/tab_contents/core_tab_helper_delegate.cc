// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/ui/tab_contents/core_tab_helper_delegate.h"

CoreTabHelperDelegate::~CoreTabHelperDelegate() {
}

void CoreTabHelperDelegate::SwapTabContents(
    content::WebContents* old_contents,
    content::WebContents* new_contents) {
}

bool CoreTabHelperDelegate::CanReloadContents(
    content::WebContents* web_contents) const {
  return true;
}

bool CoreTabHelperDelegate::CanSaveContents(
    content::WebContents* web_contents) const {
  return true;
}
