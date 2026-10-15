from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
import struct

def g655cf0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    type_obj=rnd(c,0x30); is_direct=bool(r.randrange(2))
    e.w16(type_obj+2,6 if is_direct else r.randrange(1,6))
    e.w32(type_obj+0x10,0 if is_direct else rnd(c,0x20))
    source=rnd(c,0x50)
    for off in (4,8,0xc,0x30,0x34,0x38):
        e.w32(source+off,struct.unpack('<I',struct.pack('<f',r.uniform(-10,10)))[0])
    out=rnd(c,0x20);dest=rnd(c,0x20)
    direct=pystub(c,3,this=True,ret=lambda em,k:r.getrandbits(8))
    def lookup(em,k): return type_obj if em.arg32(0)==type_obj else source
    root=obj(c,0x40,{0xc:pystub(c,1,this=True,ret=lookup),0x15c:direct})
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [root,type_obj,out,dest]

S(0x655cf0,'GUESS update transformed vector from typed source','thiscall',None,ret='al',gen=g655cf0,note='batch100013')
