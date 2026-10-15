from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 coords=struct.pack('<ff',r.uniform(-100,100),r.uniform(-100,100))
 def fill(em,k):em.wbytes(em.arg32(0),coords)
 s=obj(c,0x650,{0x308:pystub(c,1,this=True,stackmark=(0,),side=fill),0x304:pystub(c,1,this=True,deref={0:2},ret=r.getrandbits(32))})
 sys=rnd(c,0xa00);e.w32(0x70039c,sys)
 for so,sy in [(0x7f,0x9e7),(0x83,0x9eb)]:
  bits=struct.pack('<f',r.uniform(-100,100));e.wbytes(s+so,bits);e.wbytes(sys+sy,bits if r.randrange(2) else struct.pack('<f',r.uniform(-100,100)))
 e.wbytes(s+0x97,struct.pack('<f',r.choice([0.,1.,-1.,0.5,2.5])))
 e.wbytes(s+0x63b,bytes([r.randrange(2)]))
 return [s]
S(0x4f3b20,'GUESS update mouse delta','thiscall',None,ret='eax',gen=gen)
