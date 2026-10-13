"""specs_c109.py - climb thread batch 109: ZFFHeroMovementOpenSewer dtor, GetAnims, TerminateControl; 0x59a6a0."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _delete(e, r):
    e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=0)


def _dtor(c):
    e = c.emu
    e.hook(0x634273, _delete)
    o = rnd(c, 0x5c0)
    for off in (0x25, 0x3d, 0x55, 0x3d3, 0x3eb, 0x4ab, 0x523):
        sub = 0 if c.rng.random() < 0.3 else obj(e, 'owned%x' % off, 0x20, {0: (1, None)})
        e.mu.mem_write(o + off + 0x14, struct.pack('<I', sub))
    return [o, c.rng.getrandbits(32)]


S(0x5e15d0, 'ZFFHeroMovementOpenSewer scalar deleting dtor', 'thiscall', None, ret='eax', gen=_dtor, note='c109')


def _base(e, r):
    e.calllog.append(('BaseMove::GetAnims', e.reg('ecx')))
    e.ret()


def _ga(c):
    e = c.emu
    e.hook(0x5e3e90, _base)
    v = c.rng.getrandbits(32)

    def find(e, t, a):
        return (v, None, (bytes(e.rbytes(a[0], 16)).split(b'\0')[0],))
    o = rnd(c, 0x5c0)
    e.w32(o, rvt(e, 'move', {0x58: (1, find)}))
    return [o]


S(0x5e46e0, 'ZFFHeroMovementOpenSewer::GetAnims', 'thiscall', None, ret=None, gen=_ga, note='c109')

S(0x59a6a0, 'OSD flag +0x22ce (guess)', 'thiscall', None, ret=None,
  gen=lambda c: [rnd(c, 0x22e0), c.rng.choice([0, 1, c.rng.getrandbits(32)])], note='c109')


def _restore(e, r):
    e.calllog.append(('RestoreItem', e.reg('ecx')))
    e.ret()


def _term(c):
    e = c.emu
    r = c.rng
    e.hook(0x594590, _restore)
    o = rnd(c, 0x5c0)
    e.w8(o + 0x54c, 0 if r.random() < 0.5 else r.getrandbits(8))
    hero = rnd(c, 0xa00)
    osd = rnd(c, 0x22e0)
    e.mu.mem_write(hero + 0x852, struct.pack('<I', osd))
    e.mu.mem_write(o + 0x36d, struct.pack('<I', hero))
    return [o, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x5e7420, 'ZFFHeroMovementOpenSewer::TerminateControl', 'thiscall', None, ret='al', gen=_term,
  note='c109; RestoreItem is a hook; 0x59a6a0 runs as original')
