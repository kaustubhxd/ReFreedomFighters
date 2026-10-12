"""specs_s1939.py - unclaimed-66 batch 40 (gap band, GUESS name). THISCALL(this), (u32, float), ret 8.

0x44ac00 (another area's float helper, ECX = [this+0x4b]) is a recording stub hooked by address; its st0 result is fixed per case in gen.
The sys object (*0x70039c) has +0x9b = a child whose vtable +0x58 returns r or 0 (logging). r's vtable +0x84 writes three random dwords to its
argument (logging). The object under test is 0x800 random bytes."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _query(c):
    self = _rnd(c, 0x800)
    c.emu.w32(self + 0x4b, 0 if c.rng.random() < 0.3 else _rnd(c, 0x40))
    st0 = c.rng.uniform(-10, 10)
    fill = [c.rng.getrandbits(32) for _ in range(3)]
    ret_r = 0 if c.rng.random() < 0.2 else None
    if ret_r is None:
        def h84(e, r):
            p = e.arg32(0)
            e.calllog.append(('r vtable +0x84 (stub)', 0x84, e.reg('ecx'), (None,)))
            e.wbytes(p, b''.join(v.to_bytes(4, 'little') for v in fill))
            e.ret(eax=0, argbytes=4)
        vt_r = c.emu.fake_vtable('query r', 0x84 // 4 + 1, slots={0x84: h84})
        r = c.emu.fake_object('query r', 0x40, vtable=vt_r)
    else:
        r = 0

    def h58(e, rr):
        e.calllog.append(('child vtable +0x58 (stub)', 0x58, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=r, argbytes=4)
    vt_c = c.emu.fake_vtable('query child', 0x58 // 4 + 1, slots={0x58: h58})
    child = c.emu.fake_object('query child', 0x40, vtable=vt_c)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)

    def h44(e, rr):
        e.calllog.append(('0x44ac00 (GUESS stub)', 0x44ac00, e.reg('ecx'), (e.arg32(0), None, None)))
        e.ret(eax=0, argbytes=12, st0=st0)
    c.emu.hook(0x44ac00, h44)
    a1 = c.rng.getrandbits(32)
    v = c.rng.choice([0.0, -0.0, float('nan'), -3.5, 2.25]) if c.rng.random() < 0.3 else c.rng.uniform(-10, 10)
    return [self, a1, F(v)]


S(0x5231c0, 'GUESS FUN_005231c0 (query via sys+0x9b, r+0x84, helper 0x44ac00)', 'thiscall', None, ret='st0', gen=_query,
  note='unclaimed-66 batch 1939; gap band; 0x44ac00 GUESS stub; 0x58 and 0x84 vtable stubs; returns float')
