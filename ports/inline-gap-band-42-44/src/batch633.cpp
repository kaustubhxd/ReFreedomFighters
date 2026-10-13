// batch633.cpp - band 0x421000-0x441000, batch 633: one function.
//   0x426660 (stdcall, one void* argument): calls ext_676070(arg); if nonzero, returns it;
//     else logs via logger object at 0x700390 (thiscall slot 0x20, then cdecl slot 0x2c).
#include "ff.h"

typedef u32(STDCALL *ext_676070_t)(void *arg);
typedef void *(THISCALL *slot_20_t)(void *self, u32 line, void *str);
typedef void(*slot_2c_t)(void *result, void *fmt, u32 arg);

static u32 STDCALL closeFile(void *p) {
  ext_676070_t ext_fn = (ext_676070_t)G(void *, 0x676070);
  u32 r = ext_fn(p);
  if (r != 0)
    return r;
  // Logging path: call logger object
  void *logger = G(void *, 0x700390);
  void **vtable = *(void ***)logger;
  void *res = ((slot_20_t)vtable[0x20 / 4])(logger, 0x53, (void *)0x6789ac);
  // Call slot 0x2c of res (loaded into ecx for addressing, but called as cdecl)
  ((slot_2c_t)(*(void ***)res)[0x2c / 4])(res, (void *)0x678abc, (u32)p);
  return 0; // eax undefined on failure path
}
PCREG(426660, closeFile);
