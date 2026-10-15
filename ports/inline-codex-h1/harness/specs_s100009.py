from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct

def g448f80(c):
    clear_hooks(c); e=c.emu; r=c.rng
    def record3():
        return pystub(c,3,this=True,deref={2:-12})
    def record4():
        return pystub(c,4,this=True)
    target=obj(c,0x30,{0xa8:record4(),0xb0:record3(),0xac:record3()})
    resource=rnd(c,0x90); e.w32(resource+0x6c,r.getrandbits(32))
    context=obj(c,0x30,{})
    def fill_result(em,k):
        v=struct.unpack('<I',struct.pack('<f',r.uniform(-3,3)))[0]
        em.w32(em.arg32(1)+0x1c,v)
    result=pystub(c,2,this=True,side=fill_result)
    service=obj(c,0x30,{0x80:result})
    so=sysobj(c)
    e.w32(so+0x1aa3,context)
    e.w32(context+0x18,service)
    me=rnd(c,0x40); e.w32(me+8,resource)
    e.w32(me+0x14,(r.getrandbits(32)&~1)|(1 if r.randrange(2) else 0))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,target,r.getrandbits(32),r.getrandbits(32),r.getrandbits(32)]

S(0x448f80,'GUESS conditional vector parameter dispatch','thiscall',None,ret=None,gen=g448f80,note='batch100009')
