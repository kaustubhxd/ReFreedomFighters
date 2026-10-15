// batch1004.cpp - fresh-10 batch 4: menu/cutscene/window helpers, script VM helpers, destructors (slice 10).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
typedef void *(THISCALL *logpos_t)(void *, u32, u32);
static inline void LogMsg(u32 file, u32 line, u32 msg) {
  void *l = G(void *, 0x700390);
  void *p = (*(logpos_t *)(*(u8 **)l + 0x20))(l, file, line);
  typedef void (*logp1_t)(void *, u32);
  (*(logp1_t *)(*(u8 **)p + 0x2c))(p, msg);
}
static inline void *Scene() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x570620 CSewerMenu::CopyData(ZEventBase*) (medium): copies +0x1b0..+0x1bc, +0x190 and the byte +0x1a3.
static void THISCALL SewerMenuCopyData(u8 *self, u8 *src) {
  F32(self, 0x1b0) = F32(src, 0x1b0);
  F32(self, 0x1b4) = F32(src, 0x1b4);
  F32(self, 0x1b8) = F32(src, 0x1b8);
  F32(self, 0x1bc) = F32(src, 0x1bc);
  F32(self, 0x190) = F32(src, 0x190);
  self[0x1a3] = src[0x1a3];
}
PCREG(570620, SewerMenuCopyData);

// 0x4b14a0 CCutSequenceProxy::Command(unsigned short, void*): for its own command (+0x48): target (+0x44)
// slot12c(key +0x4c, cmd +0x4a, scene.slot4c(target)), then slot12c(key, cmd +0x48, data); returns 0.
static u32 THISCALL CutSequenceProxyCommand(u8 *self, u32 cmd, u32 data) {
  if ((u16)cmd == *(u16 *)(self + 0x48)) {
    u32 x = vcall<u32>(Scene(), 0x4c, F32(self, 0x44));
    vcall<void>(*(void **)(self + 0x44), 0x12c, F32(self, 0x4c), (u32) * (u16 *)(self + 0x4a), x);
    vcall<void>(*(void **)(self + 0x44), 0x12c, F32(self, 0x4c), (u32) * (u16 *)(self + 0x48), data);
  }
  return 0;
}
PCREG(4b14a0, CutSequenceProxyCommand);

// 0x4858a0 ZToggleStart::FrameUpdate(): when sys.slote8(key +0x50): item = list (+0x48).slot34(index +0x4c);
// if item: target (+0x44).slot370(item+4, item+0x28); index++, wrapping to 0 when it equals list.slot14().
static void THISCALL ToggleStartFrameUpdate(u8 *self) {
  if (!vcall<bool>(G(void *, 0x70039c), 0xe8, F32(self, 0x50))) return;
  u8 *it = vcall<u8 *>(*(void **)(self + 0x48), 0x34, F32(self, 0x4c));
  if (it) vcall<void>(*(void **)(self + 0x44), 0x370, it + 4, it + 0x28);
  F32(self, 0x4c)++;
  if (vcall<u32>(*(void **)(self + 0x48), 0x14) == F32(self, 0x4c)) F32(self, 0x4c) = 0;
}
PCREG(4858a0, ToggleStartFrameUpdate);

// 0x54f1a0 GUESS: COM call [this+4]->slot10(0x6bdf60, 2, 0, 0, &arg, 4); true when it succeeds (HRESULT >= 0),
// else logs file 0x6a4168 line 0x108 (0x6a42b4) and returns false (also false with no object).
typedef s32(STDCALL *com10_t)(void *, u32, u32, u32, u32, u32 *, u32);
static u32 THISCALL Com54f1a0(u8 *self, u32 arg) {
  void *o = *(void **)(self + 4);
  if (!o) return 0;
  if ((*(com10_t *)(*(u8 **)o + 0x10))(o, 0x6bdf60, 2, 0, 0, &arg, 4) >= 0) return 1;
  LogMsg(0x6a4168, 0x108, 0x6a42b4);
  return 0;
}
PCREG(54f1a0, Com54f1a0);

