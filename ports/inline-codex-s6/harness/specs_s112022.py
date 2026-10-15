from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4dc630,2,this=True)
 vals=[r.choice([0,r.getrandbits(32)]) for _ in range(2)]
 def out(em,k):
  em.calllog.append(('initial',em.r32(em.arg32(1))));em.w32(em.arg32(1),vals[k])
 svc=obj(c,32,{0x5c:pystub(c,2,this=True),0x88:pystub(c,2,this=True,stackmark=(1,),side=out)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=svc),0x4c:pystub(c,2,this=True,ret=r.getrandbits(32)),0x114:pystub(c,4,this=True,ret=lambda em,k:words[k]),0x58:pystub(c,1,this=True,ret=r.getrandbits(32))});words=[r.getrandbits(32) for _ in range(3)]
 parent=rnd(c,32);e.w32(parent+8,rnd(c,32));me=rnd(c,0x100);e.w32(me+0x44,parent);e.w32(me+0x52,r.choice([0,r.getrandbits(32)]));return [me]
S(0x4a8f20,'GUESS initialize_registered_controls','thiscall',None,ret=None,gen=gen)
