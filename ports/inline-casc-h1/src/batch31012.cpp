#include "ff.h"

// 0x565a30: 4 insns, 9 bytes, frame setup + tail-jump to 0x57f350
void fn_565a30() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x57f350)();
}
PCREG(565a30, fn_565a30);

// 0x5a7550: 4 insns, 9 bytes, frame setup + tail-jump to 0x5a76c0
void fn_5a7550() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x5a76c0)();
}
PCREG(5a7550, fn_5a7550);

// 0x5f0160: 4 insns, 9 bytes, frame setup + tail-jump to 0x5ed0b0
void fn_5f0160() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x5ed0b0)();
}
PCREG(5f0160, fn_5f0160);

// 0x45d5b0: 5 insns, 9 bytes, frame setup + indirect jump through [eax+0x48]
void THISCALL fn_45d5b0(void *this_ptr) {
  void *eax = *(void **)this_ptr;
  typedef void (*fn_type)();
  ((fn_type)(*(void **)((u8 *)eax + 0x48)))();
}
PCREG(45d5b0, fn_45d5b0);
