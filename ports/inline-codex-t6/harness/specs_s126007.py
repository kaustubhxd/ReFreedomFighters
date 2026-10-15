from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 target=r.choice([0,1,-1,0.5,-0.5,5])
 val=r.choice([target,0,1,-1,2,-2]);other=r.choice([0,1,-1,0.5,-0.5])
 ref=obj(c,0x20,{0xc:pystub(c,0,this=True,st0=val),0x14:pystub(c,0,this=True,st0=other)})
 me=obj(c,0x1600,{0x360:pystub(c,2,this=True),0x364:pystub(c,2,this=True)})
 e.w32(me+0x5c,ref)
 for i in range(3):e.wbytes(me+0x15df+4*i,struct.pack('<f',r.uniform(-10,10)))
 vec=struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)])
 def side(em,k):em.wbytes(em.arg32(0),vec)
 hook_rec(c,0x523330,1,this=True,nullflag=(0,),side=side)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,F(target),r.getrandbits(32)]
S(0x517c60,'GUESS directional virtual dispatch','thiscall',None,ret=None,gen=gen)
