from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec,reftab

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4da3a0,0,this=True,ret=r.randrange(2));hook_rec(c,0x4e1600,0,this=True,ret=lambda em,k:types[k]);types=[r.choice([0,1,255]) for _ in range(6)]
 reader=rnd(c,32);data=rnd(c,256);e.w32(reader,data);lengths=[r.randrange(0,20) for _ in range(6)];hook_rec(c,0x5f2de0,0,this=True,ret=lambda em,k:em.r32(em.reg('ecx')));hook_rec(c,0x4e1b30,0,this=True,side=lambda em,k:em.w32(em.reg('ecx'),em.r32(em.reg('ecx'))+lengths[k]))
 hook_rec(c,0x41e290,1,pop=0,ret=rnd(c,64));hook_rec(c,0x634d22,3,pop=0,side=lambda em,k:em.wbytes(em.arg32(0),em.rbytes(em.arg32(1),em.arg32(2))))
 cache=obj(c,32,{4:pystub(c,1,this=True),0x14:pystub(c,0,this=True,ret=r.getrandbits(32))});holder=rnd(c,16);e.w32(holder+4,cache if r.randrange(2) else 0);so=sysobj(c);table=e.r32(so+0x9b);e.w32(table+8,holder if r.randrange(2) else 0)
 rows=[];resources=[]
 for j in range(r.randrange(0,5)):
  row=rnd(c,4);rows.append(row);resource=obj(c,0x50,{4:pystub(c,1,this=True,deref={0:1})});info=rnd(c,0x40);e.w32(info+0x2b,r.choice([0,0x800]));e.w32(resource+0x40,info);resources.append(resource if r.randrange(4) else 0)
 e.w32(0x70038c,obj(c,32,{0xcc:pystub(c,1,this=True,ret=lambda em,k:resources[k])}));lst=reftab(c,rows);owner=rnd(c,32);e.w32(owner+8,lst if r.randrange(4) else 0);target=rnd(c,32);e.w32(target+16,owner)
 return [rnd(c,16),target,reader]
S(0x48da10,'GUESS read_linked_resources','thiscall',None,ret=None,gen=gen)
