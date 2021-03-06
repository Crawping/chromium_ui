// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/ui/tabs/pinned_tab_service_factory.h"

//#include "chrome/browser/profiles/profile.h"
#include "chrome/ui/tabs/pinned_tab_service.h"
//#include "components/browser_context_keyed_service/browser_context_dependency_manager.h"

// static
PinnedTabService* PinnedTabServiceFactory::GetForProfile() {
  return NULL;/*static_cast<PinnedTabService*>(
      GetInstance()->GetServiceForBrowserContext(profile, true));*/
}

PinnedTabServiceFactory* PinnedTabServiceFactory::GetInstance() {
  return Singleton<PinnedTabServiceFactory>::get();
}

PinnedTabServiceFactory::PinnedTabServiceFactory(){
}

PinnedTabServiceFactory::~PinnedTabServiceFactory() {
}

/*BrowserContextKeyedService* PinnedTabServiceFactory::BuildServiceInstanceFor(
    content::BrowserContext* profile) const {
  return new PinnedTabService(static_cast<Profile*>(profile));
}*/

//bool PinnedTabServiceFactory::ServiceIsCreatedWithBrowserContext() const {
//  return true;
//}

//bool PinnedTabServiceFactory::ServiceIsNULLWhileTesting() const {
//  return true;
//}
