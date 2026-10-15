from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;me=rnd(c,0x100)
 driver=obj(c,0x40,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});e.w32(me+0x44,driver);e.w8(me+0x48,r.choice([0,1,2,255]))
 e.w32(me+0x5f,r.randrange(3));e.w32(me+0x70,r.randrange(3))
 for off,n in [(0x74,12),(0xa4,12),(0xd4,4)]:e.wbytes(me+off,struct.pack('<'+'f'*n,*[r.choice([0.,-0.,1.,3.14159,r.uniform(-100,100)]) for _ in range(n)]))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x4fe700,'GUESS animate transform with sine offsets','thiscall',None,ret=None,gen=gen)
