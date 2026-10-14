// batch241.cpp - ZFFHERO::SendInventoryFull (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_59a580(void *osd, const char *msg, u32 colour, u32 sound);   // ZGameOSD::MessageAdd

// 0x594e30 ZFFHERO::SendInventoryFull(ZItem *item) [, medium], thiscall, ret 4.
// Throttle: when the last item was the same and its time (float +0x957 * 1024, truncated) is at or after the engine tick
// [engine+0x40], nothing happens. Otherwise, when the OSD (+0x852) exists, it shows the text "InventoryFull" from the
// localised table (database +0xae4 slot 0, keys "Menu/HelpText", "InventoryFull") in colour 0xffffff00 with sound 1.
// Then it stores the item (+0x953) and the next allowed time: (tick + 3072) / 1024 (3072 = 3 seconds of 1/1024 ticks).
static void THISCALL heroSendInventoryFull(u8 *self, u32 item) {
  u8 *eng = (u8 *)G(u32, 0x70039c);
  if (U32(self, 0x953) == item) {
    s32 t = _mm_cvttss_si32(_mm_set_ss(F32(self, 0x957) * 1024.0f));
    if (t >= (s32)U32(eng, 0x40))
      return;
  }
  u8 *osd = (u8 *)U32(self, 0x852);
  if (osd) {
    u8 *db = (u8 *)U32(eng, 0x9b);
    void *table = (void *)U32(db, 0xae4);
    const char *text = vcall<const char *>(table, 0, (const char *)0x6a67e8, (const char *)0x6acea8);
    ext_59a580(osd, text, 0xffffff00u, 1);
  }
  U32(self, 0x953) = item;
  F32(self, 0x957) = (float)((s32)U32(eng, 0x40) + 0xc00) * 0.0009765625f;
}
PCREG(594e30, heroSendInventoryFull);
