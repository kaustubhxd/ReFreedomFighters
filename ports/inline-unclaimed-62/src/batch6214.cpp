// batch6214.cpp - unclaimed-62 claim 7 (slice 1): unnamed 0x5594d0 [thiscall, ret 4]. b is a record whose +4 and +8 are two vector
// objects. The first element of the +4 vector (idx 0, through the accessor 0x5003d0) is checked (state byte at +4 must be 0 or 1,
// else the debug report and the assert hook); then one of two exe lookups (0x559380 when this->+0x1c->+0x921 is zero, otherwise
// 0x589a10 with that value as its this) fills an object pointer and a flag byte; a non-null pointer is sent to the message table
// (engine +0x9b, slot 0x4c) with its first dword. The +8 vector's element 0 gets the message result and element 1 gets the flag,
// both through the exe setter 0x5002f0. 0x559380 and 0x589a10 are exe code; the spec stubs them by address (GUESS: their bodies are
// not ported here).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *vec, u32 idx);                           // element accessor (ret 4)
extern "C" void THISCALL ext_559380(void *self, u32 a1, u32 *outp, u8 *flag);     // lookup (ret 0xc)
extern "C" void THISCALL ext_589a10(void *self, u32 a1, u32 a2, u32 *outp, u8 *flag); // lookup (ret 0x10)
extern "C" u8 *THISCALL ext_5002f0(u8 *elem, u32 value);                          // element setter: state = 1 (ret 4)

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void bad5594() {
  void *r = vcall<void *>(G(void *, 0x700390), 0x20, (const char *)0x69c8e0, 0x104);
  typedef void (*fn)(void *, const char *, const char *);
  (*(fn *)(*(u8 **)r + 0x2c))(r, (const char *)0x69c6b0, (const char *)0x69c938);
  typedef void (*hookfn)();
  hookfn h = G(hookfn, 0x7003b0);
  if (h) h();
  else __builtin_debugtrap();
}

static void THISCALL fn5594d0(u8 *self, u8 *b) {
  u32 out = 0;                                              // [ebp-8]
  u8 flag = 0;                                              // [ebp+0xb]
  u8 *p = ext_5003d0((void *)rd32u(b + 4), 0);
  if (p[4] != 0 && p[4] != 1) bad5594();
  u32 edi = rd32u(rdp(self + 0x1c) + 0x921);
  if (edi == 0) {
    ext_559380(self, rd32u(p), &out, &flag);
  } else {
    ext_589a10((void *)edi, rd32u(self + 0x1c), 0, &out, &flag);
  }
  u32 r = 0;
  if (out) {
    u8 *msg = rdp(G(u8 *, 0x70039c) + 0x9b);
    r = vcall<u32>(msg, 0x4c, rd32u((const u8 *)out));
  }
  ext_5002f0(ext_5003d0((void *)rd32u(b + 8), 0), r);
  ext_5002f0(ext_5003d0((void *)rd32u(b + 8), 1), flag);
}
PCREG(5594d0, fn5594d0);
