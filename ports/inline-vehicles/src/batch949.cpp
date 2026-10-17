// batch949.cpp - vehicles thread, batch 949: ZHeli::Save(ZSaveGame*), 0x51cbd0, callee pops 4, returns bool.
// The header (0x513ff0, stood in) first; on failure return 0. The first vector save (0x68 at +0x216) passes the caller's
// EDI as its second argument: the exe never sets EDI in this function, so the value is whatever the caller left in it.
// That is read at entry with inline asm (the checker fixes it at 0x0badf00d). Remaining stand-ins: 0x527190 (six calls,
// one argument each), 0x5274f0, 0x516e20, 0x513f50.
#include "ff.h"

extern "C" u8 THISCALL ext_513ff0(void *self, void *sg);     // ZMoveOnSpline save header (stood in)
extern "C" void THISCALL ext_527190(void *p, void *sg);      // sub-object save (stood in)
extern "C" void THISCALL ext_5274f0(void *p, void *sg);      // turret save (stood in)
extern "C" void THISCALL ext_516e20(void *p, void *sg);      // weapon save (stood in)
extern "C" void THISCALL ext_513f50(void *p, void *sg);      // sub-object save (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))
#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x51cbd0 ZHeli::Save(ZSaveGame*).
static u8 THISCALL heliSave(u8 *s, void *sg) {
  u32 entryEdi;
  __asm__ volatile("movl %%edi, %0" : "=r"(entryEdi));
  if (!ext_513ff0(s, sg))
    return 0;
  // The callee pops 4 (ret 4 like every 0x68), but the exe pushes two values here: the vector pointer and EDI. The
  // second dword is left on the stack until the epilogue, so the call is written out with the cleanup after it.
  {
    void *fn = *(void **)(*(u8 **)sg + 0x68);
    __asm__ volatile("push %1\n\tpush %2\n\tcall *%3\n\tadd $4, %%esp"
                     : "+c"(sg) : "r"(entryEdi), "r"(s + 0x216), "r"(fn) : "eax", "edx", "memory", "cc");
  }
  vcall<void>(sg, 0x68, (u32)(s + 0x222));
  vcall<void>(sg, 0x4c, F(s, 0x22e));
  vcall<void>(sg, 0x4c, F(s, 0x232));
  vcall<void>(sg, 0x4c, F(s, 0x236));
  vcall<void>(sg, 0x4c, F(s, 0x23a));
  vcall<void>(sg, 0x68, (u32)(s + 0x23e));
  vcall<void>(sg, 0x68, (u32)(s + 0x24a));
  vcall<void>(sg, 0x68, (u32)(s + 0x256));
  vcall<void>(sg, 0x68, (u32)(s + 0x3f1));
  vcall<void>(sg, 0x68, (u32)(s + 0x262));
  vcall<void>(sg, 0x4c, F(s, 0x26e));
  vcall<void>(sg, 0x4c, F(s, 0x272));
  vcall<void>(sg, 0x68, (u32)(s + 0x276));
  vcall<void>(sg, 0x68, (u32)(s + 0x282));
  vcall<void>(sg, 0x68, (u32)(s + 0x28e));
  ext_527190(s + 0x29a, sg);
  ext_527190(s + 0x2c3, sg);
  ext_527190(s + 0x2ec, sg);
  ext_527190(s + 0x315, sg);
  vcall<void>(sg, 0x4c, F(s, 0x33e));
  vcall<void>(sg, 0x4c, F(s, 0x342));
  vcall<void>(sg, 0x4c, F(s, 0x346));
  vcall<void>(sg, 0x3c, D(s, 0x34a));
  ext_5274f0(s + 0x34e, sg);
  ext_527190(s + 0x39f, sg);
  ext_527190(s + 0x3c8, sg);
  vcall<void>(sg, 0x3c, D(s, 0x3fd));
  vcall<void>(sg, 0x3c, D(s, 0x44d));
  vcall<void>(sg, 0x68, (u32)(s + 0x45d));
  vcall<void>(sg, 0x44, D(s, 0x469));
  vcall<void>(sg, 0x3c, D(s, 0x479));
  ext_516e20(s + 0x4ad, sg);
  vcall<void>(sg, 0x10, (u32)(s + 0x526), 0x6du);
  vcall<void>(sg, 0x4c, F(s, 0x593));
  vcall<void>(sg, 0x4c, F(s, 0x597));
  vcall<void>(sg, 0x3c, D(s, 0x491));
  vcall<void>(sg, 0x3c, D(s, 0x495));
  vcall<void>(sg, 0x3c, D(s, 0x499));
  vcall<void>(sg, 0x3c, D(s, 0x49d));
  vcall<void>(sg, 0x3c, D(s, 0x4a1));
  vcall<void>(sg, 0x44, D(s, 0x4a5));
  vcall<void>(sg, 0x4c, F(s, 0x4a9));
  // Five pairs: the first is [edi-0x14], the second [edi], then edi += 4.
  for (u32 i = 0; i < 5; i++) {
    vcall<void>(sg, 0x64, D(s, 0x411 + 4 * i));
    vcall<void>(sg, 0x64, D(s, 0x425 + 4 * i));
  }
  // Four singles from this+0x439.
  for (u32 i = 0; i < 4; i++)
    vcall<void>(sg, 0x64, D(s, 0x439 + 4 * i));
  ext_513f50(s + 0x59b, sg);
  return 1;
}
PCREG(51cbd0, heliSave);
