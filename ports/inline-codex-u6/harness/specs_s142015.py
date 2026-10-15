import struct,math
from pilot import S,F
from recruits_util import rnd,obj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;stride=r.randrange(4,9);n=r.randrange(0,7)
 nodes=[rnd(c,64) for i in range(n)];values=sorted(r.choice([-2.,-1.,0.,0.,1.,2.]) for i in range(n))
 if n and c.case%11==0:values[r.randrange(n)]=math.nan
 for p,v in zip(nodes,values):e.wbytes(p+stride*4-12,struct.pack('<f',v))
 nxt={p:nodes[i+1] if i+1<n else 0 for i,p in enumerate(nodes)};prev={p:nodes[i-1] if i else 0 for i,p in enumerate(nodes)}
 out=rnd(c,64)
 me=obj(c,0x40,{0x90:pystub(c,1,this=True,ret=lambda em,k:prev[em.arg32(0)]),0x94:pystub(c,1,this=True,ret=lambda em,k:nxt[em.arg32(0)]),0x84:pystub(c,1,this=True,ret=out),0x88:pystub(c,1,this=True,ret=out),0x8c:pystub(c,2,this=True,ret=out)})
 e.w32(me+0x18,stride);e.w32(me+0x1c,nodes[-1]+(stride-2)*4 if n else 0);e.w32(me+0x28,r.choice([0]+nodes))
 return [me,r.getrandbits(32),F(r.choice([-3.,-2.,-1.,0.,1.,2.,3.,math.nan])),r.choice([0,1,2,3])]
S(0x4cd730,'GUESS sorted list insert using cached float key','thiscall',None,ret='eax',gen=gen,nan_heap=True)
