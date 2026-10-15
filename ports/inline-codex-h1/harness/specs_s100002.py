from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def fbits(x): return struct.unpack('<I',struct.pack('<f',x))[0]
def g5d5ef0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    table=obj(c,0x200,{0x114:pystub(c,4,this=True,ret=r.randrange(0x10000))})
    so=sysobj(c,table_slots={0x114:pystub(c,4,this=True,ret=r.randrange(0x10000))})
    # Use the exact engine instance installed by sysobj and give its unaligned scale field a stable value.
    e.w32(so+0x6f,r.randrange(20,500))
    child=obj(c,0x100,{
        0xbc:pystub(c,1,this=True,ret=r.getrandbits(32)),
        0x258:pystub(c,2,this=True,deref={1:2}),
        0x24c:pystub(c,1,this=True,deref={0:3})})
    me=rnd(c,0x90)
    e.w32(me+0x44,child);e.w32(me+0x54,fbits(r.uniform(0.25,15.0)))
    for off in (0x5e,0x62,0x66): e.w32(me+off,r.randrange(0,1000))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    return [me]

S(0x5d5ef0,'GUESS initialize scaled engine coordinates','thiscall',None,ret=None,gen=g5d5ef0,note='batch100002')
