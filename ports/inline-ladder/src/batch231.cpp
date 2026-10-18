// batch231.cpp - ZFFHERO::EmitFootDustParticle (hero vtable slot 0x400) (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void FASTCALL ext_441940(float *dst, const float *src);   // PSVECAdd (x87)
extern "C" void *THISCALL ext_4db3b0(void *geom);                    // ZBaseGeom::GetOwnerRoom
extern "C" void THISCALL ext_581b60(void *coli, float *n);           // COLI hit-triangle normal (no GC name)
extern "C" void FASTCALL ext_4de040(float *m, const float *dir, const float *up);   // createmat
extern "C" void THISCALL ext_4e09b0(float *v);                       // vneg
extern "C" void THISCALL ext_4664a0(void *self, float f);            // ZIKLNKOBJ::EmitFootDustParticle(float) [GC 8017e418, high]

// 0x591480 ZFFHERO::EmitFootDustParticle(float) [GC 80086020, high], thiscall, ret 4 (the float is only passed to the base version).
// Only while running/sprinting flags (0xc000000 of the input word +0x417). The dust emitter: database slot 0x160(0xb6)
// gives a resource whose +0x18 geom ref resolves (slot 0x58) to the emitter; it must have flag 0x100000 at +0x23 of its
// class info (+0xc) (assert). Start point: local (rx, 200, rz) with rx, rz = engine random * 50 - 25 (x87) and rz
// offset -50 when moving (bits 0-1), taken to world (slot 0x84). A ray straight down 200 units (collision manager
// [engine+0x1aa3]+0x1c slot 0x30(coli, 0, start, (0,-200,0), 0, 4, 1, 0)) must hit, inside a room (GetOwnerRoom of
// +8). The hit normal (0x581b60, turned by the hit object's +0x54 slot 0x88) builds a matrix (createmat), whose first
// two rows are swapped and the new first row negated; the room converts it (room slot 0x94(mat, hit point)) and the
// emitter spawns there (emitter slot 0x1bc(room, mat, point, 0, 0, 0, 1)).
// Fix 2026-10-11 (VM restart): when neither flag is set the original calls the base class version
// ZIKLNKOBJ::EmitFootDustParticle(f) (0x5916e5: push the float, call 0x4664a0); the first port just returned.
static void THISCALL heroEmitFootDust(u8 *self, float f) {
  if (!(U32(self, 0x417) & 0xc000000)) {
    ext_4664a0(self, f);
    return;
  }
  u8 *res = vcall<u8 *>((void *)U32(G(u32, 0x70039c), 0x9b), 0x160, 0xb6u);
  if (!res)
    return;
  u8 *em = vcall<u8 *>((void *)U32(G(u32, 0x70039c), 0x9b), 0x58, U32(res, 0x18));
  if (!em)
    return;
  if (!(U32(U32(em, 0xc), 0x23) & 0x100000)) {
    typedef void (*hook_t)();
    hook_t h = G(hook_t, 0x7003b0);
    if (h)
      h();
    else
      __asm__ volatile("int3");
  }
  float off[3];
  U32(off, 0) = 0;
  U32(off, 4) = 0x43480000;
  U32(off, 8) = 0xc2480000;
  if (!(self[0x417] & 3))
    U32(off, 8) = 0;
  float rnd[3];
  long double r1 = vcall<long double>((void *)G(u32, 0x70039c), 0x1c0, (const char *)0x6ac6d0, 0x145eu);
  rnd[0] = (float)(r1 * (long double)50.0f - (long double)25.0f);
  U32(rnd, 4) = 0;
  long double r2 = vcall<long double>((void *)G(u32, 0x70039c), 0x1c0, (const char *)0x6ac6d0, 0x145eu);
  rnd[2] = (float)(r2 * (long double)50.0f - (long double)25.0f);
  ext_441940(off, rnd);
  vcall<void>(self, 0x84, off);
  u8 coli[0x48];
  float dir[3];
  U32(dir, 0) = 0;
  U32(dir, 4) = 0xc3480000;
  U32(dir, 8) = 0;
  U32(coli, 0) = 0x3f800000;
  void *cm = (void *)U32(U32(G(u32, 0x70039c), 0x1aa3), 0x1c);
  if (!(u8)vcall<u32>(cm, 0x30, coli, 0u, off, dir, 0u, 4u, 1u, 0u))
    return;
  void *room = ext_4db3b0((void *)U32(self, 8));
  if (!room)
    return;
  float n[3];
  ext_581b60(coli, n);
  vcall<void>((void *)U32(U32(coli, 0x10), 0x54), 0x88, n);
  float m[9];
  ext_4de040(m, n, 0);
  float a0 = m[0], a1 = m[1], a2 = m[2];
  m[0] = m[3];
  m[1] = m[4];
  m[2] = m[5];
  m[3] = a0;
  m[4] = a1;
  m[5] = a2;
  ext_4e09b0(m);
  float p[3];
  p[0] = F32(coli, 4);
  p[1] = F32(coli, 8);
  p[2] = F32(coli, 0xc);
  vcall<void>(room, 0x94, m, p);
  vcall<void>(em, 0x1bc, room, m, p, 0u, 0u, 0u, 1u);
}
PCREG(591480, heroEmitFootDust);
