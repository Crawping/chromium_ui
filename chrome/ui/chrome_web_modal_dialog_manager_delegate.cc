// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/ui/chrome_web_modal_dialog_manager_delegate.h"

#include "chrome/browser/platform_util.h"
#include "chrome/browser/web_contents.h"
#include "chrome/browser/web_contents_view.h"

ChromeWebModalDialogManagerDelegate::ChromeWebModalDialogManagerDelegate() {
}

ChromeWebModalDialogManagerDelegate::~ChromeWebModalDialogManagerDelegate() {
}

bool ChromeWebModalDialogManagerDelegate::IsWebContentsVisible(
    content::WebContents* web_contents) {
  return platform_util::IsVisible(web_contents->GetView()->GetNativeView());
}
