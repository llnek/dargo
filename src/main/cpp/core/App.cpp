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

#include "audio/include/SimpleAudioEngine.h"
#include "platform/CCGLView.h"
#include "platform/CCGL.h"
#include "XConfig.h"
#include "CCSX.h"
#include "App.h"

NS_ALIAS(den, CocosDenshion)
NS_ALIAS(cx, fusii::ccsx)
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages() {
  return 0; //flag for packages manager
}

//////////////////////////////////////////////////////////////////////////////
//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void App::initGLContextAttrs() {

  //set OpenGL context attributions,now can only set six attributions:
  //red,green,blue,alpha,depth,stencil
  GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
  c::GLView::setGLContextAttrs(glContextAttrs);

}

//////////////////////////////////////////////////////////////////////////////
//
bool App::applicationDidFinishLaunching() {

  XCFG()->setPlatform(this->getTargetPlatform());
  auto glview = CC_DTOR()->getOpenGLView();
  auto sz = XCFG()->gameSize();

  if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    glview = c::GLViewImpl::createWithRect(_appName, c::Rect(0, 0, sz.width, sz.height));
#else
    glview = c::GLViewImpl::create(_appName);
#endif
    CC_DTOR()->setOpenGLView(glview);
  }

  register_all_packages();
  f::randSeed();

  preLaunch(sz);
  //CCLOG("about to run start scene");
  // run
  CC_DTOR()->runWithScene( XCFG()->prelude());

  return true;
}

//////////////////////////////////////////////////////////////////////////////
//
void App::preLaunch(const CCT_SZ &dz) {

  // device sizes 2733x1536
  // 1495x840 => 0.41667
  // 854x480 => 0.2083333
  auto glview = CC_DTOR()->getOpenGLView();
  auto dispFPS= CC_CSV(c::Bool,"showFPS");
  auto fps = CC_CSV(c::Integer,"FPS");

  auto portrait = XCFG()->isPortrait();
  auto fz = glview->getFrameSize();
  CCT_SZ largeSize;
  CCT_SZ medSize;
  CCT_SZ smallSize;
  float w,h;
  s_vec<sstr> spaths;

  // Set the design resolution
  cx::setDevRes(dz.width, dz.height, XCFG()->policy());

  // FPS. dft is 1.0/60 if you don't call this
  CC_DTOR()->setAnimationInterval(1.0f / fps);

  // turn on display FPS?
  CC_DTOR()->setDisplayStats( dispFPS);

  if (portrait) {
    largeSize = c::Size(1536, 2048);
    medSize = c::Size(768, 1024);
    smallSize = c::Size(320, 480);
  } else {
    largeSize = c::Size(2048, 1536);
    medSize = c::Size(1024, 768);
    smallSize = c::Size(480, 320);
  }

  // if the frame's height is larger than
  // the height of medium size
  if (fz.height > medSize.height) {
    h=largeSize.height;
    w=largeSize.width;
    spaths.push_back("rd");
    spaths.push_back("hd");
    spaths.push_back("sd");
  }
  // if the frame's height is larger than
  // the height of small size.
  else if (fz.height > smallSize.height) {
    h=medSize.height;
    w=medSize.width;
    spaths.push_back("hd");
    spaths.push_back("sd");
    spaths.push_back("rd");
  }
  // if the frame's height is smaller than the height of medium size.
  else {
    h=smallSize.height;
    w=smallSize.width;
    spaths.push_back("sd");
    spaths.push_back("hd");
    spaths.push_back("rd");
  }

  CC_DTOR()->setContentScaleFactor(MIN(h/dz.height, w/dz.width));
  // for win32 add Resources
  spaths.push_back("Resources");
  CC_FILER()->setSearchPaths(spaths);

  XCFG()->setFrameSize(fz);
  XCFG()->runOnce();

  // == design size
  auto wz= CC_DTOR()->getWinSize();
  sstr dbgs;

  F__LOOP(it,spaths) {
    auto &s= *it;
    if (dbgs.length() > 0) { dbgs += " > "; }
    dbgs += s;
  }

  CCLOG("screen size, width=%d, height=%d", (int)fz.width, (int)fz.height);
  CCLOG("win size, width=%d, height=%d", (int)wz.width, (int)wz.height);
  CCLOG("game size, width=%d, height=%d", (int)dz.width, (int)dz.height);

  CCLOG("image search path=%s", dbgs.c_str());

  CCLOG("glview::content scale factor: %f",
      CC_DTOR()->getOpenGLView()->getContentScaleFactor());

  CCLOG("glview::scale x: %f",
      CC_DTOR()->getOpenGLView()->getScaleX());

  CCLOG("glview::scale y: %f",
      CC_DTOR()->getOpenGLView()->getScaleY());

  CCLOG("content scale factor=%f", CC_DTOR()->getContentScaleFactor());
  CCLOG("_scale =%f", XCFG()->getScale());
  //CCLOG("platform os=%s", )


  initAudio();
}

//////////////////////////////////////////////////////////////////////////////
//
void App::initAudio() {
  auto inst= den::SimpleAudioEngine::getInstance();
  auto a = XCFG()->getEffectFiles();

  F__LOOP(it, a) {
    auto &fp = *it;
    CCLOG("preloading sound effect: %s", fp.c_str());
    inst->preloadEffect(fp.c_str());
  }
  a= XCFG()->getMusicFiles();
  F__LOOP(it, a) {
    auto &fp = *it;
    CCLOG("preloading music: %s", fp.c_str());
    inst->preloadBackgroundMusic(fp.c_str());
  }

  inst->setBackgroundMusicVolume(0.5);
  inst->setEffectsVolume(0.5);
}

//////////////////////////////////////////////////////////////////////////////
// This function will be called when the app is inactive
// When comes a phone call,it's be invoked too
void App::applicationDidEnterBackground() {

  CC_DTOR()->stopAnimation();
  den::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//////////////////////////////////////////////////////////////////////////////
// this function will be called when the app is active again
void App::applicationWillEnterForeground() {

  CC_DTOR()->startAnimation();
  den::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}



NS_END



