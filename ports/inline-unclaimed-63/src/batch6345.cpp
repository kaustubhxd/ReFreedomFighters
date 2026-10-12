// batch6345.cpp - unclaimed-63 gap-band batch 45: 0x4cee80 (C-set; list unlink, SEH-free), thiscall, one stack argument X, ret 4.
//   X is a two-dword list header: X[0] = the head node esi, X[1] = a signed direction value.
//   If esi == 0: logger 0x700390 slot +0x24 (cdecl, two arguments) is called, then the code continues with esi = 0 (the original faults).
//   If this[+0x24] == 0: this[+0x24] = 0x41e290(0x1c) (cdecl, original; a node initialised with vtable 0x695734, +0x10 = 8, +0x14 = 0,
//   +0x18 = 1, +0xc = 8, +4 = 0, +8 = 0), or 0 if the allocation returns 0.
//   obj = this[+0x24]; obj->vtbl[+4](esi) (thiscall, one argument, ret 4).
//   X[0] = (int)X[1] > 0 ? esi[0] : esi[4]. Then: if esi[0] != 0 then esi[0][+4] = esi[4], else this[+0x1c] = esi[4].
//   If esi[4] != 0 then esi[4][0] = esi[0], else this[+0x20] = esi[0]. Finally esi[0] = 0, esi[4] = 0.
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl allocator, original code, stubbed by the spec

typedef void (*log_fn)(u32, u32);
typedef void(THISCALL * one_fn)(void *, u32);

// 0x4cee80 (C-set).
static void THISCALL unnamed4cee80(u8 *self, u32 x) {
  u32 *X = (u32 *)x;
  u32 esi = X[0];
  if (esi == 0) {
    u32 lg = G(u32, 0x700390);
    ((log_fn)(*(u32 *)(*(u32 *)lg + 0x24)))(lg, 0x695c80u);
  }
  if (*(u32 *)(self + 0x24) == 0) {
    u32 node = ext_41e290(0x1cu);
    if (node != 0) {
      *(u32 *)node = 0x695734u;
      *(u32 *)(node + 0x10) = 8;
      *(u32 *)(node + 0x14) = 0;
      *(u32 *)(node + 0x18) = 1;
      *(u32 *)(node + 0xc) = 8;
      *(u32 *)(node + 4) = 0;
      *(u32 *)(node + 8) = 0;
    }
    *(u32 *)(self + 0x24) = node;
  }
  u32 obj = *(u32 *)(self + 0x24);
  ((one_fn)(*(u32 *)(*(u32 *)obj + 4)))((void *)obj, esi);
  X[0] = ((int)X[1] > 0) ? *(u32 *)esi : *(u32 *)(esi + 4);
  u32 b = *(u32 *)esi;
  u32 a = *(u32 *)(esi + 4);
  if (b != 0)
    *(u32 *)(b + 4) = a;
  else
    *(u32 *)(self + 0x1c) = a;
  u32 c = *(u32 *)(esi + 4);
  u32 d = *(u32 *)esi;
  if (c != 0)
    *(u32 *)c = d;
  else
    *(u32 *)(self + 0x20) = d;
  *(u32 *)esi = 0;
  *(u32 *)(esi + 4) = 0;
}
PCREG(4cee80, unnamed4cee80);
