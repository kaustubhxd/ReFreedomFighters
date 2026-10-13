// batch13024.cpp - fresh slice 13, batch 24 (docs/20-fresh-13.md), 2026-10-12.
// 0x56d950 CMultiplayerKOTH::UpdatePlayerStatus() (name map high): thiscall, no arguments.
//  - tr = db+0xae4 (text table); t0 = tr->vtbl[0](section 0x6a6760, key 0x6a6758); mask = (*0x7003a0)->vtbl[+0x4c]().
//  - For players 0..3 (bit 1 << i; label widget *(this+0x18c + 4i)):
//    in the mask and byte this+0x19c+i set: s1 = tr(key 0x6a80d0 or 0x6a80d8 by byte this+0x1a0+i), s2 = tr(0x6a80e0),
//      sys->vtbl[+0x190]()->vtbl[+0x198](buf, s2, i + 1, s1) (cdecl printf-like, 5 words), colour 255.0f;
//    in the mask, byte clear: s = tr(0x6a80e8), colour 150.0f, printf(buf, 0x6a80f0, t0, i + 1, s) (6 words);
//    not in the mask: colour 150.0f and the text buffer is passed as it is (stale from an earlier player, or
//      uninitialised stack for the first one - as in the exe).
//    widget->vtbl[+0x284](buf), widget->vtbl[+0x24c](&colour[3]).
// The /GS cookie check is not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

typedef u32(THISCALL *Tr)(void *self, u32 sec, u32 key);
typedef u32(THISCALL *R0)(void *self);
typedef void(THISCALL *PV)(void *self, void *a);
typedef void (*Fmt5)(void *f, char *buf, u32 fmt, u32 a, u32 b);
typedef void (*Fmt6)(void *f, char *buf, u32 fmt, u32 a, u32 b, u32 c);

static inline u8 *tr() { return AT(u8 *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 0xae4); }

static void THISCALL fn56d950(u8 *self) {
  u32 t0 = ((Tr)VT(tr(), 0))(tr(), 0x6a6760, 0x6a6758);
  u8 *mp = G(u8 *, 0x7003a0);
  u32 mask = ((R0)VT(mp, 0x4c))(mp);
  char buf[0x104];
  float col[3];
  u32 bit = 1;
  for (s32 i = 0; i < 4; i++, bit = (bit << 1) | (bit >> 31)) {
    if (mask & bit) {
      if (AT(u8, self, 0x19c + i)) {
        u32 s1 = ((Tr)VT(tr(), 0))(tr(), 0x6a6760, AT(u8, self, 0x1a0 + i) ? 0x6a80d0 : 0x6a80d8);
        u32 s2 = ((Tr)VT(tr(), 0))(tr(), 0x6a6760, 0x6a80e0);
        u8 *s = G(u8 *, 0x70039c);
        u8 *f = (u8 *)((R0)VT(s, 0x190))(s);
        ((Fmt5)VT(f, 0x198))(f, buf, s2, i + 1, s1);
        col[0] = col[1] = col[2] = 255.0f;
      } else {
        u32 t = ((Tr)VT(tr(), 0))(tr(), 0x6a6760, 0x6a80e8);
        col[0] = col[1] = col[2] = 150.0f;
        u8 *s = G(u8 *, 0x70039c);
        u8 *f = (u8 *)((R0)VT(s, 0x190))(s);
        ((Fmt6)VT(f, 0x198))(f, buf, 0x6a80f0, t0, i + 1, t);
      }
    } else {
      col[0] = col[1] = col[2] = 150.0f;
    }
    u8 *w = AT(u8 *, self, 0x18c + 4 * i);
    ((PV)VT(w, 0x284))(w, buf);
    w = AT(u8 *, self, 0x18c + 4 * i);
    ((PV)VT(w, 0x24c))(w, col);
  }
}
PCREG(56d950, fn56d950);
