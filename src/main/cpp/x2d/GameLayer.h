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

#include "base/CCEventKeyboard.h"
#include "ecs/Engine.h"
#include "XLayer.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL GameLayer : public XLayer {
protected:

  __decl_ptr(ecs::Engine, _engine)
  __decl_nocpyass(GameLayer)

  virtual void update(float);
  virtual void surcease();

  virtual void decoPost();
  virtual void decoPre();

public:

  virtual ~GameLayer();
  GameLayer();
};




NS_END


