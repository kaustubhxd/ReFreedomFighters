"""4b56b0 spec from original disassembly: SSE/config/name/flag paths."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import struct, zlib

def g4b56b0(c):
    clear_hooks(c)
    r = c.rng
    seh_chain(c, r.choice([0, 1, 2]))
    th = rnd(c, 0x140)
    count = r.choice([-2, -1, 0, 1, 2, 3, 5])
    c.emu.w32(th + 0xee, count & 0xffffffff)
    c.emu.wbytes(th + 0x9b, bytes([r.choice([0, 0, 1, 2, 255])]))
    values = [-1000.0, -1.0, -0.0, 0.0, 0.25, 1.0, 1000.0]
    c.emu.wbytes(th + 0xde, struct.pack('<f', r.choice(values)))
    sr = seh_record(c, 2, rows=64)
    sequence = [0]
    def side(emu, k):
        emu.calllog.append(('this', zlib.crc32(emu.rbytes(th, 0x140))))
        sr(emu,sequence[0])
        sequence[0] += 1
    end = pystub(c, 0, ret=r.getrandbits(32), this=True, side=side)
    vt = c.emu.alloc(0x90, 4); c.emu.w32(vt+0x8c, end); c.emu.w32(th, vt)
    cfg_value = r.getrandbits(32)
    def cfg_out(emu, k):
        out = emu.arg32(1)
        emu.calllog.append(('cfg-initial', emu.r32(out)))
        emu.w32(out, cfg_value)
        side(emu,k)
    cfg = obj(c, 0x20, {0x88:pystub(c,2,ret=r.getrandbits(32),this=True,stackmark=(1,),side=cfg_out)})
    helper = obj(c, 0x20, {0x138:pystub(c,0,ret=cfg,this=True,side=side)})
    system = rnd(c, 0xb0); c.emu.w32(system+0x9b, helper); c.emu.w32(0x70039c,system)
    log = obj(c,0x20,{0x2c:pystub(c,3,ret=r.getrandbits(32),pop=0,this=False,side=side)})
    manager = obj(c,0x20,{0x20:pystub(c,2,ret=log,this=True,side=side)})
    c.emu.w32(0x700390,manager)
    literal=bytearray(); j=0
    while c.emu.rbytes(0x6920a8+j,1) != b'\0':
        literal += c.emu.rbytes(0x6920a8+j,1); j+=1
        assert j < 256
    names=[0,0x6920a8]
    for b in [bytes(literal)+b'\0', bytes(literal)+b'x\0', b'\0', b'other\0']:
        p=c.emu.alloc(len(b),4);c.emu.wbytes(p,b);names.append(p)
    entries=[]; outputs={}
    for i in range(max(0,count)):
        ent=rnd(c,0x10); c.emu.w32(ent+4,r.choice(names))
        result=rnd(c,0x10);c.emu.wbytes(result+4,struct.pack('<f',r.choice(values)))
        outputs[ent]=r.choice([0,result,result])
        entries.append(r.choice([0,ent,ent]))
    def lookup(emu,k):
        i=emu.arg32(0)
        return entries[i] if i < len(entries) else 0
    hook_rec(c,0x4b5620,1,ret=lookup,pop=4,this=True,side=side)
    def owner_out(emu,k):
        out=emu.arg32(2)
        if out:
            emu.calllog.append(('owner-initial',emu.r32(out)))
            emu.w32(out, outputs.get(emu.arg32(0), 0))
        side(emu,k)
    string_data=rnd(c,32)
    string_image=struct.pack('<I',string_data)+bytes(r.getrandbits(8) for _ in range(124))
    def name_out(emu,k):
        emu.wbytes(emu.arg32(0),string_image)
        side(emu,k)
    owner=obj(c,0x30,{
        0x130:pystub(c,3,ret=r.getrandbits(32),this=True,stackmark=(2,),side=owner_out),
        0x1dc:pystub(c,2,ret=lambda emu,k:emu.arg32(0),this=True,stackmark=(0,),side=name_out),
        0x124:pystub(c,4,ret=r.getrandbits(32),this=True,side=side)})
    c.emu.w32(th+0x44,owner)
    def string_read(emu,k):
        emu.calllog.append(('string',emu.rbytes(emu.reg('ecx'),128).hex()))
        side(emu,k)
    hook_rec(c,0x4cc1d0,0,ret=lambda emu,k:emu.r32(emu.reg('ecx')),pop=0,this='mark',side=string_read)
    hook_rec(c,0x4cbec0,0,ret=r.getrandbits(32),pop=0,this='mark',side=string_read)
    return [th]

S(0x4b56b0,'config name float max and flag update','thiscall',None,ret='eax',gen=g4b56b0,note='batch264000')
