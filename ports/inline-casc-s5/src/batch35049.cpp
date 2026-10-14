// batch35049.cpp - cascade s5 batch 35049: 0x513340 (GUESS test whether an object is in a given state, through its virtual predicates).
#include "ff.h"

typedef u8(THISCALL *b1_t)(void *, u32);
typedef u8(THISCALL *b0_t)(void *);
typedef u32(THISCALL *g0_t)(void *);

// 0x513340, stdcall(o) ret 4, returns a bool in AL. o slot 0x1e0(0x2007d0) true: slot 0x438() true gives 1; else slot 0x674() == 0 gives 1; else slot 0x670() true gives 1, false gives 0.
// o slot 0x1e0(0x2007d0) false: when slot 0x1e0(0x80200014) is true the result is slot 0x438() (AL as returned), otherwise 0.
static u8 STDCALL fn513340(u8 *o) {
  if ((*(b1_t **)o)[0x1e0 / 4](o, 0x2007d0)) {
    if ((*(b0_t **)o)[0x438 / 4](o)) return 1;
    if (!(*(g0_t **)o)[0x674 / 4](o)) return 1;
    if ((*(b0_t **)o)[0x670 / 4](o)) return 1;
    return 0;
  }
  if ((*(b1_t **)o)[0x1e0 / 4](o, 0x80200014)) return (*(b0_t **)o)[0x438 / 4](o);
  return 0;
}
PCREG(513340, fn513340);
