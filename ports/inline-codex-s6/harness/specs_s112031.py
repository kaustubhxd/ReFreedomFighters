from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 mat=bytes(r.getrandbits(8) for _ in range(36));hook_rec(c,0x4de7a0,0,this='mark',side=lambda em,k:em.wbytes(em.reg('ecx'),bytes(36)));hook_rec(c,0x4db2a0,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),mat))
 def endpoint():
  pos=bytes(r.getrandbits(8) for _ in range(12));write=r.randrange(2)
  return obj(c,32,{0x84:pystub(c,1,this=True,deref={0:3},side=lambda em,k:em.wbytes(em.arg32(0),pos) if write else None)})
 endpoints=[endpoint() if r.randrange(4) else 0 for _ in range(2)];sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:endpoints[k])})
 camera=obj(c,0x70,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});state=obj(c,0x60,{0x8c:pystub(c,0,this=True,ret=camera)})
 target=obj(c,32,{0x78:pystub(c,1,this=True,deref={0:3}),0x268:pystub(c,2,this=True,deref={0:3})});e.w32(target+8,rnd(c,32))
 idx=r.choice([-1,0,1,2,4]);count=r.choice([0,2,4,8]);ids=[r.getrandbits(32),r.getrandbits(32)];lst=obj(c,32,{0x14:pystub(c,0,this=True,ret=count),0x30:pystub(c,1,this=True,ret=lambda em,k:ids[k])});source=rnd(c,32);e.w32(source+24,lst)
 me=rnd(c,0x120);e.w32(me+0x10b,target if r.randrange(4) else 0);e.w32(me+0x10f,state);return [me,source if r.randrange(4) else 0,idx&0xffffffff]
S(0x5a4f70,'GUESS setup_camera_between_entries','thiscall',None,ret=None,gen=gen)
