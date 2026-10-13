// batch1203.cpp - fresh slice 12, batch 3. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"
typedef long long s64;

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // sized operator delete
extern "C" void THISCALL ext_63fdd0(u8 *self, u32 a, u32 b);            // ret 8
extern "C" void THISCALL ext_4f21f0(u8 *self, u32 a);                   // ret 4
extern "C" u8 THISCALL ext_613ba0(u8 *self);                            // ret 0, bool in AL
extern "C" u32 THISCALL ext_613a70(u8 *self);                           // ret 0
extern "C" void FASTCALL ext_54f2b0(u32 hr, u32 where);                 // fastcall (ecx, edx), ret 0
extern "C" void THISCALL ext_4cbec0(u8 *self);                          // member destructor, ret 0
extern "C" void THISCALL ext_61ba60(u8 *self);                          // base destructor, ret 0

// 0x7003b0: the engine's failure handler (cdecl, no args). The original executes int3 when it is unset.
typedef u32(__attribute__((cdecl)) * failfn)();
static inline u32 fail_7003b0() {
  failfn f = G(failfn, 0x7003b0);
  if (!f) asm volatile("int3");
  return f();
}

// 0x5f4940: maps x through the range list at +0x96 (lo +0x54, hi +0x58, base +0x48, next +0x9c): returns
// x - lo + base for the first node with lo <= x < hi, else the failure handler's result. ret 4.
static u32 THISCALL mapRange(u8 *self, u32 x) {
  for (u8 *n = *(u8 **)(self + 0x96); n; n = *(u8 **)(n + 0x9c)) {
    if (*(u32 *)(n + 0x54) <= x && *(u32 *)(n + 0x58) > x) return x + (*(u32 *)(n + 0x48) - *(u32 *)(n + 0x54));
  }
  return fail_7003b0();
}
PCREG(5f4940, mapRange);

// 0x63a800: constructor-like init: +0x3400 = 0; word at +0x400 + 12*i = i + 1 for i < 0x3ff, then 0xffff (free list);
// then 0x63fdd0(a, b). Returns this. ret 8.
static u8 *THISCALL initPool(u8 *self, u32 a, u32 b) {
  u8 *e = self + 0x400;
  *(u32 *)(e + 0x3000) = 0;
  for (u32 i = 0; i != 0x3ff; i++, e += 0xc) *(u16 *)e = (u16)(i + 1);
  *(u16 *)e = 0xffff;
  ext_63fdd0(self, a, b);
  return self;
}
PCREG(63a800, initPool);

// 0x5f32c0: appends a u16 to the write cursor at +8 (end at +0xc); calls the failure handler first when it would
// overflow, then writes anyway. ret 4.
static void THISCALL putU16(u8 *self, u16 v) {
  if (*(u32 *)(self + 8) + 2 > *(u32 *)(self + 0xc)) fail_7003b0();
  **(u16 **)(self + 8) = v;
  *(u32 *)(self + 8) += 2;
}
PCREG(5f32c0, putU16);

// 0x563440: once (byte +0x85): +0xdc = 7, +0x64 = engine clock (+0x30, int) * 1/1024 [0x6785e4]; then
// 0x4f21f0(vslot 0x84(), 0). The pushed 0 is 0x4f21f0's argument (ret 4); slot 0x84 takes none.
static void THISCALL startOnce(u8 *self) {
  if (self[0x85]) return;
  self[0x85] = 1;
  u8 *eng = G(u8 *, 0x70039c);
  *(u32 *)(self + 0xdc) = 7;
  *(float *)(self + 0x64) = (float)*(s32 *)(eng + 0x30) * G(float, 0x6785e4);
  ext_4f21f0(vcall<u8 *>(self, 0x84), 0);
}
PCREG(563440, startOnce);

// 0x4b0c00: when (clock(+0x40) - start(+0x50)) * 0x6400 >> 10 (as float, * 1/1024) >= limit (+0x58, int as float),
// calls engine(+0x1a9f)->vslot 0xcc(0).
static void THISCALL timeoutCheck(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  float lim = (float)*(s32 *)(self + 0x58);
  s32 d = *(s32 *)(eng + 0x40) - *(s32 *)(self + 0x50);
  s32 t = (s32)(((s64)d * 0x6400) >> 10);
  float el = (float)t * G(float, 0x6785e4);
  if (el >= lim) vcall<u32>(*(u8 **)(eng + 0x1a9f), 0xcc, 0);
}

PCREG(4b0c00, timeoutCheck);

// 0x4f7ec0: lerp between ints a (+0x8f) and b (+0x93) by t (+0x9f), plus 1/8192 [0x679540], rounded: truncate, then
// +1 when the remainder is > 0.5 [0x67a6ac].
static s32 THISCALL lerpRound(u8 *self) {
  s32 a = *(s32 *)(self + 0x8f);
  s32 d = *(s32 *)(self + 0x93) - a;
  float f = (float)d * *(float *)(self + 0x9f);
  f = f + (float)a;
  f = f + G(float, 0x679540);
  s32 i = _mm_cvttss_si32(_mm_set_ss(f));
  float r = f - (float)i;
  if (r > G(float, 0x67a6ac)) i++;
  return i;
}
PCREG(4f7ec0, lerpRound);

