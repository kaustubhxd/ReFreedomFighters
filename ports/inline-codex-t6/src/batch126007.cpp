#include "ff.h"
extern "C" void THISCALL ext_523330(void*,void*);
extern "C" void THISCALL ext_4e09b0(void*);
static void THISCALL direction(u8* me,float target,u32 mode){
 void* ref=G(void*,me+0x5c);long double value=vcall<long double>(ref,0xc);float delta=(float)((long double)target-value);float sign=delta>0?1.0f:-1.0f;
 float vec[3];ext_523330(G(void*,me+0x5c),vec);float signedValue=(float)(vcall<long double>(G(void*,me+0x5c),0x14)*(long double)sign);
 if(!(signedValue>0))ext_4e09b0(vec);
 float dot=G(float,me+0x15df)*vec[0];float other=G(float,me+0x15e3)*vec[1];other=other+dot;dot=G(float,me+0x15e7)*vec[2];other=other+dot;
 vcall<void>(me,other>0?0x360:0x364,target,mode);
}
PCREG(517c60,direction);
