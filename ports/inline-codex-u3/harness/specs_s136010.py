from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x1200);n=r.choice([0,1,2,3,4,7,8,16,20]);header=rnd(c,16)
 block=rnd(c,16*n+96);src=block+32;out=r.choice([src,src+4,src-4,block+16]) if r.randrange(2) else rnd(c,max(16,16*n))
 hook_rec(c,0x41e290,1,pop=0,ret=lambda em,k:header if k==0 else out)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,r.getrandbits(32),n,src,r.getrandbits(32)]
S(0x654800,'GUESS allocate and negate vector array','thiscall',None,ret='eax',gen=gen)
