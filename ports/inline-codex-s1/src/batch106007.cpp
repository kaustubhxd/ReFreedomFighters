#include "ff.h"
static u8 THISCALL segment_box(float* out,float lx,float ly,float lz,float hx,float hy,float hz,float px,float py,float pz,float dx,float dy,float dz) {
 if(px>=lx && hx>=px && py>=ly && hy>=py && pz>=lz && hz>=pz){*out=0;return 1;}
 float tx=G(float,0x67af2c),ty=tx,tz=tx;
 if(dx!=0.0f)tx=((0.0f>dx?hx:lx)-px)/dx;
 if(dy!=0.0f)ty=((0.0f>dy?hy:ly)-py)/dy;
 if(dz!=0.0f)tz=((0.0f>dz?hz:lz)-pz)/dz;
 float t;
 if(tx>=ty && tx>=tz){
  float y=tx*dy+py,z=tx*dz+pz;t=tx;
  if(ly>y || y>hy || lz>z || z>hz)return 0;
 }else if(ty>=tz){
  float z=ty*dz+pz,x=ty*dx+px;t=ty;
  if(lz>z || z>hz || lx>x || x>hx)return 0;
 }else{
  float x=tz*dx+px,y=tz*dy+py;t=tz;
  if(lx>x || x>hx || ly>y || y>hy)return 0;
 }
 *out=t;
 return t>=0.0f && 1.0f>=t;
}
PCREG(4e2800,segment_box);
