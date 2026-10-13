// fb0101.cpp - fresh slice 17, batch 1: small members (vtable forwarders, window/render helpers, file-system stubs).
#include "ff.h"

extern "C" u32 THISCALL ext_54ab70(u8 *self);
extern "C" u32 THISCALL ext_562e90(u8 *self, u32 a, u32 b);
extern "C" void ext_634273(void *p, u32 flag);     // __builtin_delete (cdecl, two words)
extern "C" u32 THISCALL ext_54de40(u8 *self);
extern "C" u32 THISCALL ext_638610(u8 *self);

typedef u32(STDCALL *com1)(void *);
typedef void (*logfn)(void *, const char *, ...);

// 0x54c3d0 (GUESS FUN_54c3d0): if this+0x63ec holds an object, call its slot +0x48 COM-style (object pushed, callee pops 4),
// then tail-jump to 0x54ab70 with the same this.
static u32 THISCALL guess54c3d0(u8 *self) {
  void *p = *(void **)(self + 0x63ec);
  if (p)
    (*(com1 *)(*(u8 **)p + 0x48))(p);
  return ext_54ab70(self);
}
PCREG(54c3d0, guess54c3d0);

// 0x650b50 ZRenderBaseDll::PushScene(const char*): the name is unused. Slot +0x90(), then slot +0x9c(this[0x3c] + 1).
static u32 THISCALL pushScene650b50(u8 *self, const char *) {
  vcall<u32>(self, 0x90);
  return vcall<u32>(self, 0x9c, *(u32 *)(self + 0x3c) + 1);
}
PCREG(650b50, pushScene650b50);

// 0x64f9d0 ZRender::DrawMemory(): r = (*0x70038c)->slot +0x98(); this->slot +0x74(r, 0x2000).
static u32 THISCALL drawMemory64f9d0(u8 *self) {
  u32 r = vcall<u32>(G(void *, 0x70038c), 0x98);
  return vcall<u32>(self, 0x74, r, 0x2000u);
}
PCREG(64f9d0, drawMemory64f9d0);

// 0x657450 ZPrimControlGC::GetPrimSplineIndices(unsigned): slot +0xc twice, the second time with field +0x80 of the first result.
static u32 THISCALL getPrimSplineIndices657450(u8 *self, u32 i) {
  u8 *p = (u8 *)vcall<u32>(self, 0x0c, i);
  return vcall<u32>(self, 0x0c, *(u32 *)(p + 0x80));
}
PCREG(657450, getPrimSplineIndices657450);

// 0x57aa50 ZFFMissingControllerDialog::OnWindowClose(unsigned, bool): base class close, slot +0x64(0x10), returns false.
// AL is 0; the rest of EAX is what slot +0x64 left.
static u32 THISCALL onWindowClose57aa50(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  u32 r = vcall<u32>(self, 0x64, 0x10u);
  return r & 0xffffff00u;
}
PCREG(57aa50, onWindowClose57aa50);

// 0x650dd0 ZRender::SetCameraList(LINKSORTREFTAB*): deletes the old list (slot 0 = scalar deleting dtor, flag 1), stores the
// new one at this+0x8c. EAX ends as the argument.
static u32 THISCALL setCameraList650dd0(u8 *self, u32 list) {
  void *old = *(void **)(self + 0x8c);
  if (old)
    vcall<u32>(old, 0x00, 1u);
  *(u32 *)(self + 0x8c) = list;
  return list;
}
PCREG(650dd0, setCameraList650dd0);

// 0x4d5410 IOFSMemoryAccess_t::nativeWrite(void*, unsigned, ImpNativeFd_t*): not supported. Gets the log object from
// (*0x700390)->slot +0x20(file 0x6966c4, line 0x130), prints 0x6966f0 through its cdecl slot +0x2c, returns 0.
static u32 STDCALL nativeWrite4d5410(u32, u32, u32) {
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x6966c4u, 0x130u);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x6966f0);
  return 0;
}
PCREG(4d5410, nativeWrite4d5410);

