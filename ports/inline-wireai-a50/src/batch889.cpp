// batch889.cpp - area 50 (residue-09 candidate table row): 0x47aad0 [~40 instr shown; thiscall, two stack args (a value and an
// object), ret 8, void; names map: none]. The list at this+4 holds 8-byte records (object pointer K at +0, value V at +4); the count
// is at this+0x50. If a record has V == a1, and K == a2, the record is removed (the last one moves into its slot). Otherwise, if K
// is not a2, or if there is no record with V == a1, the engine logger prints the names of the two objects through the sink's slot
// +0x2c (cdecl; logs at file 0x68a7c4). The vtable slot +0x20 of an object returns a sub-object whose +4 is a name (or null).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x47aad0 (name GUESS).
static void THISCALL Remove47aad0(u8 *self, u32 a1, u8 *a2) {
  u32 n = U32(self, 0x50);
  u32 i = 0;
  bool found = false;
  for (; i < n; i++) {
    if (U32(self, 4 + 8 * i) == a1) {
      found = true;
      break;
    }
  }
  if (found) {
    u32 *rec = (u32 *)(self + 8 * i);
    if (rec[0] == (u32)a2) {
      n--;
      U32(self, 0x50) = n;
      rec[0] = U32(self, 8 * n);
      rec[1] = U32(self, 8 * n + 4);
      return;
    }
    u8 *sink = (u8 *)vcall<void *>(G(u8 *, 0x700390), 0x20, (void *)0x68a7c4u, 0x50u);
    u8 *X = (u8 *)vcall<void *>((void *)rec[0], 0x20);
    const char *name1 = (const char *)0x67c8e8;
    if (FP(X, 4)) name1 = (const char *)FP(X, 4);
    u8 *Y = (u8 *)vcall<void *>(a2, 0x20);
    const char *name2 = (const char *)0x67c8e8;
    if (FP(Y, 4)) name2 = (const char *)FP(Y, 4);
    typedef void (*printf5_t)(void *, const char *, const char *, u32, const char *);
    (*(printf5_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x68a7f0u, name2, a1, name1);
    return;
  }
  u8 *sink = (u8 *)vcall<void *>(G(u8 *, 0x700390), 0x20, (void *)0x68a7c4u, 0x56u);
  u8 *X = (u8 *)vcall<void *>(a2, 0x20);
  const char *name = (const char *)0x67c8e8;
  if (FP(X, 4)) name = (const char *)FP(X, 4);
  typedef void (*printf4_t)(void *, const char *, const char *, u32);
  (*(printf4_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x68a830u, name, a1);
}
PCREG(47aad0, Remove47aad0);
