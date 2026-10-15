import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 blocks=[rnd(c,64) for _ in range(3)]
 for a in blocks:
  vals=[r.choice([0.,-0.,1.,-1.,r.uniform(-1e5,1e5),r.uniform(-1e-5,1e-5)]) for _ in range(16)]
  e.wbytes(a,struct.pack('<16f',*vals))
 if r.randrange(4)==0:
  e.wbytes(blocks[1],struct.pack('<16f',*([1e20,1.,-1e20,1.]*4)))
  e.wbytes(blocks[2],struct.pack('<16f',*([1.]*16)))
 dst,left,right=blocks
 mode=r.randrange(5)
 if mode==1:dst=left
 elif mode==2:dst=right
 elif mode==3:dst=left=right
 elif mode==4:left=right
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [dst,left,right]
S(0x410f26,'GUESS matrixMultiply','stdcall',None,ret=None,gen=gen)
