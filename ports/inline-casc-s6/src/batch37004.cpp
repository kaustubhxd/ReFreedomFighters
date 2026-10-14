// batch37004.cpp - cascade s6 batch 37004: 0x5c1b60.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);   // ret 4
extern "C" void THISCALL ext_5c1dc0(u8 *self, u32 *arg);   // ret 4
typedef void(THISCALL *s1_t)(void *, void *);
typedef void(THISCALL *s2_t)(void *, void *, u32);
typedef u32(THISCALL *t1_t)(void *, u32);
typedef u32(THISCALL *o1_t)(void *, u32);
typedef u32(THISCALL *o0_t)(void *);

static inline void w32u(u8 *p, u32 v) { for (int i = 0; i < 4; i++) p[i] = (u8)(v >> (8 * i)); }

// 0x5c1b60, thiscall(s) ret 4, returns 1: loads this entry from stream s (slot 0x40 = id, 0x48 = dword, 0x68 = byte, 0x58/0x6c = other
// reads, 0x18 = bytes(ptr, n)). Ids go through the table at [[0x70039c]+0x9b] slot 0x58.
static u32 THISCALL fn5c1b60(u8 *self, void *s) {
  u32 v = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &v);
  ext_5c1dc0(self, &v);
  void **vt = *(void ***)s;
  u32 id;
  u8 b1;
  u32 d;
#define SL(n) (vt[(n) / 4])
#define LOOKUP(dst) do { (*(s1_t)SL(0x40))(s, &id); void *tab = *(void **)(*(u8 **)0x70039c + 0x9b); \
  w32u(dst, (*(t1_t **)tab)[0x58 / 4](tab, id)); } while (0)
  LOOKUP(self + 0xe0);
  (*(s1_t)SL(0x48))(s, self + 0xe8);
  (*(s1_t)SL(0x68))(s, &b1);
  (*(s1_t)SL(0x58))(s, self + 0x100);
  LOOKUP(self + 0x50);
  (*(s1_t)SL(0x68))(s, self + 0x106);
  (*(s1_t)SL(0x48))(s, self + 0x8c);
  (*(s2_t)SL(0x18))(s, self + 0x90, 0x50);
  (*(s1_t)SL(0x6c))(s, self + 0xf4);
  (*(s1_t)SL(0x68))(s, self + 0x104);
  (*(s1_t)SL(0x68))(s, self + 0x107);
  LOOKUP(self + 0x108);
  LOOKUP(self + 0x10d);
  (*(s1_t)SL(0x48))(s, &d);
  *(u32 *)(self + 0x48) = d;
  (*(s1_t)SL(0x48))(s, &d);
  *(u32 *)(self + 0x4c) = d;
  w32u(self + 0xe4, b1 ? 0x6eef78 : 0x6eef68);
  void *o = *(void **)(self + 0x44);
  if ((u8)(*(o1_t **)o)[0x1e0 / 4](o, 0x100001)) {
    w32u(self + 0x10d, *(u32 *)(self + 0x44));
  } else {
    o = *(void **)(self + 0x44);
    w32u(self + 0x10d, (*(o0_t **)o)[0x20 / 4](o));
  }
  return 1;
}
PCREG(5c1b60, fn5c1b60);
