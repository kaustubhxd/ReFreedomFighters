// batch37051.cpp - cascade s6 batch 37051: 0x43fc30.
#include "ff.h"

extern "C" void THISCALL ext_4da770(u8 *o, u32 a);      // ret 4
extern "C" void THISCALL ext_4da720(u8 *o, u32 a);      // ret 4
extern "C" void THISCALL ext_4dae60(u8 *o);             // plain ret
extern "C" void THISCALL ext_4dc1a0(u8 *o);             // plain ret
extern "C" u8 *THISCALL ext_4daff0(u8 *o);              // plain ret
extern "C" u8 *THISCALL ext_4db7e0(u8 *o);              // plain ret
extern "C" u32 FASTCALL ext_4daf20(u32 tag, u32 flags); // pure
extern "C" u8 *THISCALL ext_4db520(u8 *o);              // plain ret
extern "C" void THISCALL ext_4dcda0(u8 *o, u32 a);      // ret 4
extern "C" void THISCALL ext_4dcd00(u8 *o, u32 a);      // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v3_t)(void *, u32, u32, u32);
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline u32 tagOf(u8 *p) { return p ? D32(*(u8 **)(p + 0xc), 0x23) : 0x200002; }

// 0x43fc30, thiscall(o, flag) ret 8: detaches the object o from this list owner. Runs 0x4da770 / 0x4da720 / 0x4dae60 for its pending state, 0x4dc1a0 for flagged owners, (when
// flag is 0) informs the owner's helper objects (0x4daff0 / 0x4db7e0 slots 0x2f4 / 0x2fc), asks the table object (slot 0x178) to refresh the owner (slot 0x280) when o is not a
// 0x40000 object, re-links the owner's first-child / count fields (+0x48 via table slot 0x3c for kind 2, +0x50 / +0x54, +0x4c--), unlinks o from its sibling chain (0x4db520, 0x4dcda0,
// 0x4dcd00; +0x60) and notifies slot 0x26c of the owner with the table's slot 0x50 result for objects tagged 0x20001c.
static void THISCALL fn43fc30(u8 *self, u8 *o, u32 flagw) {
  u8 flag = (u8)flagw;
  ext_4da770(o, 0);
  u32 f = D32(o, 0x3c);
  if (!(f & 0x200c00) && (f & 0x40000)) {
    if (D32(o, 0x64) == 0) ext_4da720(o, 0);
    ext_4dae60(o);
  }
  if (D32(*(u8 **)(self + 8), 0x3c) & 0x40040000) ext_4dc1a0(o);
  if (flag == 0) {
    u8 *r = ext_4daff0(*(u8 **)(self + 8));
    if (r) (*(v1_t **)r)[0x2f4 / 4](r, (u32)o);
    u8 *r2 = ext_4db7e0(*(u8 **)(self + 8));
    if (r2) (*(v1_t **)r2)[0x2fc / 4](r2, (u32)o);
  }
  if (!(D32(o, 0x3c) & 0x40000)) {
    void *t = *(void **)(*(u8 **)0x70039c + 0x9b);
    if ((u8)(*(v0_t **)t)[0x178 / 4](t)) (*(v0_t **)self)[0x280 / 4](self);
  }
  u32 k = ext_4daf20(tagOf(*(u8 **)(o + 0x54)), D32(o, 0x3c));
  if (k == 2) {
    void *m = *(void **)(*(u8 **)(*(u8 **)0x70039c + 0x9b) + 8);
    D32(self, 0x48) = (*(v3_t **)m)[0x3c / 4](m, D32(self, 0x48), (u32)o, (u32)o);
  }
  if (ext_4db520(o) != 0) {
    u8 *q = ext_4db520(o);
    D32(q, 0x60) = D32(o, 0x60);
  } else {
    D32(self, 0x50) = D32(o, 0x60);
  }
  if (D32(o, 0x60) != 0) {
    u8 *p = ext_4db520(o);
    ext_4dcda0(*(u8 **)(o + 0x60), (u32)p);
  } else {
    D32(self, 0x54) = (u32)ext_4db520(o);
  }
  D32(o, 0x60) = 0;
  ext_4dcda0(o, 0);
  ext_4dcda0(o, 0);
  D32(o, 0x60) = 0;
  ext_4dcd00(o, 0);
  D32(self, 0x4c)--;
  u8 *e54 = *(u8 **)(o + 0x54);
  if (e54 && tagOf(e54) == 0x20001c) {
    void *vt = *(void **)self;
    u8 *t = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    u32 x = (*(v1_t **)t)[0x50 / 4](t, (u32)o);
    (void)vt;
    (*(v1_t **)self)[0x26c / 4](self, x);
  }
  ext_4dcd00(o, 0);
}
PCREG(43fc30, fn43fc30);
