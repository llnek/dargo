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

#include "core/CCSX.h"
#include "XLayer.h"
#include "XLives.h"
NS_ALIAS(cx, fusii::ccsx)
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
XLives* XLives::reduce(int x) {
  while (x > 0) {
    if (_icons.size() > 0) {
      auto it= _icons.back();
      it->removeFromParent();
      _icons.pop_back();
    }
    --x;
    --_curLives;
  }

  return this;
}

//////////////////////////////////////////////////////////////////////////////
//
void XLives::reset() {
  F__LOOP(it, _icons) { auto n= *it; n->removeFromParent(); }
  _icons.clear();
  _curLives = _totalLives;
}

//////////////////////////////////////////////////////////////////////////////
//
void XLives::resurrect() {
  reset();
  drawLives();
}

//////////////////////////////////////////////////////////////////////////////
//
void XLives::drawLives() {
  float y;
  float x;

  for (auto n = 0; n < _curLives; ++n) {
    auto v= cx::reifySprite(_frameId);
    v->setScale(_scale);
    if (n==0) {
      _lifeSize = cx::scaleSize(CC_CSIZE(v), _scale);
      y= _refPt.y - HHZ(_lifeSize);
      x= _refPt.x + HWZ(_lifeSize);
    }
    v->setPosition(x,y);
    addChild(v);
    _icons.push_back(v);
    if (this->_dir > 0) {
      x += _lifeSize.width * 1.2;
    } else {
      x -= _lifeSize.width * 1.2;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////
//
void XLives::initLives(const sstr &frame, int lives,
    float x, float y, float scale, int d) {

  _totalLives = lives;
  _frameId = frame;
  _curLives = 0;
  _dir = d;
  this->_scale=scale;

  _refPt= CCT_PT(x,y);
  reset();
  drawLives();
}


NS_END


