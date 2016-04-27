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

#include "base/CCEventListenerKeyboard.h"
#include "base/CCEventListenerMouse.h"
#include "base/CCEventListenerTouch.h"
#include "core/XConfig.h"
#include "core/CCSX.h"
#include "GameScene.h"
#include "GameLayer.h"

NS_ALIAS(cx, fusii::ccsx)
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
GameLayer::~GameLayer() {
    mc_del_ptr(_engine);
}

//////////////////////////////////////////////////////////////////////////////
//
GameLayer::GameLayer() {
}

//////////////////////////////////////////////////////////////////////////////
//
void GameLayer::decoPost() {
  if (N_NIL(_engine)) {
    _engine->ignite();
  }
  scheduleUpdate();
}

//////////////////////////////////////////////////////////////////////////////
//
void GameLayer::decoPre() {
  cx::resumeAudio();
  enableListeners();
}

//////////////////////////////////////////////////////////////////////////////
//
void GameLayer::surcease() {
  disableListeners();
  cx::pauseAudio();
  unscheduleUpdate();
}

//////////////////////////////////////////////////////////////////////////
//
void GameLayer::update(float dt) {
  if (!cx::isTransitioning() &&
      MGMS()->isLive() &&
      N_NIL(_engine)) {
    _engine->update(dt);
  }
}



NS_END



