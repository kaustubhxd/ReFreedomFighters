// batch37031.cpp - cascade s6 batch 37031: 0x548f40.
#include "ff.h"

extern "C" void THISCALL ext_4db860(u8 *self, u32 flag);   // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v4_t)(void *, u32, u32, u32, u32);
#define F32(o) (*(u32 *)(self + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *look(u32 id) { void *t = tabObj(); return (u8 *)(*(v1_t **)t)[0x58 / 4](t, id); }
static inline u32 id16(u32 name, u32 line) {
  void *t = tabObj();
  return (u16)(*(v4_t **)t)[0x114 / 4](t, name, 0, 0x6a3208, line);
}

// 0x548f40, thiscall(a) ret 4: two table objects (ids at this+0x4c / +0x50) each own a list (slot 0xbc resets, node at +8, slot 0x50 advances). For the first, three
// 16-bit ids are looked up (strings 0x6a2cdc / 0x6a2d10 / 0x682e18); every node is reset with 0x4db860(0) and its object at +0x54 is told slot 0x128 with the second id,
// then with the first id and a+0x28 when a is given, else with the third id. The second object's nodes are only reset. Ends with slot 0x28 of the object at this+0x44.
static void THISCALL fn548f40(u8 *self, u8 *a) {
  u8 *A = look(F32(0x4c));
  u8 *B = look(F32(0x50));
  if (A) {
    u32 i1 = id16(0x6a2cdc, 0xab);
    u32 i2 = id16(0x6a2d10, 0xac);
    u32 i3 = id16(0x682e18, 0xad);
    (*(v1_t **)A)[0xbc / 4](A, 0);
    u8 *n = *(u8 **)(A + 8);
    if (n) {
      do {
        ext_4db860(n, 0);
        u8 *e = *(u8 **)(n + 0x54);
        if (e) (*(v3_t **)e)[0x128 / 4](e, i2, 0, 0);
        e = *(u8 **)(n + 0x54);
        if (a) {
          if (e) (*(v3_t **)e)[0x128 / 4](e, i1, *(u32 *)a + 0x28, 0);
        } else {
          if (e) (*(v3_t **)e)[0x128 / 4](e, i3, 0, 0);
        }
        u32 var = (u32)n;
        (*(v1_t **)A)[0x50 / 4](A, (u32)&var);
        n = (u8 *)var;
      } while (n);
    }
  }
  if (B) {
    (*(v1_t **)B)[0xbc / 4](B, 0);
    u8 *n = *(u8 **)(B + 8);
    if (n) {
      do {
        ext_4db860(n, 0);
        u32 var = (u32)n;
        (*(v1_t **)B)[0x50 / 4](B, (u32)&var);
        n = (u8 *)var;
      } while (n);
    }
  }
  void *o = *(void **)(self + 0x44);
  (*(v0_t **)o)[0x28 / 4](o);
}
PCREG(548f40, fn548f40);
