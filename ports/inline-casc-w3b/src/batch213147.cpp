#include "ff.h"

extern "C" u32 THISCALL ext_48aad0(void *pair);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline void wrfu(u8 *p, float f) { __builtin_memcpy(p, &f, 4); }

// cdecl vcall of slot `off` of O's vtable; ecx is whatever the caller left in it (here the logger object)
static void vt_cdecl2(void *O, u32 off, u32 a, u32 ecx_in) {
  u32 vtp = *(u32 *)O, fn = *(u32 *)(vtp + off), rc = ecx_in, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $8, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [o] "r"(O)
               : "edx", "memory", "cc");
}

// 0x562750: thiscall(), /GS. Screen set-up: [0x7003b8]+0x2c15 -> this[0x94], this[0x58] = 0x6a6500; looks the named widgets up through this[0x44] slot 0x25c (0x6a650c -> this[0x54],
// positioned at ((h-0x1c0)/2, (w-0x280)/2 as floats, 2.0) via slot 0x70; 0x6a6514 -> this[0x5c], else retried through this[0x44] and placed at (60.0, h-0x3c, 0)); walks the sibling chain
// of this[0x5c] (slot 0x318(2)) pushing two table lookups (slot 0x4c) per sibling into the 8-entry pair array at this+0x98 (count this[0xd8]; overflow logs through [0x700390]);
// then this.0xbc(), this.0x84() widgets 0x6a6524 / 0x6a6530 / 0x6a6534 -> this[0x4c] / this[0x50], this[0x8b] = (h-0x1c0)/2 + 0x7d, and this[0x90] = the table entry named by the
// last character '1'..'4' of this.0x84()'s name (when this[0x94][0x103f] is set) or by the string 0x681320.
extern "C" void THISCALL fn_562750(u8 *self);
static void THISCALL body_562750(u8 *self) {
  u8 *G7 = G(u8 *, 0x7003b8);
  wr32u(self + 0x94, rd32u(G7 + 0x2c15));
  wr32u(self + 0x58, 0x6a6500);
  void *A = (void *)rd32u(self + 0x44);
  u8 *w54 = vcall<u8 *>(A, 0x25c, 0x6a650c, 0);
  wr32u(self + 0x54, (u32)w54);
  if (w54) {
    u8 *E = G(u8 *, 0x70039c);
    int h = (int)rd32u(E + 0x73) - 0x1c0;
    int w = (int)rd32u(E + 0x6f) - 0x280;
    u8 *p = self + 0x78;
    wr32u(p + 8, 0x40000000);
    wrfu(p + 4, (float)(h / 2));
    wrfu(p, (float)(w / 2));
    vcall<void>((void *)rd32u(self + 0x54), 0x70, (u32)p);
  }
  u8 *c54 = (u8 *)rd32u(self + 0x54);
  if (c54) wr32u(self + 0x5c, vcall<u32>(c54, 0x25c, 0x6a6514, 0));
  if (rd32u(self + 0x5c) == 0) {
    void *A2 = (void *)rd32u(self + 0x44);
    u8 *e = vcall<u8 *>(A2, 0x25c, 0x6a6514, 0);
    wr32u(self + 0x5c, (u32)e);
    if (e) {
      u8 *E = G(u8 *, 0x70039c);
      u32 v[3];
      v[0] = 0x42700000;
      float f = (float)((int)rd32u(E + 0x73) - 0x3c);
      __builtin_memcpy(&v[1], &f, 4);
      v[2] = 0;
      vcall<void>(e, 0x70, (u32)v);
    }
  }
  u8 *ebx = (u8 *)rd32u(self + 0x5c);
  while (ebx) {
    if (vcall<u32>(ebx, 0x318, 2) == 0) break;
    if (vcall<u32>(ebx, 0x318, 2) == rd32u(self + 0x5c)) break;
    u8 *E = G(u8 *, 0x70039c);
    u8 *T = (u8 *)rd32u(E + 0x9b);
    u32 q = vcall<u32>(ebx, 0x318, 2);
    u32 r1 = (*(u32(THISCALL **)(void *, u32))(*(u8 **)T + 0x4c))(T, q);
    T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    u32 r2 = (*(u32(THISCALL **)(void *, u32))(*(u8 **)T + 0x4c))(T, (u32)ebx);
    int n = (int)rd32u(self + 0xd8);
    if (n < 8) {
      wr32u(self + 0x98 + n * 8, r2);
      wr32u(self + 0x9c + (int)rd32u(self + 0xd8) * 8, r1);
      wr32u(self + 0xd8, rd32u(self + 0xd8) + 1);
    } else {
      void *L = G(void *, 0x700390);
      void *M = vcall<void *>(L, 0x20, 0x6a64b4, 0xf5);
      vt_cdecl2(M, 0x2c, 0x6a6560, (u32)L);
    }
    ebx = vcall<u8 *>(ebx, 0x318, 2);
  }
  vcall<void>(self, 0xbc);
  void *B = vcall<void *>(self, 0x84);
  u8 *C = vcall<u8 *>(B, 0x25c, 0x6a6524, 0);
  {
    u8 *E = G(u8 *, 0x70039c);
    wr32u(self + 0x8b, (u32)(((int)rd32u(E + 0x73) - 0x1c0) / 2 + 0x7d));
  }
  if (C) {
    wr32u(self + 0x4c, vcall<u32>(C, 0x25c, 0x6a6530, 0));
    wr32u(self + 0x50, vcall<u32>(C, 0x25c, 0x6a6534, 0));
  }
  u8 *s94 = (u8 *)rd32u(self + 0x94);
  if (!s94) return;
  u8 *E = G(u8 *, 0x70039c);
  if (s94[0x103f] != 0) {
    u8 *S = vcall<u8 *>(self, 0x84);
    u32 name = rd32u(S + 4);
    const char *pn = (const char *)(name ? name : 0x67c8e8);
    u32 len = 0;
    while (pn[len]) len++;
    if (len == 0) return;
    u32 k = (u32)((int)(signed char)pn[len - 1] - 0x31);
    if (k > 3) return;
    static const u32 strs[4] = {0x681320, 0x68fcbc, 0x68fccc, 0x68fcdc};
    u8 *T = (u8 *)rd32u(E + 0x9b);
    u32 pair[2];
    pair[0] = vcall<u32>(T, 0x138);
    pair[1] = strs[k];
    T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    u32 id = ext_48aad0(pair);
    T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    wr32u(self + 0x90, vcall<u32>(T, 0x58, id));
  } else {
    u8 *T = (u8 *)rd32u(E + 0x9b);
    void *R = vcall<void *>(T, 0x138);
    u32 out = 0;
    vcall<void>(R, 0x88, 0x681320, (u32)&out);
    T = (u8 *)rd32u(G(u8 *, 0x70039c) + 0x9b);
    wr32u(self + 0x90, vcall<u32>(T, 0x58, out));
  }
}
extern "C" void THISCALL fn_562750(u8 *self) {
  body_562750(self);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(562750, fn_562750);
