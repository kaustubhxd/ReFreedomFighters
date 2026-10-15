from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def base(c):
 clear_hooks(c)
 c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g69b0(c):
 base(c);e=c.emu;r=c.rng
 n=r.randrange(1,40);a=rnd(c,4*n);b=rnd(c,4*n)
 mode=r.randrange(5)
 for i in range(n):e.w32(a+4*i,r.choice([0,1,2,0xffffffff,r.getrandbits(32)]) if mode<3 else (i if mode==3 else n-i))
 lo=r.randrange(n);hi=r.randrange(lo,n)
 e.w32(0x6e7b9c,r.getrandbits(32))
 return [a,b,lo,hi]

def gf1f0(c):
 base(c);e=c.emu;r=c.rng
 logger(c,nargs=3)
 ref=r.getrandbits(32)
 reference=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=ref)})
 first=rnd(c,0x10);second=rnd(c,0x10)
 typ=r.choice([0,1,2,3,3,4,4,5,255]);e.w8(first+4,typ)
 e.w32(first,reference if typ==4 else ref)
 e.w8(second+4,r.choice([0,1,1,2,3,255]))
 handle1=rnd(c,0x10);handle2=rnd(c,0x10)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:first if em.reg('ecx')==handle1 else second)
 found=r.choice([0,1,2,128,255])
 def out(em,k):em.w8(em.arg32(1),found)
 lookup=obj(c,0x20,{0x90:pystub(c,2,this=True,deref={1:-1},side=out)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=lookup)})
 inp=rnd(c,0x10);e.w32(inp+4,handle1);e.w32(inp+8,handle2)
 return [inp]
S(0x4e69b0,'GUESS randomized unsigned parallel quicksort','fastcall',None,ret=None,gen=g69b0)
S(0x50f1f0,'GUESS write reference lookup result to typed boolean','stdcall',None,ret=None,gen=gf1f0)
