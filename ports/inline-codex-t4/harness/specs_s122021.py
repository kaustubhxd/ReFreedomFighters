from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 hook_rec(c,0x591b20,0,this=True,ret=r.choice([9,9,0,8,10]))
 s=rnd(c,0xe20);e.w32(s+0x44,rnd(c,0x20))
 for off in [0xe0f,0xe13,0xadd,0xa54,0xa5c]:
  bits=r.choice([0,0x80000000,0x3f800000,0xbf800000,0x7fc00000,0x7f800000,0xff800000,struct.unpack('<I',struct.pack('<f',r.uniform(-20,20)))[0]])
  e.w32(s+off,bits)
 return [s]
S(0x5d0df0,'GUESS mouse aim yaw pitch','thiscall',None,ret=None,gen=gen,nan_heap=True)
