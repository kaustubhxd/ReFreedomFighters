from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g93f0(c):
 base(c);e=c.emu;r=c.rng
 n=r.randrange(21);me=rnd(c,0x60+8*max(n,1));e.w32(me+0x48,n)
 key=r.choice([0,1,2,3,r.getrandbits(32)])
 for i in range(n):e.w32(me+0x4c+8*i,r.choice([0,0,0,1,2,key,r.getrandbits(32)]))
 return [me,key,r.choice([0,1,2,0x100,0x101,0x80000000])]

def g7150(c):
 base(c);e=c.emu;r=c.rng
 stream=rnd(c,8);e.w32(stream,0)
 offset=r.choice([0,40,100,0xffffffe0]);n=r.randrange(7);words={};candidates=[]
 for i in range(n):
  at=(offset+40*i)&0xffffffff;start=r.choice([0,1,20,100,0xfffffff0]);length=r.choice([0,1,8,40,0xffffffff]);physical=r.getrandbits(32)
  for delta,v in ((0,1),(12,start),(16,length),(20,physical)):words[(at+delta)&0xffffffff]=v
  candidates.extend([start,(start-1)&0xffffffff,(start+length)&0xffffffff,(start+length-1)&0xffffffff])
 words[(offset+40*n)&0xffffffff]=0
 logical=r.choice(candidates+[r.getrandbits(32)])
 def seek(em,rr):
  file,where,origin=em.arg32(0),em.arg32(1),em.arg32(2)
  em.calllog.append(('fseek',file,where,origin));em.w32(file,where);em.ret(eax=0,argbytes=0)
 def read(em,rr):
  out,size,count,file=[em.arg32(i) for i in range(4)];at=em.r32(file);n=size*count
  data=words.get(at,0).to_bytes(4,'little')
  em.calllog.append(('fread',file,at,size,count,data));em.wbytes(out,data[:n]);em.w32(file,(at+n)&0xffffffff);em.ret(eax=count,argbytes=0)
 e.w32(0x6763e8,e.stub_fn('fseek',seek));e.w32(0x6763f8,e.stub_fn('fread',read))
 return [rnd(c,4),stream,offset,logical]
S(0x5e93f0,'GUESS remove one weapon or skip-shift purge empty pairs','thiscall',None,ret=None,gen=g93f0)
S(0x427150,'GUESS translate logical offset through file descriptors','thiscall',None,ret='eax',gen=g7150)
