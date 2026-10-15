from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
from specs_s61991 import fword

def g4c48a0(c):
    clear_hooks(c);e=c.emu;r=c.rng;rr=lambda:r.getrandbits(32)
    target=obj(c,0x20,{0x3c:pystub(c,1,this=True,ret=0),0x54:pystub(c,1,this=True,ret=rr()),0x4c:pystub(c,1,this=True,ret=rr()),0x68:pystub(c,1,this=True,deref={0:3},ret=rr())})
    vt=e.r32(target);e.w32(vt+0x3c,pystub(c,1,this=True,ret=target))
    me=rnd(c,0xc0)
    return [me,target]
def g64a7f0(c):
    clear_hooks(c);e=c.emu;r=c.rng;rr=lambda:r.getrandbits(32)
    dest=rnd(c,12);arg=rnd(c,12)
    vals=[fword(c) for _ in range(3)] if r.random()<0.8 else [0,0,0]
    def delta(em,k):
        # Record register argument EDX in addition to this and stack arg.
        em.w32(log,em.reg('edx'))
        for j,v in enumerate(vals):em.w32(em.reg('ecx')+4*j,v)
    log=rnd(c,4)
    hook_rec(c,0x446ee0,1,this=True,pop=4,side=delta,ret=rr())
    return [dest,arg,rnd(c,12)]
S(0x4c48a0,'GUESS serialize effect fields','thiscall',None,ret='al',gen=g4c48a0,note='batch61993')
S(0x64a7f0,'GUESS normalize computed vector','stdcall',None,ret=None,gen=g64a7f0,note='batch61993')
