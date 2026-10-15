from pilot import S
from recruits_util import rnd,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=rnd(c,0x60);n=r.randrange(9);off=r.choice([0,r.randrange(1,13)])
 e.w32(me+0x44,n);e.w32(me+0x48,off)
 same=r.choice([0,1,2,255]);all_same=r.random()<.3
 for i in range(max(n,1)):
  item=rnd(c,16);e.w32(me+4+4*i,item);e.wbytes(item+off,bytes([same if all_same else r.choice([0,1,2,255,r.randrange(256)])]))
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=r.choice([0.,.25,.5,.75,.999999,1.,r.random()]))})
 hook_rec(c,0x633654,0,ret=lambda em,k:em.reg('eax'));e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x5c2cb0,'choose minimum counter with random ties','thiscall',None,ret='eax',gen=gen)
