"""specs_s2901.py - unclaimed-29 batch 1 (docs/20-unclaimed-29.md, claim 1): ZFenceGate::Save (save object's vtable slots +0x60
returns the object, so the chain goes to the same vtable; +0x3c records) and ZCarIf::opaqueCall (count at 0x701800, table at
0x701808, tail jump to 0x51ad90, a logging stub). No faulting cases allowed: all pointers are valid."""
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


def _save_gen(c):
    # the save object: slot +0x60 (one stack arg) returns its own this, slot +0x3c (one arg) logs
    vt = c.emu.logging_vtable('zsavegame', 0x64, impl={0x60: lambda e, a: (e.reg('ecx'), None)},
                              argwords={0x60: 1, 0x3c: 1})
    save = _rnd(c, 0x40)
    c.emu.w32(save, vt)
    gate = _rnd(c, 0x100)
    c.emu.w8(gate + 0x25a, c.rng.getrandbits(8))
    c.emu.w8(gate + 0x25b, c.rng.getrandbits(8))
    return [gate, save]


def _setup_opaque(c):
    count = c.rng.randint(0, 8)
    c.emu.w32(0x701800, count)
    for i in range(8):
        base_ret = c.rng.getrandbits(32)

        def slot(e, r, i=i, base_ret=base_ret):
            e.calllog.append(('car-slot', i, e.reg('ecx'), (e.arg32(0),)))
            e.ret(eax=base_ret, argbytes=4)
        c.emu.w32(0x701808 + 4 * i, c.emu.stub_fn('car slot %d' % i, slot))
    rv = c.rng.getrandbits(32)

    def tail(e, r):
        e.calllog.append(('0x51ad90', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    from serial_stubs import patch
    patch(c, 0x51ad90, c.emu.stub_fn('0x51ad90 logger', tail))
    _flush_code(c)


def _opaque_gen(c):
    self_ = _rnd(c, 0x40)
    params = _rnd(c, 0x40)
    c.emu.w16(params + 0x10, c.rng.randint(0, 12))
    return [self_, params]


S(0x5c2900, 'ZFenceGate::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save_gen,
  note='unclaimed-29 batch 1 (slice 8); clears +4 bit 0x40; slot +0x60 twice (bytes +0x25a, +0x25b) then +0x3c (dword +0x50)')
S(0x51b600, 'ZCarIf::opaqueCall (unknown) thiscall', 'thiscall', None, ret='eax', gen=_opaque_gen,
  setup=_setup_opaque, note='unclaimed-29 batch 1 (slice 8, medium name); table dispatch below count at 0x701800, else tail-jump 0x51ad90')
