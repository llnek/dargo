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
//
#include "platform/CCApplication.h"
#include "platform/CCCommon.h"
#include "Primitives.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL App : public cocos2d::Application {
protected:

  void preLaunch(const CCT_SZ &designSize);
  void initAudio();

  __decl_md(sstr, _appName)
  __decl_nocpyass(App)

public:

  /**
  @brief    Implement Director and Scene init code here.
  @return true    Initialize success, app continue.
  @return false   Initialize failed, app terminate.
  */
  virtual bool applicationDidFinishLaunching();

  /**
  @brief  The function be called when the application enter background
  @param  the pointer of the application
  */
  virtual void applicationDidEnterBackground();

  /**
  @brief  The function be called when the application enter foreground
  @param  the pointer of the application
  */
  virtual void applicationWillEnterForeground();

  virtual void initGLContextAttrs();

  App(const sstr &n) { _appName=n; }
  virtual ~App() {}

};



NS_END




