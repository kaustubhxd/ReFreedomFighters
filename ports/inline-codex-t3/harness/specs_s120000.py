from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub
import math

def check(c):
    clear_hooks(c)
    e,r=c.emu,c.rng
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    o=rnd(c,0x90); p=rnd(c,12)
    for k in range(3):
        lo=r.uniform(-4000,4000)
        extent=r.choice([0.0,-0.0,1.0,-1.0,0.125,1000.0,r.uniform(-5000,5000)])
        e.wf32(o+6+4*k,lo); e.wf32(o+0x12+4*k,lo+extent)
        e.w32(o+0x3c+4*k,r.choice([0,1,8,256,0xffffffff,0x7fffffff,r.getrandbits(32)]))
        e.wf32(p+4*k,r.choice([lo,lo+extent,lo-30,r.uniform(-1e5,1e5),float('inf'),float('-inf'),float('nan')]))
    # Real 43e920 computes vector subtraction; leave it running to exercise SSE extents.
    vals=bytes(r.getrandbits(8) for _ in range(6))
    def out(em,k): em.wbytes(em.arg32(0),vals)
    hook_rec(c,0x530e80,5,this=True,ret=r.choice([0,1,0x100,r.getrandbits(32)]),
             stackmark=(0,),deref={1:-6},side=out)
    return [o,p]
S(0x52e240,'ZPFOctree_packed::CheckPosition','thiscall',None,ret='al',gen=check)
