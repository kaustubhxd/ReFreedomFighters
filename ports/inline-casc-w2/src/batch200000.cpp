// batch200000.cpp - w2 harness regression: 0x44b740 (SEH frame), already verified in batch90000; NOT a new ledger row.
#include "ff.h"

// ---------------------------------------------------------------- SEH (x86 MSVC C++ EH frame)
// The thread's exception list head is fs:[0] (NT_TIB.ExceptionList). An MSVC C++ EH frame links a
// registration record {next, handler, state} on the stack; the handler is a per-function thunk
// (mov eax, FuncInfo; jmp __CxxFrameHandler3) and state is the try level (-1 = no live object).
// 0x44b740 GUESS ZSoundObject::~ZSoundObject (cdecl helper, arg = the sound handle).
// Tells the sound system (engine object +0x1a9f, unaligned) to release the handle: vtable slot 0x118.
// The EH frame is empty (state stays -1) but is linked around the call, as the original does.
extern "C" void ZSoundObject_release(u32 handle) {
  volatile SehRecord reg;
  reg.next = seh_head();
  reg.handler = 0x669740;
  reg.state = -1;
  seh_set_head(&reg);
  void *snd;
  __builtin_memcpy(&snd, (u8 *)g_pSysInterface + 0x1a9f, 4);
  if (snd) vcall<void>(snd, 0x118, handle);
  seh_set_head(reg.next);
}
PCREG(44b740, ZSoundObject_release);
