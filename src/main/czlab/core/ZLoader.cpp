/* Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (c) 2013-2016, Kenneth Leung. All rights reserved. */

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


