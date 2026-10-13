// batch1982.cpp - 0x438f50 ZInputActions::GetActiveActions(REFTAB*)
// THISCALL(this, reftab), ret 4: walks two nested lists with iterator protocol.
// Uses iter66.py list iterator stubs (vtable +0x4c begin, +0x5c next).
#include "ff.h"

extern "C" u32 ext_437d60(void *element);  // GUESS stub (cdecl, hooked by address)
extern "C" u32 ext_438150(void *element);  // verified in area 22 (cdecl, hooked by address)

static void THISCALL gapFn438f50(u8 *self, void *reftab) {
  // Walk first list at this+0x1214
  void *list1 = *(void **)(self + 0x1214);
  if (!list1) return;

  // Begin first list: call vtable +0x4c(flag*)
  u32 flag1 = 0;
  vcall<u32>(list1, 0x4c, (u32)&flag1);
  if (!flag1) return;  // Empty list

  // Get first element from list: call vtable +0x5c(flag*) to get next
  u32 elem1 = vcall<u32>(list1, 0x5c, (u32)&flag1);
  if (!flag1 || !elem1) return;

  // elem1 is an element pointer; has nested list at +0x19
  void *list2 = *(void **)(((u8 *)elem1) + 0x19);
  if (!list2) return;

  // Begin second list
  u32 flag2 = 0;
  vcall<u32>(list2, 0x4c, (u32)&flag2);
  if (!flag2) return;

  // Get first element from second list
  u32 elem2 = vcall<u32>(list2, 0x5c, (u32)&flag2);
  if (!flag2 || !elem2) return;

  // Call action helper for this element
  ext_437d60((void *)elem2);
}

PCREG(438f50, gapFn438f50);
