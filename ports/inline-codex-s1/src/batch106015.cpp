#include "ff.h"
static float THISCALL sample_track(u8* me,u32* out,u32,u32,u32,u32){
 *out=0;u8* owner=*(u8**)(me+4);u32 off;
 if(*(u32*)(owner+0x417)&0x800)off=0xf5;
 else if(!vcall<u8>(owner,0x534) && (*(u32*)(*(u8**)(me+4)+0x417)&0x400))off=0x10d;
 else off=0xdd;
 void* track=me+off;
 void* p=vcall<void*>(track,0x14,*(float*)(me+0xc));
 if(p)*out=*(u32*)p;
 *(float*)(me+0xc)=vcall<float>(track,0xc,*(float*)(me+0xc));
 vcall<void>(me+0xdd,4);
 return *(float*)(me+0xc);
}
PCREG(488900,sample_track);
