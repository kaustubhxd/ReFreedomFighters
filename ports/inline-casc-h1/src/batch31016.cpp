#include "ff.h"

// 0x639ba0: 6 insns, 13 bytes, thiscall setter: store dword param at [ecx+0x24], ret 4
void THISCALL fn_639ba0(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0x24) = val;
}
PCREG(639ba0, fn_639ba0);

// 0x64f850: 6 insns, 15 bytes, thiscall: chained loads then indirect jump through [eax+0x4c]
void THISCALL fn_64f850(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0xbd);
  void *eax = *(void **)ecx;
  typedef void (*fn_type)();
  ((fn_type)(*(void **)((u8 *)eax + 0x4c)))();
}
PCREG(64f850, fn_64f850);

// 0x64fae0: 6 insns, 16 bytes, thiscall: conditional chained loads and indirect jump
void THISCALL fn_64fae0(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0xbd);
  if (ecx != 0) {
    void *eax = *(void **)ecx;
    typedef void (*fn_type)();
    ((fn_type)(*(void **)((u8 *)eax + 0xc)))();
  }
}
PCREG(64fae0, fn_64fae0);

// 0x445c50: 7 insns, 25 bytes, cdecl: conditional read with global pointer chain
void fn_445c50(void *this_ptr) {
  void *eax = *(void **)((u8 *)this_ptr + 0x18);
  if (eax == 0) {
    eax = *(void **)0x70039c;
    eax = *(void **)((u8 *)eax + 0x9b);
    eax = *(void **)((u8 *)eax + 0xadc);
  }
}
PCREG(445c50, fn_445c50);
