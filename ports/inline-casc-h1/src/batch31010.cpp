#include "ff.h"

// 0x468310: 4 insns, 9 bytes, frame setup + tail-jump to 0x4702b0
void fn_468310() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x4702b0)();
}
PCREG(468310, fn_468310);

// 0x472450: 4 insns, 9 bytes, frame setup + tail-jump to 0x465870
void fn_472450() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x465870)();
}
PCREG(472450, fn_472450);

// 0x4bf4b0: 4 insns, 9 bytes, frame setup + tail-jump to 0x4c0e20
void fn_4bf4b0() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x4c0e20)();
}
PCREG(4bf4b0, fn_4bf4b0);

// 0x4bf4f0: 4 insns, 9 bytes, frame setup + tail-jump to 0x4c18b0
void fn_4bf4f0() {
  typedef void (*fn_type)();
  ((fn_type)(void *)0x4c18b0)();
}
PCREG(4bf4f0, fn_4bf4f0);
