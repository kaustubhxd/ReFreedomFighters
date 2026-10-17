from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def fb(c): return struct.unpack('<I',struct.pack('<f',c.rng.uniform(-5.0,5.0)))[0]
def g4dceb0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    callback=obj(c,0x20,{0:pystub(c,1,this=True,ret=r.getrandbits(32))})
    so=sysobj(c,table_size=0x5d40)
    table=e.r32(so+0x9b);e.w32(table+0x5d31,callback)
    node2=rnd(c,0x80);node1=rnd(c,0x80);e.w32(node1+0x50,node2)
    for node in (node1,node2):
        for off in (0x24,0x28,0x2c): e.w32(node+off,fb(c))
        for off in range(0,0x24,4): e.w32(node+off,fb(c))
    me=rnd(c,0x80);e.w32(me+0x50,node1)
    arg=rnd(c,12)
    for i in range(3): e.w32(arg+4*i,fb(c))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    return [me,arg]

S(0x4dceb0,'GUESS transform vector through nested nodes','thiscall',None,ret=None,gen=g4dceb0,note='batch100005')
