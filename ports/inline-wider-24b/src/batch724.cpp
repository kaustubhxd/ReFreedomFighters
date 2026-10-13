// batch724.cpp - soldier AI, batch 724 (2026-10-11): ZFFActorIf::IsVisible(OpaqueCallParameters_t&), the script native
// "is this actor visible to the other?" Parameters are read with the accessor 0x5003d0 (index into a two-level list of
// 8-byte items, the value is the item's first dword); the answer is written to output 0 with the setter 0x5002f0
// (value dword, type byte set to 1). The message "Msg_CheckVisibleTo" goes to the actor object (this+0x1c) through
// slot 0x678 with the first parameter's value; its result goes to slot 0x12c. The answer is the local byte
// initialised to 0 (the original never writes it), so the native reports 0.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 index);      // parameter accessor: pointer to the item
extern "C" void THISCALL ext_5002f0(void *item, u32 value);       // typed setter (ret 4)

static inline void *db() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x55b330 ZFFActorIf::IsVisible(OpaqueCallParameters_t& args) [medium].
static void THISCALL ffactorif_IsVisible(u8 *self, u8 *args) {
  u32 dataVal = *ext_5003d0(*(void **)(args + 4), 0);
  (void)*ext_5003d0(*(void **)(args + 4), 1);
  u8 *obj = *(u8 **)(self + 0x1c);
  u8 vis = 0;
  u16 id = vcall<u16>(db(), 0x114, (const char *)0x690518, 0u, (const char *)0x6a5eb0, 0x25eu);
  u32 r = vcall<u32>(obj, 0x678, (u32)id, &dataVal);
  vcall<void>(obj, 0x12c, r);
  u32 out = vis;
  ext_5002f0(ext_5003d0(*(void **)(args + 8), 0), out);
}
PCREG(55b330, ffactorif_IsVisible);
