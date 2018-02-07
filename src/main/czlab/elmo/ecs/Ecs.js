/*Auto generated by Kirby v1.0.0 - Mon Feb 05 2018 02:48:03 GMT-0800 (PST)
  

*/

const K = require("kirby");
const sort_BANG = K["sort_BANG"];
const nichts_QMRK = K["nichts_QMRK"];
const not_DASH_empty = K["not_DASH_empty"];
const objClass = K["objClass"];
const some_QMRK = K["some_QMRK"];
const opt_QMRK__QMRK = K["opt_QMRK__QMRK"];
const conj_BANG = K["conj_BANG"];
const MAX_DASH_INT = K["MAX_DASH_INT"];
const kirbystdlibref = require("kirby");
const __module_namespace__ = "czlab.elmo.ecs.Ecs";
////////////////////////////////////////////////////////////////////////////////
//fn: [system-comparator] in file: Ecs.ky, line: 20
//sort low->high
const system_DASH_comparator = function(x, y) {
  return ((x.priority < y.priority) ?
    -1 :
    ((x.priority > y.priority) ?
      1 :
      0));
};
class EntityPool {
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [constructor] in file: Ecs.ky, line: 28
  constructor(name, engine, entity, batch) {
    (this["name"] = name, this["size"] = 0, this["next"] = 0, this["engine"] = engine, this["inuse"] = 0, this["slots"] = [], this["entity"] = entity, this["batch"] = batch);
    return this;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [take] in file: Ecs.ky, line: 35
  take() {
    let args = Array.prototype.slice.call(arguments, 0);
    if ( (this.next >= this.size) ) {
      this.grow();
    }
    let ent = kirbystdlibref.getProp(this.slots, this.next);
    (ent["status"] = true, ent["slot"] = this.next);
    (this["next"] = (this.next + 1), this["inuse"] = (this.inuse + 1));
    return this.engine.checkin.apply(this.engine, [ent].concat(args));
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [grow] in file: Ecs.ky, line: 49
  grow() {
    for (let x = 0, GS__3 = this.batch, ____break = false; ((!____break) && (x < GS__3)); x = (x + 1)) {
      conj_BANG(this.slots, new this.entity(this.engine));
    }
    return (this["size"] = (this.batch + this.size));
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [countUsed] in file: Ecs.ky, line: 56
  countUsed() {
    return this.inuse;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [poolSize] in file: Ecs.ky, line: 57
  poolSize() {
    return this.size;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [drop] in file: Ecs.ky, line: 59
  drop(ent) {
    return (ent.status ?
      (function() {
        this.engine.checkout(ent);
        (this["next"] = (this.next - 1), this["inuse"] = (this.inuse - 1));
        let tail = kirbystdlibref.getProp(this.slots, this.next);
        let slot_QUOT = kirbystdlibref.getProp(tail, "slot");
        let epos_QUOT = kirbystdlibref.getProp(ent, "slot");
        (this.slots[this.next] = ent, this.slots[epos_QUOT] = tail);
        (
        tail["slot"] = epos_QUOT);
        return (ent["slot"] = slot_QUOT, ent["status"] = false);
      }).call(this) :
      null);
  }
}
class Component {
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [constructor] in file: Ecs.ky, line: 79
  constructor() {
    let GS__4 = Array.prototype.slice.call(arguments, 0);
    let e = GS__4[0];
    (this["tpid"] = "", this["entity"] = opt_QMRK__QMRK(e, null));
    return this;
  }
}
const SystemPriority = (new Map([["PreUpdate", 100], ["NetPlay", 200], ["AI", 300], ["Motion", 400], ["Move", 500], ["Logic", 600], ["Collide", 700], ["Resolve", 800], ["Render", 900], ["Error", -1]]));
var lastId = 0;
////////////////////////////////////////////////////////////////////////////////
//fn: [generateEid] in file: Ecs.ky, line: 100
const generateEid = function(pfx) {
  let rc = ++lastId;
  if ( (!(rc < MAX_DASH_INT)) ) {
    throw new Error("too many entities");
  } else {
    null;
  }
  return [pfx, rc].join("");
};
class Engine {
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [constructor] in file: Ecs.ky, line: 107
  constructor() {
    let GS__5 = Array.prototype.slice.call(arguments, 0);
    let cfg = GS__5[0];
    (this["config"] = opt_QMRK__QMRK(cfg, null), this["updating?"] = false, this["pools"] = [], this["systems"] = [], this["ents"] = (new Map([])), this["types"] = (new Map([])));
    return this;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [checkout] in file: Ecs.ky, line: 114
  checkout(ent) {
    ent.finz();
    kirbystdlibref.dissoc_BANG(this.ents, ent.eid);
    return ent;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [checkin] in file: Ecs.ky, line: 118
  checkin(ent) {
    let args = Array.prototype.slice.call(arguments, 1);
    ent.init.apply(ent, args);
    (kirbystdlibref.assoc_BANG(this.ents, ent.eid, ent));
    return ent;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [unbind] in file: Ecs.ky, line: 122
  unbind(cid, ent) {
    if ( (!(some_QMRK(cid) && some_QMRK(ent))) ) {
      throw Error("Precondition failed");
    } else {
      null;
    }
    let GS__6 = kirbystdlibref.getProp(this.types, cid);
    let m = GS__6;
    if ( (!(((typeof (GS__6) === "undefined")) || ((GS__6 === null)))) ) {
      kirbystdlibref.dissoc_BANG(m, ent.eid);
    }
    return null;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [bind] in file: Ecs.ky, line: 126
  bind(co, ent) {
    if ( (!(some_QMRK(co) && some_QMRK(ent))) ) {
      throw Error("Precondition failed");
    } else {
      null;
    }
    let z = objClass(co);
    let m = kirbystdlibref.getProp(this.types, z);
    if (nichts_QMRK(m)) {
      (
      m = (new Map([])));
      (kirbystdlibref.assoc_BANG(this.types, z, m));
    }
    (kirbystdlibref.assoc_BANG(m, ent.eid, co));
    return null;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [find] in file: Ecs.ky, line: 135
  find() {
    let comTypes = Array.prototype.slice.call(arguments, 0);
    let pmin = MAX_DASH_INT;
    let missed_QMRK = false;
    let pm = null;
    let ccs = [];
    let ret = [];
    let pmks,
      ccsz,
      eid,
      cid,
      c,
      sum;
    for (let i = 0, sz = kirbystdlibref.count(comTypes), ____break = false; ((!____break) && (i < sz)); i = (i + 1)) {
      (cid = comTypes[i], c = kirbystdlibref.getProp(this.types, cid));
      if (nichts_QMRK(c)) {
        (
        missed_QMRK = true);
        (
        ____break = true);
      } else {
        if (true) {
          if ( (kirbystdlibref.count(c) < pmin) ) {
            (pmin = kirbystdlibref.count(c), pm = c);
          }
          conj_BANG(ccs, c);
        }
      }
    }
    (ccsz = kirbystdlibref.count(ccs));
    if ( ((ccsz > 0) && (!missed_QMRK)) ) {
      (
      pmks = Array.from(pm.keys()));
      for (let i = 0, sz = kirbystdlibref.count(pmks), ____break = false; ((!____break) && (i < sz)); i = (i + 1)) {
        (sum = 0, eid = pmks[i]);
        for (let j = 0, ____break = false; ((!____break) && (j < ccsz)); j = (j + 1)) {
          (
          c = ccs[j]);
          if ( (c === pm) ) {
            ++sum;
          } else {
            if (kirbystdlibref.getProp(c, eid)) {
              ++sum;
            }
          }
        }
        if ( (sum === ccsz) ) {
          let GS__7 = kirbystdlibref.getProp(this.ents, eid);
          let e = GS__7;
          if ( (((typeof (GS__7) === "undefined")) || ((GS__7 === null))) ) {
            null;
          } else {
            conj_BANG(ret, e);
          }
        }
      }
    }
    return ret;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [comment] in file: Ecs.ky, line: 169
  comment(addSystem, GS__8, GS__9, GS__10, GS__11, s) {
    let priority = GS__8[0];
    let func = GS__8[1];
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [addSystem] in file: Ecs.ky, line: 175
  addSystem(func) {
    conj_BANG(this.systems, func);
    return func;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [update] in file: Ecs.ky, line: 178
  update(time) {
    (
    this["updating?"] = true);
    try {
      this.systems.forEach(function() {
        let ____args = Array.prototype.slice.call(arguments);
        return ____args[0](this, time);
      });
    } finally {
      (
      this["updating?"] = false);
    }
    return null;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [ignite] in file: Ecs.ky, line: 185
  ignite(prologue) {
    prologue(this);
    this.systems.forEach(function() {
      let ____args = Array.prototype.slice.call(arguments);
      return ____args[0](this, -1);
    });
    return null;
  }
}
class Entity {
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [constructor] in file: Ecs.ky, line: 192
  constructor(engine) {
    let GS__12 = Array.prototype.slice.call(arguments, 1);
    let name = GS__12[0];
    (this["slot"] = -1, this["status"] = true, this["name"] = opt_QMRK__QMRK(name, ""), this["comps"] = (new Map([])), this["engine"] = engine, this["eid"] = generateEid("ent:"));
    return this;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [init] in file: Ecs.ky, line: 201
  init() {
    let args = Array.prototype.slice.call(arguments, 0);
    return (function() {
      throw new Error("you need to override this");
    }).call(this);
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [checkin] in file: Ecs.ky, line: 203
  checkin(co) {
    if ( (!(some_QMRK(co))) ) {
      throw Error("Precondition failed");
    } else {
      null;
    }
    let z = objClass(co);
    if ( (!this.has_QMRK(z)) ) {
      true;
    } else {
      throw new Error("Cannot add co twice");
    }
    this.engine.bind(co, this);
    (
    co["entity"] = this);
    (kirbystdlibref.assoc_BANG(this.comps, z, co));
    return co;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [checkout] in file: Ecs.ky, line: 211
  checkout() {
    let comTypes = Array.prototype.slice.call(arguments, 0);
    let GS__13 = comTypes;
    for (let GS__15 = 0, GS__14 = false, ____break = false; ((!____break) && ((!GS__14) && (GS__15 < GS__13.length))); GS__15 = (GS__15 + 1)) {
      let c = kirbystdlibref.getProp(GS__13, GS__15);
      null;
      if ( (!true) ) {
        (
        GS__14 = true);
      } else {
        null;
      }
      if ( ((!GS__14) && true) ) {
        let GS__16 = kirbystdlibref.getProp(this.comps, c);
        let co = GS__16;
        if ( (!(((typeof (GS__16) === "undefined")) || ((GS__16 === null)))) ) {
          kirbystdlibref.dissoc_BANG(this.comps, c);
          this.engine.unbind(co, this);
        }
      }
    }
    null;
    return null;
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [get] in file: Ecs.ky, line: 217
  get(comType) {
    return kirbystdlibref.getProp(this.comps, comType);
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [getAll] in file: Ecs.ky, line: 218
  getAll() {
    return Array.from(this.comps.values());
  }
  ////////////////////////////////////////////////////////////////////////////////
  //fn: [has?] in file: Ecs.ky, line: 219
  has_QMRK(comType) {
    return some_QMRK(kirbystdlibref.getProp(this.comps, comType));
  }
}
module.exports = {
  da57bc0172fb42438a11e6e8778f36fb: {
    ns: "czlab.elmo.ecs.Ecs",
    macros: {}
  },
  EntityPool: EntityPool,
  Component: Component,
  SystemPriority: SystemPriority,
  Engine: Engine,
  Entity: Entity
};