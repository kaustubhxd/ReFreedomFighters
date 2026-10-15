#include "ff.h"
extern "C" float THISCALL ext_4e5e80(void*);
extern "C" double VECTORCALL ext_634db2(double,double);
static void THISCALL read_response(u8* me,void* reader){
 float x=ext_4e5e80(reader);if(0.0f>x)x=0.0f-x;
 double power=ext_634db2(G(double,0x692790),(double)(x/G(float,0x67da20)));
 double one=G(double,0x678610);
 *(float*)(me+0x50)=(float)(one-one/power);
 x=ext_4e5e80(reader);*(float*)(me+0x54)=0.0f>x?0.0f:x;
 *(float*)(me+0x58)=ext_4e5e80(reader);
 x=ext_4e5e80(reader);*(float*)(me+0x5c)=0.0f>x?0.0f:x;
 x=ext_4e5e80(reader);*(float*)(me+0x60)=0.0f>x?0.0f:x;
 if(*(float*)(me+0x5c)>*(float*)(me+0x60))*(float*)(me+0x60)=*(float*)(me+0x5c);
 x=ext_4e5e80(reader);*(float*)(me+0x6c)=G(float,0x67da00)>x?bitsf(0x3c23d70a):x;
}
PCREG(4bbd00,read_response);
