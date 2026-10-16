// batch8829.cpp - wire-hit-parts run 15 (2026-10-16): 0x641a40, ZRagdollContainer's debug variables (called by the ctor 0x640d40).
// A plain-C lift: the cascade's register-level lift (inline-casc-w2q2 batch200065 and its copies) passes the new object itself as
// 0x4d8330's third argument (`lea ecx, [esi + 0xc]; push ecx; ...; mov ecx, eax; call` lifted as push of the later ecx); its spec
// does not compare that argument. Here the argument is the variable's address, as in the exe.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void *ext_41e290(u32 size);                                         // operator new (cdecl; exe)
extern "C" u8 *THISCALL ext_4d8330(void *self, u32 name, u32 help, u32 value);  // debug variable ctor (name, help text, address of the value)

typedef void (THISCALL *vRegister)(void *self, void *var);

// 0x641a40 (thiscall, no arguments): three debug variables, "nailgun" -> this+0xc, "flymo" -> this+4, "forcemult" -> this+8; each
// is new(0x108) + 0x4d8330(name, 0, &value) (0 when new fails), stored unaligned at this+0x1d / +0x15 / +0x19 and handed to the engine
// object [0x70039c] slot 0x1a4 (registered even when 0). The exe's try frame (fs:[0], states 0 / 1 / 2 / -1) is not reproduced.
static void THISCALL registerDebugVars(u8 *self) {
  static const u32 name[3] = {0x6c2820, 0x6c2828, 0x6c2830};
  static const u32 val[3] = {0xc, 4, 8};
  static const u32 slot[3] = {0x1d, 0x15, 0x19};
  for (int i = 0; i < 3; i++) {
    void *p = ext_41e290(0x108);
    u8 *v = p ? ext_4d8330(p, name[i], 0, (u32)(self + val[i])) : 0;
    __builtin_memcpy(self + slot[i], &v, 4);
    void *eng = *(void **)0x70039c;
    ((vRegister)VT(eng, 0x1a4))(eng, v);
  }
}
PCREG(641a40, registerDebugVars);
