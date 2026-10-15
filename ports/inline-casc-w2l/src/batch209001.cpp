#include "ff.h"
extern "C" u32 STDCALL ext_54f870(u32, u32);
extern "C" u32 THISCALL ext_434fb0(u32);
extern "C" u32 THISCALL ext_43de40(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_4451d0(u32, u32, u32, u32);
extern "C" u32 THISCALL ext_45c3e0(u32);
extern "C" u32 THISCALL ext_469870(u32);
extern "C" u32 THISCALL ext_49a3e0(u32);
extern "C" u32 THISCALL ext_4cbe80(u32, u32);
extern "C" u32 THISCALL ext_4cbec0(u32);
extern "C" u32 THISCALL ext_4ccba0(u32);
extern "C" u32 THISCALL ext_4d8e60(u32);
extern "C" u32 THISCALL ext_4dbb00(u32, u32);
extern "C" u32 THISCALL ext_4dcdf0(u32, u32);
extern "C" u32 THISCALL ext_4de7a0(u32);
extern "C" u32 THISCALL ext_4e7dd0(u32, u32);
extern "C" u32 THISCALL ext_4e7e80(u32);
extern "C" u32 THISCALL ext_5044c0(u32);
extern "C" u32 THISCALL ext_51a9f0(u32, u32);
extern "C" u32 THISCALL ext_51b530(u32);
extern "C" u32 THISCALL ext_5f9700(u32, u32, u32);
extern "C" u32 THISCALL ext_5fb5b0(u32);
extern "C" u32 THISCALL ext_5fb600(u32);
extern "C" u32 THISCALL ext_603900(u32);
extern "C" u32 THISCALL ext_6132a0(u32);
extern "C" u32 ext_41e290(u32);
extern "C" u32 ext_41e2c0(u32);
extern "C" u32 ext_634273(u32, u32);

#define SEH_ENTER(H) volatile SehRecord reg; reg.next = seh_head(); reg.handler = (H); reg.state = -1; seh_set_head(&reg)
#define SEH_LEAVE() seh_set_head(reg.next)

extern "C" u32 THISCALL lifted_6035a0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)((u32)(7051812)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_603900(ecx);
  ecx = edx = 0;
  eax = ext_41e2c0(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 12), sizeof v); (u32)v; }));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(6932840)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  SEH_LEAVE();
  return eax;
}
PCREG(6035a0, lifted_6035a0);

