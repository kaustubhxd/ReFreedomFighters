from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c,nargs=3)
 a=rnd(c,8);b=rnd(c,8);out=rnd(c,8);e.wbytes(a+4,bytes([r.choice([0,1,2,3,4,5])]));e.wbytes(out+4,bytes([r.choice([0,1,2,3,255])]))
 nameobj=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))});e.w32(a,nameobj)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:[a,b,out][k])
 found=rnd(c,32) if r.randrange(2) else 0
 actor=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x25c:pystub(c,2,this=True,ret=found)})
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=actor if r.randrange(2) else 0),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 args=rnd(c,16);e.w32(args+4,rnd(c,32));e.w32(args+8,rnd(c,32))
 return [rnd(c,32),args]
S(0x50de50,'GUESS find_named_resource_id','thiscall',None,ret=None,gen=gen)
