"""specs_s1221.py - pathfinding batch 1221: ZPathfinder3::CopyDataBlock on a DBLK in the doc's item order.

Real exe code: the DBLK readers (GetType, Get, FindNext/NextBlock, the blob finder), the REFTAB32 ctor/dtor/Add/Begin/
Next, striwcmp, ZPFOctree_packed::Init. Stubbed identically in both builds: ZRenderGC::Init (0x610100), SerializeData
(0x52cb60, checked in its own batch), ZBaseGeom::Name (0x4dc110, a per-case name), and the assert hook (0x7003b0).
"""
import struct
from pilot import S
from pfspec import rnd, reporter, vtable, sf
import pilot

P = lambda v: struct.pack('<I', v & 0xffffffff)


def code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def jump_to(c, addr, stub):
    c.emu.wbytes(addr, b'\xb8' + P(stub) + b'\xff\xe0')
    c.emu._image_dirty = True


def allocator(c):
    e = c.emu
    a = e.alloc(16)
    impl = {8: lambda em, args: em.alloc(args[0], 16, 0x5a) if args[0] < 0x200000 else 0,
            0x10: lambda em, args: 0,
            0x48: lambda em, args: em.alloc(args[0], 16, 0x5a) if args[0] > 0x10000 else 0}
    e.w32(a, vtable(c, 'allocator', 0x60, impl=impl, argwords={8: 1, 0x10: 1, 0x48: 1}))
    e.w32(0x70038c, a)


def ref_nodes(c, n):
    """n valid 16-byte nodes: REFTAB::Add writes through a ref, so a ref must point at memory."""
    return [c.emu.alloc(16, 4) for _ in range(n)]


def dblk(c):
    """Items: blob (7, length counts its own 4 bytes, plen > 0), REFTAB (9), int (3), int (3), float (2), int (3),
    REFTAB (9), int (3), int (3), block end (6). Layout: +4 nonzero, +8 cursor."""
    r = c.rng
    e = c.emu
    items = bytearray()
    plen = r.choice([4, 8, 16])
    items += bytes([7]) + struct.pack('<I', 4 + plen) + bytes(r.getrandbits(8) for _ in range(plen))
    refs1 = ref_nodes(c, r.choice([0, 1, 3]))
    items += bytes([9]) + struct.pack('<I', 4 + 4 * len(refs1)) + b''.join(struct.pack('<I', v) for v in refs1)
    items += bytes([3]) + struct.pack('<i', r.choice([0, 1, 5, -3]))         # +0x46
    items += bytes([3]) + struct.pack('<i', r.choice([1, 3, 7, 12]))         # +0x25 (clamp 2..10)
    items += bytes([2]) + struct.pack('<f', sf(c.fv(-50, 50)))              # +0x20
    items += bytes([3]) + struct.pack('<i', r.choice([0, 1]))               # LooseOctree warning
    refs2 = ref_nodes(c, r.choice([0, 2]))
    items += bytes([9]) + struct.pack('<I', 4 + 4 * len(refs2)) + b''.join(struct.pack('<I', v) for v in refs2)
    items += bytes([3]) + struct.pack('<i', r.choice([0, 1]))               # +0x31
    items += bytes([3]) + struct.pack('<i', r.choice([1, 5, 20, 40]))       # +0x69
    items += bytes([6])                                                      # block end
    buf = e.alloc(len(items) + 16, 16)
    e.wbytes(buf, bytes(items))
    d = e.alloc(16, 4)
    e.w32(d + 4, 1)
    e.w32(d + 8, buf)
    return d


def _cdb(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    e.w32(0x7003b0, code(c, b'\xc3'))            # assert hook: returns, so both builds go on
    allocator(c)
    name = e.cstr(r.choice(['*DDoorGarage_0*', 'wall', '*door*']))
    jump_to(c, 0x610100, code(c, b'\xc2\x04\x00'))      # ZRenderGC::Init: ret 4
    jump_to(c, 0x52cb60, code(c, b'\x31\xc0\xc2\x08\x00'))  # SerializeData: ret 8
    jump_to(c, 0x4dc110, code(c, b'\xb8' + P(name) + b'\xc3'))  # ZBaseGeom::Name: returns the name
    rm = e.alloc(0x200, 4)
    msgs = e.alloc(0xae0, 4)
    mgr = e.alloc(0x40, 4)
    e.w32(rm + 0x9b, msgs)
    e.w32(msgs + 0xadc, mgr)
    e.w32(0x70039c, rm)
    geoms = []
    for k in range(r.randint(0, 3)):
        it = e.alloc(0x60, 4)
        obj = e.alloc(0x80, 4)
        cls = e.alloc(0x40, 4)
        e.w32(cls + 0x23, r.choice([0x200002, 0x100001, 0x200015]))
        e.w32(obj + 0xc, cls)
        e.w32(it + 0x54, obj if r.random() < 0.8 else 0)
        geoms.append(it)
    nxt = {g: (geoms[i + 1] if i + 1 < len(geoms) else 0) for i, g in enumerate(geoms)}
    def mgr_next(em, args):
        cur = em.r32(args[0])
        em.w32(args[0], nxt.get(cur, 0))
        return 0
    e.w32(mgr, vtable(c, 'collmgr', 0x60, impl={0x50: mgr_next}, argwords={0x50: 1}))
    e.w32(mgr + 8, geoms[0] if geoms else 0)
    e.w32(msgs, vtable(c, 'msgs', 0x60, impl={0x58: lambda em, args: geoms[0] if geoms else 0}, argwords={0x58: 1}))
    d = dblk(c)
    self_ = e.alloc(0xa0, 4)
    e.wbytes(self_, bytes(0xa0))   # a fresh ZPathfinder3: fields start zeroed (the +0x32 REFTAB is NULL)
    e.w32(self_ + 0x51, e.alloc(4, 4))
    oct_ = e.alloc(0xd20, 4)
    e.wbytes(oct_, bytes(r.getrandbits(8) for _ in range(0xd20)))
    e.w32(self_ + 0x65, oct_)
    return [self_, d]


S(0x52ac10, 'ZPathfinder3::CopyDataBlock', 'thiscall', None, gen=_cdb, n=100)
