// batch0101.cpp - fresh-01 batch 1 (docs/20-fresh-01.md): small leaves and wrappers from slice residue 01.
// Names are from the GC name map (naming only). Bodies follow the PC bytes; callees outside the set run as exe code.
#include "ff.h"

extern "C" u32 ext_5fa630();                                            // returns the global at 0x724270
extern "C" u32 FASTCALL ext_6054b0(u32 serialInfo, u32 buffer);         // OpaqueString factory body (fastcall)
extern "C" void THISCALL ext_5630f0(u8 *self);                          // CBaseWindow::OnWindowOpen2
extern "C" void THISCALL ext_565100(u8 *self, u32 status);              // CFileWindow::SetStatus
extern "C" void THISCALL ext_64f760(u8 *self);                          // ZRender::AllocateDrawBuffers
extern "C" void *ext_41e290(u32 size);                                  // operator new (cdecl)

// 0x60db10, ZRenderGC::GetRenderName(): returns the address of the name string at 0x6bcb70.
static u32 renderGcGetRenderName() { return 0x6bcb70; }
PCREG(60db10, renderGcGetRenderName);

// 0x5f5510, Process_t::recycle(ScriptEvent_t*): gets the object at [0x724270] (via 0x5fa630) and tail-calls its
// vtable slot 0x50 with the event; that slot pops the argument.
static u32 THISCALL processRecycle(u8 *self, u32 ev) {
  u8 *o = (u8 *)ext_5fa630();
  return vcall<u32>(o, 0x50, ev);
}
PCREG(5f5510, processRecycle);

// 0x605b90 (unnamed): [this+0x10] + [this+8]*4 - [this+0xc] + 9 (a serial size computation).
static u32 THISCALL serialSize605b90(u8 *self) {
  return *(u32 *)(self + 0x10) + *(u32 *)(self + 8) * 4 - *(u32 *)(self + 0xc) + 9;
}
PCREG(605b90, serialSize605b90);

// 0x605550, OpaqueStringFactory_t::produceOpaqueObjectFromSerial(const char*, SerialInfo_t&, OpaqueObjectSerialBuffer_t&):
// ignores the name and calls 0x6054b0(info, buffer) as fastcall.
static u32 THISCALL opaqueStringProduce(u8 *self, u32 name, u32 info, u32 buf) {
  return ext_6054b0(info, buf);
}
PCREG(605550, opaqueStringProduce);

// 0x57bd50, ZFFLoadError::OnWindowOpen2(): base OnWindowOpen2, then SetStatus(this+0xcb2 dword).
static void THISCALL loadErrorOnWindowOpen2(u8 *self) {
  ext_5630f0(self);
  ext_565100(self, *(u32 *)(self + 0xcb2));
}
PCREG(57bd50, loadErrorOnWindowOpen2);

// 0x656950, ZPrimControlBase::ModifyLight(SPrimLight*, const SPrimLight*): copies dwords +0x10 and +0x14 from src to
// dst. ECX is not used; both pointers come on the stack (ret 8).
static void STDCALL primModifyLight(u8 *dst, const u8 *src) {
  *(u32 *)(dst + 0x10) = *(const u32 *)(src + 0x10);
  *(u32 *)(dst + 0x14) = *(const u32 *)(src + 0x14);
}
PCREG(656950, primModifyLight);

// 0x5f3210, SaveSerialInfo_t::savefloat(float): forwards the float to vtable slot 0x4c of the stream at this+0x15.
static u32 THISCALL saveSerialSaveFloat(u8 *self, u32 f) {
  u8 *s = *(u8 **)(self + 0x15);
  return vcall<u32>(s, 0x4c, f);
}
PCREG(5f3210, saveSerialSaveFloat);

// 0x654c90 (unnamed, render window): own vtable slot 0x88 with 0, then USER32 SetCursor(this+0x11f1 dword).
typedef u32(STDCALL *setCursorFn)(u32);
static void THISCALL render654c90(u8 *self) {
  vcall<void>(self, 0x88, 0u);
  (*(setCursorFn *)0x67622c)(*(u32 *)(self + 0x11f1));
}
PCREG(654c90, render654c90);

// 0x658110, ZRenderGC::AllocateDrawBuffers(): base ZRender::AllocateDrawBuffers, then this+0x1186 = new(0x4800).
static void THISCALL renderGcAllocateDrawBuffers(u8 *self) {
  ext_64f760(self);
  *(void **)(self + 0x1186) = ext_41e290(0x4800);
}
PCREG(658110, renderGcAllocateDrawBuffers);

// 0x5ffb50, VMImageInfo_t::getDataSegSize(): ([this+0x64] - [this+0x60]) plus the same for the chained image at
// this+0x9c, recursively.
static u32 THISCALL vmImageGetDataSegSize(u8 *self) {
  u32 n = *(u32 *)(self + 0x64) - *(u32 *)(self + 0x60);
  u8 *next = *(u8 **)(self + 0x9c);
  if (next) return vmImageGetDataSegSize(next) + n;
  return n;
}
PCREG(5ffb50, vmImageGetDataSegSize);
