"""specs_s805.py - core batch 805 (docs/20-unclaimed-65.md): four small assembly transcriptions. Callees are logging stubs (other claims):
573da0/573db0 (thiscall, no args), 577d60 (the tail target, thiscall, no args, returns 0x33), 5dd4b0 (thiscall, one argument, ret 4),
4a0d40 (thiscall, one argument, ret 4, returns 0x44), 4a22f0 (thiscall, no args)."""
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


def _stub(addr, tag, nargs, ret):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((tag, e.reg('ecx'), args))
        e.ret(eax=ret, argbytes=4 * nargs)
    return h


def _setup_tail(c):
    import serial_stubs as ss
    ss.patch(c, 0x573da0, c.emu.stub_fn('573da0', _stub(0x573da0, '573da0', 0, 0)))
    ss.patch(c, 0x573db0, c.emu.stub_fn('573db0', _stub(0x573db0, '573db0', 0, 0)))
    ss.patch(c, 0x577d60, c.emu.stub_fn('577d60', _stub(0x577d60, '577d60', 0, 0x33)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _setup_5dd(c):
    import serial_stubs as ss
    ss.patch(c, 0x5dd4b0, c.emu.stub_fn('5dd4b0', _stub(0x5dd4b0, '5dd4b0', 1, 0)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _setup_4a1(c):
    import serial_stubs as ss
    ss.patch(c, 0x4a0d40, c.emu.stub_fn('4a0d40', _stub(0x4a0d40, '4a0d40', 1, 0x44)))
    ss.patch(c, 0x4a22f0, c.emu.stub_fn('4a22f0', _stub(0x4a22f0, '4a22f0', 0, 0)))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen_this(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this + 0x5a, c.rng.getrandbits(32))
    return [this]


S(0x577cf0, 'core thunk 0x577cf0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_this, setup=_setup_tail,
  note='core batch 805: call 0x573da0 with this, then tail jump to 0x577d60')
S(0x577d50, 'core thunk 0x577d50 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_this, setup=_setup_tail,
  note='core batch 805: call 0x573db0 with this, then tail jump to 0x577d60')
S(0x5dd3e0, 'core method 0x5dd3e0 (unknown) stdcall', 'stdcall', None, ret='eax',
  gen=lambda c: [c.rng.getrandbits(32), c.rng.getrandbits(32)], setup=_setup_5dd,
  note='core batch 805: push the second argument, call 0x5dd4b0, ret 8')
S(0x4a1de0, 'core method 0x4a1de0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_this, setup=_setup_4a1,
  note='core batch 805: clear bit 0 of +0x5a, call 0x4a0d40 with this, then 0x4a22f0 with its result')
