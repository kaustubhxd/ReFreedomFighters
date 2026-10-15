from pilot import S
from pe_emu import F
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng
 color=rnd(c,0x20)
 s=obj(c,0x20,{0xc:pystub(c,1,this=True,ret=color)})
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,r.getrandbits(32),F(r.choice([0.,-0.,1.,-1.,2.,100.,r.uniform(-3,3),float('nan'),float('inf'),-float('inf')]))]
S(0x656970,'GUESS scaleColor','thiscall',None,ret=None,gen=gen)
