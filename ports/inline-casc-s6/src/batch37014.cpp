// batch37014.cpp - cascade s6 batch 37014: 0x4b0620.
#include "ff.h"

extern "C" u32 THISCALL ext_4cc5f0(u8 *s);                   // strlen of the C string whose pointer is at [ecx]
extern "C" u8 *THISCALL ext_4cc1d0(u8 *s);                   // returns [ecx]
extern "C" u8 *THISCALL ext_4dc110(u8 *o);                   // name of an object ("" fallback 0x67c8e8)
extern "C" u8 *THISCALL ext_4dc130(u8 *o);                   // [[o+0x50]+0x54] or 0
extern "C" void THISCALL ext_44b610(u8 *o);
extern "C" void ext_44b740(u8 *o);                            // cdecl
extern "C" u32 THISCALL ext_43ec00(u8 *self, u8 *a, u8 *b, u32 c, u32 d, u32 e, u32 f);   // ret 0x18
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(*cdl_t)(void *, ...);
#define F32(o) (*(u32 *)(self + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static inline u8 *tabCall(u32 slot, u32 id) { void *t = tabObj(); return (u8 *)(*(v1_t **)t)[slot / 4](t, id); }
static inline void *logger(u32 line) {
  u8 *lg = *(u8 **)0x700390;
  return (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x691edc, line);
}

// 0x4b0620, thiscall(a, b) ret 8: resolves the object for this entry (slot 0x94 with the id at +0x58, or slot 0x90 with the name at +0x5c when there is no id),
// then refreshes the handle at +0xde: the old record is shut down (0x44b610, 0x44b740) and, if +0x50 or +0x54 is set, a new handle is made with 0x43ec00 on the
// owner 0x4dc130 returns. When nothing is found it logs which lookup failed (lines 0xa67, 0xa69, 0xa6b).
static void THISCALL fn4b0620(u8 *self, u32 a, u32 b) {
  u8 *esi;
  if (F32(0x58)) {
    esi = (u8 *)(*(v2_t **)self)[0x94 / 4](self, a, F32(0x58));
    if (!esi) esi = tabCall(0x54, F32(0x58));
  } else if (ext_4cc5f0(self + 0x5c)) {
    u8 *s = ext_4cc1d0(self + 0x5c);
    esi = (u8 *)(*(v3_t **)self)[0x90 / 4](self, a, b, (u32)s);
  } else {
    esi = 0;
  }
  if (esi) {
    u8 *h = tabCall(0x60, F32(0xde));
    if (h) {
      ext_44b610(h);
      ext_44b740(h);
    }
    u32 eax = F32(0x50);
    if (!eax) {
      eax = F32(0x54);
      if (!eax) return;
    }
    u8 *own = ext_4dc130(esi);
    F32(0xde) = ext_43ec00(own, esi, esi + 0x24, eax, 0, 0, 0);
    return;
  }
  u8 *v8 = tabCall(0x54, F32(0x58));
  if (v8) {
    void *L = logger(0xa67);
    u8 *nm = ext_4dc110(v8);
    (*(cdl_t **)L)[0x2c / 4](L, 0x692578, nm, F32(0x48));
    return;
  }
  if (ext_4cc5f0(self + 0x5c)) {
    void *L = logger(0xa69);
    u8 *p = ext_4cc1d0(self + 0x5c);
    (*(cdl_t **)L)[0x2c / 4](L, 0x6925c8, p, F32(0x48));
  } else {
    void *L = logger(0xa6b);
    u32 nm = *(u32 *)(F32(0x44) + 4);
    if (!nm) nm = 0x67c8e8;
    (*(cdl_t **)L)[0x2c / 4](L, 0x692618, nm, F32(0x48));
  }
}
PCREG(4b0620, fn4b0620);
