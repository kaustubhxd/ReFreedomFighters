from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x45d380,2,this=True,ret=r.getrandbits(32))
 value=r.getrandbits(32);sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=value)})
 me=obj(c,0x230,{0x2c4:pystub(c,0,this=True),0x2dc:pystub(c,2,this=True),0x2e0:pystub(c,2,this=True)});state=rnd(c,0x60);e.w32(state+0x4b,r.randrange(2));e.w32(me+0x5c,state)
 tags=[r.randrange(1,65536) for _ in range(3)]
 for off,v in zip([0x1fd,0x209,0x20b],tags):e.wbytes(me+off,v.to_bytes(2,'little'))
 e.wbytes(me+0x133,bytes([r.randrange(2)]));e.wbytes(me+0x11e,bytes([r.randrange(2)]));n=r.randrange(0,8);e.w32(me+0xda,n)
 for i in range(n):e.w32(me+0xde+4*i,r.choice([value,r.getrandbits(32)]))
 return [me,r.choice(tags+[r.randrange(65536)])|(r.randrange(65536)<<16),r.getrandbits(32)]
S(0x5122f0,'GUESS dispatch_spline_membership','thiscall',None,ret='eax',gen=gen)
