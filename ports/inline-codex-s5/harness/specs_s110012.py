from pilot import S
from recruits_util import clear_hooks,rnd,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 t=rnd(c,0x1000);line=r.randrange(23)
 for i in range(24):e.w32(t+0xef2+4*i,r.choice([0,r.getrandbits(32)]))
 e.w32(t+0x13f,r.choice([e.r32(t+0xef2+4*line),r.getrandbits(32)]))
 a,b=rnd(c,0x80),rnd(c,0x80)
 e.wf32(a+0x70,r.uniform(0,3));e.wf32(b+0x70,r.uniform(0,3))
 choices=[r.choice([0,a]),r.choice([0,b])]
 sysobj(c,table_slots={0x60:pystub(c,1,this=True,ret=lambda em,n:choices[min(n,1)])})
 hooks=[r.choice([0,111]),r.choice([0,222])]
 hook_rec(c,0x466290,2,this=True,ret=lambda em,n:hooks[min(n,1)])
 hook_rec(c,0x467000,4,this=True,ret=r.choice([0,333]))
 hook_rec(c,0x467ca0,0,this=True,st0=r.choice([0.,.19999999,.2,.20000002,1.,2.5,r.uniform(0,4)]))
 return [t,line,r.choice([0,1,256,257,0xffffffff])]
S(0x594040,'ZFFHERO PlaySound_Command','thiscall',None,ret='eax',gen=gen)
