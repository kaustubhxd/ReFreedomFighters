"""specs_s5704.py - unclaimed-57, batch 4: CExplode::Load (0x584680). Thiscall, one argument, returns al = 1. Hooked callees (fixed
results, no pointer logged): 0x6352f0 (writes a constant through its pointer argument); the readers used by 0x584b40, run as original
code: 0x4e5e80 (returns a float in st0), 0x4e5e60 and 0x4e5e40 (return dwords). The load object's slot +0x40 is stubbed (logged).
Limit: 0x4e5e60 is called twice in 0x584b40 and its result is XORed with the dword at its DBREAD pointer, so the value
from 0x6352f0 is observable; a mutant that uses the first call's value instead of the second is not distinguishable here."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _explode(c):
    e = c.emu
    v_out = c.rng.getrandbits(32)
    v60 = c.rng.getrandbits(32)
    v40 = c.rng.getrandbits(32)
    v80 = c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75])

    def out_fn(em, r):
        em.w32(em.arg32(0), v_out)
        em.ret(eax=0, argbytes=4)
    e.hook(0x6352f0, out_fn)
    # The readers fold in the dword at their DBREAD pointer (ecx), as the real readers depend on it, so the value that
    # 0x6352f0 writes into tmp is observable and the call order matters.
    e.hook(0x4e5e80, lambda em, r: em.ret(st0=v80 + (em.r32(em.reg('ecx')) & 0xff) / 16.0, argbytes=0))
    e.hook(0x4e5e60, lambda em, r: em.ret(eax=v60 ^ em.r32(em.reg('ecx')), argbytes=0))
    e.hook(0x4e5e40, lambda em, r: em.ret(eax=v40 ^ em.r32(em.reg('ecx')), argbytes=0))
    vt = e.logging_vtable('explode_load', 32, argwords={0x40: 1})
    ld = _rnd(c, 0x40)
    e.w32(ld, vt)
    return [_rnd(c, 0x800), ld]


S(0x584680, 'CExplode::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_explode,
  note='unclaimed-57 batch 4; 0x6352f0 and readers hooked; load->vt[+0x40] stubbed; returns 1')
