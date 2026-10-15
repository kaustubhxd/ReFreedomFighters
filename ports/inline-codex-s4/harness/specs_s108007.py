from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,stub_memmove

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def gd6f0(c):
 base(c);e=c.emu;r=c.rng
 n=r.randrange(9)
 items=[rnd(c,0xb0) for _ in range(max(n,1))]
 for item in items:e.w16(item+0xac,r.choice([0,0x4000,0x2000,0x4001,0xffff]))
 array=rnd(c,4*(n+2))
 for i in range(n):e.w32(array+4*i,r.choice(items))
 callback=obj(c,0x20,{0:pystub(c,1,this=True,deref={0:3})})
 me=rnd(c,0x50);e.w32(me+0x30,r.choice([0,0,0,callback]));e.w32(me+0x20,n);e.w32(me+0x18,array);e.w32(me+4,rnd(c,0x20))
 hook_rec(c,0x4248e0,0,pop=0,ret=r.getrandbits(32))
 hook_rec(c,0x5f56f0,0,this=True)
 manager=obj(c,0x20,{0x24:pystub(c,1,this=True)})
 hook_rec(c,0x5fa630,0,pop=0,ret=manager)
 hook_rec(c,0x5fd2a0,1,this=True);hook_rec(c,0x5f3b00,0,this=True);hook_rec(c,0x634273,2,pop=0)
 stub_memmove(c)
 return [me]

def gf9d0(c):
 base(c);e=c.emu;r=c.rng
 stream=rnd(c,0x38);state=rnd(c,0x18);memory=rnd(c,0x100)
 allocret=r.choice([0,state,state,state])
 alloc=pystub(c,3,pop=0,ret=allocret)
 hook_rec(c,0x631810,3,pop=0,ret=allocret)
 e.w32(stream+0x20,r.choice([0,alloc]));e.w32(stream+0x24,r.choice([0,r.getrandbits(32)|1]))
 # The buffer allocator is abstracted but its window size/table args are recorded.
 hook_rec(c,0x632230,3,pop=0,ret=r.choice([0,memory,memory]))
 hook_rec(c,0x62f980,1);hook_rec(c,0x62fad0,1)
 version=rnd(c,8);e.wbytes(version,r.choice([b'1.2.3\0',b'0.9\0',b'2.0\0']))
 return [r.choice([0,stream,stream,stream]),r.choice([0,7,8,9,15,16,-7,-8,-15,-16,-2147483648]),r.choice([0,version,version,version]),r.choice([0x38,0x38,0x38,0x37,0x39])]
S(0x5fd6f0,'GUESS schedule processes and retire flagged entries','thiscall',None,ret=None,gen=gd6f0)
S(0x62f9d0,'GUESS initialize inflate stream with signed window bits','stdcall',None,ret='eax',gen=gf9d0)
