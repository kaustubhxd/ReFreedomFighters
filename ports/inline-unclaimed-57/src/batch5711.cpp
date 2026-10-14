// batch5711.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 11: two stdcall helpers that call the assert hook (global 0x7003b0)
// with no arguments when it is non-null, then return al = 0. 0x4ced80 takes one stack argument (ret 4); 0x4d4f00 takes two (ret 8).
// Names: 0x4ced80 medium (STATICREFTAB::RemoveIfExists), 0x4d4f00 low (ZBigFile::Add); the arguments are unused by the body.
// The assert hook is an unverified callee, stubbed (logging) in the spec.
#include "ff.h"

#define G(T, addr) (*(T *)(addr))

// 0x4ced80, STATICREFTAB::RemoveIfExists(unsigned int) (GUESS on the class; medium)
static u8 STDCALL staticRefTabRemoveIfExists(u32 id) {
  (void)id;
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)())hook)();
  return 0;
}
PCREG(4ced80, staticRefTabRemoveIfExists);

// 0x4d4f00, ZBigFile::Add(const char*, char*) (low)
static u8 STDCALL bigFileAdd(const char *a, char *b) {
  (void)a;
  (void)b;
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)())hook)();
  return 0;
}
PCREG(4d4f00, bigFileAdd);
