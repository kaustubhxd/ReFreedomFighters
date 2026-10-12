// batch803.cpp - unclaimed-08 batch 3: ZFFActor::PullWeapon (player weapon pull). Area 08 slice: floor(addr/16) mod 20 = 7.
// The original's SEH frame (fs:[0] prologue) is not reproduced: it has no effect on heap or globals. Callees:
// 0x4cc1d0 is `mov eax,[ecx]; ret` (inlined); 0x4cbec0 (a destructor that calls CRT 0x634273 only when the list
// is not empty) is bound to the original code.
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *);

// 0x5a2370, ZFFActor::PullWeapon(int) (high). `which` (the stack argument) picks the field: nonzero -> this+0x78e,
// zero -> this+0x78a. If that field is zero, one debug line is logged through the logger (0x700390, vtable +0x20 with
// file 0x6ae6a0 and line 0x37e; the returned object gets vtable +0x2c with the message). Then the predicate at vtable
// +0x6b4 is called with the field; when it returns false, vtable +0x6d0 is called with the same field.
static void THISCALL zffActorPullWeapon(u8 *self, u32 which) {
  u32 field = which ? *(u32 *)(self + 0x78e) : *(u32 *)(self + 0x78a);
  if (field == 0) {
    void *logger = *(void **)0x700390;
    u8 *out = (u8 *)vcall<void *>(logger, 0x20, (const char *)0x6ae6a0, (u32)0x37e);
    u8 local[0x80];
    // Local object: 0x1d8 fills it (out pointer and a flag 1) and returns the object to print.
    u8 *msg = (u8 *)vcall<void *>(self, 0x1d8, (void *)local, (u32)1);
    const char *text = *(const char **)msg;  // 0x4cc1d0 inlined
    typedef void(__attribute__((cdecl)) * logfn)(void *, const char *, const char *);
    logfn log = *(logfn *)(*(u8 **)out + 0x2c);
    log(out, (const char *)0x6ae9dc, text);
    ext_4cbec0(local);
  }
  if (!vcall<u8>(self, 0x6b4, field)) vcall<void>(self, 0x6d0, field);
}
PCREG(5a2370, zffActorPullWeapon);
