import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def fp(n):return struct.pack('<'+'f'*n,*[r.uniform(-20,20) for _ in range(n)])
 me=rnd(c,0x1600);data=rnd(c,0x40);e.w32(me+8,data);e.wbytes(data+0x24,fp(3));e.wbytes(me+0x15df,fp(3));e.wbytes(me+0x378,fp(2));e.w32(me+0x5c,rnd(c,16))
 a=rnd(c,12);b=rnd(c,12);direction=rnd(c,12);angle=rnd(c,4);e.wbytes(a,fp(3))
 if c.case%5==0:e.w32(me+0x37c,0);e.wbytes(a,e.rbytes(data+0x24,12))
 other=fp(3);hook_rec(c,0x523330,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),other))
 rec=e.alloc(24,4)
 def inputs(em,k):em.wbytes(rec,em.rbytes(em.reg('ecx'),12));em.wbytes(rec+12,em.rbytes(em.reg('edx'),12))
 hook_rec(c,0x4e0030,0,st0=r.uniform(-3,3),side=inputs)
 return [me,a,b,direction,angle]
S(0x518380,'GUESS position forward driving car and signed angle','thiscall',None,ret=None,gen=gen)
