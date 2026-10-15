from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec
import math, struct

def g404ed0(c):
    clear_hooks(c);r=c.rng;e=c.emu
    # Independent magnitudes drive both comparison paths; scales stay finite
    # and nonzero while both output regions begin as observable random bytes.
    a=F(r.choice([-8,-6,-4,-2,1,3,5,7])); b=F(r.choice([-9,-5,-3,2,4,6,8]))
    scale_a=F(r.choice([0.5,1.0,1.5,2.0])); scale_b=F(r.choice([0.5,1.0,1.5,2.0]))
    out_a=rnd(c,4);out_b=rnd(c,4)
    flag=r.randrange(2)
    def floor64(em,k):
        bits=em.arg32(0)|(em.arg32(1)<<32)
        return float(math.floor(struct.unpack('<d',struct.pack('<Q',bits))[0]))
    hook_rec(c,0x634dca,2,pop=0,st0=floor64)
    hook_rec(c,0x7003b0,0,ret=lambda em,k:em.rng.getrandbits(32))
    return [a,b,scale_a,scale_b,out_a,out_b,flag]

S(0x404ed0,'GUESS paired rounded float outputs','cdecl',None,ret=None,gen=g404ed0,note='batch100012')
