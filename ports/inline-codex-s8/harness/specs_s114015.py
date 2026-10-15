from pilot import S
from recruits_util import clear_hooks,rnd,hook_rec

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x80);a=rnd(c,0xc0);header=rnd(c,0x80);book=rnd(c,32)
 e.w32(a,header);e.w32(a+20,book);stride=r.randrange(1,5);num=r.randrange(9);start=r.randrange(3);e.w32(header,start);e.w32(header+4,start+num*stride);e.w32(header+8,stride);e.w32(header+12,r.randrange(1,4));e.w32(book,r.randrange(1,5));e.w32(book+4,r.randrange(1,20))
 config=rnd(c,0x1020);x=rnd(c,32);y=rnd(c,32);e.w32(s+64,x);e.w32(x+4,y);e.w32(y+28,config)
 cuts=[r.randrange(2),r.randrange(2,4),4]
 for i,v in enumerate(cuts):e.w32(config+0xfe8+i*4,v)
 types=4;tables=rnd(c,types*4);e.w32(a+24,tables)
 for i in range(types):
  e.w32(header+20+i*4,r.getrandbits(4));t=rnd(c,32);e.w32(tables+i*4,t)
  for j in range(4):e.w32(t+j*4,r.choice([0,r.getrandbits(32)]))
 thresholds=sorted(r.sample(range(num+1),r.randrange(min(num+1,6)+1)))
 for i in range(20):e.w32(a+48+i*4,thresholds[i] if i<len(thresholds) else 0x7fffffff)
 channels=r.randrange(4);outputs=rnd(c,16);classes=rnd(c,16)
 for cidx in range(channels):
  dst=rnd(c,256);cl=rnd(c,64);e.w32(outputs+cidx*4,dst);e.w32(classes+cidx*4,cl)
  for i in range(12):e.w32(cl+i*4,r.randrange(types))
 def decode(em,_):
  args=[em.arg32(i) for i in range(5)];em.calllog.append(('decode',*args));em.w32(args[1],r.getrandbits(32));em.ret(eax=r.randrange(20),argbytes=0)
 cb=e.stub_fn('decode',decode)
 hook_rec(c,0x405ee0,nargs=3,pop=0,ret=lambda em,k:r.randrange(20));hook_rec(c,0x410f10,nargs=1,pop=0,ret=lambda em,k:r.getrandbits(32))
 return [s,a,outputs,channels,r.randrange(3),classes,cb,rnd(c,4*16*4) if r.randrange(2) else 0]
S(0x4096e0,'GUESS decode layered classified vectors','cdecl',None,ret='eax',gen=gen)
