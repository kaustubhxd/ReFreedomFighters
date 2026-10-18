"""specs_s213076.py - batch 213076: panel refresh with entry selection by name, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5759e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    X2 = obj(c, 0x20, {0x2ec: sl(1), 0x2f0: sl(0, lambda emu, k: r.choice([0, 0x1234, r.getrandbits(32)])), 0x34c: sl(5)}, nslots=0x100)
    X = obj(c, 0x20, {0xdc: sl(0, lambda emu, k: r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)]))}, nslots=0x60)
    G = obj(c, 0x20, {0xbc: sl(0, X)}, nslots=0x60)
    e.w32(0x70039c, G)
    this = obj(c, 0x240 + 0x24 * 5 + 0x10, {0x84: sl(0, X2)}, nslots=0x40)
    # widgets
    for off in (0x1e0, 0x1e4, 0x1e8, 0x188, 0x20e):
        w = obj(c, 0x10, {0xbc: sl(1)}, nslots=0x60)
        e.w32(this + off, w)
    default = bytes(e.rbytes(0x67c8e8, 24)).split(b'\0')[0] + b'\0'
    name = r.choice([b'panel\0', b'a\0', b'\0', b'abcdefgh\0', default])
    nm = rnd(c, 0x60)
    e.wbytes(nm + 0x48, name)
    strobj = nm
    e.w32(this + 0x94, strobj)
    e.w32(this + 0x44, r.getrandbits(32))
    e.w32(this + 0x1b8, r.getrandbits(32))
    e.w32(this + 0x1c8, r.getrandbits(32))
    e.w32(this + 0x206, r.choice([0, 0, 0x5555, r.getrandbits(32)]))
    e.wbytes(this + 0x21b, bytes([r.choice([0, 1])]))
    for i in range(5):
        if r.random() < 0.2:
            e.w32(this + 0x224 + 0x24 * i, 0)
            continue
        ent = rnd(c, 0x20)
        rr = r.random()
        if rr < 0.15:
            e.w32(ent + 4, 0)
        else:
            if rr < 0.45:
                nmx = name
            elif rr < 0.6:
                nmx = name[:-1] + b'x\0' if len(name) > 1 else b'z\0'
            elif rr < 0.7:
                nmx = name[:-1] + b'\0' + b'y\0' if len(name) > 1 else b'\0'
            else:
                nmx = r.choice([b'panel\0', b'a\0', b'\0', b'abcdefgh\0', b'abcdefgx\0', b'panem\0', default])
            sp = rnd(c, 0x20)
            e.wbytes(sp, nmx)
            e.w32(ent + 4, sp)
        e.w32(this + 0x224 + 0x24 * i, ent)
    hook_rec(c, 0x5743c0, 2, this=True)
    hook_rec(c, 0x573af0, 1, this=True)
    hook_rec(c, 0x574680, 5, this=True, nullflag=(3,))
    hook_rec(c, 0x575bd0, 0, this=True)
    hook_rec(c, 0x575d00, 0, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    flag = r.choice([0, 1, 1, 0x100, 0xff, 0x101, r.getrandbits(32)])
    return [this, r.getrandbits(32), flag]


S(0x5759e0, 'panel_refresh', 'thiscall', None, ret='al', gen=g5759e0)
