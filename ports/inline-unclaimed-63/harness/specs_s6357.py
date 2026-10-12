"""specs_s6357.py - unclaimed-63 batch 57: 0x5e90d0 (ZWeaponRecycleList::CopyEventDataBlock; thiscall, one stack argument r, ret 4).
The reader 0x4e5e80 (thiscall with the reader in ECX, plain ret, the float in st0) is a hook: it returns a random float (NaN, zero,
infinities included) in st0 and records its ECX. The store at this+0x44c is compared through the heap."""
from pilot import S, F
import struct


def _gen_90d0(c):
    e = c.emu
    this = e.alloc(0x500, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x500)))
    r = e.alloc(0x40, 4)
    e.wbytes(r, bytes(0x40))

    def reader(em, a):
        em.calllog.append(('reader.4e5e80', None, em.reg('ecx'), ()))
        v = c.rng.choice([0.0, -0.0, 1.5, float('inf'), float('nan')]) if c.rng.random() < 0.3 else \
            struct.unpack('<f', c.rng.getrandbits(32).to_bytes(4, 'little'))[0]
        em.ret(st0=v, argbytes=0)
    e.hook(0x4e5e80, reader)
    e.mu.ctl_flush_tb()
    return [this, r]


S(0x5e90d0, 'ZWeaponRecycleList::CopyEventDataBlock thiscall', 'thiscall', None, ret=None, gen=_gen_90d0,
  note='unclaimed-63 batch 57; 0x4e5e80 hooked (returns float in st0)')
