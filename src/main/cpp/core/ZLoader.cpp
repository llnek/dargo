// This library is distributed in  the hope that it will be useful but without
// any  warranty; without  even  the  implied  warranty of  merchantability or
// fitness for a particular purpose.
// The use and distribution terms for this software are covered by the Eclipse
// Public License 1.0  (http://opensource.org/licenses/eclipse-1.0.php)  which
// can be found in the file epl-v10.html at the root of this distribution.
// By using this software in any  fashion, you are agreeing to be bound by the
// terms of this license. You  must not remove this notice, or any other, from
// this software.
// Copyright (c) 2013-2016, Kenneth Leung. All rights reserved.

#include "base/CCRef.h"
#include "ZLoader.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
void ZLoader::onEnter() {
  c::Scene::onEnter();
  this->schedule(CC_SCHEDULE_SELECTOR(ZLoader::startLoad), 0.3);
}

//////////////////////////////////////////////////////////////////////////////
//
void ZLoader::initWithResources() {
}

//////////////////////////////////////////////////////////////////////////////
//
void ZLoader::startLoad(float delta) {
  this->unschedule(CC_SCHEDULE_SELECTOR(ZLoader::startLoad));
}



NS_END


