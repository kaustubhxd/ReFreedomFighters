#include "ff.h"

// 0x410100: 5 insns, cdecl(param): dereference parameter and read byte at offset 4
u8 fn_410100(u8 *param) {
  return param[4];
}
PCREG(410100, fn_410100);
