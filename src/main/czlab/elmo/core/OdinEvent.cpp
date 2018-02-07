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

#include "base/ccUtils.h"
#include "OdinEvent.h"
NS_BEGIN(fusii)
NS_BEGIN(odin)

//////////////////////////////////////////////////////////////////////////////
//
OdinEvent::OdinEvent(MType t, EType c, const j::json &body)
  : OdinEvent() {

  this->_doco = j::json( {
    { "type", (int)t },
    { "code", (int)c }
  });
  this->_type= t;
  this->_code= c;
  if (!body.is_null()) {
    this->_doco["source"] = body;
  }
}

//////////////////////////////////////////////////////////////////////////////
//
OdinEvent::OdinEvent(MType t, EType c) : OdinEvent() {
  _type= t;
  _code= c;
}

//////////////////////////////////////////////////////////////////////////////
//
OdinEvent::OdinEvent(const j::json &full_msg)
  : OdinEvent() {

  if (full_msg.is_object()) {
    auto v= full_msg["type"];
    if (v.is_number()) {
      _type = SCAST(MType, JS_INT(v));
    }
    v= full_msg["code"];
    if (v.is_number()) {
      _code = SCAST(EType, JS_INT(v));
    }
    v= full_msg["source"];
    if (v.is_object()) {
      _doco =v;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////
//
OdinEvent::OdinEvent() : c::EventCustom("odin") {
  _tstamp = c::utils::getTimeInMilliseconds();
  _doco= j::json::object_t();
}

//////////////////////////////////////////////////////////////////////////////
//
OdinEvent::~OdinEvent() {
  CCLOG("OdinEvent::dtor() called");
}


NS_END
NS_END



