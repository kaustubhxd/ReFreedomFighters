"""specs_s6400.py - unclaimed-68 batch 40 (claim 40): ZSoundToggle::CopyEventDataBlock (0x4bb530). The DBREAD reader 0x4e5e60 is hooked by
address with a stream cursor (each call returns the next value of the run's sequence; the sequence has zeros in about one case in three)."""
from pilot import S
from engine_stubs import zero_obj


def _setup(c):
    c.hv = {'seq': [], 'n': 0}

    def read(em, r):
        i = c.hv['n']
        c.hv['n'] += 1
        v = c.hv['seq'][i] if i < len(c.hv['seq']) else 0
        em.ret(eax=v, argbytes=0)

    c.emu.hook(0x4e5e60, read)


def _gen(c):
    c.hv = {'seq': [0 if c.rng.random() < 0.33 else c.rng.getrandbits(32)], 'n': 0}
    o = zero_obj(c, 0x100)
    dbr = zero_obj(c, 0x100)
    return [o, dbr]


S(0x4bb530, 'ZSoundToggle::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 40; DBREAD reader 0x4e5e60 hooked by address with a stream cursor')
