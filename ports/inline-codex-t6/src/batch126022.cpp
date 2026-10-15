#include "ff.h"
extern "C" void THISCALL ext_523330(void*,void*);
extern "C" void THISCALL ext_520e40(void*,void*);
extern "C" void THISCALL ext_528100(void*,void*,void*);
extern "C" void THISCALL ext_525380(void*,void*,void*);
extern "C" void FASTCALL ext_4de420(void*,void*);
static void THISCALL initTank(u8* me,u32 flag){
 if(G(u8,me+0x133)){vcall<void>(me,0x80,(void*)(me+0x6c),(void*)(me+0x60));for(int i=0;i<3;++i)G(u32,me+0x2d8+4*i)=G(u32,me+0x6c+4*i);}
 else{G(float,me+0x2f0)=(flag&255)?1.0f:-1.0f;u8* ref=G(u8*,me+0x5c);for(int i=0;i<3;++i)G(u32,me+0x60+4*i)=G(u32,ref+8+4*i);float vec[3];ext_523330(G(void*,me+0x5c),vec);ext_520e40(me,vec);}
 G(float,me+0x64)=G(float,me+0x64)+G(float,0x67cd40);
 for(int i=0;i<3;++i){G(u32,me+0x2624+4*i)=i==2?0x3f800000:0;G(u32,me+0x2630+4*i)=i==2?0x3f800000:0;}
 vcall<void>(me+0x263c,4,(void*)(me+0x2624),(void*)(me+0x2630));ext_528100(me+0x2fd,me+0x60,me+0x2d8);ext_525380(me+0x2fd,me+0x6c,me+0x60);
 for(int i=0;i<3;++i)G(u32,me+0x90+4*i)=G(u32,me+0x60+4*i);ext_4de420(me+0x9c,me+0x6c);
}
PCREG(520f20,initTank);
