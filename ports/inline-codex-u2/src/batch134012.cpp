#include "ff.h"
struct PushPayload{float pos[3];float direction[3];float mass;u32 handle;};
static u8 THISCALL fn515100(u8* s){
 void* actor=G(void*,s+0x2af);float p[3]={0,0,0};vcall<void>(actor,0x84,p);vcall<void>(s,0x8c,p);
 if((double)bitsf(fbits(p[0])&0x7fffffffu)>(double)G(float,s+0x21b)||(double)bitsf(fbits(p[1])&0x7fffffffu)>(double)G(float,s+0x22b)||(double)bitsf(fbits(p[2])&0x7fffffffu)>(double)G(float,s+0x223))return 0;
 PushPayload data;for(int i=0;i<3;++i)data.pos[i]=G(float,s+0x29b+4*i);
 data.direction[0]=p[0]>0?bitsf(0x3f35c28f):bitsf(0xbf35c28f);data.direction[1]=0;data.direction[2]=bitsf(0x3f35c28f);
 vcall<void>(s,0x88,data.direction);
 data.mass=G(float,G(u8*,s+0x5c)+0x24);
 data.handle=vcall<u32>(G(void*,G(u8*,0x70039c)+0x9b),0x4c,s);
 vcall<void>(s,0x130,actor,(u32)G(u16,s+0x2d6),&data);return 1;
}
PCREG(515100,fn515100);
