from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 manager=rnd(c,0x20);e.w32(0x7003b8,manager)
 sound=rnd(c,0x80)
 ref=obj(c,0x20,{0x60:pystub(c,1,this=True,ret=r.choice([0,sound,sound]))})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,ref)
 event=rnd(c,0x20);parent=rnd(c,0x690);alternate=rnd(c,0x690)
 hook_rec(c,0x5da860,2,this=True,ret=r.choice([0,1,2,0x100,0x101]))
 hook_rec(c,0x59fb50,0,this=True)
 hook_rec(c,0x467060,2,this=True,ret=r.getrandbits(32))
 hook_rec(c,0x589c20,1,this=True,ret=event)
 hook_rec(c,0x598e10,3,this=True)
 me=obj(c,0x950,{0x684:pystub(c,1,this=True,ret=r.getrandbits(32))})
 e.w32(me+0x93a,r.choice([0,rnd(c,0x20),rnd(c,0x20)]));e.w32(me+0x54,rnd(c,0x10));e.w32(me+0x936,rnd(c,1024));e.w32(me+0x92e,r.choice([0,parent,parent]))
 return [me,r.choice([0,1,0x26,0x27,0xff,r.getrandbits(32)]),r.choice([0,1,2,0x100]),r.choice([0,alternate,alternate])]
S(0x5a1b50,'GUESS play enumerated sound','thiscall',None,ret='eax',gen=g,note='batch124008')
