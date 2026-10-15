from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 parent=obj(c,0x70,{0x290:slot(2),0x2f8:slot(1),0x2f0:slot(1)})
 def node():
  p=rnd(c,0x70);desc=rnd(c,0x40);data=rnd(c,0x40)
  typ=r.choice([0x200002,0x20001c,0x100000,0x800000,0x900000,r.getrandbits(24)])
  e.w32(data+0x23,typ);e.w32(desc+12,data);e.w32(desc+0x30,r.choice([0,0x8000,0x10000,0x18000]))
  e.w32(p+0x54,r.choice([0,desc,desc]));e.w32(p+0x3c,r.choice([0,0x400,0x800,0x40000,0x200000,r.getrandbits(32)]));e.w32(p+0x64,r.choice([0,1]));return p
 child=node();e.w32(child+0x50,r.choice([0,parent]))
 root=node();e.w32(root+0x3c,r.choice([0,0x400,0x800,0x40000,0x40000000,0x40040000,r.getrandbits(32)]))
 ancestor=obj(c,0x70,{0x20:slot(0,0)})
 me=obj(c,0x70,{0x268:slot(1),0x284:slot(0),0x20:slot(0,r.choice([0,ancestor]))})
 e.w32(me+8,root)
 nodes=[node() for _ in range(r.randrange(5))]
 links={n:(nodes[i+1] if i+1<len(nodes) else 0) for i,n in enumerate(nodes)};links[child]=0
 e.w32(me+0x54,nodes[0] if nodes else 0);e.w32(me+0x50,nodes[-1] if nodes else 0)
 for i,n in enumerate(nodes):e.w32(n+0x60,nodes[i-1] if i else 0)
 hook_rec(c,0x4dc130,0,this=True,ret=parent)
 hook_rec(c,0x4dc030,0,this=True)
 type_result=r.choice([0,1,2,2,3])
 # Fastcall arguments are registers; capture both explicitly.
 def classify(em,k):em.calllog.append(('classify',em.reg('ecx'),em.reg('edx')))
 hook_rec(c,0x4daf20,0,this=True,ret=type_result,side=classify)
 hook_rec(c,0x4dcd00,1,this=True)
 def nxt(em,k):em.calllog.append(('next',em.reg('ecx')));return links[em.reg('ecx')]
 hook_rec(c,0x4db520,0,this=True,ret=nxt)
 def link(em,k):links[em.reg('ecx')]=em.arg32(0)
 hook_rec(c,0x4dcda0,1,this=True,side=link)
 for addr,n in [(0x4db860,1),(0x4690b0,0),(0x4dc840,1),(0x4d9ce0,0),(0x4d9bf0,0)]:hook_rec(c,addr,n,this=True)
 hook_rec(c,0x4db7e0,0,this=True,ret=r.choice([0,parent]))
 hook_rec(c,0x4daff0,0,this=True,ret=r.choice([0,parent]))
 hook_rec(c,0x4dafb0,0,this=True,ret=r.choice([root,parent]))
 hook_rec(c,0x4d9d20,1,this=True,ret=r.getrandbits(32))
 mapping=obj(c,32,{0x38:slot(3,r.getrandbits(32))})
 so=sysobj(c,table_slots={0x178:slot(0,r.choice([0,1,0x100,255])),0x50:slot(1,r.getrandbits(32))},table_size=32)
 e.w32(e.r32(so+0x9b)+8,mapping)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,child,r.choice([0,1,255,0x100]),r.choice([0,1,255,0x100])]
S(0x43ef30,'GUESS attach scene child','thiscall',None,ret='eax',gen=g,note='batch128009')
