// batch1007.cpp - fresh-10 batch 7: allocate+init helpers, constructors, briefing talk, view removal (slice 10).
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl)
extern "C" void *ext_41e290(u32);            // operator new (cdecl)

// Fastcall allocate + init (SEH frame in the exe): x = b ? 0x45c4f0(size, b) : 0x45c4b0(size); x ? init(x, a, c, d) : 0.
extern "C" void *ext_45c4f0(u32, u32);
extern "C" void *ext_45c4b0(u32);
template <u32 SIZE, u32 INIT>
static u32 FASTCALL AllocInit(u32 c, u32 d, u32 a, u32 b) {
  typedef u32(THISCALL * init_t)(void *, u32, u32, u32);
  void *x = b ? ext_45c4f0(SIZE, b) : ext_45c4b0(SIZE);
  return x ? ((init_t)INIT)(x, a, c, d) : 0;
}
PCREG(4ee8a0, (AllocInit<0x20, 0x4ee2e0>));
PCREG(4f88a0, (AllocInit<0x1df, 0x4f8630>));
PCREG(52a760, (AllocInit<0x99, 0x52a370>));   // init = ZPathfinder3::ZPathfinder3(ZGEOMCLASSINFO*, const char*, ZBaseGeom*) (low)

// 0x444120 ZROOM::AddDynamicGeomToRoom(ZBaseGeom*) (high; SEH frame): the dynamic-geom table (+0xa8) is created on
// first use (new(0xac) + REFTAB32 ctor, 0 when new fails); if table.slot28(g) == 0: table.slot4(g); true.
extern "C" void *THISCALL ext_4ccba0(void *);
static bool THISCALL AddDynamicGeomToRoom(u8 *self, u32 g) {
  if (!F32(self, 0xa8)) {
    void *m = ext_41e290(0xac);
    *(void **)(self + 0xa8) = m ? ext_4ccba0(m) : 0;
  }
  if (!vcall<u32>(*(void **)(self + 0xa8), 0x28, g)) vcall<void>(*(void **)(self + 0xa8), 4, g);
  return true;
}
PCREG(444120, AddDynamicGeomToRoom);

// 0x5f29e0 ZScriptDll::ScheduleProcesses() (high): engine (+0xc)->(+4) scheduleProcesses; keep = name (+0xc+0x14)
// non-empty ? slot8c(&name) : 0; while the process count (+0x98) > keep: debug print (sys.slot190().slot184, cdecl:
// 10, count + 3, 0x679e6c), count--; count = keep.
extern "C" void THISCALL ext_5fd6f0(void *);
extern "C" u32 THISCALL ext_4cc5f0(void *);
static void THISCALL ScheduleProcesses(u8 *self) {
  ext_5fd6f0(*(void **)(*(u8 **)(self + 0xc) + 4));
  u32 keep = 0;
  if (ext_4cc5f0(*(u8 **)(self + 0xc) + 0x14)) keep = vcall<u32>(self, 0x8c, *(u8 **)(self + 0xc) + 0x14);
  while (F32(*(u8 **)(self + 0xc), 0x98) > keep) {
    void *d = vcall<void *>(G(void *, 0x70039c), 0x190);
    typedef void (*print_t)(void *, u32, u32, u32);
    (*(print_t *)(*(u8 **)d + 0x184))(d, 0xa, F32(*(u8 **)(self + 0xc), 0x98) + 3, 0x679e6c);
    F32(*(u8 **)(self + 0xc), 0x98)--;
  }
  F32(*(u8 **)(self + 0xc), 0x98) = keep;
}
PCREG(5f29e0, ScheduleProcesses);

// 0x49d220 GUESS constructor (vtable 0x68ee80): +0x1c = n, +0x20 = m, +0x24 = c; +4 = new(n*4), +8 = new(m*4) (-1 on
// overflow); +0x10..+0x18 = 0, byte +0x28 = 0; reports n*4 bytes to [0x70038c].slot24(0x68ee90, n*4) when set.
static inline u32 Bytes4(u32 n) { return (u64)n * 4 >> 32 ? 0xffffffff : n * 4; }
static u8 *THISCALL Ctor49d220(u8 *self, u32 n, u32 m, u32 c) {
  F32(self, 0x24) = c;
  F32(self, 0) = 0x68ee80;
  F32(self, 0x1c) = n;
  F32(self, 0x20) = m;
  *(void **)(self + 4) = ext_41e290(Bytes4(n));
  *(void **)(self + 8) = ext_41e290(Bytes4(m));
  F32(self, 0x10) = 0;
  F32(self, 0x14) = 0;
  F32(self, 0x18) = 0;
  self[0x28] = 0;
  void *mem = G(void *, 0x70038c);
  if (mem) vcall<void>(mem, 0x24, 0x68ee90u, n * 4);
  return self;
}
PCREG(49d220, Ctor49d220);

