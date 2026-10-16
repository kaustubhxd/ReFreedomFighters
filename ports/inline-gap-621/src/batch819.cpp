// batch819.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void * __attribute__((cdecl)) ext_41e290(u32 size);   // new operator
extern "C" void THISCALL ext_4d1390(u8 *self, u8 *child, u8 *parent);  // hooked (GUESS)
typedef void(THISCALL *VOneArg)(u8 *, u8 *);    // vt[0x1c]: thiscall one word (pointer)

// 0x4d1830, thiscall(src) ret 4: builds a tree structure with linked lists.
// For each outer node n (from src[0x24], linked via n[0x30]):
//   - Allocates object p (0x38 bytes), initializes with vtable 0x695f78
//   - Links p into doubly-linked list at this+0x24/+0x28 with forward/back pointers +0x30/+0x34
//   - For each child ch of n (from n[0x24], linked via ch[0x30]):
//     - Allocates m (0x38 bytes), calls 0x4d1390(m, ch, p)
//   - Calls n->vt[4](n, p)
// Then iterates src->vt[0x2c](src) times (count), for each i:
//   - Calls src->vt[0x40](src, i) and src->vt[0x3c](src, i, a) to get arguments
//   - Calls this->vt[0x1c](this, b)
static void THISCALL buildTree_4d1830(u8 *self, u8 *src) {
  // First loop: outer nodes
  u8 *n = *(u8 **)(src + 0x24);
  while (n) {
    u8 *p = (u8 *)ext_41e290(0x38u);
    if (p) {
      // Initialize p: vtable 0x695f78, zero fields
      *(u32 *)p = 0x695f78u;
      *(u32 *)(p + 0xc) = 0;
      *(u32 *)(p + 0x24) = 0;
      *(u32 *)(p + 0x28) = 0;
      *(u32 *)(p + 0x14) = 0;
      *(u32 *)(p + 0x10) = 0;
      *(u32 *)(p + 0x18) = 0;
      *(u32 *)(p + 0x1c) = 0;
      *(u32 *)(p + 0x20) = *(u32 *)(n + 0x20);
      *(u32 *)(p + 0x34) = 0;
      *(u32 *)(p + 0x30) = 0;
      *(u32 *)(p + 0x2c) = (u32)self;

      // Link p into list at this+0x24/+0x28
      if (self) {
        u8 *t = *(u8 **)(self + 0x28);
        *(u32 *)(p + 0x34) = (u32)t;
        if (t) {
          *(u32 *)(t + 0x30) = (u32)p;
        } else {
          *(u32 *)(self + 0x24) = (u32)p;
        }
        *(u32 *)(self + 0x28) = (u32)p;
      } else {
        *(u32 *)(p + 0x34) = 0;
        *(u32 *)(p + 0x30) = 0;
      }

      // Second loop: children
      u8 *ch = *(u8 **)(n + 0x24);
      while (ch) {
        u8 *m = (u8 *)ext_41e290(0x38u);
        if (m) {
          ext_4d1390(m, ch, p);
        }
        ch = *(u8 **)(ch + 0x30);
      }

      // Call n->vt[4](n, p) after children loop
      typedef void(THISCALL *VOneArg)(u8 *, u8 *);
      VOneArg g = (VOneArg)(*(u32 *)(*(u32 *)n + 4));
      g(n, p);
    }
    n = *(u8 **)(n + 0x30);
  }

  // Second loop: iterate over src count
  typedef u32(THISCALL *VCountFn)(u8 *);
  VCountFn cnt_fn = (VCountFn)(*(u32 *)(*(u32 *)src + 0x2c));
  u32 cnt = cnt_fn(src);
  u32 vt = *(u32 *)self;  // Read vtable BEFORE the loop (as spec says)

  for (u32 i = 0; i != cnt; i++) {
    // Call src->vt[0x40](src, i) with fastcall convention (ecx=src, stack=[i])
    typedef u8 *(FASTCALL *VArrAccess)(u8 *, u32);
    VArrAccess fn_40 = (VArrAccess)(*(u32 *)(*(u32 *)src + 0x40));
    u8 *a = fn_40(src, i);

    // Call src->vt[0x3c](src, i, a) with stack args [i, a]
    typedef u8 *(FASTCALL *VTwoArgAccess)(u8 *, u32, u8 *);
    VTwoArgAccess fn_3c = (VTwoArgAccess)(*(u32 *)(*(u32 *)src + 0x3c));
    u8 *b = fn_3c(src, i, a);

    // Call this->vt[0x1c](this, b)
    VOneArg vt_fn = (VOneArg)(*(u32 *)(vt + 0x1c));
    vt_fn(self, b);
  }
}
PCREG(4d1830, buildTree_4d1830);
