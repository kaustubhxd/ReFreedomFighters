// batch48000.cpp - cascade tier H, batch 48000: 0x4ed840 (try to add an object from a placement record to a list, with float box test).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(void *ecx, void *edx, void *arg);   // fastcall, 1 stack arg: ecx = edx - arg (3 floats)
extern "C" void FASTCALL ext_43e8e0(void *ecx, void *edx, void *arg);   // fastcall, 1 stack arg: ecx = edx + arg (3 floats)
extern "C" void FASTCALL ext_441a60(void *ecx, void *edx);              // fastcall: transform the vector ecx by the matrix edx
extern "C" void FASTCALL ext_4de4b0(void *ecx, void *edx, void *arg);   // fastcall, 1 stack arg
extern "C" u8 FASTCALL ext_4df330(void *ecx, void *edx, void *a, void *b, void *c, void *d);   // fastcall, 4 stack args, bool
extern "C" void FASTCALL ext_633654(u32 cookie);                        // /GS check

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

static inline double fabs_mask(float f) {
  union { double d; u64 u; } k;
  k.d = (double)f;
  k.u &= G(u64, 0x67cd50);
  return k.d;
}

// 0x4ed840, fastcall(ecx = &base, edx = e), returns bool. r = [e+0x5c] + [ecx]; obj = mgr->slot0x58([r+0x4c]) (mgr = [sys+0x9b]); when obj->slot0x37c() has bit 0 the result is 0.
// When [r] == 0: ext_4df330(e+0x6c, e+0x90, e+0x9c, r+4, r+0x28, r+0x40) must be true. Otherwise v = (e+0x90) - (r+0x28), w = (e+0xa8) + (r+0x40) and every |v[i]| > w[i] (double compare) fails.
// Then when [r+0x50] names an object o = mgr->slot0x54([r+0x50]): v = (e+0x90) - (r+0x28); v = M(r+4) v; m = ext_4de4b0(e+0x6c, r+4); q = [[sys+0x1aa3]+0x18]; q->slot0x20([o+0x6c], &m, &v, e+0x9c) must be true.
// Finally, when the list at [e+0x60] has room ([e+0x64] > [e+0x60] + [e+0x68]*4): obj->slot0x378(1, 0), list[[e+0x68]] = obj, [e+0x68]++, result 1.
static u8 FASTCALL fn4ed840(u8 *base, u8 *e) {
  float v[3], w[3], m[9];
  u8 *r = (u8 *)(rd32(e + 0x5c) + *(u32 *)base);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(sys + 0x9b);
  u8 *obj = vcall<u8 *>(mgr, 0x58, *(u32 *)(r + 0x4c));
  u8 res = 0;
  if (!(vcall<u8>(obj, 0x37c) & 1)) {
    bool ok = true;
    if (*(u32 *)r == 0) {
      ok = ext_4df330(e + 0x6c, e + 0x90, e + 0x9c, r + 4, r + 0x28, r + 0x40) != 0;
    } else {
      ext_43e920(v, e + 0x90, r + 0x28);
      ext_43e8e0(w, e + 0xa8, r + 0x40);
      if (fabs_mask(v[0]) > (double)w[0] || fabs_mask(v[1]) > (double)w[1] || fabs_mask(v[2]) > (double)w[2]) ok = false;
    }
    if (ok) {
      u32 id = *(u32 *)(r + 0x50);
      if (id) {
        u8 *mgr2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
        u8 *o = vcall<u8 *>(mgr2, 0x54, id);
        if (o) {
          ext_43e920(v, e + 0x90, r + 0x28);
          ext_441a60(v, r + 4);
          ext_4de4b0(m, e + 0x6c, r + 4);
          u8 *q = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
          ok = vcall<u8>(q, 0x20, *(u32 *)(o + 0x6c), (u32)m, (u32)v, (u32)(e + 0x9c)) != 0;
        }
      }
      if (ok) {
        u32 cnt = *(u32 *)(e + 0x68);
        u32 *lst = *(u32 **)(e + 0x60);
        if (*(u32 *)(e + 0x64) > (u32)(lst + cnt)) {
          vcall<void>(obj, 0x378, 1u, 0u);
          (*(u32 **)(e + 0x60))[*(u32 *)(e + 0x68)] = (u32)obj;
          res = 1;
          (*(u32 *)(e + 0x68))++;
        }
      }
    }
  }
  ext_633654(0);
  return res;
}
PCREG(4ed840, fn4ed840);
