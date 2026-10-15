from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def component():return obj(c,0x30,{0xbc:pystub(c,1,this=True),0x70:pystub(c,1,this=True,deref={0:3})})
 main=component();back=component();front=component()
 ctrl=obj(c,0x20,{0x250:pystub(c,0,this=True),0x254:pystub(c,0,this=True)})
 child=obj(c,0x100,{0x110:pystub(c,2,this=True),0x30c:pystub(c,1,this=True),0x114:pystub(c,1,this=True)})
 e.w32(child+0x6f,ctrl)
 emb=obj(c,0x10,{0x14:pystub(c,0,this=True,ret=r.choice([0,0,1,2]))});e.w32(child+0xcb,e.r32(emb))
 s=obj(c,0x100,{0x64:pystub(c,1,this=True),0x84:pystub(c,0,this=True,ret=child),0x68:pystub(c,2,this=True)})
 e.w32(s+0x44,main);hasback=r.randrange(2);e.w32(s+0x4c,back if hasback else 0);e.w32(s+0x50,front if hasback or r.randrange(2) else 0)
 so=sysobj(c);e.w32(so+0x73,r.choice([0,1,100,0xffffffff,0x7fffffff,0x80000000,r.getrandbits(32)]))
 def end(em,k):em.calllog.append(('final-mode',em.r32(s+0xdc)))
 hook_rec(c,0x562750,0,this=True,side=end)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x562440,'GUESS initialize window layers and controls','thiscall',None,ret=None,gen=gen)
