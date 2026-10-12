"""specs_s6180.py - unclaimed-68 batch 18 (claim 17): ZCharisma::CopyEventDataBlock (0x4bb230). The DBREAD readers 0x4e5e60 (dword) and
0x4e5e40 (word) are hooked by address (e.hook) and return values chosen per case; the DBREAD object is a zeroed block."""
from pilot import S
from engine_stubs import zero_obj


def _setup(c):
    # a stream cursor: each reader call returns the next value of this run's sequence (the dword reader and the word reader share it)
    c.hv = {'seq': [], 'n': 0}

    def read(em, r):
        i = c.hv['n']
        c.hv['n'] += 1
        v = c.hv['seq'][i] if i < len(c.hv['seq']) else 0
        em.ret(eax=v, argbytes=0)

    c.emu.hook(0x4e5e60, read)
    c.emu.hook(0x4e5e40, read)


def _gen(c):
    c.hv = {'seq': [c.rng.getrandbits(32), c.rng.getrandbits(16)], 'n': 0}
    o = zero_obj(c, 0x100)
    dbr = zero_obj(c, 0x100)
    return [o, dbr]


S(0x4bb230, 'ZCharisma::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 18; DBREAD readers 0x4e5e60 / 0x4e5e40 hooked by address')
