import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
from specs_s61991 import fword,cookie

def g501e40(c):
    clear_hooks(c);e=c.emu;r=c.rng;rr=lambda:r.getrandbits(32)
    def fill(em,k):
        for i,n in [(0,9),(1,3)]:
            for j in range(n): em.w32(em.arg32(i)+4*j,fword(c))
    target=obj(c,0x40,{0x80:pystub(c,2,this=True,stackmark=(0,1),ret=rr(),side=fill),0x7c:pystub(c,2,this=True,deref={0:9,1:3},ret=rr())})
    me=rnd(c,0x30);e.w32(me+0xc,target)
    arg=rnd(c,0x20);e.w32(arg+4,rnd(c,0x40))
    v=rnd(c,4);e.w32(v,fword(c))
    hook_rec(c,0x5003d0,1,this=True,ret=v)
    def mat(em,k):
        for j in range(9):em.w32(em.reg('ecx')+4*j,fword(c))
    hook_rec(c,0x4deb20,4,this='mark',ret=rr(),side=mat)
    # Both pointer operands address caller locals; log their contents through a heap record.
    log=rnd(c,72)
    def transform(em,k):
        for reg,off in [('ecx',0),('edx',36)]:
            p=em.reg(reg)
            for j in range(9):em.w32(log+off+4*j,em.r32(p+4*j))
    hook_rec(c,0x4de4f0,0,this='mark',ret=rr(),side=transform)
    cookie(c)
    return [me,arg]
def g435fa0(c):
    clear_hooks(c);e=c.emu;r=c.rng
    me=rnd(c,0x90);e.w32(me+0x1c,r.choice([0,1,2,0xffffffff]))
    e.w32(me+0x10,obj(c,0x20,{0x10:pystub(c,0,this=True,ret=r.choice([0,1,0x100]))}))
    so=sysobj(c)
    e.w32(so+0x190f,obj(c,0x20,{0xd8:pystub(c,0,this=True,ret=r.choice([0,1,2,640,0xffffffff])),0xdc:pystub(c,0,this=True,ret=r.choice([0,1,2,480,0xffffffff]))}))
    for off in [0x64,0x68]:e.w32(me+off,fword(c))
    return [me,rnd(c,8)]
def g466b70(c):
    clear_hooks(c);e=c.emu;r=c.rng
    me=rnd(c,0x50)
    for off in [0x31,0x35]:e.w32(me+off,fword(c) if r.random()<0.9 else r.choice([0,0x80000000]))
    so=sysobj(c);e.w32(so+0x40,r.choice([0,1,10,100,1000,0xffffffff]))
    return [me]
S(0x501e40,'GUESS query transform and update target','thiscall',None,ret='eax',gen=g501e40,note='batch61992')
S(0x435fa0,'GUESS clamp normalized screen coordinates','thiscall',None,ret=None,gen=g435fa0,note='batch61992')
S(0x466b70,'GUESS signed timing fade fraction','thiscall',None,ret='st0',gen=g466b70,note='batch61992')