// 0x4d7710 FsZip_t::write(IOFSHandle_t*, void*, unsigned): same shape (file 0x696924, line 0x474, text 0x696aa4), returns -1.
static u32 STDCALL zipWrite4d7710(u32, u32, u32) {
  void *log = (void *)vcall<u32>(G(void *, 0x700390), 0x20, 0x696924u, 0x474u);
  (*(logfn *)(*(u8 **)log + 0x2c))(log, (const char *)0x696aa4);
  return 0xffffffffu;
}
PCREG(4d7710, zipWrite4d7710);

// 0x54a710 (GUESS FUN_54a710): frees this+0xa269 with __builtin_delete(p, 1) when set, clears it, tail-jumps to 0x54de40.
static u32 THISCALL guess54a710(u8 *self) {
  void *p = *(void **)(self + 0xa269);
  if (p)
    ext_634273(p, 1);
  *(u32 *)(self + 0xa269) = 0;
  return ext_54de40(self);
}
PCREG(54a710, guess54a710);

// 0x638690 (GUESS FUN_638690): returns base + this[0x32]*4 + 4 + slot20() * slot1c(), base = 0x638610(this).
static u32 THISCALL guess638690(u8 *self) {
  u32 base = ext_638610(self);
  u32 p = base + *(u32 *)(self + 0x32) * 4;
  u32 a = vcall<u32>(self, 0x20);
  u32 b = vcall<u32>(self, 0x1c);
  return p + 4 + a * b;
}
PCREG(638690, guess638690);

// 0x4b0c50 CCutSequenceSoundEnvironment::Save(ZSaveGame*): clears flag 0x40 at this+4, saves this+0x48 (slot +0x44) and
// this+0x50 (slot +0x54), returns true (AL = 1 over what slot +0x54 left in EAX).
static u32 THISCALL save4b0c50(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= ~0x40u;
  vcall<u32>(sg, 0x44, *(u32 *)(self + 0x48));
  u32 r = vcall<u32>(sg, 0x54, *(u32 *)(self + 0x50));
  return (r & 0xffffff00u) | 1;
}
PCREG(4b0c50, save4b0c50);

// 0x54f0d0 (GUESS FUN_54f0d0): device = this+4; false when null. Else COM slot +0x10(dev, 0x6bdf60, 0x80000003, 0, 0, &arg, 4)
// (stdcall, 7 words) and returns HRESULT >= 0.
typedef s32(STDCALL *com7)(void *, u32, u32, u32, u32, void *, u32);
static u32 THISCALL guess54f0d0(u8 *self, u32 arg) {
  void *dev = *(void **)(self + 4);
  if (!dev)
    return 0;
  s32 hr = (*(com7 *)(*(u8 **)dev + 0x10))(dev, 0x6bdf60u, 0x80000003u, 0, 0, &arg, 4);
  return ((u32)hr & 0xffffff00u) | (hr >= 0);
}
PCREG(54f0d0, guess54f0d0);

// 0x4afd50 CCutSequenceInfo::Command(unsigned short, void*): when the command equals the word at this+0x66 and
// _stricmp(*(char**)data, *(char**)(this+0x48)) == 0, stores this+0x48 at data+4. Returns 0.
typedef int (*stricmp_t)(const char *, const char *);
static u32 THISCALL command4afd50(u8 *self, u32 cmd, u32 *data) {
  if ((u16)cmd == *(u16 *)(self + 0x66)) {
    u8 *name = self + 0x48;
    if ((*(stricmp_t *)0x676414)(*(const char **)data, *(const char **)name) == 0)
      data[1] = (u32)name;
  }
  return 0;
}
PCREG(4afd50, command4afd50);

// 0x561f50 (GUESS FUN_561f50): r = engine(0x70039c)->slot +0xbc(); tail-jumps to r->slot +0xa4 with the caller's own
// stack arguments (count unknown), so the port is naked like the original.
extern "C" __attribute__((naked)) void guess561f50() {
  asm volatile(
      "push %ebp\n mov %esp, %ebp\n mov 0x70039c, %ecx\n mov (%ecx), %eax\n call *0xbc(%eax)\n"
      "mov (%eax), %edx\n mov %eax, %ecx\n pop %ebp\n jmp *0xa4(%edx)\n");
}
PCREG(561f50, guess561f50);
