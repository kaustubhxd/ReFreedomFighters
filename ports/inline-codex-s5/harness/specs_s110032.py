from pilot import S
from recruits_util import clear_hooks,rnd,pystub,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0xa0);n=r.choice([-1,0,1,2,3,4]);q=rnd(c,0x34*max(n,1))
 for i in range(max(n,1)):
  for j in range(12):e.wf32(q+0x34*i+4*j,r.uniform(-20,20))
 e.w32(t+0x3e,n&0xffffffff);e.w32(t+0x42,r.choice([0,q,q,q]))
 a,b=rnd(c,0x10),rnd(c,0x10)
 for i in range(3):e.wf32(a+4*i,r.uniform(-20,20));e.wf32(b+4*i,r.uniform(-20,20))
 out=rnd(c,4);vals=[r.choice([-1.,0.,.5,1.,2.,10.,11.,r.uniform(-2,12)]) for _ in range(8)];rets=[r.choice([0,1,256,257]) for _ in range(8)];state=[0]
 def tri(em,_):
  i=state[0];state[0]+=1
  em.calllog.append(('tri',tuple(em.r32(em.reg('ecx')+4*j) for j in range(3)),tuple(em.r32(em.reg('edx')+4*j) for j in range(3)),tuple(em.arg32(j) for j in [0,1,2,4])))
  em.wf32(em.arg32(3),vals[i]);em.ret(eax=rets[i],argbytes=20)
 e.hook(0x4e2560,tri);_HOOKED.add(0x4e2560)
 return [t,a,b,out]
S(0x52a850,'ZPathfinder3 CheckLineAgainstAdditionalDoors','thiscall',None,ret='eax',gen=gen)
