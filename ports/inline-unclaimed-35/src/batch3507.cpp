#include "ff.h"
// batch3507.cpp - area 35 claim 7 (docs/20-unclaimed-35.md): CAction::RunMultiple(unsigned int) (0x4a19a0). Name from the GC name
// map (high). Thiscall, one argument, ret 4. Stubbed in the harness: slot +0x128 (three arguments, writes its second), the cdecl
// compare through the global function pointer at 0x676414, the entries' slot +0x90, and the hook at 0x7003b0 (null).

typedef u32(THISCALL *Slot3)(u8 *self, u32 a0, u32 a1, u32 a2);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32 (*CmpFn)(u32 a0, u32 a1);

// 0x4a19a0, CAction::RunMultiple(unsigned int) (high).
static void THISCALL actionRunMultiple(u8 *self, u32 a1) {
  // The exe skips the slot +0x128 call when the list pointer at this+0x102 is already set (cmp, jne).
  if (*(u32 *)(self + 0x102) == 0) {
    u8 *obj = *(u8 **)(self + 0x44);
    ((Slot3)*(u32 *)(*(u32 *)obj + 0x128))(obj, (u32)*(u16 *)0x7002ac, (u32)(self + 0x102), (u32)obj);
    if (*(u32 *)(self + 0x102) == 0) {
      *(u32 *)(self + 0x102) = (u32)(self + 0x7e);
      self[0x5e] = 1;
    }
  }
  u8 *list = *(u8 **)(self + 0x102);
  u32 sel[0x21];
  u32 n = 0;
  u32 count = *(u32 *)list;
  for (u32 i = 0; i < count; ++i) {
    u8 *entry = *(u8 **)(list + 4 + 4 * i);
    u32 c = *(u32 *)(self + 0x7a);
    if (c == 0 || ((CmpFn)*(u32 *)0x676414)(c, *(u32 *)(entry + 0x7a)) == 0) {
      if (n + 1 > 0x20) {
        u32 hook = *(u32 *)0x7003b0;
        if (hook)
          ((void (*)())hook)();
      }
      sel[n] = (u32)entry;
      n = n + 1;
    }
  }
  for (u32 k = 0; k < n; ++k) {
    u8 *e = (u8 *)sel[k];
    ((Slot1)*(u32 *)(*(u32 *)e + 0x90))(e, a1);
  }
}
PCREG(4a19a0, actionRunMultiple);
