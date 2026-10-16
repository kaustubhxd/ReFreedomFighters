// batch1981.cpp - slice-5 batch 117 (GUESS name): 0x493090
// CDECL(array_arg), ret 4: calls sys+0x9b vtable +0x2c; if result is nonzero, return.
// Otherwise iterate array calling sys+0x9b vtable +0x54 with each element, then 0x4dbe30.
#include "ff.h"

extern "C" void THISCALL ext_4dbe30(void *obj, u32 arg);

// CDECL function - compiler should handle ret 4
extern "C" void __cdecl gapFn493090(void *array_arg) {
  void *sys = g_pSysInterface;
  void *sys_child = *(void **)((u8 *)sys + 0x9b);

  u8 result = vcall<u8>(sys_child, 0x2c);
  if (result) return;

  u32 *array = (u32 *)array_arg;
  u32 count = *array;
  if (count) {
    for (u32 i = 0; i < count; i++) {
      void *element = (void *)array[i + 1];
      void *obj = vcall<void*>(sys_child, 0x54, (u32)element);
      ext_4dbe30(obj, 1);
    }
  }
}

PCREG(493090, gapFn493090);
