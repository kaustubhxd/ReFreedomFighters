from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x41e680,0,this=True,ret=r.getrandbits(32));o=rnd(c,32);hook_rec(c,0x589c20,1,this=True,ret=o);hook_rec(c,0x59a5e0,1,this=True);e.w32(0x7003b8,rnd(c,32))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=r.getrandbits(32))})
 me=rnd(c,0x120);tags=[r.randrange(1,65536) for _ in range(4)]
 for off,v in zip([0xf9,0xfb,0x103,0x107],tags):e.wbytes(me+off,v.to_bytes(2,'little'))
 for i in range(4):e.w32(me+0xe9+4*i,obj(c,32,{0x14:pystub(c,0,this=True,ret=r.randrange(2)),0x28:pystub(c,1,this=True,ret=r.randrange(2)),0x3c:pystub(c,1,this=True),4:pystub(c,1,this=True)}))
 e.w32(me+0x44,obj(c,32,{0x130:pystub(c,3,this=True)}));data=rnd(c,8);e.w32(data+4,r.randrange(3,7));which=r.randrange(6);id=tags[which] if which<4 else r.randrange(65536)
 if which==1:e.w32(data+4,r.choice([0,2,3,4,5,6,7,0xffffffff]))
 return [me,id | (r.randrange(65536)<<16),data]
S(0x5a3f50,'GUESS dispatch_inventory_event','thiscall',None,ret='eax',gen=gen)
