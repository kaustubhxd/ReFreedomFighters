// batch38009.cpp - cascade s8 batch 38009: 0x49c7c0 (flag nodes of a scene tree whose bounds touch the object's).
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(void *s);                          // ctor of a 0x24-byte struct
extern "C" void THISCALL ext_4daf90(u8 *obj, void *out);               // ret 4, writes 0xc bytes
extern "C" void THISCALL ext_4db7c0(u8 *obj, void *out);               // ret 4, writes 0xc bytes
extern "C" void THISCALL ext_4db600(u8 *obj, void *a, void *b);        // ret 8
extern "C" u32 FASTCALL ext_4df330(void *a, void *b, void *c, void *d, void *e, void *f);   // ecx, edx, 4 stack args (callee pops)
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

static inline u32 node_flags(u8 *s) { return s ? *(u32 *)(*(u8 **)(s + 0xc) + 0x23) : 0x200002; }

// 0x49c7c0, stdcall(obj) ret 4. Node flags come from [[s+0xc]+0x23] (s = obj+0x54; 0x200002 when null). Without bit 0x800000: when bit 0x100000 is set every child of s
// (first child at +8, advanced by slot 0x50 through an out parameter) gets bit 0x1000000 in +0x3c, otherwise obj itself does. With 0x800000: walk s and its siblings (slot 0x20)
// until slot 0x1e0(0x100021) accepts one, compute obj's two bounds structs, and flag each child that has a +0x54 and overlaps (0x4df330) the bounds.
static void STDCALL fn49c7c0(u8 *obj) {
  u8 *s = *(u8 **)(obj + 0x54);
  u32 fl = node_flags(s);
  if (!(fl & 0x800000)) {
    if (node_flags(s) & 0x100000) {
      u8 *n = *(u8 **)(s + 8);
      if (!n) return;
      do {
        *(u32 *)(n + 0x3c) = (*(u32 *)(n + 0x3c) & 0xfeffffff) | 0x1000000;
        SLOT(s, 0x50, v1_t)(s, (u32)&n);
      } while (n);
      return;
    }
    *(u32 *)(obj + 0x3c) = (*(u32 *)(obj + 0x3c) & 0xfeffffff) | 0x1000000;
    return;
  }
  while (s) {
    if ((u8)SLOT(s, 0x1e0, v1_t)(s, 0x100021)) goto found;
    s = (u8 *)SLOT(s, 0x20, v0_t)(s);
  }
  return;
found:
  u8 l7c[0x24], l58[0x24], l34[0xc], l28[0xc], l1c[0xc], l10[0xc];
  ext_4de7a0(l7c);
  ext_4daf90(obj, l1c);
  ext_4db7c0(obj, l34);
  ext_4db600(obj, l7c, l1c);
  u8 *n = *(u8 **)(s + 8);
  if (!n) return;
  do {
    if (*(u32 *)(n + 0x54)) {
      ext_4de7a0(l58);
      ext_4daf90(n, l10);
      ext_4db7c0(n, l28);
      ext_4db600(n, l58, l10);
      if ((u8)ext_4df330(l7c, l1c, l34, l58, l10, l28)) *(u32 *)(n + 0x3c) = (*(u32 *)(n + 0x3c) & 0xfeffffff) | 0x1000000;
    }
    SLOT(s, 0x50, v1_t)(s, (u32)&n);
  } while (n);
}
PCREG(49c7c0, fn49c7c0);
