from pilot import S,F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab

def gen(c):
 clear_hooks(c)
 r=c.rng;e=c.emu
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 child=obj(c,0x40,{0x230:pystub(c,1,this=True)})
 ids=[r.getrandbits(32) for _ in range(r.randrange(6))]
 targets={x:r.choice([0,child]) for x in ids}
 lookup=pystub(c,1,ret=lambda em,k:targets.get(em.arg32(0),0),this=True)
 sys=sysobj(c,table_slots={0x58:lookup})
 payload=bytes(r.getrandbits(8) for _ in range(36))
 def fill(em,k): em.wbytes(em.arg32(1),payload)
 mgr=obj(c,0x40,{0x80:pystub(c,2,this=True,stackmark=(1,),side=fill),0x98:pystub(c,2,this=True,deref={1:9})})
 root=rnd(c,0x30);e.w32(root+0x18,mgr);e.w32(sys+0x1aa3,root)
 me=obj(c,0x40,{0x238:pystub(c,0,this=True),0x220:pystub(c,1,this=True)})
 data=rnd(c,0x80);e.w32(me+8,data)
 e.w32(me+0x1c,reftab(c,ids) if r.randrange(4) else 0)
 return [me,F(r.choice([0.,-0.,1.,-1.,r.uniform(-1000,1000)]))]
S(0x449840,'GUESS_update_children','thiscall',None,ret=None,gen=gen)
