// batch1041.cpp - ZCAMERA::FindCurrentRoom. Camera thread, 2026-10-11.
#include "cam.h"

// 0x445d50 ZCAMERA::FindCurrentRoom(u32 *rooms, u32 count): sets the cached room at +0x18.
// One candidate: it is the room. Otherwise the room the virtual slot 0x288 reports wins when it is in the list;
// else the cached room stays when it is in the list; else the first candidate (if any).
static THISCALL void ZCAMERA_FindCurrentRoom(u8 *self, u32 *rooms, u32 count) {
  if (count == 1) {
    at<u32>(self, 0x18) = rooms[0];
    return;
  }
  u32 cur = vcall<u32>(self, 0x288);
  if (cur && count) {
    for (u32 i = 0; i < count; i++) {
      if (rooms[i] == cur) {
        at<u32>(self, 0x18) = cur;
        return;
      }
    }
  }
  u32 cached = at<u32>(self, 0x18);
  if (cached) {
    for (u32 i = 0; i < count; i++) {
      if (rooms[i] == cached) return;
    }
  }
  if (count) at<u32>(self, 0x18) = rooms[0];
}
PCREG(445d50, ZCAMERA_FindCurrentRoom);
