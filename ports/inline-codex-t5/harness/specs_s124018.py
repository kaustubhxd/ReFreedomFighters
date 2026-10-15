from pilot import S
from pe_emu import F
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 # Capture XMM0 at the external conversion boundary, including nonfinite values.
 returns=[r.getrandbits(32) for _ in range(3)]
 hook_rec(c,0x633910,0,pop=0,ret=lambda em,k:returns[k],side=lambda em,k:em.calllog.append(('convert-float',em.reg('xmm0')&0xffffffff)))
 rgb=rnd(c,12)
 for i in range(3):e.w32(rgb+4*i,r.choice([0,1,31,63,127,254,255,256,r.randrange(256),r.getrandbits(32)]))
 t=r.choice([0.,1.,-1.,2.,.5,float('nan'),float('inf'),float('-inf'),r.uniform(-2,2)])
 return [rgb,F(t)]
S(0x636540,'GUESS blend color channels toward luminance','thiscall',None,ret=None,gen=g,note='batch124018',tries=2)
