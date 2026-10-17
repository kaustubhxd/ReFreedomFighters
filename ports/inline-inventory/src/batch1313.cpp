// batch1313.cpp - inventory thread (inline-inventory, 2026-10-11): ZFFInventorySelector::FrameUpdate (0x567f70).
// Frame: the local block F keeps the original's esp-relative offsets (F+0x38 the text buffer, F+0x2c the hero vector,
// F+0x20 / F+0x18 / F+0x30 the vectors of the distance test, F+0xc the counter and then the best distance, F+0x10 zero).
// Object: +0x28c the HUD owner (a pointer; its +0x1d0f member takes the text), +0x288 / +0x29d / +0x299 helper results,
// +0x290 the "refresh" flag, +0x291 the selected type, +0x295 the last shown type.
// Note: hero slot 0x84 takes ONE stack argument (the vector). The float 200.0 that the original writes "after the push"
// lands in the frame at F+0xc (the best-distance variable), not in an argument slot.
// Flag: F+0x38 (the buffer's first byte) is read by the first distance test when the text block did not run; that read
// is from the original's uninitialised stack (see the harness results before trusting those cases).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);  // PSVECSubtract(dst, a, b)
extern "C" u8 *THISCALL ext_5af130(u8 *list, u32 type);               // ZFFInventoryInfoList::GetInventoryInfo
extern "C" u8 *THISCALL ext_5af0d0(u8 *list, u32 index);              // list record by index
extern "C" u32 THISCALL ext_4cc1d0(u8 *list);                         // list count
extern "C" u32 THISCALL ext_5af5b0(u8 *bridge, u32 *type, u32 *n, u32 large);  // ZFFInventoryBridge::GetWeapon
extern "C" u32 THISCALL ext_5afbb0(u8 *bridge, u32 hero, u8 *list);   // ZFFInventoryBridge::SetData
extern "C" u32 THISCALL ext_5a8510(u8 *ui, u8 *text, u32 flag);       // HUD text show
extern "C" u32 THISCALL ext_568dc0(u8 *self);                         // ZFFInventorySelector::SwapWeapons

static inline u8 *refTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }
static inline u8 *fmtObj() { return *(u8 **)(refTable() + 0xae4); }

// Copies a NUL-terminated string including its NUL to dst (dst may be the end of the text buffer).
static void copyz(u8 *dst, const u8 *src) {
  u32 n = 0;
  while (src[n]) n++;
  for (u32 i = 0; i <= n; i++) dst[i] = src[i];
}
static u8 *endz(u8 *p) {
  while (*p) p++;
  return p;
}

