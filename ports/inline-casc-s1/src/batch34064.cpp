// batch34064.cpp - cascade tier E, batch 34064: 0x455190 (read a count-first record and forward its ids), 0x48de00 (create or take an overlay object and orient it), 0x4effa0 (fetch two blocks and dispatch).
#include "ff.h"

extern "C" void THISCALL ext_441790(void *self, void *s);   // thiscall ret 4
extern "C" void THISCALL ext_4de7a0(void *m);               // thiscall, plain ret
extern "C" void FASTCALL ext_633654(u32 cookie);            // /GS check

// 0x455190, thiscall(s) ret 4, returns true: 0x441790(this, s); n = [this+0x5c]->slot0x14(); s->slot0x44(n); iterates [this+0x5c] (slot 0x4c begin, slot 0x5c next with a stack iterator) calling s->slot0x64(id)
// for every id.
static bool THISCALL fn455190(u8 *self, u8 *s) {
  u32 it[3];
  ext_441790(self, s);
  u32 n = vcall<u32>(*(u8 **)(self + 0x5c), 0x14);
  vcall<void>(s, 0x44, n);
  u8 *m = *(u8 **)(self + 0x5c);
  if (m) {
    vcall<void>(m, 0x4c, (u32)it);
    u32 id = vcall<u32>(*(u8 **)(self + 0x5c), 0x5c, (u32)it);
    if (it[0] != 0) {
      do {
        vcall<void>(s, 0x64, id);
        id = vcall<u32>(*(u8 **)(self + 0x5c), 0x5c, (u32)it);
      } while (it[0] != 0);
    }
  }
  return true;
}
PCREG(455190, fn455190);

// 0x48de00, stdcall(a), returns the object: when a is null a = [[engine table]+0xadc]->slot0x294(0x68d90c, 0x67d73c, 0, 1); [a+0x48] |= 0x10000; L = {0, 50.0f, -200.0f}; matrix M (9 dwords) from
// 0x4de7a0; a->slot0x74(&M, &L); a->slot0x108(0x68d918, -1); [a+0x4c] = 0x40000000; the /GS check (EAX kept).
static u32 STDCALL fn48de00(u8 *a) {
  u32 M[9];
  u32 L[3];
  if (!a) {
    u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *ow = *(u8 **)(tbl + 0xadc);
    a = vcall<u8 *>(ow, 0x294, 0x68d90cu, 0x67d73cu, 0u, 1u);
  }
  *(u32 *)(a + 0x48) |= 0x10000;
  L[0] = 0;
  L[1] = 0x42480000;
  L[2] = 0xc3480000;
  ext_4de7a0(M);
  vcall<void>(a, 0x74, (u32)M, (u32)L);
  vcall<void>(a, 0x108, 0x68d918u, 0xffffffffu);
  *(u32 *)(a + 0x4c) = 0x40000000;
  ext_633654(0);
  return (u32)a;
}
PCREG(48de00, fn48de00);

// 0x4effa0, thiscall(a, b) ret 8, returns false: A (9 dwords) and B (3 dwords) locals: this->slot0x80(&A, &B); b->slot0x94(&A, &B); this->slot0x224(a, b, &A, &B, byte [this+0x8f]); the /GS check.
static bool THISCALL fn4effa0(u8 *self, u32 a, u8 *b) {
  u32 A[9];
  u32 B[3];
  vcall<void>(self, 0x80, (u32)A, (u32)B);
  vcall<void>(b, 0x94, (u32)A, (u32)B);
  vcall<void>(self, 0x224, a, (u32)b, (u32)A, (u32)B, (u32)self[0x8f]);
  ext_633654(0);
  return false;
}
PCREG(4effa0, fn4effa0);
