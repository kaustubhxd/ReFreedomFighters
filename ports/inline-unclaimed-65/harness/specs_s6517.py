"""specs_s6517.py - unclaimed-65 batch 17 (docs/20-unclaimed-65.md, claim 17): COpenSewer::ReadInput. SEH frame not reproduced (the fs:[0]
writes are not compared); the cookie is patched to a ret. The render object's slot +0x2c returns a per-case byte; the DBREAD read (0x4e6330)
writes the struct's vtable (a fake whose slots take the struct as this; not logged) and the flags; the table at [0x7003b8]+0xc69 is a heap
array (count then 9-byte records)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


_ST = {}


def _setup(c):
    import serial_stubs as ss

    def noop(e, r):
        e.ret(eax=0, argbytes=0)

    def read4e(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('dbread-4e6330', e.reg('ecx'), ()))
        e.w32(ptr, _ST['vs'])    # the struct's vtable
        e.ret(eax=0, argbytes=4)
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', noop))
    ss.patch(c, 0x4ccba0, c.emu.stub_fn('0x4ccba0', noop))
    ss.patch(c, 0x4ccf60, c.emu.stub_fn('0x4ccf60', noop))
    ss.patch(c, 0x4e6330, c.emu.stub_fn('0x4e6330', read4e))
    _flush_code(c)


def _gen(c):
    flagv = c.rng.choice([0, 1])
    more = {'n': c.rng.randint(0, 3), 'i': 0}
    items = [0x1000 + k for k in range(8)]

    def s4c(e, r):
        ptr = e.arg32(0)
        e.calllog.append(('struct-4c', 0, ()))
        e.w32(ptr, 1)
        e.ret(eax=0, argbytes=4)

    def s5c(e, r):
        ptr = e.arg32(0)
        i = more['i']
        more['i'] += 1
        e.calllog.append(('struct-5c', 0, ()))
        e.w32(ptr, 1 if more['n'] - i > 0 else 0)
        e.ret(eax=items[i % 8], argbytes=4)
    vs = c.emu.fake_vtable('sewer-read-struct', 0x70, {0x4c: s4c, 0x5c: s5c})
    _ST['vs'] = vs
    # the render object: slot +0x2c returns a byte (flagv in the low byte)
    r_vt = c.emu.logging_vtable('sewer-render', 0x40, impl={0x2c: lambda e, r: (flagv, None)}, argwords={0x2c: 0})
    R = _rnd(c, 0x40)
    c.emu.w32(R, r_vt)
    rr = _rnd(c, 0x2000)
    c.emu.w32(rr + 0x9b, R)
    c.emu.w32(0x70039c, rr)
    # the table object at [0x7003b8]: count at +0xc69, records after it
    G = _rnd(c, 0x2000)
    c.emu.w32(G + 0xc69, c.rng.randint(0, 4))
    c.emu.w32(0x7003b8, G)
    self_ = _rnd(c, 0x40)
    dbread = _rnd(c, 0x40)
    return [self_, dbread]


S(0x5c3b00, 'COpenSewer::ReadInput (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 17 (residue 16); SEH frame not reproduced; struct vtable from the DBREAD read; table append')