extern "C" u32 THISCALL lifted_4478d0(u32 ecx_in) {
  SEH_ENTER(0x6656a0);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });
  { u32 v = (u32)((u32)(6806576)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_4dbb00(ecx, (u32)(0));
  ecx = edx = 0;
  ecx = esi;
  eax = ext_45c3e0(ecx);
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(4478d0, lifted_4478d0);

extern "C" u32 THISCALL lifted_5facc0(u32 ecx_in) {
  SEH_ENTER(0x66d9ec);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  reg.state = (s32)((u32)(0));
  eax = ext_5fb5b0(ecx);
  ecx = edx = 0;
  ecx = esi;
  reg.state = (s32)((u32)(1));
  eax = ext_54f870(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; }), (u32)(19));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(5facc0, lifted_5facc0);

extern "C" u32 THISCALL lifted_5ab460(u32 ecx_in) {
  SEH_ENTER(0x6684b6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = (eax - edx);
  eax = (u32)((s32)eax >> (u32)(4));
  reg.state = (s32)((u32)(0));
  if ((eax & eax) == 0) goto L5ab4a1;
  eax = (eax << (u32)(4));
  eax = ext_54f870((u32)(edx), (u32)(eax));
  ecx = edx = 0;
  L5ab4a1:;
  SEH_LEAVE();
  return eax;
}
PCREG(5ab460, lifted_5ab460);

extern "C" u32 THISCALL lifted_565870(u32 ecx_in) {
  SEH_ENTER(0x6684b6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  edx = ecx;
  { u32 v = (u32)((u32)(6974476)); __builtin_memcpy((void *)(u32)(edx + 384), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(edx + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(edx), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(edx));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(565870, lifted_565870);

extern "C" u32 THISCALL lifted_499d50(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(6875464)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_49a3e0(ecx);
  ecx = edx = 0;
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L499d9b;
  eax = ext_634273((u32)(esi), (u32)(316));
  ecx = edx = 0;
  L499d9b:;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(499d50, lifted_499d50);

extern "C" u32 THISCALL lifted_4d8d50(u32 ecx_in) {
  SEH_ENTER(0x6656a0);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  eax = ext_4d8e60(ecx);
  ecx = edx = 0;
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi), sizeof v); (u32)v; });
  if ((esi & esi) == 0) goto L4d8d92;
  ecx = esi;
  eax = ext_4e7e80(ecx);
  ecx = edx = 0;
  eax = ext_634273((u32)(esi), (u32)(33));
  ecx = edx = 0;
  L4d8d92:;
  SEH_LEAVE();
  return eax;
}
PCREG(4d8d50, lifted_4d8d50);

extern "C" u32 THISCALL lifted_4d8180(u32 ecx_in, u32 a0, u32 a1) {
  SEH_ENTER(0x66966b);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  ecx = (u32)(esi + 4);
  { u32 v = (u32)((u32)(6908948)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_4cbe80(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));
  ecx = edx = 0;
  ecx = (u32)(esi + 132);
  reg.state = (s32)((u32)(0));
  eax = ext_4cbe80(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }));
  ecx = edx = 0;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(4d8180, lifted_4d8180);

extern "C" u32 THISCALL lifted_4fb930(u32 ecx_in) {
  SEH_ENTER(0x66c468);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  eax = ext_469870(ecx);
  ecx = edx = 0;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  ecx = (u32)(esi + 152);
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(6931632)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_4ccba0(ecx);
  ecx = edx = 0;
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(4fb930, lifted_4fb930);

extern "C" u32 THISCALL lifted_6125f0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(7067040)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_6132a0(ecx);
  ecx = edx = 0;
  { u32 v = (u32)((u32)(7067028)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L612641;
  eax = ext_634273((u32)(esi), (u32)(139628));
  ecx = edx = 0;
  L612641:;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(6125f0, lifted_6125f0);

extern "C" u32 THISCALL lifted_433f30(u32 ecx_in) {
  SEH_ENTER(0x6656a0);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)((u32)(6792112)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_434fb0(ecx);
  ecx = edx = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });
  if ((ecx & ecx) == 0) goto L433f6d;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));
  ecx = edx = 0;
  L433f6d:;
  ecx = (u32)(esi + 140);
  eax = ext_4cbec0(ecx);
  ecx = edx = 0;
  ecx = (u32)(esi + 12);
  eax = ext_4cbec0(ecx);
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(433f30, lifted_433f30);

extern "C" u32 THISCALL lifted_606ce0(u32 ecx_in) {
  SEH_ENTER(0x66d9ec);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  reg.state = (s32)((u32)(0));
  eax = ext_5fb600(ecx);
  ecx = edx = 0;
  ecx = (u32)(esi + 3);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 8), sizeof v); (u32)v; });
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = (eax - edx);
  eax = (u32)((s32)eax >> (u32)(2));
  reg.state = (s32)((u32)(1));
  if ((eax & eax) == 0) goto L606d30;
  eax = (eax << (u32)(2));
  eax = ext_54f870((u32)(edx), (u32)(eax));
  ecx = edx = 0;
  L606d30:;
  SEH_LEAVE();
  return eax;
}
PCREG(606ce0, lifted_606ce0);

extern "C" u32 THISCALL lifted_500990(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x669c28);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  { u32 v = (u32)((u32)(1)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 8), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(6932928)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 16), &v, sizeof v); }
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; }) != (u32)(0)) goto L5009ef;
  eax = ext_5044c0(ecx);
  ecx = edx = 0;
  L5009ef:;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(500990, lifted_500990);

