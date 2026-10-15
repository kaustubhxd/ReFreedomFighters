from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    sys=sysobj(c); e.w32(sys+0x40,r.choice([0x20010000,0x20020000,0x20030000]))
    stream=obj(c,0x20,{})
    vt=e.r32(stream)
    for off,n in ((0x74,2),(0x84,1),(0x88,1)):
        e.w32(vt+off,pystub(c,n,this=True,stackmark=tuple(range(n))))
    target=rnd(c,0x40)
    me=rnd(c,0x160); e.w32(me+0x44,stream); e.w32(me+0x48,target)
    key=r.randrange(65536); expected=key if r.random()<0.75 else ((key+1)&0xffff)
    e.w16(me+0x115,expected)
    for i in range(6): e.w32(me+0x11b+4*i,r.getrandbits(32))
    for off in (0x84,0x90,0xde):
        for j in range(3): e.w32(me+off+4*j,r.getrandbits(32))
    for off in (0xea,): e.wf32(me+off,r.uniform(-2,2))
    return [me,key,r.choice([0,1])]
S(0x4a64c0,'GUESS apply compact transform when key matches','thiscall',None,ret='eax',gen=gen,note='batch104010')
