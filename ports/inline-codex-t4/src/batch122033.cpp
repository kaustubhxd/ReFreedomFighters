#include "ff.h"
static float THISCALL fn4bca90(u8*,float x){
 float out=0,a=G(float,0x693d3c),b=G(float,0x693d48),c=G(float,0x693d4c);
 float mul=G(float,0x685280),bias=G(float,0x680a60),bias2=G(float,0x680a6c);
 if(x>=a&&b>x){float t=x-a;t=t+t;out=t/G(float,0x693d24);}
 if(x>=b&&c>x){float t=x-b;t=t*mul;t=t/G(float,0x693d28);out=t+bias;}
 if(x>=c&&G(float,0x693d58)>=x){float t=x-c;t=t+t;t=t/G(float,0x693d34);out=t+bias2;}
 float d=G(float,0x693d38),e=G(float,0x693d30);
 if(a>x&&x>d){float t=a-x;t=t+t;out=t/G(float,0x693d68);}
 if(d>=x&&x>e){float t=d-x;t=t*mul;t=t/G(float,0x693d2c);t=t+bias;out=bitsf(fbits(t)^G(u32,0x67af40));}
 if(e>=x&&x>=0){float t=e-x;t=t+t;t=t/e;t=t+bias2;out=bitsf(fbits(t)^G(u32,0x67af40));}
 return out;
}
PCREG(4bca90,fn4bca90);
