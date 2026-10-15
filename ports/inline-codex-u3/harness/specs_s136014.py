from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x30);arg=rnd(c,0x10);lst=rnd(c,0x20);e.w32(arg+4,lst)
 target=obj(c,0x20,{0x12c:pystub(c,2,this=True)});e.w32(s+0xc,target)
 values=[rnd(c,8) for _ in range(6)]
 resource=rnd(c,0x20);handle=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=resource)})
 tag=r.choice([0,1,2,3,4,255]);e.wbytes(values[1]+4,bytes([tag]));e.w32(values[1],handle if tag==4 else resource)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:values[em.arg32(0)])
 sysobj(c,table_slots={0x114:pystub(c,5,this=True,deref={4:4},ret=r.getrandbits(32))})
 log=obj(c,0x30,{0x2c:pystub(c,3,pop=0)});logger=obj(c,0x30,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 e.w32(0x7003b0,pystub(c,0,pop=0,ret=r.getrandbits(32)))
 return [s,arg]
S(0x502ba0,'GUESS resolve resource and register expression','thiscall',None,ret=None,gen=gen)
