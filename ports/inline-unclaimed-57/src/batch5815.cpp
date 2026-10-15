// batch5815.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 115: 0x5c4e50 (GUESS name unnamed_5c4e50), thiscall, one stack argument obj (ret 4), returns al = 1.
// this+4 &= ~0x40; if the assert hook 0x7003b0 is set, call it; this+0x48 = 0x4e5e60(NULL); this+0x50 = 0x4e5e60(NULL); 0x4e6180(NULL, this+0x64);
// 0x4e6180(NULL, this+0x70); if this+0x50 > 5: this+0x50 = 5; n = this+0x50; arr = operator new(n*0x19) (overflow: 0xffffffff; cdecl, hooked); zero
// each entry's dword; this+0x4c = arr. For i < n (n re-read): ent = this+0x4c + 0x19*i; obj->vt[+0x58](ent); obj->vt[+0x40](&slot) where slot is the
// argument's own slot (the callee may write it); entry+4 = (engine)+0x9b ->vt[+0x58](slot); obj->vt[+0x48](ent+8); obj->vt[+0x6c](ent+0xc);
// obj->vt[+0x68](ent+0x18). Then this+0x58 = (this+0x44)->+0x18->vt[+0x14](). The reader and allocator run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);

extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e6180(u8 *db, u8 *out);  // float array reader, original code (hooked in the spec)
extern "C" void *ext_41e290(u32 size);  // operator new (cdecl), original code (hooked in the spec)

// 0x5c4e50, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5c4e50(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)(void))hook)();
  *(u32 *)(self + 0x48) = ext_4e5e60(0);
  *(u32 *)(self + 0x50) = ext_4e5e60(0);
  ext_4e6180(0, self + 0x64);
  ext_4e6180(0, self + 0x70);
  if ((s32)*(u32 *)(self + 0x50) > 5) *(u32 *)(self + 0x50) = 5;
  u32 n = *(u32 *)(self + 0x50);
  u32 sz;
  if (__builtin_mul_overflow(n, 0x19u, &sz)) sz = 0xffffffffu;
  u8 *arr = (u8 *)ext_41e290(sz);
  if (arr) {
    for (u32 i = 0; i < n; i++) *(u32 *)(arr + 0x19 * i) = 0;
  } else {
    arr = 0;
  }
  *(u32 *)(self + 0x4c) = (u32)(unsigned long)arr;
  u32 slot = (u32)(unsigned long)obj;  // the argument's own slot: the callee may write it, and later reads see the new value
  for (s32 i = 0; i < (s32)*(u32 *)(self + 0x50); i++) {
    u8 *ent = *(u8 **)(self + 0x4c) + 0x19 * i;
    ((SlotA)VT(obj)[0x58 / 4])(obj, (u32)(unsigned long)ent);
    ((SlotA)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)&slot);
    u8 *eng = G(u8 *, 0x70039c);
    u8 *sub = *(u8 **)(eng + 0x9b);
    *(u32 *)(ent + 4) = ((SlotA)VT(sub)[0x58 / 4])(sub, slot);
    ((SlotA)VT(obj)[0x48 / 4])(obj, (u32)(unsigned long)(ent + 8));
    ((SlotA)VT(obj)[0x6c / 4])(obj, (u32)(unsigned long)(ent + 0xc));
    ((SlotA)VT(obj)[0x68 / 4])(obj, (u32)(unsigned long)(ent + 0x18));
  }
  u8 *o = *(u8 **)(self + 0x44);
  u8 *holder = *(u8 **)(o + 0x18);
  *(u32 *)(self + 0x58) = ((SlotN)VT(holder)[0x14 / 4])(holder);
  return 1;
}
PCREG(5c4e50, unnamed5c4e50);
