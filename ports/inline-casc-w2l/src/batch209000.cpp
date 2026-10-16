#include "ff.h"
extern "C" u32 ext_4690b0(u32, u32);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_485900(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66b0fc);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));
  ecx = edx = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(4294967295));
  if (((eax & 0xff) & (u32)(1)) == 0) goto L4859ac;
  if (((eax & 0xff) & (u32)(4)) != 0) goto L48599e;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340976), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(1));
  if ((eax & eax) == 0) goto L485989;
  eax = ((u32(STDCALL *)(void))(eax))();
  ecx = edx = 0;
  eax = esi;
  SEH_LEAVE();
  return eax;
  L485989:;
  __builtin_trap();
  L48599e:;
  eax = ext_4690b0((u32)(esi), (u32)(204));
  ecx = edx = 0;
  L4859ac:;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(485900, lifted_485900);


