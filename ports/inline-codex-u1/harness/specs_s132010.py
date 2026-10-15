from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,12);a=r.getrandbits(32);b=r.choice([a,0,0xffffffff,r.getrandbits(32)])
 e.w32(p,a);e.w32(p+4,b)
 out=r.choice([p,p+4,p+8])
 t=r.choice([0.0,1.0,0.5,-1.0,2.0,r.uniform(-4,4),0.25,0.75,-0.5])
 return [out,p,p+4,F(t)]
S(0x616e00,'GUESS packed color interpolation','fastcall',None,ret=None,gen=gen)
