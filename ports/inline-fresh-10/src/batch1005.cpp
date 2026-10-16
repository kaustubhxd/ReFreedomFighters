// batch1005.cpp - fresh-10 batch 5: scene-factory creators, particle/script/menu helpers (slice 10).
#include "ff.h"

typedef void *(THISCALL *logpos_t)(void *, u32, u32);
static inline void LogMsg(u32 file, u32 line, u32 msg) {
  void *l = G(void *, 0x700390);
  void *p = (*(logpos_t *)(*(u8 **)l + 0x20))(l, file, line);
  typedef void (*logp1_t)(void *, u32);
  (*(logp1_t *)(*(u8 **)p + 0x2c))(p, msg);
}
typedef u32 (*hookr_t)();
static inline u32 AssertHook() {
  hookr_t h = G(hookr_t, 0x7003b0);
  if (!h) asm volatile("int3");
  return h();
}
static inline void *Scene() { return *(void **)(G(u8 *, 0x70039c) + 0x9b); }
#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// Scene-factory creators (each has an SEH frame in the exe): o = (scene+8).slot44(this) (the pushed ECX read as the
// argument, GUESS as in 0x4c3420); if o: constructor(o); returns o.
template <u32 CTOR>
static void *THISCALL Create(u8 *self) {
  typedef void(THISCALL * ctor_t)(void *);
  void *o = vcall<void *>(*(void **)((u8 *)Scene() + 8), 0x44, self);
  if (o) ((ctor_t)CTOR)(o);
  return o;
}
PCREG(4cad60, Create<0x4ca8f0>);   // GUESS: 0x4ca8f0 (map: ZSpin::CopyEventDataBlock, low)
PCREG(56ca20, Create<0x56c810>);   // GUESS: 0x56c810 (no name)
PCREG(5b2b60, Create<0x5b2550>);   // ZActionControlMap::ZActionControlMap() (high)
PCREG(5bfd60, Create<0x5bfac0>);   // CEntityTracker::CEntityTracker() (medium)

// 0x577920 GUESS: same creator with 0x573590, then vtable 0x6a9768 and byte +0x20f = 0.
extern "C" void THISCALL ext_573590(void *);
static void *THISCALL Create577920(u8 *self) {
  u8 *o = vcall<u8 *>(*(void **)((u8 *)Scene() + 8), 0x44, self);
  if (o) {
    ext_573590(o);
    F32(o, 0) = 0x6a9768;
    o[0x20f] = 0;
  }
  return o;
}
PCREG(577920, Create577920);

// 0x615ee0 GUESS: PrimInstanceCreate(e) on this, then e+0x20 = s.+8 + 0x4c, e+0x24 = s.+0x20 + 0x78,
// e+0x28 = s.+0x20 + (flag bit 4 of byte e.+8.+0x10.+8.+1 ? 0xf8 : 0xb8), e+0x2c = e.+0xc ?: s.+0xc ?: 0; true.
extern "C" void THISCALL ext_64d400(void *, void *);
static bool THISCALL PrimSetup615ee0(u8 *self, u8 *e) {
  ext_64d400(self, e);
  u8 *s = *(u8 **)(e + 0x14);
  u32 base = F32(s, 0x20);
  u8 fl = *(u8 *)(*(u8 **)(*(u8 **)(*(u8 **)(e + 8) + 0x10) + 8) + 1);
  F32(e, 0x20) = F32(s, 8) + 0x4c;
  F32(e, 0x24) = base + 0x78;
  F32(e, 0x28) = ((fl >> 4) & 1 ? 0xf8 : 0xb8) + base;
  u32 v = 0;
  if (F32(s, 0xc)) v = F32(s, 0xc);
  if (F32(e, 0xc)) v = F32(e, 0xc);
  F32(e, 0x2c) = v;
  return true;
}
PCREG(615ee0, PrimSetup615ee0);

// 0x456e60 ZParticleController::RegisterParticleTemplate(unsigned) (high): 256 slots of 8 bytes at +0x1d; returns
// index+1 of the slot holding id, or stores id in the first empty slot and returns its index+1; a full table logs
// file 0x682d18 line 0x1f8 (0x682e50), runs the assert hook and returns 0.
static u32 THISCALL RegisterParticleTemplate(u8 *self, u32 id) {
  for (u32 i = 0; i < 0x100; i++) {
    u32 v = F32(self, 0x1d + 8 * i);
    if (!v) { F32(self, 0x1d + 8 * i) = id; return i + 1; }
    if (v == id) return i + 1;
  }
  LogMsg(0x682d18, 0x1f8, 0x682e50);
  AssertHook();
  return 0;
}
PCREG(456e60, RegisterParticleTemplate);

// 0x5f51e0 GUESS: push a tagged value {data, tag byte} onto {array, cap (+4), count (+8)}: hook when count >= cap;
// unless src is the slot itself: a tag-4 old value is released (slot 0x28); a tag-4 src is added (slot 0x24, its
// return stored), else the raw dword; tag copied; count++; returns the new slot.
static u8 *THISCALL PushTagged(u8 *self, u8 *src) {
  if (F32(self, 8) >= F32(self, 4)) AssertHook();
  u8 *d = *(u8 **)self + F32(self, 8) * 8;
  if (src != d) {
    if (d[4] == 4) vcall<void>(*(void **)d, 0x28);
    F32(d, 0) = src[4] == 4 ? vcall<u32>(*(void **)src, 0x24) : F32(src, 0);
    d[4] = src[4];
  }
  F32(self, 8)++;
  return *(u8 **)self + F32(self, 8) * 8 - 8;
}
PCREG(5f51e0, PushTagged);

