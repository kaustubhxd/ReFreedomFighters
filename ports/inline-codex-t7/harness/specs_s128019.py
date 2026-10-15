from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 count=r.randrange(7);items=[]
 for i in range(count):
  rec=rnd(c,24);n=r.randrange(24);e.w32(rec,n);e.w32(rec+16,rnd(c,max(n,1)));items.append(rec)
 # Each getter may alter endian mode. Each output field must reload it.
 table=rnd(c,0x6300);e.w32(table+0x62e7,r.choice([0,1,3]))
 so=sysobj(c);e.w32(so+0x9b,r.choice([0,table,table]))
 toggles=[r.choice([0,1,3]) for _ in range(20)]
 def side(em,k):e.w32(table+0x62e7,toggles[k%20]);em.calllog.append(('get',em.reg('ecx')))
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,side=side,**kw)
 me=obj(c,0x24,{0x1c:slot(0,r.getrandbits(32)),0x20:slot(0,r.getrandbits(32)),0x34:slot(0,count),0x48:slot(0,r.getrandbits(32)),0x30:slot(0,r.getrandbits(32)),0x28:slot(0,r.getrandbits(32)),0x38:slot(1,ret=lambda em,k:items[em.arg32(0)])})
 text=r.choice([b'',b'Name',b'alpha beta',r.randbytes(16).replace(b'\0',b'x')]);s=rnd(c,len(text)+1);e.wbytes(s,text+b'\0');e.w32(me+24,r.choice([0,s]))
 out=rnd(c,512)
 def cp(em,k):
  d,s,n=em.arg32(0),em.arg32(1),em.arg32(2);em.calllog.append(('copy',d,s,n));em.wbytes(d,em.rbytes(s,n));return d
 hook_rec(c,0x634d22,3,pop=0,ret=cp)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,out]
S(0x6397c0,'GUESS pack named binary records','thiscall',None,ret='eax',gen=g,note='batch128019')
