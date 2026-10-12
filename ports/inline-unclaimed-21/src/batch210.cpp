// batch210.cpp - unclaimed area 21 (docs/20-unclaimed-21.md), slice floor(addr/16) mod 20 == 0.
// A link-node insert: reads a node through the object at [this+0x24] (vtable slots 0x4c, 0x5c, 0x44, 0x14, and the
// deleting slot 0), or calls the original 0x4cd540 when that object is null, then links the new node into the list
// head at [this+0x1c]. Name GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_4cd540(u8 *self, u32 arg);   // original, thiscall, one stack word

typedef void(THISCALL *SlotOut)(u8 *, u32 *);       // vtable slot taking one out pointer, no result used
typedef u32(THISCALL *SlotOutRet)(u8 *, u32 *);     // vtable slot taking one out pointer, eax result
typedef u32(THISCALL *SlotRet)(u8 *);               // vtable slot with no argument, eax result
typedef void(THISCALL *SlotFlag)(u8 *, u32);        // deleting destructor, one flag word

static u32 vslot(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x4cd880, thiscall(arg) (ret 4): tmp = 0; if [this+0x24]: p->vt[0x4c](p, &tmp); base = p->vt[0x5c](p, &tmp);
// if tmp: edi = base + (2 - [this+0x18]) * 4; p->vt[0x44](p, &tmp); else edi = arg; [edi] = arg;
// r = p->vt[0x14](p); if r == 0: if [this+0x24]: vt[0](p, 1); [this+0x24] = 0.
// else (no object): edi = ext_4cd540(this, arg) - 4.
// Then node = edi + ([this+0x18] - 2) * 4 gets 0, 0, link = [this+0x1c]; if link: [link] = node, else [this+0x20] = node;
// [this+0x1c] = node; returns edi + 4. Name GUESS.
static u32 THISCALL linkNodeInsert_4cd880(u8 *self, u32 arg) {
  u32 tmp = 0;
  u32 edi;
  u8 *p = *(u8 **)(self + 0x24);
  if (p) {
    ((SlotOut)vslot(p, 0x4c))(p, &tmp);
    p = *(u8 **)(self + 0x24);
    u32 base = ((SlotOutRet)vslot(p, 0x5c))(p, &tmp);
    if (tmp) {
      u32 idx = 2u - *(u32 *)(self + 0x18);
      edi = base + idx * 4;
      p = *(u8 **)(self + 0x24);
      ((SlotOut)vslot(p, 0x44))(p, &tmp);
    } else {
      edi = arg;
    }
    *(u32 *)edi = arg;
    p = *(u8 **)(self + 0x24);
    u32 r = ((SlotRet)vslot(p, 0x14))(p);
    if (r == 0) {
      p = *(u8 **)(self + 0x24);
      if (p) ((SlotFlag)vslot(p, 0))(p, 1);
      *(u32 *)(self + 0x24) = 0;
    }
  } else {
    edi = ext_4cd540(self, arg) - 4;
  }
  u32 node = edi + (*(u32 *)(self + 0x18) - 2u) * 4;
  *(u32 *)node = 0;
  *(u32 *)(node + 4) = 0;
  *(u32 *)(node + 4) = *(u32 *)(self + 0x1c);
  *(u32 *)node = 0;
  u32 link = *(u32 *)(self + 0x1c);
  if (link) {
    *(u32 *)link = node;
  } else {
    *(u32 *)(self + 0x20) = node;
  }
  *(u32 *)(self + 0x1c) = node;
  return edi + 4;
}
PCREG(4cd880, linkNodeInsert_4cd880);
