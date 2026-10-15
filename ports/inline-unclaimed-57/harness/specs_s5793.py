"""specs_s5793.py - unclaimed-57, batch 93: 0x5d3f70 (GUESS name unnamed_5d3f70). Thiscall, one stack argument obj (ret 4), returns al = 1.
Hooked callees: 0x6352f0 (writes a per-case dword through its out pointer, as in batch 4), 0x4e5e60 (dword reader: returns a per-case value
XORed with the dword at its pointer, which is the tmp written by 0x6352f0) and 0x4e5e80 (float reader: st0 from a per-case value plus the
low byte at its pointer, divided by 16). obj has fake slots +0x48 and +0x40 (one pointer into this each, logged as an offset from this,
and a fixed dword written through it)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d3f70(c):
    e = c.emu
    self_obj = _rnd(c, 0x200)
    v_out = c.rng.getrandbits(32)
    v60 = c.rng.getrandbits(32)
    f80 = c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0])
    vals = {0x48: c.rng.getrandbits(32), 0x40: c.rng.getrandbits(32)}

    def rel(p):
        return p - self_obj if self_obj <= p < self_obj + 0x200 else 'other'

    def slot(off):
        def h(em, r):
            p = em.arg32(0)
            em.calllog.append(('o', off, None, (rel(p),)))
            em.w32(p, vals[off])
            em.ret(eax=0, argbytes=4)
        return h

    def h6352(em, r):
        em.w32(em.arg32(0), v_out)
        em.ret(eax=0, argbytes=4)
    e.hook(0x6352f0, h6352)

    e.hook(0x4e5e60, lambda em, r: em.ret(eax=v60 ^ em.r32(em.reg('ecx')), argbytes=0))
    e.hook(0x4e5e80, lambda em, r: em.ret(st0=f80 + (em.r32(em.reg('ecx')) & 0xff) / 16.0, argbytes=0))

    vt_o = e.fake_vtable('d3f70_o', 160, {0x48: slot(0x48), 0x40: slot(0x40)})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_o)
    return [self_obj, obj]


S(0x5d3f70, 'unnamed_5d3f70 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_d3f70,
  note='unclaimed-57 batch 93; 0x6352f0, 0x4e5e60, 0x4e5e80 hooked; obj slots +0x48 and +0x40 fake (pointer logged as an offset)')
