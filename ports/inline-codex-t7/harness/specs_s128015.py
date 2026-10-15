from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 me=rnd(c,0x240);e.w32(me+0x1fe,r.choice([0,1,6,7,8,9]))
 nodes=[rnd(c,0x70) for _ in range(r.randrange(12))];links={}
 for i,p in enumerate(nodes):
  desc=rnd(c,32);typ=rnd(c,0x30);e.w32(typ+0x23,r.choice([0,0,0,0x100000]));e.w32(desc+12,typ);e.w32(p+0x54,r.choice([0,desc]));links[p]=nodes[i+1] if i+1<len(nodes) else 0
 lst=rnd(c,0x70);e.w32(lst+0x54,nodes[0] if nodes else 0)
 target=rnd(c,0x40)
 for i in range(4):e.w32(target+24+i*4,r.choice([0,r.getrandbits(32)]))
 childmap={0x6a8fe8:lst,0x6a912c:target,0x6a8ff4:r.getrandbits(32),0x6a9000:r.getrandbits(32)}
 def child(em,k):
  name=em.arg32(0);em.calllog.append(('child',em.reg('ecx'),name,em.arg32(1)));return childmap[name]
 parent=obj(c,32,{0x25c:slot(2,ret=child)})
 widget=obj(c,32,{0x20:slot(0,parent),0xbc:slot(1),0x25c:slot(2,ret=lambda em,k:rvalues[k%3])})
 rvalues=[r.getrandbits(32) for _ in range(3)]
 refs={name:r.getrandbits(32) for name in [0x6a8f58,0x6a8a74,0x6a8f60,0x6a8f6c,0x6a8f78,0x6a8f8c,0x6a8fbc,0x6a8fc4,0x6a8fcc,0x6a8fd8]}
 def ref(em,k):em.calllog.append(('ref',em.arg32(0),em.r32(em.arg32(1))));em.w32(em.arg32(1),refs.get(em.arg32(0),em.arg32(0)^0x12345678))
 res=obj(c,32,{0x88:slot(2,stackmark=(1,),side=ref)})
 lastnull=r.randrange(2)
 def lookup(em,k):
  em.calllog.append(('lookup',em.arg32(0)))
  return 0 if k==8 and lastnull else widget
 sysobj(c,table_slots={0x138:slot(0,res),0x58:slot(1,ret=lookup)})
 hook_rec(c,0x563610,1,this=True)
 hook_rec(c,0x4db520,0,this=True,ret=lambda em,k:links[em.reg('ecx')])
 hook_rec(c,0x573b20,2,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x5747e0,0,this=True,ret=r.getrandbits(32))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x573dd0,'GUESS initialize menu resource bindings','thiscall',None,ret='eax',gen=g,note='batch128015')
