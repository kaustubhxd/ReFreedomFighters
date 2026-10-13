// batch6255 - ragdoll side (claim 48): ZBoneModifyBase::ActivateRagdoll(lnk, a2, a3, a4) [0x6452f0; thiscall, four stack arguments, ret 0x10].
// If this+0x11 > 0x60 (unsigned): debug report (line 0x50f, file 0x6c2904, text 0x6c2a70), return 0.
// a2 == 0 (byte): if slot 0x34 of this returns non-zero or this+0x295 is set: lnk.slot 0x334; if lnk+8's word at +0x5a is set: r = this.slot 0x58(lnk),
//   eng+0x190f's object .slot 0x20 -> obj2; obj2.slot 0x5c(r, lnk). Then if this+0x291 is set: 0x641b60(container, ragdoll) and this+0x291 = 0.
//   this+0x295 = 0; return 1.
// a2 != 0: if this+0x291 is set: 0x641c50(ragdoll, a3); return 1. Else r = 0x642140(container, a4); this+0x291 = r; if r == 0 return 0;
//   0x644630(r, lnk); 0x640fe0(this+0x291); 0x641c50(this+0x291, a3); this+0x295 = 0; return 1.
// The helpers 0x641b60, 0x642140, 0x644630, 0x640fe0, 0x641c50 are recording stubs by address in the spec (GUESS: their bodies are not part of this batch).
#include "ff.h"

extern "C" void THISCALL ext_641b60(void *container, void *ragdoll);     // DeactivateRagdoll (GUESS stub)
extern "C" u32 THISCALL ext_642140(void *container, u32 flag);           // GetRagdoll (GUESS stub)
extern "C" void THISCALL ext_644630(void *ragdoll, void *lnk);           // CRagdoll2::Init (GUESS stub)
extern "C" void THISCALL ext_640fe0(void *ragdoll);                      // CRagdoll2::Activate (GUESS stub)
extern "C" void THISCALL ext_641c50(void *ragdoll, u32 flag);            // CRagdoll2::EnableTimeOut (GUESS stub)

typedef void (*reportStrFn)(void *, const char *);

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static u32 rd16u(const u8 *p) { u16 v; __builtin_memcpy(&v, p, 2); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u32 THISCALL fn6452f0(u8 *self, u8 *lnk, u32 a2, u32 a3, u32 a4) {
  if (rd32u(self + 0x11) > 0x60) {
    void *r = vcall<void *>(G(u8 *, 0x700390), 0x20, (const char *)0x6c2904, 0x50f);
    (*(reportStrFn *)(*(u8 **)r + 0x2c))(r, (const char *)0x6c2a70);
    return 0;
  }
  if ((u8)a2 == 0) {
    u8 t = (u8)vcall<u32>(self, 0x34);
    if (t != 0 || self[0x295] != 0) {
      vcall<void>(lnk, 0x334);
      u8 *o8 = rdp(lnk + 8);
      if (rd16u(o8 + 0x5a) != 0) {
        u32 r58 = vcall<u32>(self, 0x58, (u32)lnk);
        u8 *obj2 = (u8 *)vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x190f), 0x20);
        vcall<void>(obj2, 0x5c, r58, (u32)lnk);
      }
    }
    u8 *rag = rdp(self + 0x291);
    if (rag != 0) {
      ext_641b60(rdp(self + 0x28d), rag);
      wr32u(self + 0x291, 0);
    }
    self[0x295] = 0;
    return 1;
  }
  u8 *rag = rdp(self + 0x291);
  if (rag != 0) {
    ext_641c50(rag, a3);
    return 1;
  }
  u32 r = ext_642140(rdp(self + 0x28d), a4);
  wr32u(self + 0x291, r);
  if (r == 0) return 0;
  ext_644630((void *)r, lnk);
  ext_640fe0(rdp(self + 0x291));
  ext_641c50(rdp(self + 0x291), a3);
  self[0x295] = 0;
  return 1;
}
PCREG(6452f0, fn6452f0);
