from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 groups=[];counts=[]
 for j in range(r.randrange(3,7)):
  count=r.randrange(0,6);p=rnd(c,12*(count+1))
  for k in range(count):e.w32(p+12*k,r.randrange(1,0xffffffff))
  e.w32(p+12*count,0);groups.append(p);counts.append(count)
 def ret(em,k):
  i=em.arg32(0);return groups[i] if i<len(groups) else 0
 service=obj(c,0x20,{0x9c:pystub(c,1,this=True,ret=ret)})
 so=sysobj(c);e.w32(so+0x1907,service)
 typ=r.choice([0,1,2,0x42]);idx=r.randrange(0,sum(counts)+len(counts)+3) if typ==0x42 else r.randrange(0,9)
 return [(typ<<16)|idx]
S(0x57dde0,'GUESS resolve_grouped_id','thiscall',None,ret='eax',gen=gen,note='valid group tags 0,1,2,0x42; other tags use uninitialized stack in original')
