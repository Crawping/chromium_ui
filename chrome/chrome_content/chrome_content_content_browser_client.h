// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_CONTENT_BROWSER_CLIENT_H_
#define UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_CONTENT_BROWSER_CLIENT_H_

#include <string>

#include "base/compiler_specific.h"
#include "base/memory/scoped_ptr.h"
#include "content/public/app/content_browser_client.h"

namespace views {
namespace chromemain {

class ChromeBrowserMainParts;

class ChromeContentBrowserClient : public content::ContentBrowserClient {
 public:
  ChromeContentBrowserClient();
  virtual ~ChromeContentBrowserClient();

  // Overridden from content::ContentBrowserClient:
   virtual content::BrowserMainParts* CreateBrowserMainParts(
      ) OVERRIDE;

 private:
  ChromeBrowserMainParts* examples_browser_main_parts_;

  DISALLOW_COPY_AND_ASSIGN(ChromeContentBrowserClient);
};

}  // namespace examples
}  // namespace views

#endif  // UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_CONTENT_BROWSER_CLIENT_H_
