from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x439e50,1,this=True);hook_rec(c,0x4386a0,2,this=True);hook_rec(c,e.r32(0x67a7dc+4),2,this=True)
 name=rnd(c,80);e.wbytes(name,bytes(r.randrange(65,91) for _ in range(r.randrange(65)))+b'\0');hook_rec(c,0x4cc1d0,0,this=True,ret=name if r.randrange(3) else 0);hook_rec(c,0x41e290,1,pop=0,ret=rnd(c,80))
 src=rnd(c,0xc0)
 for off in (0xa7,0xab):e.w32(src+off,r.choice([0,r.getrandbits(32)]))
 for group in range(2):
  n=r.randrange(5)
  for i in range(4):e.w32(src+0x80+group*16+4*i,r.getrandbits(32) if i<n else 0xffffffff)
 return [rnd(c,0x60),r.getrandbits(32),src]
S(0x436640,'GUESS construct_input_action','thiscall',None,ret='eax',gen=gen)
