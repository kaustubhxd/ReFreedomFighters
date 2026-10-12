// batch6310.cpp - unclaimed-63 batch 10 (docs/20-unclaimed-63.md): ResourceCollection::GetResource(const char*, Resource*) at
// 0x49df60 (GC name, high). Body: e = [this+4]; if e == 0 return 0. r = 0x49e140(ECX = this; name, e) (thiscall, two stack
// arguments, original). If r: 0x49e260(ECX = out; name) (original, one stack argument, callee pops 4); [out] = r; return out. Else: L = [0x700390]->vtbl[+0x20]
// (0x68f018, 0xdd); then the logger's vtbl[+0x30] with ECX = *L and three stack arguments (L, 0x68f040, name), caller cleans
// 12 bytes; return 0. The PC's logger call is made in asm, because the caller cleans.
#include "ff.h"

extern "C" u32 THISCALL ext_49e140(void *self, u8 *name, u32 e);   // original, stubbed by the spec
extern "C" void THISCALL ext_49e260(void *self, u8 *name);       // original, one stack argument (name), stubbed by the spec

typedef u32(THISCALL * call2_fn)(void *, u32, u32);

// 0x49df60 (high). The asm call takes ECX = *L and pushes name, 0x68f040, L, then 'add $12, %esp'.
static u32 THISCALL resourceCollectionGetResource(u8 *self, u8 *name, u8 *out) {
  u32 e = *(u32 *)(self + 4);
  if (e == 0)
    return 0;
  u32 r = ext_49e140(self, name, e);
  if (r != 0) {
    ext_49e260(out, name);
    *(u32 *)out = r;
    return (u32)out;
  }
  u32 g = G(u32, 0x700390);
  u32 logger = ((call2_fn)(*(u32 *)(*(u32 *)g + 0x20)))((void *)g, 0x68f018, 0xdd);
  u32 vl = *(u32 *)logger;
  u32 target = *(u32 *)(vl + 0x30);
  asm volatile("push %[n]\n\tpush $0x68f040\n\tpush %[l]\n\tcall *%[fn]\n\tadd $12, %%esp"
               :
               : "c"(vl), [n] "r"(name), [l] "r"(logger), [fn] "r"(target)
               : "eax", "edx", "memory", "cc");
  return 0;
}
PCREG(49df60, resourceCollectionGetResource);
