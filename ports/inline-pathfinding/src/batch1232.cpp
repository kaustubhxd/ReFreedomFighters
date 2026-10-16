// batch1232.cpp - pathfinding tree: ZActor path stepping. The current path (pointer at +0x695, unaligned) has a count at
// +8, a record array at +0xc (16-byte entries, read at 16k - 16 / 16k), a u32 action-pointer list at +0x14, and a u32
// blocker list at +0x10. thiscall, ret 0 (FindNextPathAction, FindNextPathBlocker) or ret 4 (SendPathDone).
#include "pf.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static u16 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static void wr16u(u8 *p, u16 v) { __builtin_memcpy(p, &v, 2); }

// 0x478640 ZActor::FindNextPathAction(). Unless a step is already pending (+0x6ce set and +0x64c == 0xa), takes the first
// non-zero entry of the action list: its record's word at +2 (& 0xfff) goes to +0x6d4, its +0x1c dword to +0x6ce, the
// index to +0x6d2 and the record at +0x6d6; the entry and the next are then cleared.
static void THISCALL actorFindNextPathAction(u8 *self) {
  if (rd32u(self + 0x6ce) != 0 && rd32u(self + 0x64c) == 0xa) return;
  u8 *path = (u8 *)rd32u(self + 0x695);
  wr16u(self + 0x6d2, 0);
  if (!path) return;
  if (rd32u(path + 0x10) == 0) return;
  int n = (int)rd32u(path + 8) - 1;
  if (n <= 0) return;
  u32 *list = (u32 *)rd32u(path + 0x14);
  int k = 0;
  while (k < n && list[k] == 0) k++;
  if (k >= n) return;
  u8 *rec = (u8 *)rd32u(path + 0xc);
  wr32u(self + 0x6d6, rd32u(rec + 16 * k - 16));
  wr16u(self + 0x6d2, (u16)k);
  u8 *act = (u8 *)list[k];
  wr16u(self + 0x6d4, (u16)(rd16u(act + 2) & 0xfff));
  wr32u(self + 0x6ce, rd32u(act + 0x1c));
  list[k] = 0;
  list[k + 1] = 0;
}
PCREG(478640, actorFindNextPathAction);

// 0x478700 ZActor::FindNextPathBlocker(). Clears +0x6c6, then takes the first non-zero blocker id of the path's list
// (+0x10): the record's dword at 16k goes to +0x6ca, the id is passed to the pathfinder (vtable +0x228 at +0x5b2) and the
// result goes to +0x6c6; the entry is cleared.
static void THISCALL actorFindNextPathBlocker(u8 *self) {
  u8 *path = (u8 *)rd32u(self + 0x695);
  wr32u(self + 0x6c6, 0);
  if (!path) return;
  if (rd32u(path + 0x10) == 0) return;
  int n = (int)rd32u(path + 8);
  if (n <= 0) return;
  u32 *list = (u32 *)rd32u(path + 0x10);
  int k = 0;
  while (k < n && list[k] == 0) k++;
  if (k >= n) return;
  u8 *rec = (u8 *)rd32u(path + 0xc);
  wr32u(self + 0x6ca, rd32u(rec + 16 * k));
  u8 *pf = (u8 *)rd32u(self + 0x5b2);
  wr32u(self + 0x6c6, vcall<u32>(pf, 0x228, list[k]));
  list[k] = 0;
}
PCREG(478700, actorFindNextPathBlocker);

// 0x47b7a0 ZActor::SendPathDone(bool). thiscall, ret 4. The state at +0x727 (1..4) selects a notice (vtable slots 0x640,
// 0x644 (+0x72b), 0x648 (+0x732), 0x64c); with no path and the flag set, the position is read (0x57c) and reported (0x620,
// then 0x578 with (&v34, &v10), and the position is kept at +0x660. The state fields are then cleared.
static void THISCALL actorSendPathDone(u8 *self, u32 arg) {
  u32 state = rd32u(self + 0x727);
  bool endNow = false;
  if (state != 0) {
    u32 idx = state - 1;
    if (idx <= 3) {
      switch (idx) {
        case 0:
          if (rd32u(self + 0x695) != 0) {
            endNow = true;
          } else {
            vcall<void>(self, 0x640, (u32)0);
          }
          break;
        case 1: vcall<void>(self, 0x644, rd32u(self + 0x72b)); break;
        case 2: vcall<void>(self, 0x648, rd32u(self + 0x732)); break;
        case 3: vcall<void>(self, 0x64c, (u32)0); break;
      }
    }
    if (!endNow) {
      if (rd32u(self + 0x695) != 0) {
        endNow = true;
      } else {
        self[0x726] = 0;
        if (!(u8)arg) {
          endNow = true;
        } else {
          float v10[3], v34[3];
          vcall<void>(self, 0x57c, v34, v10);
          vcall<void>(self, 0x620, v10, (u32)1, (u32)1);
          *(float *)(self + 0x660) = v10[0];
          *(float *)(self + 0x664) = v10[1];
          *(float *)(self + 0x668) = v10[2];
          vcall<void>(self, 0x578, v34, v10);
        }
      }
    }
  } else {
    return;   // state 0: the exe jumps straight to the return, without clearing
  }
  wr32u(self + 0x650, 0);
  wr32u(self + 0x64c, 0);
  wr32u(self + 0x727, 0);
  wr32u(self + 0x72b, 0);
}
PCREG(47b7a0, actorSendPathDone);
