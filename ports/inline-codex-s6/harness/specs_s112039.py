from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));me=rnd(c,0x10180);arg=rnd(c,0x60);data=rnd(c,0x70);e.w32(arg+8,data)
 existing=r.choice([0,1,0x800,0xffff]);e.wbytes(data+0x5a,existing.to_bytes(2,'little'));newid=r.choice([1,0x800,0xfff,0xf123])
 record=rnd(c,32);e.w32(record+12,arg);e.wbytes(record+5,bytes([r.randrange(2)]));block=rnd(c,32)
 alloc=obj(c,32,{8:pystub(c,0,this=True,ret=record)});mgr=obj(c,0x220,{0x60:pystub(c,0,this=True)});e.w32(mgr+0x218,alloc);e.w32(mgr+0x68,rnd(c,0x4000));e.w32(me+0x1005d,mgr)
 hook_rec(c,0x63eab0,1,this=True,ret=record);hook_rec(c,0x63f090,1,this=True,ret=newid);hook_rec(c,0x63da80,1,this=True);hook_rec(c,0x648810,2,this=True,deref={0:1})
 e.w32(me+0x10151,obj(c,32,{8:pystub(c,0,this=True,ret=block)}));e.w32(me+0x10071,rnd(c,0x4000));e.wbytes(me+0x10028,bytes([r.randrange(2)]));e.w32(me+0x1010d,r.choice([0,1,15,16]))
 count=r.randrange(0,6);e.w32(me+0x10089,count)
 for i in range(count):e.w32(me+0x1008d+4*i,rnd(c,0x80))
 return [me,arg]
S(0x648e50,'GUESS register_draw_record','thiscall',None,ret=None,gen=gen)
