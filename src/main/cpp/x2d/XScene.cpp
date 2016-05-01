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

#include "core/XConfig.h"
#include "core/CCSX.h"
#include "XScene.h"
NS_ALIAS(cx, fusii::ccsx)
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
XLayer* XScene::addLayer(not_null<XLayer*> y, int z) {
 this->addChild(y, z, y->getIID());
 return y;
}

//////////////////////////////////////////////////////////////////////////////
//
XLayer* XScene::getLayer(int tag) {
  return SCAST(XLayer*, getChildByTag(tag));
}

//////////////////////////////////////////////////////////////////////////////
//
bool XScene::init() {
  bool ok= _usePhysics ? c::Scene::initWithPhysics() : c::Scene::init();
  if (ok) { decoUI(); }
  return ok;
}

///////////////////////////////////////////////////////////////////////////////
//
XScene::~XScene() {
}

/////////////////////////////////////////////////////////////////////////////
//
XScene::XScene() {
  bind(this);
}

/////////////////////////////////////////////////////////////////////////////
//
XScene::XScene(bool physics) {
  _usePhysics=physics;
  bind(this);
}



NS_END


