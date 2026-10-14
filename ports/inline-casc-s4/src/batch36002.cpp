// batch36002.cpp - cascade s4 batch 36002: 0x49da90, 0x4a7f20, 0x4ceda0 (tier F rows).
#include "ff.h"

typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef void(THISCALL *v1_t)(void *, void *);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v1r_t)(void *, void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

// 0x49da90, thiscall(no args): compacts the dword array at this+4 (count this[0x10]). For each v: o = [0x70038c]->slot 0xcc(v);
// o == 0: dropped; o[0x18] & 0x10: kept; else if o[0x3c] & 0x10: bit cleared, dropped; else kept. Then n = kept count;
// if n < count and [0x70038c]: slot 0x30(0x68ee90, n*4, (count-n)*4). this[0x10] = n.
static void THISCALL fn49da90(u8 *self) {
  u32 *base = *(u32 **)(self + 4);
  u32 *src = base;
  u32 *dst = base;
  if (*(u32 *)(self + 0x10) != 0) {
    u32 i = 0;
    do {
      u32 v = *src++;
      u8 *e = G(u8 *, 0x70038c);
      u8 *o = (*(v1o_t **)e)[0xcc / 4](e, v);
      if (o) {
        if (o[0x18] & 0x10) {
          *dst++ = v;
        } else {
          u32 f = *(u32 *)(o + 0x3c);
          if (f & 0x10) {
            *(u32 *)(o + 0x3c) = f & 0xffffffefu;
          } else {
            *dst++ = v;
          }
        }
      }
      i++;
    } while (i != *(u32 *)(self + 0x10));
  }
  s32 n = (s32)((u8 *)dst - *(u8 **)(self + 4)) >> 2;
  u32 cnt = *(u32 *)(self + 0x10);
  if ((u32)n < cnt) {
    u8 *e = G(u8 *, 0x70038c);
    if (e) (*(v3_t **)e)[0x30 / 4](e, 0x68ee90u, (u32)n * 4, (cnt - (u32)n) * 4);
  }
  *(u32 *)(self + 0x10) = (u32)n;
}
PCREG(49da90, fn49da90);

typedef u32 (*hook_t)();
extern "C" void THISCALL ext_4a7fb0(void *self, u32 a);  // ret 4

// 0x4a7f20, thiscall(s) ret 4, returns al = 1: this[4] &= ~0x40; assert hook [0x7003b0] (int3 when null); 0x4a7fb0(this, 0);
// s->slot 0x58(this+0x72), (this+0x76); s->slot 0x68(this+0x7b .. 0x80) one byte each.
static u8 THISCALL fn4a7f20(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  else h();
  ext_4a7fb0(self, 0);
  void **vt = *(void ***)s;
  ((v1_t)vt[0x58 / 4])(s, self + 0x72);
  vt = *(void ***)s;
  ((v1_t)vt[0x58 / 4])(s, self + 0x76);
  for (u32 off = 0x7b; off <= 0x80; off++) {
    vt = *(void ***)s;
    ((v1_t)vt[0x68 / 4])(s, self + off);
  }
  return 1;
}
PCREG(4a7f20, fn4a7f20);

typedef int (*cmp_t)(u32, u32);

// 0x4ceda0, thiscall(name) ret 4: if this: this->slot 0x4c(&loc); r = this->slot 0x5c(&loc); while loc != 0: if _stricmp(r, name) == 0:
// this->slot 0x44(&loc), this[0xc] |= 0x80000000, return; else r = this->slot 0x5c(&loc).
// Not found: log through [0x700390]: o = slot 0x20(0x695b7c, 0x58d); o->slot 0x2c(o, 0x695cc4, name) cdecl, ecx = o->vtbl.
static void THISCALL fn4ceda0(u8 *self, u32 name) {
  u32 loc[3];
  if (self) {
    void **vt = *(void ***)self;
    ((v1_t)vt[0x4c / 4])(self, loc);
    vt = *(void ***)self;
    u32 r = ((v1r_t)vt[0x5c / 4])(self, loc);
    if (loc[0] != 0) {
      for (;;) {
        int c = G(cmp_t, 0x676414)(r, name);
        vt = *(void ***)self;
        if (c == 0) {
          ((v1_t)vt[0x44 / 4])(self, loc);
          *(u32 *)(self + 0xc) |= 0x80000000u;
          return;
        }
        r = ((v1r_t)vt[0x5c / 4])(self, loc);
        if (loc[0] == 0) break;
      }
    }
  }
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x695b7cu, 0x58du);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[n]\n\tpushl %[s]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $12, %%esp"
                   : "+c"(vt2)
                   : [s] "i"(0x695cc4), [o] "r"(o), [n] "r"(name), [f] "r"(fn)
                   : "eax", "edx", "memory", "cc");
}
PCREG(4ceda0, fn4ceda0);
