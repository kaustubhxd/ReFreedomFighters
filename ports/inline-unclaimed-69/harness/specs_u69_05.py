"""specs_u69_05.py - area 69, group 5 (unclaimed-69 thread)."""
from pilot import S
from ckit import rnd


def _hooks(e):
    e.hook(0x4e12e0, lambda e, res: (e.calllog.append(('DBLK::Get', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=0, argbytes=8)))
    e.hook(0x4e1b30, lambda e, res: (e.calllog.append(('DBLK::NextBlock', e.reg('ecx'))), e.ret(argbytes=0)))


def _cmd(c):
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.w16(o + 0x56, r.getrandbits(16)) if hasattr(c.emu, 'w16') else None
    c.emu.w16(o + 0x58, r.getrandbits(16))
    cmd = r.choice([r.getrandbits(16), 0])
    k = r.random()
    if k < 0.35:
        cmd = c.emu.r32(o + 0x56) & 0xffff
    elif k < 0.7:
        cmd = c.emu.r32(o + 0x58) & 0xffff
    return [o, cmd, r.getrandbits(32)]


S(0x5d6210, 'CLensFlareControl::Command', 'thiscall', None, ret='eax', gen=_cmd, note='u69 core')


def _bp(c):
    _hooks(c.emu)
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x44d010, 'ZBoneParticle::CopyDataBlock', 'thiscall', None, ret=None, gen=_bp,
  note='u69; DBLK::Get and NextBlock are GUESS stubs (other areas)')


def _sr(c):
    return [rnd(c, 0x40), c.rng.choice([0, 1, -3, 7, c.rng.getrandbits(31)]), c.rng.choice([0, 1, 5, 1000, c.rng.getrandbits(20)])]


S(0x4ccd10, 'STRREFTAB::STRREFTAB', 'thiscall', None, ret='eax', gen=_sr, note='u69')
