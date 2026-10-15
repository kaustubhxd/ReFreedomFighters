#include "ff.h"
extern "C" double VECTORCALL ext_634de2(double);
static float min_second(float a,float b){return _mm_cvtss_f32(_mm_min_ss(_mm_set_ss(a),_mm_set_ss(b)));}
static void THISCALL update_tilt(u8* me){
 ((void(*)())G(void*,0x7003b0))();
 if(*(u32*)(me+0x34a))return;
 float f=G(float,0x69f9d0);
 if(*(u32*)(me+0x469))f=(float)ext_634de2((double)(*(float*)(me+0x597)/G(float,0x69f9dc)));
 *(float*)(me+0x232)=f;
 void* sink=vcall<void*>(G(void*,0x70039c),0x190);
 typedef void(*Print)(void*,u32,u32,u32,double,double);
 (*(Print*)(*(u8**)sink+0x184))(sink,10,0x24,0x69f998,(double)*(float*)(me+0x236),(double)*(float*)(me+0x23a));
 f=*(float*)(me+0x232);
 *(float*)(me+0x232)=0.0f>f?0.0f:min_second(G(float,0x69f9d4),f);
 f=*(float*)(me+0x23a);
 *(float*)(me+0x23a)=G(float,0x69f9e4)>f?G(float,0x69f9e4):min_second(G(float,0x69f9d8),f);
}
PCREG(51e470,update_tilt);
