#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V1)(void *, u32);
typedef u32(THISCALL *V2)(void *, u32, u32);
typedef u32 (*Fmt5)(void *, void *, u32, u32, u32);

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_566f10(void *self);
extern "C" u32 THISCALL ext_5636c0(void *self, u32 a, void *buf);
extern "C" u32 THISCALL ext_4db520(void *node);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *vt(void *o) { return *(u8 **)o; }

// 0x567510: thiscall() with no defined return value, /GS protected, 1 KB of locals: builds two stack strings from exe constants (A = ".../PS2" at 0x6a700c.., B at 0x6a7028..,
// both with a type letter 'B' / 'A' / 'C' patched in for the value 0 / 1 / 2 of 0x566f10(this), none for other values), formats a line into a 1 KB buffer through the
// log object [[0x70039c] slot 0x190]'s cdecl slot 0x198(obj, buf, 0x68dcfc, K slot 0(0x6a6a34, 0x6a7048), K slot 0(0x6a7040, &A)), K = [[[0x70039c]+0x9b]+0xae4], passes the buffer to
// 0x5636c0(this[0x18c], buf), then walks the children of this[0x194] (node [+0x54], next node by 0x4db520): an object whose [[+0xc]+0x23] flags have 0x100000 ends the walk; one
// whose slot 0x1e0(0x20002d) is set gets slot 0x284(0x679e6c) when K slot 0(&B, name) returns the name string itself (equal text), else slot 0x284(that string).
extern "C" void THISCALL fn_567510(u8 *self) {
  u8 loc[0x31];
  __builtin_memcpy(loc, (const void *)0x6a700c, 16);
  loc[0x1a] = *(const u8 *)0x6a7026;
  __builtin_memcpy(loc + 0x2c, (const void *)0x6a7038, 4);
  __builtin_memcpy(loc + 0x10, (const void *)0x6a701c, 8);
  loc[0x30] = *(const u8 *)0x6a703c;
  __builtin_memcpy(loc + 0x1c, (const void *)0x6a7028, 16);
  loc[0x16] = 0x50;
  loc[0x17] = 0x53;
  loc[0x18] = 0x32;
  loc[0x19] = 0;
  u8 *A = loc;
  u8 *B = loc + 0x1c;
  u32 r = ext_566f10(self);
  if (r == 0) {
    loc[0x14] = 0x42;
    loc[0x2c] = 0x42;
  } else if (r == 1) {
    loc[0x14] = 0x41;
    loc[0x2c] = 0x41;
  } else if (r == 2) {
    loc[0x14] = 0x43;
    loc[0x2c] = 0x43;
  }
  u8 buf[0x400];
  u32 s1, s2;
  {
    u8 *T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    void *K = (void *)rd32u(T + 0xae4);
    s1 = (*(V2 *)vt(K))(K, 0x6a7040, (u32)A);
    void *g = G(void *, 0x70039c);
    void *Z = (void *)(*(V0 *)(vt(g) + 0x190))(g);
    u8 *zv = vt(Z);
    T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    K = (void *)rd32u(T + 0xae4);
    s2 = (*(V2 *)vt(K))(K, 0x6a6a34, 0x6a7048);
    (*(Fmt5 *)(zv + 0x198))(Z, buf, 0x68dcfc, s2, s1);
  }
  ext_5636c0(self, rd32u(self + 0x18c), buf);
  u8 *holder = (u8 *)rd32u(self + 0x194);
  if (!holder) goto out;
  {
    u8 *node = (u8 *)rd32u(holder + 0x54);
    while (node) {
      u8 *o = (u8 *)rd32u(node + 0x54);
      u32 flags = o ? rd32u((u8 *)rd32u(o + 0xc) + 0x23) : 0x200002;
      if (flags & 0x100000) goto out;
      if ((u8)(*(V1 *)(vt(o) + 0x1e0))(o, 0x20002d)) {
        const char *s = (const char *)rd32u(o + 4);
        if (!s) s = (const char *)0x67c8e8;
        u8 *Tt = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
        void *K2 = (void *)rd32u(Tt + 0xae4);
        const char *name = (const char *)(*(V2 *)vt(K2))(K2, (u32)B, (u32)s);
        const char *x = name, *y = s;
        bool eq = true;
        for (;;) {
          if (*x != *y) { eq = false; break; }
          if (!*x) break;
          x++;
          y++;
        }
        (*(V1 *)(vt(o) + 0x284))(o, eq ? 0x679e6c : (u32)name);
      }
      node = (u8 *)ext_4db520(node);
    }
  }
out:
  ext_633654(G(u32, 0x6f5630));
}
PCREG(567510, fn_567510);
