// batch266.cpp - unclaimed area 26 (docs/20-unclaimed-26.md), residue-05 list.
#include "ff.h"

typedef void (__attribute__((thiscall)) *SlotOut_439bd0)(u8 *, u32 *);
typedef u32 (__attribute__((thiscall)) *SlotGet_439bd0)(u8 *, u32 *);
typedef void (__attribute__((thiscall)) *SlotOne_439bd0)(u8 *, u32);

// 0x439bd0: if the REFTAB argument (stack) is null, returns. Else t.vtbl[0x4c](&local); r = t.vtbl[0x64](&local); while
// r != 0: this.vtbl[4](this, r) and r = t.vtbl[0x64](&local). ret 4. GUESS: a walk over a reference table that calls
// back into this on each entry.
static void THISCALL overrideActions_439bd0(u8 *self, u32 table) {
    if (table == 0u) return;
    u8 *t = (u8 *)table;
    u32 local = 0u;
    ((SlotOut_439bd0)(*(void ***)t)[0x4c / 4])(t, &local);
    u32 r = ((SlotGet_439bd0)(*(void ***)t)[0x64 / 4])(t, &local);
    while (r != 0u) {
        ((SlotOne_439bd0)(*(void ***)self)[4 / 4])(self, r);
        r = ((SlotGet_439bd0)(*(void ***)t)[0x64 / 4])(t, &local);
    }
}
PCREG(439bd0, overrideActions_439bd0);
