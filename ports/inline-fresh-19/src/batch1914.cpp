// batch1914.cpp - fresh slice 19, batch 1914 (docs/20-fresh-19.md). Names from the GameCube name map where it has one.
#include "ff.h"

extern "C" void THISCALL ext_57ece0(u8 *self, s32 d);                     // (no GC name) step selection (hooked)
extern "C" void THISCALL ext_562c20(u8 *self, u32 cmd);                   // ZVideoSelector::OnCommand (hooked)
extern "C" void THISCALL ext_57e930(u8 *self);                            // (no GC name) (hooked)
extern "C" void THISCALL ext_57d000(u8 *self);                            // (no GC name) (hooked)
extern "C" void ext_634d22(u32 dst, u32 src, u32 n);                      // jmp [0x67626c] memcpy, cdecl (hooked)
extern "C" s32 ext_42ab0d(u32 s, u32 fmt, float *a, float *b);            // sscanf shape, cdecl (hooked)

typedef void (*logf_t)(void *, ...);

// 0x57def0 (no GC name; a menu OnCommand) (cmd) ret 4: only in state +0xdc == 2 (else 0). 0x3ea / 0x3eb step the
// selection by -1 / +1 (0x57ece0); 0x1388 and 0x2b67 go to ZVideoSelector::OnCommand; 0x1770 to 0x57e930; any other
// command copies +0x338 bytes from (engine +0x1907)->+0x131c to +0x32c (memcpy 0x634d22), clears +0x34a, stores the
// command at +0x33c and calls 0x57d000. Returns 1 in state 2.
static bool THISCALL onCommand_57def0(u8 *self, u32 cmd) {
  if (*(u32 *)(self + 0xdc) != 2) return false;
  if (cmd == 0x3ea) ext_57ece0(self, -1);
  else if (cmd == 0x3eb) ext_57ece0(self, 1);
  else if (cmd == 0x1388 || cmd == 0x2b67) ext_562c20(self, cmd);
  else if (cmd == 0x1770) ext_57e930(self);
  else {
    ext_634d22(*(u32 *)(self + 0x32c), *(u32 *)(*(u8 **)(*(u8 **)0x70039cu + 0x1907) + 0x131c), *(u32 *)(self + 0x338));
    self[0x34a] = 0;
    *(u32 *)(self + 0x33c) = cmd;
    ext_57d000(self);
  }
  return true;
}
PCREG(57def0, onCommand_57def0);

// 0x64f9f0 (no GC name; render base font size) (const char *s) ret 4: with s, "%f,%f" into a stack pair (both 0 first;
// a zero second value takes the first) and (+0x104)->vt[0xfc](pair); without s, (+0x104)->vt[0x100](pair) and the log line
// "Fontsize = %f,%f" (renderbase.cpp line 0x9f).
static void THISCALL fontSize_64f9f0(u8 *self, u32 s) {
  float p[2];
  if (s) {
    p[0] = 0;
    p[1] = 0;
    ext_42ab0d(s, 0x6792b4u, &p[0], &p[1]);
    if (p[1] == 0.0f) p[1] = p[0];
    vcall<void>(*(u8 **)(self + 0x104), 0xfc, p);
    return;
  }
  vcall<void>(*(u8 **)(self + 0x104), 0x100, p);
  void *log = vcall<void *>(*(void **)0x700390u, 0x20, 0x6c3180u, 0x9fu);
  (*(logf_t *)(*(u8 **)log + 0x2c))(log, 0x6c31acu, (double)p[0], (double)p[1]);
}
PCREG(64f9f0, fontSize_64f9f0);

// 0x425170 (no GC name; debug window pump) (hwnd) ret 4: +0x20 = hwnd, vt[0x18](9, hwnd, 0); if FindWindowA(0, "ZDebug")
// finds the debug window: up to 200 rounds of (Peek, then Get / Translate / Dispatch while Peek and Get succeed), stopping
// once +0x24 is set, else Sleep(5). +0x10 = 1 at the end either way.
typedef s32(STDCALL *fw_t)(u32, u32);
typedef s32(STDCALL *pm_t)(u8 *, u32, u32, u32, u32);
typedef s32(STDCALL *gm_t)(u8 *, u32, u32, u32);
typedef s32(STDCALL *m1_t)(u8 *);
typedef void(STDCALL *sl_t)(u32);
static void THISCALL pump_425170(u8 *self, u32 h) {
  *(u32 *)(self + 0x20) = h;
  vcall<void>(self, 0x18, 9u, h, 0u);
  if ((*(fw_t *)0x676224u)(0, 0x678640u)) {
    pm_t peek = *(pm_t *)0x676220u;
    gm_t get = *(gm_t *)0x6761e0u;
    u8 msg[0x1c];
    for (s32 k = 0; k < 200; k++) {
      if (peek(msg, h, 0, 0, 0)) {
        while (get(msg, h, 0, 0)) {
          (*(m1_t *)0x6761dcu)(msg);
          (*(m1_t *)0x67624cu)(msg);
          if (!peek(msg, h, 0, 0, 0)) break;
        }
      }
      if (*(u32 *)(self + 0x24)) break;
      (*(sl_t *)0x6760e4u)(5);
    }
  }
  self[0x10] = 1;
}
PCREG(425170, pump_425170);

// 0x54cdf0 ZSynth::BuildFrame(): vt[0x30](); appends to the command stream at +0x8021 one 0xc-byte record (0x1001, 0xc,
// value) per +0x14[i] (count +0x8014) and (0x1002, 0xc, value) per +0x4014[i] (count +0x8018), signed counts; once
// (0x713e18 set, 0x713e19 not yet) an 8-byte (0x1100, 8) record and 0x713e19 = 1; both counts cleared.
static void THISCALL buildFrame_54cdf0(u8 *self) {
  vcall<void>(self, 0x30);
  for (s32 i = 0; i < *(s32 *)(self + 0x8014); i++) {
    u32 *r = *(u32 **)(self + 0x8021);
    r[0] = 0x1001;
    r[1] = 0xc;
    r[2] = *(u32 *)(self + 0x14 + 4 * i);
    *(u32 *)(self + 0x8021) += 0xc;
  }
  for (s32 i = 0; i < *(s32 *)(self + 0x8018); i++) {
    u32 *r = *(u32 **)(self + 0x8021);
    r[0] = 0x1002;
    r[1] = 0xc;
    r[2] = *(u32 *)(self + 0x4014 + 4 * i);
    *(u32 *)(self + 0x8021) += 0xc;
  }
  if (G(u8, 0x713e18) && !G(u8, 0x713e19)) {
    G(u8, 0x713e19) = 1;
    u32 *r = *(u32 **)(self + 0x8021);
    r[0] = 0x1100;
    r[1] = 8;
    *(u32 *)(self + 0x8021) += 8;
  }
  *(u32 *)(self + 0x8014) = 0;
  *(u32 *)(self + 0x8018) = 0;
}
PCREG(54cdf0, buildFrame_54cdf0);
