from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 inner=obj(c,16,{0x2c:pystub(c,3,pop=0)})
 log=obj(c,16,{0x20:pystub(c,2,this=True,ret=inner)});e.w32(0x700390,log)
 objid=obj(c,16,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))})
 source=rnd(c,8);st=r.choice([0,1,2,3,3,4,4,5,0xff]);e.w32(source,objid if st==4 else r.getrandbits(32));e.wbytes(source+4,bytes([st]))
 target=rnd(c,8);e.wbytes(target+4,bytes([r.choice([0,0,2,2,1,3,4,0xff])]))
 values=[r.getrandbits(32),0,0x3f800000,0x7fc00000,0xff800000]
 def output(em,k):em.w32(em.arg32(1),r.choice(values))
 scene=obj(c,16,{0x84:pystub(c,2,this=True,stackmark=[1],side=output)})
 table=obj(c,16,{0x138:pystub(c,0,this=True,ret=scene)})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,table)
 a=rnd(c,16);b=rnd(c,16)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:source if em.reg('ecx')==a else target)
 me=rnd(c,16);e.w32(me+4,a);e.w32(me+8,b)
 return [me]
S(0x50f2e0,'GUESS retrieve scene float parameter','stdcall',None,ret=None,gen=g,nan_heap=True,note='batch124017')
