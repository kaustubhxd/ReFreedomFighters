// batch1905.cpp - fresh slice 19, batch 1905 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void THISCALL ext_5625c0(u8 *self, u32 id);                 // CBaseWindow::Leave (hooked)
extern "C" void THISCALL ext_4920e0(u8 *self, u8 *before, u8 *e);      // ZTimeUpdateList::LinkBefore (hooked)
extern "C" void THISCALL ext_469870(u8 *self);                         // base event constructor (hooked)
extern "C" u32 THISCALL ext_549780(u8 *self, float v);                 // (no GC name; hooked)
extern "C" s32 THISCALL ext_5496e0(u8 *self, u32 v);                   // (no GC name; hooked)

#define DB (*(u8 **)(*(u8 **)0x70039cu + 0x9b))

// 0x56ce70 CMultiplayerKOTH::Leave(unsigned id) ret 4: when (vt[0x84]() + 0xcb)->vt[0x14]() is 1 and id is 0: byte +0x86 = 1
// and id comes from db vt[0x138]()->vt[0x88](0x6a6c28, &id) (id cleared first); then CBaseWindow::Leave(id).
static void THISCALL leave_56ce70(u8 *self, u32 id) {
  u8 *m = vcall<u8 *>(self, 0x84) + 0xcb;
  if (vcall<u32>(m, 0x14) == 1 && id == 0) {
    self[0x86] = 1;
    u8 *o = vcall<u8 *>(DB, 0x138);
    id = 0;
    vcall<void>(o, 0x88, 0x6a6c28u, (u32)&id);
  }
  ext_5625c0(self, id);
}
PCREG(56ce70, leave_56ce70);

// 0x650f30 ZRender::SetLOD(unsigned lod) ret 4: for each level i below [0x6f5a98], byte (+0x10)[i] = the first c < 8 with
// table[lod][c] >= (float)(i + 1) (table of 8 floats per lod at 0x6c33b8), or 7 when none.
static void THISCALL setLOD_650f30(u8 *self, u32 lod) {
  const float *t = (const float *)(0x6c33b8 + lod * 32);
  for (u32 i = 0; i < G(u32, 0x6f5a98); i++) {
    float v = (float)(double)(i + 1);
    u32 c = 0;
    while (c < 8 && !(t[c] >= v)) c++;
    (*(u8 **)(self + 0x10))[i] = c == 8 ? 7 : (u8)c;
  }
}
PCREG(650f30, setLOD_650f30);

// 0x4947f0 ZTimeUpdateList::SetTime(ZTimeUpdateElement *e, TIMETYPE t) ret 8: e->time (+8) = t; finds the first element d
// from the head (+0xa04, next +0x10) with t < d->time, or t == d->time and e->+4 < d->+4 (signed); unlinks e (prev +0xc,
// next +0x10) and LinkBefore(d, e).
static void THISCALL setTime_4947f0(u8 *self, u8 *e, s32 t) {
  if ((s32 *)(e + 8) != &t) *(s32 *)(e + 8) = t;
  u8 *d = *(u8 **)(self + 0xa04);
  while (d) {
    s32 dt = *(s32 *)(d + 8);
    if (!(t > dt)) {
      if (t != dt) break;
      if (*(s32 *)(e + 4) < *(s32 *)(d + 4)) break;
    }
    d = *(u8 **)(d + 0x10);
  }
  u8 *prev = *(u8 **)(e + 0xc), *next = *(u8 **)(e + 0x10);
  if (prev) *(u8 **)(prev + 0x10) = next;
  else {
    *(u8 **)(self + 0xa04) = next;
    if (next) *(u32 *)(next + 0xc) = 0;
  }
  if (*(u8 **)(e + 0x10)) *(u32 *)(*(u8 **)(e + 0x10) + 0xc) = *(u32 *)(e + 0xc);
  ext_4920e0(self, d, e);
}
PCREG(4947f0, setTime_4947f0);

