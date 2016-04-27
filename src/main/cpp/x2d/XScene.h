/*
 * Licensed under the Apache License, Version 2.0 (the "License");
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
 * Copyright (c) Kenneth Leung. All rights reserved.
 */

#pragma once
//////////////////////////////////////////////////////////////////////////////

#include "2d/CCScene.h"
#include "XLayer.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL XScene : public XNode, public c::Scene {

  __decl_nocpyass(XScene)
  __decl_bf(_usePhysics)

public:

  XLayer* addLayer(not_null<XLayer*>, int zx = 0);
  XLayer* getLayer(int tag);

  virtual void decoUI() = 0;
  virtual bool init();
  virtual void onInited() {}

  XScene(bool physics);
  XScene();
  virtual ~XScene();
};



NS_END



