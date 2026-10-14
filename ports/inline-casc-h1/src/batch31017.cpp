#include "ff.h"

// 0x465850: 7 insns, 19 bytes, stdcall: compare param with constant, return bool, ret 4
u8 STDCALL fn_465850(u32 val) {
  return (val == 0x465710) ? 1 : 0;
}
PCREG(465850, fn_465850);

// 0x48f460: 7 insns, 24 bytes, cdecl: global pointer chain, conditional indirect jump
void fn_48f460() {
  void *eax = *(void **)0x70039c;
  void *ecx = *(void **)((u8 *)eax + 0x1a9f);
  if (ecx != 0) {
    void *eax2 = *(void **)ecx;
    typedef void (*fn_type)();
    ((fn_type)(*(void **)((u8 *)eax2 + 0x94)))();
  }
}
PCREG(48f460, fn_48f460);

// 0x512f80: 7 insns, 24 bytes, cdecl: global pointer chain, conditional read
u32 fn_512f80(void *this_ptr) {
  void *eax = *(void **)0x70039c;
  if (*(u32 *)((u8 *)eax + 0x1a9f) == 0) {
    return 0;
  }
  return *(u32 *)((u8 *)this_ptr + 0x12f);
}
PCREG(512f80, fn_512f80);

// 0x537090: 7 insns, 20 bytes, stdcall: array indexing with lea and complex offset, ret 4
u32 STDCALL fn_537090(void *this_ptr, u32 idx) {
  u32 offset = idx * 8;
  return *(u32 *)((u8 *)this_ptr + offset + idx + 0x515e);
}
PCREG(537090, fn_537090);