// Event factories (no GC names): o = (engine db +8)->vt[0x44](incoming ecx as one stack word: GUESS, as 0x57be70); with o:
// base constructor 0x469870, flag 0x20 at +4, +0x44 = 0, vptr. The exe's SEH frame and cookie are not ported.
static inline u8 *make_event(u8 *self, u32 vptr) {
  u8 *o = vcall<u8 *>(*(u8 **)(DB + 8), 0x44, (u32)self);
  if (o) {
    ext_469870(o);
    *(u32 *)(o + 4) |= 0x20;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)o = vptr;
  }
  return o;
}
static u8 *THISCALL make_4b2f70(u8 *self) { return make_event(self, 0x6912e4); }
PCREG(4b2f70, make_4b2f70);
static u8 *THISCALL make_4b31f0(u8 *self) { return make_event(self, 0x6919b0); }
PCREG(4b31f0, make_4b31f0);
static u8 *THISCALL make_4bec30(u8 *self) { return make_event(self, 0x693204); }
PCREG(4bec30, make_4bec30);
static u8 *THISCALL make_5b75b0(u8 *self) { return make_event(self, 0x6b2304); }
PCREG(5b75b0, make_5b75b0);

// 0x578db0 (no GC name) (no args): s = engine vt[0x190](); s slot 0x198 (cdecl: s, buf, fmt 0x6a9adc, +0x194) formats a
// 64-byte stack name; returns the raw flag byte db vt[0x134]()->vt[0x90](buf, &flag) writes (cleared first). Cookie not ported.
typedef void (*fmt_t)(void *, char *, u32, u32);
static u8 THISCALL fn_578db0(u8 *self) {
  char buf[0x40];
  u8 *s = vcall<u8 *>(*(u8 **)0x70039cu, 0x190);
  (*(fmt_t *)(*(u8 **)s + 0x198))(s, buf, 0x6a9adcu, *(u32 *)(self + 0x194));
  u8 *o = vcall<u8 *>(DB, 0x134);
  u8 flag = 0;
  vcall<void>(o, 0x90, (u32)buf, (u32)&flag);
  return flag;
}
PCREG(578db0, fn_578db0);

// 0x60ff30 (no GC name) fastcall (stage, a; b, c) ret 8: sampler-state cache per stage at 0x724868 / 0x724888 / 0x7248a8
// (states 1, 2, 3); a changed value is stored and sent to the device [0x724a00] slot 0xfc (stdcall: dev, stage, state, v).
typedef void(STDCALL *setss_t)(u8 *, u32, u32, u32);
static void FASTCALL setSampler_60ff30(u32 st, u32 a, u32 b, u32 c) {
  u32 v[3] = {a, b, c};
  for (u32 k = 0; k < 3; k++) {
    u32 *slot = (u32 *)(0x724868 + 0x20 * k + st * 4);
    if (*slot == v[k]) continue;
    u8 *dev = G(u8 *, 0x724a00);
    *slot = v[k];
    (*(setss_t *)(*(u8 **)dev + 0xfc))(dev, st, k + 1, v[k]);
  }
}
PCREG(60ff30, setSampler_60ff30);

// 0x54c8f0 (no GC name) (p) ret 4: o = +0x63ec (vtable read first); o slot 0x3c(o, 0x549780(float +0x63d7)) COM style; then
// v = 0x5496e0(p->+0x28) clamped to [100, 100000] goes to (+0x63ec re-read) slot 0x44(o, v).
typedef void(STDCALL *com1_t)(u8 *, u32);
static void THISCALL fn_54c8f0(u8 *self, u8 *p) {
  u8 *o = *(u8 **)(self + 0x63ec);
  u8 *vt = *(u8 **)o;
  u32 r = ext_549780(self, *(float *)(self + 0x63d7));
  (*(com1_t *)(vt + 0x3c))(*(u8 **)(self + 0x63ec), r);
  s32 v = ext_5496e0(self, *(u32 *)(p + 0x28));
  if (v > 100000) v = 100000;
  else if (v < 100) v = 100;
  u8 *o2 = *(u8 **)(self + 0x63ec);
  (*(com1_t *)(*(u8 **)o2 + 0x44))(o2, (u32)v);
}
PCREG(54c8f0, fn_54c8f0);