// 0x4c1ee0 ZSoundClock::Init(ZGEOM*, DBREAD&): GetValues(db); both counters (+0x1c4, +0x1c8) = 1 when +0x1cc is set,
// else = +0x1c0; then slot60(float +0x1ac).
extern "C" void THISCALL ext_4c0d70(void *, u32);
static void THISCALL SoundClockInit(u8 *self, u32, u32 db) {
  ext_4c0d70(self, db);
  u32 v = F32(self, 0x1cc) ? 1 : F32(self, 0x1c0);
  F32(self, 0x1c4) = v;
  F32(self, 0x1c8) = v;
  vcall<void>(self, 0x60, F32(self, 0x1ac));
}
PCREG(4c1ee0, SoundClockInit);

// 0x4f4020 ZWINDOW::WndMessage(ZWMEVENT*): type 0x100 -> slot2d8(key +8, down +0xc != 0); 0x200 -> slot2dc(same);
// other types return false.
static bool THISCALL WindowWndMessage(u8 *self, u8 *e) {
  u32 t = F32(e, 4);
  if (t == 0x100) return vcall<bool>(self, 0x2d8, F32(e, 8), (u32)(F32(e, 0xc) != 0));
  if (t == 0x200) return vcall<bool>(self, 0x2dc, F32(e, 8), (u32)(F32(e, 0xc) != 0));
  return false;
}
PCREG(4f4020, WindowWndMessage);

// 0x5613a0 CBaseWindow::Align(unsigned, unsigned): appends (a, b) to the 8-entry table at +0x98 (count +0xd8,
// signed compare); a full table logs file 0x6a64b4 line 0xf5 (0x6a6560).
static void THISCALL BaseWindowAlign(u8 *self, u32 a, u32 b) {
  s32 n = (s32)F32(self, 0xd8);
  if (n >= 8) { LogMsg(0x6a64b4, 0xf5, 0x6a6560); return; }
  F32(self, 0x98 + n * 8) = a;
  F32(self, 0x9c + F32(self, 0xd8) * 8) = b;
  F32(self, 0xd8)++;
}
PCREG(5613a0, BaseWindowAlign);

// 0x604460 ScriptEventManager_t::sendEvent(Process_t*, unsigned short, void*) (medium): an invalid process runs the
// assert hook; else handler = table (+8)[id]; ev = handler.slot0(p, id, data); if ev: p.enqueueScriptEvent(ev),
// p.handleEventsForProcess().
extern "C" bool THISCALL ext_5fb550(void *, void *);
extern "C" void THISCALL ext_5f4600(void *, u32);
extern "C" u32 THISCALL ext_5f4ac0(void *);
typedef u32 (*hookr_t)();
static u32 THISCALL SendEvent(u8 *self, u8 *p, u32 id, u32 data) {
  if (!ext_5fb550(*(void **)(self + 4), p)) {
    hookr_t h = G(hookr_t, 0x7003b0);
    if (!h) asm volatile("int3");
    return h();
  }
  u32 k = (u16)id;
  void *hd = (*(void ***)(self + 8))[k];
  if (!hd) return F32(self, 8);   // EAX still holds the table pointer
  u32 ev = vcall<u32>(hd, 0, p, k, data);
  if (!ev) return ev;
  ext_5f4600(p, ev);
  return ext_5f4ac0(p);   // EAX is what handleEventsForProcess returns
}
PCREG(604460, SendEvent);

// 0x5fe920 VMImageInfo_t::constructProcessData(Process_t*, SdlHostDataExchange_t*): size = end (+0x64) - start
// (+0x60) (+ getDataSegSize of +0x9c when set) + 1; p.data (+0x9e) = new(size), p.dataEnd (+0xa2) = data + size;
// copyAndInitDataSegment(p, &zero, x); process count (+4)++.
extern "C" u32 THISCALL ext_5ffb50(void *);
extern "C" u8 *ext_41e290(u32);
extern "C" void THISCALL ext_5fe980(void *, void *, u32 *, u32);
static void THISCALL ConstructProcessData(u8 *self, u8 *p, u32 x) {
  u32 n = F32(self, 0x64) - F32(self, 0x60);
  if (*(void **)(self + 0x9c)) n += ext_5ffb50(*(void **)(self + 0x9c));
  n++;
  u8 *d = ext_41e290(n);
  *(u8 **)(p + 0x9e) = d;
  *(u8 **)(p + 0xa2) = d + n;
  u32 off = 0;
  ext_5fe980(self, p, &off, x);
  F32(self, 4)++;
}
PCREG(5fe920, ConstructProcessData);

