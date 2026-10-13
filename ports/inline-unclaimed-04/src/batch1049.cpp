// batch1049.cpp - unclaimed-04 batch 49 (docs/20-unclaimed-04.md): 0x54ed70 and 0x4d1d70 (residue 3).
// 0x54ed70: thiscall, two stack arguments (ret 8). The first argument's vtable slot 0 is called as stdcall with
// (object, IID 0x6be1b0, this+4); a negative result returns 0. Otherwise, when the low byte of the second argument is set,
// this's vtable slot 0x10 is called (thiscall, no arguments). Returns 1. GUESS: QueryInterface-style.
// 0x4d1d70: stdcall, one argument (ret 4). Calls helper 0x4d1cf0 (stdcall, one argument); a non-null result gives its dword
// at +0x10. Otherwise the manager at global 0x700390 gets slot 0x20 (file 0x695fec, line 0x23f) and the logger it returns gets
// slot 0x2c as a cdecl call with message 0x696124. Returns 0. GUESS: log path.
#include "ff.h"

extern "C" void *__attribute__((stdcall)) ext_4d1cf0(u32 key);  // helper, hooked by address (GUESS)

typedef u32(THISCALL *query_thiscall_t)(void *self);
typedef u32(THISCALL *mgr_t)(void *self, u32 file, u32 line);
typedef void(__attribute__((cdecl)) *log_t)(void *logger, u32 msg);
// the exe leaves this in ecx for this call; the callee takes obj, the IID and the out pointer on the stack
typedef s32(THISCALL *qi_t)(void *self, void *obj, u32 iid, void *out);

// 0x54ed70
static u32 THISCALL unk54ed70(u8 *self, u8 *obj, u32 flag) {
  s32 hr = ((qi_t)(*(u32 *)(*(u32 *)obj)))(self, obj, 0x6be1b0, self + 4);
  if (hr < 0) return 0;
  if ((u8)flag != 0) ((query_thiscall_t)(*(u32 *)(*(u32 *)self + 0x10)))(self);
  return 1;
}
PCREG(54ed70, unk54ed70);

// 0x4d1d70
static u32 __attribute__((stdcall)) unk4d1d70(u32 key) {
  u8 *p = (u8 *)ext_4d1cf0(key);
  if (p != 0) return *(u32 *)(p + 0x10);
  u8 *mgr = *(u8 **)0x700390;
  u8 *logger = (u8 *)((mgr_t)(*(u32 *)(*(u32 *)mgr + 0x20)))(mgr, 0x695fec, 0x23f);
  ((log_t)(*(u32 *)(*(u32 *)logger + 0x2c)))(logger, 0x696124);
  return 0;
}
PCREG(4d1d70, unk4d1d70);
