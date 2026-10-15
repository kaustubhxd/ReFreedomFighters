from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    vecs=[]
    for _ in range(4):
        p=rnd(c,12)
        for j in range(3): e.wf32(p+4*j,r.uniform(-6.0,6.0))
        vecs.append(p)
    t=F(r.uniform(0.0,1.5))
    return vecs+[t]
S(0x460870,'GUESS three vector angle test','stdcall',None,ret='al',gen=gen,note='batch104014')
