// u18_09.cpp - area 18, group 9 (unclaimed-18 thread).
#include "ff.h"

// 0x59c510, ZFFSaveDeviceInterface::RemoveFileFromLoadList(const char*) (GC map medium). thiscall, one stack arg (ret 4).
// The exe adds 0x1218c to this and tail-jumps to slot 0x90 of the sub-object there (embedded, its vtable is its first dword)
// with the same argument (the callee pops it).
static void THISCALL removeFileFromLoadList(u8 *self, const char *name) {
  vcall<void>(self + 0x1218c, 0x90, name);
}
PCREG(59c510, removeFileFromLoadList);

// 0x65f200, unnamed (GUESS: a flag set on an object passed as argument). thiscall with one stack arg (ret 4); the `this`
// is not used. Sets bit 2 of the dword at +0x24 of the argument.
static void THISCALL setBit2OfArgument(u8 *unused, u8 *obj) {
  (void)unused;
  *(u32 *)(obj + 0x24) |= 4u;
}
PCREG(65f200, setBit2OfArgument);
