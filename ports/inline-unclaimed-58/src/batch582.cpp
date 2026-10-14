// batch582.cpp - unclaimed area 58 (docs/20-unclaimed-58.md), slice floor(addr/16) mod 20 == 17. Walks entries from a
// vtable and compares names with a string.
#include "ff.h"

typedef void(THISCALL *Vt4c)(u8 *, u32);     // slot 0x4c: out flag through a pointer argument (result unused)
typedef u8 *(THISCALL *Vt5c)(u8 *, u32);     // slot 0x5c: out flag through a pointer argument, returns an entry

// strcmp-equality as the asm does it (two bytes per step, stop at the NUL): returns true when equal.
static bool strEqual(const u8 *a, const u8 *b) {
  while (true) {
    if (*a != *b) return false;
    if (*a == 0) return true;
    if (a[1] != b[1]) return false;
    if (a[1] == 0) return true;
    a += 2;
    b += 2;
  }
}

// 0x438b10, thiscall(s) ret 4. If s is null, or [this+0x19] is null, return 0. obj = [this+0x19]; obj->vtable[0x4c](obj,
// &flag). Then esi = obj->vtable[0x5c](obj, &flag); if flag == 0, return 0. Loop: if esi and [esi+4] (name) is set and
// strEqual(s, name), return esi. Otherwise esi = obj->vtable[0x5c](obj, &flag) again, and stop with 0 when flag == 0.
// Name GUESS (find an entry by name).
static u8 *THISCALL findEntryByName_438b10(u8 *self, const u8 *s) {
  if (!s) return nullptr;
  u8 *obj = *(u8 **)(self + 0x19);
  if (!obj) return nullptr;
  u32 flag = 0;
  Vt4c f4c = (Vt4c)(*(u32 *)(*(u32 *)obj + 0x4c));
  f4c(obj, (u32)&flag);
  obj = *(u8 **)(self + 0x19);
  Vt5c f5c = (Vt5c)(*(u32 *)(*(u32 *)obj + 0x5c));
  u8 *esi = f5c(obj, (u32)&flag);
  if (!flag) return nullptr;
  while (true) {
    if (esi && *(const u8 **)(esi + 4)) {
      if (strEqual(s, *(const u8 **)(esi + 4))) return esi;
    }
    obj = *(u8 **)(self + 0x19);
    f5c = (Vt5c)(*(u32 *)(*(u32 *)obj + 0x5c));
    esi = f5c(obj, (u32)&flag);
    if (!flag) return nullptr;
  }
}
PCREG(438b10, findEntryByName_438b10);
