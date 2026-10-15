from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def print_(em,res):
  n=2 if em.arg32(1)==0x696948 else 3
  em.calllog.append(('log',tuple(em.arg32(i) for i in range(n))));em.ret(0,0)
 lo=obj(c,32,{0x2c:e.stub_fn('log',print_)});lg=obj(c,32,{0x20:pystub(c,2,this=True,ret=lo)});e.w32(0x700390,lg)
 buf=rnd(c,0x100);size=r.choice([0,1,4,20,100]);bytes_=bytes(r.getrandbits(8) for _ in range(size))
 def read(em,k):em.wbytes(em.arg32(0),bytes_)
 io=obj(c,32,{0:pystub(c,2,this=True,ret=r.choice([0,r.getrandbits(32)])),0x10:pystub(c,3,this=True),12:pystub(c,1,this=True,ret=size),0x14:pystub(c,3,this=True,side=read),4:pystub(c,1,this=True)})
 hook_rec(c,0x41e290,1,pop=0,ret=buf if r.randrange(3) else 0);hook_rec(c,0x4d7c30,4,this=True);hook_rec(c,0x634273,2,pop=0)
 me=rnd(c,32);e.w32(me+9,r.choice([0,1,2,3,4,5]));e.w32(me+0x15,io);return [me,r.getrandbits(32),r.getrandbits(32)]
S(0x4d5770,'GUESS load_file_into_parser','thiscall',None,ret='al',gen=gen)