// 0x63b0c0: pops a 64-byte entry from the free list (head word +2, 0xffff = empty, link word at entry+0x10), resets it
// (+0x10 = 0, +0x14 = 0xffff1204, +0x48 = 0, byte +0x4c = 0, word +0x4e = 0), counts it in byte +0, returns entry+0x10.
static u8 *THISCALL allocEntry(u8 *self) {
  u16 idx = *(u16 *)(self + 2);
  if (idx == 0xffff) return 0;
  u8 *e = self + (u32)idx * 64;
  *(u16 *)(self + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x4e) = 0;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1204;
  *(u32 *)(e + 0x48) = 0;
  e[0x4c] = 0;
  self[0]++;
  return e + 0x10;
}
PCREG(63b0c0, allocEntry);

// 0x492200: o->vslot 0xc(3); engine(+0x9b)->vslot 0x138()->vslot 8(o); engine(+0x9b)->vslot 0x134()->vslot 8(o).
// EAX = the last call's result. ret 4.
static u32 THISCALL registerBoth(u8 *, u8 *o) {
  vcall<u32>(o, 0xc, 3);
  u8 *m = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x138);
  vcall<u32>(m, 8, o);
  u8 *m2 = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x134);
  return vcall<u32>(m2, 8, o);
}
PCREG(492200, registerBoth);

// 0x4a8500: serialise: clears flag 0x40 at +4, then reads fields through the stream's slots 0x40/0x44/0x48/0x44/0x40
// into +0x48, +0x4c, +0x4e, +0x52, +0x54. Returns true. ret 4.
static bool THISCALL readFields(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<u32>(s, 0x40, self + 0x48);
  vcall<u32>(s, 0x44, self + 0x4c);
  vcall<u32>(s, 0x48, self + 0x4e);
  vcall<u32>(s, 0x44, self + 0x52);
  vcall<u32>(s, 0x40, self + 0x54);
  return true;
}
PCREG(4a8500, readFields);

// 0x613980: iterator next: walks the ring at +8 (link +8) past nodes whose word +2 is 0xffff, stopping at the start
// node or null; on a live node bumps +0xc and returns 0x613a70(node). Otherwise asks 0x613ba0; false -> 0, true ->
// bump +0xc and return 0x613a70(+8).
static u32 THISCALL iterNext(u8 *self) {
  u8 *start = *(u8 **)(self + 8);
  if (start) {
    for (;;) {
      u8 *n = *(u8 **)(self + 8);
      if (*(u16 *)(n + 2) != 0xffff) {
        (*(u32 *)(self + 0xc))++;
        return ext_613a70(n);
      }
      u8 *nx = *(u8 **)(n + 8);
      *(u8 **)(self + 8) = nx;
      if (nx == start || !nx) break;
    }
  }
  if (!ext_613ba0(self)) return 0;
  (*(u32 *)(self + 0xc))++;
  return ext_613a70(*(u8 **)(self + 8));
}
PCREG(613980, iterNext);

// 0x54c380: byte +0x7a = 1; vslot 0x2c(1); then on the COM-style interface at +0x63ec (stdcall, this on the stack):
// slot 0x34(p, 0) and hr = slot 0x30(p, 0, 0, flag ? 1 : 0); a non-zero hr goes to 0x54f2b0(hr, 0x6a3c20). ret 4.
typedef u32(STDCALL *com2)(u8 *, u32);
typedef u32(STDCALL *com4)(u8 *, u32, u32, u32);
static void THISCALL f54c380(u8 *self, u8 flag) {
  self[0x7a] = 1;
  vcall<u32>(self, 0x2c, 1);
  u8 *p = *(u8 **)(self + 0x63ec);
  (*(com2 *)(*(u8 **)p + 0x34))(p, 0);
  p = *(u8 **)(self + 0x63ec);
  u32 hr = (*(com4 *)(*(u8 **)p + 0x30))(p, 0, 0, flag ? 1 : 0);
  if (hr) ext_54f2b0(hr, 0x6a3c20);
}
PCREG(54c380, f54c380);

// 0x43b7c0: scalar deleting destructor: member dtors 0x4cbec0 on +0x1c3, +0x143, +0xc3, +0x10, base 0x61ba60, sized
// delete 0x24b when bit 0 of flags is set.
static u8 *THISCALL sdd43b7c0(u8 *self, u32 flags) {
  ext_4cbec0(self + 0x1c3);
  ext_4cbec0(self + 0x143);
  ext_4cbec0(self + 0xc3);
  ext_4cbec0(self + 0x10);
  ext_61ba60(self);
  if (flags & 1) ext_634273(self, 0x24b);
  return self;
}
PCREG(43b7c0, sdd43b7c0);

// 0x4b3400: resource lookup by id: id == +0x51 -> *out = this + 0x48; id == +0x53 or +0x55 -> logs message 0x7d / 0x82
// via the log object at 0x700390 (slot 0x20(0x691edc, code) gives a printer whose slot 0x2c is called cdecl
// (printer, 0x691f24)). Always returns 0. ret 8.
typedef void(__attribute__((cdecl)) * printfn)(u8 *, u32);
static u32 THISCALL lookupRes(u8 *self, u16 id, u8 **out) {
  u32 code;
  if (id == *(u16 *)(self + 0x51)) {
    *out = self + 0x48;
    return 0;
  } else if (id == *(u16 *)(self + 0x53)) {
    code = 0x7d;
  } else if (id == *(u16 *)(self + 0x55)) {
    code = 0x82;
  } else {
    return 0;
  }
  u8 *pr = vcall<u8 *>(G(u8 *, 0x700390), 0x20, 0x691edc, code);
  (*(printfn *)(*(u8 **)pr + 0x2c))(pr, 0x691f24);
  return 0;
}
PCREG(4b3400, lookupRes);
