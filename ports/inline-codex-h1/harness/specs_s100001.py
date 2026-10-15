from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-200.0,200.0)))[0]

def g57d8a0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    main=obj(c,0x80,{0x70:pystub(c,1,this=True,deref={0:3}),0x74:pystub(c,1,this=True,deref={0:3})})
    other=obj(c,0x80,{0x70:pystub(c,1,this=True,deref={0:3}),0x74:pystub(c,1,this=True,deref={0:3})})
    child=rnd(c,0x60); parent=rnd(c,0x20); e.w32(parent+8,child)
    child2=rnd(c,0x60); parent2=rnd(c,0x20); e.w32(parent2+8,child2)
    for base in (main+0x24,child+0x24,child2+0x24):
        for j in range(3): e.w32(base+4*j,fbits(c))
    # The constructor-like direct callees are replaced with observable no-op hooks;
    # the two vector getters below retain their actual field-copy semantics.
    hook_rec(c,0x562440,0,ret=0,this=True)
    hook_rec(c,0x57dd10,0,ret=0,this=True)
    def getter(em,k):
        dst=em.arg32(0); objp=em.reg('ecx')
        for j in range(3): em.w32(dst+4*j,em.r32(objp+0x24+4*j))
    hook_rec(c,0x4db500,1,ret=0,pop=4,this=True,side=getter,stackmark=(0,))
    hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'))
    me=rnd(c,0x380)
    e.w32(me+0x310,main);e.w32(me+0x314,other);e.w32(me+0x54,parent);e.w32(me+0x58,parent2)
    return [me]

S(0x57d8a0,'GUESS combine queried vectors and dispatch','thiscall',None,ret=None,gen=g57d8a0,note='batch100001')
