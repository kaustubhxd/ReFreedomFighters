from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 values=[r.randrange(2) for _ in range(4)];writes=[r.randrange(2) for _ in range(4)]
 def out(em,k):
  em.calllog.append(('initial',em.rbytes(em.arg32(1),1)))
  if writes[k]:em.wbytes(em.arg32(1),bytes([values[k]]))
 svc=obj(c,32,{0x90:pystub(c,2,this=True,stackmark=(1,),side=out)})
 sysobj(c,table_slots={0x134:pystub(c,0,this=True,ret=svc),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 mgr=obj(c,0x80,{0x24:pystub(c,3,this=True)});e.w32(0x7003a0,mgr)
 provider=obj(c,32,{0x25c:pystub(c,2,this=True,ret=r.getrandbits(32))})
 me=obj(c,0x200,{0x64:pystub(c,1,this=True),0x68:pystub(c,2,this=True)});state=rnd(c,0x13300);e.wbytes(state+0x103f,bytes([r.randrange(2)]));e.wbytes(state+0x103c,bytes([r.randrange(2)]));e.w32(me+0x94,state);e.w32(me+0x54,provider);return [me]
S(0x57a760,'GUESS initialize_player_slots','thiscall',None,ret=None,gen=gen)
