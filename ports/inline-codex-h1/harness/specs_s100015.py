from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
import struct

def fb(x): return struct.unpack('<I',struct.pack('<f',x))[0]
def g65c530(c):
    clear_hooks(c);e=c.emu;r=c.rng
    params=[r.uniform(-4,3),r.uniform(-4,3),r.uniform(-2,30),r.uniform(-2,30)]
    for i,v in enumerate(params):e.w32(0x8131c0+4*i,fb(v))
    arg_obj=obj(c,0x40,{0x240:pystub(c,1,this=True,side=lambda em,k:em.w32(em.arg32(0),fb(r.uniform(-4,3))))})
    iface=obj(c,0x40,{0x134:pystub(c,4,this=True)})
    me=rnd(c,0x10100);e.w32(me+0x10051,iface)
    for off in (0x10061,0x10065,0x10069,0x1006d):e.w32(me+off,r.randrange(-100,101)&0xffffffff)
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,arg_obj]

S(0x65c530,'GUESS clamp particle bounds and submit derived vectors','thiscall',None,ret=None,gen=g65c530,note='batch100015')
