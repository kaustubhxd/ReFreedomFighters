#include "ff.h"
static long double THISCALL fn46b4c0(u8* s,u8* target,float distance){
 u8* damage=vcall<u8*>(target,0x328);
 if(!damage){u8* log=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x6887c4,(u32)0x89c);typedef void(*Log)(u8*,u32);(*(Log*)(*(u8**)log+0x2c))(log,0x688bf8);return 0;}
 if(*(float*)(s+0xb0)>=distance){float x=vcall<float>(damage,0x324);return (long double)*(float*)(s+0xb8)*(long double)x;}
 if(distance>*(float*)(s+0xb4)){float x=vcall<float>(damage,0x328);return (long double)*(float*)(s+0xb8)*(long double)x;}
 float lo=vcall<float>(damage,0x324);float hi=vcall<float>(damage,0x328);float diff=(float)((long double)lo-(long double)hi);
 float x=vcall<float>(damage,0x324);float low=*(float*)(s+0xb0);float alpha=distance-low;float span=*(float*)(s+0xb4)-low;alpha=alpha/span;alpha=alpha*diff;
 float result=(float)((long double)x-(long double)alpha);return (long double)*(float*)(s+0xb8)*(long double)result;
}
PCREG(46b4c0,fn46b4c0);
