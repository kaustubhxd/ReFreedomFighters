from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def slot(n,ret=0,**kw):return pystub(c,n,this=True,ret=ret,**kw)
 count=r.randrange(7);pending=r.randrange(7);capacity=r.choice([0,1,2,4,8,20])
 ids=list(range(1,count+pending+1));r.shuffle(ids)
 entities={};ranks={};finds={}
 for ident in ids:
  ent=rnd(c,0x48);entities[ident]=ent;ranks[ent]=r.randrange(5)
  typeobj=rnd(c,0x24);e.wbytes(typeobj+0x1d,r.getrandbits(16).to_bytes(2,'little'))
  e.w32(ent+0x40,typeobj);e.w32(ent+0x20,r.getrandbits(32));e.w32(ent+0x3c,r.getrandbits(32))
  e.wbytes(ent+0x18,bytes([r.getrandbits(8)]))
  ref=r.choice([0,ident+100]);e.w32(ent+0x1c,ref)
  rec=rnd(c,16);e.w32(rec+0xc,typeobj);finds[ref]=r.choice([0,rec])
 def lookup(em,k):
  ident=em.arg32(0);em.calllog.append(('lookup',ident));return entities[ident]
 def rank(em,k):
  ent=em.arg32(0);em.calllog.append(('rank',ent));return ranks[ent]
 manager=obj(c,32,{0xcc:slot(1,ret=lookup),0x2c:slot(3),0x30:slot(3)})
 e.w32(0x70038c,manager)
 sysobj(c,table_slots={0x58:slot(1,ret=lambda em,k:finds[em.arg32(0)])})
 out=rnd(c,128);inp=rnd(c,128)
 for i,ident in enumerate(ids[:count]):e.w32(out+i*4,ident)
 for i,ident in enumerate(ids[count:]):e.w32(inp+i*4,ident)
 me=obj(c,0x24,{0xc:slot(1,ret=rank)})
 for off,v in [(4,out),(8,inp),(0x10,count),(0x14,pending),(0x1c,capacity)]:e.w32(me+off,v)
 hook_rec(c,0x49da90,0,this=True);hook_rec(c,0x49db30,0,this=True)
 def copy(em,k):
  d,s,n=em.arg32(0),em.arg32(1),em.arg32(2);b=em.rbytes(s,n);em.calllog.append(('copy',n,b));em.wbytes(d,b);return d
 hook_rec(c,0x634d22,3,pop=0,stackmark=(0,1),ret=copy)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x49d6c0,'GUESS merge pending entity list','thiscall',None,ret=None,gen=g,note='batch128006')
