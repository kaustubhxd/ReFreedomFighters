import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0xb0);point=rnd(c,12);extra=rnd(c,12);e.w8(p+0xa4,r.choice([0,1,1,1]))
 mat=r.choice([[1,0,0,0,1,0,0,0,1],[-1,0,0,0,1,0,0,0,-1],[r.uniform(-1,1) for _ in range(9)]])
 for k,x in enumerate(mat):e.w32(p+0x68+4*k,fb(x))
 for k in range(3):
  center=r.uniform(-3,3);bound=r.uniform(0.1,5);padding=r.choice([0,0.1,-0.1,r.uniform(-1,1)])
  e.w32(p+0x8c+4*k,fb(center));e.w32(p+0x98+4*k,fb(bound));e.w32(extra+4*k,fb(padding));e.w32(point+4*k,fb(center+r.uniform(-6,6)))
 return [p,point,extra]
S(0x4ea900,'GUESS eject point from expanded box','thiscall',None,ret='al',gen=gen)
