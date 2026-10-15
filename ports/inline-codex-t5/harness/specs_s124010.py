from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 n=r.choice([-1,0,1,2,3,8]);stride=r.choice([1,2,3,4]);idx=r.randrange(4)
 matrix=rnd(c,0x20);e.w32(matrix,n&0xffffffff)
 buf=rnd(c,512);e.w32(matrix+12,buf)
 dest=rnd(c,128)
 for p,size in [(buf,512),(dest,128)]:
  for off in range(0,size,4):e.wbytes(p+off,struct.pack('<f',r.choice([0.,-0.,1.,-1.,r.uniform(-100,100),float('inf'),float('nan')])) )
 hook_rec(c,0x405800,3,pop=0,ret=idx)
 return [matrix,dest,stride,r.choice([0,1,2,0xffffffff])]
S(0x405bf0,'GUESS subtract or divide selected matrix row','cdecl',None,ret='eax',gen=g,nan_heap=True,note='batch124010')
