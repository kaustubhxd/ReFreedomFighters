// batch273.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list.
#include "ff.h"

typedef void (__attribute__((thiscall)) *Slot0Out_4ce550)(u8 *, u32 *);
typedef u32 (__attribute__((thiscall)) *SlotOut_4ce550)(u8 *, u32 *);

// 0x4ce550(this, n): if this is null, returns 0. Else this.vtbl[0x4c](&local), x = this.vtbl[0x5c](&local); if local is
// zero, returns 0. Else: loop: if n is zero, return x; n--; x = this.vtbl[0x5c](&local); while local != 0; return 0.
// ret 4. GUESS: walks a sequence through an out-parameter iterator.
static u32 THISCALL walk_4ce550(u8 *self, u32 n) {
    if (self == 0) return 0u;
    u32 local = 0u;
    ((Slot0Out_4ce550)(*(void ***)self)[0x4c / 4])(self, &local);
    u32 x = ((SlotOut_4ce550)(*(void ***)self)[0x5c / 4])(self, &local);
    if (local == 0u) return 0u;
    for (;;) {
        if (n == 0u) return x;
        n--;
        x = ((SlotOut_4ce550)(*(void ***)self)[0x5c / 4])(self, &local);
        if (local == 0u) return 0u;
    }
}
PCREG(4ce550, walk_4ce550);
