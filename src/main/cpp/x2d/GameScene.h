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

#define MGMSLIVE() fusii::GameScene::self()->isLive()
#define MGMS() fusii::GameScene::self()
#define MGML() fusii::GameScene::get()
#define SENDMSGEX(t,m) MGMS()->sendMsgEx(t,m)
#define SENDMSG(t) MGMS()->sendMsg(t)
#include "platform/CCCommon.h"
#include "core/Odin.h"
#include "core/JSON.h"
#include "XScene.h"
#include "GameLayer.h"
NS_ALIAS(ws, fusii::odin)
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
enum GMode { ONE = 1, TWO, NET, NICHTS = -1 };

//////////////////////////////////////////////////////////////////////////////
//
struct CC_DLL GCX : public SCTX {
  GCX(GMode m, ws::OdinIO *io) { mode=m; odin=io; }
    virtual ~GCX() { mc_del_ptr(odin) ; }
  GCX(GMode m) { mode=m; }
  GCX() {}
  __decl_ptr(ws::OdinIO ,odin)
  __decl_mv(GMode,mode,GMode::ONE)
};

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL GameScene : public XScene {
protected:

  static void binds(not_null<GameScene*>);

  __decl_map(sstr, f::FPool*, _pools)
  __decl_que(sstr, _msgQ)

  __decl_mv(int, _state, 0)
  __decl_mv(int, _level, 1)
  __decl_nocpyass(GameScene)

public:

  virtual const c::Rect getEnclosureRect();
  virtual const Box4 getEnclosureBox();

  virtual bool isLive() { return _state > 0; }
  virtual void stop() { _state=0; }
  virtual void play() { _state=911; }

  static GameScene* self();
  static GameLayer* get();

  virtual void sendMsgEx(const MsgTopic &topic, void *msg) = 0;
  virtual GameLayer* getGLayer() = 0;

  void sendMsg(const MsgTopic &topic) {
    sendMsgEx(topic, nullptr);
  }

  void reifyPools(const s_vec<sstr> &names);
  f::FPool* reifyPool(const sstr &n);
  f::FPool* getPool(const sstr &n);

  int getLevel() { return _level; }
  ws::OdinIO* wsock();
  GMode getMode();
  bool isOnline();

  c::Dictionary* getCurLevel();
  f::JsonObj* getLCfg();
  void resetPools();

  s_que<sstr>& msgQueue() { return _msgQ; }

  GameScene(bool usePhysics );
  GameScene();
  virtual ~GameScene();
};



NS_END



