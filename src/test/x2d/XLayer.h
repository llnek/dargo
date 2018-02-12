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

#pragma once
//////////////////////////////////////////////////////////////////////////////

#include "2d/CCLayer.h"
#include "XNode.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
class XScene;
class CC_DLL XLayer : public XNode, public c::Layer {
protected:

  //c::Touch::DispatchMode _tMode= c::Touch::DispatchMode::ALL_AT_ONCE;
  c::Touch::DispatchMode _tMode= c::Touch::DispatchMode::ONE_BY_ONE;
  __decl_ptr(c::EventListenerMouse ,_mouseListener)
  __decl_mv(int, _mouseBtn, MOUSE_BUTTON_LEFT)
  __decl_bf(_mouseEnabled)
  __decl_bf(_mouseTarget)
  __decl_bf(_mouseDown)

  __decl_arr(bool, 256, _keys)
  __decl_nocpyass(XLayer)

  virtual void onTouchesBegan(const VecTouches&, c::Event*);
  virtual void onTouchesMoved(const VecTouches&, c::Event*);
  virtual void onTouchesEnded(const VecTouches&, c::Event*);

  virtual void onKeyReleased(KEYCODE k, c::Event*);
  virtual void onKeyPressed(KEYCODE k, c::Event*);

  virtual void onMouseScroll(c::Event*);
  virtual void onMouseDown(c::Event*);
  virtual void onMouseUp(c::Event*);
  virtual void onMouseMove(c::Event*);

  virtual bool onTouchStart(const VecTouches&);
  virtual void onTouchMotion(const VecTouches&);
  virtual void onTouchEnd(const VecTouches&);

  virtual bool onTouchStart(c::Touch*);
  virtual void onTouchMotion(c::Touch*);
  virtual void onTouchEnd(c::Touch*);

  virtual void onMouseMotion(const CCT_PT&);
  virtual bool onMouseStart(const CCT_PT&);
  virtual void onMouseClick(const CCT_PT&);

  void disableListeners();
  void enableListeners();

  virtual void decoPost() {}
  virtual void decoPre() {}

public:

  bool isMouseEnabled() { return _mouseEnabled; }
  void setMouseEnabled(bool);
  bool keyPoll(KEYCODE);

  virtual bool initEx(XScene*, int zx = 0);
  virtual void decoUI() =0;
  virtual void onInited() {}

  XScene* getSceneX();

  // tag value
  virtual int getIID() { return 1; }
  virtual ~XLayer() {}
  XLayer();

};




NS_END



