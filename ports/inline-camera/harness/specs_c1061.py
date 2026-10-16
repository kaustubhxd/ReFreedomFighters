"""specs_c1061.py - camera batch 1061: ZCAMERA::CopyDataBlock (0x445800).

The DBLK readers are the exe's own code and run in both builds. The spec builds a data block whose cursor points at a
buffer of random item headers (types 2, 3, 4, 10) with random bytes, ending in 0xff (the end marker). The stubs
(tag-only logs, or values chosen in the generator): the camera's slot 0x23c (logs its three floats), the manager's
slot 0x134 (an object whose slot 0x90 writes a flag byte), the manager's +0xadc object (slot 0x348), and the event
list nodes (slot 0xac). The global 0x7003b0 (the readers' missing-item callback) is 0."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr
import struct


def _f(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _cdb(c):
    log = Log(c, 512)
    r = c.rng

    # the camera with its vtable slot 0x23c (logs the three floats it is given)
    cam = rnd(c, 0x800)

    def v23c(e, res):
        p = e.arg32(0)
        log.put(0x23c, *[c.emu.r32(p + 4 * k) for k in range(3)])
        e.ret(argbytes=4)
    c.emu.w32(cam, c.emu.fake_vtable('cam', 0x240 // 4, {0x23c: v23c}))
    for off in (0x4c, 0x48, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x30, 0x170):
        c.emu.w32(cam + off, r.getrandbits(32))

    # the sys object: flag byte at +0x63, two words at +0x6f and +0x73, the event list at +0x190f, the manager at +0x9b
    s = sys_with_mgr(c, 0x2000)
    c.emu.w32(s + 0x63, r.getrandbits(8) & 1)
    c.emu.w32(s + 0x6f, r.randint(1, 1000))
    c.emu.w32(s + 0x73, r.randint(1, 1000))
    nodes = []
    for _ in range(3):
        nd = rnd(c, 0x100)
        c.emu.w32(nd + 0x81, r.getrandbits(8) & 1)
        nodes.append(nd)
    for k in range(3):
        c.emu.w32(nodes[k] + 8, nodes[k + 1] if k < 2 else 0)
    c.emu.w32(s + 0x190f, nodes[0])

    def v_ac(e, res):
        log.put(0xac, e.arg32(0), e.arg32(1))
        e.ret(argbytes=8)
    for nd in nodes:
        c.emu.w32(nd, c.emu.fake_vtable('node', 0xb0 // 4, {0xac: v_ac}))

    flag = r.getrandbits(8)
    obj_b = rnd(c, 0x40)

    def v90(e, res):
        log.put(0x90, e.arg32(0))
        c.emu.w8(e.arg32(1), flag)
        e.ret(argbytes=8)
    c.emu.w32(obj_b, c.emu.fake_vtable('objb', 0x94 // 4, {0x90: v90}))

    mgr = rnd(c, 0x1000)
    c.emu.w32(mgr, c.emu.fake_vtable('mgr', 0x140 // 4, {
        0x134: lambda e, res: (log.put(0x134), e.ret(eax=obj_b, argbytes=0)),
    }))
    c.emu.w32(s + 0x9b, mgr)

    o2 = rnd(c, 0x40)
    c.emu.w32(o2, c.emu.fake_vtable('o2', 0x350 // 4, {
        0x348: lambda e, res: (log.put(0x348, e.arg32(0)), e.ret(eax=0, argbytes=4)),
    }))
    c.emu.w32(mgr + 0xadc, o2)

    # the data block: +4 nonzero, +8 the cursor. The buffer is built by a model of the function's own reads: every
    # reader consumes one item per value (floats: types 1, 2, 3; dwords: 3, 8, 10, 11; strings: 4, 5), and every
    # GetType branch of the function sees the item at the cursor. Items: header byte (the type) + 4 data bytes, or a
    # header + NUL-terminated string for type 4. The buffer ends with 0xff (the end marker).
    buf = rnd(c, 0x600)
    items = []
    head = [None]

    def mk(t, val):
        if t == 4:
            n = r.randint(1, 6)
            return bytes([4]) + bytes(r.randint(1, 255) for _ in range(n)) + b'\x00'
        return bytes([t]) + (val & 0xffffffff).to_bytes(4, 'little')

    def gettype():
        if head[0] is None:
            t = [2, 3, 4, 10][r.randrange(4)]
            head[0] = (t, mk(t, _rand_val(t)))
        return head[0][0]

    def _rand_val(t):
        if t == 2:
            return _f(c, -300, 300)
        return r.randint(0, 3)

    def take(types, t_choice=None, val=None):
        if head[0] is None:
            t = t_choice if t_choice is not None else types[r.randrange(len(types))]
            head[0] = (t, mk(t, val if val is not None else _rand_val(t)))
        assert head[0][0] in types, head[0][0]
        items.append(head[0][1])
        head[0] = None

    def readF(n):
        for _ in range(n):
            take([2, 3], val=None)

    def readD(n, val=None):
        for _ in range(n):
            take([3, 8, 10, 11], val=val)

    def readStr():
        take([4, 5], t_choice=4)

    readF(1)                       # +0x64
    readF(1)                       # +0x68
    readD(3)                       # the three bits of +0x6c
    readF(1)                       # +0x60
    readF(1)                       # the float for +0x5c
    readD(1)                       # t34
    readD(1, val=r.randint(0, 3))  # the list count (the three list nodes)
    readD(1)                       # +0x4c
    if gettype() == 3:
        readD(1, val=r.randint(0, 3))   # the dispatch value
    if gettype() == 3:
        readD(1, val=r.randint(0, 1))
    if gettype() == 2:
        readF(1)                   # +0x70
    if gettype() == 2:
        readF(1)                   # +0x74
    if gettype() == 4:
        readStr()
    if gettype() == 3:
        readD(1, val=r.randint(0, 1))
    if gettype() == 2:
        readF(4)                   # the four floats of the transform
    if gettype() == 3:
        readD(1, val=r.randint(0, 1))
    pos = 0
    for it in items:
        c.emu.wbytes(buf + pos, it)
        pos += len(it)
    if head[0] is not None:
        c.emu.wbytes(buf + pos, head[0][1])
        pos += len(head[0][1])
    c.emu.wbytes(buf + pos, b'\xff' * 16)

    blk = rnd(c, 0x20)
    c.emu.w32(blk + 4, 1)
    c.emu.w32(blk + 8, buf)
    c.emu.w32(0x7003b0, 0)
    return [cam, blk]


S(0x445800, 'ZCAMERA::CopyDataBlock', 'thiscall', gen=_cdb)
