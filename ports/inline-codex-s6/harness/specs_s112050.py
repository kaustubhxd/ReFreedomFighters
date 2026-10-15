from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c,3)
 vals=[]
 for i in range(2):
  v=rnd(c,8);e.w32(v,obj(c,32,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))}));e.wbytes(v+4,bytes([r.choice([0,1,3,4,255])]));vals.append(v)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:vals[k]);svc=obj(c,32,{0x40:pystub(c,3,this=True)});sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=svc)});return [rnd(c,16),rnd(c,16)]
S(0x50fd00,'GUESS assign_named_property','thiscall',None,ret=None,gen=gen)
