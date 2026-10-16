// batch822.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
// Reworked by the 11th agent from the machine code (the old port faulted on the uninitialised global 0x70039c; the spec
// now allocates that struct and hooks the callees).
#include "ff.h"

extern "C" u8 *STDCALL ext_64c7e0(u32 idx);                                   // hooked (GUESS): lookup, ret 4
extern "C" void STDCALL ext_64d5f0(u8 *node);                                 // hooked (GUESS): ret 4
extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, void *src, u32 n);  // hooked (GUESS): memmove

typedef u8 *(THISCALL *vt1_t)(u8 *self, u32 n);
typedef void (THISCALL *vt2_t)(u8 *self, void *p, u32 n);

// 0x63d2f0, thiscall(a, b) ret 8: removes the first entry of an object's 8-byte pair array whose key (+4) equals
// [[[0x70039c]+0x1aa3]+0x20] + b, then unlinks matching nodes in the per-listener lists and compacts/reallocs the array.
static void THISCALL removeEntry_63d2f0(u8 *self, u8 *a, u32 b) {
  u32 idx = *(u16 *)(a + 0x5a);
  if (!idx) return;
  u32 off = (idx & 0xfff) << 2;
  u8 *ent = *(u8 **)(*(u8 **)(self + 0x68) + off);
  u32 cnt = ent[0x3d];
  if (cnt <= 1) return;
  u8 *g = G(u8 *, 0x70039c);
  u32 key = *(u32 *)(*(u8 **)(g + 0x1aa3) + 0x20) + b;
  u8 *arr = *(u8 **)(ent + 0x40);
  u32 j = 0;
  u8 *slot = arr;
  for (; j != cnt; j++, slot += 8)
    if (*(u32 *)(slot + 4) == key) break;
  if (j == cnt) return;
  u32 n = *(u32 *)(self + 0xec);
  if (n) {
    u32 i = 0;
    do {
      u8 *c = *(u8 **)(self + 0xf0 + 4 * i);
      u32 f = *(u32 *)(c + 0x10071);
      if (*(u32 *)(off + f) != 0) {
        u8 *r = ext_64c7e0(idx);
        u8 *edi = r + 0x1c;
        if (*(u32 *)edi != 0) {
          for (;;) {
            u8 *s = *(u8 **)edi;
            if (key == *(u32 *)(*(u8 **)(*(u8 **)(s + 8) + 0x10) + 8)) {
              u8 *nd = *(u8 **)(s + 8);
              *(u32 *)(s + 0x14) = 0;
              *(u32 *)(nd + 0x14) &= ~*(u32 *)(c + 0x10059);
              if (s[5] & 1) ext_64d5f0(s);
              *(u32 *)edi = *(u32 *)(s + 0x1c);
              *(u32 *)(s + 0x1c) = 0;
              break;
            }
            if (*(u32 *)(s + 0x1c) == 0) break;
            edi = s + 0x1c;
          }
        }
      }
    } while (++i != n);
  }
  u8 *old = *(u8 **)slot;
  if (old) *(u32 *)(old + 0xc) = 0;
  u8 *last = *(u8 **)(ent + 0x40) + cnt * 8;
  *(u32 *)(slot + 4) = *(u32 *)(last - 4);
  u8 *v = *(u8 **)(last - 8);
  *(u8 **)slot = v;
  if (v) v[8] = (u8)j;
  u32 bytes = cnt << 3;
  u8 *oldarr = *(u8 **)(ent + 0x40);
  u8 *vt = *(u8 **)self;
  u8 *na = (*(vt1_t *)(vt + 0x20))(self, bytes - 8);
  *(u8 **)(ent + 0x40) = na;
  ext_634d22(na, oldarr, bytes - 8);
  (*(vt2_t *)(*(u8 **)self + 0x24))(self, oldarr, bytes);
  ent[0x3d]--;
}
PCREG(63d2f0, removeEntry_63d2f0);
