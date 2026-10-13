// batch729.cpp - soldier AI, batch 729 (2026-10-12): two small natives.
//   ZCharisma::Command(unsigned short cmd, void* data) (0x5b7900): if cmd equals the word at +0x4c, the game OSD is fetched
//   from the engine record (gl = 0x7003b8) with (0, 8, &tmp, 0, id) where id = +0x48 and tmp is three zeroed dwords, then
//   ZGameOSD::CharismaAddExperience runs on it. Returns 0.
//   CActorActionMarker::Remove(ZCTRLIKLNKOBJ* obj) (0x5eac30): the marker keeps a count at +0x44 and an array of record
//   pointers from +4. The record whose first dword equals obj is replaced by the last record (16 bytes, the dword at +0x10
//   and the byte at +0x14), and the count drops by one. Nothing happens when the record is absent or last.
#include "ff.h"

struct MarkerRec { u8 b[0x15]; };   // 16 bytes at +0, dword at +0x10, byte at +0x14

extern "C" void *THISCALL ext_589c20(void *gl, u32 a0, u32 a1, void *a2, u32 a3, u32 a4);   // ZFFGameData::GetGameOSD
extern "C" void THISCALL ext_596940(void *osd);                                              // ZGameOSD::CharismaAddExperience

static inline void *gameRecord() { return *(void **)0x7003b8; }

// 0x5b7900 ZCharisma::Command(unsigned short cmd, void* data) [high].
static u32 THISCALL charisma_Command(u8 *self, u32 cmd, void *data) {
  (void)data;
  if ((u16)cmd == *(u16 *)(self + 0x4c)) {
    u32 tmp[3] = {0, 0, 0};
    void *osd = ext_589c20(gameRecord(), 0u, 8u, tmp, 0u, *(u32 *)(self + 0x48));
    ext_596940(osd);
  }
  return 0;
}
PCREG(5b7900, charisma_Command);

// 0x5eac30 CActorActionMarker::Remove(ZCTRLIKLNKOBJ* obj) [medium].
static void THISCALL marker_Remove(u8 *self, void *obj) {
  u32 n = *(u32 *)(self + 0x44);
  if (!n)
    return;
  u32 **arr = (u32 **)(self + 4);
  u32 k = 0;
  while (k < n && *(void **)arr[k] != obj)
    k++;
  if (k == n)
    return;
  if (k != n - 1) {
    MarkerRec *last = (MarkerRec *)arr[n - 1];
    MarkerRec *dst = (MarkerRec *)arr[k];
    for (int i = 0; i < 16; i++)
      ((u8 *)dst)[i] = ((u8 *)last)[i];
    *(u32 *)((u8 *)dst + 0x10) = *(u32 *)((u8 *)last + 0x10);
    ((u8 *)dst)[0x14] = ((u8 *)last)[0x14];
  }
  *(u32 *)(self + 0x44) = n - 1;
}
PCREG(5eac30, marker_Remove);
