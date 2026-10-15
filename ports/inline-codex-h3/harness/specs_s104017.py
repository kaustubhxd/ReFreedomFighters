from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,sysobj

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    n=5
    selfp=rnd(c,0x280)
    e.w32(selfp+0x48,n)
    for i in range(max(n,5)):
        rec=selfp+0x4c+i*0x28
        for j in range(10): e.w32(rec+4*j,r.getrandbits(32))
        e.w32(rec+0xc,r.randrange(0,4000))
        e.wf32(rec+0x14,r.uniform(0.25,6.0))
        e.wf32(rec+0x18,r.uniform(-2.0,3.0))
    system=sysobj(c)
    e.w32(system+0x40,r.randrange(0,5000))
    src=rnd(c,0x28)
    for j in range(10): e.w32(src+4*j,r.getrandbits(32))
    return [selfp,src]
S(0x5de090,'GUESS replace minimum age record','thiscall',None,ret='eax',gen=gen,note='batch104017')
