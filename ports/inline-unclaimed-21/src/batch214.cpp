// batch214.cpp - unclaimed area 21, piece of the 0x5a76c0 group. A loop over two pointer arrays of this object: for each
// non-null entry, a lookup on the render-manager child (vtable 0x154, constant key) gives a record whose dword at +0x23
// is passed to the entry's vtable 0x1e0; when it returns nonzero the entry's +0x1c is set to the argument. Names GUESS.
#include "ff.h"

typedef u8 *(THISCALL *SlotLookup)(u8 *, u32, u32);   // vtable 0x154: two stack words, returns a record pointer
typedef u32(THISCALL *SlotTest)(u8 *, u32);            // vtable 0x1e0: one stack word, al result

static u32 vslot2(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// One pass over this->array[i] (array at [this + off]): the body of the loop in 0x5aaf60 for one array.
static void visitEntry_5aaf60(u8 *self, u32 off, u32 i, u32 arg) {
  u32 *arr = *(u32 **)(self + off);
  if (arr[i] == 0) return;
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  u8 *rec = ((SlotLookup)vslot2(obj, 0x154))(obj, 0x6af1cc, 0);
  u32 v = *(u32 *)(rec + 0x23);
  u8 *node = (u8 *)arr[i];
  u8 ok = (u8)((SlotTest)vslot2(node, 0x1e0))(node, v);
  if (ok) {
    u8 *y = (u8 *)(*(u32 **)(self + off))[i];
    if (y) *(u32 *)(y + 0x1c) = arg;
  }
}

// 0x5aaf60, thiscall(arg) (ret 4): for i in [0, [this]): visitEntry(this, +4, i, arg); visitEntry(this, +8, i, arg).
static void THISCALL flagArrays_5aaf60(u8 *self, u32 arg) {
  u32 count = *(u32 *)self;
  for (u32 i = 0; i < count; ++i) {
    visitEntry_5aaf60(self, 4, i, arg);
    visitEntry_5aaf60(self, 8, i, arg);
  }
}
PCREG(5aaf60, flagArrays_5aaf60);
