from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    query=obj(c,0x20,{0x114:pystub(c,3,this=True,ret=r.choice([0,1]))})
    manager=rnd(c,0x40); e.w32(manager+0x18,query)
    sys=sysobj(c); e.w32(sys+0x1aa3,manager)
    me=rnd(c,0x80); e.w32(me+0x3c,r.getrandbits(32)); e.w32(me+0x6c,r.getrandbits(32))
    check=r.choice([0,0,1,1,0xff])
    if r.random()<0.25:
        dead=obj(c,0x20,{0:pystub(c,0,this=True)}); e.w32(me+0x54,dead)
    else: e.w32(me+0x54,0)
    for off in (0x30,0x34,0x38,0x40,0x44,0x48): e.wf32(me+off,r.uniform(-10,10))
    return [me,check]
S(0x4da1d0,'GUESS update bounded area vector and radius','thiscall',None,ret=None,gen=gen,note='batch104008')
