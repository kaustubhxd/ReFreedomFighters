// batch234.cpp - ZLNKWHANDS leftovers (inline-ladder thread, VM restart 2026-10-11): folded stubs of the hands vtable,
// the destructor, CopyDataBlock, Load and Save. Bodies transcribed from Freedom.Exe (capstone listing); names from the
// GC name map (confidence per function below).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

typedef void (*hook_t)();
static inline void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (h)
    h();
  else
    __asm__ volatile("int3");
}

// 0x4d50c0 [name map low, icf: ZLNKWHANDS::CallBackItemAction / GetNearItems and others]: the assert hook at 0x7003b0
// is tail-jumped to if set, else int3. No arguments, plain ret.
static void hands_4d50c0() { assert_hook(); }
PCREG(4d50c0, hands_4d50c0);

// 0x510bd0 [name map low, icf: ZLNKWHANDS::ControlUseTwo(u32, u32)]: assert hook, ret 8.
static void THISCALL hands_510bd0(u8 *, u32, u32) { assert_hook(); }
PCREG(510bd0, hands_510bd0);

// 0x6368b0 [name map low, icf: ZLNKWHANDS::ControlUseOneExtra(u32)]: assert hook, ret 4.
static void THISCALL hands_6368b0(u8 *, u32) { assert_hook(); }
PCREG(6368b0, hands_6368b0);

// 0x54c2c0 [name map low, icf: ZLNKWHANDS::ShowChamberAnim / ShowReloadAnim(ZItemWeapon*) const]: return true, ret 4.
static bool THISCALL hands_54c2c0(u8 *, u32) { return true; }
PCREG(54c2c0, hands_54c2c0);

// 0x610420 [name map low, icf: ZLNKWHANDS::ModifyPickupAction(4 args) const]: empty, ret 0x10.
static void THISCALL hands_610420(u8 *, u32, u32, u32, u32) {}
PCREG(610420, hands_610420);

// 0x4632a0 [name map low: listed as ZLNKWHANDS::BoneAnimCallBackToId, icf shared by 3 GC fns; GUESS from the body it
// is an anim-file-name getter]: anim file pack at +0x60; none -> the empty string at 0x677b5a, else tail call of
// ZAnimFilePack::GetAnimFileName (0x4e5330, name map medium).
extern "C" u32 THISCALL ext_4e5330(void *pack);
static u32 THISCALL hands_4632a0(u8 *self) {
  void *pack = (void *)U32(self, 0x60);
  if (!pack)
    return 0x677b5a;
  return ext_4e5330(pack);
}
PCREG(4632a0, hands_4632a0);

