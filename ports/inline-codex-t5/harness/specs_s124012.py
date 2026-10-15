from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 params=[rnd(c,8) for _ in range(4)]
 for p in params[:2]:e.wbytes(p,struct.pack('<f',r.choice([0.,-0.,1.,-1.,float('nan'),float('inf'),r.uniform(-100,100)])))
 for p in params[2:]:e.w32(p,r.choice([0,1,2,r.getrandbits(32)]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:params[em.arg32(0)])
 entries={i:rnd(c,0x20) for i in [3,4,5,6]}
 hook_rec(c,0x5a46f0,1,this=True,ret=lambda em,k:entries[em.arg32(0)])
 timer=rnd(c,0x70);manager=rnd(c,0x2c30);e.w32(manager+0x2c21,timer);e.w32(0x7003b8,manager)
 me=rnd(c,16);e.w32(me+4,rnd(c,16))
 return [me]
S(0x5600a0,'GUESS set multiplayer timer parameters','stdcall',None,ret=None,gen=g,nan_heap=True,note='batch124012')
