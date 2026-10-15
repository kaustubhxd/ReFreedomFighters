from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x60);data=rnd(c,0x6d+56*7);n=r.randrange(7);e.w32(data+0x69,n);lookup={}
 for i in range(n):
  e.w32(data+0x6d+56*i,i)
  node=rnd(c,0x50);e.w32(node+0x3c,r.choice([0,0x400,0x800,0x2000,1]));lookup[i]=node if r.randrange(3) else 0
 owner=obj(c,0x20,{0x24c:pystub(c,0,this=True,ret=data)});parent=rnd(c,0x60);e.w32(parent+0x54,owner)
 e.w32(s+0x38,parent if r.randrange(5) else 0);e.w32(s+0x48,r.choice([0,rnd(c,0x20),0xffffff70]));e.wbytes(s+0x3f,bytes([r.choice([0,1,1])]))
 tab=obj(c,0x20,{0x54:pystub(c,1,this=True,ret=lambda em,k:lookup[em.arg32(0)])});sys=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 return [s,rnd(c,32),r.choice([0,1,8])]
S(0x658e00,'GUESS gather live owner entries','thiscall',None,ret='eax',gen=gen)
