from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 offset=r.uniform(-10,10)
 def transform(em,k):
  p=em.arg32(0)
  for j in range(3):
   x=struct.unpack('<f',em.rbytes(p+4*j,4))[0];em.wbytes(p+4*j,struct.pack('<f',x+offset))
 anchor=obj(c,0x20,{0x84:pystub(c,1,this=True,deref={0:3},side=transform)})
 s=rnd(c,0x2000);e.w32(s+0x89,anchor)
 for off,base in [(0x8d,0xe91),(0x91,0x1829)]:
  n=r.randrange(5);e.w32(s+off,n)
  for i in range(n):
   for j in range(3):e.wbytes(s+base+307*i+4*j,struct.pack('<f',r.uniform(-100,100)))
 hook_rec(c,0x516620,1,this=True,deref={0:3})
 return [s]
S(0x529020,'GUESS dampers follow anchor positions','thiscall',None,ret=None,gen=gen)
