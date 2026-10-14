// u18_12.cpp - core-todo residue 17 (unclaimed-18 thread): two CopyEventDataBlock functions. The DBREAD readers are claimed
// by other threads; they are called here as original code (hooked in the spec).
#include "ff.h"

extern "C" u16 THISCALL ext_4e5e40(void *db);                  // DBREAD::operator unsigned short() (other thread)
extern "C" u32 THISCALL ext_4e5e60(void *db);                  // DBREAD::operator unsigned int() (other thread)
extern "C" void THISCALL ext_4e6330(void *db, void *refTab);   // DBREAD::GetRefTab(REFTAB*) (ret 4; original code)

static inline u8 *sys() { return G(u8 *, 0x70039c); }

// 0x4b8590, ZRelayMessage::CopyEventDataBlock(DBREAD&) (GC map medium). thiscall, one stack arg (ret 4): two words then a
// dword read from the block into +0x48, +0x4a, +0x4c.
static void THISCALL relayMessageCopyEventDataBlock(u8 *self, u8 *db) {
  *(u16 *)(self + 0x48) = ext_4e5e40(db);
  *(u16 *)(self + 0x4a) = ext_4e5e40(db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
}
PCREG(4b8590, relayMessageCopyEventDataBlock);

// 0x5c4150, ZRepositionCharacter::CopyEventDataBlock(DBREAD&) (GC map high). thiscall, one stack arg (ret 4). Reads a
// dword (a name id); the engine (sys+0x9b) turns it into an object through slot 0x58, stored at +0x50. Then the block's
// reference table is read with the dword at +0x48 as argument, and +0x4c is cleared.
static void THISCALL repositionCharacterCopyEventDataBlock(u8 *self, u8 *db) {
  u32 id = ext_4e5e60(db);
  u8 *engine = *(u8 **)(sys() + 0x9b);
  *(u32 *)(self + 0x50) = vcall<u32>(engine, 0x58, id);
  ext_4e6330(db, (void *)*(u32 *)(self + 0x48));
  *(u32 *)(self + 0x4c) = 0;
}
PCREG(5c4150, repositionCharacterCopyEventDataBlock);
