// batch6247 - ragdoll side (claim 40): Load2 at 0x644820 (thiscall, no argument; the name map gives both CRagdoll2::Load2 and
// ZRagdollContainer::Load2 for this address). For each of this+0x21 entries (signed; stride 0x1df from this+0x25) and then once for the entry at
// this+0x29: r = the message table's slot 0x58 with the entry's dword at +0x3a; if the byte at +0x3e is set, 0x645000 (thiscall, the entry, r; GUESS
// stub by address) and +0x2e = 0; if the byte at +0x15 is set: when the byte at +0x14 is zero, +0x16 = 1000, +0x1a = 0x43160000, +0x1e = 0x44bb8000,
// +0x22 = 0; then the byte at +0x14 = 1.
#include "ff.h"

extern "C" void THISCALL ext_645000(void *self, u32 r);   // exe: thiscall, one stack argument (ret 4); GUESS stub by address

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void loadEntry(u8 *e) {
  u32 r = vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x58, rd32u(e + 0x3a));
  if (e[0x3e] != 0) {
    ext_645000(e, r);
    wr32u(e + 0x2e, 0);
  }
  if (e[0x15] != 0) {
    if (e[0x14] == 0) {
      wr32u(e + 0x16, 0x3e8);
      wr32u(e + 0x1a, 0x43160000u);
      wr32u(e + 0x1e, 0x44bb8000u);
      wr32u(e + 0x22, 0);
    }
    e[0x14] = 1;
  }
}

static void THISCALL fn644820(u8 *self) {
  s32 count = (s32)rd32u(self + 0x21);
  for (s32 i = 0; i < count; i++) loadEntry(rdp(self + 0x25) + (u32)i * 0x1df);
  loadEntry(rdp(self + 0x29));
}

PCREG(644820, fn644820);
