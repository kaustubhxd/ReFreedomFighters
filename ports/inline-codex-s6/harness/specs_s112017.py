from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 ctx=rnd(c,0x260);enc=rnd(c,0x50);scratch=ctx+0x22c
 e.w32(ctx+0x40,pystub(c,3,pop=0) if r.randrange(4) else 0);e.w32(ctx+0x50,r.randrange(2));e.w32(enc+0x44,r.choice([0,1,2,4]));e.w32(enc+0x20,pystub(c,2,pop=0,ret=r.randrange(20)));e.w32(enc+0x24,pystub(c,2,pop=0,ret=r.getrandbits(32)))
 results=[r.randrange(2),r.randrange(2)];growth=r.randrange(2);values=[rnd(c,32),rnd(c,32)];ends=[rnd(c,32),rnd(c,32)];full=[r.randrange(2),r.randrange(2)];null=[r.randrange(4)==0,r.randrange(4)==0]
 def convert(em,k):
  em.w32(scratch+12,ends[k]);em.w32(scratch+8,ends[k] if full[k] else ends[k]+16);em.w32(scratch+16,0 if null[k] else values[k])
 hook_rec(c,0x620180,4,pop=0,side=convert,ret=lambda em,k:results[k])
 hook_rec(c,0x6206e0,1,pop=0,ret=growth,side=lambda em,k:em.w32(scratch+12,ends[0]+4))
 hook_rec(c,0x620cb0,4,pop=0);hook_rec(c,0x6200d0,1,pop=0);hook_rec(c,0x6204a0,1,pop=0)
 return [ctx,enc,r.getrandbits(32),r.getrandbits(32)]
S(0x620d50,'GUESS parse_pair_and_notify','cdecl',None,ret='eax',gen=gen)
