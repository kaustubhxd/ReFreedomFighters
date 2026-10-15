#include "ff.h"
extern "C" void THISCALL ext_562440(u8*);
extern "C" void THISCALL ext_57dd10(u8*);
extern "C" void THISCALL ext_4db500(u8*, u32*);
extern "C" void FASTCALL ext_43e8e0(u32*, u32*, u32*);
static void THISCALL fn57d8a0(u8* s) {
 ext_562440(s); ext_57dd10(s);
 u32* a=(u32*)(s+0x34b); u32 b[3], sum[3];
 ext_4db500(*(u8**)(*(u8**)(s+0x310)+8),a);
 ext_4db500(*(u8**)(*(u8**)(s+0x54)+8),b);
 ext_43e8e0(sum,a,b);
 vcall<void>(*(u8**)(s+0x310),0x70,sum);
 b[0]^=G(u32,0x67af40); b[1]^=G(u32,0x67af40);
 vcall<void>(*(u8**)(s+0x314),0x70,b);
}
PCREG(57d8a0,fn57d8a0);
