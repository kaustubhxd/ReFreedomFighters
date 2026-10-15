#include "ff.h"
extern "C" void FASTCALL ext_4ddcb0(void*,void*,float);
extern "C" void THISCALL ext_4dcb90(void*,void*);
static void THISCALL steer(u8* me,float target){
 float delta=G(float,G(u32,0x70039c)+0x48)*G(float,0x67885c); delta=delta*G(float,0x67da04);
 float current=G(float,me+0x10), goal=G(float,me+0x14); bool update=false;
 if(current>goal){current=current-delta; G(float,me+0x10)=current; if(goal+G(float,0x679540)>current){G(float,me+0x10)=goal;update=true;}}
 else if(goal>current){current=current+delta;G(float,me+0x10)=current;if(current>goal-G(float,0x679540)){G(float,me+0x10)=goal;update=true;}}
 else update=true;
 if(update)G(float,me+0x14)=target;
 float angle=G(float,0x69f1a8);current=G(float,me+0x10);
 if(!(angle>current))angle=_mm_cvtss_f32(_mm_min_ss(_mm_set_ss(G(float,0x69f1a0)),_mm_set_ss(current)));
 float axis[3]={0,1,0}, matrix[9];ext_4ddcb0(matrix,axis,angle);ext_4dcb90((void*)G(u32,G(u32,me+0x18)+8),matrix);
}
PCREG(52a0b0,steer);
