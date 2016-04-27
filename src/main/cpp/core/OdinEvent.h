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

#include "base/CCEventCustom.h"
#include "JSON.h"
#include "Primitives.h"
NS_BEGIN(fusii)
NS_BEGIN(odin)

//////////////////////////////////////////////////////////////////////////////
//
enum class CC_DLL MType {
  NETWORK = 0,
  SESSION,
  ALL,

  NICHTS = -1
};

//////////////////////////////////////////////////////////////////////////////
//
enum class CC_DLL EType {

  PLAYGAME_REQ = 0,
  JOINGAME_REQ,

  PLAYREQ_NOK,
  JOINREQ_NOK,
  USER_NOK,
  GAME_NOK,
  ROOM_NOK,
  ROOM_FILLED,
  ROOMS_FULL,

  PLAYREQ_OK,
  JOINREQ_OK,

  AWAIT_START,
  SYNC_ARENA,
  POKE_RUMBLE,

  RESTART,
  START,
  STOP,
  POKE_MOVE,
  POKE_WAIT,
  PLAY_MOVE,
  REPLAY,

  QUIT_GAME,

  PLAYER_JOINED,
  STARTED,
  CONNECTED,
  ERROR,
  CLOSED,

  NICHTS = -1
};

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL OdinEvent : public c::EventCustom {

  __decl_mv(MType, _type, MType::NICHTS)
  __decl_mv(EType, _code, EType::NICHTS)
  __decl_md(j::json, _doco)
  __decl_nocpyass(OdinEvent)
  long long _tstamp=0;

public:

  OdinEvent(MType, EType, const j::json &body);
  OdinEvent(MType, EType);
  OdinEvent(const j::json &msg);

  __decl_gsms(j::json&,_doco, Doco)
  __decl_gsms(MType,_type, Type)
  __decl_gsms(EType,_code, Code)

  virtual ~OdinEvent();
  OdinEvent();
};



NS_END
NS_END




