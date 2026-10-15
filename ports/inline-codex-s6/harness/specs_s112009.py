from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4f9af0,0,this=True);hook_rec(c,0x4dc630,2,this=True)
 hook_rec(c,0x4db9a0,1,this=True,ret=lambda em,k:choices[em.reg('ecx')])
 hook_rec(c,0x4db520,0,this=True,ret=lambda em,k:links[em.reg('ecx')])
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32)),0x58:pystub(c,1,this=True,ret=rnd(c,32))})
 created=obj(c,0x20,{0x124:pystub(c,4,this=True),0x27c:pystub(c,1,this=True),0xbc:pystub(c,1,this=True),0x260:pystub(c,1,this=True),0x248:pystub(c,1,this=True),0x284:pystub(c,1,this=True),0x26c:pystub(c,3,this=True)})
 e.w32(created+8,rnd(c,32))
 me=obj(c,0x200,{0x294:pystub(c,4,this=True,ret=created)})
 embedded=obj(c,0x20,{4:pystub(c,1,this=True),0x14:pystub(c,0,this=True,ret=r.randrange(3)),0x30:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(me+0x10f,e.r32(embedded))
 e.w32(me+0x1c3,r.getrandbits(32) if r.randrange(4) else 0)
 tail=0;choices={};links={}
 for j in range(r.randrange(0,6)):
  info=rnd(c,0x30);e.w32(info+0x23,r.choice([0,1,0x100000]));actor=rnd(c,0x20);e.w32(actor+12,info)
  node=rnd(c,0x70);e.w32(node+0x54,actor if r.randrange(3) else 0);links[node]=tail;choices[node]=r.randrange(2);tail=node
 e.w32(me+0x54,tail)
 return [me]
S(0x4f89b0,'GUESS create_linked_overlay','thiscall',None,ret=None,gen=gen)
