import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=obj(c,0x80,{0x84:pystub(c,1,this=True,deref={0:3}),0x88:pystub(c,0,this=True)})
 child=obj(c,16,{0x70:pystub(c,1,this=True,deref={0:3})});e.w32(p+0x48,child)
 for off in [0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c]:e.w32(p+off,fb(r.uniform(-100,100)))
 e.w32(p+0x70,r.choice([0,1,100,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)]));e.w32(p+0x74,fb(r.uniform(-10000,10000)))
 so=sysobj(c);e.w32(so+0x40,r.getrandbits(32))
 return [p]
S(0x4a3860,'GUESS timed movement with target clamp','thiscall',None,ret=None,gen=gen)
