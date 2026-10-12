"""specs_s804.py - core batch 804 (docs/20-unclaimed-65.md): tail-jump thunks and two small thiscall methods. Targets are logging stubs
(the other claims); each records the registers and arguments it receives, so the jump's arguments and ecx are compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cdecl_target(addr, tag):
    def make(c):
        import serial_stubs as ss
        ss.patch(c, addr, c.emu.stub_fn(tag, lambda e, r: (e.calllog.append((tag, (e.arg32(0), e.arg32(1)))), e.ret(eax=0x77, argbytes=0))))
        c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
        c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    return make


def _tail_cdecl(addr, target, name):
    setup = _cdecl_target(target, name)
    S(addr, 'core thunk %x (unknown) cdecl' % addr, 'cdecl', None, ret='eax',
      gen=lambda c: [c.rng.getrandbits(32), c.rng.getrandbits(32)], setup=setup,
      note='core batch 804: tail jump to %x' % target)


_tail_cdecl(0x5dbc10, 0x5dbc30, 'tgt 5dbc30')
_tail_cdecl(0x5c26e0, 0x5c2870, 'tgt 5c2870')
_tail_cdecl(0x5c39e0, 0x5c3b00, 'tgt 5c3b00')
_tail_cdecl(0x5dc8a0, 0x5dcea0, 'tgt 5dcea0')


def _setup_none(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_obj(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x5a, c.rng.getrandbits(32))
    return [this]


S(0x4a0e90, 'core method 0x4a0e90 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_obj, setup=_setup_none,
  note='core batch 804: or 1 into a dword at +0x5a')


def _setup_thisfn(c):
    import serial_stubs as ss
    vt = c.emu.fake_vtable('core-804-664', 0x700, {0x664: lambda e, r: (e.calllog.append(('0x664', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    c.thisvt = vt
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_thisfn(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this, c.thisvt)
    return [this, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4783f0, 'core method 0x4783f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_thisfn, setup=_setup_thisfn,
  note='core batch 804: slot 0x664 with no arguments; the four stack arguments are popped by the method')


def _setup_c4190(c):
    import serial_stubs as ss
    tgt_vt = c.emu.fake_vtable('core-804-c', 0x100, {0xc: lambda e, r: (e.calllog.append(('0xc', e.reg('ecx'), (e.arg32(0), e.arg32(1)))), e.ret(eax=0x66, argbytes=8))[-1]})
    tgt = _rnd(c, 0x40)
    c.emu.w32(tgt, tgt_vt)
    c.tgt = tgt
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_c4190(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x48, c.tgt)
    return [this, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5c4190, 'core thunk 0x5c4190 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_c4190, setup=_setup_c4190,
  note='core batch 804: object at +0x48, tail jump through its slot 0xc with the same arguments')
