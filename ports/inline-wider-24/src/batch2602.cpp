// batch2602.cpp - wider batch 2602. 0x434d10 (GUESS list find): thiscall(arg), ret 4, returns the first element object whose slot 0x14(arg)
// is true. The member at this+4 is an iterator source: slot 0x4c (begin, &local), slot 0x64 (next, &local) returns a pointer to a cell that holds
// the element object (the exe dereferences it once). Null arg or null member returns 0. The member pointer is reloaded from this+4 on each
// iteration, as in the original.
#include "ff.h"

typedef void(THISCALL *vbegin_t)(void *, void *);
typedef void **(THISCALL *vnext_t)(void *, void *);
typedef u32(THISCALL *vtest_t)(void *, u32);

static void *THISCALL listFind(u8 *self, u32 arg) {
  u32 local[3];
  if (!arg) return 0;
  void *m = *(void **)(self + 4);
  if (!m) return 0;
  (*(vbegin_t **)m)[0x4c / 4](m, local);
  m = *(void **)(self + 4);
  void **cell = (*(vnext_t **)m)[0x64 / 4](m, local);
  while (cell) {
    void *o = *cell;
    if ((*(vtest_t **)o)[0x14 / 4](o, arg) & 0xff) return o;
    m = *(void **)(self + 4);
    cell = (*(vnext_t **)m)[0x64 / 4](m, local);
  }
  return 0;
}
PCREG(434d10, listFind);
