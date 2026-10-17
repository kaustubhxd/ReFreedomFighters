#include "ff.h"

extern "C" const char *THISCALL ext_4dc110(void *node);
extern "C" int FASTCALL ext_4cc850(const char *name, const char *cmp);
extern "C" void THISCALL ext_516b60(void *entry, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_516f40(void *entry, void *vec);
extern "C" void FASTCALL ext_633654(u32 cookie);

typedef u32(THISCALL *V3)(void *, u32, u32, u32);

static inline u32 R32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline float RF(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }
static inline void WF(u8 *p, float v) { __builtin_memcpy(p, &v, 4); }
static inline double absd(double d) {
  u64 b;
  __builtin_memcpy(&b, &d, 8);
  b &= 0x7fffffffffffffffull;
  __builtin_memcpy(&d, &b, 8);
  return d;
}
static inline float cf(u32 addr) { return *(const float *)addr; }

// cdecl vcall of slot `off` of M's vtable with ecx = the vtable pointer, args (fmt, a)
static void vt_log2(void *M, u32 off, u32 fmt, u32 a) {
  u32 vtp = *(u32 *)M, fn = *(u32 *)(vtp + off), rc = vtp, ra = fn;
  asm volatile("pushl %[a]\n\tpushl %[f]\n\tpushl %[o]\n\tcall *%%eax\n\taddl $12, %%esp"
               : "+a"(ra), "+c"(rc)
               : [a] "r"(a), [f] "r"(fmt), [o] "r"(M)
               : "edx", "memory", "cc");
}

// 0x5257a0: thiscall(arg) ret 4 -> bool, /GS. Walks the child list of this[0x88] ([+0x50], next [+0x60]); each child's name (0x4dc110) is matched against nine constant names:
// four "type A" names call slot 0 of the embedded sub-object at this+0x7ad / 0x910 / 0xa73 / 0xbd6 (this[0x88], child[0x54], 1) and count successes in this[0x8c]; four "type B" names
// (0xd39 / 0xe6c / 0xf9f / 0x10d2) call the same and always count in this[0x90]; the ninth appends an effect record (0x79 bytes at this+0x1205 + n * 0x79, n = this[0x12f7]).
// Afterwards counts of 2 or 4 combine this[0x7d1] / this[0xa97] / this[0xd5d] / this[0xfc3] into this[0xa0] / this[0xa4]; other counts log an assert (lines 0x221 / 0x22d) and return false;
// finally this[0xa8], [0xac], [0xb0], [0xb4], [0xb8] are derived (|differences|, [0x67da20], [0x67a6ac]) and true is returned.
static bool body_5257a0(u8 *self, u32 arg) {
  W32(self + 0x8c, 0);
  W32(self + 0x90, 0);
  W32(self + 0x12f7, 0);
  u8 *root = (u8 *)R32(self + 0x88);
  u8 *node = (u8 *)R32(root + 0x50);
  static const u32 names[9] = {0x6a0878, 0x6a0888, 0x6a0898, 0x6a08a8, 0x6a08b8, 0x6a08c8, 0x6a08d8, 0x6a08e8, 0x6a08f8};
  static const u32 offs[8] = {0x7ad, 0x910, 0xa73, 0xbd6, 0xd39, 0xe6c, 0xf9f, 0x10d2};
  while (node) {
    int hit = -1;
    for (int k = 0; k < 9; k++) {
      const char *nm = ext_4dc110(node);
      if (ext_4cc850(nm, (const char *)names[k]) == 0) {
        hit = k;
        break;
      }
    }
    if (hit >= 0 && hit < 4) {
      u8 *sub = self + offs[hit];
      u32 vtp = R32(sub);
      u32 r = (*(V3 *)(vtp))(sub, R32(self + 0x88), R32(node + 0x54), 1);
      if ((u8)r) W32(self + 0x8c, R32(self + 0x8c) + 1);
    } else if (hit >= 4 && hit < 8) {
      u8 *sub = self + offs[hit];
      u32 vtp = R32(sub);
      (*(V3 *)(vtp))(sub, R32(self + 0x88), R32(node + 0x54), 1);
      W32(self + 0x90, R32(self + 0x90) + 1);
    } else if (hit == 8) {
      float vec[3] = {0.0f, 0.0f, -1.0f};
      u32 n = R32(self + 0x12f7);
      u8 *entry = self + 0x1205 + n * 0x79;
      ext_516b60(entry, arg, 0x6a0904, R32(node + 0x54));
      ext_516f40(entry, vec);
      n = R32(self + 0x12f7);
      u8 *e1 = self + n * 0x79;
      W32(e1 + 0x1262, 0x41200000);
      n = R32(self + 0x12f7);
      W32(self + n * 0x79 + 0x1262, 0x42480000);
      n = R32(self + 0x12f7);
      W32(self + n * 0x79 + 0x1266, 0x42480000);
      n = R32(self + 0x12f7);
      W32(self + n * 0x79 + 0x1219, 0x3f666666);
      n = R32(self + 0x12f7);
      ext_516f40(self + 0x1205 + n * 0x79, vec);
      n = R32(self + 0x12f7);
      W32(self + n * 0x79 + 0x1256, 0x3eb2b8c2);
      W32(self + n * 0x79 + 0x125a, 0x3eb2b8c2);
      W32(self + n * 0x79 + 0x125e, 0);
      W32(self + 0x12f7, R32(self + 0x12f7) + 1);
    }
    node = (u8 *)R32(node + 0x60);
  }
  u32 c1 = R32(self + 0x8c);
  float half = cf(0x67a6ac);
  if (c1 == 2) {
    W32(self + 0xa0, R32(self + 0x7d1));
  } else if (c1 == 4) {
    WF(self + 0xa0, (RF(self + 0xa97) + RF(self + 0x7d1)) * half);
  } else {
    u8 *L = G(u8 *, 0x700390);
    u8 *M = (u8 *)(*(u32(THISCALL **)(void *, u32, u32))(*(u8 **)L + 0x20))(L, 0x6a0918, 0x221);
    u8 *r88 = (u8 *)R32(self + 0x88);
    u32 nm = R32(r88 + 4);
    vt_log2(M, 0x2c, 0x6a0950, nm ? nm : 0x67c8e8);
    return false;
  }
  u32 c2 = R32(self + 0x90);
  float v;
  if (c2 == 2) {
    v = -RF(self + 0xd5d);
    WF(self + 0xa4, v);
  } else if (c2 == 4) {
    v = (RF(self + 0xfc3) + RF(self + 0xd5d)) * cf(0x67a6b0);
    WF(self + 0xa4, v);
  } else {
    u8 *L = G(u8 *, 0x700390);
    u8 *M = (u8 *)(*(u32(THISCALL **)(void *, u32, u32))(*(u8 **)L + 0x20))(L, 0x6a0918, 0x22d);
    u8 *r88 = (u8 *)R32(self + 0x88);
    u32 nm = R32(r88 + 4);
    vt_log2(M, 0x2c, 0x6a0970, nm ? nm : 0x67c8e8);
    return false;
  }
  double d1 = absd((double)(RF(self + 0x7c9) - RF(self + 0x92c)));
  WF(self + 0xa8, (float)d1);
  double d2 = absd((double)(RF(self + 0x7d1) - RF(self + 0xd5d)));
  float t = (float)d2;
  WF(self + 0xac, t);
  float x0 = RF(self + 0xa8) + cf(0x67da20);
  float x2 = t + cf(0x67da20);
  W32(self + 0xb4, 0x42480000);
  WF(self + 0xb0, x0 * half);
  WF(self + 0xb8, x2 * half);
  return true;
}
extern "C" u32 THISCALL fn_5257a0(u8 *self, u32 arg);
extern "C" u32 THISCALL fn_5257a0(u8 *self, u32 arg) {
  bool r = body_5257a0(self, arg);
  ext_633654(G(u32, 0x6f5630));
  return r;
}
PCREG(5257a0, fn_5257a0);
