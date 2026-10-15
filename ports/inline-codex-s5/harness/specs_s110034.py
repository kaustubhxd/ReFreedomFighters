from pilot import S
from recruits_util import clear_hooks,rnd,pystub,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0x20);shift=r.choice([0,1,31,32,33,63,64,r.randrange(128)]);n=r.choice([0,1,7,8,9,15,16,17])
 p=rnd(c,0x1c);a=rnd(c,n*4+16);first=r.choice([0,p])
 hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:first if k==0 else a)
 return [t,shift,n]
S(0x4cc930,'GUESS bit mask array constructor','thiscall',None,ret='eax',gen=gen)
