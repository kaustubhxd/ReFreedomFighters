// batch37010.cpp - cascade s6 batch 37010: 0x50cfd0.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u32 self, u32 idx);   // ret 4
extern "C" void THISCALL ext_5002f0(u8 *self, u32 flag); // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void(*cdl_t)(void *, ...);

static void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }
static void *lookup(u32 id) { void *t = tabObj(); return (void *)(*(v1_t **)t)[0x58 / 4](t, id); }
static void *logger(u32 line) {
  u8 *lg = *(u8 **)0x700390;
  return (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69d420, line);
}

// 0x50cfd0, thiscall(a) ret 4: a+4 holds three ids (nodes 0..2) looked up in the object table; a missing one logs an error (0x443 or 0x440); otherwise logs
// the three names, finds the object slot 0x4c of this returns for node 0 and, if its slots 0x504/0x500 equal the third object, calls its slots 0x54c/0x548
// (0, 1), then calls slot 0x2f0 of the third object (node 1 id, name of the second object). Always ends with 0x5002f0 on node 0 of a+8 (flag 1 on success).
static void THISCALL fn50cfd0(u8 *self, u8 *a) {
  void *o0 = lookup(*(u32 *)ext_5003d0(*(u32 *)(a + 4), 0));
  void *o1 = lookup(*(u32 *)ext_5003d0(*(u32 *)(a + 4), 1));
  u32 flag = 0;
  if (!o0 || !o1) {
    void *L = logger(0x443);
    (*(cdl_t **)L)[0x2c / 4](L, 0x69da38);
  } else {
    void *o2 = lookup(*(u32 *)ext_5003d0(*(u32 *)(a + 4), 2));
    if (!o2) {
      void *L = logger(0x440);
      (*(cdl_t **)L)[0x2c / 4](L, 0x69d9fc);
    } else {
      void *L = logger(0x430);
      u8 *r1 = (u8 *)(*(v0_t **)o1)[0x20 / 4](o1);
      u32 n1 = *(u32 *)(r1 + 4);
      u8 *r0 = (u8 *)(*(v0_t **)o0)[0x20 / 4](o0);
      u32 n0 = *(u32 *)(r0 + 4);
      u8 *r2 = (u8 *)(*(v0_t **)o2)[0x2e8 / 4](o2);
      (*(cdl_t **)L)[0x2c / 4](L, 0x69d9e0, *(u32 *)(r2 + 4), n0, n1);
      void *e = (void *)(*(v1_t **)self)[0x4c / 4](self, *(u32 *)ext_5003d0(*(u32 *)(a + 4), 0));
      if (e) {
        if ((*(v0_t **)e)[0x504 / 4](e) == (u32)o2) (*(v2_t **)e)[0x54c / 4](e, 0, 1);
        if ((*(v0_t **)e)[0x500 / 4](e) == (u32)o2) (*(v2_t **)e)[0x548 / 4](e, 0, 1);
      }
      u8 *n = ext_5003d0(*(u32 *)(a + 4), 1);
      u32 r = (*(v1_t **)o1)[0x20 / 4](o1, 1);
      (*(v2_t **)o2)[0x2f0 / 4](o2, *(u32 *)n, r);
      flag = 1;
    }
  }
  ext_5002f0(ext_5003d0(*(u32 *)(a + 8), 0), flag);
}
PCREG(50cfd0, fn50cfd0);
