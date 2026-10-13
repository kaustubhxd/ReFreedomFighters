// fb0202.cpp - fresh slice 17, batch 2.
#include "ff.h"

extern "C" u32 THISCALL ext_4244a0(u8 *self);
extern "C" u32 THISCALL ext_65f1b0(u8 *self);
extern "C" u32 THISCALL ext_64c8d0(void *self);

typedef void (*logfn)(void *, const char *, ...);
typedef void (*voidfn)();
#define g_pAssertHook G(voidfn, 0x7003b0)

// 0x6017d0 CSdlDataExchange::getExportSymbolNifHandle(const string&, const string&): unsupported. Logs through
// (*0x700390)->slot +0x20(file 0x6b9834, line 0x1c0) then the cdecl slot +0x2c(log, 0x69c6b0, 0x6b88c8), calls the assert
// hook at 0x7003b0 (int3 when none), returns 0.
static u32 STDCALL getExportSymbolNifHandle6017d0(u32, u32) {
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x6b9834u, 0x1c0u);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x69c6b0, (const char *)0x6b88c8);
  if (!g_pAssertHook)
    __builtin_debugtrap();
  g_pAssertHook();
  return 0;
}
PCREG(6017d0, getExportSymbolNifHandle6017d0);

// 0x633190 inflate_codes_new(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_streamp z) (zlib 1.1): c = ZALLOC(z, 1,
// 0x1c); on success c->mode = START (0), c->lbits = bl, c->dbits = bd, c->ltree = tl, c->dtree = td.
typedef void *(*zalloc_t)(void *, u32, u32);
static void *inflateCodesNew633190(u32 bl, u32 bd, u32 tl, u32 td, u8 *z) {
  u8 *c = (u8 *)(*(zalloc_t *)(z + 0x20))(*(void **)(z + 0x28), 1, 0x1c);
  if (c) {
    c[0x10] = (u8)bl;
    c[0x11] = (u8)bd;
    *(u32 *)(c + 0x18) = td;
    *(u32 *)c = 0;
    *(u32 *)(c + 0x14) = tl;
  }
  return c;
}
PCREG(633190, inflateCodesNew633190);

// 0x54df50 _ZSoundBuffer::SegmentSwitch(): calls the assert hook (int3 when none), n = slot +0x34(); true when
// size*seg <= n < size*(seg+1), size = this+0x40a9, seg = this+0x40ad (signed compares).
static u32 THISCALL segmentSwitch54df50(u8 *self) {
  if (!g_pAssertHook)
    __builtin_debugtrap();
  g_pAssertHook();
  s32 n = vcall<s32>(self, 0x34);
  s32 seg = *(s32 *)(self + 0x40ad), size = *(s32 *)(self + 0x40a9);
  if (n >= size * seg && n < (seg + 1) * size)
    return 1;
  return 0;
}
PCREG(54df50, segmentSwitch54df50);

// 0x655a10 (GUESS window procedure): obj = GetWindowLongA(hwnd, GWL_USERDATA) or the global 0x725824; when one exists,
// obj+0x133 = hwnd and the result is obj->slot +0x200(msg, wp, lp). Otherwise returns 0 (EAX from GetWindowLongA).
typedef u32(STDCALL *gwl_t)(u32, s32);
static u32 STDCALL wndProc655a10(u32 hwnd, u32 msg, u32 wp, u32 lp) {
  u8 *o = (u8 *)(*(gwl_t *)0x67623c)(hwnd, -0x15);
  if (!o) {
    o = G(u8 *, 0x725824);
    if (!o)
      return 0;
  }
  *(u32 *)(o + 0x133) = hwnd;
  return vcall<u32>(o, 0x200, msg, wp, lp);
}
PCREG(655a10, wndProc655a10);

