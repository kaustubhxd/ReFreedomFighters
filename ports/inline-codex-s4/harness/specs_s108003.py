from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g2b00(c):
 base(c);e=c.emu;r=c.rng
 me=rnd(c,0x300)
 n=r.choice(list(range(17))+[17,18])
 e.w32(me+0x2c0,n)
 names=[]
 for i in range(n):
  text=bytes(r.choice(b'abcABC12') for _ in range(r.randrange(16)))
  p=rnd(c,0x30);e.wbytes(p,text+b'\0');e.w32(me+8+14*i,p);names.append(text)
 text=r.choice(names) if names and r.randrange(2)==0 else bytes(r.choice(b'abcABC12') for _ in range(r.randrange(16)))
 p=rnd(c,0x30);e.wbytes(p,text+b'\0')
 return [me,p,r.getrandbits(32),r.getrandbits(32),r.choice([0,0,r.getrandbits(32)]),r.getrandbits(32)]

def gffc0(c):
 base(c);e=c.emu;r=c.rng
 logger(c,nargs=3)
 hook_rec(c,0x5ffb00,1,this=True,ret=r.getrandbits(32))
 key=r.getrandbits(32)
 nodes=[rnd(c,0x110) for _ in range(r.randrange(5))]
 target=r.randrange(len(nodes)+1) if nodes else -1
 for j,node in enumerate(nodes):
  n=r.randrange(6)
  if j==target:n=max(n,1)
  keys=rnd(c,4*max(n,1));indices=rnd(c,2*max(n,1))
  start=r.choice([0,1,20,0xffff,0x10000]);count=r.choice([0,1,3,8])
  values=rnd(c,4*max(count,1))
  for i in range(n):
   e.w32(keys+4*i,key if j==target and i==0 else key^r.randrange(1,10000))
   idx=r.choice([0,max(0,start-1)&0xffff,start&0xffff,(start+count)&0xffff,(start+count-1)&0xffff])
   e.w16(indices+2*i,idx)
  e.w32(node+0xd0,n);e.w32(node+0xe0,keys);e.w32(node+0xf0,indices)
  e.w32(node+0xa0,start);e.w32(node+0xa8,count);e.w32(node+0xac,values);e.w32(node+0xb0,r.getrandbits(32))
  e.w32(node+0x9c,nodes[j+1] if j+1<len(nodes) else 0)
 return [nodes[0] if nodes else 0,key]
S(0x5c2b00,'GUESS add unique named fourteen-byte entry','thiscall',None,ret=None,gen=g2b00)
S(0x5fffc0,'GUESS resolve key through chained indexed tables','thiscall',None,ret='eax',gen=gffc0)
