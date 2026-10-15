from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,reftab
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=obj(c,0x40,{0x238:pystub(c,0,this=True),0x220:pystub(c,1,this=True)})
 e.w32(s+8,rnd(c,0x80));ids=[r.getrandbits(32) for _ in range(r.randrange(5))]
 li=reftab(c,ids);e.w32(s+0x1c,li if r.randrange(4) else 0)
 targets=[obj(c,0x20,{0x230:pystub(c,1,this=True)}) if r.randrange(3) else 0 for _ in ids]
 tab=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=lambda em,k:targets[k])})
 data=bytes(r.getrandbits(8) for _ in range(60))
 def fill(em,k):em.wbytes(em.arg32(1),data)
 cb=obj(c,0x20,{0x88:pystub(c,2,this=True,stackmark=(1,),side=fill),0xa8:pystub(c,2,this=True,deref={1:15})})
 sys=rnd(c,0x1b00);cfg=rnd(c,0x40);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab);e.w32(sys+0x1aa3,cfg);e.w32(cfg+0x18,cb)
 return [s,F(r.uniform(-100,100))]
S(0x449a00,'GUESS propagate animation time','thiscall',None,ret=None,gen=gen)
