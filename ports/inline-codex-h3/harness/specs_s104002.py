from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    selfp=rnd(c,0x120); entity=rnd(c,0x420); out=rnd(c,4)
    flags=r.choice([0,0x400,0x800,0xc00,0x1000])
    e.w32(entity+0x417,flags)
    e.w32(selfp+4,entity); e.wf32(selfp+0xc,r.choice([-2.0,-0.2,0.0,0.25,0.75,1.0,2.0]))
    pred=pystub(c,0,this=True,ret=r.randrange(2))
    ev=e.alloc(0x540,4); e.w32(ev,0)
    e.w32(entity,ev); e.w32(ev+0x534,pred)
    for off in (0xdd,0xf5,0x10d):
        result=rnd(c,0x20); e.w32(result,r.getrandbits(32))
        value=0.25
        vt=e.alloc(0x20,4)
        e.w32(vt+0x14,pystub(c,1,this=True,ret=result))
        e.w32(vt+0xc,pystub(c,1,this=True,st0=value))
        e.w32(vt+4,pystub(c,0,this=True))
        e.w32(selfp+off,vt)
    return [selfp,out,r.getrandbits(32),r.getrandbits(32),r.getrandbits(32),r.getrandbits(32)]
S(0x488900,'GUESS select resource and advance timer','thiscall',None,ret='st0',gen=gen,note='batch104002')
