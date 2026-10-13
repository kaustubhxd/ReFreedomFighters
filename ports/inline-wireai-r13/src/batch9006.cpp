// batch9006.cpp (wire-ai thread, 2026-10-13: residue 13 batch1644 with mcpy declared as a function, so it builds for wasm; the logic
// is unchanged and re-verified here on batch1644's spec) - CRagdoll2::GetLinkMatPos_global(long idx, float* p1, float* p2, float* p3, float* p4) const (0x641d90,
// residue 13, 2026-10-12). Entries are 0x30 bytes apart (idx * 48). Copies the entry's first 0x24 bytes into p1 (exe mcpy
// 0x4de420, fixed size), sets p2 to the entry's words at +0x24/+0x28/+0x2c, and, when given, copies p3 from the base
// entry's first three words and p4 from its +0x10/+0x14/+0x18 words. Then passes (p1, p2) to the object's vtable +0x98.
// Returns true. GUESS: the names of the object fields (+0x2e, +0x36) and of the vtable slots (+0x2cc, +0x98) are from the
// code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" void FASTCALL ext_4de420(void *dst, const void *src);  // mcpy: 0x24 bytes, ECX = dst, EDX = src

static u8 THISCALL CRagdoll2_GetLinkMatPos_global(u8 *self, s32 idx, float *p1, float *p2, float *p3, float *p4) {
  u32 off = (u32)idx * 0x30u;
  u8 *obj = AT(u8 *, self, 0x36);
  u8 *base = vcall<u8 *>(obj, 0x2cc);
  u8 *entry = base + off;
  if (p3) {
    p3[0] = AT(float, entry, 0);
    p3[1] = AT(float, entry, 4);
    p3[2] = AT(float, entry, 8);
  }
  if (p4) {
    p4[0] = AT(float, entry, 0x10);
    p4[1] = AT(float, entry, 0x14);
    p4[2] = AT(float, entry, 0x18);
  }
  u8 *src = AT(u8 *, self, 0x2e) + off;
  ext_4de420(p1, src);
  u8 *lk = AT(u8 *, self, 0x2e) + off;
  p2[0] = AT(float, lk, 0x24);
  p2[1] = AT(float, lk, 0x28);
  p2[2] = AT(float, lk, 0x2c);
  vcall<void>(AT(u8 *, self, 0x36), 0x98, p1, p2);
  return 1;
}
PCREG(641d90, CRagdoll2_GetLinkMatPos_global);
