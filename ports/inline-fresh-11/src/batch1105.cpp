// batch1105.cpp - fresh-11 batch 5: slice-11 functions of 119 to 131 bytes. Names from the GC name map; GUESS otherwise.
// SEH frames and /GS cookies are not reproduced (stack and fs:[0] only, restored before return).
#include "ff.h"

static inline u8 *Eng9b() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *PoolAlloc(u32 arg) { return vcall<u8 *>(*(void **)(Eng9b() + 8), 0x44, arg); }
typedef void (*cb_t)();

// GUESS factories: p = ([eng9b+8])->slot +0x44(ECX as passed); when p: base ctor 0x469870, flags +4 |= 0x20,
// +0x44 = 0, vtable (and the extras noted per address); returns p.
extern "C" void THISCALL ext_469870(void *self);
template <u32 VT>
static u8 *THISCALL NewObj(u32 arg) {
  u8 *p = PoolAlloc(arg);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = VT;
  }
  return p;
}
PCREG(5bca30, NewObj<0x6aaf64>);
PCREG(5c5b30, NewObj<0x6b431c>);
PCREG(5c7bb0, NewObj<0x6b47b0>);
PCREG(5d6a70, NewObj<0x6b5ae4>);

// 0x4b2ef0: as above with vtable 0x691590, then +0x50 = 0.
static u8 *THISCALL NewObj4b2ef0(u32 arg) {
  u8 *p = PoolAlloc(arg);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x691590;
    *(u32 *)(p + 0x50) = 0;
  }
  return p;
}
PCREG(4b2ef0, NewObj4b2ef0);

// 0x5bd2f0: as above with vtable 0x6aafec, then REFTAB32::REFTAB32() on +0x4c.
extern "C" void THISCALL ext_4ccba0(void *self);
static u8 *THISCALL NewObj5bd2f0(u32 arg) {
  u8 *p = PoolAlloc(arg);
  if (p) {
    ext_469870(p);
    *(u32 *)(p + 4) |= 0x20;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)p = 0x6aafec;
    ext_4ccba0(p + 0x4c);
  }
  return p;
}
PCREG(5bd2f0, NewObj5bd2f0);

// 0x5659b0 GUESS factory: base ctor 0x564460, vtable 0x6a6b00, +0x180 = 0x6a6c0c, byte +0x87 = 0.
extern "C" void THISCALL ext_564460(void *self);
static u8 *THISCALL NewObj5659b0(u32 arg) {
  u8 *p = PoolAlloc(arg);
  if (p) {
    ext_564460(p);
    *(u32 *)p = 0x6a6b00;
    *(u32 *)(p + 0x180) = 0x6a6c0c;
    p[0x87] = 0;
  }
  return p;
}
PCREG(5659b0, NewObj5659b0);

// 0x60feb0 GUESS set three cached states of stage s (fastcall s, a; stack b, c): types 4/5/6 through device
// [0x724a00] slot +0xfc (COM stdcall (dev, s, type, value)), each only when the cache at 0x7248c8/0x7248e8/0x724908
// [s] differs.
typedef u32(STDCALL *setss_t)(void *, u32, u32, u32);
static void FASTCALL SetStageStates(u32 s, u32 a, u32 b, u32 c) {
  const u32 cache[3] = {0x7248c8, 0x7248e8, 0x724908};
  const u32 v[3] = {a, b, c};
  for (u32 k = 0; k < 3; k++) {
    u32 *slot = (u32 *)(cache[k] + s * 4);
    if (*slot != v[k]) {
      void *d = G(void *, 0x724a00);
      *slot = v[k];
      (*(setss_t *)(*(u8 **)d + 0xfc))(d, s, 4 + k, v[k]);
    }
  }
}
PCREG(60feb0, SetStageStates);

// 0x4c6770 ZPreviewCamera::~ZPreviewCamera() [high] (deleting): body 0x4c65a0; flag 1: flag 4 -> 0x4690b0(this, 0x5f),
// else the [0x7003b0] callback (int3 when null).
extern "C" void THISCALL ext_4c65a0(void *self);
extern "C" void ext_4690b0(void *p, u32 n);
static u8 *THISCALL PreviewCamera_DelDtor(u8 *self, u32 flags) {
  ext_4c65a0(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x5f);
    } else {
      cb_t f = G(cb_t, 0x7003b0);
      if (!f) __builtin_trap();
      f();
    }
  }
  return self;
}
PCREG(4c6770, PreviewCamera_DelDtor);

// 0x63d270 ZDrawBase::CreateView(ZRender*, unsigned int) [high]: slot +0x60(); first free index i (< 0x20) of the table
// +0x6c; v = slot +0x7c(render, i, arg); Init() when byte +5; table[v+0x10055] = v; append v to +0xf0[count +0xec]
// (callback [0x7003b0] when the count would pass 0x20).
extern "C" void THISCALL ext_64c8d0(void *self);
static u8 *THISCALL DrawBase_CreateView(u8 *self, u32 render, u32 arg) {
  vcall<void>(self, 0x60);
  u32 i = 0;
  while (*(u32 *)(self + 0x6c + 4 * i) != 0) {
    i++;
    if (i == 0x20) break;
  }
  u8 *v = vcall<u8 *>(self, 0x7c, render, i, arg);
  if (self[5]) ext_64c8d0(v);
  *(u8 **)(self + 0x6c + 4 * *(u32 *)(v + 0x10055)) = v;
  if (*(u32 *)(self + 0xec) + 1 > 0x20) {
    cb_t f = G(cb_t, 0x7003b0);
    if (!f) __builtin_trap();
    f();
  }
  *(u8 **)(self + 0xf0 + 4 * *(u32 *)(self + 0xec)) = v;
  *(u32 *)(self + 0xec) += 1;
  return v;
}
PCREG(63d270, DrawBase_CreateView);

// 0x48b530 ZTimeUpdateList::AddSort(unsigned int, int) [medium]: when count +0xa0c < capacity +0xa08: element
// e = this + 4 + 20*count {id, prio, +8 = 0}; count++; walk from +0xa04 (next +0x10) past nodes with +8 == 0 and
// prio >= node prio; LinkBefore(node, e); returns e (0 when full).
extern "C" void THISCALL ext_4920e0(void *self, void *before, void *e);
static u32 *THISCALL TimeUpdateList_AddSort(u8 *self, u32 id, s32 prio) {
  u32 n = *(u32 *)(self + 0xa0c);
  if (n >= *(u32 *)(self + 0xa08)) return 0;
  u32 *e = (u32 *)(self + 4 * (5 * n + 1));
  u32 local;
  e[1] = (u32)prio;
  if (&e[2] != &local) e[2] = 0;
  e[0] = id;
  *(u32 *)(self + 0xa0c) += 1;
  u8 *c = *(u8 **)(self + 0xa04);
  while (c && *(u32 *)(c + 8) == 0 && prio >= *(s32 *)(c + 4)) c = *(u8 **)(c + 0x10);
  ext_4920e0(self, c, e);
  return e;
}
PCREG(48b530, TimeUpdateList_AddSort);
