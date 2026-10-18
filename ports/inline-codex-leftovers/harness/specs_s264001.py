"""494950 normal entry exercises shared 4949d3 continuation with real parent frame."""
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub,seh_record,seh_chain
import struct,zlib

def g494950(c):
    clear_hooks(c);r=c.rng
    seh_chain(c,r.choice([0,1,2]))
    th=rnd(c,0xc60)
    sr=seh_record(c,2,rows=32)
    sequence = [0]
    def side(emu,k):
        emu.calllog.append(('this',zlib.crc32(emu.rbytes(th,0xc60))))
        sr(emu,sequence[0])
        sequence[0] += 1
    names=[b'',b'plain',b'a;b',b';tail',b'head;',b'a;b;c',b'long-prefix;different-tail']
    name=r.choice(names)+b'\0'
    data=rnd(c,128);c.emu.wbytes(data,name);c.emu.w32(th+0xbcd,data)
    doflag=r.choice([0,1,2,255])
    def notify(emu,k):
        emu.wbytes(th+0xbb2,bytes([doflag]));side(emu,k)
    vt=c.emu.alloc(0x190,4);c.emu.w32(th,vt)
    for off,n,fn in [(0xa0,1,side),(0x18c,1,notify),(0x188,1,side),(0x120,0,side)]:
        c.emu.w32(vt+off,pystub(c,n,ret=r.getrandbits(32),this=True,side=fn))
    manager=obj(c,0x30,{0x58:pystub(c,1,ret=r.getrandbits(32),this=True,side=side)})
    optional=obj(c,0x30,{0x3c:pystub(c,0,ret=r.getrandbits(32),this=True,side=side)})
    engine=rnd(c,0x1b00);c.emu.w32(engine+0x1aa3,manager)
    c.emu.w32(engine+0x1a9f,r.choice([0,optional]));c.emu.w32(0x70039c,engine)
    def ctor(emu,k):
        src=emu.r32(emu.arg32(0));b=bytearray()
        while emu.rbytes(src+len(b),1)!=b'\0':
            b+=emu.rbytes(src+len(b),1);assert len(b)<128
        copied=rnd(c,128);emu.wbytes(copied,bytes(b)+b'\0')
        image=struct.pack('<I',copied)+bytes(r.getrandbits(8) for _ in range(124))
        emu.wbytes(emu.reg('ecx'),image);side(emu,k)
    hook_rec(c,0x4cbe50,1,ret=r.getrandbits(32),pop=4,this='mark',side=ctor)
    def read(emu,k):side(emu,k)
    hook_rec(c,0x4cc1d0,0,ret=lambda emu,k:emu.r32(emu.reg('ecx')),pop=0,this='mark',side=read)
    def drop(emu,k):
        emu.calllog.append(('local',emu.rbytes(emu.reg('ecx'),128).hex()));side(emu,k)
    hook_rec(c,0x4cbec0,0,ret=r.getrandbits(32),pop=0,this='mark',side=drop)
    # CRT strchr is cdecl; preserve real input chars and record both arguments.
    def find(emu,k):
        p=emu.arg32(0);ch=emu.arg32(1)&255
        for i in range(128):
            b=emu.rbytes(p+i,1)[0]
            if b==ch:return p+i
            if b==0:return 0
        return 0
    def strchr_stub(emu, _):
        emu.calllog.append(('strchr',emu.arg32(0),emu.arg32(1)))
        side(emu,0)
        emu.ret(eax=find(emu,0),argbytes=0)
    c.emu.stub_import('strchr',strchr_stub)
    return [th]
S(0x494950,'shared-frame semicolon split and notifications','thiscall',None,ret='eax',gen=g494950,note='batch264001 normal entry; shared4949d3 covered, no standalone ABI claim')
