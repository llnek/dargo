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

#include "platform/CCCommon.h"
#include "core/Primitives.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL XLives : public c::Node {
protected:

  __decl_vec(c::Sprite*, _icons)
  __decl_md(CCT_SZ, _lifeSize)
  __decl_md(CCT_PT, _refPt)
  __decl_md(sstr, _frameId)

  __decl_nocpyass(XLives)

  __decl_mv(float, _scale, 1)
  __decl_mv(int, _dir, 1)
  __decl_iz(_totalLives)
  __decl_iz(_curLives)

public:

  virtual void initLives(const sstr &frame, int lives,
      float x, float y,
      float scale=1, int dir= 1);

  bool isDead() { return _curLives <= 0; }
  int getLives() { return _curLives; }

  XLives* reduce(int cnt = 1);
  void reset();
  void resurrect();
  void drawLives();

  virtual ~XLives() {}
  XLives() {}
};



NS_END


