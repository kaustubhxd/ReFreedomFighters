// batch123.cpp - three small clean functions reached from the climb tree (climb thread, batch 123).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);       // operator delete(p, size) (cdecl, CRT; the exe pushes size then ptr)
extern "C" u32 ext_41e290(u32 size);                  // __builtin_new (cdecl, one arg; original code)
extern "C" u32 ext_41e2c0(u32 size);                  // second allocator path (cdecl, one arg; original code)

// 0x4cbec0, MYSTR::~MYSTR() (GC map high). thiscall, void. The string's data pointer is at +0; when it does not point at
// the inline buffer (+4), the block is freed with size 1.
static void THISCALL mystrDtor(u8 *self) {
  void *p = *(void **)self;
  if (p != (void *)(self + 4))
    ext_634273(p, 1);
}
PCREG(4cbec0, mystrDtor);

// 0x6014a0, CHostInterface::alloc(unsigned int) (GC map high). stdcall, one arg (ret 4): returns the allocator's result.
static u32 STDCALL hostAlloc(u32 size) { return ext_41e290(size); }
PCREG(6014a0, hostAlloc);

// 0x54f870, unnamed (no GC match). stdcall with two stack args (ret 8); the second is not used; returns the second
// allocator path's result (ext_41e2c0 with the first argument).
static u32 STDCALL unnamed54f870(u32 a, u32 b) {
  (void)b;
  return ext_41e2c0(a);
}
PCREG(54f870, unnamed54f870);
