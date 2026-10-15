// batch33045.cpp - h3 (Sonnet) batch 33045: tier B loops, list insert, ring push, string copy
#include "ff.h"

extern "C" void THISCALL ext_64cda0(u8 *self, u32 a);                           // ret 4
extern "C" void THISCALL ext_4ce180(u8 *self, u32 a);                           // ret 4
extern "C" u32 __attribute__((fastcall)) ext_4cc850(u32 ecx, u32 edx);          // plain ret
extern "C" void THISCALL ext_4920e0(u8 *self, u8 *pos, u8 *node);               // ret 8
extern "C" void THISCALL ext_63f600(u8 *self, u8 *a);                           // ret 4
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);
extern "C" void __attribute__((fastcall)) ext_43e8e0(u8 *ecx, u8 *edx, u8 *stk); // ret 4
extern "C" void THISCALL ext_440ce0(u32 *out, u32 a);                           // ret 4
extern "C" u32 THISCALL ext_57dde0(u32 id);                                     // this = id

// 0x63ee70: thiscall(a) ret 4
static void THISCALL fn63ee70(u8 *self, u32 a) {
  u32 n = *(u32 *)(self + 0xec);
  if (n) {
    for (u32 i = 0; i != *(u32 *)(self + 0xec);) {
      u8 *el = *(u8 **)(self + 0xf0 + 4 * i);
      u32 tab = *(u32 *)(el + 0x10071);
      if (*(u32 *)(tab + (a & 0xfff) * 4) != 0) ext_64cda0(el, a);
      i++;
    }
  }
  u32 id = (u16)a;
  *(u32 *)(*(u8 **)(self + 0x68) + (id & 0xfff) * 4) = 0;
  ext_4ce180(self + 0xb990, id - 1);
}
PCREG(63ee70, fn63ee70);

// 0x4e53f0: thiscall(a,b) ret 8: find first entry where 0x4cc850 returns 0
static u32 THISCALL fn4e53f0(u8 *self, u8 *a, u32 b) {
  u8 *ebx = (u8 *)(*(u32 *)(a + 0x80) + *(u32 *)(self + 0xc));
  if (*(u32 *)ebx != 0) {
    u32 i = 0;
    u8 *edi = ebx + 4;
    do {
      u32 node = *(u32 *)edi + *(u32 *)(self + 0xc);
      u32 ecx = *(u32 *)node + (*(u32 *)(self + 8) + 1);
      if (ext_4cc850(ecx, b) == 0) return node;
      i++;
      edi += 4;
    } while (i != *(u32 *)ebx);
  }
  return 0;
}
PCREG(4e53f0, fn4e53f0);

// 0x4947f0: thiscall(a, b) ret 8: unlink node a from sorted list at [this+0xa04], find insert position, 0x4920e0(pos, a)
static void THISCALL fn4947f0(u8 *self, u8 *a, int b) {
  *(int *)(a + 8) = b;
  u8 *edx = *(u8 **)(self + 0xa04);
  while (edx) {
    int ecx = *(int *)(edx + 8);
    if (b > ecx) {
    } else if (b != ecx) {
      break;
    } else if (*(int *)(a + 4) < *(int *)(edx + 4)) {
      break;
    }
    edx = *(u8 **)(edx + 0x10);
  }
  u8 *prev = *(u8 **)(a + 0xc);
  u8 *next = *(u8 **)(a + 0x10);
  if (prev) {
    *(u8 **)(prev + 0x10) = next;
  } else {
    *(u8 **)(self + 0xa04) = next;
    if (next) *(u32 *)(next + 0xc) = 0;
  }
  u8 *nx = *(u8 **)(a + 0x10);
  if (nx) *(u8 **)(nx + 0xc) = *(u8 **)(a + 0xc);
  ext_4920e0(self, edx, a);
}
PCREG(4947f0, fn4947f0);

// 0x64a120: thiscall(a) ret 4: push node a+4 onto ring buffer at [this+0x1005d]+0x268, drop refcount of [a+0xc]
static void THISCALL fn64a120(u8 *self, u8 *a) {
  u8 *esi = a ? a + 4 : 0;
  esi[5] &= 0xfe;
  *(u32 *)esi = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u8 *edx = *(u8 **)(self + 0x1005d) + 0x268;
  *(u32 *)esi = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u8 *ecx = *(u8 **)edx;
  u32 idx = (u16)((int)(ecx - edx - 8) >> 2);
  *(u8 **)ecx = esi;
  *(u32 *)edx += 4;
  if (*(u8 **)edx == edx + 0x8008) *(u8 **)edx = edx + 8;
  *(u16 *)(esi + 6) = (u16)idx;
  u8 *rc = *(u8 **)(a + 0xc);
  rc[8] += 0xff;
  if (rc[8] == 0) ext_63f600(*(u8 **)(self + 0x1005d), rc);
}
PCREG(64a120, fn64a120);

