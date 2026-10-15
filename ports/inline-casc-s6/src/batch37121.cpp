// batch37121.cpp - cascade s6 batch 37121: 0x4fd160.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *v);   // ret 4
extern "C" void THISCALL ext_4fd510(u8 *self, u32 *v);   // ret 4
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 bytes);   // allocate
typedef u32(THISCALL *v2_t)(void *, u32, u32);
typedef void (*cd3_t)(void *, u32, u32);

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4fd160, thiscall(stream) ret 4, returns 1: loads this object's entry list from a stream (slot 0x40 = read dword, 0x68 = read byte, 0x50 = read value). After clearing bit 6 of
// +4 and running 0x6352f0 / 0x4fd510 on a local vector it reads ids until -1; each id's table object is logged (error line 0x2b8 with its name, default 0x67c8e8) and a 0x15-byte
// node {id, value, prev, next, owner, flag} appended to the doubly linked list +0x48 (head) / +0x4c (tail), then its flag byte (+0x14) and value (+4) are read from the stream. Finally
// one more index is read and the list's node with that index becomes the current one (+0x50).
static u8 THISCALL fn4fd160(u8 *self, u8 *s) {
  u32 vec = 0;
  D32(self, 4) &= 0xffffffbfu;
  ext_6352f0(self, &vec);
  ext_4fd510(self, &vec);
  u32 id;
  vcall<void>(s, 0x40, (u32)&id);
  while (id != 0xffffffffu) {
    u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
    u8 *obj = (u8 *)vcall<u32>(tab, 0x58, id);
    u8 *lg = *(u8 **)0x700390;
    void *L = (void *)(*(v2_t **)lg)[0x20 / 4](lg, 0x69c54c, 0x2b8);
    u32 nm = D32(obj, 4);
    if (!nm) nm = 0x67c8e8;
    (*(cd3_t **)L)[0x2c / 4](L, 0x69c578, nm);
    u8 *node = (u8 *)ext_41e290(0x15);
    if (node) {
      node[0x14] = 0;
      D32(node, 0x10) = (u32)self;
      D32(node, 0) = id;
      D32(node, 4) = 0;
      u8 *tail = *(u8 **)(self + 0x4c);
      D32(node, 8) = (u32)tail;
      D32(node, 0xc) = 0;
      if (tail) {
        D32(tail, 0xc) = (u32)node;
        D32(self, 0x4c) = (u32)node;
      } else {
        D32(self, 0x48) = (u32)node;
        D32(self, 0x4c) = (u32)node;
      }
    }
    vcall<void>(s, 0x68, (u32)(node + 0x14));
    vcall<void>(s, 0x50, (u32)(node + 4));
    vcall<void>(s, 0x40, (u32)&id);
  }
  u32 idx;
  vcall<void>(s, 0x40, (u32)&idx);
  u8 *cur = *(u8 **)(self + 0x48);
  u32 i = 0;
  while (cur) {
    if (i == idx) {
      D32(self, 0x50) = (u32)cur;
      break;
    }
    cur = *(u8 **)(cur + 0xc);
    i++;
  }
  return 1;
}
PCREG(4fd160, fn4fd160);
