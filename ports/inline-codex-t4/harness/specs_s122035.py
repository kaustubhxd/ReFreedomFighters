from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 src=rnd(c,12);dst=src if r.randrange(3)==0 else rnd(c,12);angle=rnd(c,12)
 for p in [src,angle]:
  for j in range(3):e.wbytes(p+4*j,struct.pack('<f',r.choice([0.,-0.,1.,-1.,r.uniform(-10,10)])))
 return [dst,src,angle]
S(0x4e0ab0,'GUESS rotate vector by Euler angles','fastcall',None,ret=None,gen=gen)