extern "C" u32 THISCALL lifted_5b2100(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x66c278);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  eax = ext_4451d0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));
  ecx = edx = 0;
  ecx = (u32)(esi + 412);
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(7018064)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 408), &v, sizeof v); }
  { u8 v = (u8)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 407), &v, sizeof v); }
  eax = ext_4de7a0(ecx);
  ecx = edx = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 456), &v, sizeof v); }
  eax = esi;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 452), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 448), &v, sizeof v); }
  SEH_LEAVE();
  return eax;
}
PCREG(5b2100, lifted_5b2100);

extern "C" u32 THISCALL lifted_4be090(u32 ecx_in) {
  SEH_ENTER(0x66c468);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  eax = ext_469870(ecx);
  ecx = edx = 0;
  { u32 v = (u32)((({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 4), sizeof v); (u32)v; }) | (u32)(32))); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  ecx = (u32)(esi + 173);
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(6895704)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 109), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 105), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 145), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 137), &v, sizeof v); }
  eax = ext_4de7a0(ecx);
  ecx = edx = 0;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(4be090, lifted_4be090);

extern "C" u32 THISCALL lifted_4a3360(u32 ecx_in) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)((u32)(6879964)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_634273(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; }), (u32)(10));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(4a3360, lifted_4a3360);

extern "C" u32 THISCALL lifted_608220(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 20), sizeof v); (u32)v; });
  { u32 v = (u32)((u32)(7063724)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  reg.state = (s32)((u32)(0));
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax), sizeof v); (u32)v; });
  eax = ((u32(STDCALL *)(u32))(*(u32 *)(edx + 8)))((u32)(eax));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(7063692)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  if ((({ u8 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }) & (u32)(1)) == 0) goto L608272;
  eax = ext_634273((u32)(esi), (u32)(28));
  ecx = edx = 0;
  L608272:;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(608220, lifted_608220);

extern "C" u32 THISCALL lifted_51afb0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66a238);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  edi = ecx;
  { u32 v = (u32)(edi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  esi = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; });
  eax = ext_51a9f0(ecx, (u32)(esi));
  ecx = edx = 0;
  reg.state = (s32)((u32)(0));
  { u32 v = (u32)((u32)(6943804)); __builtin_memcpy((void *)(u32)(edi), &v, sizeof v); }
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(edi + 28), &v, sizeof v); }
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7346176), sizeof v); (u32)v; }) != (u32)(0)) goto L51b003;
  ecx = edi;
  eax = ext_51b530(ecx);
  ecx = edx = 0;
  L51b003:;
  eax = edi;
  SEH_LEAVE();
  return eax;
}
PCREG(51afb0, lifted_51afb0);

extern "C" u32 THISCALL lifted_45ad90(u32 ecx_in, u32 a0, u32 a1, u32 a2) {
  SEH_ENTER(0x666568);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  __builtin_memcpy(F + 0x300 + 12, &a1, 4);
  __builtin_memcpy(F + 0x300 + 16, &a2, 4);
  esi = ecx;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  eax = ext_43de40(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 12), sizeof v); (u32)v; }), ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 16), sizeof v); (u32)v; }));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(6831696)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 24), &v, sizeof v); }
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 28), &v, sizeof v); }
  { u32 v = (u32)((u32)(1092616192)); __builtin_memcpy((void *)(u32)(esi + 32), &v, sizeof v); }
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 8), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  eax = ext_4dcdf0(ecx, (u32)(0));
  ecx = edx = 0;
  eax = esi;
  SEH_LEAVE();
  return eax;
}
PCREG(45ad90, lifted_45ad90);

extern "C" u32 THISCALL lifted_5bfc00(u32 ecx_in) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)((u32)(7026868)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_41e2c0(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 80), sizeof v); (u32)v; }));
  ecx = edx = 0;
  eax = ext_41e2c0(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 76), sizeof v); (u32)v; }));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(5bfc00, lifted_5bfc00);

extern "C" u32 THISCALL lifted_5dc060(u32 ecx_in) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 72), sizeof v); (u32)v; });
  { u32 v = (u32)((u32)(7039672)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  if ((ecx & ecx) == 0) goto L5dc098;
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 0)))(ecx, (u32)(1));
  ecx = edx = 0;
  L5dc098:;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(5dc060, lifted_5dc060);