// 0x56fc20 CNewMenu::Sub() (medium): backspace: with text (+0x1c9) and a word stack (count +0x4b2, lengths +0x3b2):
// pop, cut the text at len - popped, edit (+0x5ce).slot284(text), SetCaretPos(); empty text plays slot248(0xff0000)
// on +0x5ca.
extern "C" void THISCALL ext_56fb10(void *);
static void THISCALL NewMenuSub(u8 *self) {
  char *t = (char *)(self + 0x1c9);
  u32 n = 0;
  while (t[n]) n++;
  if (!n) { vcall<void>(*(void **)(self + 0x5ca), 0x248, 0xff0000u); return; }
  u32 k = F32(self, 0x4b2);
  if (!k) return;
  F32(self, 0x4b2) = --k;
  t[n - F32(self, 0x3b2 + k * 4)] = 0;
  vcall<void>(*(void **)(self + 0x5ce), 0x284, t);
  ext_56fb10(self);
}
PCREG(56fc20, NewMenuSub);

// 0x4d4c20 IOFSPhysicalAccess_t::nativeEof(ImpNativeFd_t*) (low; SEH frame in the exe): r = feof(*fd);
// ferror(*fd) != 0 runs the assert hook; returns r.
typedef u32 (*crt1_t)(u32);
static u32 THISCALL NativeEof(u8 *, u32 *fd) {
  u32 f = *fd;
  u32 r = G(crt1_t, 0x6763dc)(f);
  if (G(crt1_t, 0x6763d8)(f)) AssertHook();
  return r;
}
PCREG(4d4c20, NativeEof);

// 0x4246e0 ZSysInterfaceGC::UPlotF(ZRender*, int, int, const char*, ...) (medium; cdecl with this first): unless the
// float at rm+0x9c7 equals 0.0 (0x6785d0), vsprintf into a 1 KB buffer and render.slot124(render, x, y, buf) (cdecl).
extern "C" void ext_42abee(char *, const char *, void *);
static void UPlotF(void *, u8 *render, u32 x, u32 y, const char *fmt, ...) {
  float v = *(float *)(G(u8 *, 0x70039c) + 0x9c7);
  if (v == G(float, 0x6785d0)) return;
  char buf[0x400];
  __builtin_va_list ap;
  __builtin_va_start(ap, fmt);
  ext_42abee(buf, fmt, (void *)ap);
  __builtin_va_end(ap);
  typedef void (*plot_t)(void *, u32, u32, char *);
  (*(plot_t *)(*(u8 **)render + 0x124))(render, x, y, buf);
}
PCREG(4246e0, UPlotF);

// 0x63eca0 GUESS: walks a chunked list (iterator from (+0x1c8).slotc: entry pointer, index, chunk {count, -, next,
// -, entries...}) and writes each element's +0x38 into out[]; returns the count.
static u32 THISCALL Collect63eca0(u8 *self, u32 *out) {
  u32 tmp[6];
  u8 *lst = self + 0x1c8;
  u32 *it = vcall<u32 *>(lst, 0xc, tmp);
  u32 *e = (u32 *)it[0];
  u32 idx = it[1];
  u8 *ch = (u8 *)it[2];
  u32 n = 0;
  while (e) {
    out[n++] = F32(*e, 0x38);
    if (++idx == F32(ch, 0)) {
      ch = *(u8 **)(ch + 8);
      if (!ch) break;
      idx = 0;
      e = (u32 *)(ch + 0x10);
    } else {
      e++;
    }
  }
  return n;
}
PCREG(63eca0, Collect63eca0);

// 0x42d2e0 ZSysInterface::HandleIfDef(string*&) (high): flag = slot8c(arg) && the enclosing flag (top of the dword
// stack at +0x1b61) is set; push it (vector push_back; the grow path is 0x4301c0(end, &flag)).
extern "C" void THISCALL ext_4301c0(void *, u32 *, u32 *);
static void THISCALL HandleIfDef(u8 *self, u32 arg) {
  bool r = vcall<bool>(self, 0x8c, arg);
  u8 *v = *(u8 **)(self + 0x1b61);
  u32 *end = *(u32 **)(v + 4);
  u32 flag = (r && end[-1]) ? 1 : 0;
  if (end == *(u32 **)(v + 8)) { ext_4301c0(v, end, &flag); return; }
  if (end) *end = flag;
  F32(v, 4) += 4;
}
PCREG(42d2e0, HandleIfDef);

// 0x551720 Signature_iff_EventTranslator_t::handleEventTranslation(ScriptEventFactory_t*, unsigned, void*) (low):
// ev = factory.slot18(id); if ev: t = ev.slot4c(); t[0] = data[0] (0x5002f0), t[1] = float data[1], t[2] = float
// data[2] (0x500360), each element from 0x5003d0(t, i); returns ev.
extern "C" void *THISCALL ext_5003d0(void *, u32);
extern "C" void THISCALL ext_5002f0(void *, u32);
extern "C" void THISCALL ext_500360(void *, u32);
static void *THISCALL HandleEventTranslation(u8 *, void *fac, u32 id, u32 *data) {
  void *ev = vcall<void *>(fac, 0x18, id);
  if (!ev) return ev;
  void *t = vcall<void *>(ev, 0x4c);
  ext_5002f0(ext_5003d0(t, 0), data[0]);
  ext_500360(ext_5003d0(t, 1), data[1]);
  ext_500360(ext_5003d0(t, 2), data[2]);
  return ev;
}
PCREG(551720, HandleEventTranslation);
