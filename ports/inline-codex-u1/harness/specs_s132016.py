import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub,sysobj,logger

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32),pop=0));logger(c,3)
 p=rnd(c,0x24);req=rnd(c,12);inp=rnd(c,16);out=rnd(c,16);e.w32(req+4,inp);e.w32(req+8,out)
 args=[rnd(c,8) for _ in range(3)];result=rnd(c,8);kind=r.choice([3,3,4,0,2]);e.w8(args[1]+4,kind);e.w8(result+4,r.choice([0,2,2,1,4]))
 if kind==4:e.w32(args[1],obj(c,16,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))}))
 e.w32(args[2],r.choice([0,r.getrandbits(32) or 1]));mapping={(inp,k):v for k,v in enumerate(args)};mapping[(out,0)]=result
 hook_rec(c,0x5003d0,1,this=True,ret=lambda e,k:mapping[(e.reg('ecx'),e.arg32(0))])
 e.w32(p+0x1c,obj(c,16,{0x6ec:pystub(c,3,this=True,ret=r.getrandbits(32))}))
 sound=rnd(c,0x80);e.w32(sound+0x70,fb(r.uniform(-10,200)));sysobj(c,table_slots={0x60:pystub(c,1,this=True,ret=r.choice([0,sound,sound]))})
 return [p,req]
S(0x55bbc0,'GUESS script sound playback duration','thiscall',None,ret=None,gen=gen)