// 0x63fce0 ZDrawBase::RemoveView(ZViewBase*) (high): slot64 (lock); find v in the list +0xf0 (count +0xec); not
// found: slot64, false. Found: swap-remove, v.slot10(), slot64, RemoveCameras, slot +0x6c[v+0x10055] = 0, End,
// delete(v, 0x182a1), slot60; true.
extern "C" void THISCALL ext_64b070(void *);
extern "C" void THISCALL ext_648280(void *);
static bool THISCALL DrawRemoveView(u8 *self, u8 *v) {
  vcall<void>(self, 0x64);
  u32 n = F32(self, 0xec), i = 0;
  if (n)
    for (; i != n; i++)
      if (*(u8 **)(self + 0xf0 + 4 * i) == v) goto found;
  vcall<void>(self, 0x64);
  return false;
found:
  F32(self, 0xec)--;
  F32(self, 0xf0 + 4 * i) = F32(self, 0xf0 + 4 * F32(self, 0xec));
  vcall<void>(v, 0x10);
  vcall<void>(self, 0x64);
  ext_64b070(v);
  F32(self, 0x6c + 4 * F32(v, 0x10055)) = 0;
  ext_648280(v);
  ext_634273(v, 0x182a1);
  vcall<void>(self, 0x60);
  return true;
}
PCREG(63fce0, DrawRemoveView);

// 0x566b20 CBriefing::Talk() (medium): when the clock (rm+0x40) has reached next (+0x1ea, seconds * 1024) and lines
// remain (+0x9f8 < +0x1be; else +0xa0b = 0): StartMumbling(+0x19a, line, sound) returns its length (ST0);
// next = (clock + 0x600 - (int)(len * -1024)) / 1024; line++.
extern "C" float THISCALL ext_5668d0(void *, u32, u32, u32);
static inline s32 Cvtt(float f) { s32 r; asm("cvttss2si %1, %0" : "=r"(r) : "x"(f)); return r; }
static void THISCALL BriefingTalk(u8 *self) {
  s32 clk = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  if (clk < Cvtt(*(float *)(self + 0x1ea) * 1024.0f)) return;   // 1024.0 at 0x678620
  s32 i = *(s32 *)(self + 0x9f8);
  if (i >= *(s32 *)(self + 0x1be)) { self[0xa0b] = 0; return; }
  u32 line = F32(self, 0x19e + 4 * i);
  if (!line) return;
  float len = ext_5668d0(self, F32(self, 0x19a), line, F32(self, 0x1c2 + 4 * i));
  float t = (float)((long double)len * -1024.0L);   // x87 fmul by -1024.0 (0x67862c), fstp dword
  clk = clk + 0x600 - Cvtt(t);
  F32(self, 0x9f8)++;
  *(float *)(self + 0x1ea) = (float)clk * 0.0009765625f;   // 0x6785e4
}
PCREG(566b20, BriefingTalk);

// 0x41f1e0 GUESS ZSysMem constructor (SEH frame; three stack arguments unused): base 0x41e180; vtable 0x677370;
// InitializeCriticalSection(0x6fd228); allocator +0x31 = new(0x12144) built by ZMalloc(0, -1, 0) (0 when new fails);
// global [0x70038c] = this; CheckAndInitRefs; byte +0x4f = 1; returns this.
extern "C" void THISCALL ext_41e180(void *);
extern "C" void THISCALL ext_41e4b0(void *);
extern "C" u32 THISCALL ext_4cf940(void *, u32, u32, u32);
typedef void(STDCALL *ics_t)(u32);
static u8 *THISCALL ZSysMemCtor(u8 *self, u32, u32, u32) {
  ext_41e180(self);
  F32(self, 0) = 0x677370;
  G(ics_t, 0x6760c0)(0x6fd228);
  void *m = ext_41e290(0x12144);
  F32(self, 0x31) = m ? ext_4cf940(m, 0, 0xffffffff, 0) : 0;
  G(u8 *, 0x70038c) = self;
  ext_41e4b0(self);
  self[0x4f] = 1;
  return self;
}
PCREG(41f1e0, ZSysMemCtor);

// 0x420ea0 GUESS (cdecl): out = MYSTR(<folder of the exe> + "error.log"): GetModuleFileNameA(0, buf, 0x400), cut
// after the last '\\' (strrchr), append "error.log" (10 bytes from 0x677a60).
typedef u32(STDCALL *gmfn_t)(u32, char *, u32);
typedef char *(*strrchr_t)(const char *, u32);
extern "C" void THISCALL ext_4cbe80(void *, const char *);
static void *ErrorLogPath(void *out) {
  char buf[0x400];
  G(gmfn_t, 0x67607c)(0, buf, 0x400);
  char *p = G(strrchr_t, 0x676258)(buf, 0x5c);
  if (p) p[1] = 0;
  char *e = buf;
  while (*e) e++;
  for (int i = 0; i < 10; i++) e[i] = G(char, 0x677a60 + i);
  ext_4cbe80(out, buf);
  return out;
}
PCREG(420ea0, ErrorLogPath);
