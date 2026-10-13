// batch78.cpp - searchlight group handle lists, inline session batch 78: ZFFSearchLightGroup::IsInList (0x5c7160,
// stdcall, ret 8, al), GetRefTabToEngageGuards (0x5c6bf0, thiscall, ret 4) and GetRefTabToOperators (0x5c6c50,
// thiscall, ret 4). Each walks an embedded handle list at +0x60 (IsInList: the list at +4 of its spot info) with the
// list's slot 0x4c (start) and slot 0x5c (next; the valid flag is written to a local).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef void(THISCALL *iterStartFn)(void *self, u32 *valid);
typedef u32(THISCALL *iterNextFn)(void *self, u32 *valid);

// The list walk: the first handle, then the rest while valid. The exe checks valid after each next call.
static u32 firstOf(u8 *list, u32 *valid) {
  ((iterStartFn)VT(list, 0x4c))(list, valid);
  return ((iterNextFn)VT(list, 0x5c))(list, valid);
}
static u32 nextOf(u8 *list, u32 *valid) { return ((iterNextFn)VT(list, 0x5c))(list, valid); }

// 0x5c7160 ZFFSearchLightGroup::IsInList(unsigned int id, tagSPOTINFO *s), stdcall, ret 8: true when id is a handle of
// the list at s+4.
static u8 STDCALL slgIsInList(u32 id, u8 *s) {
  u8 *list = *(u8 **)(s + 4);
  if (!list)
    return 0;
  u32 valid = 0;
  u32 h = firstOf(list, &valid);
  if (!valid)
    return 0;
  for (;;) {
    if (h == id)
      return 1;
    h = nextOf(list, &valid);
    if (!valid)
      return 0;
  }
}
PCREG(5c7160, slgIsInList);

// 0x5c6bf0 ZFFSearchLightGroup::GetRefTabToEngageGuards(unsigned int key), thiscall, ret 4: the record at the list
// (+0x60) whose first dword is key, its dword at +0xc; 0 when none.
static u32 THISCALL slgRefTabEngage(u8 *self, u32 key) {
  u8 *list = *(u8 **)(self + 0x60);
  if (!list)
    return 0;
  u32 valid = 0;
  u32 h = firstOf(list, &valid);
  if (!valid)
    return 0;
  for (;;) {
    if (key == *(u32 *)h)
      return *(u32 *)(h + 0xc);
    h = nextOf(list, &valid);
    if (!valid)
      return 0;
  }
}
PCREG(5c6bf0, slgRefTabEngage);

// 0x5c6c50 ZFFSearchLightGroup::GetRefTabToOperators(unsigned int key), thiscall, ret 4: as above, the dword at +0x8.
static u32 THISCALL slgRefTabOperators(u8 *self, u32 key) {
  u8 *list = *(u8 **)(self + 0x60);
  if (!list)
    return 0;
  u32 valid = 0;
  u32 h = firstOf(list, &valid);
  if (!valid)
    return 0;
  for (;;) {
    if (key == *(u32 *)h)
      return *(u32 *)(h + 8);
    h = nextOf(list, &valid);
    if (!valid)
      return 0;
  }
}
PCREG(5c6c50, slgRefTabOperators);
