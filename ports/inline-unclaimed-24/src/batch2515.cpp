// batch2515.cpp - decomp area 24, batch 2515. 0x4b2470 (GUESS per-element property application), thiscall(arg), ret 4, SEH frame
// (plain C++: the frame pushes EAX after EBX/ESI/EDI, so the callee-saved registers are restored; SEH state writes and the stack cookie
// check (0x633654) are not reproduced). Walks the table at arg+0x18 (reftab slots 0x4c begin, 0x5c next with a valid flag), looks each
// id up through slot 0x54 of the object at system+0x9b, skips entries whose name (0x4dc110) does not compare equal (IAT 0x67625c) to
// the string at 0x692368, asks the object at this+0x44 (slot 0x130) for a record, resolves the target through 0x4b4990 / slot 0x54 /
// 0x4b48c0 and applies the record's fields through the target's slots and 0x4b7f90, with a log line (slot 0x2c of the logger object)
// when the target lacks the 0x200073 property.
#include "ff.h"

extern "C" u32 THISCALL ext_4dc110(void *self);
extern "C" u32 THISCALL ext_4b4990(void *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_4b48c0(void *self, u32 a);
extern "C" void THISCALL ext_4b7f90(void *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_4cc1d0(void *self);
extern "C" void THISCALL ext_4cbec0(void *self);
extern "C" u8 THISCALL ext_4db9a0(void *self, u32 flags);
extern "C" u32 FASTCALL ext_4cc7f0(u32 a, u32 b);
extern "C" void THISCALL ext_4b7940(void *self, u32 a);

typedef s32(__attribute__((cdecl)) * cmp_t)(const void *, const void *);
typedef u32(THISCALL *vf1)(void *, u32);
typedef u32(THISCALL *vf1p)(void *, void *);
typedef u32(THISCALL *vf2)(void *, u32, u32);
typedef u32(THISCALL *vf3)(void *, u32, u32, void *);
typedef u32(THISCALL *vf3b)(void *, u32, u32, u32);
typedef u32(THISCALL *vf4)(void *, u32, u32, float, float);
typedef void(__attribute__((cdecl)) * vflog)(void *, const void *, u32, u32);
typedef u32(THISCALL *vflg)(void *, const void *, u32);

#define VT(o, T, off) ((*(T **)(o))[(off) / 4])

static inline u8 *sysTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

static void THISCALL propApply(u8 *self, u8 *arg) {
  u32 flags = 0;
  u8 *tbl = *(u8 **)(arg + 0x18);
  if (!tbl) return;
  u32 iter[4];
  VT(tbl, vf1p, 0x4c)(tbl, iter);
  u32 el = VT(tbl, vf1p, 0x5c)(tbl, iter);
  if (iter[0] == 0) return;
  do {
    u8 *st = sysTable();
    u8 *edi = (u8 *)VT(st, vf1, 0x54)(st, el);
    if (edi) {
      const void *s = (const void *)ext_4dc110(edi);
      if (G(cmp_t, 0x67625c)(s, (const void *)0x692368) == 0) {
        u32 loc[2];
        loc[0] = ext_4dc110(edi);
        loc[1] = 0;
        u8 *o44 = *(u8 **)(self + 0x44);
        VT(o44, vf3, 0x130)(o44, (u32)arg, *(u16 *)(self + 0x58), loc);
        u8 *b = (u8 *)loc[1];
        u32 nm = ext_4dc110(edi);
        u32 x118 = ext_4b4990(self, nm, (u32)tbl, (u32)b);
        if (x118) {
          st = sysTable();
          u8 *tg = (u8 *)VT(st, vf1, 0x54)(st, x118);   // edi from here on
          u8 *esi = 0;
          if (b) {
            esi = (u8 *)ext_4b48c0(self, *(u32 *)(tg + 0x54));
            if (b[4]) ext_4b7f90(self, x118, *(u32 *)(b + 5));
            if (*(u32 *)(b + 9) != 0) {
              const void *r124;
              bool skipLog = false;
              u32 loc110[8];
              if (esi) {
                if (VT(esi, vf1, 0x1e0)(esi, 0x200073) & 0xff) {
                  st = sysTable();
                  u8 *o = (u8 *)VT(st, vf1, 0x58)(st, *(u32 *)(b + 9));
                  u8 *q = *(u8 **)(tg + 0x50);
                  u32 r = VT(o, vf2, 0x2c4)(o, *(u32 *)(q + 0x54), 0x4954454d);
                  VT(esi, vf2, 0x54c)(esi, r, 0);
                  skipLog = true;
                } else {
                  u8 *o = (u8 *)VT(esi, vf2, 0x1d8)(esi, (u32)loc110, 1);
                  flags |= 1;
                  r124 = (const void *)ext_4cc1d0(o);
                }
              } else {
                r124 = (const void *)0x685178;
              }
              if (!skipLog) {
                void *lg = G(void *, 0x700390);
                void *lo = (void *)VT(lg, vflg, 0x20)(lg, (const void *)0x691edc, 0x520);
                u8 *t44 = *(u8 **)(self + 0x44);
                u32 loc90[8];
                u8 *o2 = (u8 *)VT(t44, vf2, 0x1d8)(t44, (u32)loc90, 1);
                u32 cs = ext_4cc1d0(o2);
                VT(lo, vflog, 0x2c)(lo, (const void *)0x692378, cs, (u32)r124);
                ext_4cbec0(loc90);
                if (flags & 1) {
                  flags &= ~1u;
                  ext_4cbec0(loc110);
                }
              }
            }
            if (b[0x1d] && esi) {
              if (b[0x1a]) {
                VT(esi, vf4, 0x224)(esi, *(u32 *)(b + 0xd), 0x11, *(float *)(b + 0x11), *(float *)(b + 0x15));
              } else {
                VT(esi, vf2, 0x22c)(esi, *(u32 *)(b + 0xd), 0x11);
              }
              VT(esi, vf1, 0x32c)(esi, 1);
            }
            if (b[0x1a]) {
              u8 *x = *(u8 **)(tg + 0x54);
              if (x) VT(x, vf3b, 0x128)(x, *(u16 *)(self + 0x5a), (u32)_mm_cvttss_si32(_mm_load_ss((float *)(b + 0x11))), 0);
              x = *(u8 **)(tg + 0x54);
              if (x) VT(x, vf3b, 0x128)(x, *(u16 *)(self + 0x5c), (u32)_mm_cvttss_si32(_mm_load_ss((float *)(b + 0x15))), 0);
              x = *(u8 **)(tg + 0x54);
              if (x) VT(x, vf3b, 0x128)(x, *(u16 *)(self + 0x5e), 0, 0);
            }
          }
          u8 *fin = tg;
          if (ext_4db9a0(tg, 0x100001)) {
            u32 nm2 = ext_4dc110(tg);
            if (ext_4cc7f0(nm2, 0x6923c8)) {
              u8 *pp = *(u8 **)(tg + 0x54);
              u8 *ch = *(u8 **)(pp + 0x50);
              while (ch) {
                if (ext_4db9a0(ch, 0x400003)) {
                  st = sysTable();
                  x118 = VT(st, vf1, 0x50)(st, (u32)ch);
                  fin = ch;
                  break;
                }
                ch = *(u8 **)(ch + 0x60);
              }
            }
          }
          if (ext_4db9a0(fin, 0x400003)) ext_4b7940(self, x118);
        }
      }
    }
    el = VT(tbl, vf1p, 0x5c)(tbl, iter);
  } while (iter[0] != 0);
}
PCREG(4b2470, propApply);
