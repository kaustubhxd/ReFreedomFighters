from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 for addr,n in [(0x4db500,12),(0x4db2a0,36)]:
  data=bytes(r.getrandbits(8) for _ in range(n));hook_rec(c,addr,1,this=True,stackmark=(0,),side=lambda em,k,data=data:em.wbytes(em.arg32(0),data))
 created=obj(c,32,{0x2c:pystub(c,0,this=True),0xbc:pystub(c,1,this=True)})
 old=obj(c,32,{0x1bc:pystub(c,7,this=True,deref={1:9,2:3},ret=created)});e.w32(old+8,rnd(c,32))
 service=obj(c,32,{0x60:pystub(c,2,this=True)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=service),0x4c:pystub(c,2,pop=4,this=True,ret=r.getrandbits(32)),0x114:pystub(c,4,this=True,ret=lambda em,k:words[k]),0x58:pystub(c,1,this=True,ret=old if r.randrange(2) else 0)})
 # Slot 4c has two args at the first site, one at the final site.
 so=e.r32(0x70039c);tab=e.r32(so+0x9b);vt=e.r32(tab);count=e.alloc(4);returns=[r.getrandbits(32),r.getrandbits(32)]
 def lookup(em,res):
  k=em.r32(count);em.w32(count,k+1);em.calllog.append(('id',em.reg('ecx'),em.arg32(0),em.arg32(1) if k==0 else None));em.ret(returns[min(k,1)],8 if k==0 else 4)
 e.w32(vt+0x4c,e.stub_fn('id',lookup));words=[r.getrandbits(32) for _ in range(3)]
 me=rnd(c,0x100);e.w32(me+0x5a,r.randrange(4));return [me]
S(0x5d67e0,'GUESS initialize_clone_reference','thiscall',None,ret=None,gen=gen)
