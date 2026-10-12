// batch772.cpp - unclaimed-77 claim 2 (docs/20-unclaimed-77.md): five pure leaves, thiscall, no callees. Names are from the GC
// name map (medium).
#include "ff.h"

// 0x4834c0, ZPlayer::EnableT1() (medium): stores byte 0 at this+0x5fe.
static void THISCALL playerEnableT1(u8 *self) {
  self[0x5fe] = 0;
}
PCREG(4834c0, playerEnableT1);

// 0x483b00, ZPlayer::GetGroundContact() const (medium): returns the byte at this+0x42c (into al).
static u8 THISCALL playerGetGroundContact(u8 *self) {
  return self[0x42c];
}
PCREG(483b00, playerGetGroundContact);

// 0x453a40, ZGATE::GetGates() (medium): returns the dword at this+0x52.
static u32 THISCALL gateGetGates(u8 *self) {
  return *(u32 *)(self + 0x52);
}
PCREG(453a40, gateGetGates);

// 0x462f40, ZItemTemplate::GetPointerContextPicture() const (medium): returns the dword at this+0x6c.
static u32 THISCALL itemTemplateGetPointerContextPicture(u8 *self) {
  return *(u32 *)(self + 0x6c);
}
PCREG(462f40, itemTemplateGetPointerContextPicture);

// 0x44c100, ZSNDOBJ::GetPitch() (medium): loads the pointer at this+0x18, returns the dword at its +0x64.
static u32 THISCALL sndobjGetPitch(u8 *self) {
  u8 *p = *(u8 **)(self + 0x18);
  return *(u32 *)(p + 0x64);
}
PCREG(44c100, sndobjGetPitch);
