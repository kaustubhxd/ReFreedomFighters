// u18_05.cpp - area 18, group 5 (unclaimed-18 thread).
#include "ff.h"

extern "C" void THISCALL ext_4c14b0(void *self, void *dbread);  // ZSoundSegmentPitch::GetValues(DBREAD&) (ret 4; original code)

// 0x4bf4d0, ZSoundSegmentPitch::CopyEventDataBlock(DBREAD&) (GC map high). thiscall, one stack arg (ret 4). The exe
// tail-jumps to GetValues with the same argument.
static void THISCALL segmentPitchCopyEventDataBlock(u8 *self, void *dbread) { ext_4c14b0(self, dbread); }
PCREG(4bf4d0, segmentPitchCopyEventDataBlock);

// 0x54e090, _ZSoundBuffer::CopyWaveData() (GC map medium). thiscall, one stack arg (ret 4); returns (dword at +0x5d != 0)
// in AL. The argument is not used.
static bool THISCALL soundBufferCopyWaveData(u8 *self, void *arg) {
  (void)arg;
  return *(u32 *)(self + 0x5d) != 0;
}
PCREG(54e090, soundBufferCopyWaveData);

// 0x56b410, CLoadMenu::CopyData(ZEventBase*) (GC map high). thiscall, one stack arg (ret 4). Copies the dword at +0xcee
// from the event block (the argument) into this.
static void THISCALL loadMenuCopyData(u8 *self, u8 *ev) { *(u32 *)(self + 0xcee) = *(u32 *)(ev + 0xcee); }
PCREG(56b410, loadMenuCopyData);
