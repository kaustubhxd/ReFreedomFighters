from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 source=obj(c,0x20,{4:pystub(c,0,this=True,st0=r.uniform(-1000,1000))})
 hook_rec(c,0x5fa630,0,pop=0,ret=source)
 e.w32(0x6762ec,pystub(c,1,pop=0))
 n=r.randrange(1,8);idx=r.randrange(n)
 s=rnd(c,0xbe+20*n);a=rnd(c,20);cur=s+0xbe+20*idx
 e.w32(s+0xb6,cur);e.w32(s+0xba,n)
 e.w32(a,r.choice([1,1,2,3,0]));e.w32(cur,r.choice([0,3,2]))
 if idx:
  e.w32(cur-20,r.choice([1,1,2]));e.w16(cur-8,int.from_bytes(e.rbytes(a+12,2),"little") if r.randrange(2) else r.randrange(65536))
 return [s,a]
S(0x5f3c90,'GUESS append coalesced ring event','thiscall',None,ret=None,gen=gen)