// 0x4f7fe0 ZSlider::NotifyChange() (medium): t = slot2c4(); v = slot368(scene.slot58(+0x60));
// t.slot2dc(0x10000, scene.slot4c(this), v).
static void THISCALL SliderNotifyChange(u8 *self) {
  void *t = vcall<void *>(self, 0x2c4);
  u32 y = vcall<u32>(Scene(), 0x58, F32(self, 0x60));
  u32 v = vcall<u32>(self, 0x368, y);
  u32 w = vcall<u32>(Scene(), 0x4c, self);
  vcall<void>(t, 0x2dc, 0x10000u, w, v);
}
PCREG(4f7fe0, SliderNotifyChange);

// 0x492820 GUESS: size (+0xaf8) = slot218() when unset (0 or -1 leaves it 0 and stops); buffer (+0xafc) = new(size)
// when unset, then slot21c(buffer, size).
static void THISCALL LazyBuffer492820(u8 *self) {
  if (!F32(self, 0xaf8)) {
    u32 v = vcall<u32>(self, 0x218);
    F32(self, 0xaf8) = v;
    if (v == 0 || v == 0xffffffff) { F32(self, 0xaf8) = 0; return; }
  }
  if (!F32(self, 0xafc)) {
    u8 *b = ext_41e290(F32(self, 0xaf8));
    *(u8 **)(self + 0xafc) = b;
    vcall<void>(self, 0x21c, b, F32(self, 0xaf8));
  }
}
PCREG(492820, LazyBuffer492820);

// 0x5f1720 ZScriptDll::CleanMrProper(): 0x5fb5a0 on (+0xc)->(+4), then empties the vector at (+0xc)+0xac/+0xb0
// (the compiled erase(begin, end) moves end - end = 0 elements, then end -= ((end - begin) >> 2) * 4).
extern "C" void THISCALL ext_5fb5a0(void *);
static void THISCALL CleanMrProper(u8 *self) {
  ext_5fb5a0(*(void **)(*(u8 **)(self + 0xc) + 4));
  u8 *b = *(u8 **)(self + 0xc);
  s32 n = (s32)(F32(b, 0xb0) - F32(b, 0xac)) >> 2;
  F32(b, 0xb0) += (u32)(-n) << 2;
}
PCREG(5f1720, CleanMrProper);

// 0x54ea20 GUESS scalar deleting destructor (SEH frame in the exe): vtable 0x6a410c; [this+4]->Release (slot 8,
// stdcall this); delete(this, 8) when flag & 1.
typedef u32(STDCALL *rel_t)(void *);
static u8 *THISCALL SDtor54ea20(u8 *self, u32 flags) {
  void *c = *(void **)(self + 4);
  *(u32 *)self = 0x6a410c;
  if (c) (*(rel_t *)(*(u8 **)c + 8))(c);
  if (flags & 1) ext_634273(self, 8);
  return self;
}
PCREG(54ea20, SDtor54ea20);

// 0x6487a0 GUESS ZArrayBlock take: free index (word +2), 0xffff = full -> 0; slot = block + idx*36 + 0x10;
// free index = slot's next (word); slot cleared (+0x14 = 0xffff1202); used count (byte +0)++; returns the slot.
static u8 *THISCALL BlockTake(u8 *blk) {
  u16 i = *(u16 *)(blk + 2);
  if (i == 0xffff) return 0;
  u8 *e = blk + (u32)i * 36;
  *(u16 *)(blk + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x2e) = 0;
  F32(e, 0x30) = 0;
  F32(e, 0x10) = 0;
  F32(e, 0x14) = 0xffff1202;
  F32(e, 0x18) = 0;
  F32(e, 0x1c) = 0;
  F32(e, 0x20) = 0;
  F32(e, 0x24) = 0;
  F32(e, 0x28) = 0;
  blk[0]++;
  return e + 0x10;
}
PCREG(6487a0, BlockTake);

// 0x4c3420 GUESS (SEH frame in the exe): o = (scene+8).slot44(this) (the pushed ECX read as its argument, GUESS);
// if o: 0x4c32a0(o); returns o.
extern "C" void THISCALL ext_4c32a0(void *);
static void *THISCALL Create4c3420(u8 *self) {
  void *o = vcall<void *>(*(void **)((u8 *)Scene() + 8), 0x44, self);
  if (o) ext_4c32a0(o);
  return o;
}
PCREG(4c3420, Create4c3420);
