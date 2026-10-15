from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def fb(c): return struct.unpack('<I',struct.pack('<f',c.rng.uniform(-50.0,50.0)))[0]
def g573c70(c):
    clear_hooks(c);e=c.emu;r=c.rng
    helper=obj(c,0x80,{0x8c:pystub(c,1,this=True,deref={0:3})})
    e.w8(helper+0x48,r.choice([0,1]))
    for off in (0x3c,0x40,0x58): e.w32(helper+off,fb(c))
    ret=pystub(c,1,this=True,ret=helper)
    so=sysobj(c,table_slots={0x58:ret})
    e.w32(so+0x6f,r.randrange(1,100));e.w32(so+0x73,r.randrange(1,100))
    vec=rnd(c,12)
    for i in range(3): e.w32(vec+4*i,fb(c))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    return [rnd(c,0x40),r.getrandbits(32),vec]

S(0x573c70,'GUESS transform vector by engine units','thiscall',None,ret=None,gen=g573c70,note='batch100004')
