// batch2516.cpp - decomp area 24, batch 2516. 0x536c70 (GUESS entity list update), thiscall(A, B), ret 8, no SEH frame.
// Pass 1 empties the embedded list at this+0x5306 (slots 0x4c begin, 0x5c next, 0x44 remove current): for every id the object found
// through slot 0x60 of the object at system+0x9b is released (0x44b610 / 0x44b740 when its kind at +4 is 0xc) and B slot 4 is told
// the id. Pass 2 walks list A the same way: missing or orphaned entities are dropped, flagged ones (+0x40 bit 7) are re-stated from a
// per-slot table at this+0x515d, and live ones get their placement copied (slots 0x84 / 0x88 of the object at system slot 0x58) and a
// timed expiry check using x87-returning slots 0x1e0 / 0x1e4 of this.
#include "ff.h"

extern "C" void THISCALL ext_44b610(void *self);
extern "C" void __attribute__((cdecl)) ext_44b740(void *obj);
extern "C" u8 THISCALL ext_44bc00(void *self);

typedef u32(THISCALL *vf1)(void *, u32);
typedef u32(THISCALL *vf1p)(void *, void *);
typedef float(THISCALL *vf1f)(void *, u32);
typedef void(__attribute__((cdecl)) * vflog)(void *, const void *, u32);
typedef u32(THISCALL *vflg)(void *, const void *, u32);

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])
#define W32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static inline u8 *sysTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL entityUpdate(u8 *self, u8 *A, u8 *B) {
  u8 *T1 = self + 0x5306;
  u32 iter[4];
  u32 el;
  if (T1) {
    VT(T1, vf1p, 0x4c)(T1, iter);
    el = VT(T1, vf1p, 0x5c)(T1, iter);
    if (iter[0] != 0) {
      do {
        u8 *st = sysTable();
        u8 *o = (u8 *)VT(st, vf1, 0x60)(st, el);
        if (o && W32(o, 4) == 0xc) {
          ext_44b610(o);
          ext_44b740(o);
        }
        VT(B, vf1, 4)(B, el);
        VT(T1, vf1p, 0x44)(T1, iter);
        el = VT(T1, vf1p, 0x5c)(T1, iter);
      } while (iter[0] != 0);
    }
  }
  if (!A) return;
  u32 it2[4];
  VT(A, vf1p, 0x4c)(A, it2);
  el = VT(A, vf1p, 0x5c)(A, it2);
  if (it2[0] == 0) return;
  do {
    u8 *st = sysTable();
    u8 *e = (u8 *)VT(st, vf1, 0x60)(st, el);
    if (!e) {
      VT(A, vf1p, 0x44)(A, it2);
      VT(B, vf1, 4)(B, el);
      goto next;
    }
    if (W32(e, 0x3c)) {
      st = sysTable();
      if (!VT(st, vf1, 0x58)(st, W32(e, 0x3c))) {
        VT(A, vf1p, 0x44)(A, it2);
        VT(B, vf1, 4)(B, el);
        ext_44b610(e);
        ext_44b740(e);
        goto next;
      }
    }
    {
      u32 fl = W32(e, 0x40);
      if (fl & 0x40) goto next;
      if (fl & 0x80) {
        u32 k = W32(e, 0x2c);
        W32(e, 0x40) = fl & 0xffffff7fu;
        u8 flag = *(u8 *)(self + k * 9 + 0x515d);
        if (flag != 0) {
          if (W32(e, 4) == 7) W32(e, 4) = 0xa;
        } else if (W32(e, 4) != 7) {
          W32(e, 4) = 7;
          VT(B, vf1, 4)(B, el);
        }
      }
    }
    if (!(ext_44bc00(e) & 0xff)) {
      ext_44b610(e);
      ext_44b740(e);
      VT(B, vf1, 4)(B, el);
      goto next;
    }
    {
      st = sysTable();
      u8 *en = (u8 *)VT(st, vf1, 0x60)(st, el);
      u32 kind = W32(en, 8);
      if (kind != 4 && kind != 5 && kind != 8) {
        st = sysTable();
        u8 *tgt = (u8 *)VT(st, vf1, 0x58)(st, W32(en, 0x3c));
        u32 id0 = W32(en, 0);
        if (id0) {
          st = sysTable();
          u8 *r = (u8 *)VT(st, vf1, 0x58)(st, id0);
          if (r) {
            u8 *c = *(u8 **)(r + 8);
            W32(en, 0x14) = W32(c, 0x24);
            W32(en, 0x18) = W32(c, 0x28);
            W32(en, 0x1c) = W32(c, 0x2c);
            W32(en, 0x20) = W32(c, 0);
            W32(en, 0x24) = W32(c, 4);
            W32(en, 0x28) = W32(c, 8);
          }
        }
        W32(en, 0xd4) = W32(en, 0x14);
        W32(en, 0xd8) = W32(en, 0x18);
        W32(en, 0xdc) = W32(en, 0x1c);
        W32(en, 0xe0) = W32(en, 0x20);
        W32(en, 0xe4) = W32(en, 0x24);
        W32(en, 0xe8) = W32(en, 0x28);
        if (tgt) {
          VT(tgt, vf1, 0x84)(tgt, (u32)(en + 0xd4));
          VT(tgt, vf1, 0x88)(tgt, (u32)(en + 0xe0));
        } else {
          void *lg = G(void *, 0x700390);
          void *lo = (void *)VT(lg, vflg, 0x20)(lg, (const void *)0x6a1e2c, 0x868);
          u32 v = VT(self, vf1, 0x78)(self, W32(en, 0x7c));
          VT(lo, vflog, 0x30)(lo, (const void *)0x6a2380, v);
        }
      }
    }
    {
      u32 a = VT(self, vf1, 0x40)(self, W32(e, 0x7c));
      u32 b = VT(self, vf1, 0x1dc)(self, a);
      (void)VT(self, vf1f, 0x1e0)(self, b);
      if (!(W32(e, 0x40) & 8)) {
        float f78 = *(float *)(e + 0x78);
        int c1 = (int)W32(e, 0x6c) - _mm_cvttss_si32(_mm_set_ss(f78 * G(float, 0x67862c)));
        u8 *sys = G(u8 *, 0x70039c);
        if (!((int)W32(sys, 0x1c) < c1)) {
          float d = *(float *)(e + 0x70) - *(float *)(sys + 0x20);
          float rr = VT(self, vf1f, 0x1e4)(self, W32(e, 0x60));
          float q = d / rr;
          W32(e, 0x60) = 0;
          *(float *)(e + 0x70) = q;
          int c2 = _mm_cvttss_si32(_mm_set_ss(*(float *)(e + 0x78) * G(float, 0x678620)));
          int dl = (int)W32(G(u8 *, 0x70039c), 0x1c) - c2 - (int)W32(e, 0x6c);
          float x1 = (float)dl * G(float, 0x6785e4);
          float x0 = x1 + q;
          if (x1 >= x0) {
            VT(A, vf1p, 0x44)(A, it2);
            u32 old = W32(e, 0x40);
            W32(e, 0x40) = old & 2;
            W32(e, 4) = 3;
            if ((old & 2) != 0 || *(u8 *)(e + 0xec) != 0) {
              ext_44b610(e);
              ext_44b740(e);
            }
            VT(B, vf1, 4)(B, el);
          } else if (W32(e, 4) == 0xb) {
            VT(B, vf1, 4)(B, el);
          }
        }
      }
    }
  next:
    el = VT(A, vf1p, 0x5c)(A, it2);
  } while (it2[0] != 0);
}
PCREG(536c70, entityUpdate);
