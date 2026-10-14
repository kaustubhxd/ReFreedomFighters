#include "ff.h"

// 0x4dbbd0: 6 insns, 13 bytes, thiscall: load field, test, conditional jump or tail-jump
void THISCALL fn_4dbbd0(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0x54);
  if (ecx != 0) {
    void *eax = *(void **)ecx;
    typedef void (*fn_type)();
    ((fn_type)(*(void **)((u8 *)eax + 0x1c)))();
  }
}
PCREG(4dbbd0, fn_4dbbd0);

// 0x4f3230: 6 insns, 15 bytes, thiscall: load field, load vtable, indirect jump
void THISCALL fn_4f3230(void *this_ptr) {
  void *ecx = *(void **)((u8 *)this_ptr + 0x6f);
  void *eax = *(void **)ecx;
  typedef void (*fn_type)();
  ((fn_type)(*(void **)((u8 *)eax + 0x21c)))();
}
PCREG(4f3230, fn_4f3230);

// 0x5186c0: 6 insns, 16 bytes, thiscall setter: store dword param at [ecx+0x1635], ret 4
void THISCALL fn_5186c0(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0x1635) = val;
}
PCREG(5186c0, fn_5186c0);

// 0x5332d0: 6 insns, 13 bytes, thiscall setter: store byte param at [ecx+0x49], ret 4
void THISCALL fn_5332d0(void *this_ptr, u8 val) {
  *(u8 *)((u8 *)this_ptr + 0x49) = val;
}
PCREG(5332d0, fn_5332d0);
