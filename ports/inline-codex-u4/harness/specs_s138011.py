from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng
 block=rnd(c,0x500);src=block+0x180
 delta=r.choice([0,1,-1,4,-4,16,-16,64,-64,0x180])
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [src+delta,src]
S(0x56eb60,'GUESS copySettings','thiscall',None,ret='eax',gen=gen)
