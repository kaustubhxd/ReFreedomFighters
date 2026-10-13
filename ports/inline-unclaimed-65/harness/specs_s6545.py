"""specs_s6545.py - unclaimed-65 batch 45 (docs/20-unclaimed-65.md, claim 25): 0x4daa70 with the cases of its branches drawn per case: the
flag a5 (0 or 1), this+0x54 (NULL or an object c with slot 0xdc, logged), this+0x6c (0 or not), c+0x14 (bit 0 random), the object a1 with
slot 0x30 (logged). 0x4daaf0 is a logging stub for both sides (other claim). The cookie is not involved."""
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


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x4daaf0, c.emu.stub_fn('4daaf0', lambda e, r: (e.calllog.append(('0x4daaf0', e.reg('ecx'),
                                                                               tuple(e.arg32(k) for k in range(5)))),
                                                              e.ret(eax=0, argbytes=0x14))))
    _flush_code(c)


def _gen(c):
    seed = c.rng.getrandbits(32)

    def pick(*keys):
        return hash((seed,) + keys) & 1

    self_ = _rnd(c, 0x100)
    # object c at this+0x54 (or NULL): slot 0xdc (four args, logged); its +0x14 bit 0 is set on half of the cases
    cdc = lambda e, r: (e.calllog.append(('0xdc', e.reg('ecx'), tuple(e.arg32(k) for k in range(4)))), e.ret(eax=0, argbytes=0x10))[-1]
    c_vt = c.emu.fake_vtable('daa70-c', 0x100, {0xdc: cdc})
    cobj = _rnd(c, 0x40)
    c.emu.w32(cobj, c_vt)
    c.emu.w32(cobj + 0x14, (c.rng.getrandbits(32) & ~1) | pick(0x14))
    c.emu.w32(self_ + 0x54, cobj if pick(0x54) else 0)
    c.emu.w32(self_ + 0x6c, c.rng.getrandbits(32) if pick(0x6c) else 0)
    # object a1 with slot 0x30 (four args, logged)
    s30 = lambda e, r: (e.calllog.append(('0x30', e.reg('ecx'), tuple(e.arg32(k) for k in range(4)))), e.ret(eax=0, argbytes=0x10))[-1]
    a1_vt = c.emu.fake_vtable('daa70-a1', 0x100, {0x30: s30})
    a1 = _rnd(c, 0x40)
    c.emu.w32(a1, a1_vt)
    a2 = c.rng.getrandbits(32)
    a3 = c.rng.getrandbits(32)
    a4 = c.rng.getrandbits(32)
    a5 = c.rng.choice([0, 1, 0x100, 0x1234])
    return [self_, a1, a2, a3, a4, a5]


S(0x4daa70, 'ZFFClass 0x4daa70 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 45 (claim 25): dispatch on the flag, the object, and the bit tests; 0x4daaf0 stubbed')
