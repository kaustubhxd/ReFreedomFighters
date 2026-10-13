// fb0808.cpp - fresh slice 17, batch 8.
#include "ff.h"

extern "C" void ext_42ab62(const char *fmt, ...);                         // printf
extern "C" u32 THISCALL ext_48c4b0(u8 *self, void *out, const char *name); // ZEngineDataBase::CalcCacheFileName (MYSTR by value)
extern "C" u32 THISCALL ext_4cc1d0(void *str);                            // MYSTR c_str (first word)
extern "C" u32 THISCALL ext_4cbec0(void *str);                            // MYSTR::~MYSTR()

typedef u32 (*voidfn)();
typedef void (*logfn)(void *, const char *, ...);
#define g_pAssertHook G(voidfn, 0x7003b0)
static inline void assertHook() {
  if (!g_pAssertHook)
    __builtin_debugtrap();
  g_pAssertHook();
}

// 0x426f50 ZSysFileGC::GetSize(const char*, bool) (really an existence test): unless `raw`, asks the archive first
// (h = slot +0x130(name), a = slot +0x70(h), a->slot +0x14(h) -> true); otherwise / failing that FindFirstFileA on the
// disk name (-1 -> false, else FindClose and true). The /GS check is not reproduced.
typedef u32(STDCALL *ffirst_t)(const char *, void *);
typedef u32(STDCALL *fclose_t)(u32);
static u32 THISCALL getSize426f50(u8 *self, const char *name, u32 raw) {
  if (!(u8)raw) {
    u32 h = vcall<u32>(self, 0x130, name);
    void *a = (void *)vcall<u32>(self, 0x70, h);
    if (a && (u8)vcall<u32>(a, 0x14, h))
      return 1;
  }
  u8 wfd[0x140];
  u32 f = (*(ffirst_t *)0x67610c)(name, wfd);
  if (f == 0xffffffffu)
    return 0;
  (*(fclose_t *)0x676108)(f);
  return 1;
}
PCREG(426f50, getSize426f50);

// 0x638e10 (GUESS palettised texture unpack to 32-bit): level info = slot +0x38(level) (pitch +4, data +0x10); for h rows
// of w pixels from (x, y), dst = palette(this+0x2d)[index] & 0xffffff with alpha from the byte plane at this+0x36 (same
// offsets, signed byte << 24). dst advances by `pitch` bytes per row.
static void THISCALL unpack638e10(u8 *self, u32 *dst, s32 x, s32 y, s32 w, s32 h, s32 pitch, u32 level) {
  u8 *info = (u8 *)vcall<u32>(self, 0x38, level);
  s32 off = *(s32 *)(info + 4) * y + x;
  u8 *data = *(u8 **)(info + 0x10);
  for (; h > 0; h--) {
    for (s32 i = 0; i < w; i++) {
      u32 col = (*(u32 **)(self + 0x2d))[data[off + i]] & 0xffffff;
      dst[i] = col;
      dst[i] = ((u32)(s32)(*(s8 **)(self + 0x36))[i + off] << 24) | col;
    }
    dst = (u32 *)((u8 *)dst + pitch);
    off += *(s32 *)(info + 4);
  }
}
PCREG(638e10, unpack638e10);

// 0x490090 ZEngineDataBase::GetAnimsSize() and 0x491210 ZEngineDataBase::GetTextureSize(): size of the cache file
// CalcCacheFileName(0x68d860 / 0x68d850) through the file system (0x700394) slot +0x30(name, 0). SEH frame and /GS
// check not reproduced.
static u32 cacheSize(u8 *self, const char *tag) {
  u8 str[0x80];
  ext_48c4b0(self, str, tag);
  void *fs = G(void *, 0x700394);
  u32 name = ext_4cc1d0(str);
  u32 n = vcall<u32>(fs, 0x30, name, 0u);
  ext_4cbec0(str);
  return n;
}
static u32 THISCALL getAnimsSize490090(u8 *self) { return cacheSize(self, (const char *)0x68d860); }
PCREG(490090, getAnimsSize490090);
static u32 THISCALL getTextureSize491210(u8 *self) { return cacheSize(self, (const char *)0x68d850); }
PCREG(491210, getTextureSize491210);

// 0x5f5250 (GUESS slot pool set, kind 1): asserts index < count (printf 0x6b89b4 + hook); takes slot [index++]; a slot of
// kind 0 or 1 becomes {*value, 1}; any other kind logs (0x69c8e0 line 0xc4, 0x69c6b0 / 0x69c938) and asserts.
static u8 *THISCALL slotSet5f5250(u8 *self, u32 *value) {
  if (*(u32 *)(self + 8) >= *(u32 *)(self + 4)) {
    ext_42ab62((const char *)0x6b89b4);
    assertHook();
  }
  u32 i = *(u32 *)(self + 8);
  u8 *s = *(u8 **)self + i * 8;
  *(u32 *)(self + 8) = i + 1;
  if (s[4] <= 1) {
    *(u32 *)s = *value;
    s[4] = 1;
    return s;
  }
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x69c8e0u, 0xc4u);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x69c6b0, (const char *)0x69c938);
  assertHook();
  return s;
}
PCREG(5f5250, slotSet5f5250);
