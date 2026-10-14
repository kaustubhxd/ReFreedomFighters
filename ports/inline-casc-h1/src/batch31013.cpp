#include "ff.h"

// 0x471670: 6 insns, 16 bytes, thiscall setter: store dword param at [ecx+0xd5], ret 4
void THISCALL fn_471670(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0xd5) = val;
}
PCREG(471670, fn_471670);

// 0x478620: 6 insns, 16 bytes, thiscall setter: store byte param at [ecx+0x690], ret 4
void THISCALL fn_478620(void *this_ptr, u8 val) {
  *(u8 *)((u8 *)this_ptr + 0x690) = val;
}
PCREG(478620, fn_478620);

// 0x4b00d0: 6 insns, 13 bytes, thiscall setter: store dword param at [ecx+0x48], ret 4
void THISCALL fn_4b00d0(void *this_ptr, u32 val) {
  *(u32 *)((u8 *)this_ptr + 0x48) = val;
}
PCREG(4b00d0, fn_4b00d0);

// 0x4d49b0: 6 insns, 15 bytes, thiscall: add offset, load, indirect jump through [eax+4]
void THISCALL fn_4d49b0(void *this_ptr) {
  void *eax = *(void **)((u8 *)this_ptr + 0x10db);
  typedef void (*fn_type)();
  ((fn_type)(*(void **)((u8 *)eax + 4)))();
}
PCREG(4d49b0, fn_4d49b0);
