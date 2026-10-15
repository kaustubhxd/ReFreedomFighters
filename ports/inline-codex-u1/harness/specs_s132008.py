import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 n=r.choice([0,1,2,3,5,8,12]);offset=r.randrange(5);lines=r.randrange(1,9);octave=offset+lines//2+r.randrange(4)
 octs=[]
 for i in range(max(n,1)+1):octs.append(octave);octave+=r.randrange(6)
 total=octave-offset+r.randrange(1,5);table=rnd(c,4*len(octs));vi=rnd(c,0x80);p=rnd(c,0x30)
 for i,x in enumerate(octs):e.w32(table+4*i,x)
 e.w32(vi+0x7c,r.choice([fb(r.uniform(-100,100)),fb(-9999),fb(1e30),0x7fc01234]))
 for off,x in [(0,n),(4,vi),(0x18,table),(0x20,offset),(0x28,lines),(0x2c,total)]:e.w32(p+off,x)
 seeds=rnd(c,4*(total+2));floor=rnd(c,4*max(n,1))
 for base,count in [(seeds,total+2),(floor,max(n,1))]:
  for i in range(count):e.w32(base+4*i,r.choice([fb(-9999),fb(r.uniform(-100,100)),fb(r.uniform(-100,0)),0x7fc01234,0x7f800000,0xff800000]))
 return [p,seeds,floor]
S(0x404460,'GUESS vorbis max seeds','cdecl',None,ret=None,gen=gen,nan_heap=True)
