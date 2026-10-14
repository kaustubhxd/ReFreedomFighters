// batch34054.cpp - cascade tier E, batch 34054: 0x5d5c20 (fetch two 9+3-dword blocks through slots), 0x5e0250 (select a mode value and send a command with a vector), 0x62d990 (a callback that
// picks a handler by message code).
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);   // /GS check
typedef u32 (*cb_t)(void *, u32, u32, u32);        // cdecl

// 0x5d5c20, thiscall(a, b) ret 8, returns false: A (9 dwords) and B (3 dwords) locals: this->slot0x80(&A, &B); b->slot0x94(&A, &B); this->slot0xdc(a, b, &A, &B); the /GS check.
static bool THISCALL fn5d5c20(u8 *self, u32 a, u8 *b) {
  u32 A[9];
  u32 B[3];
  vcall<void>(self, 0x80, (u32)A, (u32)B);
  vcall<void>(b, 0x94, (u32)A, (u32)B);
  vcall<void>(self, 0xdc, a, (u32)b, (u32)A, (u32)B);
  ext_633654(0);
  return false;
}
PCREG(5d5c20, fn5d5c20);

// 0x5e0250, thiscall, no args, returns false: o = [this+8]->slot0x504(); mode = [this+0x10], or [this+0xc] when o exists, o->slot0x1e0(0x1007d2) holds and o->slot0x350()->slot0x330() is in 2..7;
// [this+8]->slot0x228(mode, 1, 0, -1.0f, 1.0f) (five stack args); when byte [this+0x14] is set, byte [[this+8]+0x94e] = 1.
static bool THISCALL fn5e0250(u8 *self) {
  u8 *owner = *(u8 **)(self + 8);
  u8 *o = vcall<u8 *>(owner, 0x504);
  u32 mode = *(u32 *)(self + 0x10);
  if (o && vcall<bool>(o, 0x1e0, 0x1007d2u)) {
    u8 *p = vcall<u8 *>(o, 0x350);
    u32 q = vcall<u32>(p, 0x330);
    if (q - 2 <= 5) mode = *(u32 *)(self + 0xc);
  }
  vcall<void>(*(u8 **)(self + 8), 0x228, mode, 1u, 0u, 0xbf800000u, 0x3f800000u);
  if (self[0x14]) (*(u8 **)(self + 8))[0x94e] = 1;
  return false;
}
PCREG(5e0250, fn5e0250);

// 0x62d990, cdecl(a, code, d, e, c): code 0xf -> 0; 0x11 -> [a] = (a[3] ? 0x62dc60 : 0x62dbb0), returns 0xd; 0x12 -> r = c's function pointer at +0x1c called with (c, d, e, 0x6c01c4); a non-zero r sets [a] =
// 0x62da10 and returns 0, a zero r falls through to the default case; otherwise returns 0x34 when a[3] == 0 and code == 0x1c, else [a] = 0x51f230 and returns -1.
static u32 fn62d990(u32 *a, u32 code, u32 d, u32 e, u8 *c) {
  if (code == 0xf) return 0;
  if (code == 0x11) {
    a[0] = a[3] ? 0x62dc60 : 0x62dbb0;
    return 0xd;
  }
  if (code == 0x12) {
    cb_t f = *(cb_t *)(c + 0x1c);
    u32 r = f(c, d, e, 0x6c01c4);
    if (r) {
      a[0] = 0x62da10;
      return 0;
    }
  }
  if (a[3] == 0 && code == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return 0xffffffffu;
}
PCREG(62d990, fn62d990);
