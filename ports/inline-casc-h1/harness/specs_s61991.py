import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def fword(c):
    return struct.unpack('<I',struct.pack('<f',c.rng.uniform(-100,100)))[0]
def cookie(c):
    hook_rec(c,0x633654,0,ret=lambda e,k:e.reg('eax'),pop=0,this=True)
def g5c97f0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    me=rnd(c,0x600)
    idx=r.randrange(4);e.w32(me+0x64,idx)
    for off in [0x78,0x7c,0x80,0xd9+idx*0x82,0x2fa]: e.w32(me+off,fword(c))
    e.w32(me+0x44,obj(c,0x40,{0x78:pystub(c,1,ret=r.getrandbits(32),this=True,deref={0:3})}))
    log=rnd(c,16)
    def first(em,k):
        for j in range(3):
            em.w32(log+4*j,em.r32(em.reg('ecx')+4*j))
            em.w32(em.reg('ecx')+4*j,fword(c))
    hook_rec(c,0x4e0d80,1,pop=4,this='mark',ret=0,side=first)
    def second(em,k):
        em.w32(log+12,em.reg('edx'))
        for j in range(3):em.w32(em.reg('ecx')+4*j,em.r32(em.arg32(0)+4*j))
    hook_rec(c,0x43e8e0,1,pop=4,this=True,deref={0:3},ret=0,side=second)
    cookie(c)
    return [me]
def g5592f0(c):
    clear_hooks(c);e=c.emu;r=c.rng;rr=lambda:r.getrandbits(32)
    def fill(em,k):
        for arg,n in [(0,9),(1,3)]:
            for j in range(n):em.w32(em.arg32(arg)+4*j,fword(c))
    child=obj(c,0x40,{0x84:pystub(c,1,pop=4,this=True,deref={0:3},ret=rr())})
    target=obj(c,0x40,{0x3a0:pystub(c,2,pop=8,this=True,stackmark=(0,1),side=fill,ret=rr()),0x390:pystub(c,1,this=True,ret=rr()),0x20:pystub(c,0,this=True,ret=child)})
    me=rnd(c,0x40);e.w32(me+0x1c,target)
    e.w32(0x7003b8,rnd(c,0x40))
    hook_rec(c,0x589c20,1,pop=4,this=True,ret=rnd(c,0x40))
    hook_rec(c,0x596940,4,pop=16,this=True,deref={1:3},ret=rr())
    cookie(c)
    return [me,rr()]
S(0x5c97f0,'GUESS update indexed offset and transformed position','thiscall',None,ret='eax',gen=g5c97f0,note='batch61991')
S(0x5592f0,'GUESS query position and dispatch effect','thiscall',None,ret='eax',gen=g5592f0,note='batch61991')
