from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,sysobj,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 so=sysobj(c,table_size=0xb00,slots={0x5c:pystub(c,2,this=True,nullflag=(1,),ret=r.choice([0,1,256,257])),0x1c0:pystub(c,2,this=True,st0=r.uniform(0,1))})
 geoms=[];matches=set()
 for i in range(r.randrange(7)):
  values=[r.uniform(-100,100) for _ in range(3)]
  def pos(em,n,values=values):
   for j,v in enumerate(values):em.wf32(em.arg32(0)+4*j,v)
  ob=obj(c,0x60,{0x84:pystub(c,1,this=True,nullflag=(0,),side=pos)})
  name=rnd(c,0x20);e.wbytes(name,b'waypoint\x00')
  if r.random()<.5:matches.add(name)
  e.w32(ob+4,r.choice([name,name,0]));g=rnd(c,0x60);e.w32(g+0x54,ob);geoms.append(g)
 def cmp(em,_):
  a,b=em.reg('ecx'),em.reg('edx');em.calllog.append(('wildcmp',a,b));em.ret(eax=0 if a in matches else 1)
 e.hook(0x4cc850,cmp);_HOOKED.add(0x4cc850)
 def nxt(em,_):
  p=em.arg32(0);cur=e.r32(p);idx=geoms.index(cur);em.calllog.append(('next',cur));em.w32(p,geoms[idx+1] if idx+1<len(geoms) else 0);em.ret(argbytes=4)
 world=obj(c,0x20,{0x50:e.stub_fn('next',nxt),0x238:pystub(c,5,this=True,deref={0:9,1:3,2:3})});e.w32(world+8,geoms[0] if geoms else 0);e.w32(e.r32(so+0x9b)+0xadc,world)
 return [rnd(c,0x200)]
S(0x5d0310,'ZCamHelper InitRecruitWayPoints','thiscall',None,ret=None,gen=gen)