// 0x6055b0: thiscall(s) ret 4 bool: copy string into [this+0xc], reallocating when it does not fit in [this+0x10] chars
static u32 THISCALL fn6055b0(u8 *self, const u8 *s) {
  u32 n = 0;
  while (s[n]) n++;
  int cap = (int)*(u16 *)(self + 0x10) - 1;
  if ((int)(u16)n > cap) {
    ext_634273(*(void **)(self + 0xc), 1);
    u32 m = 0;
    while (s[m]) m++;
    u16 len = (u16)(m + 1);
    *(u16 *)(self + 0x10) = len;
    *(void **)(self + 0xc) = ext_41e290(len);
  }
  u8 *d = *(u8 **)(self + 0xc);
  u8 c;
  do {
    c = *s++;
    *d++ = c;
  } while (c);
  return 1;
}
PCREG(6055b0, fn6055b0);

// 0x4526a0: stdcall(a, b) ret 8: for 20 table entries call 0x43e8e0(a+12*i, b+(t+7)*4, b+0x10)
static void STDCALL fn4526a0(u8 *a, u8 *b) {
  static const u32 t[20] = {0, 3, 9, 0xc, 3, 6, 9, 0x12, 3, 0xc, 0xf, 0x12, 9, 0x12, 0x15, 0xc, 3, 9, 0xc, 0x12};
  for (u32 i = 0; i != 20; i++) {
    ext_43e8e0(a, b + (t[i] + 7) * 4, b + 0x10);
    a += 0xc;
  }
}
PCREG(4526a0, fn4526a0);

// 0x444d50: thiscall(out, limit) ret 8: copy masked pairs from a segmented source into out
static u8 *THISCALL fn444d50(u8 *self, u8 *out, u8 *limit) {
  u32 tmp[4];
  ext_440ce0(tmp, *(u32 *)(self + 0xb8));
  u8 *edx = (u8 *)tmp[1];
  u8 *esi = out;
  if (!edx) return esi;
  u8 *lim = (u8 *)tmp[2];
  u8 *ebx = esi + 4;
  u8 *ecx = (u8 *)tmp[0];
  for (;;) {
    u32 edi = *(u32 *)edx & 0xfffffff8u;
    u32 eax = *(u32 *)(edx + 4);
    edx += 8;
    if (limit <= ebx) return esi;
    eax &= 0xfffffff8u;
    *(u32 *)esi = edi;
    *(u32 *)(esi + 4) = eax;
    ebx += 8;
    esi += 8;
    if (edx == lim) {
      if (!ecx) return esi;
      for (;;) {
        if (!(ecx[8] & 1)) return esi;
        ecx = *(u8 **)(ecx + 0xc);
        if (!ecx) return esi;
        if (ecx[8] >= 2) break;
      }
      u8 al = ecx[8];
      edx = ecx + 0xc;
      if (al & 1) edx += 4;
      lim = ecx + ((u32)al + 3) * 4;
    }
    if (!edx) return esi;
  }
}
PCREG(444d50, fn444d50);

// 0x57d460: thiscall(out) ret 4: resolve up to 4 ids at this+0xac via 0x57dde0
static u32 THISCALL fn57d460(u8 *self, u32 *out) {
  u32 count = 0;
  u32 *p = (u32 *)(self + 0xac);
  do {
    int ecx = (int)*p;
    if (ecx == -1) return count;
    if ((ecx & 0xffff0000) == 0) {
      u32 esi = 0;
      u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x190b);
      if (tab) {
        u8 *e = tab;
        for (;;) {
          int ebx = *(int *)e;
          if (!(ebx > ecx) && *(int *)(e + 0xc) + ebx > ecx) {
            esi = (esi << 16) - ebx;
            ecx += esi;
            goto resolved;
          }
          esi++;
          e += 0x10;
        }
      }
      ecx = -1;
    }
  resolved:
    u32 r = ext_57dde0(ecx);
    if (!r) return count;
    out[count] = r;
    count++;
    p++;
  } while (count < 4);
  return count;
}
PCREG(57d460, fn57d460);
