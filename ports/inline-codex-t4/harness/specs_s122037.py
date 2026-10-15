from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 owner=obj(c,0x20,{0x32c:pystub(c,1,this=True,deref={0:3})})
 s=obj(c,0x400,{0x3b0:pystub(c,0,this=True,ret=r.getrandbits(32)),0x320:pystub(c,1,this=True,ret=r.choice([0,0x100,0x101])),0x50c:pystub(c,0,this=True,ret=owner if r.randrange(3) else 0),0x4a8:pystub(c,0,this=True)})
 e.wbytes(s+0x3e8,bytes([r.choice([0,0,1])]))
 hook_rec(c,0x4678e0,4,this=True)
 hook_rec(c,0x467700,0,this=True,ret=r.choice([0,1,0x100,0x101]))
 hook_rec(c,0x467b00,2,this=True)
 return [s,F(r.choice([0.,-0.,1.,float('nan'),r.uniform(-10,10)])),*[r.getrandbits(32) for _ in range(4)]]
S(0x475140,'GUESS remove aim target with transition','thiscall',None,ret=None,gen=gen)
