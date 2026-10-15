#include "ff.h"
extern "C" void FASTCALL ext_441940(void*,void*);
extern "C" float FASTCALL ext_4e0030(void*,void*);
static void THISCALL set_pair(u8* me,const u32* a,const u32* b) {
 for(int i=0;i<3;i++)*(u32*)(me+4+4*i)=a[i];
 for(int i=0;i<3;i++)*(u32*)(me+0x10+4*i)=b[i];
 ext_441940(me+0x10,me+0x1c);
 float dot=ext_4e0030(me+4,me+0x10);
 vcall<void>(me+0x28,4,0, dot,0);
}
PCREG(527420,set_pair);
