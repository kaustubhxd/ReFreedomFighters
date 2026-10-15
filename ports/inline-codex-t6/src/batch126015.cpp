#include "ff.h"
extern "C" void THISCALL ext_4de7a0(void*);
extern "C" void FASTCALL ext_4ddcb0(void*,void*,float);
extern "C" long double FASTCALL ext_4e0830(void*,void*);
extern "C" void THISCALL ext_514890(void*,u32,void*,void*,void*,u32,u32);
static void THISCALL cannon(u8* me){
 float matrix[9];ext_4de7a0(matrix);vcall<void>(me,0x384);
 float cur=G(float,me+0x268d),goal=G(float,me+0x2691),step=G(float,G(u32,0x70039c)+0x48)*G(float,0x6a066c);
 if(cur>goal){cur=cur-step;G(float,me+0x268d)=cur;if(goal+G(float,0x679540)>cur)G(float,me+0x268d)=goal;}
 else if(goal>cur){cur=cur+step;G(float,me+0x268d)=cur;if(cur>goal-G(float,0x679540))G(float,me+0x268d)=goal;}
 float angle=bitsf(fbits(G(float,me+0x268d))^0x80000000);ext_4ddcb0(matrix,matrix+6,angle);
 bool far=true;if(G(u32,me+0x2610)){float distance=(float)ext_4e0830(me+0x25fd,me+0x60);far=distance>G(float,me+0x261c);}
 ext_514890(me,G(u32,me+0x25e1),me+0x25fd,matrix,me+0x25e5,(G(u32,me+0x2620)&&far)?1:0,G(u8,me+0x2609));
}
PCREG(521ab0,cannon);
