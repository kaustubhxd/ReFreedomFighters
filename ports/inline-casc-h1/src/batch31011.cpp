#include "ff.h"

// 0x4e11d0: 4 insns, 9 bytes, frame setup + tail-jump to 0x4e1110
void fn_4e11d0() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x4e1110)();
}
PCREG(4e11d0, fn_4e11d0);

// 0x4fc130: 4 insns, 9 bytes, frame setup + tail-jump to 0x4fd510
void fn_4fc130() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x4fd510)();
}
PCREG(4fc130, fn_4fc130);

// 0x513180: 4 insns, 9 bytes, frame setup + tail-jump to 0x45f070
void fn_513180() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x45f070)();
}
PCREG(513180, fn_513180);

// 0x536260: 4 insns, 15 bytes, load field, test, conditional jump
void THISCALL fn_536260(void *this_ptr) {
  u32 ecx = *(u32 *)((u8 *)this_ptr + 0x52fa);
  if (ecx != 0) {
    typedef void (THISCALL *fn_type)(void *);
    ((fn_type)(void *)0x53b100)(this_ptr);
  }
}
PCREG(536260, fn_536260);
