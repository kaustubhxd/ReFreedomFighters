from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c)
 hook_rec(c,0x61ba1c,2,ret=r.choice([0,0,0,1]))
 def error(em,res):em.calllog.append(('error',em.reg('ecx'),em.reg('edx')));em.ret(0,0)
 e.hook(0x54f2b0,error)
 from recruits_util import _HOOKED
 _HOOKED.add(0x54f2b0)
 iface=obj(c,32,{0x18:pystub(c,3,ret=r.choice([0,0,1])),0x10:pystub(c,2,ret=r.choice([0,0,1]),deref={1:1})})
 create=pystub(c,3,ret=r.choice([0,0,1]),side=lambda em,k:em.w32(em.arg32(1),iface));e.w32(0x676028,create)
 me=obj(c,0xa280,{0x94:pystub(c,0,this=True,ret=r.getrandbits(32)),0xb0:pystub(c,0,this=True,ret=r.choice([0,1,2,256,255]))});return [me]
S(0x54aeb0,'GUESS initialize_audio_interface','thiscall',None,ret='al',gen=gen)
