"""specs_c104.py - climb thread batch 104: jump and fall movement members."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _delete(e, r):
    e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=0)


S(0x591f20, 'ZFFHERO::GetJump', 'thiscall', None, ret='al', gen=lambda c: [rnd(c, 0x420)], note='c104')


def _sub(c, name='owned'):
    if c.rng.random() < 0.3:
        return 0
    return obj(c.emu, name, 0x20, {0: (1, None)})


def _adl(c):
    o = rnd(c, 0x20)
    c.emu.w32(o + 0x14, _sub(c))
    return [o]


S(0x480fd0, 'ZAnimDefsList::~ZAnimDefsList body', 'thiscall', None, ret=None, gen=_adl, note='c104')


def _mbm(c):
    o = rnd(c, 0x80)
    for off in (0x25, 0x3d, 0x55):
        c.emu.mu.mem_write(o + off + 0x14, struct.pack('<I', _sub(c, 'owned%x' % off)))
    return [o]


S(0x4878d0, 'ZMovementBaseMove::~ZMovementBaseMove body', 'thiscall', None, ret=None, gen=_mbm,
  note='c104; ZAnimDefsList dtor runs as original code')


def _hdtor(c):
    e = c.emu
    e.hook(0x634273, _delete)
    o = rnd(c, 0x5c0)
    for off in (0x25, 0x3d, 0x55, 0x3d3, 0x3eb, 0x4ab, 0x523):
        e.mu.mem_write(o + off + 0x14, struct.pack('<I', _sub(c, 'owned%x' % off)))
    return [o, c.rng.getrandbits(32)]


S(0x5e13f0, 'ZFFHeroMovementFall scalar deleting dtor', 'thiscall', None, ret='eax', gen=_hdtor, note='c104')
S(0x5e14b0, 'ZFFHeroMovementJump scalar deleting dtor', 'thiscall', None, ret='eax', gen=_hdtor, note='c104')


def _term(c):
    o = rnd(c, 0x560)
    r = c.rng
    for off in (0x550, 0x554):
        c.emu.w8(o + off, 0 if r.random() < 0.5 else r.getrandbits(8))
    hero = rnd(c, 0x420)
    c.emu.mu.mem_write(o + 0x36d, struct.pack('<I', hero))
    sys_ = rnd(c, 0x80)
    c.emu.w32(0x70039c, sys_)
    if r.random() < 0.3:
        c.emu.w32(sys_ + 0x40, r.randint(0, 1 << 20))
    return [o, r.choice([0, 1, r.getrandbits(32)])]


S(0x5e71f0, 'ZFFHeroMovementFall::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='c104')
S(0x5e7230, 'ZFFHeroMovementJump::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='c104')


def _base(e, r):
    e.calllog.append(('BaseMove::GetAnims', e.reg('ecx')))
    e.ret()


def _ga(c):
    e = c.emu
    e.hook(0x5e3e90, _base)
    seq = [c.rng.getrandbits(32) for _ in range(4)]

    def find(e, t, a, seq=seq):
        s = bytes(e.rbytes(a[0], 32)).split(b'\0')[0]
        return (seq.pop(0) if seq else 0, None, (s,))
    vt = rvt(e, 'move', {0x54: (1, None), 0x58: (1, find)})
    o = rnd(c, 0x5b0)
    e.w32(o, vt)
    return [o]


S(0x5e45d0, 'ZFFHeroMovementFall::GetAnims', 'thiscall', None, ret=None, gen=_ga,
  note='c104; the base GetAnims is a logging hook')
S(0x5e4630, 'ZFFHeroMovementJump::GetAnims', 'thiscall', None, ret=None, gen=_ga,
  note='c104; the base GetAnims is a logging hook')
