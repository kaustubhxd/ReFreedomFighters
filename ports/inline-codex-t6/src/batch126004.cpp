#include "ff.h"
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void FASTCALL ext_441a60(void*,void*);
extern "C" void FASTCALL ext_4de4b0(void*,void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
extern "C" void FASTCALL ext_660c00(u32,u32,u32,u32,u32,u32,void*,void*);
static u32 THISCALL packet(u8* me,u32 dest,u32 unused,u32 mode,u8* record,u32 unused2){
 u8* source=G(u8*,record+8);u32 count=G(u16,source+0x40);float diff[3],matrix[9],copy[9];
 ext_43e920(diff,source+0x2c,me+0x1821d);ext_441a60(diff,me+0x181f9);
 ext_4de4b0(matrix,source+8,me+0x181f9);ext_4de420(copy,matrix);
 float vec[3]={diff[0],diff[1],diff[2]};
 ext_660c00(G(u32,source+0x48),count,mode,G(u32,record+0x14),G(u16,record+0x1e),dest,copy,vec);
 return dest+((((count*2+0x7f)>>5)&0x7fffffc)*4);
}
PCREG(64a1b0,packet);
