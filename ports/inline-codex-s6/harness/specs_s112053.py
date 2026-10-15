from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x41e680,0,this=True,ret=r.getrandbits(32))
 vals=[r.getrandbits(32) for _ in range(8)];stream=obj(c,32,{0x18:pystub(c,2,this=True,stackmark=(0,),side=lambda em,k:em.w32(em.arg32(0),vals[k]))});me=obj(c,0x50,{0x64:pystub(c,1,this=True),0x68:pystub(c,2,this=True)})
 so=sysobj(c,table_size=0xe0);table=e.r32(so+0x9b);embedded=obj(c,32,{8:pystub(c,0,this=True,ret=r.randrange(2)),4:pystub(c,1,this=True,ret=r.choice([0,r.getrandbits(32)])),0:pystub(c,2,this=True)});e.w32(table+0xcc,e.r32(embedded));return [me,stream]
S(0x468fa0,'GUESS load_object_properties','thiscall',None,ret='al',gen=gen)
