"""specs_s6520.py - unclaimed-65 batch 20 (docs/20-unclaimed-65.md, claim 19), branch path B of ZItem::ClassInit2: the first 0x2e8 result
is a non-zero object (vobj), the 0x2ec test is non-zero (46bd4a to 46bdaf), the render slot 0x58 returns zero and this+0x78 is null
(the loop of group 3 is skipped), and slot 0x25c on vobj returns zero (0x2dc and 0x2d8 are skipped). This runs groups 2 and 4 of the
port end to end. The real exe code runs for 0x4d2280, 0x4d3ab0 (and its 0x4d24e0 callee), 0x4d2330 and the render object is faked.
The cookie check 0x633654 is patched to a ret. Stack-frame addresses are not logged."""
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
    """A thiscall handler: logs the listed arguments and the ecx, returns ret_of(e); the callee pops nargs dwords."""
    def h(e, r):
        e.calllog.append((tag, e.reg('ecx'), tuple(e.arg32(i) for i in logidx)))
        e.ret(eax=ret_of(e), argbytes=4 * nargs)
    return h


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    # the struct helpers reach the CRT heap (0x4d2280 calls malloc through 0x6693b6; 0x4d3ab0 goes into 0x4d24e0). They are stubbed
    # as logging callees for both sides (the port calls them through ext_, at the same addresses). Only their arguments are logged,
    # not the stack struct address in ecx.
    ss.patch(c, 0x4d2280, c.emu.stub_fn('4d2280 logger', lambda e, r: (e.calllog.append(('0x4d2280', ())), e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x4d3ab0, c.emu.stub_fn('4d3ab0 logger', lambda e, r: (e.calllog.append(('0x4d3ab0', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=8))))
    ss.patch(c, 0x4d2330, c.emu.stub_fn('4d2330 logger', lambda e, r: (e.calllog.append(('0x4d2330', ())), e.ret(eax=0, argbytes=0))))
    _flush_code(c)


def _gen(c):
    # vobj: the object returned by slot 0x2e8 (non-zero); its slot 0x25c returns zero (the t == 0 path of group 4)
    vobj = _rnd(c, 0x40)
    vobj_vt = c.emu.fake_vtable('ci2b-vobj', 0x300, {
        0x25c: _logger('0x25c', 2, [0, 1], lambda e: 0)})
    c.emu.w32(vobj, vobj_vt)

    # render object: slot 0x58 returns zero (s == 0, so the loop of group 3 is not entered); it logs its argument
    r_vt = c.emu.fake_vtable('ci2b-render', 0x100, {0x58: _logger('0x58', 1, [0], lambda e: 0)})
    render = _rnd(c, 0x40)
    c.emu.w32(render, r_vt)
    gobj = _rnd(c, 0x2000)
    c.emu.w32(gobj + 0x9b, render)
    c.emu.w32(0x70039c, gobj)

    # this: 0x2e8 returns vobj (both calls), 0x2ec returns 1 (non-zero, the 46bdaf branch), 0x2fc returns 0, 0x168 logs its word
    # (the second argument is the frame address), 0x2f0 and 0x110 log their words, 0x40 is a plain call
    this_vt = c.emu.fake_vtable('ci2b-this', 0x300, {
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
    c.emu.w32(self_ + 0x78, 0)                       # the this+0x78 object is null: the loop is skipped
    c.emu.w16(self_ + 0x7c, c.rng.getrandbits(16))
    blk = _rnd(c, 0x40)                              # this+0x10: the object whose +0x18 gets or-ed with 1
    c.emu.w32(blk + 0x18, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x10, blk)
    return [self_]


S(0x46bca0, 'ZItem::ClassInit2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 20 (claim 19); branch path B: 0x2e8 non-zero, 0x2ec non-zero, render 0x58 zero, this+0x78 null, 0x25c zero')
