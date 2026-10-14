// batch872.cpp - area 50 (residue-09 candidate): 0x519950 [42 instr, thiscall, one stack arg (an object whose +8 leads to a
// record), ret 4; no name in the map (GUESS "store a value into a record whose state is 0 or 2, else assert")]. The value is the
// float that this+0x14's vt +0x2d4 returns; the record comes from the accessor 0x5003d0 (stood in) on arg+8; when its state byte
// (+4) is 0 or 2 the float is stored at the record and the state becomes 2. Otherwise an assertion line is printed (logger
// 0x700390, file 0x69c8e0, line 0xd5, format 0x69c6b0 with 0x69c938) and the assert hook at 0x7003b0 is called when set.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" u8 *THISCALL ext_5003d0(void *obj, u32 idx);   // accessor (stood in by the harness)

// 0x519950 (name GUESS).
static void THISCALL Store519950(u8 *self, u8 *arg) {
  u8 *obj = (u8 *)FP(self, 0x14);
  float f = vcall<float>(obj, 0x2d4);
  u8 *rec = ext_5003d0(FP(arg, 8), 0);      // the exe loads [arg+8] into ECX
  u8 st = U8(rec, 4);
  if (st == 0 || st == 2) {
    *(float *)rec = f;
    U8(rec, 4) = 2;
    return;
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *sink = vcall<u8 *>(lg, 0x20, (u32)0x69c8e0, 0xd5u);
  typedef void (*printf_t)(void *, const char *, const char *);
  (*(printf_t *)(*(u8 **)sink + 0x2c))(sink, (const char *)0x69c6b0, (const char *)0x69c938);
  typedef void (*hook_t)(void);
  hook_t hook = *(hook_t *)0x7003b0;
  if (hook) hook();
}
PCREG(519950, Store519950);
