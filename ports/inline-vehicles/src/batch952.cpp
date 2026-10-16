// batch952.cpp - residue-03 (core todo), batch 952: ZRelayMessageList deleting destructor, 0x4b8730, thiscall(flags), ret 4.
// The MSVC exception frame (fs:[0] writes) is not reproduced: it is not game state.
// Order: vtable 0x69289c; member at +0x4c gets its slot-0 call with 1 (when set); +0x44 and +0x30 cleared; vtable
// 0x686874; render manager slot 0x34 with this; then if flags&1: flags&4 -> operator delete(this, 0x58) (0x4690b0,
// a bare ret here), else the hook at 0x7003b0 (a null hook is an int3 in the exe).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);  // operator delete (cdecl, bare ret)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x4b8730 ZRelayMessageList::~ZRelayMessageList(flags).
static u8 *THISCALL relayListDtor(u8 *t, u32 flags) {
  void *member = (void *)D(t, 0x4c);
  D(t, 0x0) = 0x69289c;
  if (member)
    vcall<void>(member, 0, 1u);
  D(t, 0x44) = 0;
  D(t, 0x30) = 0;
  D(t, 0x0) = 0x686874;
  u8 *sys = *(u8 **)0x70039c;
  vcall<void>(*(void **)(sys + 0x9b), 0x34, (u32)t);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(t, 0x58);
    } else {
      void (*hook)() = *(void (**)())0x7003b0;
      if (!hook)
        __asm__ volatile("int3");
      hook();
    }
  }
  return t;
}
PCREG(4b8730, relayListDtor);