static void THISCALL selectorFrameUpdate(u8 *self) {
  u8 F[0x834];
  u8 *buf = F + 0x38;
  u8 *sys = G(u8 *, 0x70039c);

  if (self[0x290]) {
    u8 *X = *(u8 **)(sys + 0x1907);
    u32 a1 = vcall<u32>(X, 0x60, 0x69c690u);
    *(u32 *)(self + 0x299) = a1;
    u32 a2 = vcall<u32>((u8 *)a1, 0x14, 0x6a6decu);
    *(u32 *)(self + 0x29d) = a2;
    u8 *hero = *(u8 **)(self + 0x90);
    *(u32 *)(self + 0x28c) = *(u32 *)(hero + 0x852);
    *(u32 *)(self + 0x288) = vcall<u32>(hero, 0x464);
    ext_5afbb0(self + 0x27c, (u32)hero, self + 0x180);
    self[0x290] = 0;

    u8 *edi = self + 0x228;
    if (ext_4cc1d0(edi)) {
      // the text: the formatted header, then the 3-byte tail at 0x6a73b0
      u32 s = vcall<u32>(fmtObj(), 0, 0x6a67e8u, 0x6a73a4u);
      copyz(buf, (const u8 *)s);
      u8 *e = endz(buf);
      for (int i = 0; i < 3; i++) e[i] = G(u8, 0x6a73b0 + i);

      u32 counter = 0;
      *(u32 *)(F + 0xc) = 0;
      if ((s32)ext_4cc1d0(edi) > 0) {
        for (;;) {
          u8 *info = ext_5af0d0(edi, counter);
          u32 nm = *(u32 *)(*(u8 **)info + 4);
          u32 name = nm ? nm : 0x67c8e8;                      // "<NONAME>"
          u32 t2 = vcall<u32>(fmtObj(), 0, 0x68899cu, name);
          copyz(endz(buf), (const u8 *)t2);
          counter++;
          *(u32 *)(F + 0xc) = counter;
          u32 c1 = ext_4cc1d0(edi);
          if ((s32)counter < (s32)c1) {
            // separator 1 (0x67a878) and then 0x6a73b0 again
            u8 *q = endz(buf);
            for (int i = 0; i < 3; i++) q[i] = G(u8, 0x67a878 + i);
            q = endz(buf);
            for (int i = 0; i < 3; i++) q[i] = G(u8, 0x6a73b0 + i);
          }
          u32 c2 = ext_4cc1d0(edi);
          if (!((s32)counter < (s32)c2)) break;
        }
      }
      u8 *osd = *(u8 **)(self + 0x28c);
      u8 *ui = *(u8 **)(osd + 0x1d0f);
      ext_5a8510(ui, buf, 1);
    }
  }

  // 568167: the hero's vector call (GUESS for args 1-3, see the header), then the eight selection slots
  u8 *hero = *(u8 **)(self + 0x90);
  *(u32 *)(F + 0x2c) = 0;
  *(u32 *)(F + 0x30) = 0;
  *(u32 *)(F + 0x34) = 0;
  *(u32 *)(self + 0x291) = 0;
  vcall<u32>(hero, 0x84, (u32)(F + 0x2c));
  *(float *)(F + 0xc) = 200.0f;                           // movss [esp+0x10] after the push: the frame's best distance

  u8 *slot = self + 0x3ee;
  for (int k = 0; k < 8; k++, slot += 8) {
    if (!*(u32 *)slot) continue;
    u8 *info = ext_5af130(self + 0x1d4, *(u32 *)(slot + 4));
    if (!info) continue;
    u8 *obj = *(u8 **)slot;
    *(u32 *)(F + 0x20) = 0;
    *(u32 *)(F + 0x24) = 0;
    *(u32 *)(F + 0x28) = 0;
    vcall<u32>(obj, 0x84, (u32)(F + 0x20));
    ext_43e920((float *)(F + 0x18), (const float *)(F + 0x30), (const float *)(F + 0x20));
    float x = *(float *)(F + 0x14), y = *(float *)(F + 0x18), z = *(float *)(F + 0x1c);
    float s = x * x;
    s = s + y * y;
    s = s + z * z;
    float dist = (float)crt::sqrt((double)s);
    float best = *(float *)(F + 0xc);
    if (best > dist) {
      *(float *)(F + 0xc) = dist;
      *(u32 *)(self + 0x291) = *(u32 *)(slot + 4);
    }
  }
  *(u32 *)(F + 0x10) = 0;

  if (*(u32 *)(self + 0x291)) {
    u8 *info = ext_5af130(self + 0x180, *(u32 *)(self + 0x291));
    u32 flag = (*(u32 *)(info + 0x19) == 1) ? 1 : 0;
    ext_5af5b0(self + 0x27c, (u32 *)(F + 0x18), (u32 *)(F + 0xc), flag);
    // F+0x10 was zeroed above, so the original's "non-zero" branch (a HUD use-action text, 0x5682b5) is not reached
    if (*(u32 *)(F + 0x10) == 0) ext_568dc0(self);
  }

  *(u32 *)(self + 0x295) = *(u32 *)(self + 0x291);
  u8 *X2 = *(u8 **)(sys + 0x1907);
  if (vcall<u32>(X2, 0x2c, *(u32 *)(self + 0x29d), 0u) & 0xff) {
    if (*(u32 *)(self + 0x291) && *(u32 *)(self + 0x291) != *(u32 *)(F + 0x10)) ext_568dc0(self);
  }
  (void)buf;
}
PCREG(567f70, selectorFrameUpdate);
