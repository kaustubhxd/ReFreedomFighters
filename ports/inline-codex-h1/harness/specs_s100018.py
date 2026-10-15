from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec
import struct

def vec(c):
    a=rnd(c,12)
    for off in (0,4,8):c.emu.w32(a+off,struct.unpack('<I',struct.pack('<f',c.rng.uniform(-5,5)))[0])
    return a

def g44f8b0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    me=rnd(c,0x240);e.w32(me+0x44,1)
    holder=rnd(c,0x10);records=rnd(c,0x30);e.w32(holder,records);e.w32(me+0x7c,holder)
    va=vec(c);vb=vec(c);edx_seen=rnd(c,12)
    def save_edx(em,k):
        p=em.reg('edx')
        for j in range(3):em.w32(edx_seen+4*j,em.r32(p+4*j))
    hook_rec(c,0x44fde0,5,this=True,ret=0,deref={0:3,1:1,2:1,3:1,4:3},side=save_edx)
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('ecx'))
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [me,va,vb,F(r.uniform(-2,2))]

S(0x44f8b0,'GUESS transform point against candidate records','thiscall',None,ret=None,gen=g44f8b0,note='batch100018')