// 0x471f90 ZLNKWHANDS::~ZLNKWHANDS() [GC name map high; PC scalar deleting dtor], thiscall, ret 4, returns this.
// Vtable 0x6890a4; the ref table at +0x3b7 is deleted through its slot 0 (flag 1); base dtor 0x468080; if flag bit 0:
// bit 2 set -> 0x4690b0(this, 0x412) (cdecl, an empty function in this build), else operator delete 0x45c510(this).
extern "C" void THISCALL ext_468080(void *self);
extern "C" void ext_4690b0(void *p, u32 n);
extern "C" void ext_45c510(void *p);
static u8 *THISCALL handsDtor(u8 *self, u32 flags) {
  U32(self, 0) = 0x6890a4;
  void *rt = (void *)U32(self, 0x3b7);
  if (rt)
    vcall<void>(rt, 0, 1u);
  ext_468080(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x412);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(471f90, handsDtor);

// 0x473370 ZLNKWHANDS::CopyDataBlock(DBLK*) [GC name map high], thiscall, ret 4. Base ZCTRLIKLNKOBJ::CopyDataBlock
// (0x4681a0); if the block type (DBLK::GetType 0x4e1600) is 3: DBLK::Get(int*, 1) (0x4e11e0, value unused), and if
// the type is then 4: DBLK::Get(char**) (0x4e1440) stored at +0x58, then DBLK::NextBlock (0x4e1b30).
extern "C" void THISCALL ext_4681a0(void *self, void *d);
extern "C" u8 THISCALL ext_4e1600(void *d);
extern "C" void THISCALL ext_4e11e0(void *d, u32 *out, u32 n);
extern "C" void THISCALL ext_4e1440(void *d, u32 *out);
extern "C" void THISCALL ext_4e1b30(void *d);
static void THISCALL handsCopyDataBlock(u8 *self, void *d) {
  ext_4681a0(self, d);
  if (ext_4e1600(d) != 3)
    return;
  u32 tmp;
  ext_4e11e0(d, &tmp, 1);
  if (ext_4e1600(d) == 4) {
    u32 v;
    ext_4e1440(d, &v);
    U32(self, 0x58) = v;
  }
  ext_4e1b30(d);
}
PCREG(473370, handsCopyDataBlock);

// 0x474770 ZLNKWHANDS::Load(ZLoadGame*) [GC name map high], thiscall, ret 4, al = 1. Base ZCTRLIKLNKOBJ::Load
// (0x468220), ZTARGET::Load (0x466eb0) on +0x26a, the two embedded objects at +0x34f and +0x2e7 (slot 4), a 4-byte
// "has ref table" word (stream slot 0x18); if set, new(0x1c) + REFTAB::REFTAB(4, 0) (0x4ccbe0) at +0x3b7 and stream
// slot 0x28 loads it. Then 3 x 12 bytes (+0x3bc, +0x3c8, +0x3d4), 2 bytes (+0x3e8, +0x3e9), and two floats (slot 0x50:
// +0x1e2, +0x3e4). The SEH frame only guards the new; no exception path is modelled.
extern "C" void THISCALL ext_468220(void *self, void *s);
extern "C" void THISCALL ext_466eb0(void *tgt, void *s, void *self);
extern "C" void *ext_41e290(u32 n);
extern "C" void *THISCALL ext_4ccbe0(void *p, u32 a, u32 b);
static bool THISCALL handsLoad(u8 *self, void *s) {
  ext_468220(self, s);
  ext_466eb0(self + 0x26a, s, self);
  vcall<void>(self + 0x34f, 4, s, self);
  vcall<void>(self + 0x2e7, 4, s, self);
  u32 has;
  vcall<void>(s, 0x18, &has, 4u);
  if (has) {
    void *p = ext_41e290(0x1c);
    void *rt = p ? ext_4ccbe0(p, 4, 0) : 0;
    U32(self, 0x3b7) = (u32)rt;
    vcall<void>(s, 0x28, rt);
  }
  vcall<void>(s, 0x18, self + 0x3bc, 0xcu);
  vcall<void>(s, 0x18, self + 0x3c8, 0xcu);
  vcall<void>(s, 0x18, self + 0x3d4, 0xcu);
  vcall<void>(s, 0x18, self + 0x3e8, 1u);
  vcall<void>(s, 0x18, self + 0x3e9, 1u);
  vcall<void>(s, 0x50, self + 0x1e2);
  vcall<void>(s, 0x50, self + 0x3e4);
  return true;
}
PCREG(474770, handsLoad);

// 0x4753c0 ZLNKWHANDS::Save(ZSaveGame*) [GC name map high], thiscall, ret 4, al = 1. Mirror of Load: base
// ZCTRLIKLNKOBJ::Save (0x468270), ZTARGET::Save (0x467850), embedded objects slot 0; the word written is the ref
// table's slot 0x14 value (called twice, as the original does) or 0; if non-zero the table is saved (slot 0x20); then
// the same fields with stream slot 0x10 and two floats by value (slot 0x4c).
extern "C" void THISCALL ext_468270(void *self, void *s);
extern "C" void THISCALL ext_467850(void *tgt, void *s, void *self);
static bool THISCALL handsSave(u8 *self, void *s) {
  ext_468270(self, s);
  ext_467850(self + 0x26a, s, self);
  vcall<void>(self + 0x34f, 0, s, self);
  vcall<void>(self + 0x2e7, 0, s, self);
  u32 has = 0;
  void *rt = (void *)U32(self, 0x3b7);
  if (rt && vcall<u32>(rt, 0x14))
    has = vcall<u32>((void *)U32(self, 0x3b7), 0x14);
  vcall<void>(s, 0x10, &has, 4u);
  if (has)
    vcall<void>(s, 0x20, U32(self, 0x3b7));
  vcall<void>(s, 0x10, self + 0x3bc, 0xcu);
  vcall<void>(s, 0x10, self + 0x3c8, 0xcu);
  vcall<void>(s, 0x10, self + 0x3d4, 0xcu);
  vcall<void>(s, 0x10, self + 0x3e8, 1u);
  vcall<void>(s, 0x10, self + 0x3e9, 1u);
  vcall<void>(s, 0x4c, F32(self, 0x1e2));
  vcall<void>(s, 0x4c, F32(self, 0x3e4));
  return true;
}
PCREG(4753c0, handsSave);
