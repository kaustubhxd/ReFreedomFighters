#include "ff.h"

extern "C" void *ext_634d10(void *dst, int val, u32 n);
extern "C" void THISCALL ext_565190(void *self, char *buf, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_563710(void *self, u32 ent, u32 str);
extern "C" void THISCALL ext_4db500(void *self, void *out);
extern "C" void THISCALL ext_5618b0(void *self, u32 a, u32 b);
extern "C" void THISCALL ext_565240(void *self, char *buf, u32 flag, u32 lines);
extern "C" void THISCALL ext_565760(void *self, u32 v);
extern "C" void FASTCALL ext_633654(u32 cookie);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline u8 *vt(void *o) { return *(u8 **)o; }

#define EBP (fr + 0x1040)
#define P(off) (EBP - (off))

// cdecl vcall (ecx = the vtable) with the formatter's 5 pushed arguments (obj, out, fmt, a, b)
static void cd5(void *o, u32 off, u32 out, u32 fmt, u32 a, u32 b) {
  u32 vtp = *(u32 *)o, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  u32 w[5] = {(u32)o, out, fmt, a, b};
  asm volatile("pushl 16(%[w])\n\tpushl 12(%[w])\n\tpushl 8(%[w])\n\tpushl 4(%[w])\n\tpushl (%[w])\n\tcall *%%eax\n\taddl $20, %%esp"
               : "+a"(ra), "+c"(rc)
               : [w] "r"(w)
               : "edx", "memory", "cc");
}
static u32 slen(const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  return n;
}

// 0x565360: thiscall(args) ret 4, /GS (4 KB frame, __chkstk), void. Two text buffers (0x565190) from the argument record; the three entities this[0xc6a..0xc72] get their
// text (table slot 0 -> 0x563710), chained with entity slot 0x31c, and the longest line count is kept; then 0x4db500 / entity slot 0x70 position the third entity, the
// helper object (this slot 0x84, slot 0x2ec) re-parents the entities (this[0x44]) via 0x5618b0, the two buffers are merged with the engine formatter (engine slot
// 0x190 -> 0x198, fmt 0x6a6a44) or copied, and 0x565240 / 0x565760 are called with the merged text, a flag (any of the three optional ids set) and the line count.
// The frame keeps the original layout (the flag dword at -0x1018 still holds the high bytes of the entity cursor).
static void body_565360(u8 *edi, u8 *arg) {
  u8 fr[0x1048];
  { void *d = fr; u32 n = sizeof fr; asm volatile("rep stosb" : "+D"(d), "+c"(n) : "a"(0xcc) : "memory"); }
  W32(P(0x1020), (u32)arg);
  W32(P(0x1030), (u32)edi);
  ext_634d10(P(0x404), 0, 0x400);
  ext_634d10(P(0x804), 0, 0x400);
  ext_634d10(P(0x1004), 0, 0x800);
  ext_565190(edi, (char *)P(0x404), R32(arg), R32(arg + 0x14), R32(arg + 0x18));
  ext_565190(edi, (char *)P(0x804), R32(arg + 4), R32(arg + 0x1c), R32(arg + 0x20));
  vcall<u32>(edi, 0xfc, 1u);
  if (slen(P(0x404)) == 0) return;
  *P(0x1012) = 0;
  u8 *ebx = edi + 0xc6a;
  u8 *cur = arg + 8;
  W32(P(0x1024), 1);
  *(u16 *)P(0x1014) = 0;
  W32(P(0x101c), 0);
  W32(P(0x1018), (u32)ebx);
  W32(P(0x1028), (u32)cur);
  W32(P(0x1034), (u32)cur);
  u32 esi = 0;
  do {
    u32 id = R32((u8 *)R32(P(0x1034)));
    if (id == 0) {
      vcall<u32>((u8 *)R32(ebx), 0xbc, 1u);
    } else {
      u8 *T = (u8 *)R32(G(u8 *, 0x70039c) + 0x9b);
      u8 *Z = (u8 *)R32(T + 0xae4);
      u32 str = vcall<u32>(Z, 0, 0x6a6a34u, id);
      W32(P(0x102c), str);
      ext_563710(edi, R32(ebx), str);
      vcall<u32>((u8 *)R32(ebx), 0xbc, 0u);
      P(0x1014)[esi] = 1;
      u32 len = slen((const u8 *)str);
      u32 lines = 1;
      for (u32 k = 0; (s32)k < (s32)len; k++)
        if (((u8 *)str)[k] == 0xa) lines++;
      if ((s32)lines > (s32)R32(P(0x1024))) W32(P(0x1024), lines);
    }
    if (esi != 0 && P(0x1014)[esi] != 0) {
      if (P(0x1015)[esi] != 0) {
        vcall<u32>((u8 *)R32(ebx - 4), 0x31c, R32(ebx), 2u);
        vcall<u32>((u8 *)R32(ebx), 0x31c, R32(ebx - 4), 1u);
      } else {
        vcall<u32>((u8 *)R32(ebx), 0x31c, 0u, 1u);
      }
      vcall<u32>((u8 *)R32(ebx), 0x31c, 0u, 2u);
    }
    esi++;
    cur += 4;
    W32(P(0x1034), (u32)cur);
    W32(P(0x101c), esi);
    ebx += 4;
    W32(P(0x1018), (u32)ebx);
  } while ((s32)esi < 3);
  u8 *e0 = (u8 *)R32(edi + 0xc6a);
  ext_4db500((u8 *)R32(e0 + 8), P(0x1010));
  vcall<u32>((u8 *)R32(edi + 0xc72), 0x70, (u32)P(0x1010));
  for (u32 k = 0; k < 3; k++) {
    u8 *ob = vcall<u8 *>(edi, 0x84);
    vcall<u32>(ob, 0x2ec, R32(edi + 0xc6a + 4 * k));
  }
  {
    u8 *ob = vcall<u8 *>(edi, 0x84);
    vcall<u32>(ob, 0x2ec, R32(edi + 0x44));
  }
  ext_5618b0(edi, R32(edi + 0xc6a), R32(edi + 0xc6e));
  if (R32((u8 *)R32(P(0x1028))) == 0) {
    u8 *ob = vcall<u8 *>(edi, 0x84);
    if (R32(arg + 0x10) != 0) vcall<u32>(ob, 0x2ec, R32(edi + 0xc72));
    else vcall<u32>(ob, 0x2ec, R32(edi + 0x44));
  } else {
    u8 *ob = vcall<u8 *>(edi, 0x84);
    vcall<u32>(ob, 0x2ec, R32(edi + 0xc6a));
    ext_5618b0(edi, R32(edi + 0xc6e), R32(edi + 0xc72));
  }
  if (slen(P(0x804)) != 0) {
    u8 *E = G(u8 *, 0x70039c);
    u8 *N = vcall<u8 *>(E, 0x190);
    cd5(N, 0x198, (u32)P(0x1004), 0x6a6a44u, (u32)P(0x404), (u32)P(0x804));
  } else {
    u32 k = 0;
    u8 al;
    do {
      al = P(0x404)[k];
      k++;
      *(P(0x1005) + k) = al;
    } while (al != 0);
  }
  u8 *an = (u8 *)R32(P(0x1028));
  if (R32(an) != 0 || R32(arg + 0xc) != 0 || R32(arg + 0x10) != 0) *P(0x1018) = 1;
  else *P(0x1018) = 0;
  ext_565240(edi, (char *)P(0x1004), R32(P(0x1018)), R32(P(0x1024)));
  float f = RF(arg + 0x24) * G(float, 0x67862c);
  s32 iv = (s32)f;
  s32 d = (s32)R32(G(u8 *, 0x70039c) + 0x30) - iv;
  WF(edi + 0xca6, (float)d * G(float, 0x6785e4));
  W32(edi + 0xcaa, R32(arg + 0x24));
  ext_565760(edi, arg[0x28]);
}
extern "C" void THISCALL fn_565360(u8 *self, u8 *arg);
extern "C" void THISCALL fn_565360(u8 *self, u8 *arg) {
  body_565360(self, arg);
  ext_633654(G(u32, 0x6f5630));
}
PCREG(565360, fn_565360);
