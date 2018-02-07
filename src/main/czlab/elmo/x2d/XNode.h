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

#define __decl_get_iid(x) virtual int getIID() { return x; }
#define __decl_update() virtual void update(float);
#define __decl_deco_ui() virtual void decoUI();

#include "2d/CCSpriteBatchNode.h"
#include "platform/CCCommon.h"
#include "core/Primitives.h"
NS_BEGIN(fusii)

//////////////////////////////////////////////////////////////////////////////
//
struct CC_DLL SCTX {
  __decl_mv(int, count,1)
  SCTX() {}
  virtual ~SCTX() {}
};

//////////////////////////////////////////////////////////////////////////////
//
class CC_DLL XNode {
protected:

  virtual c::Menu* addAudioIcons(const s_arr<c::MenuItem*,2>&,
    const CCT_PT &anchor, const CCT_PT &pos);

  virtual c::SpriteBatchNode* regoAtlas(const sstr &name, int zx = 0);
  virtual void bind(c::Node* p) { _self = p; }

  __decl_map(sstr, c::SpriteBatchNode*, _atlases)
  __decl_ptr(c::Node, _self)
  __decl_ptr(SCTX, _context)

  XNode() {}

public:

  virtual void addAtlasFrame(const sstr &atlas, const sstr &n, const CCT_PT &pos, int z, int tag=0);
  virtual void addAtlasFrame(const sstr &atlas, const sstr &n, const CCT_PT &pos);

  virtual void addAtlasItem(const sstr &atlas, not_null<c::Node*> n, int z, int tag=0);
  virtual void addAtlasItem(const sstr &atlas, not_null<c::Node*> n);

  virtual void addFrame(const sstr &n, const CCT_PT &pos, int z, int tag=0);
  virtual void addFrame(const sstr &n, const CCT_PT &pos);

  virtual c::SpriteBatchNode* getAtlas(const sstr &name);

  virtual void addItem(not_null<c::Node*> n, int z, int tag=0);
  virtual void addItem(not_null<c::Node*> n);

  virtual const sstr gets(const sstr&, const s_vec<sstr>&);
  virtual const sstr gets(const sstr&);

  virtual c::Sprite* centerImage(const sstr &n, int z= -1);
  virtual void removeAtlasAll(const sstr &atlas) ;
  virtual void removeItem(c::Node*);
  virtual void removeAll();

  virtual void setCtx(SCTX*, bool clean=true);
  virtual SCTX* getCtx() { return _context; }
  virtual SCTX* ejectCtx();

  virtual ~XNode();
};


NS_END


