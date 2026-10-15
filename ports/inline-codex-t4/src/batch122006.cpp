#include "ff.h"
static u8 THISCALL fn466eb0(u8* s,u8* stream,u8* ctx){
 vcall<void>(stream,0x68,s);vcall<void>(stream,0x74,s+1);
 vcall<void>(stream,0x6c,s+0x25);vcall<void>(stream,0x50,s+0x31);
 vcall<void>(stream,0x50,s+0x35);vcall<void>(stream,0x40,s+0x39);
 u32 key=(u32)stream;vcall<void>(stream,0x40,&key);
 u32 tmp[4];u8* p=vcall<u8*>(ctx,0x3c0,tmp,key);
 for(u32 i=0;i<16;++i)s[0x3d+i]=p[i];
 return 0;
}
PCREG(466eb0,fn466eb0);
