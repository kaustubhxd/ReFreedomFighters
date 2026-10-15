from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4db9a0,1,this=True,ret=lambda em,k:flags[k])
 resource=obj(c,32,{0x34c:pystub(c,5,this=True),0x30c:pystub(c,1,this=True)})
 me=obj(c,0x350,{0x84:pystub(c,0,this=True,ret=resource),0x64:pystub(c,1,this=True)})
 entries=[];flags=[]
 for j in range(r.randrange(0,5)):
  p=rnd(c,0x60);e.w32(p+0x54,obj(c,32,{0x250:pystub(c,1,this=True)}));entries.append(p);flags.append(r.randrange(2))
 def nxt(em,k):em.w32(em.arg32(0),entries[k+1] if k+1<len(entries) else 0)
 lst=obj(c,32,{0x50:pystub(c,1,this=True,deref={0:1},side=nxt)});e.w32(lst+8,entries[0] if entries else 0);e.w32(me+0x310,lst)
 embedded=obj(c,32,{0x30:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(me+0x23c,e.r32(embedded))
 controls=rnd(c,0x30)
 for i in range(8):e.w32(controls+12+4*i,obj(c,32,{0x28c:pystub(c,0,this=True),0x284:pystub(c,1,this=True),0x26c:pystub(c,3,this=True)}))
 mgr=obj(c,32,{0xcc:pystub(c,1,this=True,ret=controls)});e.w32(0x70038c,mgr)
 so=sysobj(c,table_size=0xb00);table=e.r32(so+0x9b);e.w32(table+0xae4,obj(c,32,{0:pystub(c,2,this=True,ret=r.getrandbits(32))}));return [me]
S(0x57d000,'GUESS update_control_group','thiscall',None,ret=None,gen=gen)
