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
#include "GameScene.h"
NS_ALIAS(cx, fusii::ccsx)
NS_BEGIN(fusii)

static GameScene *_singleton;

//////////////////////////////////////////////////////////////////////////////
//
GameLayer* GameScene::get() {
  return _singleton->getGLayer();
}

//////////////////////////////////////////////////////////////////////////////
//
GameScene* GameScene::self() {
  return _singleton;
}

//////////////////////////////////////////////////////////////////////////////
//
GameScene::~GameScene() {
  F__LOOP(it, _pools) { delete it->second; }
}
//////////////////////////////////////////////////////////////////////////////
//
GameScene::GameScene() {
  binds(this);
}

//////////////////////////////////////////////////////////////////////////////
//
GameScene::GameScene(bool usePhysics)
  : XScene(usePhysics) {
  binds(this);
}

//////////////////////////////////////////////////////////////////////////////
//
c::Dictionary* GameScene::getCurLevel() {
  return XCFG()->getLevel(s::to_string(_level));
}

//////////////////////////////////////////////////////////////////////////////
//
f::JsonObj* GameScene::getLCfg() {
  return XCFG()->getLevelCfg(s::to_string(_level));
}

//////////////////////////////////////////////////////////////////////////////
//
f::FPool* GameScene::getPool(const sstr &key) {
  auto it = _pools.find(key);
  if (it != _pools.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////////
//
f::FPool* GameScene::reifyPool(const sstr &key) {
  auto p= mc_new1(f::FPool,false);
  auto it = _pools.find(key);
  if (it != _pools.end()) {
    delete it->second;
    _pools.erase(it);
  }
  _pools.insert(S__PAIR(sstr, f::FPool*, key, p));
  return p;
}

//////////////////////////////////////////////////////////////////////////////
//
void GameScene::resetPools() {
  F__LOOP(it, _pools) {
    it->second->clearAll();
  }
}

//////////////////////////////////////////////////////////////////////////
//
void GameScene::binds(not_null<GameScene*> m) {
  _singleton=m;
}

//////////////////////////////////////////////////////////////////////////////
//
ws::OdinIO* GameScene::wsock() {
  return static_cast<GCX*>(_context)->odin;
}

//////////////////////////////////////////////////////////////////////////////
//
GMode GameScene::getMode() {
  return static_cast<GCX*>(_context)->mode;
}

//////////////////////////////////////////////////////////////////////////////
//
bool GameScene::isOnline() {
  return static_cast<GCX*>(_context)->odin != CC_NIL;
}

//////////////////////////////////////////////////////////////////////////////
//
const CCT_RT GameScene::getEnclosureRect() {
  return cx::visRect();
}

//////////////////////////////////////////////////////////////////////////////
const Box4 GameScene::getEnclosureBox() {
  return cx::visBox();
}

//////////////////////////////////////////////////////////////////////////////
//
void GameScene::reifyPools(const s_vec<sstr> &names) {
  F__LOOP(it,names) {
    reifyPool(*it);
  }
}



NS_END


