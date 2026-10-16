"""specs_s1525.py - recruits thread batch 1525: SSquad::AddMember (0x5898c0). teb=True (the original's SEH frame reads
fs:[0]). The log object (0x700390) and the MYSTR helpers (0x4cc1d0 / 0x4cbec0) are recorders; the actor's slot 0x1d8
returns a fixed MYSTR buffer. The squad record: count at +0 (0..12), members from +4."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, logger, stub_memset


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memset(c)
    logger(c, 3)
    strp = e.alloc(8, 4)
    hook_rec(c, 0x4cc1d0, 0, ret=strp, this=True)
    hook_rec(c, 0x4cbec0, 0, this='mark')
    mys = rnd(c, 0x10)
    actor = obj(c, 0x200, {0x1d8: pystub(c, 2, ret=mys, stackmark=(0,))})
    sq = rnd(c, 0xf4)
    n = r.choice([r.randint(0, 11), 12])
    e.w32(sq, n)
    sysobj(c, table_slots={0x20: pystub(c, 0, ret=0)}, table_size=0x20)
    return [sq, actor]


S(0x5898c0, 'ZFFGameData::SSquad::AddMember', 'thiscall', ret='al', gen=_gen, note='batch1525', teb=True)
