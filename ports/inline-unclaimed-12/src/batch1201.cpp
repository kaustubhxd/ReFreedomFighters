// batch1201.cpp - unclaimed-12: batch 1 (docs/20-unclaimed-12.md). Every function is thiscall; the stack args are popped by the callee.
// Names are from the GC name map (naming only, GUESS where the map is medium or low); the bodies are from the PC bytes.
#include "ff.h"

// 16 bytes as four dwords (the original uses movups; four unaligned dword moves give the same bytes).
static void copy16(u8 *dst, const u8 *src) {
  for (int i = 0; i < 16; i += 4) *(u32 *)(dst + i) = *(const u32 *)(src + i);
}

// 0x4b85f0, ZRelayMessage::CopyData(ZEventBase*) (high): word +0x48, word +0x4a, dword +0x4c from the source.
static void THISCALL relayMessageCopyData(u8 *self, const u8 *src) {
  *(u16 *)(self + 0x48) = *(const u16 *)(src + 0x48);
  *(u16 *)(self + 0x4a) = *(const u16 *)(src + 0x4a);
  *(u32 *)(self + 0x4c) = *(const u32 *)(src + 0x4c);
}
PCREG(4b85f0, relayMessageCopyData);

// 0x4fb880, CCHECKOBJINOBJ::CopyData(ZEventBase*) (high): dword +0x51, +0x59, +0x55 and word +0x4d, +0x4f from the source.
static void THISCALL checkObjInObjCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x51) = *(const u32 *)(src + 0x51);
  *(u32 *)(self + 0x59) = *(const u32 *)(src + 0x59);
  *(u32 *)(self + 0x55) = *(const u32 *)(src + 0x55);
  *(u16 *)(self + 0x4d) = *(const u16 *)(src + 0x4d);
  *(u16 *)(self + 0x4f) = *(const u16 *)(src + 0x4f);
}
PCREG(4fb880, checkObjInObjCopyData);

// 0x582700, CExplodeMolotov::CopyData(ZEventBase*) (high): dword +0x48, +0x4c and word +0x54, +0x56 from the source.
static void THISCALL explodeMolotovCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x48) = *(const u32 *)(src + 0x48);
  *(u32 *)(self + 0x4c) = *(const u32 *)(src + 0x4c);
  *(u16 *)(self + 0x54) = *(const u16 *)(src + 0x54);
  *(u16 *)(self + 0x56) = *(const u16 *)(src + 0x56);
}
PCREG(582700, explodeMolotovCopyData);

// 0x5b1b70, ZKillBox::CopyData(ZEventBase*) (high): dword +0x4a, word +0x48, dword +0x4e, 16 bytes at +0x52, +0x62, +0x72,
// byte +0x82, dword +0x83, byte +0x87, dword +0x88, byte +0x8c, all from the source.
static void THISCALL killBoxCopyData(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x4a) = *(const u32 *)(src + 0x4a);
  *(u16 *)(self + 0x48) = *(const u16 *)(src + 0x48);
  *(u32 *)(self + 0x4e) = *(const u32 *)(src + 0x4e);
  copy16(self + 0x52, src + 0x52);
  copy16(self + 0x62, src + 0x62);
  copy16(self + 0x72, src + 0x72);
  self[0x82] = src[0x82];
  *(u32 *)(self + 0x83) = *(const u32 *)(src + 0x83);
  self[0x87] = src[0x87];
  *(u32 *)(self + 0x88) = *(const u32 *)(src + 0x88);
  self[0x8c] = src[0x8c];
}
PCREG(5b1b70, killBoxCopyData);

// 0x489d80, ZMovementAction::WantControl(const float*, const float*, const float*) (medium, GUESS name): the three float
// pointers are unused. Returns the byte this+0x21 when the object at this+4 has flag 0x80000 in the dword at +0x417; else 0.
static bool THISCALL movementActionWantControl(u8 *self, const void *, const void *, const void *) {
  const u8 *owner = *(const u8 *const *)(self + 4);
  if (*(const u32 *)(owner + 0x417) & 0x80000) return self[0x21] != 0;
  return false;
}
PCREG(489d80, movementActionWantControl);

// 0x471a40, ZItemAmmo::VerifyItemTemplate(const ZItemTemplate*) const (high): this is unused. A null template gives 0;
// otherwise 1 when the dword at [template+0xc]+0x23 equals 0x1007d5.
static bool THISCALL itemAmmoVerifyItemTemplate(const u8 *self, const u8 *tmpl) {
  (void)self;
  if (!tmpl) return false;
  const u8 *block = *(const u8 *const *)(tmpl + 0xc);
  return *(const u32 *)(block + 0x23) == 0x1007d5;
}
PCREG(471a40, itemAmmoVerifyItemTemplate);

// 0x523e80, CMoveAlongPath::SetTargetSpeed(float, float) (medium): the arguments are floats, passed as bits. Stores arg1 at
// +0x2c and arg2 at +0x28; arg2 is stored with its sign flipped when the float at +0x24 is greater than arg1 (comiss/jbe:
// an unordered compare does not flip). Sign flip is an xor on the bits, as in the original.
static void THISCALL moveAlongPathSetTargetSpeed(u8 *self, u32 a1, u32 a2) {
  const float v1 = *(const float *)&a1;
  *(u32 *)(self + 0x2c) = a1;
  if (*(const float *)(self + 0x24) > v1)
    *(u32 *)(self + 0x28) = a2 ^ 0x80000000u;
  else
    *(u32 *)(self + 0x28) = a2;
}
PCREG(523e80, moveAlongPathSetTargetSpeed);
