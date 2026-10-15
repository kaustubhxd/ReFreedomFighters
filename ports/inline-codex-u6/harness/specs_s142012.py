import struct
from pilot import S
from recruits_util import rnd,obj,sysobj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 ob=obj(c,16,{0xc:pystub(c,0,this=True,ret=r.choice([0,0,1,2,256])),0x10:pystub(c,2,this=True)})
 sys=sysobj(c,slots={0x1b0:pystub(c,0,this=True,ret=r.choice([0,ob,ob]))})
 now=r.randrange(-100000,100000);e.w32(sys+0x40,now&0xffffffff);e.wbytes(sys+0x6e,bytes([r.choice([0,0,1])]))
 key=r.choice([0,1,2,3,255,256,257,-1,-128,r.randrange(256)])
 flags=r.choice([0,0x290000,0x40290000,0x40000000,r.getrandbits(32)])
 for off in [0xa07+5*(key&255),0xf07+5*((flags>>16)&511)]:e.wbytes(sys+off,struct.pack('<f',(now-r.choice([-10,0,255,256,257,1000]))/1024))
 me=rnd(c,0x150);e.w32(me+0x137,r.choice([0,0,0,1]));return [me,key,flags]
S(0x654a60,'GUESS input event flags and double press timestamps','thiscall',None,ret=None,gen=gen)
