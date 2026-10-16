// batch509.cpp - weapons thread, batch 509: weapon switching through the item wheel (ZGameOSD).
// ZGameOSD fields: +0x1d0f the on-screen-display object (ZOnScreenDisplay), +0x1d47 last wheel selection.
// ZOnScreenDisplay wheel state: +0x37d a 0x45-byte pocket table, +0x3c2 selected pocket (0..7, 8 = none),
// +0x3c6 wheel shown. Pocket table (offsets into the 0x45 bytes): message ids at +0x00, +0x04, +0x08, +0x0c, +0x15,
// +0x19; items at +0x25, +0x29, +0x2d, +0x31, +0x35, +0x39, +0x3d, +0x41; +0x1d a state for pocket 6 (2 = disabled).
#include "ff.h"

extern "C" u32 THISCALL ext_4f9680(void *guiSound, u32 set);          // ZGui_Sound::PlaySound
extern "C" void THISCALL ext_5ab230(void *osd, u32 msg);              // ZOnScreenDisplay::WheelMessage(unsigned)
extern "C" void THISCALL ext_5ab2a0(void *osd, const char *msg);      // ZOnScreenDisplay::WheelMessage(char*)
extern "C" void THISCALL ext_5ab130(void *osd, u32 cmd);              // ZOnScreenDisplay::WheelInventoryCommand
extern "C" u32 THISCALL ext_5e9b70(u8 *self);                         // ZGameOSD::WheelInventoryGetItem

static inline u32 at(const u8 *l, u32 o) { return *(const u32 *)(l + o); }

// 0x5e9b70 ZGameOSD::WheelInventoryGetItem(): the item in the selected pocket (0 for an empty pocket or none), with
// the pocket's name shown as the wheel message ("" otherwise) and a GUI click (ZGui_Sound set 0, object 0x700e24)
// when the selection changed to a pocket. Selection 8 shows "" and returns 0 without remembering the selection.
static u32 THISCALL wheelInventoryGetItem(u8 *self) {
  u8 *osd = *(u8 **)(self + 0x1d0f);
  u8 l[0x45];
  for (int i = 0; i < 0x45; i++)
    l[i] = osd[0x37d + i];
  u32 sel = *(u32 *)(osd + 0x3c2);
  if (sel != *(u32 *)(self + 0x1d47) && sel != 8)
    ext_4f9680((void *)0x700e24, 0);
  osd = *(u8 **)(self + 0x1d0f);
  u32 item = 0, msg = 0;
  int show = 0;   // 1: numbered message, 0: empty message
  switch (*(u32 *)(osd + 0x3c2)) {
  case 0: if (at(l, 0x04)) { item = at(l, 0x29); msg = at(l, 0x04); show = 1; } break;
  case 1: item = at(l, 0x35); break;
  case 2: item = at(l, 0x3d); if (item) { msg = at(l, 0x15); show = 1; } break;
  case 3: item = at(l, 0x25); if (item) { msg = at(l, 0x00); show = 1; } break;
  case 4: if (at(l, 0x0c)) { item = at(l, 0x31); msg = at(l, 0x0c); show = 1; } break;
  case 5: item = at(l, 0x41); break;
  case 6: item = at(l, 0x39); if (item && at(l, 0x1d) != 2) { msg = at(l, 0x19); show = 1; } break;
  case 7: item = at(l, 0x2d); if (item) { msg = at(l, 0x08); show = 1; } break;
  case 8: ext_5ab2a0(osd, (const char *)0x677b5a); return 0;
  default: break;
  }
  if (show)
    ext_5ab230(osd, msg);
  else
    ext_5ab2a0(osd, (const char *)0x677b5a);   // ""
  *(u32 *)(self + 0x1d47) = *(u32 *)(*(u8 **)(self + 0x1d0f) + 0x3c2);
  return item;
}
PCREG(5e9b70, wheelInventoryGetItem);

// 0x5e9b40 ZGameOSD::WheelInventoryCommand(cmd): while the wheel is shown, pass the command (move selection) to the
// display and refresh the selected item (the result is left in eax).
static u32 THISCALL wheelInventoryCommand(u8 *self, u32 cmd) {
  u8 *osd = *(u8 **)(self + 0x1d0f);
  if (!osd || !osd[0x3c6])
    return 0;
  ext_5ab130(osd, cmd);
  return ext_5e9b70(self);
}
PCREG(5e9b40, wheelInventoryCommand);
