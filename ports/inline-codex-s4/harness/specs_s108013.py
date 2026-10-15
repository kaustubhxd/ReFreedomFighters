from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,reftab

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gb720(c):
 base(c);e=c.emu;r=c.rng
 entries=[];mapping={}
 for i in range(r.randrange(7)):
  ident=r.getrandbits(32);entry=rnd(c,8);e.w32(entry,ident);e.w8(entry+4,r.choice([0,1,2,255]));entries.append(entry)
  actor=obj(c,0x20,{0x130:pystub(c,3,this=True)})
  mapping[ident]=r.choice([0,actor,actor])
 table=reftab(c,entries)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 me=rnd(c,0x80);e.w32(me+0x54,r.choice([0,table,table]));e.w16(me+0x52,r.getrandbits(16))
 n=r.randrange(7);array=rnd(c,4*max(n,1))
 for i in range(n):e.w32(array+4*i,rnd(c,0x20))
 e.w32(me+0x64,n);e.w32(me+0x68,r.choice([0,array,array]));e.w32(me+0x6c,r.choice([0,rnd(c,0x10)]))
 hook_rec(c,0x634273,2,pop=0)
 return [me]

def gac50(c):
 base(c);e=c.emu;r=c.rng
 root=rnd(c,0x70);n=r.randrange(1,7);nodes=[rnd(c,0x70) for _ in range(n)]
 mode=r.randrange(3)
 e.w32(root+0x3c,[0,0x40000000,0x40000][mode]);e.w32(root+0x50,nodes[0])
 for i,node in enumerate(nodes):
  e.w32(node+0x50,nodes[i+1] if i+1<n else 0)
  e.w32(node+0x3c,0x40000 if i+1==n else 0)
  actor=obj(c,0x20,{0x2a8:pystub(c,0,this=True,ret=r.choice([0,0x1000000,0x2000000,0x3000000,0x2000001]))})
  e.w32(node+0x54,actor)
 handle=r.choice([0,1,0xffff,r.getrandbits(16)])
 e.w16(root+0x5c,handle);e.w16(nodes[-1]+0x5c,handle)
 record=rnd(c,0x20);e.w8(record+0x1c,r.choice([0,1,2,255]))
 attr=obj(c,0x20,{0x5c:pystub(c,1,this=True,ret=r.choice([0,record,record]))})
 system=sysobj(c);e.w32(e.r32(system+0x9b)+8,attr)
 return [root,rnd(c,4*(n+2))]
S(0x4cb720,'GUESS notify active references and release view allocations','thiscall',None,ret=None,gen=gb720)
S(0x4dac50,'GUESS collect linked actors with terminal attribute lookup','fastcall',None,ret='eax',gen=gac50)
