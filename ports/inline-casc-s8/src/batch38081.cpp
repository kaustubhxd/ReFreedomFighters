// batch38081.cpp - cascade s8 batch 38081: 0x5f4ac0 (drain a queue of pending objects: map each to a range, run the update, reset the state flags).
#include "ff.h"

extern "C" u32 THISCALL ext_5ffbc0(u8 *tab, u32 id);                // ret 4
extern "C" void THISCALL ext_5f3c90(u8 *self, u32 *p);              // ret 4
extern "C" void THISCALL ext_5f56f0(u8 *self);
extern "C" void THISCALL ext_5f9130(u8 *self, u32 a, u32 b);        // ret 8
extern "C" u32 THISCALL ext_600810(u8 *p);                          // eax = [p+8] - [p+4]
typedef u32(THISCALL *v0_t)(void *);
typedef u32 (*hook_t)();
typedef int (*stricmp_t)(const char *, const char *);
#define imp_stricmp G(stricmp_t, 0x676414)
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define W(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword
#define W16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define UN16(p, off) (*(u16 *)((u8 *)(p) + (off)))

static void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
}

// 0x5f4ac0, thiscall(void). this+0x4c = array of object pointers, +0x54 = count, +0xac = state flags (word), +0x96 = table of ranges, +0x8c / +0x70 = id translation.
static void THISCALL fn5f4ac0(u8 *self) {
  u32 flags = UN16(self, 0xac);
  if (flags & 0xa800) return;
  if ((flags & 0xf) == 0) return;
  do {
    u32 n0 = W(self, 0x54);
    if (n0 != 0) {
      u32 i = 0;
      do {
        if (!(i < W(self, 0x54))) assert_hook();
        u8 *obj = ((u8 **)W(self, 0x4c))[i];
        u32 idv = (u16)SLOT(obj, 0x5c, v0_t)(obj);
        u32 ebx = idv ? ext_5ffbc0(self + 0x70, idv) : W(self, 0x8c);
        bool skip = false;
        if (ebx == 0xffffffff) {
          ebx = W(self, 0x8c);
          if (ebx == 0xffffffff) skip = true;
        }
        if (!skip) {
          u32 loc[4] = {1, 0, 0, 0};   // the original's stack struct: dword 1 at +0, the id word at +0xc
          u8 *A = (u8 *)UN32(self, 0x96);
          *(u8 **)(W(A, 0x3c) + UN32(self, 0x9e)) = obj;
          A = (u8 *)UN32(self, 0x96);
          *(u32 *)(W(A, 0x40) + UN32(self, 0x9e)) = 0;
          u16 w18 = (u16)SLOT(obj, 0x5c, v0_t)(obj);
          *(u16 *)((u8 *)loc + 0xc) = w18;
          ext_5f3c90(self, loc);
          u32 si = (u16)SLOT(obj, 0x5c, v0_t)(obj);
          UN32(self, 0x1a) = SLOT(obj, 0x54, v0_t)(obj);
          u32 a6 = UN32(self, 0xa6);
          UN16(self, 0x1e) = (u16)si;
          u8 *e = (u8 *)UN32(self, 0x96);
          UN32(self, 0xae) = a6;
          UN32(self, 0xb2) = UN32(self, 0xaa);
          u32 res = 0;
          bool found = false;
          while (e) {
            if (!(W(e, 0x48) > ebx) && ext_600810(e + 0x50) + W(e, 0x48) > ebx) { found = true; break; }
            e = (u8 *)W(e, 0x9c);
          }
          if (found) res = W(e, 0x54) - W(e, 0x48) + ebx;
          else assert_hook();
          UN32(self, 0xa6) = res;
          UN32(self, 0x12) = 0xffffffff;
          UN16(self, 0xac) |= 0x8000;
          ext_5f56f0(self);
          UN32(self, 0xa6) = UN32(self, 0xae);
          UN32(self, 0xaa) = UN32(self, 0xb2);
          u32 v12 = UN32(self, 0x12);
          UN32(self, 0x1a) = 0x6b8b40;
          if (v12 != 0xffffffff) {
            ext_5f9130(self, v12, 1);
            UN16(self, 0xac) = (UN16(self, 0xac) & 0xfff1) | 1;
            UN32(self, 0xa) = 0;
            UN32(self, 0x16) = 0;
          }
        }
        if (!SLOT(obj, 0x40, v0_t)(obj)) assert_hook();
        char *name = (char *)SLOT(obj, 0x54, v0_t)(obj);
        u8 m = UN16(self, 0xac) & 0xf;
        if (m == 4 || m == 5) {
          u32 cmp = UN32(self, 0x16);
          if (cmp != 0) {
            if (imp_stricmp(name, (const char *)cmp) == 0) {
              UN16(self, 0xac) = (UN16(self, 0xac) & 0xfff1) | 1;
              UN32(self, 0x16) = 0;
              UN32(self, 0xa) = 0;
            }
          } else {
            UN16(self, 0xac) = (UN16(self, 0xac) & 0xfff1) | 1;
            UN32(self, 0xa) = 0;
          }
        }
        SLOT(obj, 0x28, v0_t)(obj);
        i++;
      } while (i < n0);
      if (n0 < W(self, 0x54)) {
        u32 *arr = (u32 *)W(self, 0x4c);
        for (u32 d = n0, s = 0; d < W(self, 0x54); d++, s++) ((u32 *)W(self, 0x4c))[s] = ((u32 *)W(self, 0x4c))[d];
        (void)arr;
        W(self, 0x54) -= n0;
      } else {
        W(self, 0x54) = 0;
      }
    } else {
      W(self, 0x54) = 0;
    }
  } while (W(self, 0x54) != 0);
}
PCREG(5f4ac0, fn5f4ac0);
