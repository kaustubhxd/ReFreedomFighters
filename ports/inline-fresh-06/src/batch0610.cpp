// batch0610.cpp - fresh-06 batch 10 (docs/20-fresh-06.md). Callee pop counts from tools/rets.py.
#include "ff.h"

extern "C" void *ext_41e290(u32 n);                  // __builtin_new (cdecl)
extern "C" void ext_4690b0(void *p, u32 sz);         // sized pool free (cdecl, GUESS)
static inline void *rmgr() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
typedef void (*hfn)();
static inline void handlerCall() {
  hfn h = G(hfn, 0x7003b0);
  if (!h) asm volatile("int3");
  h();
}

// Serialised-object factories (fastcall: SerialInfo_t& in ECX, OpaqueObjectSerialBuffer_t& in EDX; GUESS from the
// 0x5f9700 constructor's name): a new object is built by the base constructor (si, buf), gets its vtable, runs the
// class's one-time init while the class global is 0, and stores the geom for the id that the serial info's stream
// (+0x15, slot 0x40 into a local) gives (render manager slot 0x58). Returns the object (0 when the allocation fails).
// 0x504660: 0x14 bytes, OpaqueType_t, vtable 0x69c9c0, global 0x700e70, init 0x5044c0, geom at +0xc.
// 0x51ae60: 0x1c bytes, 0x519330, vtable 0x69f364, global 0x701730, init 0x51ace0, geom at +0x18.
// 0x51f320: 0x1c bytes, 0x519330, vtable 0x69fa64, global 0x7018d8, init 0x51f170, geom at +0x18.
typedef void (THISCALL *baseCtor)(void *o, void *si, void *buf);
typedef void (THISCALL *initFn)(void *o);
extern "C" void THISCALL ext_5f9700(void *o, void *si, void *buf);
extern "C" void THISCALL ext_519330(void *o, void *si, void *buf);
extern "C" void THISCALL ext_5044c0(void *o);
extern "C" void THISCALL ext_51ace0(void *o);
extern "C" void THISCALL ext_51f170(void *o);
static inline void *serialMake(u8 *si, void *buf, u32 size, baseCtor ctor, u32 vtab, u32 glob, initFn init, u32 off) {
  u8 *o = (u8 *)ext_41e290(size);
  if (!o) return 0;
  ctor(o, si, buf);
  *(u32 *)o = vtab;
  if (*(u32 *)glob == 0) init(o);
  u32 id;
  vcall<void>(*(void **)(si + 0x15), 0x40, &id);
  *(u32 *)(o + off) = vcall<u32>(rmgr(), 0x58, id);
  return o;
}
static void *FASTCALL serialMake504660(u8 *si, void *buf) {
  return serialMake(si, buf, 0x14, ext_5f9700, 0x69c9c0, 0x700e70, ext_5044c0, 0xc);
}
PCREG(504660, serialMake504660);
static void *FASTCALL serialMake51ae60(u8 *si, void *buf) {
  return serialMake(si, buf, 0x1c, ext_519330, 0x69f364, 0x701730, ext_51ace0, 0x18);
}
PCREG(51ae60, serialMake51ae60);
static void *FASTCALL serialMake51f320(u8 *si, void *buf) {
  return serialMake(si, buf, 0x1c, ext_519330, 0x69fa64, 0x7018d8, ext_51f170, 0x18);
}
PCREG(51f320, serialMake51f320);

// 0x57fc20, CLightToggle deleting destructor: REFTAB32 at +0x48 destroyed, +0x44/+0x30 cleared, base vtable 0x686874,
// unregistered (render manager slot 0x34); flags bit 0: bit 2 -> 0x4690b0(this, 0x126), else the error handler (int3
// when none; not exercised). Returns this.
extern "C" void THISCALL ext_4ccf60(void *t);
static void *THISCALL lightToggleDelDtor(u8 *self, u32 flags) {
  ext_4ccf60(self + 0x48);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  vcall<void>(rmgr(), 0x34, self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x126);
    else handlerCall();
  }
  return self;
}
PCREG(57fc20, lightToggleDelDtor);

// 0x50f060, ZScriptSceneInterface_t::GetOwnerForGeom(OpaqueCallParameters_t&) (stdcall): the geom for the id in
// argument 0 (in array +4, 0x5003d0; render manager slot 0x58). None: result (array +8) element 0 is cleared
// (0x5002f0(.., 0)). Else the geom's (+8) owner (0x4db2f0(true)) goes through render manager slot 0x4c into result
// element 0 with type byte 1; a result whose type byte is above 1 logs an error (0x69c8e0 line 0xc4; sink with
// 0x69c6b0, 0x69c938) and calls the handler (int3 when none; not exercised) instead.
extern "C" void *THISCALL ext_5003d0(void *arr, u32 i);
extern "C" void THISCALL ext_5002f0(void *v, u32 x);
extern "C" void *THISCALL ext_4db2f0(void *g, u32 b);
static void STDCALL scriptGetOwnerForGeom(u8 *p) {
  u32 id = *(u32 *)ext_5003d0(*(void **)(p + 4), 0);
  u8 *g = vcall<u8 *>(rmgr(), 0x58, id);
  if (!g) {
    ext_5002f0(ext_5003d0(*(void **)(p + 8), 0), 0);
    return;
  }
  void *own = ext_4db2f0(*(void **)(g + 8), 1);
  u32 r = vcall<u32>(rmgr(), 0x4c, own);
  u8 *a = (u8 *)ext_5003d0(*(void **)(p + 8), 0);
  if (a[4] > 1) {
    void *sink = vcall<void *>(G(void *, 0x700390), 0x20, 0x69c8e0u, 0xc4u);
    typedef void (*sinkFn)(void *, u32, u32);
    (*(sinkFn *)(*(u8 **)sink + 0x2c))(sink, 0x69c6b0, 0x69c938);
    handlerCall();
    return;
  }
  *(u32 *)a = r;
  a[4] = 1;
}
PCREG(50f060, scriptGetOwnerForGeom);

// 0x4480a0 (no map name; GUESS: geom factory, fastcall: class info in ECX, name in EDX; stack: parent, placement):
// with a placement buffer, 0x447140 (fastcall: placement, parent; stack: class info, name) does it all; else a 0x1c
// object (0x45c4b0) is constructed as a ZGEOM (parent, class info, name), +0x18 cleared, flag 1 at +0x14 when render
// manager byte +0xbad is set, vtable 0x67e300 (0x67dc30 in between). Returns the object (0 when the allocation fails).
extern "C" void *FASTCALL ext_447140(void *p, void *parent, void *ci, const char *nm);
extern "C" void *ext_45c4b0(u32 size);
extern "C" void THISCALL ext_45c3a0(void *o, void *parent, void *ci, const char *nm);
static void *FASTCALL geomFactory4480a0(void *ci, const char *nm, void *parent, void *p) {
  if (p) return ext_447140(p, parent, ci, nm);
  u8 *o = (u8 *)ext_45c4b0(0x1c);
  if (!o) return 0;
  ext_45c3a0(o, parent, ci, nm);
  *(u32 *)o = 0x67dc30;
  *(u32 *)(o + 0x18) = 0;
  if (*((u8 *)rmgr() + 0xbad)) *(u32 *)(o + 0x14) |= 1;
  *(u32 *)o = 0x67e300;
  return o;
}
PCREG(4480a0, geomFactory4480a0);
