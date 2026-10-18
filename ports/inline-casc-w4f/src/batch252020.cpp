// batch252020.cpp - Sonnet-w4f hand port of 0x425b10 (lifter: `lift: ebp`).
#include "ff.h"
#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)
#define IAT(T, a) ((T)(*(u32 *)(a)))

// 0x425b10: fastcall(ecx = name buffer, edx = size) + 2 stack args (domain buffer, size) ret 8; SEH (handler 0x633665, funclet 0x425c3b).
// SEH4 frame (push -2; push scopetable): record at ebp-0x10 {next, handler, scopetable ^ cookie}.
// Look up the account of the current token user: LookupAccountSidA(0, sid, ecx, edx, a, b, &use).
extern "C" u32 FASTCALL lifted_425b10(u32 ecx_in, u32 edx_in, u32 a, u32 b) {
  SEH_ENTER(0x633665);
  u32 edi = 0, esi = 0, tok = 0, len = 0, use = 0;
  reg.state = (s32)(0x6d4b80u ^ G(u32, 0x6f5630));   // SEH4 record +8 = scopetable ^ cookie; the try level [ebp-4] is not visible in the record
  u32 th = IAT(u32(STDCALL *)(), 0x676078)();
  u32 ok = IAT(u32(STDCALL *)(u32, u32, u32, u32 *), 0x67600c)(th, 8, 1, &tok);
  if (ok == 0) {
    if (IAT(u32(STDCALL *)(), 0x67609c)() != 0x3f0) goto done;
    u32 pr = IAT(u32(STDCALL *)(), 0x6760ac)();
    if (IAT(u32(STDCALL *)(u32, u32, u32 *), 0x676010)(pr, 8, &tok) == 0) goto done;
  }
  if (IAT(u32(STDCALL *)(u32, u32, u32, u32, u32 *), 0x676004)(tok, 1, 0, 0, &len) != 0) goto done;
  if (IAT(u32(STDCALL *)(), 0x67609c)() != 0x7a) goto done;
  {
    u32 heap = IAT(u32(STDCALL *)(), 0x6760a8)();
    esi = IAT(u32(STDCALL *)(u32, u32, u32), 0x6760a0)(heap, 0, len);
  }
  if (esi == 0) goto done;
  if (IAT(u32(STDCALL *)(u32, u32, u32, u32, u32 *), 0x676004)(tok, 1, esi, len, &len) == 0) goto done;
  {
    u32 r = IAT(u32(STDCALL *)(u32, u32, u32, u32, u32, u32, u32 *), 0x676000)(0, G(u32, esi), ecx_in, edx_in, a, b, &use);
    edi = r != 0 ? 1 : 0;
  }
done:
  // funclet 0x425c3b
  if (tok) IAT(u32(STDCALL *)(u32), 0x676070)(tok);
  if (esi) {
    u32 heap = IAT(u32(STDCALL *)(), 0x6760a8)();
    IAT(u32(STDCALL *)(u32, u32, u32), 0x6760a4)(heap, 0, esi);
  }
  SEH_LEAVE();
  return edi;
}
PCREG(425b10, lifted_425b10);

// 0x656260: thiscall(this, kind) ret 4. Hand port (lifter: `lift: ebp`, jump table + _alloca_probe 0x633c90).
// kind 0 / 1 / 2: size = this-vtable slot +0x11c / +0x118 / +0x120 () (jump table order 0x656290, 0x656284, 0x65629c); kind 3: calls the global hook [0x7003b0] (int3 when null), size stays 0; other kinds size 0.
// Then zeroes a stack buffer of `size` bytes (memset 0x634d10), index = slot +0x50(buf, size), record = slot +0xc(index), record word +2 = 6, record byte +0xc = kind; returns the index.
extern "C" u32 ext_634d10_cdecl(...) __asm__("ext_634d10");
extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL lifted_656260(u32 ecx_in, u32 kind) {
  u32 size = 0;
  u32 vt = G(u32, ecx_in);
  switch (kind) {
    case 0: size = ((u32(THISCALL *)(u32))(*(u32 *)(vt + 0x11c)))(ecx_in); break;
    case 1: size = ((u32(THISCALL *)(u32))(*(u32 *)(vt + 0x118)))(ecx_in); break;
    case 2: size = ((u32(THISCALL *)(u32))(*(u32 *)(vt + 0x120)))(ecx_in); break;
    case 3: {
      u32 hook = G(u32, 0x7003b0);
      if (hook) ((u32(*)())hook)(); else __builtin_trap();
      break;
    }
    default: break;
  }
  u8 *buf = (u8 *)__builtin_alloca((size + 3) & ~3u);
  ext_634d10_cdecl(buf, 0, size);
  u32 idx = ((u32(THISCALL *)(u32, u32, u32))(*(u32 *)(G(u32, ecx_in) + 0x50)))(ecx_in, (u32)buf, size);
  u32 rec = ((u32(THISCALL *)(u32, u32))(*(u32 *)(G(u32, ecx_in) + 0xc)))(ecx_in, idx);
  G(u16, rec + 2) = 6;
  G(u8, rec + 0xc) = (u8)kind;
  ext_633654(G(u32, 0x6f5630));
  return idx;
}
PCREG(656260, lifted_656260);
