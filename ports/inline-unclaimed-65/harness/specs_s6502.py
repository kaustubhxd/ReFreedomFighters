"""specs_s6502.py - unclaimed-65 batch 2 (docs/20-unclaimed-65.md, claim 2): ZSHAPE::~ZSHAPE (member, base and delete callees
stubbed) and CFFCoverList::Init2 (render object at 0x70039c+0x9b: slot +0x138 returns X; X's slot +0x88 writes a value through
its out pointer; the render object's slot +0x58 returns a per-case value). Translation cache flushed after the patches."""
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


def _logger(name, nargs, cdecl=False):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=0, argbytes=0 if cdecl else 4 * nargs)
    return h


def _setup_shape(c):
    from serial_stubs import patch
    patch(c, 0x4609e0, c.emu.stub_fn('0x4609e0', _logger('0x4609e0', 0)))
    patch(c, 0x45c3e0, c.emu.stub_fn('0x45c3e0', _logger('0x45c3e0', 0)))
    patch(c, 0x45c510, c.emu.stub_fn('0x45c510', _logger('0x45c510', 1, cdecl=True)))
    patch(c, 0x4690b0, c.emu.stub_fn('0x4690b0', _logger('0x4690b0', 2, cdecl=True)))
    patch(c, 0x634273, c.emu.stub_fn('0x634273', _logger('0x634273', 2, cdecl=True)))
    _flush_code(c)


def _shape_gen(c):
    self_ = _rnd(c, 0x80)
    inner = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x18, inner if c.rng.random() < 0.5 else 0)
    return [self_, c.rng.getrandbits(32)]


def _setup_cover(c):
    from serial_stubs import patch  # noqa: F401
    import serial_stubs as ss  # noqa: F401
    value = c.rng.getrandbits(32)

    def slot88(e, r):
        ptr = e.arg32(1)
        e.calllog.append(('cover-x-88', e.reg('ecx'), (e.arg32(0),)))
        e.w32(ptr, value)
        e.ret(eax=0, argbytes=8)
    x_vt = c.emu.fake_vtable('cover-x', 0x90, {0x88: slot88})
    x = _rnd(c, 0x40)
    c.emu.w32(x, x_vt)
    ret58 = c.rng.getrandbits(32)
    r_vt = c.emu.logging_vtable('render-cover', 0x140, impl={0x138: lambda e, a: (x, None),
                                                              0x58: lambda e, a: (ret58, None)},
                                argwords={0x138: 0, 0x58: 1})
    r_obj = _rnd(c, 0x40)
    c.emu.w32(r_obj, r_vt)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, r_obj)
    c.emu.w32(0x70039c, rm)


def _cover_gen(c):
    return [_rnd(c, 0x100)]


S(0x44a960, 'ZSHAPE::~ZSHAPE (unknown) thiscall', 'thiscall', None, ret='eax', gen=_shape_gen, setup=_setup_shape,
  note='unclaimed-65 batch 2 (residue 18); vtable 0x67f874; delete 0x38 if +0x18; member 0x4609e0; base 0x45c3e0; flag bit 0 paths')
S(0x5879e0, 'CFFCoverList::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_cover_gen, setup=_setup_cover,
  note='unclaimed-65 batch 2 (residue 18); render 0x138 -> X; X slot 0x88 writes through; render slot 0x58 into +0x6f')
