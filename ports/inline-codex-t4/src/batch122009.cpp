#include "ff.h"
static u8* output(){return vcall<u8*>(G(u8*,0x70039c),0x190);}
typedef void(*Print0)(u8*,u32,u32,u32);
typedef void(*PrintD)(u8*,u32,u32,u32,double);
static void THISCALL fn4bcc60(u8* s){
 if(*(u32*)(s+0x60)==0){u8* p=output();(*(Print0*)(*(u8**)p+0x184))(p,0,8,0x693c94);}
 if(*(u32*)(s+0x60)==1){u8* p=output();(*(Print0*)(*(u8**)p+0x184))(p,0,8,0x693cac);}
 u8* p=output();(*(PrintD*)(*(u8**)p+0x184))(p,0,11,0x693cc4,(double)*(float*)(s+0xd1));
 p=output();(*(PrintD*)(*(u8**)p+0x184))(p,0,12,0x693ccc,(double)*(float*)(s+0xd5));
}
PCREG(4bcc60,fn4bcc60);
