// batch37006.cpp - cascade s6 batch 37006: 0x64c2d0.
#include "ff.h"

extern "C" void THISCALL ext_645c10(u8 *self, u8 *p);                                   // ret 4
extern "C" u32 THISCALL ext_658e00(u8 *self, u32 *arr, u32 n);                         // ret 8, returns count
extern "C" u8 *THISCALL ext_64d030(u8 *self, u8 *a, u8 *b, u32 c, u32 d);              // ret 0x10
extern "C" void THISCALL ext_658fd0(u8 *self, u8 *p);                                   // ret 4
typedef void(THISCALL *s1_t)(void *, void *);
typedef u32(THISCALL *v0_t)(void *);

static inline u32 tagOf(u8 *o) { return o ? *(u32 *)(*(u8 **)(o + 0xc) + 0x23) : 0x200002; }
static inline void adv(u32 *it) {
  it[1]++;
  u32 *ch = (u32 *)it[2];
  if (it[1] == ch[0]) {
    u32 nx = ch[2];
    it[2] = nx;
    if (nx) { it[1] = 0; it[0] = nx + 0x10; } else it[0] = 0;
  } else {
    it[0] += 4;
  }
}

// 0x64c2d0, thiscall, no args: walks the node list at this+0x10199 (iterator via slots 0xc/0x10); for nodes whose +0x10 equals [engine+0x3c]
// it feeds the string at +0x15 to 0x645c10, then for the up-to-8 objects 0x658e00 returns, walks the chain reached through +0x54/+8 and
// calls 0x64d030 (and 0x658fd0 on its result when the +0x5a word is 0).
static void THISCALL fn64c2d0(u8 *self) {
  u32 it[3];
  *(u32 *)(self + 0x10045) = 0;
  *(u32 *)(self + 0x10041) = 0;
  u32 key = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u8 *L = self + 0x10199;
  (*(s1_t **)L)[0xc / 4](L, it);
  while (it[0]) {
    u8 *node = *(u8 **)it[0];
    if (*(u32 *)(node + 0x10) != key) {
      (*(s1_t **)L)[0x10 / 4](L, it);
      continue;
    }
    u8 *B = *(u8 **)(node + 8);
    u8 *P = *(u8 **)(*(u8 **)(B + 0x38) + 0x54);
    u8 *r = (u8 *)(*(v0_t **)P)[0x24c / 4](P);
    ext_645c10(r, node + 0x15);
    adv(it);
    *(u32 *)(self + 0x1004d) = *(u32 *)(node + 0x20);
    u32 arr[8];
    u32 cnt = ext_658e00(B, arr, 8);
    if (cnt) {
      u32 idx = 0;
      do {
        u8 *c = (u8 *)arr[idx];
        u8 *edi = *(u8 **)(c + 0x54);
        if ((tagOf(edi) & 0x100000)) {
          u8 *ecx = *(u8 **)(edi + 8);
          if (!(*(u32 *)(ecx + 0x3c) & 0x2c00) && ecx) {
            u32 v34 = (u32)ecx;
            do {
              if (!(tagOf(*(u8 **)(ecx + 0x54)) & 0x100000) && *(u32 *)(ecx + 0x6c) && !(*(u32 *)(ecx + 0x3c) & 0x2c00)) {
                u16 w = *(u16 *)(ecx + 0x5a);
                u8 *rr = ext_64d030(self, self + 0x1002d, ecx, 0, 0);
                if (!w && rr) ext_658fd0(*(u8 **)(rr + 8), B);
              }
              (*(s1_t **)edi)[0x50 / 4](edi, &v34);
              ecx = (u8 *)v34;
            } while (ecx);
          }
        }
        idx++;
      } while (idx != cnt);
    }
  }
  *(u32 *)(self + 0x1004d) = 0;
}
PCREG(64c2d0, fn64c2d0);
