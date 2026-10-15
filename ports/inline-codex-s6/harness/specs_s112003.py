from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x5f2d60,2,this=True)
 def parse(em,k):
  p=em.r32(em.arg32(1));end=em.arg32(2)
  if p!=end:em.w32(em.arg32(1),p+1)
 me=obj(c,0x20,{0x84:pystub(c,3,this=True,side=parse)})
 data=r.choice([b'',b' ',b'\t \t\tA',b'\r\n\nZ',b'$',b'abc',b'//comment\r\nZ',b'//end',b'/',b'//\t x',b' $',b'\0abc'])
 data+=bytes(r.choice([9,10,13,32,36,47,65,66]) for _ in range(r.randrange(8))) if data else b''
 p=rnd(c,len(data)+4);e.wbytes(p,data+b'\0\0');cursor=rnd(c,4);e.w32(cursor,p)
 end=p+r.randrange(len(data)+1)
 return [me,rnd(c,16),cursor,end]
S(0x42ceb0,'GUESS classify_token','thiscall',None,ret=None,gen=gen)
