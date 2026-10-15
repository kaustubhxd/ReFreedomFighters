from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=rnd(c,0x1e0)
 nested=obj(c,16,{4:pystub(c,0,this=True,ret=r.getrandbits(32)),0x18:pystub(c,1,this=True)})
 parent=rnd(c,16);e.w32(parent+4,r.choice([0,nested]));e.w32(me+0x1ce,parent)
 sub=obj(c,16,{0x4c:pystub(c,1,this=True)})
 stream=obj(c,16,{0x3c:pystub(c,1,this=True),0x60:pystub(c,1,this=True),0x44:pystub(c,1,this=True),0x4c:pystub(c,1,this=True),0x68:pystub(c,1,this=True,deref={0:3},ret=sub)})
 hook_rec(c,0x4640f0,1,this=True,ret=r.choice([0,1,0x100,0x101]))
 hook_rec(c,0x467850,2,this=True)
 e.w32(0x7003b0,pystub(c,0))
 return [me,stream]
S(0x467770,'serialize entity fields and nested record','thiscall',None,ret='al',gen=gen)
