from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
import struct

def f32(c):
    x = c.rng.uniform(-10000.0, 10000.0)
    return struct.unpack('<I', struct.pack('<f', x))[0]

def g4f9140(c):
    clear_hooks(c); e=c.emu; r=c.rng
    # Target query result and the bounds object used by the integer-to-float conversion.
    val = r.randrange(0, 100000)
    target=obj(c,0x40,{})
    e.w32(target+0x24,f32(c))
    comp=rnd(c,0x60)
    e.w32(comp+0x30,f32(c)); e.w32(comp+0x40,f32(c))
    query=obj(c,0x20,{0x290:pystub(c,1,this=True,ret=val)})
    e.w32(query+8,comp)
    limit=obj(c,0x20,{0x70:pystub(c,1,this=True,deref={0:3})})
    e.w32(limit+8,target)
    me=rnd(c,0x220)
    e.w32(me+0x1bb,query);e.w32(me+0x1bf,limit)
    # /GS helper must retain the cookie in ECX and preserve EAX as the exe helper does.
    hook_rec(c,0x633654,0,ret=lambda em,k: em.reg('eax'))
    return [me,r.randrange(0,0xffffffff)]

S(0x4f9140,'GUESS update queried integer and report float','thiscall',None,ret=None,gen=g4f9140,note='batch100000')
