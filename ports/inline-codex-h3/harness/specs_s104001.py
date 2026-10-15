from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    selfp=rnd(c,0x70)
    mapobj=rnd(c,0x40)
    rows=r.randrange(1,5)
    data=rnd(c,rows*0x38)
    e.w32(mapobj+0x28,data); e.w32(mapobj+0x2c,rows)
    e.w32(selfp+0x4b,mapobj)
    e.wf32(selfp+0x53,r.choice([0.5,1.0,2.0,3.0]))
    e.wf32(selfp+0x20,r.choice([0.25,0.5,1.0,2.0]))
    a=r.choice([-0.3,-0.1,0.0,0.2,0.7,1.0]); b=r.choice([-0.2,0.0,0.1,0.4,0.8])
    return [selfp,F(a),F(b)]
S(0x522f60,'GUESS sample map and return signed angle','thiscall',None,ret='st0',gen=gen,note='batch104001')
