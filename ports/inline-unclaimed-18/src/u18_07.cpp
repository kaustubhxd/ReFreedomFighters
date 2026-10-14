// u18_07.cpp - area 18, group 7 (unclaimed-18 thread).
#include "ff.h"

extern "C" void THISCALL ext_4cce40(void *self);   // LINKSORTREFTAB base cleanup (original code; hooked in spec)
extern "C" void THISCALL ext_51b020(void *self);   // ZPmvIf base cleanup (original code; hooked in spec)
extern "C" void ext_634273(void *p, u32 size);     // operator delete(p, size) (cdecl)

// 0x4cd210, LINKSORTREFTAB::~LINKSORTREFTAB() (GC map high). Scalar deleting destructor: thiscall, one stack arg (flags,
// ret 4), returns this. vtable 0x6959f8, base cleanup, then the block (size 0x2c) is freed when the flag's bit 0 is set.
static u8 *THISCALL linkSortRefTabDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6959f8u;
  ext_4cce40(self);
  if (flags & 1)
    ext_634273(self, 0x2c);
  return self;
}
PCREG(4cd210, linkSortRefTabDtor);

// 0x51fc90, ZPmvIf::~ZPmvIf() (GC map high). Scalar deleting destructor, as above: vtable 0x69fff4, base 0x51b020,
// block size 0x24.
static u8 *THISCALL pmvIfDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x69fff4u;
  ext_51b020(self);
  if (flags & 1)
    ext_634273(self, 0x24);
  return self;
}
PCREG(51fc90, pmvIfDtor);

// 0x4cf150, LINKREFTAB::RunInitPrevRef(RefRun*) (GC map high). thiscall, one stack arg (ret 4). The run record gets
// index -1 at +4 and 0 at +0; the flag bit 31 of the dword at this+0xc is cleared.
static void THISCALL linkRefTabRunInitPrevRef(u8 *self, u8 *run) {
  *(u32 *)(run + 4) = 0xffffffffu;
  *(u32 *)run = 0;
  *(u32 *)(self + 0xc) &= 0x7fffffffu;
}
PCREG(4cf150, linkRefTabRunInitPrevRef);
