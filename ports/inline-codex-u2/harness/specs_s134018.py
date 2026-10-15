from pilot import S
from pe_emu import F
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;n=r.choice([-1,0,1,2,4,8,12]);me=rnd(c,0x40);model=rnd(c,0x800);ids=rnd(c,max(n,1)*4);scores=rnd(c,max(n,1)*4);limits=rnd(c,max(n,1)*4);table=rnd(c,17*4);context=rnd(c,32)
 e.w32(me,n);e.w32(me+4,model);e.w32(me+0x18,ids);e.w32(me+0x24,r.choice([0,1,2,4,31,32,33,255]));e.wf32(model+0x760,r.uniform(-100,100))
 prev=0
 for i in range(max(n,1)):
  id=prev if r.random()<0.5 else r.choice([-100,-1,0,1,16,17,100,0x7fffffff]);prev=id;e.w32(ids+i*4,id);v=r.uniform(-10,10);e.wf32(scores+i*4,v);e.wf32(limits+i*4,r.choice([v,v+0.001,v-0.001,r.uniform(-10,10)]))
 def side(em,k):em.w32(context+4*(k%8),em.r32(context+4*(k%8))^0x13579bdf)
 hook_rec(c,0x4043a0,7,pop=0,side=side);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,table,scores,limits,context,F(r.uniform(-100,100))]
S(0x4042c0,'GUESS group maxima and dispatch threshold hits','cdecl',None,ret=None,gen=gen)
