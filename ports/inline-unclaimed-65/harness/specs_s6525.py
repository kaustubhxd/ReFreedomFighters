"""specs_s6521.py - unclaimed-65 batch 25 (docs/20-unclaimed-65.md, claim 19), branch path G of ZItem::ClassInit2: as path B (specs_s6520)
and the render slot 0x58 returns ZERO (s == 0, so the guard before the 0x2e8 call is false; the loop still runs), and this+0x78 is an object o78 whose slot 0x64 returns a non-zero
block once and then zero: the group-3 loop runs one iteration (0x4c, 0x64, 0xcc on the global 0x70038c object, 0x44, the 0x2e8 call
on sobj with (this, edi), 0x64 again). The struct helpers and the cookie are stubbed as in specs_s6520."""
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


def _logger(tag, nargs, logidx, ret_of):
    """A thiscall handler: logs the listed arguments, returns ret_of(e); the callee pops nargs dwords."""
    def h(e, r):
        e.calllog.append((tag, e.reg('ecx'), tuple(e.arg32(i) for i in logidx)))
        e.ret(eax=ret_of(e), argbytes=4 * nargs)
    return h


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    ss.patch(c, 0x4d2280, c.emu.stub_fn('4d2280 logger', lambda e, r: (e.calllog.append(('0x4d2280', ())), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4d3ab0, c.emu.stub_fn('4d3ab0 logger', lambda e, r: (e.calllog.append(('0x4d3ab0', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=8))))
    ss.patch(c, 0x4d2330, c.emu.stub_fn('4d2330 logger', lambda e, r: (e.calllog.append(('0x4d2330', ())), e.ret(eax=0, argbytes=0))))
    _flush_code(c)


def _gen(c):
    vobj = _rnd(c, 0x40)
    vobj_vt = c.emu.fake_vtable('ci2c-vobj', 0x300, {0x25c: _logger('0x25c', 2, [0, 1], lambda e: 0)})
    c.emu.w32(vobj, vobj_vt)

    # sobj: the render slot 0x58 result (non-zero); its slot 0x2e8 is called with (this, edi) in the loop
    sobj = _rnd(c, 0x40)
    sobj_vt = c.emu.fake_vtable('ci2c-sobj', 0x300, {0x2e8: _logger('0x2e8s', 2, [0, 1], lambda e: 0)})
    c.emu.w32(sobj, sobj_vt)
    r_vt = c.emu.fake_vtable('ci2c-render', 0x100, {0x58: _logger('0x58', 1, [0], lambda e: 0)})
    render = _rnd(c, 0x40)
    c.emu.w32(render, r_vt)
    gobj = _rnd(c, 0x2000)
    c.emu.w32(gobj + 0x9b, render)
    c.emu.w32(0x70039c, gobj)

    # the loop object o78: slot 0x4c and 0x44 return zero; slot 0x64 returns the block xb once, then zero
    xb = _rnd(c, 0x40)
    c.emu.w32(xb, c.rng.getrandbits(32))
    state = {'n': 0}

    def s64(e, r):
        e.calllog.append(('0x64', e.reg('ecx'), ()))
        v = xb if state['n'] == 0 else 0
        state['n'] += 1
        e.ret(eax=v, argbytes=4)

    o78_vt = c.emu.fake_vtable('ci2c-o78', 0x100, {
        0x4c: _logger('0x4c', 1, [], lambda e: 0),
        0x64: s64,
        0x44: _logger('0x44', 1, [], lambda e: 0),
    })
    o78 = _rnd(c, 0x40)
    c.emu.w32(o78, o78_vt)

    # the global 0x70038c object: slot 0xcc (one arg, the value of *xb) returns yb, whose +0x44 dword is the edi of the loop
    yb = _rnd(c, 0x80)
    c.emu.w32(yb + 0x44, c.rng.getrandbits(32))
    cc_vt = c.emu.fake_vtable('ci2c-cc', 0x100, {0xcc: _logger('0xcc', 1, [0], lambda e: yb)})
    cc = _rnd(c, 0x40)
    c.emu.w32(cc, cc_vt)
    c.emu.w32(0x70038c, cc)

    # this: as path B; 0x2e8 returns vobj, 0x2ec returns 1
    this_vt = c.emu.fake_vtable('ci2c-this', 0x300, {
        0x2e8: _logger('0x2e8', 0, [], lambda e: vobj),
        0x2ec: _logger('0x2ec', 1, [0], lambda e: 1),
        0x2fc: _logger('0x2fc', 0, [], lambda e: 0),
        0x168: _logger('0x168', 2, [0], lambda e: 0),
        0x2f0: _logger('0x2f0', 3, [0, 1, 2], lambda e: 0),
        0x110: _logger('0x110', 2, [0, 1], lambda e: 0),
        0x40: _logger('0x40', 0, [], lambda e: 0),
    })
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, this_vt)
    c.emu.w32(self_ + 0x5c, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x60, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x64, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x78, o78)
    c.emu.w16(self_ + 0x7c, c.rng.getrandbits(16))
    blk = _rnd(c, 0x40)
    c.emu.w32(blk + 0x18, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x10, blk)
    return [self_]


S(0x46bca0, 'ZItem::ClassInit2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 25 (claim 19); branch path C: as B, render 0x58 non-zero, one loop iteration (0x64 then 0)')