// 0x60fdd0 (GUESS cached render state pair): fastcall (a, b). States 0x13 and 0x14 of the device at 0x724a00 are set
// (COM slot +0xc8, stdcall 3 words) only when they differ from the cached copies at 0x724928 / 0x72492c.
typedef u32(STDCALL *com3)(void *, u32, u32);
static void FASTCALL setStatePair60fdd0(u32 a, u32 b) {
  if (G(u32, 0x724928) != a) {
    void *dev = G(void *, 0x724a00);
    G(u32, 0x724928) = a;
    (*(com3 *)(*(u8 **)dev + 0xc8))(dev, 0x13, a);
  }
  if (G(u32, 0x72492c) != b) {
    void *dev = G(void *, 0x724a00);
    G(u32, 0x72492c) = b;
    (*(com3 *)(*(u8 **)dev + 0xc8))(dev, 0x14, b);
  }
}
PCREG(60fdd0, setStatePair60fdd0);

// 0x423850 ZSysInterfaceGC::RunMain(char*): slot +0x14c(cmdline); if slot +0x30(0) succeeds, runs slot +0x154(1) until it
// returns false with byte this+0x25ea clear; then 0x4244a0(this).
static u32 THISCALL runMain423850(u8 *self, u32 cmd) {
  vcall<u32>(self, 0x14c, cmd);
  if ((u8)vcall<u32>(self, 0x30, 0u)) {
    for (;;) {
      if ((u8)vcall<u32>(self, 0x154, 1u))
        continue;
      if (self[0x25ea] != 0)
        continue;
      break;
    }
  }
  return ext_4244a0(self);
}
PCREG(423850, runMain423850);

// 0x63ed10 ZDrawBase::Init(): byte +5 = 1, slot +4(), ZGeometryDecal::Init(this+0x8270), slot +0x78(), then
// ZViewBase::Init() on each of the this+0xec views listed at this+0xf0.
static void THISCALL drawBaseInit63ed10(u8 *self) {
  self[5] = 1;
  vcall<u32>(self, 0x04);
  ext_65f1b0(self + 0x8270);
  vcall<u32>(self, 0x78);
  if (*(u32 *)(self + 0xec)) {
    u32 i = 0;
    do {
      ext_64c8d0(*(void **)(self + 0xf0 + 4 * i));
      i++;
    } while (i != *(u32 *)(self + 0xec));
  }
}
PCREG(63ed10, drawBaseInit63ed10);

// 0x63b110 (GUESS free-list pop): 20-byte entries from this+0x10, head index word at this+2 (0xffff = empty, returns 0).
// Pops the head (its first word is the next index), zeroes the entry, marks its word at +0x4 0xffff1205, counts byte +0.
static u8 *THISCALL freeListPop63b110(u8 *self) {
  u16 idx = *(u16 *)(self + 2);
  if (idx == 0xffff)
    return 0;
  u8 *e = self + (u32)idx * 20;
  *(u16 *)(self + 2) = *(u16 *)(e + 0x10);
  *(u16 *)(e + 0x1c) = 0;
  *(u32 *)(e + 0x20) = 0;
  *(u32 *)(e + 0x10) = 0;
  *(u32 *)(e + 0x14) = 0xffff1205u;
  *(u32 *)(e + 0x18) = 0;
  self[0]++;
  return e + 0x10;
}
PCREG(63b110, freeListPop63b110);

// 0x54e950 ZSoundStreamerGC::Terminate(): fclose(this+0x2d6) and clear it; when the thread handle this+0x2ca exists,
// SetEvent(this+0x2d2) and WaitForSingleObject(thread, 5000).
typedef int (*fclose_t)(void *);
typedef u32(STDCALL *setev_t)(u32);
typedef u32(STDCALL *wait_t)(u32, u32);
static void THISCALL terminate54e950(u8 *self) {
  void *f = *(void **)(self + 0x2d6);
  if (f) {
    (*(fclose_t *)0x6763ac)(f);
    *(u32 *)(self + 0x2d6) = 0;
  }
  if (*(u32 *)(self + 0x2ca)) {
    (*(setev_t *)0x67613c)(*(u32 *)(self + 0x2d2));
    (*(wait_t *)0x676144)(*(u32 *)(self + 0x2ca), 0x1388);
  }
}
PCREG(54e950, terminate54e950);
