import struct,math
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 sys=sysobj(c,table_slots={0x178:pystub(c,0,this=True,ret=r.choice([0,0,1,2,255,256]))})
 e.wbytes(sys+0x9c7,struct.pack('<f',r.choice([0.,1.,-1.,math.nan,2.])))
 e.wbytes(sys+0x1b3e,bytes([r.choice([0,1,2])]))
 me=rnd(c,0x60);e.wbytes(me+0x32,bytes([r.choice([0,8,16,128,136,144,255,r.randrange(256)]),r.randrange(256)]))
 e.w32(me+0x35,r.choice(list(range(10))+[100]));e.wbytes(me+0x3d,bytes([r.choice([0,1])]))
 e.wbytes(me+0x46,bytes([r.choice([0,0,1,2])]))
 e.wbytes(me+0x10,bytes([r.choice([0,1,1,2])]))
 e.w32(me+0x15,obj(c,16,{0x14:pystub(c,0,this=True,ret=r.choice([0,1,2]))}))
 hook_rec(c,0x43b2d0,0,this=True)
 hook_rec(c,0x438380,0,this=True,ret=r.choice([0,1,2,0x55,0xff,r.getrandbits(32)]))
 return [me]
S(0x437d60,'GUESS input action gate and check','thiscall',None,ret='al',gen=gen)
