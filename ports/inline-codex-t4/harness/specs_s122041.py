from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x2000)
 for off in [0x8c,0x90]:e.w32(s+off,r.randrange(7))
 for off in [0xa8,0x74,0x68,0x7c,0x6c,0x78]:e.wbytes(s+off,struct.pack('<f',r.uniform(-10,10)))
 hook_rec(c,0x529e30,2,this=True);hook_rec(c,0x52a0b0,1,this=True)
 return [s]
S(0x525f30,'GUESS update wheel pairs and steering','thiscall',None,ret=None,gen=gen)
