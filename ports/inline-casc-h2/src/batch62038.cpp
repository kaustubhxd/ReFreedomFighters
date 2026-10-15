#include "ff.h"

extern "C" void THISCALL ext_518850(u8 *self);
extern "C" void THISCALL ext_512e10(u8 *self, u8 *out);
extern "C" void THISCALL ext_51fbe0(u8 *self);

static void THISCALL fn51fa60(u8 *self) {
  ext_518850(self);
  u8 *engine = G(u8 *, 0x70039c);
  u8 *table = *(u8 **)(engine + 0x9b);
  u8 *item = vcall<u8 *>(table, 0x58, *(u32 *)(self + 0x1654));
  ext_512e10(self + 0x16e5, self + 0x16d9);
  ext_51fbe0(self);
  u8 *resource = vcall<u8 *>(engine, 0x190);
  u8 *vt = *(u8 **)resource;
  u32 fn = *(u32 *)(vt + 0x184);
  u32 last = *(u32 *)(self + 0x16d5);
  asm volatile(
      "push %[last]\n\tpush $0x69ff58\n\tpush $0x14\n\tpush $2\n\tpush %[resource]\n\t"
      "mov %[vt], %%ecx\n\tcall *%[fn]\n\tadd $20, %%esp"
      : : [last] "r"(last), [resource] "r"((u32)resource), [vt] "r"((u32)vt), [fn] "r"(fn)
      : "eax", "ecx", "edx", "memory", "cc");
  (void)item;
}

PCREG(51fa60, fn51fa60);
