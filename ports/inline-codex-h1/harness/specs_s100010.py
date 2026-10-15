from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct

def g51fad0(c):
    clear_hooks(c); e=c.emu; r=c.rng
    def fill_point(em,k):
        a=em.arg32(0)
        for off in (0,4,8): em.w32(a+off,struct.unpack('<I',struct.pack('<f',r.uniform(-20,20)))[0])
    point=pystub(c,1,this=True,side=fill_point)
    geometry=obj(c,0x30,{0x84:point})
    table_slot=pystub(c,1,this=True,ret=geometry)
    sysobj(c,table_slots={0x58:table_slot})
    vector_slot=pystub(c,1,this=True,deref={0:-12})
    me=obj(c,0x1700,{0x84:vector_slot})
    e.w32(me+0x14,1)
    e.w32(me+0x64,struct.unpack('<I',struct.pack('<f',r.uniform(100,250)))[0])
    for off in (0x1660,0x1664,0x1668):
        e.w32(me+off,struct.unpack('<I',struct.pack('<f',r.uniform(-20,20)))[0])
    hook_rec(c,0x514600,1,ret=lambda em,k:1 if r.randrange(5) else 0)
    def distance(em,k):
        p=em.reg('ecx'); v=em.reg('edx')
        vals=[em.rf32(p+4*i)-em.rf32(v+4*i) for i in range(3)]
        return sum(x*x for x in vals)
    hook_rec(c,0x4e0830,0,this=True,st0=distance)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,rnd(c,0x30)]

S(0x51fad0,'GUESS validate and compare transformed point','thiscall',None,ret='al',gen=g51fad0,note='batch100010')
