// batch864.cpp - area 50 (residue-9 candidate): 0x4cef90 [87 instr, thiscall, one stack arg (a record pointer), ret 4; no name in
// the map (GUESS "release n entries from a segment and advance the list")]. The segment (this) keeps its node at +8, a counter at
// +0x14 and a count n at +0x18. The node's count (+8) drops by n; the record's count (+8) drops by n too and, when it goes
// negative, the record restarts at this+0x10 - n and takes the dword its pointer leads to. While the counter is not zero, n
// dwords are moved in the node's data (memcpy, or memset with 0x55 when the source and destination are the same), then, when
// the node's count is zero, the node moves to its next (+0) and the head of the list is updated, or the list ends and the
// logger reports it (cdecl, line 0x695bf4). The node's virtual slot +0x7c is called with the old node.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x4cef90 (name GUESS).
static void THISCALL Fn4cef90(u8 *self, u8 *r) {
  u8 *node = (u8 *)FP(self, 8);
  U32(self, 0x14) = U32(self, 0x14) - 1;
  u32 n = U32(self, 0x18);
  U32(node, 8) = U32(node, 8) - n;
  if ((s32)U32(r, 8) > 0) {
    U32(r, 4) = U32(r, 4) - n;
    if ((s32)U32(r, 4) < 0) {
      U32(r, 4) = U32(self, 0x10) - U32(self, 0x18);
      U32(r, 0) = *(u32 *)U32(r, 0);
    }
  }
  if (U32(self, 0x14) != 0) {
    u8 *a = node + 0x10 + U32(node, 8) * 4;
    u8 *b = (u8 *)U32(r, 0) + (U32(r, 4) + 4) * 4;
    u32 bytes = n << 2;
    if (a == b) {
      typedef void *(*memset_t)(void *, int, u32);
      (*(memset_t *)0x676260)(a, 0x55, bytes);
    } else {
      typedef void *(*memcpy_t)(void *, const void *, u32);
      (*(memcpy_t *)0x67626c)(b, a, bytes);
    }
  }
  node = (u8 *)FP(self, 8);
  if (U32(node, 8) != 0) return;
  u32 nx = U32(node, 0);
  U32(self, 8) = nx;
  if (nx != 0) {
    if ((u32)node == U32(r, 0)) {
      U32(r, 0) = nx;
      U32(r, 4) = U32(self, 0x10);
    }
    U32((u8 *)FP(self, 8), 4) = 0;
    vcall<void>(self, 0x7c, node);
    return;
  }
  U32(self, 4) = 0;
  U32(r, 0) = 0;
  if (U32(self, 0x14) != 0) {
    u8 *lg = G(u8 *, 0x700390);
    typedef void (*log_t)(void *, const char *);
    (*(log_t *)(*(u8 **)lg + 0x24))(lg, (const char *)0x695bf4);
  }
  vcall<void>(self, 0x7c, node);
}
PCREG(4cef90, Fn4cef90);