extern "C" u32 THISCALL lifted_4d8ce0(u32 ecx_in, u32 a0) {
  SEH_ENTER(0x66971f);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  __builtin_memcpy(F + 0x300 + 8, &a0, 4);
  esi = ecx;
  eax = ext_41e290((u32)(33));
  ecx = edx = 0;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(EBP - 16), &v, sizeof v); }
  reg.state = (s32)((u32)(0));
  if ((eax & eax) == 0) goto L4d8d2a;
  ecx = eax;
  eax = ext_4e7dd0(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP + 8), sizeof v); (u32)v; }));
  ecx = edx = 0;
  goto L4d8d2c;
  L4d8d2a:;
  eax = 0;
  L4d8d2c:;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = esi;
  { u16 v = (u16)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 4), &v, sizeof v); }
  SEH_LEAVE();
  return eax;
}
PCREG(4d8ce0, lifted_4d8ce0);

extern "C" u32 THISCALL lifted_4b9160(u32 ecx_in) {
  SEH_ENTER(0x665fd6);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = 0, ebx = 0, esi = 0, edi = 0;
  esi = ecx;
  { u32 v = (u32)((u32)(6892080)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ext_634273(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 141), sizeof v); (u32)v; }), (u32)(109));
  ecx = edx = 0;
  eax = ext_634273(({ u32 v; __builtin_memcpy(&v, (void *)(u32)(esi + 109), sizeof v); (u32)v; }), (u32)(44));
  ecx = edx = 0;
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 68), &v, sizeof v); }
  { u32 v = (u32)((u32)(0)); __builtin_memcpy((void *)(u32)(esi + 48), &v, sizeof v); }
  { u32 v = (u32)((u32)(6842484)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  reg.state = (s32)((u32)(0));
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(eax + 155), sizeof v); (u32)v; });
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 52)))(ecx, (u32)(esi));
  ecx = edx = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(4b9160, lifted_4b9160);

extern "C" u32 FASTCALL lifted_504660(u32 ecx_in, u32 edx_in) {
  SEH_ENTER(0x669ca7);
  u8 F[0x400] __attribute__((aligned(16)));
  u32 EBP = (u32)(F + 0x300);
  u32 eax = 0, ecx = ecx_in, edx = edx_in, ebx = 0, esi = 0, edi = 0;
  ebx = edx;
  edi = ecx;
  eax = ext_41e290((u32)(20));
  ecx = edx = 0;
  esi = eax;
  { u32 v = (u32)(esi); __builtin_memcpy((void *)(u32)(EBP - 20), &v, sizeof v); }
  reg.state = (s32)((u32)(0));
  if ((esi & esi) == 0) goto L504700;
  ecx = esi;
  eax = ext_5f9700(ecx, (u32)(edi), (u32)(ebx));
  ecx = edx = 0;
  reg.state = (s32)((u32)(1));
  { u32 v = (u32)((u32)(6932928)); __builtin_memcpy((void *)(u32)(esi), &v, sizeof v); }
  if (({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7343728), sizeof v); (u32)v; }) != (u32)(0)) goto L5046c9;
  ecx = esi;
  eax = ext_5044c0(ecx);
  ecx = edx = 0;
  L5046c9:;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(edi + 21), sizeof v); (u32)v; });
  edx = (u32)(EBP - 16);
  eax = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(eax + 64)))(ecx, (u32)(edx));
  ecx = edx = 0;
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(7340956), sizeof v); (u32)v; });
  ecx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx + 155), sizeof v); (u32)v; });
  edx = ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(ecx), sizeof v); (u32)v; });
  eax = ((u32(THISCALL *)(u32, u32))(*(u32 *)(edx + 88)))(ecx, ({ u32 v; __builtin_memcpy(&v, (void *)(u32)(EBP - 16), sizeof v); (u32)v; }));
  ecx = edx = 0;
  { u32 v = (u32)(eax); __builtin_memcpy((void *)(u32)(esi + 12), &v, sizeof v); }
  eax = esi;
  SEH_LEAVE();
  return eax;
  L504700:;
  eax = 0;
  SEH_LEAVE();
  return eax;
}
PCREG(504660, lifted_504660);
